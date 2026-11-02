/* sys/aica_model.h - the AICA's register file and its channels.
 *
 * The AICA is the sound chip: one register file (8 KiB) that both the SH-4 and
 * the ARM7 (the sound CPU) can reach, and 2 MiB of sound RAM that both share.
 * This module models the register file and the channels' parameters; the
 * mixer that turns the channels into PCM is the next piece
 * (docs/re/aica_audio_model.md).
 *
 * The layout is the hardware's, not a guess:
 *
 *   - the register file is 8 KiB; the SGC's channel slots are 0x80 bytes each,
 *     so there are 64 of them;
 *   - a slot's registers are 16 bits wide, aligned to 32 bits: the word at
 *     +0x00 holds `SA_hi:7 PCMS:2 LPCTL SSCTL :3 KYONB KYONEX`, the word at
 *     +0x04 holds `SA_low:16`, and so on;
 *   - the reference's own view of a slot is its packed `ChannelCommonData`
 *     (flycast's core/hw/aica/sgc_if.cpp).
 *
 * The registers are stored as bytes, the way the hardware stores them: the
 * driver writes a byte at +0x01 (the high half of the word at +0x00) to set
 * the key-on bits, and a byte at +0x29 (the high half of the word at +0x28)
 * to set the total level.
 *
 * The ports:
 *   - the ARM7's window is 0x00800000 + offset (the offset is & 0x7FFF);
 *   - the SH-4's window is 0x00700000 + offset.
 */
#ifndef VF3_SYS_AICA_MODEL_H
#define VF3_SYS_AICA_MODEL_H

#include <stdint.h>

/* The register file's size, and the sound RAM's. */
#define VF3_AICA_REG_SIZE    0x8000u
#define VF3_AICA_RAM_SIZE    0x200000u

/* The SGC's channel slots. */
#define VF3_AICA_SLOT_COUNT  64u
#define VF3_AICA_SLOT_STRIDE 0x80u

/* The sample formats a channel can play (the reference's PCMSType). */
enum {
    VF3_AICA_PCM16       = 0,
    VF3_AICA_PCM8        = 1,
    VF3_AICA_ADPCM       = 2,
    VF3_AICA_ADPCM_STREAM = 3,
    VF3_AICA_NOISE       = 4
};

/* One channel's parameters, decoded from its slot. */
typedef struct {
    uint32_t sa;        /* the 22-bit sample address */
    uint16_t lsa;       /* the loop start */
    uint16_t lea;       /* the loop end */
    uint8_t pcms;       /* the sample format */
    uint8_t lpctl;      /* the loop control */
    uint8_t ssctl;      /* the noise control */
    uint8_t kyonb;      /* the key-on bit (the channel's own) */
    uint8_t kyonex;     /* the key-on trigger (cleared by the hardware) */
    uint8_t ar, d1r, d2r;   /* the amplitude envelope */
    uint8_t rr, dl, krs;    /* the release, the decay level, the key rate */
    uint8_t lpslnk;         /* the loop's link */
    uint16_t fns;           /* the frequency number */
    uint8_t oct;            /* the octave */
    uint8_t alfos, alfows;  /* the amplitude LFO */
    uint8_t plfos, plfows;  /* the pitch LFO */
    uint8_t lfof, lfore;    /* the LFO's frequency and its "derived" flag */
    uint8_t isel, imxl;     /* the input selector and the send level */
    uint8_t dipan, disdl;   /* the digital pan and the direct send level */
    uint8_t q, lpoff, voff; /* the filter's Q, the filter's and the
                              * attenuation's "off" bits */
    uint8_t tl;             /* the total level (0xFF is silence) */
    uint8_t fd1r, far;      /* the filter's envelope */
    uint8_t fd2r, frr;
    uint16_t flv0, flv1, flv2, flv3, flv4;  /* the filter's envelope's levels */
    uint32_t rate;          /* the derived playback rate (the reference's
                             * update_rate) */
} vf3_aica_channel;

/* The AICA: the register file, the sound RAM and the channels.  The tag is
 * named so a header can forward-declare it (native_tick.h). */
typedef struct vf3_aica_model {
    uint8_t reg[VF3_AICA_REG_SIZE];
    uint8_t *ram;                            /* the sound RAM (the caller's) */
    vf3_aica_channel chan[VF3_AICA_SLOT_COUNT];
    uint8_t keyed[VF3_AICA_SLOT_COUNT];      /* the channels that are on */
    uint32_t ca[VF3_AICA_SLOT_COUNT];        /* the channels' current address */
} vf3_aica_model;

/* The model, with the sound RAM the caller owns. */
void vf3_aica_init(vf3_aica_model *m, uint8_t *ram);

/* A write into the register file: the bytes only.  The key-on trigger (the
 * hardware starting the channels) is the mixer's business, because only the
 * mixer knows the channels' running state. */
void vf3_aica_write_bytes(vf3_aica_model *m, uint32_t offset, uint32_t value, unsigned size);

/* A write into the register file.  `offset` is the offset in the file (the
 * ARM7's window is 0x00800000 + offset, the SH-4's is 0x00700000 + offset);
 * `size` is 1, 2 or 4.  A write that sets the key-on trigger starts (or
 * stops) the channels, the way the hardware does. */
void vf3_aica_write(vf3_aica_model *m, uint32_t offset, uint32_t value, unsigned size);

/* A read from the register file. */
uint32_t vf3_aica_read(const vf3_aica_model *m, uint32_t offset, unsigned size);

/* The channel's parameters, decoded from its slot. */
void vf3_aica_decode(vf3_aica_model *m, unsigned slot);

/* The key-on: the channel starts playing from its sample address. */
void vf3_aica_key_on(vf3_aica_model *m, unsigned slot);
void vf3_aica_key_off(vf3_aica_model *m, unsigned slot);

/* The playback rate of a channel, the way the hardware derives it from the
 * frequency number and the octave: the rate is 1024 | FNS, shifted by the
 * octave (an octave of 8 or more divides). */
uint32_t vf3_aica_rate(uint16_t fns, uint8_t oct);

#endif
