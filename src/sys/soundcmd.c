/* sys/soundcmd.c — unattributed libsnd 0.82 "mpdrv" endpoint facade (M37).
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
 * Updated evidence: the complete BGM_VAN bank begins at AICA 0x086E50.
 * The old 0x00A0B4..0x00CF5D change window includes ARM stack, command
 * queue and software work records; PCM streaming is not established.
 *
 * SNDDRV.BIN is the resident ARM firmware. Verified SH-4 producers live
 * in fight/audio_*.c. Debug strings do not establish these endpoints or
 * their opcodes, and no voice-reset framing is claimed by this facade.
 */
#include <stdint.h>

#include "mainloop.h"   /* vf3_sys_lookup */

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
