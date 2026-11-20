# native_pack_expand (0x8C09D5AE)

The fight engine's packed-attribute expansion, ported natively in
`src/native/pack_expand.c` (`vf3_native_pack_expand`) as a plain-C transcription
of the readable port `src/fight/pack_expand.c` (`vf3_pack_expand_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU - and it carries the guest's stack contract (a dead push/pop
round trip plus a two-word push) that the flat-RAM API has to reproduce
exactly.  Its pool reads are all **sign-extended halfwords**, which stress the
`vf3_aim_h16` helper.

## The body

The function takes one record and expands the **sixteen packed bytes** the
record's table entry points at into **sixteen groups of four two-bit fields**,
written to a destination the record carries.  The literal pool holds three
entries read at run time: the address of a pointer to the table (`0x0c09d6dc`),
and the record's two offsets (`0x0c09d6ce` for the packed byte, `0x0c09d6d0`
for the destination).  The record's halfword at +60 names the table entry
(from one); each twelve-byte entry carries three offsets from the table's base
(the packed bytes, and two places the record remembers).  The destination's
first word is the source's head plus seventeen, and its other two words are the
remembered places.

Two details the port keeps: the guest pushes the record on its stack and pops
it again without using it (the stack pointer's round trip is visible), and the
record's packed byte moves up by 29 while the record's own byte takes bit 14 of
the source's head.  The loop ends with the counter at 16, so the T bit the port
leaves is **set**.

## Evidence

The **differential** (`tests/pack_expand_native_replay.c`, target
`vf3nativepackexpand`) runs the native port against the readable guest port from
the same seed over the same six scenarios as the readable test: the corpus'
offsets, a middle entry, a high entry with bit 14 of the head set, every field
set, a head with only bit 14 set, and **negative offsets out of the pool** (the
`0x8000`/`0x9000` halfwords, which as sign-extended offsets place the record's
fields *below* it - the fixture applies them in signed arithmetic and its
window reaches below the record).  The whole region spanned by one flat buffer
is compared byte for byte, the output registers (`r0..r7`), the T bit and r15,
and the outcome (the record's two bytes, the destination's three words, the
sixteen groups and the two pushed stack words) against the fixture itself.
**6/6 PASS.**

The **mutation gate** (`tests/pack_expand_native_mutations.json`) applies
forty-four mutations mapped onto the native lines: the three pool entries
swapped or misread, the entry/record/halfword layouts wrong, the index not
counted from one, the three offsets not from the table's base, the head's shift
and mask wrong, the packed byte's step wrong, the group origin/size/count wrong,
the source head step wrong, the four two-bit fields each pulled from the wrong
bits, the source read one byte off, the record's two bytes not written, the
packed byte read one off, the two offsets **not sign-extended**, the destination
pointer read one word off, the dead push not popped / the two words not pushed /
pushed in the wrong order / the stack not popped, the T bit not set, the
destination's words swapped, the limit / source pointer / last-group address /
stride / round counter / destination registers wrong, and the last byte and
packed byte not left in r0/r6.  The differential catches **all 44**.

```
build\vf3nativepackexpand.exe ->
  pack_expand_native_replay: PASS
python tools/mutate.py --port src/native/pack_expand.c --exe build/vf3nativepackexpand.exe \
    --mutations tests/pack_expand_native_mutations.json --target vf3nativepackexpand \
    --keep-going
  44/44 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable authority
(which replays its 8-case oracle corpus).

## Notes

* The source file must use **LF** line endings: the five multi-line mutation
  subs write `\n`-joined text, and on a CRLF file the `old` text never matches
  (the first version of the gate only caught 39/44, missing exactly those
  five).
* The flat buffer base must equal the pool's base (0x0c09d000), and the record
  window must reach below the record so the negative-offset scenario's fields
  land inside it.
