#!/usr/bin/env python3
"""Probe where the memory card driver's free block count comes from.

The game's SDK refuses to start when the card has fewer free blocks than it
needs.  This script runs the port with different card images (the root
block's media info and the FAT's free marker) and prints the mpdrv record the
game left in RAM, so the count's origin can be pinned down.

Usage:
    python tools/maple_card_count_probe.py build/boot2.state
"""
from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RECORDS = 0x0C19C6A0

CASES = [
    ("the reference's card", {}, None),
    ("the save area at 200 with 31 blocks", {"VF3_VMU_ROOTINFO": "255,0,255,254,1,253,13,5,200,31,0,128"}, None),
    ("the save area at 200 with 100 blocks", {"VF3_VMU_ROOTINFO": "255,0,255,254,1,253,13,5,200,100,0,128"}, None),
    ("the save area at 0 with 255 blocks", {"VF3_VMU_ROOTINFO": "255,0,255,254,1,253,13,5,0,255,0,128"}, None),
    ("the save area at 100 with 31 blocks", {"VF3_VMU_ROOTINFO": "255,0,255,254,1,253,13,5,100,31,0,128"}, None),
    ("the save area at 241 with 14 blocks", {"VF3_VMU_ROOTINFO": "255,0,255,254,1,253,13,5,241,14,0,128"}, None),
]


def main() -> int:
    state = sys.argv[1] if len(sys.argv) > 1 else "build/boot2.state"
    frames = os.environ.get("VF3_PROBE_FRAMES", "60")
    for name, env_extra, _ in CASES:
        ram = Path("build/probe_card.ram")
        if ram.exists():
            ram.unlink()
        env = dict(os.environ)
        env.pop("VF3_VMU_INFO", None)
        env.pop("VF3_VMU_ROOTINFO", None)
        env.update(env_extra)
        cmd = ["build/vf3sdl.exe", "--state", state, "--entry", "0x8c004000",
               "--gdi", "rom/vf3.gdi", "--bios",
               "tools/emu/flycast-ref-build/data/dc_boot.bin",
               "--frames", frames, "--headless", "--dump-ram", str(ram)]
        subprocess.run(cmd, env=env, stdout=subprocess.DEVNULL,
                       stderr=subprocess.DEVNULL, check=False)
        if not ram.exists():
            print("%-38s : no dump" % name)
            continue
        blob = ram.read_bytes()
        off = RECORDS - RAM_BASE
        words = [int.from_bytes(blob[off + 4 * i:off + 4 * i + 4], "little")
                 for i in range(6)]
        print("%-38s : rec0 = %s" % (name, words))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
