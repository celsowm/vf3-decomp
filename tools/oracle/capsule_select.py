#!/usr/bin/env python3
"""Select VF3CAP invocations by their entry registers, RAM words and PCs."""
from __future__ import annotations

import argparse
import struct
from pathlib import Path

from capsules import records
from inspect_capsule import register_index


def canonical(address: int) -> int:
    return address & 0x1FFFFFFF


def before_register(record: dict, name: str) -> int | None:
    index = register_index(name)
    if index >= record["nstate"]:
        return None
    return struct.unpack_from("<I", record["before"], index * 4)[0]


def ram_word(record: dict, address: int, side: str = "before") -> int | None:
    physical = canonical(address)
    for base, before, after in record["pages"]:
        data = before if side == "before" else after
        offset = physical - base
        if 0 <= offset <= len(data) - 4:
            return struct.unpack_from("<I", data, offset)[0]
    return None


def matches(record: dict, *, registers: dict[str, int] | None = None,
            words: dict[int, int] | None = None, pcs: list[int] | None = None) -> bool:
    for name, expected in (registers or {}).items():
        if before_register(record, name) != expected:
            return False
    for address, expected in (words or {}).items():
        if ram_word(record, address) != expected:
            return False
    observed = {canonical(pc) for pc, _ in record["ops"]}
    return all(canonical(pc) in observed for pc in (pcs or []))


def parse_assignment(value: str, label: str) -> tuple[str, int]:
    if "=" not in value:
        raise ValueError(f"{label} must be NAME=VALUE")
    name, number = value.split("=", 1)
    if not name:
        raise ValueError(f"{label} has an empty name")
    try:
        parsed = int(number, 0)
    except ValueError:
        raise ValueError(f"{label} value must be an integer or base-prefixed number") from None
    if not 0 <= parsed <= 0xFFFFFFFF:
        raise ValueError(f"{label} value is outside uint32 range")
    return name, parsed


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("capsules", nargs="+", type=Path)
    parser.add_argument("--entry", type=lambda value: int(value, 0), required=True)
    parser.add_argument("--reg", action="append", default=[], metavar="NAME=VALUE",
                        help="match an entry register (r0-r15, pr, sr, frN, xfN, ...) ")
    parser.add_argument("--word", action="append", default=[], metavar="ADDRESS=VALUE",
                        help="match a captured entry RAM word")
    parser.add_argument("--pc", action="append", default=[], type=lambda value: int(value, 0),
                        help="require this PC in the invocation instruction stream")
    parser.add_argument("--show-reg", action="append", default=[], metavar="NAME")
    parser.add_argument("--show-word", action="append", default=[], type=lambda value: int(value, 0),
                        metavar="ADDRESS")
    parser.add_argument("--last-ops", type=int, default=0,
                        help="print the last N recorded instructions")
    parser.add_argument("--limit", type=int, default=40)
    args = parser.parse_args()
    if args.limit < 0 or args.last_ops < 0:
        parser.error("--limit and --last-ops must be nonnegative")
    try:
        registers = dict(parse_assignment(value, "--reg") for value in args.reg)
        words = {int(name, 0): value
                 for name, value in (parse_assignment(item, "--word") for item in args.word)}
        shown_registers = [register_index(name) for name in args.show_reg]
    except ValueError as error:
        parser.error(str(error))

    matched = 0
    for path in args.capsules:
        for record in records(path):
            if canonical(record["entry"]) != canonical(args.entry):
                continue
            if not matches(record, registers=registers, words=words, pcs=args.pc):
                continue
            matched += 1
            if matched > args.limit:
                break
            print(f"{path} id={record['id']} flags={record['flags']} "
                  f"exit=0x{record['exitpc']:08x}")
            for index, name in zip(shown_registers, args.show_reg):
                value = before_register(record, name)
                text = "unavailable" if value is None else f"0x{value:08x}"
                print(f"  {name}={text}")
            for address in args.show_word:
                before = ram_word(record, address, "before")
                after = ram_word(record, address, "after")
                left = "uncaptured" if before is None else f"0x{before:08x}"
                right = "uncaptured" if after is None else f"0x{after:08x}"
                print(f"  [0x{address:08x}] {left} -> {right}")
            if args.last_ops:
                selected = record["ops"][-args.last_ops:]
                print("  ops=" + " ".join(f"{pc:08x}:{opcode:04x}" for pc, opcode in selected))
        if matched > args.limit:
            break
    print(f"{min(matched, args.limit)} matching invocations"
          + (" (more exist)" if matched > args.limit else ""))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
