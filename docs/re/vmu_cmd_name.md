# The save-operation name selector (SH-4 0x8C0374B0)

A readable port of the engine's save-operation name selector, and the evidence
for it.

## The function

| entry | body | what it does |
|---|---|---|
| `0x8C0374B0` | `0x0C0374B0..0x0C037500` (80 B) | maps a save-operation command id to the string that names it |

The function is a **self-contained leaf**: no calls, no FPU, no stack frame.
It reads a command id in `r4` and answers with the **address** of an ASCII
string naming that operation on the VMU / save unit.

The port: `src/fight/readable/vmu_cmd_name.c`, registered in
`src/fight/readable.c` as `vmu_cmd_name`.

## What the function does

The literal pool holds the addresses of the strings.  The guest copies `r4`
into `r0` and tests it against seven known ids in order, taking the first
match; an id that matches none falls back to the "UNKNOWN OPERATION" string:

| id | the string returned |
|---|---|
| `0`   | `"NOP"` |
| `1`   | `"CONNECTED"` |
| `2`   | `"DISCONNECTED"` |
| `3`   | `"FORMAT DISK"` |
| `7`   | `"DELETE FILE"` |
| `0xb` | `"LOAD FILE"` |
| `0xc` | `"SAVE FILE"` |
| else  | `"UNKNOWN OPERATION"` |

The strings are not inline: each answer is the string's address stored in the
pool at `0x0C03754C`..`0x0C037564` (one word per known id), and the fallback
at `0x0C037568`.  In the image these point at the ASCII text at
`0x0C0CCD14`.. (e.g. `0x0C03754C` = `0x0C0CCD14` = `"NOP"`).

## The details the port has to keep

**The T bit the guest leaves depends on the path.**  The matching compare made
the T bit set, so a matched id leaves T set; the fallback leaves it clear,
because it is the last compare (`r0 == 0xc`), which has just failed.  The port
mirrors this by leaving the loop's last `set_t` in place.

**r0 is overwritten twice.**  `mov r4, r0` at the entry, then the pool word on
the chosen path - so the answer in r0 is the string address, never the command
id.

**The live register set is tiny.**  The generated translation only touches r0
and the T bit (SR bit 0), and leaves every other register - including r4 and
the return address r16 - untouched.  The readable port does the same, so the
full-register-file comparison passes.

## The registers the guest leaves

Only r0 and the T bit change.  r0 holds the string address; the T bit is set
on a match and clear on the fallback.

## The evidence

**The differential** (`tests/vmu_cmd_name_replay.c`, 10 scenarios) compares
three arms on the whole register file, the return PC, the failed PC, the
out-of-window counter and every RAM byte: the generated chain (the reference),
the readable port called directly, and the readable port reached through the
readable override (which is how the native tick reaches it).  It also checks
the outcome **against the fixture itself**: the answer in r0 has to be the
fixture's pool word for the command, and the T bit has to match the path.

The pool is ROM, so the test supplies it as a window carrying the image's own
words - the eight string addresses.  Every one of the eight is distinct, so a
port that reads the wrong offset answers with the wrong string and fails both
the differential and the fixture check.

The scenarios cover **every branch of the guest's tree**: the seven known ids
(one per selector branch) and three unknowns - `5`, `0xFFFFFFFF` and `0x1000`
- that all take the "UNKNOWN OPERATION" fallback.

**The mutations** (`tests/vmu_cmd_name_mutations.json`, 8 of them) are all
caught by `tools/mutate.py`: the id read from the wrong register, the fallback
from the NOP slot, the LOAD branch answering from the SAVE slot, the third key
typoed to `2`, the T bit inverted, a known command never matched, the answer
read from the next pool word, and the exit PC mis-set.

## The coverage accounting

The selector is a **leaf inside the baseline body of `f_8c03746a`**: its span
`0x0C0374B0..0x0C037500` sits inside that entry's `0x0C03746A..0x0C037502`,
which is already ported.  So the ledger row carries a size of 80 but adds **0
address-union bytes** (the union is flat), exactly like the nested leaves the
address-union metric exists to keep from double counting.

There is **no corpus for the `0x8C0374B0` entry itself** (the golden bindings
only name the nominal `0x8C03746A`), so the chain here is only
*readable port == generated translation* - the third leg (== oracle) is
missing and cannot be closed offline, in the same shape as the state-advance
port.  The readable port is still a genuine SRP gain: it turns a block of the
generated goto-ladder into reviewed source-level C with a named, single
responsibility.
