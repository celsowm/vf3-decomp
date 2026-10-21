# The tail transfer and the literal pool

*Milestone: 405,664 B of verified C (93.3299%), 2,313 ledger entries.*

Two structural gaps in the port cost four bodies and blocked a fifth.  Both
are now closed.

## 1. The tail transfer (`tests/matrix_family_replay.c`)

`vf3_family_tail_retry` already existed: `vf3_matrix_family_dispatch` retries
the dispatch at the PC a module was lost at, provided the PC is not the entry
itself.  `src/fight/native_tick.c` sets it; the replay harness did not.

A module that reaches a register-indirect jump whose target it was not
generated with stops at that target with the jump already taken - the
reference continues there as the tail transfer it is.  The replay now does the
same, so the dispatcher resumes at the lost PC instead of failing there:

```c
{ const char *tr=getenv("VF3_TAIL_RETRY"); vf3_family_tail_retry=(!tr||tr[0]!='0'); }
```

`VF3_TAIL_RETRY=0` restores the strict single-module behaviour.  The gate
compares the whole register file, XF, FPUL, GBR, the exit PC and the RAM
windows, so a port that takes the wrong path still fails the comparison: the
retry cannot make a wrong port pass.

Unblocked and promoted (300 B):

| entry | bytes | corpus | why it stopped before |
|---|---|---|---|
| `0x8c0377a8` | 84 | `tenpp_prologue_clean_cases` | `0x0c0512dc` - the corner-block helper |
| `0x8c03780c` | 76 | `tenpp_prologue_survey_cases` | `0x0c0512dc` |
| `0x8c0a1294` | 46 | `tenpp_prologue_survey_cases` | `0x0c0512dc` |
| `0x8c047230` | 94 | `tenpp_survey_final_cases` | `0x0c0512dc` |

The corner-block descriptor loop at `0x0c0510b6` was diagnosed earlier as a
"missing trip count"; the real cause was the tail transfer: the loop ends with
`mov.l 0x8c0510ec,r1` / `jmp @r1`, and `0x8c0510ec` holds `0x0c0512dc` - the
epilogue of the caller itself.  The module never had that PC, so the jump was
lost.

## 2. The literal pool (`tools/oracle/translate_adapters.py`)

`jmp @rN` (opcode `0x402b`) is emitted as a switch over the reviewed indirect
targets plus the router's dispatch.  357 sites in the image load the jump
target from the literal pool with the instruction right before the jump:

```
8c0510c2  d10a    mov.l 0x8c0510ec,r1   # lit=0c0512dc
8c0510c4  412b    jmp @r1
```

The literal lives in the original image, so the destination is a property of
the code, not of the run.  The translator now resolves it statically:

```python
def literal_jump(a):
    """Static destination of an indirect jump fed by the literal pool."""
```

The resolved target joins the CFG (so the body is translated) and the emitted
switch gains one more `case`.  The switch keeps its `default` arm, so a
runtime target that differs from the literal still reaches the router - the
rule is strictly additive.

## 3. The c95 module is *not* regenerated

An uncommitted regeneration of `src/fight/vf3_c95_adapter.c` (the previous
session's, with the alias handoff and the `stc vbr` support) broke two bodies
that the committed module replays clean:

```
FAIL 0x8c035370:   case 1: mem win5 @+0x8bb: got 0c want 8c
FAIL 0x8c0354a4:   case 1: mem win5 @+0x8c3: got 0c want 8c
```

The regenerated module computes its code base from the *masked* entry:

```c
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?...:(entry&0xff000000u));
```

`vf3_matrix_family_core` masks the entry to 29 bits before dispatching, so the
`0x8c` alias of a direct entry is gone and the module falls back to `0x0c`.
The committed module derives the alias from the link register instead, which
is what the recorded corpora expect.  The regeneration was therefore dropped
(`git checkout -- src/fight/vf3_c95_adapter.c`); the alias model is a separate
piece of work that has to keep the *unmasked* entry's alias.

## What is still open

| cluster | bytes | blocker |
|---|---|---|
| REIOS GD vector (`0x8c04326c` family) | 316 | the drive state behind the vector is per case; the corpus does not carry it |
| `0x8c063446` | 450 | the entry spins on a flag another thread sets; the corpus has one case |
| `0x8c04c024`, `0x8c0a2a84`, `0x8c04853a` | 542 | the port reads pages the corpus does not carry (OOB) |
| `0x8c035270`, `0x8c035306`, `0x8c035518` | 326 | the virtual dispatch through the table at `0x0c0ea314` returns a different value |
| `0x8c03bbd2` | 194 | `fr4` differs in one bit (`0x7ffff0c8` vs `0xfffff0c8`) |
| literal pool (`0x8c058780` family) | 98 | the image holds data where the RAM copy holds code |
| the 215 entries with no corpus | 27,750 | they never ran in any recorded capture |
