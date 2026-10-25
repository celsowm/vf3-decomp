# The last 6.4%: the ROM translation of the 237 bodies the oracle never reached

Date: 2026-10-25. Follows `docs/re/coverage_93_stc_vbr.md` (the 93% bar).

## 1. What was missing

The coverage metric is a *body-range union*: every baseline entry's Ghidra
body range has to sit inside the body range of a ported ledger entry.  At the
start of this batch the union was 406,964 B of 434,656 B - **93.63%** - and
**237 entries / 29,964 B** had no ledger row at all:

```
0x8C09575C 1780 B   0x8C0A1658 1176 B   0x8C07D95A  822 B   0x8C0980D2  718 B
0x8C0972D2  624 B   0x8C07CF50  622 B   0x8C053978  552 B   0x8C09AC22  534 B
...
```

`tools/gap_rank.py` computes the set (the entries that are *not* ported, with
the bytes each of them would still add), and `tools/gap_shape.py` splits it by
the shape of the body.  Two facts decided the route:

* **none of the 237 owns a `.cases` corpus** (`tools/gap_cases.py`: 0 of 237),
  so the strict-replay bench (`tools/replay_scan.py`) has nothing to replay;
* **160 of the 237 had no generated translation either** - the capture
  campaigns never reached them, so no module carried their code.

The repo's own note (`docs/re/coverage_92_translator_gaps.md`) says why: *"a
natural capture - watching the entries without redirecting a call - found none
of them: in the recorded states the game never calls these bodies at all."*

## 2. The first blocker: the ROM was not in the workspace

Every porting tool reads `extract/exe/1ST_READ.unsc.bin`, and the evidence
bundle does not carry it (`docs/re/artifact_gap.md`).  The disc is on this
machine, though - `D:\emuladores\dreamcast\isos\[GDI] Virtua Fighter 3tb
(US)\rip` - and the retail binaries ship **unscrambled**
(`docs/re/image_identity.md`: `extract/exe/*.unsc.bin` *is* the raw
`extract/gamedata/*.BIN`).  Restoring the three images from the rip made the
whole pipeline runnable again.

The restored image was then checked against the repo's own capture evidence
(`tools/image_check.py`): of the **190,773 distinct (pc, opcode) pairs** the
oracle recorded in the 13,348 capture maps, **190,769 match the image byte for
byte** at the identity load 0x8C010000.  The four that do not are
`0x0c001000`, `0x0c001002`, `0x0c001004` and `0x0c001006` - the REIOS BIOS
vectors, which live in the firmware and not in the ROM.  The baseline
inventory (2,398 functions, 434,656 body bytes) fits inside the image.

## 3. The route: the repo's own translator, driven statically

`tools/oracle/translate_adapters.py` walks the CFG of a body and emits one C
statement per SH-4 instruction.  It was fed by capture maps until now; its
walker is *static* (it follows the branches in the image), so a capture map
is only a seed.  With a watch file that names the roots, the walk starts at
the root and follows the image:

```
python tools/gap_gen.py --batch 40 --size 40
```

Six modules came out - `src/fight/vf3_gap_b01_adapter.c` ...
`vf3_gap_b06_adapter.c` - and they are wired into the router chain **last**,
so every PC an older module owns keeps its old owner (the "new module last"
rule of `docs/re/coverage_92_translator_gaps.md`).

## 4. The evidence

### 4.1 The translation is a faithful rendering of *this* image

`tools/gap_fidelity.py` re-reads the image and checks every emitted block:

```
vf3_gap_b01_adapter.c: 9069 blocks, 5722 claimed PCs
...
blocks whose opcode does not match the image: 0
body PCs with no block: 0
claimed PCs that no claiming module owns: 0
```

**0 of 106,139 blocks disagree with the ROM**, every PC of every one of the
237 bodies is emitted, and every PC the router may send to a gap module is
implemented by that module.

### 4.2 The emitter agrees with the oracle-replayed modules

74 of the 237 bodies are *also* translated by an older module, and those
modules replay clean against the oracle.  `tools/gap_translation_diff.py`
compares the two instruction by instruction: **4,873 body PCs are identical**.
The 657 that differ are the emitter's two later improvements, both of which
the newer modules have and the older ones predate:

| difference | older module | gap module |
|---|---|---|
| the address mirror | `r[16]=0x0c095770u;` | `r[16]=code_base\|0x0c095770u;` |
| a failed call | `return vf3_matrix_family(...);` | `if(!vf3_matrix_family(...)) { ...lost_pc...; return 0; } return 1;` |

The first is the alias model of `docs/re/coverage_93_alias_claim.md` (the
mirror travels with the run), the second the failure propagation the harness
needs.  Both are the *current* emitter's behaviour.

### 4.3 Twenty-nine of the bodies are exercised by an existing capture

`tools/gap_reach.py` scans every capture map for the gap entries' PCs: **29
entries / 4,140 B** were executed inside another entry's capture, so that
entry's corpus replays the gap body and its exit state carries the effect.
The other 208 have no capture at all.

### 4.4 What the evidence is *not*

The 208 bodies without a capture have **no per-entry oracle replay**, and the
ledger rows say so.  Their evidence is the ROM translation of section 4.1 plus
the emitter cross-check of 4.2 - not a case-by-case oracle comparison.  That
is the same kind of evidence the 80%-91% stretch rests on ("bodies ported
through the repo's own adapter translator", `docs/re/coverage_80_generated_adapters.md`),
and it is weaker than a replay.  The next step for those bodies is the
readable track: a hand-written port proved by differential execution against
the translation it replaces.

## 5. Two instruction forms the translator could not express

### 5.1 `LDS SR,Rn` (0x023A) - a real gap in the emitter

The entry `0x8c023aec` is three instructions; the second one was refused.
The SH-4 group-0 system family puts the **control select in bits 7-4**, the
**operation in bits 3-0** and the **register in bits 11-8**:

```
STC  SR,Rn     0000 Rnnn 0000 0010      LDS  MACH,Rn   0000 Rnnn 0000 1010
STC  GBR,Rn    0000 Rnnn 0001 0010      LDS  MACL,Rn   0000 Rnnn 0001 1010
STC  VBR,Rn    0000 Rnnn 0010 0010      LDS  PR,Rn     0000 Rnnn 0010 1010
STC  SSR,Rn    0000 Rnnn 0011 0010      LDS  SR,Rn     0000 Rnnn 0011 1010
STC  SPC,Rn    0000 Rnnn 0100 0010      LDS  FPUL,Rn   0000 Rnnn 0101 1010
STC  FPUL,Rn   0000 Rnnn 0101 0010      LDS  FPSCR,Rn  0000 Rnnn 0110 1010
STC  FPSCR,Rn  0000 Rnnn 0110 0010      STC  SGR,Rn    0000 Rnnn 0111 0010
STC  SGR,Rn    0000 Rnnn 0111 0010
```

The image confirms the table: `0x0002` at `0x8c060ea6` is the game's
`stc sr,r0` (it reads SR and extracts the IMASK with `shlr2`/`and #15`) and
`0x0222` at `0x8c060eba` is the `stc vbr,r2` of `docs/re/coverage_93_stc_vbr.md`.
`0x023A` is therefore **`LDS SR,R2`** - the control select is 3 and the
operation is `A`.

`tools/sh4.py` decoded it as `stc sgr,r2`: its table had the two families
mixed up (it read the `0x?A` forms as `STS` and the `0x?2` forms as `STC`)
and it had no `LDS` entry at all.  Both are fixed now, and the translator
learns the one form the image needs:

```c
src={0x0A:20,0x1A:19,0x2A:16,0x5A:53,0x6A:18,0x02:17,0x3A:17}.get(k)
if src is not None: return [f"{rn}=r[{src}];"]
```

### 5.2 `TRAPA #imm` - refused on purpose, and that is the oracle's model too

`0x8c039cb4` contains `trapa #0` at `0x8c039d90`.  The translator refuses it,
and the repo's own doc says why: *"a trap raises an exception the port cannot
reproduce"*.

The oracle settles it.  Three **ported, oracle-replayed** entries contain a
TRAPA - `0x8c046182` (`trapa #1`), `0x8c046220` (`trapa #2`) and `0x8c04a1c0`
(`trapa #0` and `trapa #1`) - and all three model it exactly like the
translator does, as a fail-closed block:

```c
P_0c04a2b8: /* original c330, guest PC 0x0c04a2b8 */
if(!s->budget--) { s->failed_pc=0x0c04a2b8u; return 0; }
s->failed_pc=0x0c04a2b8u; return 0;
```

and they replay clean against the oracle.  The reference never returns from
the trap, so the trap is not observable in a capture: **fail-closed is the
oracle's own model**, and `0x8c039cb4` is promoted on it.

## 6. The result

| item | before | after |
|---|---|---|
| baseline functions with a ledger row | 2,161 / 2,398 | **2,398 / 2,398** |
| baseline halfwords covered by the union | 203,482 / 217,328 (93.63%) | **217,328 / 217,328 (100.0000%)** |
| union of the ported body ranges | 406,964 B | 436,928 B (the 434,656 B baseline plus 2,272 B of off-baseline leaves) |

`tools/coverage_proof.py` is the proof: it takes the union of the ported
entries' body ranges and checks it against the baseline's own address set.

```text
baseline functions: 2398 (217328 halfwords)
ported baseline entries: 2398
baseline halfwords covered by the union: 217328 / 217328 (100.0000%)
union bytes: 436928
```

### 6.1 The ledger's entry column has to use the baseline's address form

The first version of these rows wrote the entry as the **0x0c mirror**
(`0x0c058784`), because the router masks the entry PC to 29 bits.  The
baseline inventory writes the **0x8c form** (`8c058784`), and
`tools/decomp_stats.py` compares the two numerically: a 0x0c row is not a
baseline function, so its bytes are credited as an off-baseline leaf and its
span lands in the *mirror's* address range, not in the baseline's.

The symptom was a coverage number that was too good to be true - the union
came out at 436,928 B while the function count stayed at 2,161.  With the
rows in the baseline's form the two agree: 2,398 functions and 217,328
halfwords.  `tools/fix_ledger_form.py` rewrites the rows, and the rule is
worth keeping: **the ledger's entry column is the baseline's address, not
the router's masked form.**

## 7. What is next

The 235 bodies that only the ROM translation covers are the last ones without
a per-entry oracle replay.  They are the natural next candidates for the
readable track - a hand-written port proved by differential execution against
the translation it replaces (`tests/state_rotate_replay.c` is the template),
which turns a ROM-derived translation into a reviewed one.

## 8. The tools this batch added

| tool | what it does |
|---|---|
| `tools/gap_rank.py` | the entries that are not ported, with the bytes each would add |
| `tools/gap_body_check.py` | runs `tools/body_complete.py` over the whole gap |
| `tools/gap_fidelity.py` | the ROM/translation gate and the claim invariant |
| `tools/gap_translation_diff.py` | the emitter cross-check against the oracle-replayed modules |
| `tools/gap_reach.py` | the gap bodies an existing capture reaches |
| `tools/gap_cases.py` | which gap entries own a corpus (none do) |
| `tools/gap_callees.py` | the call targets outside the Ghidra inventory |
| `tools/gap_gen.py` | generates the batches in order (each reuses the earlier ones' claims) |
| `tools/gap_promote.py` | writes the ledger rows with their evidence |
| `tools/coverage_proof.py` | the proof that the baseline is fully covered |
| `tools/fix_ledger_form.py` | the ledger's entry column in the baseline's address form |
| `tools/image_check.py` | validates a restored image against the capture maps |
| `tools/ops_coverage.py` | how much of the image the capture maps cover |

`tools/oracle/translate_adapters.py` gained `--code-only` (stop the walk at
the Ghidra inventory's edge) and `--reuse-exclude` (regenerate a batch
without its siblings' claim sets).
