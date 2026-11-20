# native_record_flag40

Native port of the record flag-40 probe, **0x8C04B9BE**, as the plain-C
leaf `vf3_native_record_flag40` (`src/native/record_flag40.c`), in the same
spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/small_leaves.c` (`vf3_record_flag40_entry`) onto the
`vf3_native_aim` context (flat RAM, register file).

## The function

A self-contained leaf (call-free, no FPU, no stack frame).  `r4` is a record.
It reads the record's first word — the **record kind**:

```
kind = *r4;
T    = (kind == 1);
if (kind == 1) { r0 = 0; }
else           { r1 = 16; r0 = (int8)byte[ *(r4+4) + 16 ] & 0x40; }
```

So `r0` is `0` for a kind-1 record, otherwise the low `0x40` bit of the byte
the record's second word points at (offset `+16`), sign-extended and masked.
`r1` is set to `16` on the else path only; `r4` and every other register are
untouched.  SR's T bit is `(kind == 1)`.  The return pops `pr` (the caller's
return address).

## Proof

* **Differential** — `tests/record_flag40_native_replay.c` (the
  `vf3nativerecordflag40` target) runs the native leaf against the readable
  guest port on the same flat RAM and register file for 7 scenarios (kind 1
  with the bit set and with it clear, kind 0 with the bit set/clear/other,
  kind 2, and a kind with the high bits set) and matches:
  * the output registers `r0` and `r1` and SR's T bit against the guest;
  * every other register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** that computes `r0`/`r1`/T straight from
    the record.
  The fixture seeds SR with T **clear** so the leaf must set it, and gives the
  record's pointer and the aux byte distinguishable values.
* **Mutation gate** — `tests/record_flag40_native_mutations.json`, **6/6
  caught** (`python tools/mutate.py --port src/native/record_flag40.c --exe
  build/vf3nativerecordflag40.exe --mutations
  tests/record_flag40_native_mutations.json --target vf3nativerecordflag40
  --keep-going`).

## Details the port keeps

* `r1` is set to **16 only on the else path** — the kind-1 path leaves it
  untouched.
* The pointer is read from **`[r4+4]`**, not `[r4]`.
* The aux byte is read from **`ptr + 16`**, sign-extended, then masked with
  `0x40` — so only the flag bit survives.
* SR's T bit is **`(kind == 1)`** — set for a kind-1 record, clear otherwise.

## Files

* `src/native/record_flag40.h` — the `vf3_native_record_flag40` declaration.
* `src/native/record_flag40.c` — the port.
* `tests/record_flag40_native_replay.c` — the differential test.
* `tests/record_flag40_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativerecordflag40` target.
