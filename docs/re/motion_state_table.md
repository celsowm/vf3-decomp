# Actor-byte-indexed motion ID lookup

At `0x8C0A93F8`, the game loads the pointer table at `0x0C102E34`. The preceding
call at `0x0C0C9CE6` advances a global linear-congruential random seed and
returns a nonnegative value. The following call at `0x0C042D7C` computes that
value modulo 6. Its result selects pointer-table rows 0 through 5. The selected
pointer addresses a packed `u16` map; the byte at actor offset `+0x61` indexes
that map, and the resulting halfword is written to actor offset `+0x3C`.

Other readable code treats actor `+0x61` as a fighter-kind field
(`src/fight/facing_update.c`, `src/fight/state_ladder.c`). This lookup therefore
selects a raw motion ID by random row and fighter kind. It is not an
action-state-to-motion lookup. The seventh pointer is present in the table, but
this call site does not select it.

The readable view of this structure is available with
`tools/sh4_pointer_map.py`:

```text
python tools/sh4_pointer_map.py extract/exe/1ST_READ.unsc.bin --base 0x0c010000 --table 0x0c102e34 --count 7 --end 0x0c102e34
```

The seven map targets are consecutive from `0x0C102D7C` through `0x0C102E18`.
The first six contain 13 halfwords each; the last contains 14 and ends at the
pointer table. These bounds come from the target addresses and disassembled
access width. For a subset, `--selector N` shows one map and `--index N` shows
one map element.

This establishes a random-row → fighter-kind → raw motion-ID path in the retail
code. It does not identify the random selection's gameplay purpose or map a
motion ID to an action clip and extracted MT row. Those links still need
independent evidence before runtime animation can use the table. `0x8C0A9466`
contains a separate path through a direct table at `0x0C102E50`; it should be
analyzed independently.

## Separate direct-table branch at `0x8C0A9466`

The direct-table path is gated by the signed byte at `0x0C29BCDC` being `2`.
When that predicate is true, the function reads the actor's byte at `+0x61`,
uses it as an index into 32-bit values at `0x0C102E50`, and stores the selected
value into actor `+0x3C`. It also sets the actor's frame halfword at `+0x3E` to
`1` and initializes several descriptor fields before calling the normal
motion-frame path. This is a distinct selector from the random-row table above.

The first 13 dwords at `0x0C102E50` are:

| actor `+0x61` | motion ID |
| ---: | ---: |
| 0 | `0x61D` |
| 1 | `0x622` |
| 2 | `0x64B` |
| 3 | `0x297` |
| 4 | `0x66F` |
| 5 | `0x689` |
| 6 | `0x67C` |
| 7 | `0x690` |
| 8 | `0x29B` |
| 9 | `0x61D` |
| 10 | `0x69C` |
| 11 | `0x53B` |
| 12 | `0x53F` |

I checked the lookup index, gate, and actor motion fields in the retained fight
savestates 26–29 and 45–46. The direct-table gate is `0` in all six states.
The actors' `+0x61` values are `(0,7)`, `(4,7)`, `(4,2)`, `(11,3)`, `(4,2)`,
and `(11,3)` respectively; their current `+0x3C` motion IDs are not the
corresponding direct-table values. This path therefore does not identify the
natural fight actions or provide a safe runtime action-to-motion mapping.
The distinction between actor bytes `+0x60` and `+0x61` matters: the former is
read by the style-specific model selector, while both motion lookup paths use
`+0x61`.

Reproduce the byte comparison without extracting or modifying the savestates:

```powershell
python tools/flycast_state_profile.py `
  tools/emu/flycast-build/data/vf3_26.state `
  tools/emu/flycast-build/data/vf3_27.state `
  tools/emu/flycast-build/data/vf3_28.state `
  tools/emu/flycast-build/data/vf3_29.state `
  tools/emu/flycast-build/data/vf3_45.state `
  tools/emu/flycast-build/data/vf3_46.state `
  --image extract/exe/1ST_READ.unsc.bin `
  --read 0x0c1fefe4+0x61:1 --read 0x0c20138c+0x61:1 `
  --read 0x0c29bcdc:1 --read 0x0c1fefe4+0x3c:2 `
  --read 0x0c20138c+0x3c:2 --summary
```
