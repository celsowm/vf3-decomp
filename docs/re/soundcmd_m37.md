# M37 — sound command layer catalog (2026-09-24)

Findings (true image, string cluster 0x8C0CD600..0x8C0CD9xx):

- Sound library identified: **Sega libsnd 0.82 (1999-04-20)**
  (`libsnd0.82-19990420` @0x8c0cd540), NAOMI LIBRARY Ver 0.8 strings
  (@0x8ccf64) nearby.
- Command endpoints (mpdrv family): `mpdrv_set_dreq_ns(%d)`,
  `mpdrv_set_dreset_ns(%d)` (dreset = voice-reset = M13/M26 kit write),
  `mpdrv_set_hreset_ns`, `mpdrv_set_ft4ctrl`, maple exdev exec cmd set
  (`exdev::execcmd is DevReq/DevKill`).
- String refs resolve into literal pools at 0x8C035EC8 .. 0x8C0367B0
  — the sound command bodies live in the 0x8C035Exx..0x8C0368xx block
  alongside the task-VM manager thunks (which is why M34's slot table
  singletons at 0x8C0CC9E8/0x8C0CC988 sit in the same data island).

Port: `src/sys/soundcmd.c` — command-framing model with
registry-resolved endpoints (0 = unattributed until the M36 trace
windows pin the fn borders; the borders are segmentation-dead-zone,
consistent with the taskvm cases).

## Open thread → M40+
- Attribute each mpdrv_* endpoint body (pool-user walk back from
  0x8C0361xx/62xx/63xx).
