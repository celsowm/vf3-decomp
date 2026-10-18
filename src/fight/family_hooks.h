/* family_hooks.h - verification hooks of the vf3_matrix_family dispatcher.
 * Kept out of matrix_family.h so touching the hooks does not rebuild the
 * 1.8M-line generated adapter set.
 *
 * override: consulted first; readable C replacements register here by entry.
 * missing:  consulted when no ported code owns the entry (the generated
 *           adapter failed at the entry itself); tests replay an
 *           oracle-recorded call effect there so the surrounding ported code
 *           can still be verified. Both stay NULL in a shipping build. */
#ifndef VF3_FAMILY_HOOKS_H
#define VF3_FAMILY_HOOKS_H
#include "fight/matrix_family.h"
typedef int (*vf3_family_hook_fn)(uint32_t entry, vf3_matrix_state *, const vf3_ram_map *, int *handled);
/* fail: observer called on every failed return (diagnostics only). */
extern vf3_family_hook_fn vf3_family_override, vf3_family_missing, vf3_family_fail;
/* enter/leave: observers bracketing every dispatch (audit of each native call
 * against the oracle record); leave's `ok` is the dispatch result. */
typedef void (*vf3_family_obs_fn)(uint32_t entry, vf3_matrix_state *, const vf3_ram_map *, int ok);
extern vf3_family_obs_fn vf3_family_enter, vf3_family_leave;
/* nonzero: vf3_matrix_family keeps dispatching until pc reaches the caller's pr */
extern int vf3_family_complete_calls;
extern uint32_t vf3_family_extra_stop;
extern int vf3_family_tail_retry;
/* Store-queue bursts (PREF @Rn with Rn in 0xE0000000..0xE3FFFFFF). The replay corpora under
 * extract/analysis predate the burst model and their device tapes do not contain the burst
 * writes, so the model is opt-in: whole-tick runs set it, the legacy per-function gates do not. */
extern int vf3_sq_model;
/* Store-queue burst of PREF @Rn; the caller checks Rn is in 0xE0000000..0xE3FFFFFF. */
void vf3_matrix_pref(const vf3_ram_map *ram, uint32_t addr);
/* optional filter for the above: returns nonzero when `entry` is a call target (jsr/bsr/jmp-tail
 * destination), zero for a fragment seed inside a function. NULL: every entry is a call target. */
extern int (*vf3_family_call_entry)(uint32_t entry);
#endif
