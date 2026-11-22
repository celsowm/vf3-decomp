# native_cache_wb_stub

`cache_wb_stub` (`0x8C062E8E`) ported to plain C in
`src/native/cache_wb_stub.c` (`vf3_native_cache_wb_stub`), proved against the
readable guest authority (`src/fight/cache_wb_stub.c`,
`vf3_cache_wb_stub_entry`) by `tests/cache_wb_stub_native_replay.c`
(differential) and by the mutation gate
(`tests/cache_wb_stub_native_mutations.json`, 8/8 caught).

## The leaf

`cache_wb_stub` is a near-trivial call-free leaf: `ocbwb @r4; rts`.  The
operand cache is not modelled (RAM is always coherent in the port), so the
instruction has no architectural effect - every register is left as it was
and control returns to the caller.

## The port

`src/native/cache_wb_stub.c` is a no-op: it discards the context and returns
with nothing moved.

## The proof

`tests/cache_wb_stub_native_replay.c` seeds identical register state and RAM
on both sides and asserts that the comparable state (the `r[0..15]` file,
`pr`, `sr`, `fpscr`, `fpul`, `gbr`) is unchanged by **both** sides, that the
two agree, and that neither side wrote a byte of RAM (which is seeded with a
sentinel pattern).  Cases cover a low `r4` seed and a high (0x8c-form) one.

## The mutation gate

`tools/mutate.py --port src/native/cache_wb_stub.c --exe
build/vf3nativecachewbstub.exe --mutations
tests/cache_wb_stub_native_mutations.json --target vf3nativecachewbstub
--keep-going` catches **8/8**: touching `r4`, touching `r0`, writing RAM,
clobbering `pr`, `sr`, `gbr`, `fpscr`, or `fpul`.  A no-op leaf still has
observable state (every register and every RAM byte), and the gate pins it.

No regression to the coverage union (`docs/coverage.md` left untreated).
