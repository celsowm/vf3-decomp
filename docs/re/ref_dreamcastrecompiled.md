# Ref: Duw0ng/DreamcastRecompiled (cloned refs/DreamcastRecompiled)

SH-4 static recompiler (SH-4 → DCIR IR → native C++), MIT, boot into
commercial titles (ChuChu Rocket, Crazy Taxi 2, Daytona 2001, Record of
Lodoss War). No VF3-specific data, and no symbol-named functions ship in
the repo (`generated/` is empty in VCS) — so its value to us is **tooling
algorithms**, not VF3 knowledge.

What we mined from `src/common/function_analysis.cpp` (107 kB CFG core):

1. **BRAF switch-table resolution** (THE pattern family of our ring/fight
   dispatchers). Three distinct discoverers:
   - byte tables: `MOVA` + `MOV.B @(R0,Rn),Rn [+EXTU.B]` + `BRAF Rn`;
     table byte = signed (or unsigned with the extu) byte offset from BRAF+4.
   - word tables: base (`MOVA` or `MOV.L lit`) + optional `ADD Rn,Rn` scale +
     `MOV.W @(R0,Rn),Rn` + `BRAF Rn`; u16 signed offsets. Bound from
     `CMP/HS`/`CMP/HI reg,#imm` scanned up to 512 B backwards, through
     register-copy chains (`index_def_reg` re-chases MOV rX,rY copies).
     Distinguish: CMP/HS means valid `0..bound-1`; CMP/HI means `0..bound`.
   - absolute 32-bit tables: `MOV.L lit,Rt` + `MOV.L @(R0,Rt),Rn` +
     `JSR/JMP @Rn` → dense pointer table (walk until first non-code value).
2. **Backward value resolution across a block**
   (`resolve_register_*_before`): slightly-bounded dataflow to prove jump
   targets for register-carried branches — the generalization of what our
   hand-trace did for `task_run_C`'s 8×`jsr @r14`.
3. **Thunk recognizers** (`has_compact_return_thunk`, `has_..._tail_thunk`,
   `has_indexed_literal_tail_dispatch_thunk`) — teachable pattern class for
   our 2268 seed-fragmented tiny fns; several coincide with the
   "anonymous tail trampolines" polluting our Ghidra fn list.
4. Function-map CSV schema (docs/*.csv: e.g. CT2_SH4_MAP_0.0.175.csv with
   3,444 fns incl. `caller_targets`) — a proven shape for our own
   funcs CSV growth.

## Ported into this repo
- `tools/braf_tables.py` — capstone-based re-implementation of the three
  table discoverers + fallback sentinel-walk (`*?` kind column) when no
  `cmp/h[si]` bound is visible. Run: `tools/.venv/Scripts/python
  tools/braf_tables.py` → `extract/analysis/braf_tables.csv`.
  First full pass resolved 8 word-table switch sites in 1ST_READ
  (e.g. 0x8C078EE4 → 6 targets at stride 32 B starting 0x8C078F12).
  Known gap: table-base via `mova` that lands mid-code (SD-style
  `mov.l @(r0,r6),r0 ; braf r1` "value table" wrappers, e.g. 0x8C068FA4)
  is NOT matched — those need the register-value propagation from §2.

## Not useful to us there
- CDI/boot preparation (we already descramble byte-exact).
- Their PVR/AICA emulation (we have flycast; different axis).
- DCIR/C++ codegen (we are pursuing a readable-C mirror, not a runner).
