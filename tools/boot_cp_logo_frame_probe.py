#!/usr/bin/env python3
"""boot_cp_logo_frame_probe.py - prove the real title frame loop requests CP_LOGO.BIN.

The emulator trace from state 22 shows the frame loop entry at 0x8C095CC2 with
pr=0x0C02007C, then the scene dispatcher 0x8C0968CC, the setup 0x8C096E62 and the
resource loader 0x8C07AAAC(0x414F), which asks the file loader for file 5
(CP_LOGO.BIN).  This probe captures that exact frame-loop entry (real stack, real
registers) and runs it free:

  python tools/boot_cp_logo_frame_probe.py

A frame-loop slice must be larger than the render callback that runs before the
scene dispatcher (the default 20,000-step slice stops inside it); the probe passes
--slice 200000.  BS_KEEP_PR=1 keeps the captured return address.

Output: PASS with the first GD read = CP_LOGO (FAD 0x68ec9, 0x100 sectors,
destination 0x0C828800) and zero unowned calls.
"""
from __future__ import annotations

import os
import re
import struct
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
A = REPO / "extract" / "analysis"
BOOT = REPO / "build" / "vf3boot.exe"
CAPTURE = A / "golden_frame_entry_s22_vf3_22.bin"
STATE = REPO / "tools" / "emu" / "flycast-build" / "data" / "vf3_22.state"
IRQA = A / "golden_bootI_vf3_30.bin"
IRQB = A / "golden_bootS_vf3_30.bin"

CP_LOGO = (0x68EC9, 0x100, 0x0C828800)
REQ = re.compile(r"req cmd\s+17 params\s+([0-9a-fA-F]{8}) ([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})")


def capture_frame_loop() -> None:
    if CAPTURE.exists() and CAPTURE.stat().st_size > 1_000_000:
        return
    if not STATE.exists():
        raise SystemExit(f"missing {STATE}; cannot capture the frame-loop entry")
    cmd = [sys.executable, str(REPO / "tools" / "tick_capture.py"), "0x8C095CC2",
           "--state", str(STATE), "--frames", "1000", "--pairs", "1",
           "--name", "frame_entry_s22"]
    proc = subprocess.run(cmd, cwd=REPO, capture_output=True, text=True, timeout=1800)
    if proc.returncode != 0 or not CAPTURE.exists() or CAPTURE.stat().st_size <= 1_000_000:
        print(proc.stdout[-2000:], file=sys.stderr)
        print(proc.stderr[-2000:], file=sys.stderr)
        raise SystemExit("frame-loop capture failed")


def write_idle_state(dst: Path) -> None:
    words = [
        0x19, 0x1A, 0, 0x11,
        0x68EC9, 0x100, 0x0C828800, 0,
        0, 0, 0, 0,
        0x7167A, 0x7167A, 0x0C621000, 0,
    ]
    dst.write_text(" ".join(f"{w:08x}" for w in words) + "\n", encoding="ascii")


def main() -> int:
    if not BOOT.exists():
        raise SystemExit(f"missing {BOOT}; build the project first")
    for p in (IRQA, IRQB):
        if not p.exists():
            raise SystemExit(f"missing {p}")
    capture_frame_loop()
    gdstate = A / "gdstate_frame_probe.txt"
    write_idle_state(gdstate)

    env = dict(os.environ, VF3_TMU="1", VF3_ASIC_FIRST="1", VF3_GDTRACE="1",
               BS_KEEP_PR="1")
    cmd = [
        str(BOOT), str(CAPTURE), str(IRQA), str(IRQB),
        "--loop-entry", "0x8c095cc2", "--loop-stop", "0x0c035530",
        "--irqa", "0x8c063d1e", "--irqb", "0x8c062e94",
        "--cycle-frames", "300", "--first-polls", "531", "--gd-phase", "565440",
        "--full-loop", "1", "--continue", "4000", "--vblank-cap", "5",
        "--slice", "200000",
        "--aica-word", "88:001e0000", "--gdi", "rom/vf3.gdi",
        "--gd-state", str(gdstate), "--free", "1",
    ]
    proc = subprocess.run(cmd, cwd=REPO, env=env, capture_output=True, text=True, timeout=1800)
    log = proc.stdout + proc.stderr
    if proc.returncode != 0:
        print(f"vf3boot exited {proc.returncode}", file=sys.stderr)
        print(log[-3000:], file=sys.stderr)
        return 1
    reqs = [(int(a, 16), int(b, 16), int(c, 16)) for a, b, c in REQ.findall(log)]
    if not reqs:
        print("no GD read requests in the frame-loop run", file=sys.stderr)
        print(log[-3000:], file=sys.stderr)
        return 1
    print("first GD reads:")
    for i, r in enumerate(reqs[:6]):
        print(f"  {i}: fad {r[0]:08x} sectors {r[1]:08x} dest {r[2]:08x}")
    if reqs[0] != CP_LOGO:
        print(f"FAIL: first read is {reqs[0]}, expected {CP_LOGO}", file=sys.stderr)
        return 1
    unowned = re.search(r"after the wait:.*?unowned (\d+)", log)
    if not unowned or int(unowned.group(1)) != 0:
        print("FAIL: unowned calls in the frame-loop run", file=sys.stderr)
        print(log[-3000:], file=sys.stderr)
        return 1
    print("PASS: frame loop 0x8C095CC2 -> dispatcher -> setup -> CP_LOGO.BIN "
          "(FAD 0x68ec9, 0x100 sectors, dest 0x0C828800); unowned=0")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
