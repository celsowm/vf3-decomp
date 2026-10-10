# Fight audio caller execution plan

Prepared after milestone `22f9bfd`. Baseline readable coverage is
258,502 / 434,656 bytes (59.47%). The first target is callable `0x8c099060`,
with frozen owner `0x8c099070`, 232 bytes. Earlier captures reached only
66/232 bytes with 106 inputs; they supply no complete-body promotion proof.

1. **Recover the complete call contract.** Confirm the prefix saves r14/r13
   and reads scene flags at +0x138. Map input-mode selection, the signed
   +0x3e2 counter and its threshold at 16, +12 scene early exit, floating-point
   copies, actor choice, style normalization around 13, and final scene writes.
   Record literal pools and actual callers separately from Ghidra fragments.
2. **Resolve the tail before implementing the caller.** The body invokes
   physical `0x0c0968f8`, the general request wrapper with `0x000300a0`, and
   both actor style helpers. It then tail-jumps to `0x0c097ff4`. That tail
   either returns or updates scene fields and jumps to `0x0c0968d0`, which
   dispatches through the immutable table at `0x0c10baa8`. Recover the real
   target selected by the tail's index 10, its dependencies and complete return
   behavior. Compare existing generated paths as leads, then validate against
   the retail image and observed original executions. Keep callbacks real;
   do not replace an unresolved target with a no-op or patch the ROM table.
3. **Capture original development cases.** Use process-level one-shot audio
   capture and owned writable actor/scene inputs. Start with small pilots of
   the early-return, normal audio and callback-tail paths. Expand to at least
   64 distinct complete inputs across two active scenarios, provisionally
   states 26/27. Vary mode 1/3/other, input mask 0x800, counter boundaries,
   actor selection, flag 4 override, style boundaries, queue busy state and tail
   scene flags. Preserve loaded immutable assets and record callback PCs.
   Require union execution of all 232 frozen bytes; reject incomplete probes.
4. **Implement readable clocked C.** Add the caller and separately understood
   tail helpers, reuse the verified request/style/encoder implementations,
   preserve signed loads, exact float bit copies, delay-slot ordering, aliases,
   register saves and tail return PCs. Verify native replay first, then add the
   caller to the live bridge. Freeze executable and source artifacts before
   acceptance. No behavior derived by executing original SH-4 opcodes in C.
5. **Run independent acceptance.** Use at least 64 distinct changed inputs
   across two other active scenarios, provisionally states 28/29, with relocated
   stack and owned actor objects. Require complete invocation agreement in
   native replay and strict live original/C comparisons, zero skips, complete
   frozen-body coverage in both corpora, and real AICA crossings. Compare
   registers, touched RAM, ordered device accesses, ARM/DSP/checkpoint state
   and PCM. Preserve failed cases and use a corruption control to establish
   mismatch detection for the newly accepted path.
6. **Promote and seal only proved work.** Validate the unchanged callable and
   frozen-owner attribution requirements, including real caller evidence.
   Compute the marginal frozen-body union; do not count reused helpers or
   duplicate body bytes. The owner's 232 bytes alone would add at most
   0.0534 percentage points, reaching about 59.53%, if all promotion gates
   pass. Record any separately accepted callback owners independently.
   Run focused audio regression, relevant native/tool suites and the full
   milestone hash audit; document retained failures, commit and push.

If the real callback prevents complete capture or fails independent recovery,
keep the result an explicitly uncredited pilot and report the exact unresolved
target and observed failure. Do not report the audio caller complete based on
the branch that avoids its callback. Song/reset attribution and standalone
ARM/DSP playback remain subsequent milestones.

## Execution outcome (2026-10-09)

The caller, real callback 10 and its rendering/registration dependencies are
implemented. Development and held-out acceptance each pass 64 strict live and
native cases with complete 232-byte body execution and zero skips; the corruption
control detects the changed C queue word. Focused regression, 39 native suites,
86 tool checks and the milestone hash chain pass. Promotion stays uncredited:
the existing validator requires two direct BSR callers and a single register
save prefix, while this entry has a table-dispatch slot and two saves. No gate
was relaxed. Full evidence and remaining scope are in
[audio_fight_caller.md](audio_fight_caller.md).
