# (b) Top-50 head recon — structural ports next (2026-09-25)

Source: extract/analysis/top50_m71.csv (largest unclaimed) joined with
disasm_1ST_READ.unsc.bin.dispatch.csv (2578 rows) + sh4full.py dumps.
No ledger credit claimed — transliteration still pending.

## 1. FUN_8c0750be — 5432 B (largest unclaimed)
Prologue: sts.l pr / mov.w 0xFF4C (frame -180?) / mov.w 0x00B0 / sts.l macl /
add r0,r15 + add r15,r3 frame base; r4/r5 saved to frame; refcount bump
(mov.l @(r0,r3),r2; +1) at 8c0750da-e0; scene byte test mov.b @(3,r2) at 8c0750e8.
Data islands inside body: .word runs at 8c075208-21A (0x0000/0x0080/0x0001 runs).
Dispatch (7): r10 @8c0752F2; r12 @8c075376; r14 x5 burst @8c0756E2/F4 (6B stride = slot ladder).
Tail: flag tests 0x00800000/0x40000000, cmp/eq #4, jmp @r3 via lit 0c076942.
Role: scene/task frame (r14 task bursts + r13/r12 struct tails).

## 2. f_8c0782ea — 4472 B (top dispatcher, 23 sites)
Prologue: sts.l pr / mov.w 0xF784 (frame -1928?) / mov.w 0x0878 + r4/r5/r6/r7 to frame;
r14/r13/r12 struct loads at 8c078312-1A; per-part store mov.l r3,@(20,r12).
Dispatch (23): r13 @8c07837E/8c078490/98; r14 x6 @8c078564-94; r12 @8c07860C;
r14 x5 @8c0786C2-DA; r14 x6 @8c079220-3E. Largest struct-task ladder in image.
Role: fight/scene frame driver candidate — trace first (vf3_7 watch pc 8C0782EA).

## 3. f_8c076c00 — 4138 B (12 sites)
Prologue: sts.l pr / mov.w 0xFF64 / mov.w 0x0098 + r4/r5/r6 to frame;
literal 0c29b864 stored to frame; r14/r13 loads.
Dispatch (12): r14 x10 burst @8c076D42-7C; r13 @8c0772BA; r12 @8c0772C0.
Role: sibling frame of 8c0782ea (same prologue shape, shorter tail).

## Port order
1. 8c0782ea first (most dispatch signal; trace it from vf3_7).
2. 8c076c00 second (same family, reuses ladder model).
3. 8c0750be last (largest + data islands need CFG split).
Each: sh4full full dump → transliterate prologue/frame + slot ladder with
registry hooks (walker.c pattern) + replay test before ledger credit.
