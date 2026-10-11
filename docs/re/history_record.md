# Paired history recording (2026-10-11)

Callable `0x8c0a83c2`, frozen owner `0x8c0a83ce`, adds **96 verified
C bytes** through `src/fight/history_record.c`. The 12-byte prefix and
off-inventory packing helper `0x8c0a8458` receive no separate credit.

The callback checks the original pause flags, records both actors into
one 128-byte slot at `0x0c22f864`, and increments the descriptor's index
at offset 16, wrapping after 319. It copies flags, raw float positions,
signed words, metadata bytes and staged events into the original field
layout. Class-two records inspect the previous slot before choosing the
stored class. Event staging words are cleared after transfer. The two
global float markers retain the original primary-actor reads.

Development and independent holdout each pass **128/128** strict cases
with complete 96-byte owner execution, zero skips and no rejected
specimens. The unchanged executable and 387-file compiled source freeze
precede holdout. Typed RAM fixtures vary pause flags, index wraparound,
actor fields, classes and previous-slot state.

Eight original windows begin at `0x8c0a83ae`: load the untouched callback
pool at `0x0c0a843c`, install it at descriptor offset 12, recover the
descriptor argument and initializer's saved PR from the original stack,
then take the BRA at `0x8c0a83b6` into the recording callback. The proof
checks the caller's eight-byte stack retirement, callback installation,
nested saves, ordered restoration and actual caller return. Background
AICA events grant no device coverage.

The only affected binding is the new callback; its frozen initializer
parent `0x8c0a8370` is unbound. The affected binding, **39 native suites**,
and **242 tool tests** pass. Seven mutation tests reject forged callback,
tail, prefix, pool, stack/save and return evidence. Only the 39 required
native regression executables are archived.

The larger replay-playback pilot remains unqualified. Callable
`0x8c0a8ac0`, owner `0x8c0a8aca` (544 bytes), yielded only 16 valid
early-return specimens. Active paths entered SDK graphics code and
produced 27 exceptions, 14 budget limits and two interruptions; both
state runs ended with incomplete invocations. It grants **zero bytes**.
Its raw captures, batches, patches, debug logs and exclusion counts are
pinned by the recording milestone seal. A pointer at `0x8c09a59c`
identifies the playback entry; the apparent BSR at `0x8c0a99f4` is the
literal value `0x0c29b864`, not an established caller.

`tools/oracle/history_record_v1_manifest.json` seals qualified evidence,
the excluded playback pilot, and the prior history-scan proof chain.
Verified C is **266,644 / 434,656 (61.35%)**; **15,883 bytes remain to
65%**. The next full inventory gate remains required at 62.5%.
