#!/usr/bin/env python3
"""Smart Ghidra + Java locator and analyzeHeadless runner for the VF3 project.

One-time setup pain (where is Ghidra? where is Java?) is solved once here and
cached in extract/analysis/ghidra_locator.json (gitignored with extract/).

Importable:
    from ghidra_run import locate
    cfg = locate()          # {"java": ..., "headless": ..., "home": ...}

CLI:
    python tools/ghidra_run.py locate [--verbose] [--refresh]
    python tools/ghidra_run.py doctor
    python tools/ghidra_run.py list
    python tools/ghidra_run.py run 1ST_READ.unsc.bin -p Vf3Probe
    python tools/ghidra_run.py run 1ST_READ.unsc.bin -p "DumpAt.java out.txt 0x8C010000"
    python tools/ghidra_run.py run 1ST_READ.unsc.bin --analyze -p Vf3SeedPointers

Probe order for Ghidra (first existing hit wins):
  1. GHIDRA_HOME / GHIDRA_INSTALL_DIR env vars
  2. cached locator file
  3. repo-root ghidra.bat (parsed for GHIDRA= and JAVA_HOME=)
  4. repo-local tools/ghidra*/support/analyzeHeadless(.bat)
  5. drive roots / Program Files / %USERPROFILE% ghidra* dirs
  6. analyzeHeadless(.bat) on PATH

Java probe order: JAVA_HOME env, cache, ghidra.bat, java on PATH,
Adoptium "C:/Program Files/Eclipse Adoptium/jdk-*" (highest version wins).
"""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
CACHE = REPO / "extract" / "analysis" / "ghidra_locator.json"
PROJECT_DIR = REPO / "extract" / "ghidra_proj"
PROJECT_NAME = "VF3"
GSCRIPTS = REPO / "tools" / "gscripts"
ANALYSIS_DIR = REPO / "extract" / "analysis"


# --------------------------------------------------------------------------- locator

def _norm(p: str | os.PathLike) -> str:
    return str(Path(p).resolve())


def _headless_in(home: Path) -> Path | None:
    for name in ("analyzeHeadless.bat", "analyzeHeadless"):
        c = home / "support" / name
        if c.is_file():
            return c
    return None


def _ghidra_bat_hints() -> tuple[Path | None, Path | None]:
    """Parse repo-root ghidra.bat for GHIDRA= and JAVA_HOME= hints."""
    bat = REPO / "ghidra.bat"
    if not bat.is_file():
        return None, None
    ghidra = java = None
    for line in bat.read_text(encoding="utf-8", errors="replace").splitlines():
        m = re.match(r'\s*set\s+"(?P<k>[^=]+)=(?P<v>[^"]+)"', line)
        if not m:
            continue
        k, v = m.group("k").strip().upper(), m.group("v").strip()
        if k == "GHIDRA":
            ghidra = Path(v).parent  # points at ghidraRun.bat -> parent is home
        elif k == "JAVA_HOME":
            java = Path(v)
    return ghidra, java


def _ghidra_probes() -> list[Path]:
    out: list[Path] = []

    def add_home(h: Path):
        hh = _headless_in(h)
        if hh:
            out.append(hh)

    for var in ("GHIDRA_HOME", "GHIDRA_INSTALL_DIR"):
        v = os.environ.get(var)
        if v:
            add_home(Path(v))

    ghidra_home, _ = _ghidra_bat_hints()
    if ghidra_home:
        add_home(ghidra_home)

    for glob_pat in ("tools/ghidra*/tools",):  # placeholder, replaced below
        pass
    for cand in sorted(REPO.glob("tools/ghidra*/")):
        add_home(cand)

    roots = [Path(d) for d in ("C:\\", "D:\\", "E:\\", "F:\\") if Path(d).is_dir()]
    extras = [
        Path(os.environ.get("ProgramFiles", r"C:\Program Files")),
        Path(os.environ.get("USERPROFILE", "")),
        Path(os.environ.get("USERPROFILE", "")) / "Downloads",
    ]
    for base in roots + extras:
        try:
            for d in base.glob("ghidra*/"):
                add_home(d)
                if (d / "support").is_dir():
                    for sub in d.glob("ghidra*/"):
                        add_home(sub)
        except PermissionError:
            continue
    return out


def _java_probes() -> list[Path]:
    out: list[Path] = []

    def add(home: Path):
        for rel in ("bin/java.exe", "bin/java"):
            c = home / rel
            if c.is_file():
                out.append(c)

    v = os.environ.get("JAVA_HOME")
    if v:
        add(Path(v))
    _, java_home = _ghidra_bat_hints()
    if java_home:
        add(java_home)
    adoptium = Path(os.environ.get("ProgramFiles", r"C:\Program Files")) / "Eclipse Adoptium"
    if adoptium.is_dir():
        for jdk in sorted(adoptium.glob("jdk-*/"), reverse=True):
            add(jdk)
    return out


def _on_path(exe_names: list[str]) -> Path | None:
    for d in os.environ.get("PATH", "").split(os.pathsep):
        if not d:
            continue
        for name in exe_names:
            c = Path(d) / name
            if c.is_file():
                return c
    return None


def locate(refresh: bool = False) -> dict:
    """Resolve Ghidra headless + java, using (and updating) the cache."""
    if not refresh and CACHE.is_file():
        try:
            cached = json.loads(CACHE.read_text())
            if Path(cached.get("headless", "")).is_file():
                return cached
        except Exception:
            pass

    headless: Path | None = None
    for c in _ghidra_probes():
        headless = c
        break
    if headless is None:
        headless = _on_path(["analyzeHeadless.bat", "analyzeHeadless"])
    if headless is None:
        raise SystemExit(
            "Ghidra not found. Tried env vars, ghidra.bat, tools/ghidra*/, "
            "drive roots, PATH. Set GHIDRA_HOME or edit the probes in this file."
        )

    java: Path | None = None
    for c in _java_probes():
        java = c
        break
    if java is None:
        java = _on_path(["java.exe", "java"])

    info = {
        "headless": _norm(headless),
        "home": _norm(headless.parent.parent),
        "java": _norm(java) if java else None,
        "project_dir": _norm(PROJECT_DIR),
        "project": PROJECT_NAME,
        "gscripts": _norm(GSCRIPTS),
    }
    CACHE.parent.mkdir(parents=True, exist_ok=True)
    CACHE.write_text(json.dumps(info, indent=2))
    return info


# --------------------------------------------------------------------------- commands

def cmd_locate(a) -> int:
    info = locate(refresh=a.refresh)
    for k, v in info.items():
        print(f"{k:12} {v}")
    return 0


def cmd_doctor(a) -> int:
    ok = True
    info = locate(refresh=False)
    checks = {
        "analyzeHeadless": Path(info["headless"]).is_file(),
        "ghidra home": Path(info["home"]).is_dir(),
        "java": bool(info["java"]) and Path(info["java"]).is_file(),
        "project dir": PROJECT_DIR.is_dir(),
        "gscripts dir": GSCRIPTS.is_dir(),
    }
    for name, good in checks.items():
        print(f"{'OK ' if good else 'FAIL'} {name}")
        ok = ok and good
    if info["java"] and Path(info["java"]).is_file():
        r = subprocess.run([info["java"], "-version"], capture_output=True, text=True)
        first = (r.stderr or r.stdout).splitlines()[0] if (r.stderr or r.stdout) else "?"
        print(f"     java: {first}")
    print(f"     cache: {CACHE}")
    return 0 if ok else 1


def cmd_list(a) -> int:
    idx = PROJECT_DIR / f"{PROJECT_NAME}.rep" / "idata" / "~index.dat"
    print("programs:")
    if idx.is_file():
        txt = idx.read_text(errors="replace")
        for m in re.finditer(r"\d{8}:([^:\r\n]+):[0-9a-f]", txt):
            print(f"  {m.group(1)}")
    else:
        print(f"  (cannot read {idx}; open Ghidra GUI or run with -process first)")
    print("gscripts:")
    for s in sorted(GSCRIPTS.glob("*.java")):
        print(f"  {s.name}")
    return 0


def _split_script(spec: str) -> list[str]:
    return spec.split()


def cmd_run(a) -> int:
    info = locate(refresh=False)
    argv = [info["headless"], str(PROJECT_DIR), PROJECT_NAME]
    if a.program:
        argv += ["-process", a.program]
        if not a.keep:
            pass  # NB: -process reopens the saved program; nothing extra needed
    argv += ["-noAnalysis"] if not a.analyze else []
    if a.read_only:
        argv += ["-readOnly"]
    for sp in a.scriptpath or [str(GSCRIPTS)]:
        argv += ["-scriptPath", sp]
    for spec in a.pre or []:
        argv += ["-preScript", *_split_script(spec)]
    for spec in a.post or []:
        argv += ["-postScript", *_split_script(spec)]
    if a.delete_project:
        argv += ["-deleteProject"]

    env = dict(os.environ)
    if info["java"]:
        env.setdefault("JAVA_HOME", str(Path(info["java"]).parent.parent))
    for kv in a.define or []:
        k, _, v = kv.partition("=")
        env[k] = v

    ANALYSIS_DIR.mkdir(parents=True, exist_ok=True)
    stamp = time.strftime("%Y%m%d-%H%M%S")
    prog_tag = (a.program or "project").replace(".", "_")
    log_path = Path(a.log) if a.log else ANALYSIS_DIR / f"headless_{prog_tag}_{stamp}.log"

    cmd = ["cmd", "/c", *argv] if sys.platform == "win32" else argv
    print("ghidra_run:", " ".join(argv))
    t0 = time.time()
    with open(log_path, "w", encoding="utf-8", errors="replace") as log:
        proc = subprocess.Popen(
            cmd, cwd=REPO, env=env, text=True,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, bufsize=1,
        )
        assert proc.stdout is not None
        for line in proc.stdout:
            log.write(line)
            verbose = a.verbose
            keep = _KEEP.search(line) if not verbose else True
            if keep:
                sys.stdout.write(line)
        rc = proc.wait()
    dt = time.time() - t0
    print(f"ghidra_run: exit {rc} in {dt:.0f}s; log {log_path}")
    return rc


_KEEP = re.compile(
    r"Vf3|seed|created|Seed|function|ERROR|Error|Exception|WARN|points|candidates|round"
)


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    sub = ap.add_subparsers(dest="cmd", required=True)

    p = sub.add_parser("locate", help="resolve ghidra/java, print and cache")
    p.add_argument("--refresh", action="store_true", help="ignore the cache and re-probe")
    p.set_defaults(fn=cmd_locate)

    p = sub.add_parser("doctor", help="verify the located toolchain")
    p.set_defaults(fn=cmd_doctor)

    p = sub.add_parser("list", help="list programs in the project and available gscripts")
    p.set_defaults(fn=cmd_list)

    p = sub.add_parser("run", help="run analyzeHeadless on the VF3 project")
    p.add_argument("program", nargs="?", help="program in the project (e.g. 1ST_READ.unsc.bin)")
    p.add_argument("--analyze", action="store_true",
                   help="let auto-analysis run (default: -noAnalysis, matching repo pipeline)")
    p.add_argument("--read-only", action="store_true", help="do not save program changes")
    p.add_argument("--delete-project", action="store_true", help="pass -deleteProject")
    p.add_argument("--scriptpath", action="append", help="extra script dir (repeatable)")
    p.add_argument("--pre", action="append", metavar="SPEC",
                   help='preScript, e.g. "MarkEntry.java" (repeatable)')
    p.add_argument("-p", "--post", action="append", metavar="SPEC",
                   help='postScript, e.g. "Vf3SeedPointers.java" or "Dump.java out.txt 0x8C..."')
    p.add_argument("-D", "--define", action="append", metavar="KEY=VAL",
                   help="env var for the run (repeatable; e.g. VF3_FORCE_FUNCS=...)")
    p.add_argument("--keep", action="store_true", help="(reserved) keep program state")
    p.add_argument("--verbose", "-v", action="store_true", help="echo all headless output")
    p.add_argument("--log", help="explicit log path (default extract/analysis/headless_*.log)")
    p.set_defaults(fn=cmd_run)

    a = ap.parse_args()
    return a.fn(a)


if __name__ == "__main__":
    raise SystemExit(main())
