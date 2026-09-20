#!/usr/bin/env python3
"""SYSROF/LBR tooling for the Katana SDK libraries.

Subcommands:
  extract LIB --out DIR   extract every module of an H-series .lib to DIR/*.obj
                          (drives the SDK's own lbr.exe interactively)
  list    LIB             print module+symbol list of a .lib
  parse   OBJ ...         dump minimal SYSROF structure of object file(s) as JSON

lbr.exe (Hitachi H SERIES OBJECT LIBRARIAN 2.0, interactive):
  LIBRARY <file>  /  LIST  /  OUTPUT <file>  /  EXTRACT <module>  /  EXIT
"""
from __future__ import annotations

import argparse
import csv
import json
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
LBR = REPO / "tools" / "katana" / "katana" / "shc" / "bin" / "lbr.exe"


def lbr_session(cmds: list[str]) -> str:
    payload = "\r\n".join([*cmds, "EXIT"]) + "\r\n"
    p = subprocess.run([str(LBR)], input=payload, capture_output=True, text=True,
                       encoding="cp437", errors="replace", timeout=300)
    return p.stdout or ""


def lbr_modules(lib: Path) -> list[str]:
    out = lbr_session(["LIBRARY " + str(lib), "LIST"])
    mods: list[str] = []
    pending = ""
    in_listing = False
    for line in out.splitlines():
        if "Number of symbols" in line:
            in_listing = True  # module list starts after the header block
            continue
        if not in_listing:
            continue
        if "Entry date" in line:
            name = (pending + line.split("Entry date")[0]).strip()
            pending = ""
            if name:
                mods.append(name)
        else:
            s = line.strip()
            # a long module name gets its own line, with the date wrapped onto
            # the next; only identifier-shaped fragments count
            if s and re.fullmatch(r"[A-Za-z0-9_.$]+", s):
                pending += s
    return mods


def cmd_list(a) -> int:
    mods = lbr_modules(Path(a.lib))
    print(f"{len(mods)} modules")
    for m in mods:
        print(" ", m)
    return 0


def cmd_extract(a) -> int:
    lib = Path(a.lib).resolve()
    out = Path(a.out).resolve()
    out.mkdir(parents=True, exist_ok=True)
    mods = lbr_modules(lib)
    print(f"{len(mods)} modules in {lib.name}")
    ok, failed = 0, []
    for i, m in enumerate(mods):
        target = out / (m + ".obj")
        if target.exists():
            target.unlink()  # lbr refuses to overwrite
        txt = lbr_session([
            "LIBRARY " + str(lib),
            f"OUTPUT {target}",
            f"EXTRACT {m}",
        ])
        if target.is_file():
            ok += 1
        else:
            err = next((l.strip() for l in txt.splitlines() if "**" in l), "?")
            failed.append((m, err))
        if (i + 1) % 50 == 0:
            print(f"  {i + 1}/{len(mods)}")
    if failed:
        print("failed:", *failed[:10], sep="\n  ")
    print(f"done: {ok}/{len(mods)} objects in {out}")
    return 1 if failed else 0


# ----------------------------------------------------------------- SYSROF parse
# Observed on memset.obj (sh4nlfzz.lib, SHC 5.0 Apr-98):
#   0x000: e0 2e ...  padded 256B: header ("P032LBR2-MW" = producer string)
#   0x100: e2 <len>  padded 256B: module record  (name at +17, len-prefixed)
#   0x200: e4 <len>  padded 256B: symbol record   ("_memset")
#   0x300: DWF/debug block (80 21 ...)
#   ... then definition records with raw code bytes visible ("e7 73 63 62 33.."
#   = the memset entry words).
# This is a v0 structural walk, not a full decoder.

def parse_obj(p: Path) -> dict:
    d = p.read_bytes()
    info: dict = {"file": p.name, "size": len(d),
                  "is_sysrof": d[:2] in (b"\xe0.", b"\xe0/", b"\xe00"),
                  "module": None, "symbols": []}
    if not d.startswith(b"\xe0"):
        return info
    # crude ascii run harvest for module/symbol spotting (names are ' 06name' etc.)
    txt = []
    i = 0
    while i < len(d):
        if 0x20 <= d[i] < 0x7F:
            j = i
            while j < len(d) and 0x20 <= d[j] < 0x7F:
                j += 1
            txt.append(d[i:j].decode("ascii"))
            i = j
        else:
            i += 1
    info["strings"] = txt
    return info


def cmd_parse(a) -> int:
    for f in a.obj:
        info = parse_obj(Path(f))
        print(json.dumps(info, indent=1))
    return 0


# ---------------------------------------------------------------- corpus match
def _code_windows(d: bytes, start_at: int = 0x300, min_len: int = 6):
    runs, begin, i = [], None, start_at
    while i + 1 < len(d):
        w = d[i] | (d[i + 1] << 8)
        if w == 0:
            if begin is not None and i - begin >= min_len:
                runs.append((begin, i))
            begin = None
        elif begin is None:
            begin = i
        i += 2
    if begin is not None and len(d) - begin >= min_len:
        runs.append((begin, len(d)))
    return runs


def _find_all(haystack: bytes, needle: bytes):
    at = haystack.find(needle)
    while at >= 0:
        yield at
        at = haystack.find(needle, at + 1)


def _module_match(obj: Path, game: bytes, base: int, probe: int = 24,
                  min_hits: int = 2):
    """Longest contiguous run of this module's bytes found verbatim in the
    game image. Seeds 24B probes at several window offsets, extends each seed
    by exact byte equality within window bounds. Returns dict|None."""
    d = obj.read_bytes()
    best = None
    for (ws, we) in _code_windows(d):
        win = d[ws:we]
        if len(win) < 12:
            continue
        offs = list(range(0, len(win) - probe + 2, 2)) or [0]
        seen_deltas = 0
        for o in offs:
            seed = win[o:o + probe]
            if len(set(seed)) < 4:
                continue  # degenerate filler probe (nops/zeros)
            for at in _find_all(game, seed):
                # extend forward
                f = probe + o
                while f < len(win) and at + (f - o) < len(game) \
                        and win[f] == game[at + (f - o)]:
                    f += 1
                # extend backward
                b = o
                while b > 0 and at - (o - b) - 1 >= 0 \
                        and win[b - 1] == game[at - (o - b) - 1]:
                    b -= 1
                span = f - b
                gstart = base + at - o + b
                if best is None or span > best["span"]:
                    best = {
                        "module": obj.stem,
                        "win_off": ws + b, "win_len": span,
                        "span": span,
                        "cover": span * 100 // len(win),
                        "game_start": gstart,
                    }
                seen_deltas += 1
                if seen_deltas > 6:
                    break
            if seen_deltas > 6:
                break
    if best and best["span"] >= 16:
        return best
    return None


def cmd_match(a) -> int:
    game = Path(a.game).read_bytes()
    base = int(a.base, 0)
    out = Path(a.out)
    rows = []
    for libdir in a.dir:
        lib = Path(libdir)
        for obj in sorted(lib.glob("*.obj")):
            m = _module_match(obj, game, base, probe=a.probe)
            if m:
                m["lib"] = lib.name
                rows.append(m)
    out.parent.mkdir(parents=True, exist_ok=True)
    with open(out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["lib", "module", "game_start", "span", "cover", "win_off", "win_len"])
        for m in sorted(rows, key=lambda r: -r["span"]):
            w.writerow([m["lib"], m["module"], f"0x{m['game_start'] & ~1:08x}",
                        m["span"], m["cover"], f"0x{m['win_off']:x}", m["win_len"]])
    print(f"matched {len(rows)} modules -> {out}")
    return 0


_KAMUI_SUFFIX = re.compile(r"_[A-Za-z0-9]+_lib_$")
_NINJA_SUFFIX = re.compile(r"_workaround_for_sh_lnk_$")


def _symbol_name(lib: str, module: str) -> str:
    s = module
    s = _KAMUI_SUFFIX.sub("", s)
    s = _NINJA_SUFFIX.sub("", s)
    if not s.startswith("_"):
        s = "_" + s
    return s


def cmd_names(a) -> int:
    """katana_matches.csv -> Vf3ApplyNames CSV (addr,name,span).
    Confident: cover>=80 -> direct name. Partial: span>=24 & cover>=40 -> cand_."""
    import csv as _csv
    rows = list(_csv.DictReader(open(a.matches)))
    chosen: dict[str, dict] = {}  # game_start -> best row
    for r in rows:
        g = r["game_start"]
        if g not in chosen or int(r["span"]) > int(chosen[g]["span"]):
            chosen[g] = r
    confident = 0
    with open(a.out, "w", newline="") as f:
        w = _csv.writer(f)
        w.writerow(["addr", "name", "span"])
        for g, r in sorted(chosen.items(), key=lambda kv: int(kv[0], 16)):
            span, cover = int(r["span"]), int(r["cover"])
            name = _symbol_name(r["lib"], r["module"])
            if (cover >= 60 and span >= 18) or span >= 32:
                w.writerow([f"0x{int(g, 16):08x}", name, span])
                confident += 1
            elif span >= 24:
                w.writerow([f"0x{int(g, 16):08x}", "cand_" + name, -span])
    print(f"names -> {a.out} ({confident} confident of {len(rows)} matched modules)")
    return 0


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("extract")
    p.add_argument("lib")
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_extract)

    p = sub.add_parser("list")
    p.add_argument("lib")
    p.set_defaults(fn=cmd_list)

    p = sub.add_parser("parse")
    p.add_argument("obj", nargs="+")
    p.set_defaults(fn=cmd_parse)

    p = sub.add_parser("names", help="build Vf3ApplyNames CSV from katana_matches.csv")
    p.add_argument("matches")
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_names)

    p = sub.add_parser("match", help="byte-match extracted modules against a game image")
    p.add_argument("dir", nargs="+", help="dirs of extracted .obj (one per lib)")
    p.add_argument("--game", required=True)
    p.add_argument("--funcs", help="funcs_*.csv (for fixture naming of hits)")
    p.add_argument("--base", default="0x8C010000")
    p.add_argument("--probe", type=int, default=24)
    p.add_argument("--out", required=True)
    p.set_defaults(fn=cmd_match)

    a = ap.parse_args()
    return a.fn(a)


if __name__ == "__main__":
    sys.exit(main())
