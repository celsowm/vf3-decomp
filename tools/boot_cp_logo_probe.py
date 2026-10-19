#!/usr/bin/env python3
"""boot_cp_logo_probe.py - prove the native title scene handler requests CP_LOGO.BIN.

State 25 is captured while the ROB texture read is still in flight.  The frame loop's scene
dispatcher (`0x8C0968CC`, scene context `0x0C29B864`) selects sub-state 2 and tail-jumps to
the setup handler `0x8C096E5C`/`0x8C096E62`; the handler calls the resource loader
`0x8C07AAAC` with resource id `0x414F` at `0x8C096F24`, which asks the file loader for
`CP_LOGO.BIN` at FAD `0x68ec9`.

This probe forces the drive idle (the inherited ROB read is done in the emulator capture) and
enters the handler with its recorded arguments (r4 = scene context, r5 = 8).  It asserts that
the first native GD read is the CP_LOGO read:

  python tools/boot_cp_logo_probe.py

The patched capture and idle GD state are written under extract/analysis/ (gitignored).
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
SRC = A / "golden_bootV_vf3_25.bin"
IRQA = A / "golden_bootI_vf3_30.bin"
IRQB = A / "golden_bootS_vf3_30.bin"

CP_LOGO = (0x68EC9, 0x100, 0x0C828800)
REQ = re.compile(r"req cmd\s+17 params\s+([0-9a-fA-F]{8}) ([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})")


def patch_capture(dst: Path) -> None:
    data = bytearray(SRC.read_bytes())
    marker = struct.unpack_from("<Q", data, 0)[0]
    if marker & 0xFFFF != 0xFA30:
        raise SystemExit(f"{SRC}: not a capture (marker {marker:#x})")
    # 37 entry registers follow the marker: r0-r15, pc, pr, ...
    regs = {4: 0x0C29B864, 5: 8, 16: 0x8C095CC2}
    for i, value in regs.items():
        struct.pack_into("<Q", data, 8 + 8 * i, value)
    dst.write_bytes(data)


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
    for p in (SRC, IRQA, IRQB):
        if not p.exists():
            raise SystemExit(f"missing {p}")

    capture = A / "golden_cp_logo_probe.bin"
    gdstate = A / "gdstate_cp_logo_probe.txt"
    patch_capture(capture)
    write_idle_state(gdstate)

    env = dict(os.environ, VF3_TMU="1", VF3_ASIC_FIRST="1", VF3_GDTRACE="1")
    cmd = [
        str(BOOT), str(capture), str(IRQA), str(IRQB),
        "--loop-entry", "0x8c096e62", "--loop-stop", "0x0c035530",
        "--irqa", "0x8c063d1e", "--irqb", "0x8c062e94",
        "--cycle-frames", "300", "--first-polls", "531", "--gd-phase", "565440",
        "--full-loop", "1", "--continue", "4000", "--vblank-cap", "300",
        "--aica-word", "88:001e0000", "--gdi", "rom/vf3.gdi",
        "--gd-state", str(gdstate), "--free", "1",
    ]
    proc = subprocess.run(cmd, cwd=REPO, env=env, capture_output=True, text=True, timeout=1800)
    log = proc.stdout + proc.stderr
    reqs = [(int(a, 16), int(b, 16), int(c, 16)) for a, b, c in REQ.findall(log)]
    if proc.returncode != 0:
        print(f"vf3boot exited {proc.returncode}", file=sys.stderr)
        print(log[-2000:], file=sys.stderr)
        return 1
    if not reqs:
        print("no GD read requests in the run", file=sys.stderr)
        print(log[-2000:], file=sys.stderr)
        return 1
    print("first GD reads:")
    for i, r in enumerate(reqs[:6]):
        print(f"  {i}: fad {r[0]:08x} sectors {r[1]:08x} dest {r[2]:08x}")
    if reqs[0] != CP_LOGO:
        print(f"FAIL: first read is {reqs[0]}, expected {CP_LOGO}", file=sys.stderr)
        return 1
    unowned = re.search(r"unowned (\d+) \(first ([0-9a-fA-F]+)\)", log)
    print(f"PASS: first read is CP_LOGO.BIN (FAD 0x68ec9, 0x100 sectors, dest 0x0C828800); "
          f"unowned={unowned.group(1) if unowned else '?'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
