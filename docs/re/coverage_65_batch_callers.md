# RAM/clipping batch: original caller contracts in development

These findings grant no C coverage. Original terminating caller captures,
independent whole-owner development/holdout, strict native replay and the
milestone gates remain required. The production C snapshot is unchanged by
this caller-tool work.

## Component update dispatch

Geometry `0x8c087e04` and timed effect `0x8c08acc0` are update callbacks in
the immutable component table, rather than descriptor-offset-12 callbacks
installed by the fight descriptor registrar.

The original table base is `0x0c0f71d0`, loaded through pool `0x8c08b50c`
at `0x8c08b46e`. Records have stride 28. Geometry is record 11 at
`0x0c0f7304`, with its update callback at `0x0c0f7310`; the timed effect is
record 2 at `0x0c0f7208`, with its update callback at `0x0c0f7214`.
The update selector is **12**, not 16: record offsets 0/4/8/12/16 contain
distinct callback phases, followed by size and flags at offsets 20/24.

The caller window starts at the actual table-base load `0x8c08b46e`.
It retains the loop predicate, decrements the signed component index,
multiplies it by 28 through MACL, adds the loaded table base, applies the
original record flag filter and reads the selected callback. The original
`MOV.L @(R0,R14),R11` is at `0x8c08b4ac`; `JSR @R11` is at
`0x8c08b4ae`, with `MOV R13,R4` in its delay slot. Return is
`0x8c08b4b2`.

`tools/callable_component_update.py` checks the exact executed indexing and
call sequence, original record and pool bytes, both save prefixes, ordered
restorations, PR, saved frame slots and caller state after the loader. It
accounts for the loader's legitimate changes to R10/R11/R14 and FR15.
Seven mutation tests reject missing instructions, altered signatures,
wrong indices/phases, modified tables, bad float widths, corrupted saves
and wrong returns. The prepared original-capture recipe uses four typed
variants per row and relocated writable objects. Original v1 finished:
all eight timed-effect callers pass, and five of eight geometry callers
pass. Three active geometry cases in state 28 were interrupted. All thirteen
completed valid cases satisfy the structural contract. The mixed v1 campaign
is retained as unqualified; separate v2 recipes vary the genuine foreground
trigger ordinal while retaining active and guarded paths.
Timed-effect v2 passes **8/8** original caller contracts in states 28/29.
Geometry v2 remains **5/8**: the same three active state-28 invocations
were interrupted at the changed trigger times. This hypothesis did not
resolve the original caller qualification issue; no interrupted case is
accepted and no C correction follows from it.

## Triangle clipping callers

The seven new clipping variants have fixed literal-JSR callers:

| Callable | Literal load | Target pool | Restore start |
| --- | --- | --- | --- |
| `0x8c05152c` | `0x8c05725e` | `0x8c057288` | `0x8c051700` |
| `0x8c051918` | `0x8c0566a2` | `0x8c0566cc` | `0x8c051b0c` |
| `0x8c051c2c` | `0x8c057602` | `0x8c05762c` | `0x8c051e00` |
| `0x8c05228c` | `0x8c0579e6` | `0x8c057a10` | `0x8c052460` |
| `0x8c0525c0` | `0x8c056e62` | `0x8c056e8c` | `0x8c0527b4` |
| `0x8c05291c` | `0x8c058120` | `0x8c058148` | `0x8c052af0` |
| `0x8c052c34` | `0x8c057de0` | `0x8c057e08` | `0x8c052e08` |

Each load targets R2, followed by `JSR @R2` and delay-slot `MOV R0,R4`.
R12 is the inherited output cursor; no PVR address is substituted for it.
The wrappers save R10/R9 twice, save every FR, and preserve all integer
registers except the advancing R12. The original restore includes both
extra R9/R10 pops. The inner duplicate saved slots are deliberately reused
for the second/third strip cursors; their final values must equal the
original R8 plus one/two format strides. The outer copies retain the
caller's original R9/R10. Nonempty results contain three or four 32-byte packets,
and the last packet receives the original banked R4 end-of-strip command.

`tools/callable_clip_triangle.py` checks these fixed literal callers,
complete prefixes/restore sequences, original pools, all 33 saved frame
slots, architectural save invariants, cursor advancement and the final
command. Eight mutation tests cover all seven shapes, missing/forged
instructions, saved registers/frames, pools, packet boundaries and float
modes. The prepared recipe varies selectors and both colored shader paths
using relocated RAM streams and attributes. All **56/56** captures across
states 28/29 pass execution accounting and the structural contract. Each
callable has four original inputs per state. The complete original one-shot
manifest and state provenance pass `require_original_scenarios`; the
contract report is retained under `extract/analysis/`.

The combined oracle tool suite passes 272 tests at this development point.
Neither contract has yet been registered as a promotion attribution kind;
registration requires passing original caller captures and whole-body
integration tests.

## Completed additional caller cohorts

Geometry v4 uses original states 26/29 and retains all active/guarded inputs
without a raw SR override. All **8/8** original windows pass the component
contract. Replay interpolation v4 and the replay initializer v4 also pass
**8/8** original windows in states 26/29. List interpolation v1 passes
**8/8** in states 28/29. Each complete one-shot manifest passes state and
capsule provenance checks through `require_original_scenarios`.

The initializer contract distinguishes its direct return from the original
history-record tail, including the legitimate descriptor callback change
and reuse of the saved stack frame. Interpolation contracts check the
original stack/actor argument setup, BSR or literal JSR, saved slots and
ordered restorations. Seven mutation tests cover each new contract group.

The raw-SR geometry v3 experiment remained unqualified. The fixed observer
sets `ctx->sr` for a seeded SR input without refreshing its decoded interrupt
mask. Its failing device tape records exception/interrupt event `0x320`
and normal interrupt status `0x30` at `0x005f6900`. The observer and its
source freeze were preserved; no interrupted case was accepted.

Clock/history scene caller validation is prepared and has six passing
mutation tests, but its original caller captures remain pending. These are
the two remaining caller entries for this batch. The current oracle suite
passes **292** tests. The combined C holdout is running after the formal
complete development freeze; no C coverage has been promoted.
