# The 93% bar: the alias handoff, the claim rule and the missing RAM shadows

Date: 2026-10-21. Follows `docs/re/coverage_93_c97_batch.md` and
`docs/re/coverage_92_translator_gaps.md`.

The coverage went from **92.8431%** (403,548 B of 434,656 B) to
**93.2609%** (405,364 B).  The 93% bar (404,230 B) is crossed.  Three
independent defects stood between the port and those bytes, and each one is a
property of the *harness*, not of the SH-4 code that was ported.

## 1. The address alias has to travel with the call

The SH-4 mirrors the `0x0c000000` region at `0x8c000000` and at
`0xac000000`, and the game's loader reaches the same code through all three.
A PC-relative `mova` computes its result from the address the CPU is
executing, so the *mirror* the code runs under is part of its behaviour:

```
0c010758  4f22    sts.l pr,@-r15
0c01075a  4f12    sts.l macl,@-r15
0c01075c  7ff8    add #-8,r15
0c01075e  d36e    mov.l 0x8c010918,r3
0c010760  c702    mova 0x8c01076c,r0      <-- PC-relative: the base matters
...
0c01077a  410b    jsr @r1                 <-- the callee runs at 0xac01098c
```

The capture of `0x8c010758` shows the body running at `0x0c010758` and then
jumping into the `0xac` mirror (`0xac01098c`), where a second `mova`
produces `0xac0109a0`.  The reference's final `r3` is `0xac0119a4`; a port
that computes the same address in the `0x0c` mirror gets `0x0c0119a4` and the
strict replay rejects it.

The first attempt tracked the alias *per site* (each `mova` baked with the
alias seen in its own capture).  That is wrong: the same code legitimately
runs under `0x0c` in one capture and under `0xac` in another, so the alias is
a property of the *run*, not of the instruction.  The translator now keeps a
`code_base` variable that follows the execution:

* the entry sets it from the mirror the entry was reached under;
* an indirect jump sets it from the branch target (`code_base=target&0xff000000u`);
* a `mova` emits `r[0]=code_base|0x…u;` instead of a literal.

There is one hole left: **the router masks the entry PC to 29 bits**
(`entry&=0x1FFFFFFFu` in `vf3_matrix_family_core`), so the callee never sees
the `0xac` mirror of its own entry PC.  The alias therefore travels out of
band: the caller sets two words before it hands control over, and the callee
reads them once, on entry.

```c
/* src/fight/matrix_family.h */
extern uint32_t vf3_matrix_call_alias;    /* top byte of the call target */
extern uint32_t vf3_matrix_call_alias_pc;  /* masked PC of that target */
```

The generated call site emits

```c
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u);
if(!vf3_matrix_family(target,s,ram)) return 0; ...
```

and the module's entry reads them:

```c
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias
                   :(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
```

The harness resets the two words before every case
(`tests/matrix_family_replay.c`), so a stale alias from the previous case can
never reach the next entry.

With the handoff, the two entries that the per-site model could never express
(`0x8c010684`, `0x8c010758`) replay strict-clean over 3 and 4 corpora.

## 2. A module has to serve what nobody else serves

`docs/re/coverage_92_translator_gaps.md` introduced the two arrays a generated
module emits:

* `owned_pcs[]` - every PC the module implements;
* `claim_pcs[]` - the PCs the router may route here: *the PCs no other module
  owns*, plus the module's own roots.

Ownership turned out to be the wrong criterion.  A PC can be **owned by three
modules and claimed by none**: `c90`, `c91` and `c95` all walk into
`0x0c0635ec`, but each of them excludes it from its claim set because another
module owned it when it was generated - and the module that "owns" it does not
claim it either.  The router then has nowhere to send the call, and the entry
that needed it fails with `unsupported helper/state at 8c063446 PC 0c0635ec`.

The rule is now: **a module serves the PCs no other module *claims***.  The
translator reads the other modules' claim arrays (falling back to their owned
set for the legacy modules, which have none and therefore serve everything
they own) and treats that as the "already implemented" set:

```python
def adapter_claims(paths):
    """The PCs a module actually serves."""
```

Both the *implementation* decision (`reused()`) and the *claim* decision now
use that set, so a PC that nobody serves is implemented by the newest module
that walks into it - and it is routed there.

## 3. A corpus without its RAM shadow is not evidence

`tools/build_promote_csv.py` only accepts a corpus whose every row still has
its entry/exit RAM shadow.  Three entries with a recorded corpus
(`0x8c058348`, `0x8c04e8f8`, `0x8c09457e`) had lost their `.in.bin`/`.out.bin`
files, so they were excluded - 814 B of body bytes that nobody could claim.

The reason the shadows are missing is the recorder's page budget: the
original capture ran with the 128-page observer, and the specimen touched more
pages than the budget allowed, so the row was recorded without its RAM.  The
re-capture has to use an observer that keeps the pages.

`tools/oracle/recapture_v2.py` re-runs a recorded batch with the v2 observer
(the patched oracle with the page budget at 1024) and reproduces every
parameter of the original run from the batch manifest.  Two details matter:

* `--max-samples` is **not** recorded in the manifest; the recorded campaigns
  used 256 samples, and the default of 64 silently truncates the probe
  campaign to a quarter of its seeds;
* the page budget raises the cost of every probe restore, so the campaign
  needs more frames to reach the same number of seeds (`600` instead of
  `120` for `0x8c058348`).

With the shadows back, `0x8c058348` (4 cases) and `0x8c09457e` (16 cases)
replay strict-clean and were promoted through `vf3_c103_adapter.c`.

## 4. What the milestone contains

| module | roots | promoted |
|---|---|---|
| `src/fight/vf3_c101_adapter.c` | 10 | 10 (nested bodies, 0 new union bytes) |
| `src/fight/vf3_c102_adapter.c` | 6 | `0x8c011090` |
| `src/fight/vf3_c103_adapter.c` | 2 | `0x8c058348`, `0x8c09457e` |
| `src/fight/vf3_c99_adapter.c` (regenerated) | 7 | `0x8c010684`, `0x8c010758` + 5 earlier |

`vf3_c102_adapter.c` sits **ahead** of `vf3_c95_adapter.c` in the router
chain: `c95` walks into the literal-pool family (`0x8c058780/84/88/8c`) and
into `0x8c0512dc` as well, and claims them, so the module that implements
the roots has to win them.

## 5. What is still parked, and why

* **The literal-pool family** (`0x8c058780/84/88/8c`, 98 B).  The four
  addresses are *data* in the image and code in the RAM copy: the reference
  executes `4f22` (`sts.l pr,@-r15`) at `0x0c058788`.  A statically
  generated module cannot express that - the word in RAM decides what runs -
  so the entry needs a dynamic decode of the pool.  `u90_sw2_8c058780` fails
  8 of its 16 cases on the call-out to `0x0c0588f0`, a fall-through past the
  end of the body that no module serves.
* **The REIOS GD vector** (7 entries, 194 B).  The loader polls
  `GET_CMD_STAT` until the transfer completes, and the size it reports is the
  byte count the drive has moved.  The state lives in the firmware's command
  queue, which no corpus carries (`docs/re/reios_exec_server.md`).
* **`STC VBR`** in the helper `0x0c060eba`: the game's vector base is not in
  the captured state.
* **The four big corpus-less entries** (`0x8c09575c` 1,780 B,
  `0x8c0a1658` 1,176 B, `0x8c07d95a` 822 B, `0x8c0980d2` 718 B).  The
  isolated probe reaches them but every specimen is retired with the
  instruction budget: the entry spins instead of returning.
