#!/usr/bin/env python3
"""Parse DATELIST.ASC (dev-tree build manifest) -> docs/build_manifest_notes.md

DATELIST.ASC is a NUL-separated list of records:
    <gdfile>  <MON DD> <HH:MM>  <dev-tree source path>  <size>
"""
import collections
import os
import re

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GD = os.path.join(REPO, "extract", "gamedata")
DOCS = os.path.join(REPO, "docs")

PAT = re.compile(r"(\S+)\s+([A-Za-z]{3})\s+(\d+)\s+(\d+):(\d+)\s+(\S+)\s+(\d+)")


def main():
    raw = open(os.path.join(GD, "DATELIST.ASC"), "rb").read().decode("ascii", "replace")
    lines = [l.strip() for l in re.split("[\x00\r\n]+", raw) if l.strip()]
    rows = []
    for ln in lines:
        m = PAT.match(ln)
        if not m:
            rows.append(("?", "?", "?", ln))
            continue
        name, mon, day, hh, mm, src, size = m.groups()
        rows.append((name, f"{mon} {day} {hh}:{mm}", src, int(size)))

    groups = collections.defaultdict(list)
    for name, date, src, size in rows:
        grp = src.split("/")[0] if isinstance(src, str) else "?"
        sub = src.split("/")[1].split(".")[0] if isinstance(src, str) and "/" in src else "?"
        groups[(grp, sub)].append(name)

    with open(os.path.join(DOCS, "build_manifest_notes.md"), "w", newline="\n") as d:
        d.write("# DATELIST.ASC - developer build manifest\n\n")
        d.write("Shipped on disc; maps every GD-ROM file to its **original source "
                "path in the AM2 dev tree** with archive date and size. "
                "Records are NUL-separated; DATE.ASC holds the master date "
                "(1998/10/29 21:49).\n\n")
        d.write("## Dev-tree groups\n\n")
        d.write("| dev path | files | shipped files (sample) |\n|---|---|---|\n")
        for (grp, sub), names in sorted(groups.items()):
            sample = ", ".join(sorted(names)[:6]) + (" ..." if len(names) > 6 else "")
            d.write(f"| `{grp}/{sub}` | {len(names)} | {sample} |\n")
        d.write("\nGroup interpretation hypotheses (to verify against code):\n\n")
        d.write("- `SCROLL/CNVS` -> `CP_*.BIN` 2D canvas/sprite picture packs\n")
        d.write("- `MODEL/KAO_IB` -> `MKAO_*` character model set A (face/detail variant)\n")
        d.write("- `MODEL/ROB_IB` -> `ROB_*` character model set B (+ ALP/BALL extras)\n")
        d.write("- `MODEL/STG_IB` -> `ST*.POL/.TEX` stage models\n")
        d.write("- `COLI_S/STxx`  -> `ST*.CLI` stage collision\n")
        d.write("- `MOTION/CHAR_VS` -> `MT*.BIN` per-matchup motion data\n")
        d.write("- `SOUND/BIN.981013` -> audio snapshot (BGM/VO/SFX), built 1998-10-13\n")
        d.write("- `AM2/SET5` -> sound driver related (likely SNDDRV.BIN)\n")
        d.write("\n## Full mapping\n\n")
        d.write("| shipped file | archived | dev source | size |\n|---|---|---|---|\n")
        for name, date, src, size in rows:
            d.write(f"| {name} | {date} | `{src}` | {size} |\n")

    print(f"{len(rows)} records -> docs/build_manifest_notes.md")


if __name__ == "__main__":
    main()
