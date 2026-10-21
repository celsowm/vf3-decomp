# The exception vector: 405,744 B (93.35%)

## What the STC VBR really is

The helper at `0x0c060eba` is the game installing its own exception handler
vector: it stores a pointer into the SH-4's VBR table.  The port had refused
that instruction (`stc vbr,r2`), so every specimen that reached the installer
failed closed and the entry never got a corpus that replays.

The value the reference stores is **0x0c00f400**, not the REIOS default
`0x0c000000`.  The evidence is in the captured specimens themselves: the
game's handler installer at `0x0c060ea6` writes its pointer to `VBR+0x224`,
and every recorded specimen carries that word at `0x0c00f624` - which is
`0x0c00f400 + 0x224`.  A VBR of `0x0c000000` would have put the word at
`0x0c000224`, and no specimen has it there.

With the constant right, all six corpora of `0x8c06371c` (27 cases) replay
clean, and the entry promotes for 80 bytes.

## The change

Three generated adapters (`src/fight/tenpp_survey_adapters_2.c`,
`src/fight/vf3_c95_adapter.c`, `src/fight/vf3_sweep_adapters_1.c`) now emit the
store instead of failing closed:

```c
P_0c060eba: /* original 0222, guest PC 0x0c060eba */
r[2]=0x0c00f400u;
```

`tools/oracle/translate_adapters.py` carries the same rule, so a regenerated
module keeps it.

## Result

| item | value |
|---|---|
| union of the ported body ranges | 405,744 B (93.3483%) |
| ledger entries | 2,314 |
| promoted here | `0x8c06371c` (80 B) |
| strict-replay gate | 2,321 / 2,321 PASS |

The 93% bar (404,230 B) was crossed by the previous commit; the next bar is
94% = 408,576 B, i.e. 2,832 B more.
