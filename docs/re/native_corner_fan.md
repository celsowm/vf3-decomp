# native_corner_fan

Native port of the four-corner offset-fan, **0x8C03FB10**, as the plain-C
leaf `vf3_native_corner_fan` (`src/native/corner_fan.c`), in the same spirit
as the other `src/native/*` ports: a transcription of the readable guest port
`src/fight/geom_readable.c` (`vf3_corner_fan_entry`) onto the
`vf3_native_aim` context (flat RAM, FR bank, register file, FPUL).

## The function

A self-contained FP leaf (call-free, no tail-transfer).  r4 = object (flags
word at **+0x2C**: low 2 bits = the base column A, the next 2 bits = the base
row B), r5/r6 = output arrays of 4 floats, FR4..FR7 = (a, b, c, d).  Each of
the **4 table corners** (u, v) in `0x0C0EA670` gives

    du = u - A, dv = v - B
    out5 = obj[+4] + du*(a*d) + dv*(b*c)
    out6 = obj[+8] - (a*c)*du + dv*(b*d)

in the order of the original: the **macs round once**, and the du (dv) terms
are skipped entirely when du (dv) is zero.  This entry also writes the entry
FR14 — a **dead push** — to sp-4.

Leaves the four outputs in r5/r6's arrays, r1 = 0, r3 = 3, r5/r6 one past the
arrays, r7 = the pool table's end, FPUL = the row, SR's **T bit set**, and
fr0..fr11 repacked (fr0/1/2/3 the per-iteration lasts, fr4 = a*c, fr5 = b*d,
fr6 = base_u, fr7 = the last du, fr8 = a*d, fr9 = b*c, fr10 = the last dv,
fr11 = the last out5).  fr12..fr15, the stack pointer and pr are untouched.

## Proof

* **Differential** — `tests/corner_fan_native_replay.c` (the
  `vf3nativecornerfan` target) runs the native leaf against the readable
  guest port on the same flat RAM (the object, the corner table, the two
  output arrays, the sp-4 push slot) for **8 scenarios** (all four base
  corner/row selectors, negative coefficients) and matches:
  * the output arrays and the dead sp-4 push, byte for byte;
  * the output registers r1/r3/r5/r6/r7, FPUL and SR's T bit, and every
    untouched register against its entry value;
  * every FR-bank output the leaf writes (fr0..fr11) and the untouched
    fr12..fr15;
  * an **independent fixture model** that recomputes all four (out5, out6)
    pairs from the defining equation with the same toward-zero + fused-mac
    rounding.
  The fixture seeds SR with T **clear** so the leaf must set it.
* **Mutation gate** — `tests/corner_fan_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/corner_fan.c --exe
  build/vf3nativecornerfan.exe --mutations
  tests/corner_fan_native_mutations.json --target vf3nativecornerfan
  --keep-going`).

## Details the port keeps

* A and B come from the **flags word** (`& 3` and `>>2 & 3`), converted
  int->float, and are **subtracted** from each table corner (u, v) to get
  du, dv.
* The four products `bc, ac, bd, ad` are computed **once** up front; the
  per-corner terms are **fused macs** (`fmaf`) that round once — a
  multiply-then-add would round twice and drift.
* The du arm **negates** (`^0x80000000`) the `ac*du` product before adding —
  this is the `out6 -= (a*c)*du` term.
* The du/dv terms are skipped when du/dv is exactly **zero**.
* The dead fr14 push writes the **entry** FR14 to sp-4 before any FR register
  is touched; the test compares that slot so the push is pinned.
* FPUL = the row (B), not the column; r7 = the table's end pointer.

## Files

* `src/native/corner_fan.h` — the `vf3_native_corner_fan` declaration.
* `src/native/corner_fan.c` — the port.
* `tests/corner_fan_native_replay.c` — the differential test.
* `tests/corner_fan_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativecornerfan` target.
