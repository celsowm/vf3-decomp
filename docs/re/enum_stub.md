# The enumeration stub 0x0C046E14: the indirect target is a plain literal

Status: 2026-10-31.  This closes the second lead of
`docs/re/boot_real_disc.md` ("the enumeration stub `0x0C046E14` - who computes
its indirect target (no literal, no direct branch, absent from RAM)").

**Nobody computes it.**  The stub calls through a literal in its own pool, and
the literal holds the target.

## The stub

```
0C046E14  sts.l pr,@-r15
0C046E16  mov.l @(56,pc),r3      ; r3 = the literal
0C046E18  add #-4,r15
0C046E1A  jsr @r3                ; the call
0C046E1C  mov.l r4,@r15
0C046E1E  mov r0,r4
0C046E20  tst r4,r4
0C046E22  bf 0x0C046E2C          ; r0 == 0 -> return
0C046E24  mov.l @r15,r4
0C046E26  add #4,r15
0C046E28  bra 0x0C046E594        ; otherwise the tail transfer
0C046E2C  add #4,r15
0C046E2E  lds.l @r15+,pr
0C046E30  rts
```

## Where the literal is

The SH-4 takes the base of a PC-relative load from `(PC & ~3)`, where `PC` is
the instruction's own address plus four.  For the load at `0x0C046E16` that is

```
(0x0C046E16 + 4) & ~3 + 56 = 0x0C046E18 + 56 = 0x0C046E50
```

and the word there is the target:

```
0C046E40  0C04C4F0
0C046E44  0C04C57C
0C046E48  0C0EA7D0
0C046E4C  0C04BE3C
0C046E50  0C04C9A2     <- the target of the jsr @r3
0C046E54  6E532FE6     <- code, the next function's first instructions
```

The old note's "no literal" came from reading `0x0C046E54`: that is
`0x0C046E1A + 56` rounded up to the next four-byte boundary, and it holds
code.  The pool slot is four bytes earlier.

The value is the same in the image and in the RAM the guest runs on - the slot
is not patched at runtime:

```
$ python -c "..."   # build/boot_long.ram, the port's own boot
0C046E50 = 0C04C9A2
0C04C9A2 = 2FD62FE6      (mov.l r13,@-r15 / mov.l r14,@-r15 - the callee's prologue)
```

`0x0C04C9A2` is a function of the same module, and the ledger already carries
it (`0x8c04c9a2` in `src/fight/vf3_c90e_adapter.c`).  The port's generated
adapter reads the very same slot:

```c
P_0c046e16: /* original d30e, guest PC 0x0c046e16 */
r[3]=read(ram,0x0c046e50u,4);
```

so the port was right and the note's premise was wrong.

## Correction

* `docs/re/boot_real_disc.md`, "What is still open": the enumeration stub's
  indirect target is the literal `0x0C04C9A2` at `0x0C046E50`; it is not
  computed at runtime and it is not absent from the RAM.
