/* vf3dump.h - the reference emulator's state dumper and hits probe.
 *
 * Ours; see vf3dump.c and docs/re/patches/reference_frame_dump.md for the
 * two one-line hooks a Flycast checkout needs.
 */
#pragma once
#include "types.h"

void vf3DumpInit();
void vf3DumpCheck(u32 pc);
