# Main loop / frame dispatcher (M25, 2026-09-23)

Corrected-image enabled the long-blocked main-loop frontier (the M3 "static
jsr ~3%" ceiling was a property of the shuffled image — literal vcalls now
resolve).

## Boot chain (true-image verified)

```
0x8C010000  image entry: reloc copy loop -> jmp @r2
0x8C020000  CRT0: 3x BSS-zero loops (mova tables), GPR/FR zero, SP load,
            jsr @r0
0x8C09574E  startup (_start == this; trace: first executed @rec 97,856,826)
```

## f_8c034852 — per-frame task-node dispatch step

Root object at `*(0x8C0EA2EC)`. Per frame (walked by caller; this fn does
ONE step against the chain head):

```
root_obj->f24 = 1                       # frame marker
node    = root_obj->f28                 # chain head
payload = node ? node->f3C : 0
handler = root_obj->f14->f10            # vtable call
r0 = handler(payload, &frame[2])        # frame on caller stack
switch (r0):
  0,1: root->f28=0; node->w4C=r0; node->f3C=0
       r0==1 ? by state word (node->w44):
                 1: node->f18=frame[0]; node->f14+=node->f1C;
                    w44=0; w46=2; if (node->f24) node->f24(node->f40)
                 4: node->f18=node->f20; node->f14+=node->f1C; w46=2
                 6: jsr 0x8C0355A0(node)             # aux (unported)
       -> node->w44 = 0
  7:   api = root->f20; er = api->f24(payload, frame)
       er==1 -> node->f18 = frame[0]
       er==0 -> removal path (data island 0x8c03492c; TODO)
  4,5,6: node->w4C=r0; node->w4E=frame[0].lo; node->f40=frame[1];
         node->f3C=0; root->f28=0; if (node->f34) node->f34(node, w4E)
  default: node->w4C = r0&0xFF; node->f3C=0; root->f28=0
root_obj->f24 = 0
return r0
```

Fact-checked line-by-line against `tools/sh4full.py` dumps and the
`mainloop_replay` unit test (all five result classes + empty chain).

## Port

- `src/sys/mainloop.{c,h}`: guest-arena memory model
  (`vf3_sys_bind_ram` + rd/wr) + host registry
  (`vf3_sys_register`/`vf3_sys_lookup`) for vtable targets.
- `tests/mainloop_replay.c` (vf3loop): result classes 0/1/4/5/6(0-path)/7/
  default/empty-chain — PASS.

## Tremors from the image fix (to re-derive next turns)

- The fight-runner `fight_f_8c0796f4`-family addresses point at trace-true
  PCs, but Ghidra bodies/name CSVs pre-M23 are quarantined; the verified
  frame pipeline (src/fight/frame.c with the six-slot ladder) must be
  re-cross-checked against the new listing.
- `f_8c03482a` (memcmp5) + this dispatcher compose the actual frame engine:
  the OLD `f_8c035ca2`-era notes were shuffle junk.
- mt loader relocation (+0x27B0 record shift) sits between this dispatcher
  and `mt_vm_eval_frame` (docs/re/mt_vm.md open thread).
