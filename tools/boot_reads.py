#!/usr/bin/env python3
"""Compare the port's boot reads with the reference's real boot, request by request.

Both sides ask the drive for sectors; the addresses they use are FADs (the
drive's own sector address, FAD = LBA + 150).

The reference's log has two lines per transfer:

    hw/gdrom/gdromv3.cpp:773  SPI_CD_READ - Sector=45166 Size=1/2048 DMA=1
    hw/gdrom/gdromv3.cpp:1326 GDROM-DMA start addr 0C2A6300 len 2048 fad b06f

The first prints `read_params.start_sector` **as the command was parsed** - that
is the sector the guest asked for.  The second prints it *after* the transfer
advanced it, so its "fad" is the address of the sector **after** the one that
was read (for a one-sector read it is the request plus one).  Only the first
line is the request, so this tool parses that one.

The port's log prints its own requests:

    req cmd 17 params 0000b06e 00000001 0c2a6300 00000000

which is the FAD, the sector count, the destination and the flags.

Usage:
    python tools/boot_reads.py <reference.log> [port.log] [--iso rom/track03.bin]
"""
import argparse
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import iso9660 as I

# "SPI_CD_READ - Sector=45166 Size=1/2048 DMA=1" - the guest's request
REF_REQ_RE = re.compile(r"SPI_CD_READ - Sector=(\d+) Size=(\d+)/(\d+)")
# "GDROM-DMA start addr 0C2A6300 len 2048 fad b06f" - the transfer
REF_DMA_RE = re.compile(
    r"GDROM-DMA start addr ([0-9A-Fa-f]+) len (\d+) fad ([0-9a-fA-F]+)")
# the port's own request
PORT_RE = re.compile(
    r"req cmd 17 params ([0-9a-fA-F]{8}) ([0-9a-fA-F]{8}) ([0-9a-fA-F]{8})")


def volume(path):
    """Every file of the volume: name -> (lba, size)."""
    tr = I.Track(path)
    pvd = tr.user_at_fad(I.DATA_TRACK_LBA + I.FAD_PREGAP + 16)
    if pvd[:6] != b"\x01CD001":
        raise SystemExit(f"{path}: no primary volume descriptor")
    root = pvd[156:190]
    lba = struct.unpack_from("<I", root, 2)[0]
    ln = struct.unpack_from("<I", root, 10)[0]
    ents = I.walk(tr, lba, ln)
    tr.close()
    return [(f, r["lba"], r["size"]) for f, r in ents if not r["dir"]]


def owner(files, fad):
    """The file that owns a FAD, with the offset inside it."""
    lba = fad - I.FAD_PREGAP
    for full, start, size in files:
        ns = (size + I.USER - 1) // I.USER
        if start <= lba < start + ns:
            return full, size, (lba - start) * I.USER
    return None, None, None


def ref_requests(path):
    """(fad, count, dest, len) per request, in order.

    The request's sector is the SPI_CD_READ line; the destination and the
    length come from the GDROM-DMA line that follows it.
    """
    out = []
    pending = None
    with open(path, "r", errors="replace") as f:
        for line in f:
            m = REF_REQ_RE.search(line)
            if m:
                pending = (int(m.group(1)), int(m.group(2)))
                continue
            m = REF_DMA_RE.search(line)
            if m and pending is not None:
                dest = int(m.group(1), 16)
                ln = int(m.group(2))
                out.append((pending[0], pending[1], dest, ln))
                pending = None
    return out


def port_requests(path):
    """(fad, count, dest, len) per request, in order."""
    out = []
    with open(path, "r", errors="replace") as f:
        for line in f:
            m = PORT_RE.search(line)
            if m:
                fad = int(m.group(1), 16)
                cnt = int(m.group(2), 16)
                dest = int(m.group(3), 16)
                out.append((fad, cnt, dest, cnt * I.USER))
    return out


def show(label, reads, files, limit):
    print(f"=== {label}: {len(reads)} requests ===")
    print(f"{'#':>4} {'dest':>10} {'len':>9} {'fad':>8}  file")
    for i, (fad, cnt, dest, ln) in enumerate(reads[:limit]):
        full, size, off = owner(files, fad)
        name = f"{full} + {off}" if full else "(not a file)"
        print(f"{i:>4} {dest:>10x} {ln:>9d} {fad:>8x}  {name}")
    if len(reads) > limit:
        print(f"... {len(reads) - limit} more")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("reference")
    ap.add_argument("port", nargs="?")
    ap.add_argument("--iso", default="rom/track03.bin")
    ap.add_argument("--limit", type=int, default=30)
    a = ap.parse_args()

    files = volume(a.iso)
    print(f"volume: {len(files)} files")

    rr = ref_requests(a.reference)
    show("reference", rr, files, a.limit)
    if not a.port:
        return 0

    pr = port_requests(a.port)
    show("port", pr, files, a.limit)

    print()
    print(f"reference asks for {len(rr)} sectors, the port for {len(pr)}")
    n = 0
    while n < min(len(rr), len(pr)) and rr[n][0] == pr[n][0]:
        n += 1
    print(f"common prefix: {n} requests")
    if n < len(rr) and n < len(pr):
        full, size, off = owner(files, rr[n][0])
        print(f"  first difference: reference asks fad {rr[n][0]:#x} "
              f"({full}), the port asks fad {pr[n][0]:#x}")
    elif n < len(rr):
        full, size, off = owner(files, rr[n][0])
        print(f"  the port stops after {n} requests; the reference's next is "
              f"fad {rr[n][0]:#x} ({full})")
    else:
        print("  the port asks for every sector the reference does")
    return 0


if __name__ == "__main__":
    sys.exit(main())
