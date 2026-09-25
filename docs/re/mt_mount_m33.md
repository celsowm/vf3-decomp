# M33 — GDFS/loader layer + MT mount fixup characterization (2026-09-24)

## GDFS name layer
`src/sys/gdfs.c` (M21) covers the name→tag decode; name-pointer table
boundaries measured (M28b): entries for the character/Motion block span
0x8C1069BC..0x8C106BCC (132 string ptrs; MTJACLAU = entry 39). No static
code reference to the table base exists in the image (checked: zero pool
dwords, zero mova targets land in 0x8C0D6000..0x8C0D8000 or
0x8C106000..0x8C107000) → the loader reaches it via a runtime-populated
pointer (init-time relocation or manager object) — resolve via trace
(M36 harness), not statics.

## MT mount fixup (mt_vm.md open thread) — RESOLVED (falsified +0x27B0)
Residency check of `extract/gamedata/MTJACLAU.BIN` (1.49 MB) against the
fight-live RAM window `extract/analysis/shots/mem_mtdump_vf3_7_659011021.bin`:
- File header maps at dump offset 0x39C3 (dump base = MEMF offset +
  0x39C3), but only at the header.
- Beyond the header the content is *per-record scattered*: unique-content
  64-byte probes map at wildly varying deltas (top clusters at +0x29A6C /
  +0x24194 / +0x28C60 / +0x3A34 / +0x2C514 — i.e. the loader unpacks the
  pack into per-motion records and re-sites each one; ~1,681 probes absent
  as verbatim 64-B windows (table/encoding rewrites).
- ⇒ the "+0x27B0 uniform shift" from the old notes was a single-record
  coincidence. The mounted form is a record-indexed structure, not a full
  file image.

## Follow-ups
- The pack loader function = the fn that reads slot table (mtmap.py's
  8,880-slot table offsets +0x27B0-headed region) then relocates each
  record: find via trace watch on the dst window (M36).

## M33 check evidence
`python - <<` probes in this file's history (commands in git log M33);
falsification math shown above.
