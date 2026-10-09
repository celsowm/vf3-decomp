/* Research observer only. PC is assigned by the x64 ARM compiler before
 * each memory instruction, including interpreter fallback instructions. */
#pragma once
extern unsigned vf3ArmTracePc;
void vf3ArmTraceMemory(unsigned addr, unsigned data, unsigned size, bool store);
