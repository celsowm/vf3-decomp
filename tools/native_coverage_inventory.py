#!/usr/bin/env python3
"""Conservative native coverage of entries in the readable registry.

An entry counts when its vf3_native_<registry-name> function, or a manually
reviewed alternate name, has a C definition explicitly compiled into
vf3nativeview. This is a lower bound: other differently named and shared
implementations need review. A definition is not evidence that an entry is
exercised by the SDL3 game loop or has passed a differential test.
"""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parent.parent
registry = (ROOT / "src/fight/readable.c").read_text(encoding="utf-8")
cmake = (ROOT / "CMakeLists.txt").read_text(encoding="utf-8")
block = re.search(r"add_library\(vf3nativeview\s+STATIC\s+(.*?)\)", cmake, re.S)
if not block:
    raise SystemExit("vf3nativeview source list not found")
sources = re.findall(r"src/native/[\w./-]+\.c", block.group(1))
definitions = {}
for name in sources:
    source = (ROOT / name).read_text(encoding="utf-8")
    source = re.sub(r"/\*.*?\*/|//[^\n]*", "", source, flags=re.S)
    for match in re.finditer(r"\b(vf3_native_[A-Za-z0-9_]+)\s*\([^;{}]*\)\s*\{", source, re.S):
        definitions.setdefault(match.group(1), []).append(name)
# Reviewed alternate names: these functions implement the same guest entry,
# and the associated native replay tests exercise the mapping. Shared
# arithmetic helpers with a narrower interface are deliberately excluded.
aliases = {
    "rotate_x": "vf3_native_matrix_rotate_x",
    "rotate_y": "vf3_native_matrix_rotate_y",
    "rotate_z": "vf3_native_matrix_rotate_z",
    "float_scale_b": "vf3_native_float_scale",
    "div_signed": "vf3_native_mod_s32",
    "matrix_identity": "vf3_native_xmtrx_identity",
    "root_orientation": "vf3_native_root_orientation_entry",
}
entries = re.findall(r'\{\s*(0x0c[0-9a-fA-F]{6})u\s*,\s*"([^"]+)"', registry)
seen = set()
entries = [(address.lower(), name) for address, name in entries
           if not (address.lower() in seen or seen.add(address.lower()))]
def symbol(name):
    return aliases.get(name, "vf3_native_" + name)

covered = [(address, name, definitions[symbol(name)]) for address, name in entries
           if symbol(name) in definitions]
print(f"Registry entries: {len(entries)}")
print(f"Matched native definitions: {len(covered)} ({len(covered)*100/len(entries):.1f}%)")
print("Includes reviewed aliases; this is not a verified SDL3 runtime coverage figure.")
print("Unmatched registry entries:")
for address, name in entries:
    if symbol(name) not in definitions:
        print(f"  {address} {name}")
