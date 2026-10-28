#!/usr/bin/env python3
"""Try the reply headers the memory card driver may accept.

The SDK's driver compares a per-unit word against 0xFFFFFF00 and 0xFFFFFFFF
(the "no device" answer and a second status), so the header the port answers
with decides whether the card is attached.  This script runs the port with
several forced headers and prints the mpdrv record the game left in RAM.

Usage:
    python tools/maple_card_header_probe.py build/boot2.state
"""
from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RECORDS = 0x0C19C6A0

CASES = [
    ("the port's answer (the reference's too)", None),
    ("the no-device answer", "FFFFFFFF"),
    ("the sender byte 0xFF", "1CFF0005"),
    ("the recipient byte 0xFF", "1C00FF05"),
    ("the status-all code", "1C010006"),
]


def main() -> int:
    state = sys.argv[1] if len(sys.argv) > 1 else "build/boot2.state"
    frames = os.environ.get("VF3_PROBE_FRAMES", "80")
    for name, hdr in CASES:
        ram = Path("build/probe_hdr.ram")
        ppm = Path("build/probe_hdr.ppm")
        for p in (ram, ppm):
            if p.exists():
                p.unlink()
        env = dict(os.environ)
        env.pop("VF3_MAPLE_HDR", None)
        if hdr:
            env["VF3_MAPLE_HDR"] = hdr
        cmd = ["build/vf3sdl.exe", "--state", state, "--entry", "0x8c004000",
               "--gdi", "rom/vf3.gdi", "--bios",
               "tools/emu/flycast-ref-build/data/dc_boot.bin",
               "--frames", frames, "--headless", "--dump-ram", str(ram),
               "--dump-frame", str(ppm)]
        subprocess.run(cmd, env=env, stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL, check=False)
        rec = "no dump"
        if ram.exists():
            blob = ram.read_bytes()
            off = RECORDS - RAM_BASE
            rec = str([int.from_bytes(blob[off + 4 * i:off + 4 * i + 4], "little")
                       for i in range(6)])
        lit = 0
        if ppm.exists():
            try:
                from PIL import Image
                import collections
                im = Image.open(ppm).convert("RGB")
                c = collections.Counter(im.getdata())
                lit = sum(v for k, v in c.items() if k != (0, 0, 0))
            except Exception:
                lit = -1
        print("%-38s rec0 = %-28s lit = %d" % (name, rec, lit))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
