# Who serves a gap entry, and can the router reach every PC of its body?

Date: 2026-10-25. Follows `docs/re/coverage_100_gap_translation.md` (the 100%
bar).

The 100% bar was reached by translating the 237 bodies the oracle never
reached (`docs/re/coverage_100_gap_translation.md`).  That doc proves the
translation is *faithful* - every emitted block matches the image - and
`tools/body_complete.py` proves the *coverage* - every PC of every body
carries a translated label.  Neither says anything about **dispatch**: the
router has to be able to send a call to those PCs.

## 1. The question

The router (`vf3_matrix_family_core` in `src/fight/matrix_family.c`) picks a
module by walking a chain of `_contains` tests.  Each module's `_contains`
reads its `claim_pcs[]` array when it has one and its `owned_pcs[]` array when
it does not.  So three sets matter, and they are not the same set:

| set | what it is |
|---|---|
| owned | the PCs a module's translation implements |
| claim | the PCs a module may be *routed to* |
| served | the union of the claims of every module the chain reaches |

A body is only reachable if every one of its PCs is in `served`.  The repo's
own note records the failure this guards against (`AGENTS.md`): *"two modules
can own the same PC while neither claims it - then nobody serves it and the
router has nowhere to send the call."*

`tools/gap_serve_audit.py` answers the question for the 237 gap entries:

```
$ python tools/gap_serve_audit.py
  fallback module: vf3_matrix_adapter (matrix_adapters.c) serves 27964 PCs
gap entries audited: 237
  served by a gap module : 182
  served by an older one : 55
  served by nobody       : 0
  body PCs no module claims (the router cannot serve them): 0
  body PCs the serving module does not own (split bodies): 1
    0x0c0c74bc served by c94_adapter (vf3_c94_adapter.c) body=234 B missing 6 PCs: 0x0c0c66e0, ...
```

**No gap body has an unreachable PC.**  182 of the 237 are served by the gap
module that translated them; the other 55 are served by an *older* module that
already carried the same body (an oracle-replayed one, so the stronger
evidence), and one body (`0x8c0c74bc`) is split: `vf3_c94_adapter.c` owns most
of it and the fallback covers the rest.

## 2. The false alarm, and what it taught

The first run of the audit reported **93 unreachable PCs**, all of them body
continuations like `0x0c038cb2`.  The cause was in the audit, not in the
port: it looked for `_contains` symbols and so never saw the module the chain
*ends* with.

`vf3_matrix_adapter` (in `src/fight/matrix_adapters.c`) has **no `_contains`
symbol and no claim array**.  It is the chain's last line:

```c
        if(vf3_gap_b06_adapter_contains(entry)) return vf3_gap_b06_adapter(entry,s,ram);
        return vf3_matrix_adapter(entry,s,ram);     /* the fallback */
```

so it serves **every PC its translation carries** - 27,964 of them, including
all 93 that the audit had called unreachable.  A scan that only looks for
`_contains` sees a hole that is not there.

Two modules in `src/fight` define a `_contains` symbol the router never
calls: `fight26_mod.c` (`vf3_fight_adapterN_contains`, 3,565 owned PCs) and
`seventh_final_adapters.c` (`vf3_seventh_final_adapter_contains`, 117 PCs).
They are dead code: nothing dispatches to them.  Their PCs are nevertheless
served - by the fallback - so they are not a hole either.

## 3. The translator's "already implemented" set

`tools/oracle/translate_adapters.py` builds the set of PCs it must *not*
re-translate, and it uses that set to decide which PCs the new module may
claim:

```python
claim = sorted((set(ops) - existing) | (roots & set(ops)))
```

`existing` was every `P_` label (or claim) of every file matching
`src/fight/*.c` - including the two dead modules.  That is *almost* right: a
PC an older module owns is a PC the older module serves, so the new module
must not claim it.  It is wrong for a module the router never calls, whose
PCs nobody serves.

The translator now asks the router instead of guessing
(`router_calls()` / `file_serves()`): a file whose `_contains` symbol the
chain never calls contributes nothing to `existing`.

**The change is output-neutral today** - regenerating all six gap modules
with it reproduces the committed files byte for byte, because the fallback
already covers every PC the two dead modules owned.  It is kept because it
makes the invariant explicit and it removes the trap for the next module: a
PC that only a dead module owns would otherwise be claimed by nobody.

```
$ python tools/gap_gen.py --batch 40 --size 40     # -> git diff is empty
```

## 4. `tools/adapter_dump.py` was reading the wrong mnemonic

`adapter_dump.py` is the bridge between the generated translation and a
hand-written port, so a wrong mnemonic there produces a wrong port.  It
carried its own table, keyed on the top nibble of the opcode:

```python
names = {0: "mov", 1: "mov.w", 2: "mov.b", ...}
```

The group-2 sub-opcode sits in **bits 3-0**, not in the top nibble, so
`0x2e42` was printed as `mov.b` when it is `mov.l r4,@r14`.  The tool now
calls `tools/sh4.py`, the repo's decoder, and prints the real mnemonic and
operands:

```
$ python tools/adapter_dump.py 0x0c04341e
  0x0c04341e  4f22  sts.l pr,@-r15    r[15]-=4; write(ram,r[15],r[16],4); goto P_0c043420;
  0x0c043420  7ff0  add #-16,r15      r[15]+=0xfffffff0u; goto P_0c043422;
  0x0c043422  6ef3  mov r15,r14       r[14]=r[15]; goto P_0c043424;
  0x0c043424  2e42  mov.l r4,@r14     write(ram,r[14],r[4],4); goto P_0c043426;
```

The mnemonic table in `tools/sh4.py` is confirmed by the SH-4 prologue:
`0x2fe6` decodes as `mov.l r14,@-r15` under bits 3-0 (and would be `muls`
under any other layout), which is the instruction every SH-4 function starts
with.

## 5. The regression verdict

`tools/verify_all.py` fails in this workspace, and every failure is the
artifact gap (`docs/re/artifact_gap.md`), not a regression from the gap
batch:

| check | why it fails |
|---|---|
| `audit_matrix_batch.py`, `audit_next_batch.py`, `audit_sixth_batch.py` | `extract/analysis/*_dev_cases/capsule_manifest.json` - the capsule payloads the bundle did not carry |
| `body_cover.py` | `tools/emu/flycast-build/data/vf3_28.state` - the patched oracle (`tools/emu`) is absent |
| `verify_union.py` | `extract/analysis/sdk_corpus/sdk8eu.bin` - absent |
| `portcheck.py` (6 bindings) | the six corpora carry their `.cases` metadata but **no RAM blobs** (`e000.bin`, `x000.bin`, `*.exitram*.bin`), so the harness reads 0 cases |
| `portcheck.py` (71 bindings) | the `.cases` file itself is missing |

The 6 `portcheck` failures are all readable ports with their **own** test
binary (`build/vf3fvecnorm070120.exe` and friends, built before the gap
batch), and their entry PCs are claimed by no generated module at all - the
chain cannot reach them.  They are not a regression.

Everything the gap batch *can* be held to passes: `tools/gap_fidelity.py`
(0 opcode mismatches, 0 missing body PCs, 0 bad claims),
`tools/gap_body_check.py` (237/237 complete), `tools/coverage_proof.py`
(217,328/217,328 baseline halfwords) and `tools/gap_serve_audit.py` (0
unreachable PCs).

## 6. The tools

| tool | what it answers |
|---|---|
| `tools/gap_serve_audit.py` | which module serves each gap entry, and whether every PC of its body is servable |
| `tools/gap_fidelity.py` | does every emitted block match the image |
| `tools/gap_body_check.py` | is every body range emitted |
| `tools/coverage_proof.py` | are all 217,328 baseline halfwords covered |
| `tools/adapter_dump.py` | the generated translation as guest disassembly, with the right mnemonics |
