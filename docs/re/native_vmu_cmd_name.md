# native_vmu_cmd_name (0x8C0374B0)

The save-operation name selector, ported natively in `src/native/vmu_cmd_name.c`
(`vf3_native_vmu_cmd_name`) as a plain-C transcription of the readable port
`src/fight/readable/vmu_cmd_name.c` (`vf3_vmu_cmd_name_entry`).

## Why this leaf

The readable authority is a self-contained leaf: **no calls, no FPU, no stack
frame** - the cleanest kind of native target.  It is a pure integer selector
over a small table of command ids, with one SR T bit as the only "carry".

## The body

The engine hands the function a command id in r4 and it answers with the
*address* of the ASCII string that names that operation, read from the literal
pool.  The pool holds one word per known command (the string's address at
`0x0c03754c..0x0c037564`) and one for the fallback (`0x0c037568`).  The body
copies r4 into r0, tests it against the seven known ids in order (0, 1, 2, 3,
7, 0xb, 0xc) and takes the first match, falling back to "UNKNOWN OPERATION".

Two details the port keeps:

* **r0 is overwritten twice** - the entry `mov r4,r0`, then the pool word on
  every path - so the answer in r0 is the string address, never the command
  id.
* **The T bit it leaves is the last test's.**  A matched id leaves T set (the
  matching compare just made it); the fallback leaves it clear (the last
  compare, `r0 == 0xc`, has just failed).

## Evidence

The **differential** (`tests/vmu_cmd_name_native_replay.c`, target
`vf3nativevmucmdname`) runs the native port against the readable guest port
from the same seed over the same ten scenarios as the readable test - the
seven known command ids (one per branch of the selector) and three unknowns
that take the fallback (5, `0xffffffff`, `0x1000`).  It lays the pool into one
flat window whose base matches the pool addresses (an early draft pointed the
window at `0x0c010000`, overrunning its own 64 KB buffer and segfaulting), runs
both sides, and compares the whole pool window byte for byte plus r0 (the
string-address answer) and SR's T bit.  It also checks the outcome against an
independent model of the guest (the same key/pool mapping), so a fixture that
is not where the guest looks cannot make both sides agree on the wrong bytes.
**10/10 PASS.**

The **mutation gate** (`tests/vmu_cmd_name_native_mutations.json`) applies
seven of the readable gate's eight mutations (the eighth, the exit PC, is
guest-specific - the native port's return is implicit): the command id from
r5, the fallback from the NOP slot, the save/load pool slots swapped, the
third key 2 instead of 3, the T bit the other way round, a known command never
matched, and the answer read from the next pool word.  The differential catches
**all 7**.

```
build\vf3nativevmucmdname.exe ->
  vmu_cmd_name_native_replay: PASS
python tools/mutate.py --port src/native/vmu_cmd_name.c --exe build/vf3nativevmucmdname.exe \
    --mutations tests/vmu_cmd_name_native_mutations.json --target vf3nativevmucmdname
  7/7 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
is byte-for-byte the generated translation (see docs/re/vmu_cmd_name.md).

## Notes

* The port keeps the pool reading live (reads `rd32(a, pool_addr)`) rather
  than baking the string addresses in, exactly as the guest reads them.
* The fixture/pool layout lesson from fdiv applies again: make the flat window
  base equal the guest addresses the leaf reads, or `rd32/ab` compute offsets
  past the buffer.
