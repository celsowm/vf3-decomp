#!/usr/bin/env python3
import os
from pathlib import Path

AN = Path('extract/analysis')
entries = ['8c09635a','8c063894','8c063d36','8c0441e6','8c0433f0','8c05e23c','8c062390','8c0a2eda','8c0c761e','8c093558','8c0c438e']

for e in entries:
    found = False
    for d in sorted(AN.glob('*cases')):
        f = d / f'f_{e}.cases'
        if f.exists():
            print(f'{d.name}: f_{e}.cases EXISTS ({f.stat().st_size} bytes)')
            found = True
            break
    if not found:
        print(f'{e}: NO .cases FILE in any corpus')