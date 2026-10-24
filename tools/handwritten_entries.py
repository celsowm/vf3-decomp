#!/usr/bin/env python3
"""handwritten_entries.py - the call targets a hand-written module already serves.

The readable-gap tool counts the generated adapters only, so a call target that
one of the hand-written modules already implements still shows up as unported.
This lists the entries the hand-written modules dispatch, so a candidate can be
checked before it is ported.

    python tools/handwritten_entries.py            # every entry
    python tools/handwritten_entries.py 0x0c040f1e  # is this one served?
"""
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
FIGHT = REPO / 'src' / 'fight'

# the generated modules carry the guest code; the hand-written ones do not
GENERATED = re.compile(r'(adapter|phase1|phase2|fifth|seventh|eighth|next|motion|'
                       r'sweep|ultimate|tickgap|device|phase1_adapters)')


def main():
    served = {}
    for path in sorted(FIGHT.glob('*.c')):
        if GENERATED.search(path.name):
            continue
        text = path.read_text(errors='replace')
        for m in re.finditer(r'case\s+(0x[0-9a-fA-F]+)u?\s*:', text):
            entry = int(m.group(1), 16)
            served.setdefault(entry, set()).add(path.name)
        # the `if(entry==0x...) return ...;` shape the dispatcher uses
        for m in re.finditer(r'entry\s*==\s*(0x[0-9a-fA-F]+)u?', text):
            entry = int(m.group(1), 16)
            served.setdefault(entry, set()).add(path.name)

    if len(sys.argv) > 1:
        entry = int(sys.argv[1], 16)
        files = served.get(entry)
        if files:
            print(f'0x{entry:08x} is served by {", ".join(sorted(files))}')
        else:
            print(f'0x{entry:08x} is not served by a hand-written module')
        return

    print(f'{len(served)} entries served by a hand-written module')
    for entry in sorted(served):
        print(f'0x{entry:08x} {", ".join(sorted(served[entry]))}')


if __name__ == '__main__':
    main()
