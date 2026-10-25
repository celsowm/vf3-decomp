# The uncached-mirror call (SH-4 0x8C011984)

Date: 2026-10-25. Follows `docs/re/coverage_100_gap_translation.md` (the 100%
bar) and `docs/re/gap_dispatch_audit.md`.

The gap batch translated 237 bodies the oracle never reached
(`docs/re/coverage_100_gap_translation.md`); that translation is a faithful
disassembly, but it is a disassembly, not a port.  This is the first of those
bodies to be rewritten as source-level C and proved against the translation it
replaces.

## 1. What the function does

```
0x0c011984  sts.l pr,@-r15      ; push pr
0x0c011986  add r0,r3           ; r3 += r0
0x0c011988  mov.l @(59*4,pc),r2 ; r2 = the literal pool word at 0x0c011a78
0x0c01198a  mov r3,r0           ; r0 = r3
0x0c01198c  or r2,r0            ; r0 |= r2
0x0c01198e  jsr @r0             ; call it
0x0c011990  nop                 ; the jsr's delay slot
0x0c011992  tst r0,r0           ; T = (r0 == 0)
0x0c011994  bt 0x0c01199c       ; a PLAIN bt: no delay slot
0x0c011996  lds.l @r15+,pr      ; the fall-through: pop pr
0x0c011998  rts                 ; pc = pr; the delay slot runs first
0x0c01199a  mov #1,r0           ; the RTS's delay slot: r0 = 1
0x0c01199c  mov #0,r0           ; the bt's target: r0 = 0
0x0c01199e  lds.l @r15+,pr      ; pop pr
0x0c0119a0  rts                 ; pc = pr
0x0c0119a2  nop                 ; the rts's delay slot
```

In words: **take a base in r3 and an offset in r0, add them, force the result
into the 0xac mirror and call it.  The answer is one when the callee left a
non-zero r0 and zero when it left zero.**

Two details are easy to get wrong:

* the `mov #1,r0` belongs to the **delay slot of the `rts`**, not to the
  branch.  The branch is a plain `bt`, and a plain `bt` has no delay slot -
  only the `/s` forms have one.  So the non-zero arm pops the pr and returns
  through the `rts`, whose delay slot sets r0 to one, and the zero arm
  branches to the `mov #0,r0` and returns through an `rts` of its own.  The
  net effect is `r0 = (r0 == 0) ? 0 : 1`, and the T bit ends up **set when
  the answer is zero** - the last test the guest made is the one the caller
  sees.
* the `rts` only sets the pc: it does **not** restore r14.  A SH function
  that wants r14 back pops it explicitly (`mov.l @r15+,r14`) in front of the
  `rts`, and this function never touches r14 at all - so the port must not
  touch it either.
* the literal pool word at 0x0c011a78 is **0xa0000000**.  The SH-4 mirrors the
  0x0c000000 region at 0x8c000000 and again at 0xac000000, so the mask turns
  any address of the region into its 0xac form - the uncached one.

## 2. The two things the router cannot see

The generated module computes its code base like this:

```c
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))
  ? vf3_matrix_call_alias
  : (((entry&0xff000000u)==0x8c000000u)
      ? (((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u)
      : (entry&0xff000000u));
```

and hands the callee the mirror it jumped to:

```c
vf3_matrix_call_alias_pc=(target&0x1fffffffu);
vf3_matrix_call_alias=(target&0xff000000u);
```

Both matter here, because the continuation the callee comes back to is
written with the code base (`r[16]=code_base|0x0c011992u`).

A readable port is reached through `vf3_family_override`, and the dispatcher
hands it the **masked** entry (`entry & 0x1FFFFFFFu`).  The mirror therefore
cannot travel in the entry PC; it travels in the two alias words, and the
port reads them the way the module does:

```c
if (vf3_matrix_call_alias_pc == (ENTRY & 0x1fffffffu)) return vf3_matrix_call_alias;
return 0x0c000000u;
```

The second line is the masked entry's own top byte - which is exactly what
the generated module computes for a masked entry.  Every generated caller
sets the alias before it hands control over, so a run that came through a
caller keeps its mirror; a run that did not is in the 0x0c mirror in both
arms.

## 3. The port

`src/fight/uncached_call.c`:

```c
int vf3_uncached_call_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t base = code_base_of(s);
    uint32_t target;
    int zero;

    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), R(16));

    R(3) += R(0);
    R(0) = R(3);
    R(2) = vf3_mem_u32(ram, MIRROR_MASK);
    R(0) |= R(2);
    target = R(0);

    if (!guest_call(s, ram, target, base | CONT)) return 0;

    zero = (R(0) == 0);
    set_t(s, zero);
    R(0) = zero ? 0u : 1u;

    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
```

The port keeps the guest's own stack traffic (it pushes pr and pops it again),
so the stack it leaves in RAM is the one the original left.

## 4. The proof

`tests/uncached_call_replay.c` is a differential test against the retained
generated translation, in three arms:

1. the generated chain - the reference;
2. the readable port, called directly;
3. the readable port, reached through the readable override (which is how the
   native tick reaches it).

The callee is not known at compile time, so the test answers it with a
**stub**: the stub leaves the answer the scenario picked in r0 and comes back
to the caller's return address.

All three compare the whole register file (the FP registers and SR included),
the exit PC, the failed PC, the out-of-window counter and every RAM byte.
Two more things are compared explicitly, because they are part of the
contract and the register file does not show them:

* **the continuation the callee was handed** - it carries the mirror the run
  came through, and the test compares it across the three arms;
* **the alias the caller left** - the callee is told which mirror it was
  jumped to.

The stack the fixture hands to the guest is filled with garbage, not zeroes,
so a store the port forgets shows up in the result.

Eight scenarios: the callee answers zero, one and a word; the entry point has
an offset; the base is already in the 0x8c mirror; and two runs that came
through a mirror the caller left behind (0xac and 0x8c).

```
$ build/vf3uncachedcall.exe
uncached_call: 8 differential cases - PASS
```

### The mutation list

`tests/uncached_call_mutations.json` holds 13 mutations, one at a time, and
`tools/mutate.py` requires the port's own test to fail for each:

```
$ python tools/mutate.py --port src/fight/uncached_call.c \
      --exe build/vf3uncachedcall.exe \
      --mutations tests/uncached_call_mutations.json --target vf3uncachedcall
```

They cover the mirror mask's pool entry, the mask not being applied, the
offset being added instead of subtracted (and not added at all), the answer
being inverted or always one, the T bit being inverted, the continuation
being the wrong address, the alias not being handed to the callee, the
alias not being read on entry, and the pr not being pushed or popped.

## 5. Where it stands in the ledger

The entry keeps its `docs/decomp_status.csv` row: the body is still
implemented by the generated module, and the row's evidence is the ROM
translation.  What the readable port adds is the *review* - the body is now
readable C that a human can check against the disassembly, and the
differential test proves the two agree.

`docs/readable_status.csv` carries the readable entries; this one is in it
with `verified=unexercised`, because the recorded states never call it - it
is in the low region, and `src/fight/call_targets.c` (the entries the
captured fight ticks call) does not name it.  `tools/readable_gap.py` ranks
the entries the recorded states *do* call and that are still served only by a
generated adapter; this body is not one of them.

## 6. The tools

| tool | what it does |
|---|---|
| `tools/adapter_body.py` | the whole generated source of a PC range (the dump alone walks the fall-through and hides a branch arm) |
| `tools/adapter_dump.py` | the generated translation as guest disassembly |
| `tools/mutate.py` | applies the mutation list one at a time and requires the test to fail |
