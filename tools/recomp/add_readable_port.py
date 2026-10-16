#!/usr/bin/env python3
"""Register a new readable port: CMakeLists source line, readable.c prototype and table row.

  add_readable_port.py --entry 0x8c073aac --name hitbox_overlap --src src/fight/hitbox_overlap.c \
      [--mask "B(8) | B(9) ..."] [--after chain_frames] [--doc "description"]

--func defaults to vf3_<name>_entry. --mask defaults to B(8)..B(17) (callee-saved + pr + sr).
--after names the CMake source (without .c) and table row the new lines follow; default: the last
port registered in CMakeLists before chain_readable.c. --doc also appends a row to
docs/re/oracle_recomp.md after the --after port's row. Byte-level edits keep each file's EOL.
"""
import argparse, re, sys

def edit(path, fn):
    b = open(path, 'rb').read()
    nb = fn(b)
    open(path, 'wb').write(nb)

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--entry', required=True)
    ap.add_argument('--name', required=True)
    ap.add_argument('--src', required=True)
    ap.add_argument('--func')
    ap.add_argument('--mask', default=' | '.join(f'B({i})' for i in range(8, 18)))
    ap.add_argument('--after', required=True, help='existing port name to insert after, e.g. chain_frames')
    ap.add_argument('--doc')
    a = ap.parse_args()
    func = a.func or f'vf3_{a.name}_entry'
    entry = int(a.entry, 16) & 0x0FFFFFFF | 0x0C000000
    nl = b'\n'
    def cm(b):
        old = f'    src/fight/{a.after}.c'.encode()
        assert b.count(old) == 1, 'CMake anchor'
        eol = b'\r\n' if b'\r\n' in b else nl
        return b.replace(old + eol, old + eol + f'    {a.src}'.encode() + eol)
    edit('CMakeLists.txt', cm)
    def rc(b):
        eol = b'\r\n' if b'\r\n' in b else nl
        proto = f'int {func}(vf3_matrix_state *s, const vf3_ram_map *ram);'.encode()
        m = list(re.finditer(rb'int vf3_\w+_entry\(vf3_matrix_state \*s, const vf3_ram_map \*ram\);' + eol, b))
        assert m, 'prototype anchor'
        k = m[-1].end()
        b = b[:k] + proto + eol + b[k:]
        row = f'    {{ 0x{entry:08x}u, "{a.name}", {func},{eol.decode()}      {a.mask} }},{eol.decode()}'.encode()
        anchor = re.search(rb'    \{ 0x0c[0-9a-f]{6}u, "' + a.after.encode() + rb'"', b)
        assert anchor, 'row anchor'
        # insert before the --after row (table order is not significant)
        return b[:anchor.start()] + row + b[anchor.start():]
    edit('src/fight/readable.c', rc)
    if a.doc:
        def dc(b):
            m = re.search(rb'\| `0x8c[0-9a-f]+` \| ' + a.after.encode() + rb' \|[^\n]*\n', b)
            assert m, 'doc anchor'
            row = f'| `0x8c{entry & 0xFFFFFF:06x}` | {a.name} | `{a.src.split("/")[-1]}` | {a.doc} |\n'.encode()
            return b[:m.end()] + row + b[m.end():]
        edit('docs/re/oracle_recomp.md', dc)
    print('registered', a.name, hex(entry))

main()
