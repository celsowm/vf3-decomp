# The translator's missing instruction families, and the claim-set rule

Date: 2026-10-21. Follows `docs/re/coverage_80_generated_adapters.md` (the
recipe for the generated adapter batches).

## 1. What was measured

The unported pool had 302 entries / 39,056 B of new bytes; 42 of them
(5,086 B) already owned a captured corpus, so only the translator and the
strict replay stood between them and ledger credit.

The first question was therefore not "which entries can be captured" but
"which bodies can the translator express at all".  For every unported entry,
every PC of its Ghidra body range was fed through the generator's own
`emit()`, following the same classification the CFG walker uses (a branch
word is handled by the walker, its delay slot is passed to `emit()`):

```
unported entries whose body the translator cannot express: 12 (624 B)
  8c010dde  236 B  ops=4007 4027 4037 4047      LDC.L @Rn+,SR / VBR
  8c03746a  152 B  ops=cc2c cc30 ...            TST.B #imm,@(R0,GBR)
  8c039cb4   82 B  ops=c330                    TRAPA #imm
  8c1011a8   38 B  ops=3d9f                    ADDV Rm,Rn
  8c0345c6   34 B  ops=466f                    MAC.W @Rm+,@Rn+
  8c05e12e   24 B  ops=cd40 cd48               AND.B #imm,@(R0,GBR)
  8c025fe8   24 B  ops=025f                    MAC.L @Rm+,@Rn+
  8c0c5bbe    8 B  ops=cccc                    TST.B #imm,@(R0,GBR)
  8c031fe0    8 B  ops=031f                    MAC.L @Rm+,@Rn+
  8c02dfd4    8 B  ops=02df                    MAC.L @Rm+,@Rn+
  8c023aec    6 B  ops=023a                    STC SGR,Rn
  8c0d2b0a    4 B  ops=026f                    MAC.L @Rm+,@Rn+
```

## 2. The semantics come from the emulator, not from a manual

Every opcode was resolved against the emulator's own decoder table
(`tools/emu/flycast/core/hw/sh4/interpr/sh4_opcodes.h`, one `sh4op()` pattern
per instruction) and, where the pattern was ambiguous, against its
implementation in `sh4_opcodes.cpp`.  That table is the authority because the
corpus was recorded by that emulator: a hand-written model of `TST.B` that
disagreed with the emulator would fail the strict replay, not the compiler.

The seven families that were missing:

| opcode | instruction | semantics taken from the emulator |
|---|---|---|
| `0xcc**` | `TST.B #imm,@(R0,GBR)` | `T = ((u8)mem8[GBR+R0] & imm) == 0` |
| `0xcd**` | `AND.B #imm,@(R0,GBR)` | `mem8[GBR+R0] &= imm` (read-modify-write) |
| `0xce**` / `0xcf**` | `XOR.B` / `OR.B` | same shape as `AND.B` |
| `0x?xxx7` (format 0) | `MAC.L @Rm+,@Rn+` | `mac.full += (s64)rm * (s64)rn`; `Rm`/`Rn` advance by 4 |
| `0x4xxxF` (format 4) | `MAC.W @Rm+,@Rn+` | same with 16-bit operands, advance by 2 |
| `0x3?xxF` (format 3) | `ADDV Rm,Rn` | `Rn += Rm`, `T` = signed 32-bit overflow |
| `0x4x07` (format 4) | `LDC.L @Rn+,SR` | `SR = mem32[Rn] & 0x700083F2` (the emulator's `sr_t::MASK`), `Rn += 4` |

Two details are easy to get wrong and were taken from the emulator rather
than from the instruction manual:

* `MAC.L` adjusts the **RN** address when `n == m` (`Rn + 4`), `MAC.W`
  adjusts the **RM** address (`Rm + 2`).  The two forms are not symmetric.
* `LDC.L @Rn+,SR` loads the *masked* SR: the emulator's `sr_t::setFull`
  keeps only `0x700083F2` (S, IMASK, Q, M, BL/RB/MD and T) and drops the
  reserved bits, so the C state has to store the same masked value.

`TRAPA #imm` and `STC SGR,Rn` stayed unsupported on purpose: a trap raises an
exception the port cannot reproduce, and `SGR` is a control register the
oracle does not capture.  Both are in entries without a corpus, so they cost
nothing today (2 entries / 88 B).

After the extension the same measurement reads:

```
unported entries whose body the translator cannot express: 2 (88 B)
  8c039cb4  82 B  ops=c330   TRAPA
  8c023aec   6 B  ops=023a   STC SGR
```

## 3. The claim set: why a new module may not own everything it implements

The first attempt to wire the new module (`src/fight/vf3_c95_adapter.c`,
45 roots) placed it **first** in the router chain so that it could take over
the three entries whose bodies an older module still held in its stale
pre-extension form.  That was wrong, and the random-binding regression plus
the corpus sweep showed why:

* the generator forces a root's body **and its intraprocedural control flow**
  into the new module, so the module also implements the bodies of *other*
  ledger entries that those roots call;
* the router dispatches by entry PC, so a module placed first takes over
  every entry it implements - including those it only implements partially;
* `0x8c048480` (a promoted entry) moved from `device_adapters.c` to the new
  module and stopped replaying: the entry PC was served by the new module
  while the rest of its body stayed in the old one.

The fix is in the generator, not in the chain order.  `ownership()` now emits
two arrays:

* `owned_pcs[]` - every PC the module implements (used by the coverage audit);
* `claim_pcs[]` - the PCs the router may route here: **the PCs no other
  module owns, plus this module's own roots**.

With the usual "new module last" order the two sets agree, because the
earlier module wins every contested PC anyway.  With the module placed first
the claim set keeps the ownership of the older modules intact, so the new
module serves exactly its own roots and the code nobody else implements.

## 4. What the batch promoted

`vf3_c95_adapter.c` (45 roots, 3,059 statements) is wired into the router
chain ahead of the `c9x` adapters.  Three entries replay strict-clean across
every corpus they own and are promoted:

| entry | body | why it was blocked before |
|---|---|---|
| `0x8c03746a` | 152 B | the owner's body held 15 `TST.B #imm,@(R0,GBR)` instructions the old translator could not express |
| `0x8c05e12e` | 24 B | two `AND.B #imm,@(R0,GBR)` instructions |
| `0x8c0734fe` | 2 B | one `MAC.L @Rm+,@Rn+` |

The three shadowed golden bindings (`0x8c0483f4`, `0x8c05e146`,
`0x8c073514`) were re-verified strict-clean after the rewire, and the
400-binding random regression stays green.

## 5. The walls that remain (and why they are not porting bugs)

The other 39 corpus-bearing entries fail in five named classes, all of them
already documented in `docs/re/reios_exec_server.md` and
`docs/re/advance_progress.md`:

1. **REIOS GD-ROM vector `0x8C001006`** (10 entries, 742 B).  The stub in
   `src/fight/vf3_aica_stub_adapter.c` answers `r7` in 2..13; `REQ_CMD`
   (`r7=0`) and `GET_CMD_STAT` (`r7=1`) need the firmware's internal command
   state (`gd_hle_state`: the request id, the parameters and the transfer byte
   count in `result[2]`).  No case input determines that state, so the answer
   is not derivable from the corpus - it needs the REIOS model that
   `docs/re/reios_exec_server.md` scopes out.
2. **Uncaptured RAM writes** (8 entries, ~794 B).  The port writes outside
   the captured windows; the reference wrote there too, the recorder just did
   not keep that page, so the harness's out-of-window counter rejects a
   behaviourally correct port.
3. **The corner-block descriptor flush loop** at `0x0c0510b6` (4 entries,
   300 B).  Its iteration count comes from driver state at `0x0c16cdxx` that
   these corpora do not carry.
4. **`STC VBR`** in the helper `0x0c060eba` (1 entry, 80 B).  The game's VBR
   is not in the captured state, and the value is used as an address
   (`mov.l r4,@(r0,r2)`).
5. **Register and device mismatches** (4 entries, ~764 B): a NaN sign bit
   (`0x8c03bbd2`), a device write value (`0x8c09aa14`), a missing RAM window
   (`0x8c04340c`) and an entry whose corpus has no RAM rows at all
   (`0x8c042672`).

Each of them needs evidence the corpora do not carry; none of them is a
translator or dispatch defect.

## 6. The oracle's RAM page budget, and what the capture sweep yields

The out-of-window failures of class 2 are not "the port writes where the
reference did not".  The traces show the opposite: the port **reads** an
address the recorder never kept, for example `0x0c31f8cc` (main RAM above the
image, which the 512 KiB page budget of the recorder dropped), and the value it
reads is 0 where the reference read the game's table.

The recorder keeps a page of RAM per touched page and refuses a specimen once
the cache is full:

```c
constexpr unsigned PAGE = 4096, LIMIT = 128;      /* tools/emu/flycast/core/vf3oracle.cpp */
if (c.pages.size()==LIMIT) { c.flags|=4; continue; }
```

128 pages is 512 KiB, and the arena-seeded fixture alone spreads its 16
registers over 128 pages, so any target that also touches its own data tips
over the limit.  The limit is a memory budget, not a semantic constraint, so
`docs/re/patches/oracle_device_reads.patch` now raises it to 1024 pages (4 MiB)
- enough for the fixture, the target's own data and the pre-probe restore
image.  The patch is regenerated with `python extract/analysis/make_oracle_patch.py`
and the emulator rebuilds incrementally:

```
cd tools/emu/flycast-build
C:/msys64/ucrt64/bin/mingw32-make.exe flycast -j8
```

With the raised budget the 260 corpus-less unported entries were swept
(`extract/analysis/u95_watch.txt`, 260 entries / 33,970 B, biggest first) in
four parallel shards, twice: once with the arena-seeded fixture and once with
the game's live registers (which the device-reads patch made viable again - the
old reason to avoid them, a live register holding a null-ish pointer that
dereferenced a device address, no longer aborts the specimen).

The yield is low, and the reason is uniform: the probe never returns.

| fixture | entries attempted | entries with cases |
|---|---|---|
| arena seeds (8 variants) | 260 | 5 |
| live registers | 260 | see `extract/analysis/u95_live*/progress.json` |

`flags=4` on a synthetic probe means the excursion hit the 100,000-instruction
budget (`c.ops.size()>=probeOps`), i.e. the target spun.  The arena fixture
makes that likely: every register points at a zeroed arena page, so a loop
whose trip count comes from game data never terminates.  The live registers
give the target real data and do better, but the trip count still comes from
data the probe's state does not contain.

## 7. The REIOS cluster is a state problem, not a dispatch problem

The reference trace of `0x8c035518` (`f_8c035518.ops.json`) ends at
`8c001006 : 085b` - the BIOS vector - so the port's dispatch to
`0x0c001006` is right and the stub is what rejects it.  The stub is entered
with `r6=0`, `r7=2` (EXEC_SERVER), `pr=0x0c0434d0` and a budget of 99,960, and
it does *not* take its own fail path.

The mismatch is in the **readable** port that pre-empts the generated chain,
`src/fight/gd_syscall_stub.c`:

```c
int vf3_gd_exec_server_wrapper_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(6) = 0; R(7) = 2;
    R(0) = m32(ram, BIOS_VECTOR_PTR);
    if (!vf3_guest_call(s, ram, R(0) & 0x0FFFFFFFu, pr0)) return 0;
    ...
    R(0) = 1;                 /* the wrapper's rts delay slot */
```

It models **one** BIOS call and forces `r0 = 1`.  The corpus expects the REIOS
command state at the entry's exit:

```
in : r0=0000004c r6=00000000 r7=00000000 pr=0c034bbe
out: r0=00000000 r6=00000004 r7=00000001 pr=0c034bbe
```

`r7=1` is `GET_CMD_STAT`, and its answer is the firmware's request id plus the
four `result[]` words (word 2 is the byte count of the last transfer).  Those
come from the REIOS `gd_hle_state`, which is not in guest RAM and is not
determined by any case input.  The machinery for it exists
(`tools/gd_state_dump.py`, the `VF3_GDLOG` observer log, `vf3_gdrom` in
`src/sys/`), but the *per-case* seeding is missing: `VF3_GD_STATE` names one
file of 16 state words for a whole process, and a corpus has many cases with
different drive states.

So the cluster (10 entries, 742 B) needs the corpus to carry the GD state per
case.  That is the concrete remainder of the design project scoped in
`docs/re/reios_exec_server.md`.

