#!/usr/bin/env python3
"""iso_list.py — minimal ISO9660 directory walker (no deps).

Usage: python tools/iso_list.py <iso> [substring]
Prints path + size for every file (or those matching substring).
"""
import struct
import sys


def read_iso(path):
    return open(path, "rb").read()


def walk(data):
    # Primary Volume Descriptor at sector 16 (2048)
    pvd = data[16 * 2048:16 * 2048 + 2048]
    if pvd[0] != 1 or pvd[1:6] != b"CD001":
        # try 32k offset (raw track)
        for base in (16 * 2048, 32768, 0):
            if data[base:base + 6] == b"\x01CD001":
                pvd = data[base:base + 2048]
                break
    root = pvd[156:156 + 34]
    extent = struct.unpack_from("<I", root, 2)[0]
    size = struct.unpack_from("<I", root, 10)[0]
    out = []
    seen = set()

    def rec(sector, length, prefix):
        if sector in seen:
            return
        seen.add(sector)
        off = sector * 2048
        end = off + length
        p = off
        while p < end and p + 33 <= len(data):
            rlen = data[p]
            if rlen == 0:
                p = ((p // 2048) + 1) * 2048
                continue
            rec_len = rlen
            ext = struct.unpack_from("<I", data, p + 2)[0]
            sz = struct.unpack_from("<I", data, p + 10)[0]
            flags = data[p + 25]
            nlen = data[p + 32]
            name = data[p + 33:p + 33 + nlen]
            if name not in (b"\x00", b"\x01"):
                nm = name.decode("ascii", "replace").split(";")[0]
                full = prefix + "/" + nm
                if flags & 2:
                    out.append((full + "/", 0))
                    # capture subdir extent/len before advancing
                    sub = (ext, sz, full)
                    rec(ext, sz, full)
                else:
                    out.append((full, sz))
            p += rec_len

    rec(extent, size, "")
    return out


def main():
    iso = sys.argv[1]
    pat = sys.argv[2].lower() if len(sys.argv) > 2 else ""
    data = read_iso(iso)
    rows = walk(data)
    for path, sz in rows:
        if pat and pat not in path.lower():
            continue
        print(f"{sz:10d}  {path}")


if __name__ == "__main__":
    main()