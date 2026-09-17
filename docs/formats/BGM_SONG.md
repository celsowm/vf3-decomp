# BGM_* DTPK kits (sequenced music)

BGM packs differ from VO packs: they contain a **sequenced song** —
samples + note event streams — not a continuous mono ADPCM track.

Sections (typical): sec0 bank header, sec1 variable seq-cfg, sec2 global
constant envelope table (132B, same as VO), **sec3 = event/byte stream**
(runs 0x80-0xFF command bytes + param u16s; per-track offsets visible),
sec4 **3112B melodic envelope table**, sec5 = ADPCM sample bank.

Decoding path (deferred): interpret sec3 via AICA key-on semantics,
point at sec5 sub-offsets via per-voice headers in sec0.

Today: mono-sliced decode of sec5 yields ~40% clipped-concentrated layouts —
the waveform envelope ramp kernel is audibly there but voices overlap.
Track-structural work is a future milestone once the sequencer
ISA is mapped from the driver code.
