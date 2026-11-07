#!/usr/bin/env python3
"""Extract SH-4 RAM from a Flycast savestate using the loaded game image.

This is an offline RE helper. It decompresses a Flycast RZIP savestate, finds
the game image at its known SH-4 address, and uses that occurrence to locate
the serialized 16 MiB main-RAM block. When runtime changes have modified the
image, it can infer RAM from distributed image chunks. It never modifies the
state.

Examples:
  python tools/flycast_ram.py tools/emu/flycast-build/data/vf3_29.state \
      --image extract/exe/1ST_READ.unsc.bin --read 0x0c1fefe4:0x60
  python tools/flycast_ram.py tools/emu/flycast-build/data/vf3_29.state \
      --image extract/exe/1ST_READ.unsc.bin --dump extract/analysis/vf3_29.ram
"""

from __future__ import annotations

import argparse
from pathlib import Path
import sys

from aica_state import load_state

RAM_BASE = 0x0C000000
RAM_SIZE = 0x01000000
ADDRESS_MASK = 0x1FFFFFFF
DEFAULT_IMAGE_ADDRESS = 0x0C010000


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f"invalid integer: {text}") from exc
    if not 0 <= value <= 0xFFFFFFFF:
        raise argparse.ArgumentTypeError("value must fit in 32 bits")
    return value


def read_spec(text: str) -> tuple[int, int]:
    try:
        address_text, size_text = text.split(":", 1)
        address, size = number(address_text), int(size_text, 0)
    except (ValueError, argparse.ArgumentTypeError) as exc:
        raise argparse.ArgumentTypeError("expected ADDRESS:SIZE") from exc
    if size <= 0:
        raise argparse.ArgumentTypeError("read size must be positive")
    return address, size


def locate_image_chunk_candidate(blob: bytes, image: bytes,
                                image_offset: int) -> tuple[int, int]:
    """Infer the RAM base from matching chunks spread across the image.

    Some states contain a game image that was patched after loading, so a
    single leading prefix is not always reliable. Several independent chunks
    can still identify the same serialized RAM block.
    """
    chunk_size = 0x400
    stride = 0x10000
    image_chunks = list(range(0, len(image) - chunk_size + 1, stride))
    image_chunks.append(len(image) - chunk_size)
    candidates: dict[int, set[int]] = {}
    for image_chunk_offset in sorted(set(image_chunks)):
        chunk = image[image_chunk_offset:image_chunk_offset + chunk_size]
        if len(set(chunk)) < 32:
            continue
        position = blob.find(chunk)
        while position >= 0:
            ram_offset = position - image_offset - image_chunk_offset
            if ram_offset >= 0 and ram_offset + RAM_SIZE <= len(blob):
                candidates.setdefault(ram_offset, set()).add(image_chunk_offset)
            position = blob.find(chunk, position + 1)

    ranked = sorted(((len(offsets), offset) for offset, offsets in candidates.items()),
                    reverse=True)
    if not ranked or ranked[0][0] < 3:
        raise ValueError("no RAM block supported by three distributed image chunks")
    if len(ranked) > 1 and ranked[0][0] == ranked[1][0]:
        raise ValueError("distributed image chunks match multiple RAM offsets equally")
    return ranked[0][1], ranked[0][0]


def locate_ram(blob: bytes, image: bytes, image_address: int,
               anchor_bytes: int | None) -> tuple[int, bytes, str]:
    if not image:
        raise ValueError("image anchor is empty")
    image_physical = image_address & ADDRESS_MASK
    image_offset = image_physical - RAM_BASE
    if not 0 <= image_offset < RAM_SIZE:
        raise ValueError("image address is outside the 16 MiB SH-4 RAM window")

    if anchor_bytes is None:
        sizes = []
        candidate = min(len(image), 1 << (len(image).bit_length() - 1))
        while candidate >= 0x400:
            sizes.append(candidate)
            candidate //= 2
        if len(image) not in sizes:
            sizes.insert(0, len(image))
    else:
        if not 0x100 <= anchor_bytes <= len(image):
            raise ValueError("anchor length must be between 0x100 and the image size")
        sizes = [anchor_bytes]

    first = -1
    matched_size = 0
    for size in sizes:
        signature = image[:size]
        candidate = blob.find(signature)
        if candidate >= 0 and blob.find(signature, candidate + 1) < 0:
            first = candidate
            matched_size = size
            break
    if first >= 0:
        ram_offset = first - image_offset
        if 0 <= ram_offset and ram_offset + RAM_SIZE <= len(blob):
            ram = blob[ram_offset:ram_offset + RAM_SIZE]
            if ram[image_offset:image_offset + matched_size] == image[:matched_size]:
                return ram_offset, ram, f"image prefix 0x{image_address:08x}+0x{matched_size:x} verified"
    elif anchor_bytes is not None:
        raise ValueError("no unique image prefix found in the decompressed savestate")

    if anchor_bytes is not None:
        raise ValueError("image prefix does not lead to a complete serialized RAM block")
    ram_offset, matched_chunks = locate_image_chunk_candidate(
        blob, image, image_offset)
    ram = blob[ram_offset:ram_offset + RAM_SIZE]
    return ram_offset, ram, f"{matched_chunks} distributed image chunks verified"


def read_ram(ram: bytes, address: int, size: int) -> bytes:
    physical = address & ADDRESS_MASK
    offset = physical - RAM_BASE
    if offset < 0 or size > RAM_SIZE - offset:
        raise ValueError(f"read {address:#010x}+{size:#x} is outside SH-4 RAM")
    return ram[offset:offset + size]


def dump_read(address: int, data: bytes) -> None:
    for offset in range(0, len(data), 16):
        row = data[offset:offset + 16]
        ascii_text = "".join(chr(byte) if 32 <= byte < 127 else "." for byte in row)
        print(f"{address + offset:08x}  {row.hex(' '):<47}  |{ascii_text}|")


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("state", type=Path, help="Flycast savestate")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact game image loaded at --image-address")
    parser.add_argument("--image-address", type=number, default=DEFAULT_IMAGE_ADDRESS,
                        help="SH-4 address of the image (default: 0x0c010000)")
    parser.add_argument("--anchor-bytes", type=number,
                        help="require this many leading image bytes to match; default tries a unique prefix")
    parser.add_argument("--read", type=read_spec, action="append", default=[],
                        metavar="ADDRESS:SIZE", help="read a RAM range; repeatable")
    parser.add_argument("--dump", type=Path, help="write the raw 16 MiB RAM image")
    args = parser.parse_args(argv)
    if not args.read and not args.dump:
        parser.error("choose at least one --read or --dump")
    if args.dump and args.dump.exists():
        parser.error(f"refusing to replace existing dump: {args.dump}")

    try:
        image = args.image.read_bytes()
        blob = load_state(str(args.state))
        ram_offset, ram, anchor_text = locate_ram(
            blob, image, args.image_address, args.anchor_bytes)
        print(f"{args.state}: RAM at decompressed offset 0x{ram_offset:x}; {anchor_text}")
        for address, size in args.read:
            data = read_ram(ram, address, size)
            print(f"read {address:#010x} ({size} bytes)")
            dump_read(address, data)
        if args.dump:
            args.dump.parent.mkdir(parents=True, exist_ok=True)
            args.dump.write_bytes(ram)
            print(f"wrote {args.dump} ({len(ram)} bytes)")
    except (OSError, ValueError) as exc:
        print(f"flycast_ram: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
