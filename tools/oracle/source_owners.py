"""Discover advisory C ownership from linked adapter routes, without ledger credit.

Only CMake-linked sources and their local .inc files participate. Dispatcher
priority resolves overlapping adapters; retired source files are not scanned.
Presence of a translated entry is a planning lead, not a complete-body proof.
"""
import argparse
import csv
import io
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]
HEX = re.compile(r'0x([0-9a-fA-F]{8})[uU]?')


def function_body(text, symbol):
    match = re.search(r'\bint\s+' + re.escape(symbol) + r'\s*\([^;{}]*\)\s*\{', text)
    if not match:
        return None
    start = match.end()
    depth = 1
    for index in range(start, len(text)):
        depth += (text[index] == '{') - (text[index] == '}')
        if depth == 0:
            return text[start:index]
    raise ValueError(f'unclosed function: {symbol}')


def chunks(source):
    seen, pending = set(), [source]
    while pending:
        path = pending.pop().resolve()
        if path in seen:
            continue
        if not path.is_relative_to(ROOT / 'src'):
            raise ValueError(f'include outside source tree: {path}')
        seen.add(path)
        text = path.read_text()
        yield path, text
        for include in re.findall(r'^\s*#include\s+"([^"\n]+\.inc)"', text, re.M):
            child = path.parent / include
            if not child.is_file():
                child = ROOT / 'src' / include
            pending.append(child)


def linked_sources(build):
    paths = set()
    for target in ('vf3core', 'vf3matrixfamily'):
        metadata = build / 'CMakeFiles' / (target + '.dir') / 'DependInfo.cmake'
        if not metadata.is_file():
            raise FileNotFoundError(metadata)
        for name in re.findall(r'^\s*"([^"\n]+\.c)"\s+"', metadata.read_text(), re.M):
            path = Path(name).resolve()
            if path.is_relative_to(ROOT / 'src'):
                paths.add(path)
    return sorted(paths)


def ownership(sources, dispatch, entries):
    implementations, fallbacks = {}, {}
    for source in sources:
        owner = source.relative_to(ROOT).as_posix()
        for _, text in chunks(source):
            arrays = {match[1]: {int(value, 16) | 0x80000000 for value in HEX.findall(match[2])}
                      for match in re.finditer(r'const\s+uint32_t\s+(\w+)\[\]\s*=\s*\{(.*?)\};',
                                               text, re.S)}
            for symbol in re.findall(r'\bint\s+(\w+_contains)\s*\(', text):
                body = function_body(text, symbol)
                if body is None:
                    continue
                pcs = {int(value, 16) | 0x80000000 for value in
                       re.findall(r'\bcase\s+0x([0-9a-fA-F]{8})[uU]?\s*:', body)}
                for array, values in arrays.items():
                    if re.search(r'\b' + re.escape(array) + r'\b', body):
                        pcs.update(values)
                implementation = (owner, pcs)
                if symbol in implementations and implementations[symbol] != implementation:
                    raise ValueError(f'multiple linked owners for {symbol}')
                implementations[symbol] = implementation
            body = function_body(text, 'vf3_matrix_adapter')
            if body is not None:
                for value in re.findall(r'\bcase\s+0x([0-9a-fA-F]{8})[uU]?\s*:', body):
                    fallbacks[int(value, 16) | 0x80000000] = owner
    routes = re.findall(r'if\s*\(\s*(\w+_contains)\s*\(entry\)', dispatch)
    owners, unresolved = {}, []
    for route in routes:
        if route not in implementations:
            unresolved.append(route)
            continue
        owner, pcs = implementations[route]
        for entry in sorted(pcs & entries):
            owners.setdefault(entry, owner)
    for entry in sorted(entries & fallbacks.keys()):
        owners.setdefault(entry, fallbacks[entry])
    return owners, unresolved


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--build', type=Path, default=ROOT / 'build')
    parser.add_argument('--inventory', type=Path, default=ROOT / 'extract/analysis/funcs_1ST_READ.unsc.bin.csv')
    parser.add_argument('--manual-map', type=Path)
    parser.add_argument('--resolved-calls', type=Path,
                        help='also map resolved direct-call targets in inventory gaps')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    entries = {int(row['entry'], 16) for row in csv.DictReader(io.StringIO(args.inventory.read_text()))}
    inventory_count = len(entries)
    if args.resolved_calls:
        entries.update(int(row['target'], 16) for row in
                       csv.DictReader(io.StringIO(args.resolved_calls.read_text()))
                       if row.get('target'))
    sources = linked_sources(args.build)
    owners, unresolved = ownership(sources, (ROOT / 'src/fight/matrix_family.c').read_text(), entries)
    if args.manual_map:
        for entry, source in json.loads(args.manual_map.read_text()).items():
            path = (ROOT / source).resolve()
            if not path.is_relative_to(ROOT / 'src') or not path.is_file():
                raise ValueError(f'invalid manual owner: {source}')
            owners[int(entry, 16) | 0x80000000] = path.relative_to(ROOT).as_posix()
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps({hex(entry): owner for entry, owner in sorted(owners.items())}, indent=1) + '\n')
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(dict(advisory=True, ledger_credit=False,
        inventory_entries=inventory_count, requested_entries=len(entries), mapped_entries=len(owners),
        linked_sources=[path.relative_to(ROOT).as_posix() for path in sources],
        unresolved_routes=unresolved), indent=1) + '\n')
    print(f'{len(owners)} advisory C owners; {len(unresolved)} unresolved adapter routes; no ledger credit')


if __name__ == '__main__':
    main()
