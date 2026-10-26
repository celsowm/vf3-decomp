/* render/ta_stream.h - where the display list bursts land.
 *
 * The PVR2's Tile Accelerator reads its display list out of the PVR2's own
 * memory, not out of a stream: the game fills that memory through the SH-4's
 * store queue and then tells the TA which part of it to run.  The port keeps
 * that memory, so a burst that is written twice (the store queue still holds
 * the previous burst's words when the game starts the next list) lands the way
 * the hardware's would.
 */
#ifndef VF3_TA_STREAM_H
#define VF3_TA_STREAM_H

#include <stdint.h>

/* The TA's list area: 0x10000000 in the SH-4's address space. */
#define VF3_TA_AREA_BASE 0x10000000u
#define VF3_TA_AREA_SIZE 0x00800000u   /* 8 MB */

/* Where the last display-command burst went.  The port reads it right after
 * the flush hook returns, so the hook itself keeps its signature. */
extern uint32_t vf3_ta_flush_dest;

#endif
