#!/usr/bin/env python3
"""trace_sum.py - summarise a port trace log: how often each entry was
entered and from which return address.

    python tools/trace_sum.py build/tr2.log
"""
from __future__ import annotations

import collections
import re
import sys
from pathlib import Path

ANSI = re.compile(r"\x1b\[[0-9;]*m")


def main() -> int:
    counts = collections.Counter()
    for raw in Path(sys.argv[1]).read_text(errors="replace").splitlines():
        line = ANSI.sub("", raw)
        m = re.match(r"\s*enter\s+([0-9a-f]{8})\s+pr\s+([0-9a-f]{8})", line)
        if not m:
            continue
        r4 = ""
        m4 = re.search(r"r4\s+([0-9a-f]{8})", line)
        if m4:
            r4 = m4.group(1)
        counts[(m.group(1), m.group(2), r4)] += 1
    for (entry, pr, r4), n in counts.most_common(40):
        print("%5d  entry %s  pr %s  r4 %s" % (n, entry, pr, r4))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
