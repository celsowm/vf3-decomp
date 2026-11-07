# MT*.BIN — VF3tb motion files (paired-fighter packs)

91 files `MT<abc><def>.BIN`, each covers an "A vs B" pairing.

## Table
- `0x0000..0x8ABF`: 8,880 × u32 slot table (≈76% empty = 0)
- every nonzero slot holds a record offset (min is always `0x8AC0`)
- slot order is not file-offset order; multiple slots may alias one offset
- record size = next greater distinct payload offset − this offset (or EOF)

The 91 files contain 209,925 nonzero slot references and 203,216 distinct
payload offsets. The nearest-greater-offset spans range from 2 to 14,588 bytes
(median 106); these bounds describe file layout and do not prove semantic
record boundaries. Aliased slots share a span.
(tools/mtmap.py → extract/analysis/mt_tables/*.csv)

## Motion stream rows (partially recovered)

The runtime motion selector at `0x8C09D5AE` treats the 8,880 words as 2,960
three-offset rows. Actor `+0x3C` supplies a one-based motion ID; the selected
row starts at `(id - 1) * 12`. The three file offsets point to the packed
channel descriptor/count area, key-time bytes, and float tuples. The first
area begins with a descriptor word, followed by sixteen bytes expanded as
four 2-bit channel opcodes per byte. The evaluator uses 63 of the 64 decoded
opcodes.

For the count stream, the selector stores `offset0 + 17` in the runtime header;
the evaluator pre-increments that pointer before its first count read, so the
source count bytes begin at `offset0 + 18`. The runtime header's other two
stream pointers are `offset1` and `offset2`. `src/media/mt.c` resolves this
layout for native code and bounds counts, times, and tuples against their
source spans. The first descriptor word is retained as metadata; it is not
the loop period. The cycle remains runtime state at actor `+0x1A00`.

This recovers stream slicing, not every record's semantic role. It does not
identify which channels drive which bones or POL slots, and it does not
reconstruct the guest loader's resident scatter/rewrite process. Earlier notes
calling leading bytes bone modes or slot IDs a skeleton map remain unproven.

## Validation anchors for future decoding
- `MT*x*x.BIN` mirror-pair comparisons may help identify shared records, but
  shared offsets alone do not establish a skeleton or part mapping. The 8,880
  table entries are file slots; their relationship to runtime channels and
  POL model parts is still unknown.

## Play-back trace windows (M18, oracle-verified)

The evaluator (`fight_f_8c09d6e0`/`fight_f_8c09d69a`) reads these regions of
the **active chain** per frame (slot ids: fight capture MTJACLAU, trace
extract/analysis/mt_field_reads.csv; oracle: `vf3test`):

| slot | window(s) at record base + off | class |
|---|---|---|
| 5093 | `0x736..0x73D` (8 byte reads), `0x75B..0x77B` (byte reads), `0x7A4..0x7B0` (four adjacent u32 reads) | evaluator read windows; field meaning unknown |
| 5096 | `0xE0/0x14C/0x230/0x2A4/0x35C/0x3B0` (u32 reads), `0x194/0x1C8/0x1F0` (float-like windows), other byte windows | additional record reads during the observed evaluation; linkage semantics unknown |
| 1304/1307 | `0x41C..`, `0x4A8..` (+1307: `0x0D4`,`0x40C`,`0x498`,`0x4E4`) | additional records read in the captured paths; roles unknown |
| 1313 | `0x2C` (u32 read) | read observed; pointer/link meaning unconfirmed |
| 572 | `0x3E0..0x3E9` bytes, `0x4E4..0x4F8` u32 reads | additional record in the captured path; fighter association unconfirmed |

These are observed read addresses and values, not a recovered record schema.
In particular, the byte reads do not establish part IDs or mode tags, the
four-word group is not proven to be a live output tuple, and reads from 5096,
1304, 1307, 1313, and 572 do not yet establish a chain/link format or fighter
ownership. See `docs/re/mt_fields.md` for the file-byte comparisons and the
specific fields that remain open.

## Native C reader

`src/media/mt.c` reads the extracted file's 8,880-slot table and bounds each
record by the next greater distinct payload offset (aliases share a span).
`tools/mt_record_inspect.py` prints selected slots or byte windows for offline
inspection; it does not alter assets or infer field meanings by itself.
`tools/mt_motion_find.py <motion-id>...` scans extracted `MT*.BIN` packs for
the three-slot row selected by a one-based runtime motion ID, and flags partial
rows. It is useful for locating an ID across pairing packs; it does not assign
fighter/action semantics.
`vf3mtmotiondump <vfa> <MT*.BIN> <motion-id> <cycle> <start-frame>
<frame-count> [frame-step]` prints the native evaluator's 63 channel values
at selected frame phases. It uses only the VFA asset and the source-level C
evaluator; the values still need a recovered mapping to bones and model parts.
For corpus state inspection, `tools/oracle/evidence_inspect.py profile`
summarizes values at one or more GPR-relative RAM offsets across replay cases;
`case --address` reads selected addresses from one case. `tools/ram_read.py`
provides the corresponding address lookup for a raw binary mapped at a supplied
guest base address.
`tests/mt_asset_replay.c` runs that reader over the VFA archive, not the disc or
guest RAM: all 91 MT assets and 209,925 slot references pass, with record spans
from 2 to 14,588 bytes. The stream decoder is separately gated on representative
motion rows; the guest loader's resident scatter/rewrite is not reproduced.
