#!/usr/bin/env python3
"""Probe the memory card check of the boot with different card answers.

The game's SDK counts the card's free blocks and refuses to start when the
count is below what it needs.  This script runs the port with a few different
media-info answers (the port's `VF3_VMU_INFO` override) and prints the
mpdrv record the game left in RAM, so the count's origin can be seen.

Usage:
    python tools/maple_card_probe.py build/boot2.state
"""
from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RECORDS = 0x0C19C6A0
RECORD_STRIDE = 76

CASES = [
    ("the card's own media info", None),
    ("the reference's unformatted answer", "255,0,255,254,1,253,13,0,200,31,0,0"),
    ("no save blocks", "255,0,255,254,1,253,13,0,200,0,0,0"),
    ("the whole card is the save area", "255,0,255,254,1,253,13,0,0,255,0,0"),
    ("one save block", "255,0,255,254,1,253,13,0,200,1,0,0"),
]


def main() -> int:
    state = sys.argv[1] if len(sys.argv) > 1 else "build/boot2.state"
    frames = os.environ.get("VF3_PROBE_FRAMES", "60")
    for name, info in CASES:
        ram = Path("build/probe_card.ram")
        if ram.exists():
            ram.unlink()
        env = dict(os.environ)
        env.pop("VF3_VMU_INFO", None)
        if info:
            env["VF3_VMU_INFO"] = info
        cmd = ["build/vf3sdl.exe", "--state", state, "--entry", "0x8c004000",
               "--gdi", "rom/vf3.gdi", "--bios",
               "tools/emu/flycast-ref-build/data/dc_boot.bin",
               "--frames", frames, "--headless", "--dump-ram", str(ram)]
        subprocess.run(cmd, env=env, stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL, check=False)
        if not ram.exists():
            print("%-34s : no dump" % name)
            continue
        blob = ram.read_bytes()
        off = RECORDS - RAM_BASE
        words = [int.from_bytes(blob[off + 4 * i:off + 4 * i + 4], "little")
                 for i in range(6)]
        print("%-34s : rec0 = %s" % (name, words))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
