# Sound / BGM subsystem (2026-09-19, static pass; M13 evidence 2026-09-22)

## 2026-10-09 corrections from aligned runtime evidence

The historical observations below retain their original dates; their driver,
bank-boundary and reset interpretations are superseded by the following:

- The resident ARM driver is `SNDDRV.BIN`, not `RELOAD.BIN`. All eight retained
  state26/state28 checkpoints match its complete `0x0510..0x9fff` code range.
  `RELOAD.BIN` starts with SH-4 code. The identity ledger is
  `extract/analysis/audio_snddrv_identity_v1.json`.
- Whole-package equality places `BGM_VAN.BIN` at AICA `0x086e50`, length
  1,014,948 bytes. `0x086e54` was the first changed byte in older captures;
  it does not establish an allocation boundary or a reset contract.
- Read-only ARM observation passed paired fresh-process equivalence in states
  26 and 28, with 44,380 and 85,342 retained events and no truncation. Event
  ordering and guest PC are exact; timestamps identify the enclosing SH-4
  scheduler callback and do not resolve individual ARM cycles.
- State26 contains nine nonzero A0 queue handoffs: two reads at ARM `0x668`
  and `0x674`, clearing at `0x688`, byte reversal through `0x48..0x4f`, then
  publication at `0x245c` into the internal `0xa400` ring. The consumer ORs
  bit 6 into the reversed A0 word. This does not identify a voice-reset API.
- State28 contains 277 hardware voice-register writes and no nonzero external
  queue consumption in this bounded observation. Thirteen enabled voices in
  a retained longer state26 checkpoint point inside the proved BGM_VAN bank.
  Register key requests alone are not proof that a voice is enabled.
- The historical `0x00a0b4..0x00cf5d` change window overlaps the ARM stack
  (initial SP `0x00a100`), driver context at `0x00a200`, the proved command
  ring `0x00a400..0x00a7ff`, and sixteen 48-byte software work records at
  `0x00cc50..0x00cf4f`. Calling the entire window a PCM streaming ring is
  unsupported. The literal/record-layout derivation is retained in
  `extract/analysis/audio_arm_workspace_v1.json`; runtime command-ring stores
  are proved separately. Sample streaming and wrap behavior remain open.

The accepted observer manifest is
`tools/oracle/audio_arm_observer_v2_manifest.json`. A separately bounded C
handoff model in `src/media/driver_queue.c` reproduces all nine ordered store
sequences; it does not replace ARM execution, interrupt timing or DSP. The
observer's state28 PCM exports contain 14,446 exact stereo frames (about
0.328 seconds); WAV round-trip preserves all samples. A full menu/fight/second
song comparison and a manual listening check remain required.

## M13 voice-reset boundary LOCATED (extract/analysis/shots/aica_load_*)
- Full song-kit write: one contiguous block `0x086E54 .. 0x1CC29D`
  (1,222,259 B) replacing attract/menu kit with the fight kit (AICAF 24200 ->
  25400 in f2f2 ladder; menu->load swap is instead a full-RAM 301 KB exchange).
- Driver + voices baseline `0x0 .. 0x86E53` survive ALL transitions (driver
  code, voice headers, FX tables).
- Steady-state: streaming window `0x00A0B4 .. 0x00CF5D` (~12 KB ring),
  controls at `0x44..0xF8`; cadence ~10 B/1200f = sample-position updates.
- Interpretation: `drv_set_dreset_ns(%d)` corresponds to the kit write;
  BGM_<stage>.BIN lands in the kit region (why static ROM xrefs found nothing).

## M17 (2026-09-22): AICA region census
Derived from the aica_load_* ladder (extract/analysis/shots/) — 32 consecutive
2 MB wave-RAM dumps covering menu → load → fight:

| AICA range | role | delta behaviour across transitions |
|---|---|---|
| 0x000000–0x000043 | idle/reset pad | untouched |
| 0x000044–0x0000F8 | control/status words | 20-byte bursts, only window whose deltas precede every scene step |
| 0x00A0B4–0x00CF5D | streaming ring (~12 KB) | continuously rewritten; cadence ~10–300 B per 600 frame window (sample position updates) |
| 0x00CF5E–0x086E53 | **driver + voice headers** | byte-identical across menu/load/fight (M13 vf3_7 fight-live probe confirmed code layout) |
| 0x086E54–0x1FFFFF | **song kit / sample bank** | single contiguous write during a scene swap (largest: 1.22 MB fight kit at 0x086E54..0x1CC29D) |

So the ARM7/ARM7-side driver model is: code+voices anchored at the bottom of
wave RAM; song kits appended after 0x86E54; `drv_set_dreset_ns`-style resets
simply overwrite the suffix region. RELOAD.unsc.bin (ARM7 driver) contains no
recoverable ASCII surface (compressed section); voice-slot mapping work
continues from the SH4 side strings + these ranges instead of reading it.


## String-heap inventory (1ST_READ.unsc.bin)

26 `BGM_<stage>.BIN` names, e.g. AKI AOI CONT DEBU DOHY DURA ENDI FIGH FUNK
ITO ITO4 ITO6 JEFF KAGE LAU LEON NAME PAI SARA SHOT SHUN SONG STAR TAKA VAN
WOLF — one per stage/character select context, contiguous-ish in rodata
clusters (0x8c03f6xx, 0x8c0435xx, 0x8c050bxx, 0x8c06b8xx, 0x8c07c844,
0x8c0869xx, 0x8c08xxxx). Adjacent string variants ("efc_035", "c_034",
"_udo_pai_yubi_l") indicate the same compiled-in string heap as known
sound.c zone strings.

Driver debug strings (from `sound.c` build, shipped with printf refs):
- `drv_set_dreset_ns(%d)` — the voice-reset call (a "dreset" = voice reset)
- `drv_set_dkill_ns(bi_r_4_t...)` — voice kill
- `drv_setcmd(%d,%02x)`, `drv_mac`, `drv:%d`, `drv=%d,blk=%04X,adr=%0lX`,
  `drv_frame_recv_pre()`, `drv_make_exdev`

## Voice-reset boundaries (question → finding)

The frontier item "BGM song-kit voice reset boundaries" maps to the drv_*
sound driver API: `drv_set_dreset_ns(%d)` is the voice-reset entry (the
`%d` = voice id; kit = the per-BGM DTPK voice set). BUT the pointers to
these strings do NOT appear as literal-pool dwords in the binary (checked:
zero dword refs over the whole image) — the sound.c build uses
mova/base+offset addressing against its own string clusters, so static
attribution of the reset boundaries is NOT reachable from byte patterns
alone. Unknown whether the strings are even reachable from shipped entry
points (possible dead debug strings).

Resume recipe (needs new trace class): capture a G2/AICA access trace —
filter RAM-access records touching 0xA0080000..+0x80000 (AICA wave RAM) or
the mailbox regs — around a song change (fight_1 fight_2 reset), and
attribute the reset loop entry to its host fn. The RELOAD.unsc.bin (ARM7
driver) governs the ARM-side interpretation; SH4 side issues commands via
the mailbox protocol in/out.

## M57 — attribution gate pinned (2026-09-28, static; negative results)
- Exhaustive `mova @(disp,PC)` scan over the image: **0** mova targets land
  in the mpdrv string block `0x8C0CD600..0x8C0CDA00` — strings are reached
  only via base+offset dataflow (M56 mova hypothesis confirmed, tightened).
- Sound block `0x8C035E00..0x8C036900` = 15 fns, **14 with 0 execution hits**
  (campaign C dyn-dispatch; 4 already `accounted`); the mpdrv endpoints never
  fire in any captured scenario.
- Sound-block literal pools pointing at G2/AICA space: exactly **1**
  (`0x8C036048 → 0xA062E907`, implausible reg — data constant). Command posts
  go through the libsnd driver layer, not direct pool loads.
- ⇒ voice-reset boundary stays trace-gated: needs (a) a song-change scenario
  (fight_1→fight_2; no in-tree play input drives it), (b) a new AICA-bus
  trace class in the fork (mem-watch wraps SH-4 ReadMem/WriteMem only; no
  G2/0xA0080000 support). `src/sys/soundcmd.c` endpoints remain 0 =
  unattributed by design until then.

## MT live-residency proof (side catch)

`MTJACLAU.BIN` (Jacky vs Lau) byte-verified resident at RAM offset
0x5F4100 during fight (ram_r15 snapshot) = mem 0x8C5F4100. Current-fight
pairing matches fight_scene.md ground truth (MTJACKAG/BGM_JACK/AU.AKIRA
artifacts are separate loads; JACLAU is the active motion pack).
