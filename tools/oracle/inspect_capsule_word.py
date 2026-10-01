#!/usr/bin/env python3
"""Inspect one watched invocation's before/after RAM word in raw capsules."""
import argparse
import struct
from capsules import records

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('capsule')
parser.add_argument('entry', type=lambda s: int(s, 0))
parser.add_argument('address', type=lambda s: int(s, 0))
args = parser.parse_args()
for record in records(args.capsule):
    if (record['entry'] | 0x80000000) != args.entry:
        continue
    for base, before, after in record['pages']:
        if base <= args.address <= base + len(before) - 4:
            offset = args.address - base
            a, b = struct.unpack_from('<I', before, offset)[0], struct.unpack_from('<I', after, offset)[0]
            print(f"id={record['id']} flags={record['flags']} before=0x{a:08x} after=0x{b:08x}")
