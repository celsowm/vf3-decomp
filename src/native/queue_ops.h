#ifndef VF3_NATIVE_QUEUE_OPS_H
#define VF3_NATIVE_QUEUE_OPS_H

/* Native ports of the fight engine's queue family (0x8C038570 reset,
 * 0x8C038590 push, 0x8C0385C0 pop). */
#include "aim_math.h"

/* 0x8C038570 - empty the queue and seed the struct from the arrays' first
 * slots. */
void vf3_native_queue_reset(vf3_native_aim *a);

/* 0x8C038590 - append the struct's two words at the counter's new value;
 * refuse (-1) once the queue is full. */
void vf3_native_queue_push(vf3_native_aim *a);

/* 0x8C0385C0 - take the arrays' last slots back into the struct and count down;
 * refuse (-1) once the queue is empty. */
void vf3_native_queue_pop(vf3_native_aim *a);

#endif /* VF3_NATIVE_QUEUE_OPS_H */
