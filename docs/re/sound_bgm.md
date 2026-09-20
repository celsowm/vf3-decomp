# Sound / BGM subsystem (2026-09-19, static pass)

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

## MT live-residency proof (side catch)

`MTJACLAU.BIN` (Jacky vs Lau) byte-verified resident at RAM offset
0x5F4100 during fight (ram_r15 snapshot) = mem 0x8C5F4100. Current-fight
pairing matches fight_scene.md ground truth (MTJACKAG/BGM_JACK/AU.AKIRA
artifacts are separate loads; JACLAU is the active motion pack).
