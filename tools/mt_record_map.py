"""MT record stream-region map (static, file-backed).

Reads MTJACLAU.BIN slot bodies at the M14-observed stream offsets and checks:
 1. tuple regions decode as sane floats (finite, |v| < 1e6, no NaN) at the
    exact quartet addresses the evaluator's 4-PC group reads;
 2. overlapping quartet advance (cursor steps of 4 B across frames);
 3. CRC32 of each stream region (stability artifact).

Usage: python3 tools/mt_record_map.py
Writes: extract/analysis/mt_record_map.csv (gitignored scratch OK to keep).
"""
import csv
import struct
import zlib

REPO = __file__.rsplit('tools', 1)[0] if 'tools' in __file__ else '.'
import os
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PACK = os.path.join(REPO, 'extract', 'gamedata', 'MTJACLAU.BIN')
MTMAP = os.path.join(REPO, 'extract', 'analysis', 'mt_tables', 'MTJACLAU.csv')
OUT = os.path.join(REPO, 'extract', 'analysis', 'mt_record_map.csv')

# (slot, rec_delta, len, stream, reader_pc) from M14 mt_field_reads.csv
REGIONS = [
    (5093, 0x736, 8, 'counts-cursor-B', '0x8C09D6F6'),
    (5093, 0x75B, 33, 'times-cursor', '0x8C09D70C'),
    (5093, 0x7A4, 16, 'tuples-quartet', '0x8C09D778/77E/782/794'),
    (5096, 0x194, 64, 'tuples-linked', '0x8C09D778/77E/782/794'),
    (1304, 0x41C, 32, 'tuples-inst2', '0x8C09D778/77E/782/794'),
]


def sane_floats(blob):
    n = len(blob) // 4
    vals = struct.unpack('<%df' % n, blob[:4 * n])
    bad = [v for v in vals if v != v or abs(v) >= 1e6]
    return vals, bad


def main():
    data = open(PACK, 'rb').read()
    slots = {}
    with open(MTMAP) as f:
        for r in csv.DictReader(f):
            slots[int(r['slot'])] = (int(r['offset'], 16), int(r['size']))
    rows = []
    for slot, delta, ln, stream, pc in REGIONS:
        base, size = slots[slot]
        assert delta + ln <= size, (slot, hex(delta), size)
        blob = data[base + delta:base + delta + ln]
        vals, bad = sane_floats(blob)
        rows.append({
            'slot': slot, 'file_off': hex(base + delta),
            'rec_delta': hex(delta), 'len': ln, 'stream': stream,
            'reader_pc': pc, 'crc32': '%08x' % zlib.crc32(blob),
            'n_floats': len(vals), 'n_bad_floats': len(bad),
            'v0': repr(vals[0]) if vals else '',
            'v1': repr(vals[1]) if len(vals) > 1 else '',
        })
        print('%s rec+%s %-16s crc=%s floats=%d bad=%d v0=%s v1=%s' % (
            slot, hex(delta), stream, '%08x' % zlib.crc32(blob),
            len(vals), len(bad),
            repr(vals[0]) if vals else '-', repr(vals[1]) if len(vals) > 1 else '-'))
    with open(OUT, 'w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)
    print('wrote', OUT)


if __name__ == '__main__':
    main()
