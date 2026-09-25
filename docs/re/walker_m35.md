# M35 — walker/frame-ladder reinterpretation (2026-09-24, recon slice)

Byte-level hexdump at 0x8C0B1AA2 resolves the dispatch block structure:

```
8C0B1A86  r0 = mov.w @(24,pc)  -> word 0xC4F0 (at 8C0B1AB8)
8C0B1A8C  r0 = mov.w @(20,pc)  -> word 0x756C (at 8C0B1AB4)
8C0B1A92  r0 = mov.w @(16,pc)  -> ...
8C0B1A98  r0 = mov.w @(12,pc)  -> ...
8C0B1A9A  jsr @r12 ;  r4 = mov.l @(r0, r13)     # arg = *(base13 + word)
8C0B1AAA+ sequential helper chain: mov.w r4,@(table-esc) ; bsr 0x8C0B2510 ;
          bsrf r12 ; bsr 0x8C0B15B4 ; bsrf r12 ; ...
```

So the scene switch selects a **word offset** by scene id — and
`*(r13 + word)` = per-scene handler arg, `r12` = handler entry. This
vindicates the old `FRAME_SLOTS = {0x0C0E, 0x76AC, 0x0C0E, 0x76B8,
0x0C0E, 0x76C4}` constants in `src/fight/frame.c`: they are EXACTLY this
kind of struct-offset word (offsets into the per-task state record living
in the r13-pointed table region), NOT PCs. frame.c's port shape stands;
its on-image citations were the stale part (M27 fixed the attribution).

Words observed in this walker's switch block: 0xC4F0, 0x756C, 0x7662,
0x8570 chain the per-scene dispatch.

## Follow-up (next turn)
- Full transliteration of f_8c0b1a54 (224 B) + fight runner f_8c0796f4
  into `src/fight/walker.c` / `runner.c` with registry helper hooks.
