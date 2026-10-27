/* vf3dump.h - the reference emulator's state dumper and hits probe.
 *
 * Ours; see vf3dump.c and docs/re/patches/reference_frame_dump.md for the
 * two one-line hooks a Flycast checkout needs.
 */
#pragma once
#include "types.h"

void vf3DumpInit();
void vf3DumpCheck(u32 pc);

/* The Tile Accelerator's input: the 32-byte blocks the hardware receives, in
 * the order it receives them.  The hook sits in the emulator's TA parse path
 * (core/hw/pvr/ta.cpp). */
void vf3DumpTaBlock(const void *block32);

/* The PVR2's own state: the register file (the frame buffer's configuration)
 * and the VRAM (the textures).  The emulator is the only place they exist,
 * and the port starts from a state the emulator dumped. */
void vf3DumpPvrState(const char *path);
/* The same, once, when the emulator has loaded a state. */
void vf3DumpPvrStateOnce();
