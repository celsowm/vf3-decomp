#!/usr/bin/env python3
"""mutate.py - prove that a differential test has teeth.

A readable port is proved by running it against the retained generated
translation and comparing the two.  That comparison passes for a wrong port
too, if the fixture is laid out where the guest does not look: both sides
read the same bytes and agree on them.  The way to find that out is to break
the port on purpose and require the test to notice.

This tool applies one mutation at a time to a port's source, rebuilds, runs
the port's test and records whether the test failed.  A mutation that the test
does not catch is a path the test never reaches - unless the mutation is one
of the ones the guest's own behaviour makes unobservable, and the port's
documentation says so.

    python tools/mutate.py --port src/fight/float_blend.c \\
                           --exe build/vf3floatblend.exe \\
                           --mutations tests/float_blend_mutations.json

--target names the ninja target to rebuild.  The port's own test target is
usually enough and much faster than relinking every test in the tree; without
it the whole build is rebuilt after each mutation.

The mutation file is JSON: a list of objects with a name and a list of
substitutions, each a [old, new] pair of strings that must occur in the port
source.  The first occurrence of each pair is replaced.

The port's source is restored and rebuilt when the run ends, whatever happens.
"""
import argparse
import json
import os
import shutil
import subprocess
import sys
from pathlib import Path


def load_mutations(path):
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    out = []
    for entry in data:
        subs = [(s[0], s[1]) for s in entry["subs"]]
        out.append((entry["name"], subs))
    return out


def build(build_dir, target=None):
    cmd = ["ninja", "-C", str(build_dir)]
    if target:
        cmd.append(target)
    return subprocess.run(cmd, capture_output=True, text=True)


def run(exe):
    return subprocess.run([str(exe)], capture_output=True, text=True)


def first_line(text):
    for line in (text or "").splitlines():
        if line.strip():
            return " ".join(line.split())
    return ""


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--port", required=True,
                    help="the readable port's source, mutated in place")
    ap.add_argument("--exe", required=True, help="the port's test binary")
    ap.add_argument("--mutations", required=True, help="the mutation file")
    ap.add_argument("--build", default="build", help="the build directory")
    ap.add_argument("--target",
                    help="the ninja target to rebuild (default: all of them); "
                         "the port's own test target is usually enough")
    ap.add_argument("--keep-going", action="store_true",
                    help="do not stop at the first missed mutation")
    args = ap.parse_args()

    port = Path(args.port).resolve()
    exe = Path(args.exe).resolve()
    build_dir = Path(args.build).resolve()
    mutations = load_mutations(args.mutations)

    if not exe.exists():
        print(f"no such test binary: {exe}")
        return 2

    original = port.read_bytes()
    results = []
    try:
        for name, subs in mutations:
            text = original.decode("utf-8")
            missing = None
            for old, new in subs:
                if old not in text:
                    missing = old
                    break
                text = text.replace(old, new, 1)
            if missing is not None:
                print(f"{name}: PATTERN NOT FOUND: {missing!r}")
                results.append((name, False, "pattern missing"))
                continue
            port.write_bytes(text.encode("utf-8"))
            b = build(build_dir, args.target)
            if b.returncode != 0:
                print(f"{name}: BUILD FAILED")
                print((b.stdout or "")[-1500:], (b.stderr or "")[-1500:])
                results.append((name, False, "build failed"))
                continue
            r = run(exe)
            caught = r.returncode != 0
            print(f"{name}: {'CAUGHT' if caught else 'MISSED'} :: "
                  f"{first_line(r.stdout)}{first_line(r.stderr)}".rstrip())
            results.append((name, caught, first_line(r.stdout)))
            if not caught and not args.keep_going:
                break
    finally:
        port.write_bytes(original)
        build(build_dir, args.target)

    missed = [n for n, c, _ in results if not c]
    print(f"\n{len(results) - len(missed)}/{len(results)} mutations caught")
    if missed:
        print("MISSED: " + ", ".join(missed))
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
