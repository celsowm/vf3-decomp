# native_matrix_io — the matrix store/load leaves (0x8C03B620 / 0x8C03BD80)

The readable ports `src/fight/matrix_lib.c` (`vf3_matrix_store_entry`,
`vf3_matrix_load_entry`) are rewritten as plain C in
`src/native/matrix_io.c` (`vf3_native_matrix_store`,
`vf3_native_matrix_load`), proved against them by
`tests/matrix_io_native_replay.c` (5 differential cases) and by the mutation
gate (`tests/matrix_io_native_mutations.json`, 9/9 caught).

## The leaves

Two sibling, self-contained, call-free leaves that move the current transform
(XMTRX) between the XF bank and RAM.  The guest keeps XMTRX in the XF bank
(readable `s->v[37..52]`); the native port carries it as `a->xm[16]`.

```
matrix_store (0x8C03B620):
  dest = r4;  if (dest == 0) dest = *(0x0C19D2EC);   (the matrix stack top)
  write XMTRX (16 words) to dest;
  r0 = dest;  r4 = dest;

matrix_load (0x8C03BD80):
  src = r4;  if (src == 0) src = *(0x0C19D2EC);      (the matrix stack top)
  XMTRX = the 16 words at src;
  r4 = src + 64;
```

Only `r0`/`r4` (store) or `r4` (load) and XMTRX move; everything else — the
other registers, SR, pr — is untouched.  Both reads/writes are raw 32-bit
word moves, so arbitrary bit patterns pass through uninterpreted.

## The port

`src/native/matrix_io.c` uses the shared byte-exact RAM accessors
(`vf3_aim_u32`, `vf3_aim_set_u32`, `vf3_aim_fbits`, `vf3_aim_ubits`) and the
stack-top fallback reads the pointer word at `0x0C19D2EC` exactly as the
readable port does.  No FRU is used beyond the XF bank the leaf already owns,
so `vf3_native_aim` needs no extra state.

## The test

`tests/matrix_io_native_replay.c` seeds the flat RAM with a distinctive
16-word matrix at `0x0C1A0000`, the stack-top pointer at `0x0C19D2EC`, and
the same XMTRX into both the guest XF bank (`s->v[37..52]`) and the native
`a->xm[16]`.  Five cases:

- store to an explicit destination (`r4` nonzero): the RAM at the
  destination and `r0`/`r4` are compared against the guest;
- store via the stack top (`r4` zero): the write lands at the pointer's
  value;
- load from an explicit source: the resulting XMTRX (native `xm` vs the
  guest XF bank, word for word) and `r4 = src + 64` are compared;
- load via the stack top;
- store to the matrix's own source address.

Every other register is checked equal to its entry value on both leaves.

## The mutation gate

`tests/matrix_io_native_mutations.json` applies 9 single mutations: the word
count (15 vs 16) and a skipped store for `matrix_store`; the stack-top
pointer offset (`+4`) and the `r0`/`r4` writes for both; the word count, the
stack-top pointer and the `r4` advance for `matrix_load`.  All 9 are caught.
Command:

```
python tools/mutate.py --keep-going --port src/native/matrix_io.c \
  --exe build/vf3nativematrixio.exe \
  --mutations tests/matrix_io_native_mutations.json \
  --target vf3nativematrixio
```

## Authority

The readable ports are the authority; the chain is *native == readable*.
No oracle corpus names these exact entries as watched specimens, so the proof
stands on the differential against the readable translation, the same shape
every readable leaf uses.

Result: **5/5 PASS**, **9/9 mutations caught**.
