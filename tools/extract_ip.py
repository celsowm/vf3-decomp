#!/usr/bin/env python3
"""Parse the Dreamcast IP.BIN bootstrap header -> docs/ip.md"""
import os
import struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IP_PATH = os.path.join(REPO, "extract", "ip", "IP.BIN")
DOCS = os.path.join(REPO, "docs")


def field(buf, off, n):
    return buf[off:off + n].decode("ascii", "replace").strip()


def main():
    with open(IP_PATH, "rb") as f:
        ip = f.read(32768)

    fields = [
        ("0x000", "Hardware ID", field(ip, 0x000, 16)),
        ("0x010", "Maker ID", field(ip, 0x010, 16)),
        ("0x020", "CRC (hex ascii)", field(ip, 0x020, 4)),
        ("0x024", "Device info", field(ip, 0x025, 11)),
        ("0x030", "Area codes", field(ip, 0x030, 8)),
        ("0x038", "Compatible peripherals", field(ip, 0x038, 8)),
        ("0x040", "Product number", field(ip, 0x040, 10)),
        ("0x04A", "Version", field(ip, 0x04A, 6)),
        ("0x050", "Release date", field(ip, 0x050, 8)),
        ("0x058", "(padding)", repr(field(ip, 0x058, 8))),
        ("0x060", "Boot filename", field(ip, 0x060, 16)),
        ("0x070", "Software maker", field(ip, 0x070, 16)),
        ("0x080", "Title", field(ip, 0x080, 128)),
    ]

    words = []
    for off in range(0x300, 0x340, 4):
        words.append((off, struct.unpack_from("<I", ip, off)[0]))

    with open(os.path.join(DOCS, "ip.md"), "w", newline="\n") as d:
        d.write("# IP.BIN header\n\n")
        d.write("| offset | field | value |\n|---|---|---|\n")
        for off, name, val in fields:
            d.write(f"| {off} | {name} | `{val}` |\n")
        d.write("\n## Words at 0x300-0x33F (IP init area: entry/stack/settings)\n\n")
        d.write("| offset | LE u32 | hex |\n|---|---|---|\n")
        for off, val in words:
            d.write(f"| 0x{off:03X} | {val} | 0x{val:08X} |\n")
        d.write("\nNote: retail games are loaded and entered at 0x8C010000 via 1ST_READ.BIN.\n")

    for off, name, val in fields:
        print(f"{off} {name}: {val}")


if __name__ == "__main__":
    main()
