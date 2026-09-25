# M47 — differential harness spec (2026-09-25)

Anchor: `extract/analysis/watchcount_boot3.csv` (M36):

```
0x8c034864 (dispatcher) 292033 hits, rec 133959203..308253416
0x8c0b1a54 (walker) 2048 hits, rec 286089014..426610212
0x8c0796f4 (runner) 0 hits (boot window; fight-only, expected)
0x8c09574e (startup) first hit rec 97856828
```

Replay: run ported `vf3_frame_dispatch` (mainloop.c) + `vf3_node_finalize`
+ `vf3_walker_step` (walker.c) vs `trace_boot3.bin` (427M records):
replay N frames, PC-sequence compare around dispatcher calls
(`0x8C034852` step + `0x8C0355A0` aux + walker switch). Tolerances:
guest-arena base remap allowed; vtable registry hits must match exactly;
frame-marker `root+0x24` 1→0 discipline asserted per step.
`tools/trace_watchcount.py --watch <pc-list> trace_boot3.bin --out` is the
counter; PC-compare harness is next code (gated on vf3_7 fight window).
