/* sys/mainloop.h — per-frame task dispatch facts (M25)
 *
 * True-image verified, f_8c034852 (frame step) + entry-chain constants.
 * All in-struct pointers are guest (DC, 32-bit) addresses; the host maps
 * them through a bound arena (vf3_sys_bind_ram) and resolves code pointers
 * through the host registry (vf3_sys_register).
 */
#ifndef VF3_MAINLOOP_H
#define VF3_MAINLOOP_H

#include <stdint.h>

#define VF3_ADDR_IMAGE_ENTRY   0x8C010000u   /* reloc copy loop  */
#define VF3_ADDR_CRT0          0x8C020000u   /* BSS clears, CRT  */
#define VF3_ADDR_STARTUP       0x8C09574Eu   /* main module init */
#define VF3_ROOT_PTR_ADDR      0x8C0EA2ECu   /* global: &root_obj */

typedef uint32_t gaddr;         /* guest (DC) address */

/* guest RAM access layer */
void     vf3_sys_bind_ram(void *host_base, gaddr guest_base);
uint32_t vf3_sys_rd32(gaddr a);
uint16_t vf3_sys_rd16(gaddr a);
void     vf3_sys_wr32(gaddr a, uint32_t v);
void     vf3_sys_wr16(gaddr a, uint16_t v);

/* host registry: guest function address -> host implementation */
void     vf3_sys_register(gaddr ga, void *hostfn);
void    *vf3_sys_lookup(gaddr ga);

/* Node offsets used by the dispatcher (exact) */
#define N_ACCUM20     0x14   /* accum += step when finishing state 1/4  */
#define N_BASE18      0x18   /* frame[0] write / saved base             */
#define N_STEP1C      0x1C
#define N_F20         0x20
#define N_CBPROGRESS  0x24   /* jsr @(24,node) (state 1 branch)         */
#define N_CBPHASE     0x34   /* jsr @(34,node) (result 4/5/6)           */
#define N_PAYLOAD     0x3C   /* handler arg (r4)                        */
#define N_CBARG       0x40   /* frame[1] write (result 4/5/6); cb arg   */
#define N_W68_STATE   0x44   /* state word: 1/4/6 handled               */
#define N_W70         0x46
#define N_W76_RESULT  0x4C
#define N_W78         0x4E

/* root object offsets */
#define R_VTBLA       0x14   /* -> sub-struct, handler at sub+0x10      */
#define R_API         0x20   /* -> api struct, exit handler at +0x24    */
#define R_MARKER      0x24   /* frame marker 1 during dispatch          */
#define R_CHAIN       0x28   /* chain head node                         */
#define R_F40         0x28   /* (same cell — consumed on dispatch)      */

typedef uint32_t (*VF3NodeHandler)(uint32_t payload, gaddr frame);

/* Per-frame dispatch step (f_8c034852). frame = guest addr of a 2-word
 * scratch frame block.  Returns the handler's result code (r0), -9 when
 * no root object is bound. */
int vf3_frame_dispatch(gaddr root_obj, gaddr frame);

#endif
