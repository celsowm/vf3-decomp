# M14 — MT motion record access trace (2026-09-22)

Tooling: `VF3_WATCH` mem mode (vf3trace.cpp): `mem <addr_hex> <len>` lines;
each tagged read/write emits `(pc<<16)|0xFA20, (size<<48)|(isWrite<<47),
addr, value`. Installed by wrapping the SH4-execution `ReadMem*`/`WriteMem*`
pointers after `mem_Reset` (winmain runs it after state load too — savestate
resume bounces the pointers via mem_Reset). Interpreter-only: dynarec inlines
its own memory ops.

## Capture
- Run: extract/analysis/m14_wide_vf3_7.bin (95 frames, fight attract state
  vf3_7), watch window 0x8C5F0000..0x8C810000 (covers the whole loaded MTJACLAU
  motion pack, which M8 established as resident at 0x8C5F4100+, 1,493,636 B).
- 4,817 mem hits, 22 unique reader PCs.
- Per-access rows: extract/analysis/mt_field_reads.csv.

## The reading engine
The whole MT-side reader is two functions:
- `fight_f_8c09d69a` (69 B) — short helper, reads a handful of u32 slots from
  linked/secondary records (`pc 0x8C09D6CA` hits).
- `fight_f_8c09d6e0` (263 B) — **the motion-frame evaluator hot loop**.
  Five sub-PCs produce 75% of all hits:
  - `0x8C09D6F6` byte-stream cursor: reads consecutive bytes walking DOWN the
    record from `record+0x736` (+736..+779 within record 5093) — this is the
    per-frame **opcode/command stream**.
  - `0x8C09D70C` byte-stream second cursor (alternative channel).
  - `0x8C09D77A/80/84/96` four u32 reads at `record+0x7A4..0x7B0`: the
    per-frame vector quartet (bone transform or angular params) — always
    read together; 4 states (one quat limb).
  - same four PCs also read `record2+0x194..0x1FC` inside record 5096 —
    proving **record-level linking**: the primary record (5093) pulls extra
    param tuple tables from a second linked record (5096). Stride = one
    tuple per frame-ish.

- A separate init path (`f_8c09d5xx..`): byte reads at file off 151872..151879
  + header walk 18340..18400 range = record **loading/activation** (seen once
  per observation window).

## What records 5093 / 5096 look like (MTJACLAU offsets)
- slot 5093 @ 0xCE154, size 2120 B — the active motion (frame replay source).
- slot 5096 @ 0xCEA1C, size 1448 B — referenced param pool.
- The evaluator's byte cursor tracks slot+736.. (byte-rate advance), and the
  four fp/u32 slots at slot+0x7A4-local sit within 5093 only when 5093 is the
  active record (i.e. big records are bytecode+quad tuples interleaved in one
  blob, not out-of-line).

## Port status
`src/fight/mt_play.c` mirrors this: stream walker explains a record body,
resolves the secondary record reference, emits the 4-dword per-frame tuple
that the dynarec-side code hands to the transform machinery.
