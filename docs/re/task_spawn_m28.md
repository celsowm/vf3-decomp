# Task spawner + pointer-alias rule (M28, 2026-09-24)

## Pointer-alias rule (verified across literal pools)

Compiler-emitted literal dwords hold **physical** addresses
(0x0C000000-mirror). SH4 P1 cache maps 0x8C000000 -> 0x0C000000, so
e.g. literal `0x0C0EA2EC` == runtime `0x8C0EA2EC`. All decoders/ports
must normalize: `addr | 0x8C000000` when `0x0C000000 <= addr < 0x0D000000`.
Verified in f_8c034852 and f_8c0349aa pools (`spawner_true.txt`).

## f_8c0349aa — task-node spawn/link (true-image decode)

```
n = f_8c035bf2( mem = root_obj->f2C,        /* alloc pool        */
                zero = 0,
                arg1,                        /* r6                */
                arg2 << 11 )                 /* r7 = size << 11   */
if (!n) return -9;
n->w4A = (uint16_t) root_obj->f08;           /* generation tag?    */
r0   = f_8c0356cc( n, arg2, arg3 );          /* node init          */
     = f_8c0355a0( n );                      /* register/link      */
return r0_from_first_call;                   /* *r15 saved result  */
```

Cross-links:
- `f_8c034852` state-6 helper == `f_8c0355a0` == the node register/link
  called by the spawner. State 6 in the dispatcher = "finalize node".
- Allocator `f_8c035bf2(mem_pool, 0, a, size<<11)`: pool object at
  `root_obj->f2C`; units are bytes encoded as `size<<11` (2 KiB units).

## M28 open thread (next): MT pack mount-time relocation

`docs/re/mt_vm.md` open thread: the mounted MT record region is shifted
uniformly ~+0x27B0 vs the file (vf3_7 capture), and the 8,880-slot offset
table (tools/mtmap.py) is rewritten at mount. The loader sits between
GDFS read of `MTJACLAU.BIN` (gdfs slot 104) and the task VM motion
headers; its fixup pass walks `hdr[1]` key-times / `hdr[2]` tuples.
Static-side search recipe: xref the GDFS-table string `MTJACLAU.BIN`
(gdfs slot 104) from its literal physical-alias dword.
