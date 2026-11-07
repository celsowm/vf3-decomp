# POL — VF3tb model packages

POL files contain model-slot references, texture descriptors, and tagged
model/mesh records. The checked native scene path covers the extracted
`MKAO_AKI`, `MKAO_JAC`, `ST01`, and `ST01_E` packages. Other POL generations
still need format-specific readers.

## Header

The fixed header is 0x30 bytes, little-endian:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | u32 | Header marker, `0x200` |
| `+0x04` | u32 | Build stamp, commonly `0x19981021` |
| `+0x08` | u32 | Per-file value; meaning unresolved |
| `+0x0C` | u16 | Model-slot count |
| `+0x0E` | u16 | Texture-descriptor count |
| `+0x10` | u32 | Model-slot table offset; `0x30` in checked fighter assets |
| `+0x14` | u32 | Texture-descriptor table offset |
| `+0x18` | u32 | Per-file value; meaning unresolved |
| `+0x1C` | u32 | Per-file value; meaning unresolved |

Examples: AKI has 22 slots and 10 descriptors, with the descriptor table at
`0x88`. JACKY has 43 slots and 13 descriptors, with the table at `0xE0` (four
bytes of padding after its slot table).

## Model slots

The slot table contains `slot_count` u32 words. The low bit is retained as a
tag; clearing it gives an in-file offset candidate in the two checked fighter
assets. For example, AKI's first value is `0x00035B19`, whose candidate is
`0x00035B18`. The full words and tag are preserved by `pol_slots`.
`pol_slot_spans` groups tagged references to the same target, then orders the
groups by file offset. Each group gets a bounded byte window ending at the
next distinct tagged target. AKI's first window is
`0x35B18..0x36598`. Slot order is not file order; repeated table entries may
alias the same payload. `pol_data_spans` also indexes every nonzero slot,
including untagged entries, with aliases sharing a window. This keeps raw
directory/rig candidates inspectable without assigning them a structure they
have not yet been shown to use. In AKI and JAC, the untagged entries are
bounded this way but their roles are still unresolved. In both packages, the
12 untagged slots form a bounded backwards-reference chain: each span starts
with an offset-like value equal to `start - 0x34`, and each later span's next
word points inside the preceding untagged span. The first span points back to
earlier package data. This relationship is checked by
`pol_asset_tables_replay`; the linked records' role and relationship to tagged
geometry remain unresolved. A reusable `--before-bytes 0x34` scan of
representative fighter nodes shows a repeated 52-byte prefix: the first word
is `1`, the second is an in-file offset 0x20 bytes before that prefix, the
words through `+0x1C` are zero, and `+0x20..+0x28` are three `1.0f` values;
the last two words are zero. These fields are recorded without assigning them
transform or hierarchy semantics. A four-byte scan across every tagged payload found
no exact references to those nodes' starts or their `start - 0x34` headers in
either fighter package. That excludes a direct pointer map from the current
mesh records; encoded or index-based relationships remain possible. The
reciprocal full-payload scan in `pol_slot_inspect.py --find-slot-references`
also finds no exact pointers from untagged payloads to tagged model starts in
either package. Thus the current evidence rules out direct slot-start pointers
in both directions, while encoded indices or an external lookup table remain
possible.

## Tagged model geometry

The tagged AKI, JAC, ST01, and ST01_E windows begin with an 0x18-byte model
header and then contain 0x50-byte mesh headers followed by polygon data. The mesh
header's u32 at `+0x4C` is the following polygon-data byte count; the u32 at
`+0x20` selects a texture descriptor. In ROB_WO2, `0xffffffff` marks an
untextured mesh; other indices must resolve to a descriptor. The C scene reader
preserves that sentinel, and the native SDL renderer submits those meshes with
no texture and white vertex color. Polygon data consists of 8-byte
type/count headers followed by vertex records. A type with bit 3 set carries
`count * 3` records and emits independent triangles. Other types carry
`count` records in triangle-strip order. A 32-byte vertex record contains
eight little-endian floats: position, normal, and UV. An 8-byte backward
reference reuses an earlier vertex in the package. In the checked packages,
its second word is a NaN-shaped encoded back-reference. A zero word and its
following count terminate the model.

The parser reads all tagged records in AKI, JAC, ST01, and ST01_E:
respectively 25, 42, 68, and 463 meshes; 2,452, 2,114, 2,381, and 41,033
unique vertices; and 6,618, 6,831, 7,251, and 114,306 triangle indices. The
mesh center/radius and color fields are retained; their remaining runtime
meaning is still open. ROB_WO2 has 64 tagged slots and 122 meshes in the
offline inventory, including ten untextured meshes using the all-ones marker.

## Texture descriptors

Each descriptor is 16 bytes at `model_block_offset`:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | u32 | Packed dimensions: width in low 16 bits, height in high 16 bits |
| `+0x04` | u32 | PVR pixel-format and data-layout codes |
| `+0x08` | u32 | Byte offset into the companion `.TEX` file |
| `+0x0C` | u32 | Reserved/unknown |

The native decoder supports square twiddled 16-bit pixels and non-mipmapped
VQ textures. AKI's first descriptor is 64x64 at offset 0; its second is 64x64
at `0x2000`; its fourth is 128x128 at `0x6000`. ST01 uses VQ descriptors; its
512x512 payload is a 2 KiB codebook followed by 65,536 block indices. The
decoder checks the compressed payload size against the companion `.TEX` file.

## C reader

`src/media/pol.c` provides bounds-checked `pol_header`, `pol_slots`,
`pol_slot_spans`, `pol_data_spans`, and `pol_textures` readers.
`src/media/pol_mesh.c` resolves the tagged geometry into native vertex and
index arrays. `src/media/pvr_texture.c` decodes square twiddled and VQ
textures. `tests/pol_asset_tables_replay.c` checks the fighter tables,
aliasing and textures; `tests/pol_mesh_replay.c` checks real models, every
nonzero fighter slot, and malformed bounds. The decoded `PolScene` retains a
`PolModel` row for each tagged payload, including its POL slot ID, file span,
and mesh range;
this preserves the source identities needed to recover fighter part selection
and pose application. `tests/native_view_replay.c` renders the stage and
fighters from the VFA archive. Slot identity is retained, while character rig
and transform semantics remain under investigation.

`tools/pol_model_inventory.py <file.POL>` is a read-only offline inspector for
the same tagged model slots. It reports per-mesh texture IDs (`none` for the
all-ones sentinel), vertex and
back-reference counts, index counts, and XYZ bounds; `--csv <path>` writes the
rows for comparison across character packages. These measurements describe
local model geometry and do not assign bone or action semantics.

`tools/pol_slot_inspect.py <file.POL>` inspects the bounded raw payloads behind
untagged slots (and tagged slots with `--all`). It reports aliases, leading
little-endian words, and values that happen to fall on another slot target.
Use `--slot N` to select one or more slots, `--words N` to change the preview
length, and `--floats` to view those same dwords as IEEE-754 values. The
reported in-file values are candidates only; the tool does not classify links,
rig records, or model parts.
`--find-slot-references` additionally scans each selected full payload for
exact pointers to tagged model starts and the same offsets with the low-bit
slot tag set, reporting the source file offset, encoding, and target slot IDs.
An empty result rules out only those direct-pointer forms; it does not rule
out encoded indices or external lookup tables.
`--before-bytes N` includes a bounded hex preview immediately before each
selected slot target. This is useful when a slot points into the middle of a
larger record and its preceding fields may contain header or chain data; the
preview exposes bytes without assigning them a meaning. For the 0x34-byte
prefix associated with the fighter untagged slots, use:

```text
python tools/pol_slot_inspect.py extract/gamedata/MKAO_JAC.POL --before-bytes 0x34
```
`--file-range OFFSET:SIZE` reads an exact file window as raw bytes and
little-endian dwords; repeat it to inspect several candidate link targets.
Ranges are bounded by the input file and the option cannot be combined with
slot scans:

```text
python tools/pol_slot_inspect.py extract/gamedata/MKAO_JAC.POL --file-range 0x1d4:0x60 --file-range 0x4db8:0x20
```

`tools/pol_scan.py FILE OUTPUT.png` is a heuristic float-triple point-cloud
viewer. `--split-dir DIR` writes each detected block separately, `--block N`
selects one zero-based block, and `--axes x-z` or `--axes y-z` changes the
projection. These previews help inspect raw vertex candidates; a run of finite
xyz floats does not prove a model boundary or triangle topology.
