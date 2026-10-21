# Original image-entry segments

`src/sys/boot_entry.c` implements two bounded original-code segments on the
caller's existing `vf3_matrix_state` and RAM. It does not create BIOS state,
load a savestate implicitly, call an emulator, or invoke the startup body.

| API | Original entry | Stops before executing |
|---|---|---|
| `vf3_boot_relocate` | image entry `0x0C010000` and RAM aliases | literal jump target `0xAC004000` |
| `vf3_boot_crt0` | CRT0 `0x0C020000` and RAM aliases | startup `0x0C09574E` |

The first segment loads its three original literals, copies words from
`0xAC010100..0xAC014000` to `0xAC004000..0xAC007F00`, and performs the original
jump. PR is untouched. Its exact instruction count is 24,198, including the
JMP delay-slot NOP.

CRT0 executes three descriptor-driven BSS clear loops, obtains SP and the
startup address from its own literal data, zeros r1–r14 and the active FR
bank, and performs the original JSR/delay-slot handoff. The actual captured
entry is the low alias `0x0C020000`, so PR becomes `0x0C02007C`. The port does
not replace this return address with a harness sentinel. FR/XF selection is
represented by the existing active-bank register layout; the inactive XF
bank, FPUL, GBR, MAC registers, banked GPRs, and other untouched state survive.

## Input contract and failure behavior

The supplied RAM map must contain every code, literal, source and destination
byte. The implementation verifies the original instruction words and the
fixed relocation pool. It reads CRT descriptors from RAM, validates nonzero
counts, alignment, bounds, stack and startup target, and rejects BSS ranges
that would overwrite the executing code or its descriptors. There is no
fallback to a binary on disk or zero-filled missing memory.

Unsupported FPU modes (SR.FD, FPSCR.PR or FPSCR.SZ) fail before CRT execution.
Privileged alias accesses require SR.MD. Each entire segment must fit the
provided host instruction budget. On rejection, both RAM and the complete
input context remain unchanged. On success the budget is decremented by the
exact retired-instruction count, `failed_pc` is cleared, and `pc` identifies
the handoff. `task_driver` ownership is not replaced or reconstructed.

These functions do not model caches, MMU translation or asynchronous
interrupt delivery. Callers must supply the correct architectural data view
and use them only at the established boundaries. They do not provide an
arbitrary-PC native continuation API.

## Fresh uninterrupted reference capture, 2026-10-21

The local observer run in `../vf3-oracle-new/captures/boot-handoffs-v1`
captured all four boundaries during one uninterrupted cold start of the
original disc. It records each boundary before its instruction executes.
The test context format is exactly 64 little-endian uint32 words: actual PC,
54 existing register words, GBR, then eight banked GPRs. Conversion provenance
is recorded in the capture manifest.

| Segment | Before / after stems | Observer instruction ordinals | Native instructions | Full comparison |
|---|---|---|---:|---|
| Relocation | `0000_entry_ac010000` / `0001_entry_ac004000` | 94,346,656 / 94,370,854 | 24,198 | 0 RAM bytes and 0/64 context words differ |
| CRT0 | `0002_entry_0c020000` / `0003_entry_0c09574e` | 96,574,135 / 97,856,493 | 1,282,358 | 0 RAM bytes and 0/64 context words differ |

All four captures have CCR=0 and MMUCR=0. The independently derived P1 RAM
views changed zero bytes and reported zero valid cache lines. Raw physical
RAM is therefore the correct data view for these specific comparisons;
this observation must not be generalized to later cached gameplay states.
VBR/SPC/SSR/SGR/DBR are unchanged within each reference pair and live outside
`vf3_matrix_state`; these segments do not access them.

The captured CRT BSS was already zero before clearing. The full-state reference
still validates the complete observed state transition; separate synthetic
boundary tests initialize BSS to nonzero bytes and check the exact written
ranges so that a missing clear cannot pass only because of this fixture.

Sealed capture manifest SHA-256 at verification:
`190260ab1498718c659c5339ec778e6d13b77aa86016102df0815e76e3424053`.
Derived-data manifest SHA-256:
`c168aa3d104bd8c0f392dccc1474b4722e9f22a36d335751b00c5b0339170c69`.

| Stem | Context SHA-256 | Raw RAM SHA-256 |
|---|---|---|
| `0000_entry_ac010000` | `b50c24e53d9450ee59b136226c8e30b1083f81dc19b34ac91267a1c042fbca92` | `127160bcd7218a00fa6529d604a18709a09e5d47190b2fc14ee48514c9fdd23f` |
| `0001_entry_ac004000` | `5c54437b929791b01085d982c47b5a19f920de7893779ced9e074af9b4bffd46` | `c958790bfdf1090703d92af3855d1c7f4f5280189d891c4af666f7f06556bffb` |
| `0002_entry_0c020000` | `3943be95b6fb2cdfa84f71871a9b7a62563bec4a36c2d5599ff23caf5ca5807f` | `0a6206b6e5ac40b547cb3e73d7ebe880c9a6e7efb00facddc540a9a4c0cceaec` |
| `0003_entry_0c09574e` | `e35ac1b07232581ddd101bbbbee2cc91c54d7108451d4d7b9e3a4a5595813a72` | `0a6206b6e5ac40b547cb3e73d7ebe880c9a6e7efb00facddc540a9a4c0cceaec` |

## Reproduction

The standalone test requires only `tests/boot_entry_test.c`,
`src/sys/boot_entry.c`, and the `src` include directory:

```sh
cc -std=c99 -Wall -Wextra -Werror -Isrc \
  tests/boot_entry_test.c src/sys/boot_entry.c -o build/vf3bootentry
build/vf3bootentry
```

The default ROM-free tests cover three PC aliases, dirty BSS, exact PR/SR and
untouched registers, full memory outside written ranges, wrong code/entry,
missing RAM, descriptor overflow/zero count, self-overwriting descriptors,
unsupported FPU/privilege state and insufficient execution budget. They also
pass under AddressSanitizer and UndefinedBehaviorSanitizer.

Reference mode takes explicit files and refuses absent/wrong-sized data:

```text
vf3bootentry --reference relocate|crt0 BEFORE.context.bin BEFORE.ram.bin AFTER.context.bin AFTER.ram.bin
```

It compares every byte of the 16 MiB RAM and every one of the 64 captured
context words. It never substitutes synthetic state for missing references.

## Remaining cold-start chain

The relocated Katana bootstrap between `0xAC004000` and `0x0C020000` and the
startup body beginning at `0x0C09574E` are separate implementation and
validation work. The two passing segments are not a claim of complete cold
boot, title flow, playable gameplay, or overall coverage percentage.

## Strict-cache reference recheck

The same two native segments also pass against the separate, complete
`boot-handoffs-strict-v3b` capture from the new reference built with upstream
`STRICT_MODE` and `TARGET_NO_REC`. Both full 16 MiB RAM comparisons and all
64 context words match exactly. Its observer ordinals are 289,120,446 /
289,144,644 for relocation and 291,347,925 / 292,630,283 for CRT0; the native
instruction counts therefore remain 24,198 and 1,282,358. All four boundaries
have CCR=0 and MMUCR=0. This recheck does not claim the later cached scheduler
or complete game loop is implemented.

Strict capture manifest SHA-256: `aa870f6a1533a06c3c74772dff9c9598c8db6fc9685f1455c86b25618002baad`.
