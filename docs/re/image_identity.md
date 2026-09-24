# Image identity — the disc is NOT scrambled (M23 foundation fix, 2026-09-23)

## Discovery

While decoding the MT motion evaluator, trace-verified reader PCs did not match
the descrambled image (`extract/exe/1ST_READ.unsc.bin`) — the image showed
`fsqrt fr0` (`0xF06D`) where the CPU had actually executed `mov.b @r5,r5`
(`0x6550`). Reconstruction of the true executed opcodes **from the trace stream
itself** (interpreter pushes `(pc<<16)|op` per instruction) showed coherent
fight-engine code that could not be found in the descrambled image at all.

`tools/overlay_hunt.py` then located the executed bytes **at identity file
offsets** in the *shipped* `extract/gamedata/1ST_READ.BIN` (and in
`VF3TBE3.BIN` for the E3 build, at its own layout).

## Verification (tools/image_truth.py)

Score unique executed (pc -> opcode) pairs from interpreter traces against
three candidate sources at `pc - 0x8C010000`:

| trace | pairs | raw file | dc_scramble output |
|---|---|---|---|
| m14_wide_vf3_7.bin (fight) | 37,188 | **100.00%** | 0.12% |
| trace_boot3.bin (boot+attract) | 69,807 | **100.00%** | 0.29% |

The residue for the descrambled image is fixed-point/coincidence-level.

## Conclusion

**MK-51001 V1.002 (retail GD-ROM) ships plain (unscrambled) binaries.** The
KallistiOS-style 32-byte-slice permutation in `tools/dc_scramble.py` was
vacuous: `descramble(plain)` *produced* a shuffled image, and
`scramble(descramble(x)) == x` round-trips regardless of input, so the M1
"byte-exact" check could never detect the error. All prior sub-32-byte
verifications (memset 24-byte window, SYSROF 24B probes) stayed inside
permutation slices and therefore passed by construction.

Excavated ground truth supporting identity-load:
- raw file @0x8C010000 = canonical DC boot copy-loop (`mov.l @(24,pc),r0; ...
  jmp @r2`), @0x8C020000 = C-runtime BSS clear (`mova; mov.l @r0+,r2; mov #0;
  mov.l r3,@r2; bf ...`).
- boot trace executed op `0xC720` at 0x8C020000 == raw file bytes.
- the raw E3 binary shows the same entry idiom.

## Consequences / quarantine

- `extract/exe/{1ST_READ,VF3TBE3,RELOAD}.unsc.bin` replaced by the raw
  `extract/gamedata/*.BIN` contents (identity). The old permuted files are
  regenerable via `dc_scramble.py` if ever needed for archaeology.
- Ghidra project re-imported from the corrected images
  (SuperH4:LE:32:default @ 0x8C010000): `Vf3Prologue` created **2,165 real
  functions**; baseline `funcs_1ST_READ.unsc.bin.csv` regenerated (2,398 fns,
  434,656 body bytes). Old programs quarantined at
  `extract/ghidra_proj/VF3.rep.shuffled_image_quarantine` (gitignored).
- **All pre-M23 static-analysis CSVs derived from the shuffled image are
  suspect** (funcs listings, callgraph edges, hotspots, braf tables, katana
  match addresses, MT tables). Trace-derived artifacts (fight_f_* addresses,
  hit counts, mem-watch censuses) remain valid — PCs were runtime addresses.
- The M3 conclusions drawn from the shuffled image must be re-examined on the
  corrected image, in particular the "static jsr ceiling ~3%" and the switch
  table census — both are plausibly artifacts of 32-byte slice shuffling.
- `tools/dc_scramble.py` kept but re-scoped: selfboot MIL-CD titles only.
- New durable tooling from this pass: `tools/sh4.py` (complete SH-4 decoder
  incl. FPU — capstone's SH backend drops the whole 0xF opcode space),
  `tools/sh4full.py`, `tools/m14_seq.py` (interleaved instr+mem dump; `--vdis`
  reconstructs executed code), `tools/overlay_hunt.py`, `tools/image_truth.py`.

## Confirmed decoder calibration

flycast interpreter `ReadNexOp` sets `ctx->pc = addr+2` before executing, so
mem-watch records carry `executing_instruction + 2`. With that correction the
M14 census maps 1:1 onto the true listing (e.g. byte cursor `mov.b @r5,r5` at
0x8C09D6F4 ↔ record pc 0x8C09D6F6).
