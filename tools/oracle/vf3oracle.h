#pragma once
struct Sh4Context;
/* Load large fixture plans while guest execution is stopped, before frames. */
void vf3OraclePrepare(void);
void vf3OracleBefore(unsigned pc, unsigned short op, const Sh4Context *ctx);
void vf3OracleInvalidate(unsigned reason);
/* True when a synthetic-entry probe was active and has just been rolled back
 * because it faulted. The caller must then drop the exception instead of
 * dispatching it: the probe's own fault would otherwise fault again inside the
 * handler and kill the emulator run. */
bool vf3OracleAbortProbe(void);
/* True right after the oracle rolled back a probe whose current instruction
 * belongs to the probe (fault or budget abort). The interpreter must then discard
 * the opcode it already fetched and re-fetch at the restored PC, otherwise a
 * branch inside the aborted probe overrides the resume point and the run dies. */
bool vf3OracleTakeSkip(void);
/* True when a synthetic probe redirected at this instruction. The interpreter
 * must then execute the target's first opcode *instead of* the trigger's: a
 * plain PC redirect still lets ExecuteOpcode run the trigger (a `jsr` would
 * rewrite pr from the redirected PC and leave the caller with a broken return
 * chain). Returns the substitute PC and opcode through the out parameters. */
bool vf3OracleTakeSubstitute(unsigned *pc, unsigned short *op);
