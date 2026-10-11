# Eighteen-entry scene insertion: qualified C

`src/fight/scene_insert.c` implements original uncached callable
`0x0c09fefe`, frozen owner `0x8c09ff12`. Its complete owner adds **374
verified bytes**. The twenty-byte prefix saves R14 through R8, initializes
R12, and loads the scene-global address. Prefix bytes earn no extra credit.

The routine clears scene status bytes and finds an insertion point in
eighteen parallel arrays rooted at `0x0c11e418`: identifiers at `+0`,
frame keys at `+72`, secondary keys at `+144`, and byte identifiers at
`+216`. Comparisons use signed 32-bit values. Equal frame keys use the
secondary key to decide whether to continue scanning. The retained suffix
moves backwards before the new key and selected actor identifier are stored.
Scanning past all eighteen rows sets the original full-table status.

Development on original states 21/26 and independent holdout on states
28/29 each pass **127/127 valid cases**, with no native skips. Each
campaign executes every frozen owner instruction. Inputs vary insertion
positions, equal keys, secondary-key ordering, actor selection and
identifiers. Holdout changes key spacing and values, relocates owned
objects, and uses the alternate floating bank. One interruption per
campaign remains in the raw evidence and is explicitly excluded.

The immutable `vf3matrixfamily_scene_insert_dev_v1.exe` and all **378
compiled dependencies** were frozen before holdout capture. Full native
comparisons include architecture, RAM and actual returns. Integer callee
saves, stack, floating registers, XF and FPSCR remain preserved.

The real caller loads target `0x0c09fefe` at `0x8c09a6b2` (`d216`) from
literal slot `0x0c09a70c`, then executes JSR `0x8c09a6b4` (`420b`) with
the original NOP delay. Eight original-only windows on states 28/29
verify this transfer, original literal pools, saved stack slots and
ordered restoration through RTS `0x8c0a00b2`, returning to `0x8c09a6b8`.
These windows qualify the callable boundary; the full caller is a separate
coverage requirement. Background AICA events confer no device credit.

All matrix-binding opcode ledgers were checked for the changed entry,
real JSR and frozen caller owner. No ledgers are missing; one binding is
affected and passes. All **39 native suites** and **172 tool tests** pass.
All 190 default executables are archived. `scene_insert_v1_manifest.json`
seals the proof and pins the previous contact-frame seal and full 60%
checkpoint.

Verified readable C is **262,802 / 434,656 (60.46%)**. **19,725 bytes**
remain to reach 65%. The next required full inventory gate is at 62.5%.
