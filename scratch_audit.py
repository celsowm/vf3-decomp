#!/usr/bin/env python3
"""Reconstruct the native-coverage audit.

Counts how many registry entries (readable.c) are natively served: an entry at
0x0cXXXXXX is served iff its low-6 address literal ("0cXXXXXX") appears in some
src/native/*.c file.  Mirrors the deleted scratch_audit.py per the checkpoint.
"""
import re, sys

def implied():
    reg = {}
    for line in open('src/fight/readable.c', encoding='utf-8', errors='replace'):
        m = re.match(r'\s*\{\s*(0x0c[0-9a-fA-F]{6})u,\s*"([^"]+)"', line)
        if m:
            reg[m.group(1).lower()] = m.group(2)

    native = []
    import glob
    for path in glob.glob('src/native/*.c'):
        native.append(open(path, encoding='utf-8', errors='replace').read())
    nativetext = '\n'.join(native).lower()

    served = []
    unserved = []
    for addr, name in sorted(reg.items()):
        low6 = addr[-6:]  # last 6 hex digits, e.g. 03f830 for 0x0c03f830
        if low6 in nativetext:
            served.append((addr, name))
        else:
            unserved.append((addr, name))
    return reg, served, unserved

if __name__ == '__main__':
    reg, served, unserved = implied()
    total = len(reg)
    print(f"registry entries: {total}")
    print(f"natively served:  {len(served)}  ({len(served)/total*100:.1f}%)")
    print(f"unserved:         {len(unserved)}")
    print("\nUNSERVED:")
    for addr, name in unserved:
        print(f"  {addr}  {name}")
