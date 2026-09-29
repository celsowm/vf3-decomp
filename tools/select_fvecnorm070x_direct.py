#!/usr/bin/env python3
"""Select 0x8C0708B0 cases that actually take the 0x0C070A64 tail transfer.

The entry/exit capture can fall back to the enclosing caller's RTS on cases
that branch around 0x8C070920. Keep only rows whose observed output is the
direct transfer target and whose PR still matches the entry PR. Copy each
referenced RAM blob and descriptor beside the filtered cases file.
"""
from pathlib import Path
import argparse
import shutil


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("source", type=Path)
    ap.add_argument("output", type=Path)
    args = ap.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    kept = []
    for line in args.source.read_text().splitlines():
        fields = line.split()
        if len(fields) < 90:
            raise ValueError(f"malformed case row ({len(fields)} fields)")
        before = [int(x, 16) for x in fields[:37]]
        after = [int(x, 16) for x in fields[37:74]]
        if after[3] != 0x0C070A64 or after[16] != before[16]:
            continue
        nwin = int(fields[75], 16)
        exit_name_i = 76 + 2 * nwin
        for name in (fields[74], fields[exit_name_i]):
            for suffix in (".bin", ".meta"):
                src = args.source.parent / name.replace(".bin", suffix)
                dst = args.output / name.replace(".bin", suffix)
                if src.exists() and not dst.exists():
                    shutil.copyfile(src, dst)
        kept.append(line)
    out_file = args.output / args.source.name
    out_file.write_text("\n".join(kept) + ("\n" if kept else ""))
    print(f"{len(kept)} direct-tail cases -> {out_file}")


if __name__ == "__main__":
    main()
