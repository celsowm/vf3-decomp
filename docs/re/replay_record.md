# Replay record restoration (2026-10-11)

Callable `0x8c0a9036`, frozen owner `0x8c0a9040`, adds **348 verified
C bytes** through `src/fight/replay_record.c`. Its ten-byte save prefix
and existing interpolation/motion helpers receive no additional credit.

The routine restores packed actor flags, float position bits, signed
words and metadata. Scene flags and the odd-frame timer select the
original interpolation helper. Character eight restores its extra byte.
Both recorded events pass through the existing sound submission routine;
typed fixtures route its command queue into owned RAM. Motion changes,
initial frames, subsequent frames and pose updates use the actual
existing helpers. Original stack temporaries and integer/float scratch
results are retained; pose helpers also change the original scratch XF
bank, which strict replay compares rather than treating as preserved.
This proves RAM behavior, without granting live audio-device coverage.

Final development `coverage_65_replay_record_dev_v3` runs states 26/27
for 600 frames each: 64/64 and 53/53 invocations complete, **108 valid
strict cases** pass, and nine interrupted specimens are excluded.
Independent holdout `coverage_65_replay_record_accept_v3` runs states
28/29: 64/64 invocations complete per state, **116 valid strict cases**
pass, and twelve interrupted specimens are excluded. Both campaigns
execute every byte of the 348-byte frozen owner. There are no incomplete
invocations, nondeterministic retained entries or native replay skips.
Holdout follows the unchanged executable and 388-file compiled source
freeze. Owned descriptors and queues relocate by `0x100000`; the actor
and its loaded motion context remain at their observed addresses.

Eight original windows start at untouched BSR sites `0x8c0a8e64` and
`0x8c0a8e6e`, with the original MOV R13,R4 delay. Typed holdout indices
5/6/7/8 select short zero-motion paths so all eight return without an
interrupt or device access. The validator checks exact branch targets,
ordered saves/restores, scene-context literal bytes, saved PR/stack,
architecture preservation and actual return. These prove the image's
call edges; they are process-owned fixtures rather than natural playback.
Seven mutation tests reject forged call, prefix, pool, stack and return
proofs.

Earlier development pilots remain excluded: v1 has 45 valid cases,
80 non-RAM rejections and three interruptions; v2 has 61 valid cases,
62 non-RAM rejections and five interruptions. Their valid subsets
matched C but missed owner instructions. The first caller pilot also
remains excluded after four state-28 interruptions. Its four valid
state-29 windows receive no separate qualification. All pilot raw
capsules, reports and provenance remain pinned by the seal.

The affected gate passes the two observed/static affected bindings
(new reader and target configuration), plus 48 legacy bindings included
conservatively because they lack opcode ledgers. All **50 bindings**,
**39 native suites** and **249 tool tests** pass. Only the 39 required
native regression executables are archived. Both target-configuration
calls and both replay-callback calls are included in selection.

`tools/oracle/replay_record_v1_manifest.json` seals the frozen source,
final campaigns, original callers, exclusions, strict regression and
prior history-record proof chain. Verified C is **266,992 / 434,656
(61.43%)**; **15,535 bytes remain to 65%**. The full binding gates at
62.5% and 65% remain required.
