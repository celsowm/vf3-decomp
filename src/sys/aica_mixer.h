/* sys/aica_mixer.h - the AICA's mixer: the channels into PCM.
 *
 * The AICA has 64 channels.  Each one fetches a sample out of the sound RAM,
 * interpolates it, runs it through an amplitude envelope, an optional low-pass
 * filter and a volume/pan stage, and the sum of the 64 channels is the stereo
 * frame the chip hands to the rest of the machine.
 *
 * This module is that mixer.  It is the mirror of the reference's own mixer
 * (flycast's core/hw/aica/sgc_if.cpp, the `ChannelEx` class and
 * `AICA_Sample`), and every rule below is the hardware's:
 *
 *   - the channel's registers live in the register file (sys/aica_model.h);
 *     the mixer reads them and keeps the running state the hardware keeps
 *     between samples (where the channel is in its sample, what its
 *     envelopes are doing, the interpolator's two samples);
 *   - the amplitude envelope advances once per output sample, in 16.16 fixed
 *     point, through attack, decay 1, decay 2 and release;
 *   - the sample is interpolated between the channel's last two samples, and
 *     the pitch is the channel's rate (1024 | FNS, shifted by the octave);
 *   - the volume is a logarithmic table: the total level, the send levels and
 *     the pan are summed into one attenuation and looked up;
 *   - the master volume and the saturation are the last steps.
 *
 * What the reference's mixer adds and this one does not: the Yamaha DSP
 * (reverb and the other effects) and the CD-audio input.  The reference runs
 * with the DSP off (its `aica.DSPEnabled` option defaults to false) and the
 * game has no CD-audio stream, so both contribute silence; the mixer here
 * leaves them out, and docs/re/aica_audio_model.md records the measurement.
 */
#ifndef VF3_SYS_AICA_MIXER_H
#define VF3_SYS_AICA_MIXER_H

#include <stdint.h>

#include "sys/aica_model.h"

/* The amplitude envelope's states (the reference's EGState). */
enum {
    VF3_AEG_ATTACK  = 0,
    VF3_AEG_DECAY1  = 1,
    VF3_AEG_DECAY2  = 2,
    VF3_AEG_RELEASE = 3
};

/* The LFO's waveforms (the reference's LFOType). */
enum {
    VF3_LFO_SAWTOOTH = 0,
    VF3_LFO_SQUARE   = 1,
    VF3_LFO_TRIANGLE = 2,
    VF3_LFO_RANDOM   = 3
};

/* One channel's running state: the hardware's own bookkeeping between
 * samples.  The names follow the reference's `ChannelEx`. */
typedef struct {
    uint32_t sa;            /* the sample's address in the sound RAM */
    uint32_t ca;            /* the current sample index inside it */
    uint32_t step;          /* the playback step, 22.10 fixed point */
    int32_t  s0, s1;        /* the last two samples, for the interpolator */
    uint8_t  looped;        /* the channel has reached the loop's end */
    int32_t  adpcm_quant;      /* the ADPCM's quantizer */
    int32_t  adpcm_loop_quant; /* the quantizer at the loop's start */
    int32_t  adpcm_loop_prev;  /* the sample before the loop's start */
    uint8_t  adpcm_in_loop;
    uint32_t noise_state;   /* the noise generator's state */
    int32_t  aeg_value;     /* the amplitude envelope, 16 fractional bits */
    uint8_t  aeg_state;
    uint32_t feg_value;     /* the filter's envelope */
    uint8_t  feg_state;
    int32_t  feg_prev1, feg_prev2, feg_fract;
    uint32_t lfo_counter;   /* the LFO's countdown */
    uint8_t  lfo_state;     /* the LFO's phase */
    uint8_t  enabled;       /* the channel is playing */
    uint8_t  lfo_alfo;      /* the amplitude LFO's current value */
    uint8_t  lfo_alfo_shift;
    uint32_t lfo_plfo_step; /* the pitch LFO's step, 22.10 fixed point */
    /* The values the hardware derives from the registers (the reference's
     * Update* helpers).  They follow the register file, so the mixer
     * refreshes them before it uses them. */
    uint32_t dl_att, dr_att, dsp_att; /* the three attenuations */
    uint32_t attack_rate, decay1_rate, decay2_value, decay2_rate, release_rate;
    uint32_t feg_attack_rate, feg_decay1_rate, feg_decay2_rate, feg_release_rate;
    int32_t  feg_q;          /* the filter's Q */
    uint8_t  feg_active;     /* the filter is in the circuit */
    uint8_t  lfo_alfo_type, lfo_plfo_type;
    uint32_t lfo_start_value;
} vf3_aica_mixer_channel;

/* The mixer: the 64 channels' running state, over a register file and a sound
 * RAM (the model's). */
typedef struct {
    vf3_aica_model *model;  /* the register file and the sound RAM */
    vf3_aica_mixer_channel chan[VF3_AICA_SLOT_COUNT];
} vf3_aica_mixer;

/* The mixer, over a model the caller owns. */
void vf3_aica_mixer_init(vf3_aica_mixer *mx, vf3_aica_model *model);

/* A write into the register file, the way the hardware takes it: the bytes go
 * into the file and the channel they belong to reacts (the key-on trigger
 * starts or stops the channels, the LFO's registers restart it).  `offset` is
 * the offset in the register file, `size` is 1, 2 or 4. */
void vf3_aica_mixer_write(vf3_aica_mixer *mx, uint32_t offset, uint32_t value,
                          unsigned size);

/* One sample: the 64 channels are mixed, the master volume and the
 * saturation are applied.  The chip's frame is (right, left); the mixer
 * hands them out in that order too. */
void vf3_aica_mixer_sample(vf3_aica_mixer *mx, int16_t *right, int16_t *left);

/* The channel's state, for the tests and for the save states. */
vf3_aica_mixer_channel *vf3_aica_mixer_channel_state(vf3_aica_mixer *mx,
                                                       unsigned slot);

/* Refresh the channels' parameters from the register file.  The model
 * decodes them on every write, so this is only needed when the register
 * file was filled in directly (a state that was loaded). */
void vf3_aica_mixer_decode_all(vf3_aica_mixer *mx);

/* The channel's running state, as the hardware keeps it between samples (a
 * save state, or the reference's own serialization).  The mixer takes the
 * state and refreshes the values it derives from the registers. */
void vf3_aica_mixer_channel_load(vf3_aica_mixer *mx, unsigned slot,
                                 const vf3_aica_mixer_channel *state);

#endif
