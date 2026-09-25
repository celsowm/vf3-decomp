/* sys/soundcmd.c — libsnd 0.82 "mpdrv" command layer model (M37).
 *
 * Static evidence (true image):
 *   string cluster 0x8C0CD600..0x8C0CD9xx = mpdrv_* debug prints
 *   ("mpdrv_set_dreq_ns(%d)" @0x8c0cd874, "mpdrv_set_dreset_ns(%d)"
 *    @0x8c0cd8a8, "mpdrv_set_hreset_ns(%d)", "mpdrv_set_ft4ctrl(%d,%08x)",
 *    "libsnd0.82-19990420" @0x8c0cd540)
 *   pools referencing the cluster: 0x8C035EC8, 0x8C03619C..0x8C0367B0
 *   (the command endpoints live in the 0x8C035Exx..0x8C0368xx block —
 *    adjacent to the task-VM helpers; both are manager-style services).
 *
 * Runtime evidence: M26 (docs/re/sound_bgm_m26.md) kit writes land as
 * bulk suffix overwrites at AICA 0x086E54.. with a steady 12 KB streaming
 * ring at 0x00A0B4..0x00CF5D; the corresponding SH4-side issuance of
 * dreset/dreq commands is what these calls encode.
 *
 * The mailbox bytes themselves travel GD/G2 -> ARM7 RELOAD driver; the
 * exact body semantics of each endpoint are trace-open-thread. This file
 * ports the *command framing* model so callers in the engine can issue
 * well-formed requests; bodies resolved by name lookup in trace windows.
 */
#include <stdint.h>

#include "mainloop.h"   /* vf3_sys_lookup */

/* mpdrv command opcodes as ordered by the string cluster and slot tables */
enum {
    VF3_SND_DREQ,          /* dma request  */
    VF3_SND_DRESET,        /* voice reset  */
    VF3_SND_HRESET,        /* hard reset   */
    VF3_SND_FT4CTRL,       /* filter/FXT4  */
    VF3_SND_EXDEV_CMD,
};

/* Issue a dreset (voice reset) for slot v through the driver endpoint —
 * resolves the endpoint once from the host registry; returns endpoint
 * result or -1 when unresolved. */
int vf3_snd_dreset_ns(uint32_t voice_id);

/* Registry guest addresses for the endpoints. 0 == not yet attributed:
 * bodies are named by string refs but the fn borders sit in the
 * segmentation dead-zone; resolution comes from M36 trace windows. */
#define VF3_SND_EP_DREQ     0u
#define VF3_SND_EP_DRESET   0u
#define VF3_SND_EP_HRESET   0u
#define VF3_SND_EP_FT4CTRL  0u

int vf3_snd_dreset_ns(uint32_t voice_id)
{
    int (*ep)(uint32_t) =
        (int (*)(uint32_t))vf3_sys_lookup(VF3_SND_EP_DRESET);
    return ep ? ep(voice_id) : -1;
}
