/* sys/aica_mixer.c - the AICA's mixer: the channels into PCM.
 *
 * The mirror of the reference's own mixer (flycast's
 * core/hw/aica/sgc_if.cpp: the `ChannelEx` class and `AICA_Sample`).  Every
 * rule here is the hardware's, and the names in the comments are the
 * reference's, so the two can be read side by side:
 *
 *   core/hw/aica/sgc_if.cpp
 *     ChannelEx::Step          -> channel_step()
 *     ChannelEx::AegStep       -> aeg_step()
 *     ChannelEx::FegStep       -> feg_step()
 *     ChannelEx::StreamStep    -> stream_step()
 *     ChannelEx::StepDecodeSample -> decode_sample()
 *     ChannelEx::InterpolateSample -> interpolate()
 *     ChannelEx::lowPassFilter -> low_pass_filter()
 *     ChannelEx::KEY_ON/KEY_OFF -> key_on()/key_off()
 *     ChannelEx::RegWrite      -> vf3_aica_mixer_write()
 *     sgc::AICA_Sample         -> vf3_aica_mixer_sample()
 *
 * The two things the reference's mixer has and this one does not are the
 * Yamaha DSP (the effects) and the CD-audio input.  The reference runs with
 * the DSP off (`aica.DSPEnabled` defaults to false) and the game has no
 * CD-audio stream, so both are silent; docs/re/aica_audio_model.md records
 * the measurement.
 */
#include "sys/aica_mixer.h"

#include <math.h>
#include <string.h>

/* ---- the hardware's tables -------------------------------------------- */

/* The attenuation table (xx.15): the index is the total attenuation, the
 * value the gain.  The reference builds it from the formula
 * (1 << 15) / pow(2, i / 16) and leaves the entries from 256 up at zero,
 * which is what mutes a channel whose total level is 0xFF. */
static int32_t tl_lut[256];

/* The master volume table.  The reference leaves the first entry at zero, so
 * the master's value 0 is silence and 15 (what the game programs) is unity. */
static int32_t volume_lut[16];

/* The envelope's rates: the steps per sample, for each of the 64 rates. */
static uint32_t aeg_att_sps[64];
static uint32_t aeg_dsr_sps[64];

/* The pitch LFO's step table: the eight depths, each with its 256 phases. */
static int32_t plfo_scales[8][256];

/* The filter's Q table. */
static const int32_t q_table[32] = {
    2048,  1536,  1024,   512,
       0,  -256,  -512,  -768,
   -1024, -1280, -1536, -1792,
   -2048, -2176, -2304, -2432,
   -2560, -2688, -2816, -2944,
   -3072, -3136, -3200, -3264,
   -3328, -3392, -3456, -3520,
   -3584, -3648, -3712, -3776
};

/* The send levels (the reference's SendLevel): 255 is silence. */
static const uint32_t send_level[16] = {
    255, 14 << 3, 13 << 3, 12 << 3, 11 << 3, 10 << 3, 9 << 3, 8 << 3,
    7 << 3, 6 << 3, 5 << 3, 4 << 3, 3 << 3, 2 << 3, 1 << 3, 0 << 3
};

/* The ADPCM's tables: the quantizer's multiplier and the scale of the
 * eight steps. */
static const int32_t adpcm_qs[8] = {
    0x0e6, 0x0e6, 0x0e6, 0x0e6, 0x133, 0x199, 0x200, 0x266
};
static const int32_t adpcm_scale[8] = { 1, 3, 5, 7, 9, 11, 13, 15 };

/* The noise generator's constants (the reference's RAND_FACTOR/RAND_TERM). */
#define RAND_FACTOR 0x41c64e6du
#define RAND_TERM   0x3039u

/* The envelope's fixed point: the value carries 16 fractional bits. */
#define EG_STEP_BITS 16
#define AEG_ATTACK_SHIFT 16

/* ---- the tables' construction ----------------------------------------- */

/* The number of steps a decay takes (the reference's CalcEgSteps).  The
 * envelope's whole range is 1024 steps of 16.16. */
static uint32_t calc_eg_steps(double t)
{
    const double eg_allsteps = 1024.0 * (double)(1u << EG_STEP_BITS) - 1.0;
    double steps;

    if (t < 0.0) return 0;
    if (t == 0.0) return (uint32_t)eg_allsteps;
    steps = eg_allsteps / (44.1 * t);
    return (uint32_t)(steps + 0.5);
}

/* The number of steps an attack takes (the reference's CalcAttackEgSteps).
 * The attack is the exponential approach to zero, so its rate is not a
 * division but the inverse of the curve. */
static uint32_t calc_attack_eg_steps(double t)
{
    double scnt, factor;

    if (t < 0.0) return 0;
    if (t == 0.0) return 1u << AEG_ATTACK_SHIFT;
    scnt = 44.1 * t;
    factor = (1.0 / (1.0 - 1.0 / pow(0x280, 1.0 / scnt))) * (double)(1u << AEG_ATTACK_SHIFT);
    return (uint32_t)(factor + 0.5);
}

/* The attack times, in milliseconds (the reference's AEG_Attack_Time). */
static const double aeg_attack_time[64] = {
    -1,-1,8100.0,6900.0,6000.0,4800.0,4000.0,3400.0,3000.0,2400.0,2000.0,1700.0,1500.0,
    1200.0,1000.0,860.0,760.0,600.0,500.0,430.0,380.0,300.0,250.0,220.0,190.0,150.0,130.0,110.0,95.0,
    76.0,63.0,55.0,47.0,38.0,31.0,27.0,24.0,19.0,15.0,13.0,12.0,9.4,7.9,6.8,6.0,4.7,3.8,3.4,3.0,2.4,
    2.0,1.8,1.6,1.3,1.1,0.93,0.85,0.65,0.53,0.44,0.40,0.35,0.0,0.0
};

/* The decay and release times, in milliseconds (the reference's
 * AEG_DSR_Time). */
static const double aeg_dsr_time[64] = {
    -1,-1,118200.0,101300.0,88600.0,70900.0,59100.0,50700.0,44300.0,35500.0,29600.0,25300.0,22200.0,17700.0,
    14800.0,12700.0,11100.0,8900.0,7400.0,6300.0,5500.0,4400.0,3700.0,3200.0,2800.0,2200.0,1800.0,1600.0,1400.0,1100.0,
    920.0,790.0,690.0,550.0,460.0,390.0,340.0,270.0,230.0,200.0,170.0,140.0,110.0,98.0,85.0,68.0,57.0,49.0,43.0,34.0,
    28.0,25.0,22.0,18.0,14.0,12.0,11.0,8.5,7.1,6.1,5.4,4.3,3.6,3.1
};

/* The pitch LFO's depth per scale (the reference's PLFOS_Scale). */
static const float plfo_scale[8] = {
    0.f, 3.61f, 7.22f, 14.44f, 28.88f, 57.75f, 115.5f, 231.f
};

static int tables_ready;

static void build_tables(void)
{
    unsigned i, s;

    if (tables_ready) return;
    tables_ready = 1;

    for (i = 0; i < 256; ++i)
        tl_lut[i] = (int32_t)((1 << 15) / pow(2.0, (double)i / 16.0));

    /* the reference starts at 1: the entry 0 stays zero, so the master's
     * value 0 is silence */
    for (i = 1; i < 16; ++i)
        volume_lut[i] = (int32_t)((1 << 15) / pow(2.0, (double)(15 - i) / 2.0));

    for (i = 0; i < 64; ++i) {
        aeg_att_sps[i] = calc_attack_eg_steps(aeg_attack_time[i]);
        aeg_dsr_sps[i] = calc_eg_steps(aeg_dsr_time[i]);
    }

    for (s = 0; s < 8; ++s) {
        const float limit = plfo_scale[s];
        for (i = 0; i < 256; ++i)
            plfo_scales[s][i] = (int32_t)(1024.f * powf(2.f, limit * (float)i / 128.f / 1200.f));
    }
}

/* ---- the sound RAM ---------------------------------------------------- */

/* The RAM is 2 MiB and the hardware wraps around it (the reference's
 * ARAM_MASK). */
#define ARAM_MASK 0x1FFFFFu

static uint32_t ram_u8(const vf3_aica_model *m, uint32_t addr)
{
    return m->ram[addr & ARAM_MASK];
}

static int32_t ram_s8(const vf3_aica_model *m, uint32_t addr)
{
    return (int32_t)(int8_t)m->ram[addr & ARAM_MASK];
}

static int32_t ram_s16(const vf3_aica_model *m, uint32_t addr)
{
    addr &= ARAM_MASK & ~(uint32_t)1;
    return (int32_t)(int16_t)((uint32_t)m->ram[addr] | ((uint32_t)m->ram[addr + 1u] << 8));
}

/* ---- the channel's running state -------------------------------------- */

/* The channel's next sample (defined below, with the samples). */
static void decode_sample(vf3_aica_mixer *mx, unsigned slot, uint32_t ca, int last);

static int32_t aeg_get_value(const vf3_aica_mixer_channel *c)
{
    return c->aeg_value >> EG_STEP_BITS;
}

static void aeg_set_value(vf3_aica_mixer_channel *c, uint32_t value)
{
    c->aeg_value = (int32_t)(value << EG_STEP_BITS);
}

/* The envelope's state change (the reference's SetAegState).  The release
 * also clears the channel's key-on bit in the register file: the hardware
 * does that when the voice goes silent. */
static void set_aeg_state(vf3_aica_mixer *mx, unsigned slot, unsigned state)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    c->aeg_state = (uint8_t)state;
    if (state == VF3_AEG_RELEASE)
        mx->model->reg[slot * VF3_AICA_SLOT_STRIDE + 1u] &= (uint8_t)~0x40u;
}

/* The filter's envelope's state change (the reference's SetFegState). */
static void set_feg_state(vf3_aica_mixer *mx, unsigned slot, unsigned state)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    c->feg_state = (uint8_t)state;
    if (state == VF3_AEG_ATTACK) {
        c->feg_value = (uint32_t)mx->model->chan[slot].flv0 << EG_STEP_BITS;
        c->feg_prev1 = 0;
        c->feg_prev2 = 0;
        c->feg_fract = 0;
    }
}

/* The channel stops (the reference's disable). */
static void channel_disable(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    c->enabled = 0;
    set_aeg_state(mx, slot, VF3_AEG_RELEASE);
    aeg_set_value(c, 0x3FF);
    c->ca = 0;
}

/* The channel starts (the reference's KEY_ON). */
static void key_on(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];

    if (c->aeg_state != VF3_AEG_RELEASE) return;

    c->enabled = 1;
    set_aeg_state(mx, slot, VF3_AEG_ATTACK);
    aeg_set_value(c, 0x280);       /* the attack starts from the top */
    set_feg_state(mx, slot, VF3_AEG_ATTACK);

    c->ca = 0;
    c->step = 0;
    c->looped = 0;

    /* the ADPCM's decoder restarts */
    c->adpcm_quant = 127;
    c->adpcm_loop_quant = 0;
    c->adpcm_loop_prev = 0;
    c->adpcm_in_loop = 0;
    c->s0 = 0;

    /* the first sample of the channel */
    decode_sample(mx, slot, 0, 1);

    mx->model->keyed[slot] = 1;
    mx->model->ca[slot] = mx->model->chan[slot].sa;
}

/* The channel is released (the reference's KEY_OFF). */
static void key_off(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];

    if (c->aeg_state == VF3_AEG_RELEASE) return;
    set_aeg_state(mx, slot, VF3_AEG_RELEASE);
    set_feg_state(mx, slot, VF3_AEG_RELEASE);
}

/* The sample's address (the reference's UpdateSA).  The channel plays from
 * the address in its registers, and the driver reprograms it when it starts
 * a voice. */
static void update_sa(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];

    c->sa = p->sa;
    if (p->pcms == VF3_AICA_PCM16) c->sa &= ~1u;
}

/* ---- the samples ------------------------------------------------------ */

/* One ADPCM step (the reference's DecodeADPCM): the nibble says how much to
 * move and in which direction. */
static int32_t decode_adpcm(int32_t sample, int32_t prev, int32_t *quant)
{
    const int32_t sign = 1 - 2 * (sample / 8);
    const unsigned data = (unsigned)sample & 7u;
    int32_t rv = (*quant * adpcm_scale[data]) >> 3;

    if (rv > 0x7FFF) rv = 0x7FFF;
    rv = sign * rv + prev;

    *quant = (*quant * adpcm_qs[data]) >> 8;
    if (*quant < 127) *quant = 127;
    else if (*quant > 24576) *quant = 24576;

    if (rv < -32768) rv = -32768;
    else if (rv > 32767) rv = 32767;
    return rv;
}

/* The channel's next sample (the reference's StepDecodeSample).  `last` says
 * whether this is the sample the channel stops on: only then is the second
 * sample of the interpolation decoded as well. */
static void decode_sample(vf3_aica_mixer *mx, unsigned slot, uint32_t ca, int last)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];
    const vf3_aica_model *m = mx->model;
    uint32_t next = ca + 1u;
    uint32_t lea;
    int32_t s0 = 0, s1 = 0;

    if (p->pcms == VF3_AICA_ADPCM_STREAM) {
        /* the long stream needs the loop's end aligned to four samples */
        lea = (p->lea + 3u) & ~3u;
    } else {
        lea = p->lea;
    }
    if (next >= lea && lea > p->lsa) next = p->lsa;

    switch (p->pcms) {
    case VF3_AICA_NOISE:
        c->noise_state = c->noise_state * RAND_FACTOR + RAND_TERM;
        s0 = (int32_t)(c->noise_state >> 16);
        c->noise_state = c->noise_state * RAND_FACTOR + RAND_TERM;
        s1 = (int32_t)(c->noise_state >> 16);
        break;

    case VF3_AICA_PCM16:
        s0 = ram_s16(m, c->sa + ca * 2u);
        s1 = ram_s16(m, c->sa + next * 2u);
        break;

    case VF3_AICA_PCM8:
        s0 = ram_s8(m, c->sa + ca) << 8;
        s1 = ram_s8(m, c->sa + next) << 8;
        break;

    case VF3_AICA_ADPCM:
    case VF3_AICA_ADPCM_STREAM:
    {
        unsigned ad1 = ram_u8(m, c->sa + (ca >> 1));
        unsigned ad2 = ram_u8(m, c->sa + (next >> 1));
        int32_t q = c->adpcm_quant;

        ad1 >>= (ca & 1u) * 4u;      /* the low nibble comes first */
        ad2 >>= (next & 1u) * 4u;
        ad1 &= 0xFu;
        ad2 &= 0xFu;

        if (ca == p->lsa) {
            if (!c->adpcm_in_loop) {
                /* the first time at the loop's start: remember the state */
                c->adpcm_in_loop = 1;
                c->adpcm_loop_quant = q;
                c->adpcm_loop_prev = c->s0;
            } else if (p->pcms == VF3_AICA_ADPCM) {
                /* the loop restarts from the remembered state */
                q = c->adpcm_loop_quant;
                c->s0 = c->adpcm_loop_prev;
            }
        }
        s0 = decode_adpcm((int32_t)ad1, c->s0, &q);
        c->adpcm_quant = q;
        if (last) {
            int32_t prev = s0;
            if (p->pcms == VF3_AICA_ADPCM && next == p->lsa && c->adpcm_in_loop) {
                q = c->adpcm_loop_quant;
                prev = c->adpcm_loop_prev;
            }
            s1 = decode_adpcm((int32_t)ad2, prev, &q);
        } else {
            s1 = 0;
        }
        break;
    }
    default:
        break;
    }

    c->s0 = s0;
    c->s1 = s1;
}

/* The interpolation between the channel's last two samples (the reference's
 * InterpolateSample). */
static int32_t interpolate(const vf3_aica_mixer_channel *c)
{
    const int32_t fp = (int32_t)(c->step & 0x3FFu);
    int32_t rv = (int32_t)(((int64_t)c->s0 * (1024 - fp)) >> 10);
    rv += (int32_t)(((int64_t)c->s1 * fp) >> 10);
    return rv;
}

/* The channel's playback step (the reference's StreamStep): the channel
 * advances by its rate, one sample at a time, and decodes what it passes. */
static void stream_step(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];
    uint32_t full, ip;

    full = c->step + (uint32_t)(((uint64_t)p->rate * (uint64_t)c->lfo_plfo_step) >> 10);
    ip = full >> 10;
    c->step = full & 0x3FFu;         /* the integer part is spent here */

    while (ip > 0) {
        uint32_t ca, lea;
        --ip;
        ca = c->ca + 1u;
        lea = (p->pcms == VF3_AICA_ADPCM_STREAM) ? ((p->lea + 3u) & ~3u) : p->lea;

        if (p->lpslnk && c->aeg_state == VF3_AEG_ATTACK && ca >= p->lsa)
            set_aeg_state(mx, slot, VF3_AEG_DECAY1);

        if (ca >= lea) {
            if (p->lsa > lea) {
                /* the hardware does not stop at the loop's end but at the
                 * loop's start, and it does not loop there */
                if (ca >= p->lsa) {
                    c->looped = 1;
                    ca = 0;
                    channel_disable(mx, slot);
                }
            } else {
                c->looped = 1;
                if (!p->lpctl) {
                    ca = 0;
                    channel_disable(mx, slot);
                } else {
                    ca = p->lsa;
                }
            }
        }

        c->ca = ca;
        decode_sample(mx, slot, ca, ip == 0);
    }
}

/* ---- the envelopes ---------------------------------------------------- */

/* The envelope's rate, the way the hardware derives it from the key rate
 * (the reference's EG_EffRate). */
static uint32_t eg_eff_rate(const vf3_aica_channel *p, uint32_t rate)
{
    uint32_t effrate = rate * 2u;

    if (p->krs < 0xFu) {
        effrate += ((uint32_t)p->fns >> 9) & 1u;
        {
            const int32_t extra = (int32_t)p->krs + (int32_t)(p->oct ^ 8u) - 8;
            if (extra > 0) effrate += (uint32_t)(extra * 2);
        }
    }
    if (effrate > 0x3Fu) effrate = 0x3Fu;
    return effrate;
}

/* The amplitude envelope's step (the reference's AegStep). */
static void aeg_step(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];

    switch (c->aeg_state) {
    case VF3_AEG_ATTACK:
        if (c->attack_rate != 0) {
            const uint64_t value = (uint64_t)(int64_t)c->aeg_value;
            const uint64_t drop = ((value << AEG_ATTACK_SHIFT) / c->attack_rate) + 1u;
            c->aeg_value = (int32_t)(uint32_t)(value - drop);
            if (aeg_get_value(c) <= 0) {
                if (!p->lpslnk) set_aeg_state(mx, slot, VF3_AEG_DECAY1);
                aeg_set_value(c, 0);
            }
        }
        break;

    case VF3_AEG_DECAY1:
        c->aeg_value += (int32_t)c->decay1_rate;
        if ((uint32_t)aeg_get_value(c) >= c->decay2_value)
            set_aeg_state(mx, slot, VF3_AEG_DECAY2);
        break;

    case VF3_AEG_DECAY2:
        c->aeg_value += (int32_t)c->decay2_rate;
        if (aeg_get_value(c) >= 0x3FF) {
            aeg_set_value(c, 0x3FF);
            set_aeg_state(mx, slot, VF3_AEG_RELEASE);
        }
        break;

    case VF3_AEG_RELEASE:
        c->aeg_value += (int32_t)c->release_rate;
        if (aeg_get_value(c) >= 0x3FF) channel_disable(mx, slot);
        break;

    default:
        break;
    }
}

/* The filter's envelope's step (the reference's FegStep). */
static void feg_step(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];
    uint32_t delta, target;

    if (!c->feg_active) return;

    switch (c->feg_state) {
    case VF3_AEG_ATTACK:  delta = c->feg_attack_rate;  target = p->flv1; break;
    case VF3_AEG_DECAY1:  delta = c->feg_decay1_rate;  target = p->flv2; break;
    case VF3_AEG_DECAY2:  delta = c->feg_decay2_rate;  target = p->flv3; break;
    default:              delta = c->feg_release_rate; target = p->flv4; break;
    }
    target <<= EG_STEP_BITS;

    if (c->feg_value < target) {
        uint32_t maxd = target - c->feg_value;
        if (delta > maxd) delta = maxd;
        c->feg_value += delta;
    } else if (c->feg_value > target) {
        uint32_t maxd = c->feg_value - target;
        if (delta > maxd) delta = maxd;
        c->feg_value -= delta;
    } else if (c->feg_state < VF3_AEG_DECAY2) {
        set_feg_state(mx, slot, (unsigned)c->feg_state + 1u);
    }
}

/* The low-pass filter (the reference's lowPassFilter). */
static int32_t low_pass_filter(vf3_aica_mixer *mx, unsigned slot, int32_t sample)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const uint32_t coef_bits = 30;
    uint32_t fv, exp, mant;
    uint64_t a0;
    int64_t f, b1, b2, mac;

    if (!c->feg_active) return sample;

    fv = c->feg_value >> EG_STEP_BITS;
    exp = fv >> 9;
    mant = (fv & 0x1FFu) | 0x200u;
    a0 = ((uint64_t)mant << 30) >> ((15u - exp) * 2u);
    a0 *= (mant - 1u) / 8u;
    a0 >>= (47u - coef_bits);
    f = ((int64_t)mant << exp) << (int64_t)(coef_bits - 25);
    f += (int64_t)c->feg_q * f / 4096;
    b1 = 128ll * 1024 * (1ll << (int64_t)(coef_bits - 16)) - (f + (int64_t)a0);
    b2 = 64ll * 1024 * (1ll << (int64_t)(coef_bits - 16)) - f;
    if (exp == 0) c->feg_fract = 0;

    mac = -(int64_t)a0 * sample + b1 * c->feg_prev1 - b2 * c->feg_prev2 - c->feg_fract;
    sample = (int32_t)(mac >> (int64_t)coef_bits);
    c->feg_fract = (int32_t)(((int64_t)sample << (int64_t)coef_bits) - mac);
    c->feg_prev2 = c->feg_prev1;
    if (sample < -512 * 1024) sample = -512 * 1024;
    else if (sample > 512 * 1024 - 1) sample = 512 * 1024 - 1;
    c->feg_prev1 = sample;
    return sample;
}

/* ---- the LFO ---------------------------------------------------------- */

/* The LFO's waveform (the reference's CalcAlfo/CalcPlfo). */
static uint32_t lfo_wave(unsigned type, uint8_t state)
{
    switch (type) {
    case VF3_LFO_SQUARE:   return (state & 0x80u) ? 255u : 0u;
    case VF3_LFO_TRIANGLE:
        return (uint32_t)(((state & 0x7Fu) ^ (state & 0x80u ? 0x7Fu : 0u)) << 1);
    case VF3_LFO_RANDOM:   return (uint32_t)(state * RAND_FACTOR + RAND_TERM) & 0xFFu;
    default:               return state;
    }
}

static void calc_alfo(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const uint32_t rv = lfo_wave(c->lfo_alfo_type, c->lfo_state);
    c->lfo_alfo = (uint8_t)(rv >> c->lfo_alfo_shift);
}

static void calc_plfo(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const uint32_t rv = lfo_wave(c->lfo_plfo_type, c->lfo_state);
    c->lfo_plfo_step = (uint32_t)plfo_scales[mx->model->chan[slot].plfos][rv & 0xFFu];
}

/* The LFO's registers (the reference's UpdateLFO).  `derived` says the state
 * comes from a save state, so the countdown is not restarted. */
static void update_lfo(vf3_aica_mixer *mx, unsigned slot, int derived)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];

    c->lfo_alfo_type = p->alfows;
    c->lfo_plfo_type = p->plfows;
    if (p->alfows == VF3_LFO_RANDOM && p->plfows == VF3_LFO_RANDOM) {
        /* the frequency does not matter when both are random */
        c->lfo_start_value = 1;
        c->lfo_counter = 1;
    } else {
        const uint32_t n = p->lfof;
        const uint32_t s = n >> 2;
        const uint32_t mm = (~n) & 3u;
        const uint32_t g = 128u >> s;
        const uint32_t l = (g - 1u) << 2;
        c->lfo_start_value = l + g * (mm + 1u);
        if (!derived) c->lfo_counter = c->lfo_start_value;
    }
    c->lfo_alfo_shift = (uint8_t)(8u - p->alfos);

    if (p->lfore && !derived) {
        c->lfo_state = 0;
        c->lfo_counter = c->lfo_start_value;
    }
    calc_alfo(mx, slot);
    calc_plfo(mx, slot);
}

/* The LFO's step (the reference's Lfo::Step). */
static void lfo_step(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];

    --c->lfo_counter;
    if (c->lfo_counter == 0) {
        ++c->lfo_state;
        c->lfo_counter = c->lfo_start_value;
        calc_alfo(mx, slot);
        calc_plfo(mx, slot);
    } else {
        if (c->lfo_alfo_type == VF3_LFO_RANDOM) calc_alfo(mx, slot);
        if (c->lfo_plfo_type == VF3_LFO_RANDOM) calc_plfo(mx, slot);
    }
}

/* ---- the values the registers derive ---------------------------------- */

/* The three attenuations (the reference's UpdateAtts): the total level, the
 * send levels and the pan are summed into one number each. */
static void update_atts(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];
    const uint32_t total = p->voff ? 0u : (uint32_t)p->tl;
    const uint32_t att_full = total + send_level[p->disdl];
    const uint32_t att_pan = att_full + send_level[(~p->dipan) & 0xFu];

    if (p->dipan & 0x10u) {
        /* the right channel decreases */
        c->dl_att = att_full;
        c->dr_att = att_pan;
    } else {
        /* the left channel decreases */
        c->dl_att = att_pan;
        c->dr_att = att_full;
    }
    c->dsp_att = total + send_level[p->imxl];
}

/* The envelope's rates (the reference's UpdateAEG). */
static void update_aeg(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];

    c->attack_rate = aeg_att_sps[eg_eff_rate(p, p->ar)];
    c->decay1_rate = aeg_dsr_sps[eg_eff_rate(p, p->d1r)];
    c->decay2_value = (uint32_t)p->dl << 5;
    c->decay2_rate = aeg_dsr_sps[eg_eff_rate(p, p->d2r)];
    c->release_rate = aeg_dsr_sps[eg_eff_rate(p, p->rr)];
}

/* The filter's envelope (the reference's UpdateFEG). */
static void update_feg(vf3_aica_mixer *mx, unsigned slot)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];

    c->feg_active = (uint8_t)(p->lpoff == 0 &&
        (p->flv0 < 0x1FF8u || p->flv1 < 0x1FF8u || p->flv2 < 0x1FF8u ||
         p->flv3 < 0x1FF8u || p->flv4 < 0x1FF8u || p->q != 4));
    if (!c->feg_active) return;
    c->feg_q = q_table[p->q];
    c->feg_attack_rate = aeg_dsr_sps[eg_eff_rate(p, p->far)];
    c->feg_decay1_rate = aeg_dsr_sps[eg_eff_rate(p, p->fd1r)];
    c->feg_decay2_rate = aeg_dsr_sps[eg_eff_rate(p, p->fd2r)];
    c->feg_release_rate = aeg_dsr_sps[eg_eff_rate(p, p->frr)];
}

/* ---- the channel's step ----------------------------------------------- */

/* The gain for an attenuation (the reference's tl_lut, which is zero from
 * the entry 256 up). */
static int32_t lut_gain(uint32_t index)
{
    return (index < 256u) ? tl_lut[index] : 0;
}

/* One channel's contribution (the reference's ChannelEx::Step). */
static void channel_step(vf3_aica_mixer *mx, unsigned slot, int32_t *mixl, int32_t *mixr)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];
    const vf3_aica_channel *p = &mx->model->chan[slot];
    int32_t sample, oleft, oright, odsp;
    uint32_t ofsatt, max_att, dl, dr, ds;

    if (!c->enabled) return;

    /* the values the registers derive are refreshed before they are used */
    update_atts(mx, slot);
    update_aeg(mx, slot);
    update_feg(mx, slot);

    sample = interpolate(c) << 4;
    sample = low_pass_filter(mx, slot, sample);

    if (p->voff) {
        ofsatt = 0;
    } else {
        ofsatt = (uint32_t)c->lfo_alfo + (uint32_t)(aeg_get_value(c) >> 2);
        if (ofsatt > 255u) ofsatt = 255u;
    }
    max_att = 255u - ofsatt;

    dl = c->dl_att; if (dl > max_att) dl = max_att;
    dr = c->dr_att; if (dr > max_att) dr = max_att;
    ds = c->dsp_att; if (ds > max_att) ds = max_att;

    oleft = (int32_t)(((int64_t)sample * lut_gain(ofsatt + dl)) >> 19);
    oright = (int32_t)(((int64_t)sample * lut_gain(ofsatt + dr)) >> 19);
    odsp = (int32_t)(((int64_t)sample * lut_gain(ofsatt + ds)) >> 15);

    aeg_step(mx, slot);
    if (c->enabled) {
        feg_step(mx, slot);
        stream_step(mx, slot);
        lfo_step(mx, slot);
    }

    /* with the DSP off, a channel that is silent in both directions is
     * replaced by its send to the DSP, scaled down (the reference's
     * ChannelEx::Step(mixl, mixr)) */
    if (oleft + oright == 0) {
        oleft = odsp >> 4;
        oright = oleft;
    }
    *mixl += oleft;
    *mixr += oright;
}

/* ---- the mixer's own API ---------------------------------------------- */

void vf3_aica_mixer_init(vf3_aica_mixer *mx, vf3_aica_model *model)
{
    unsigned slot;

    build_tables();
    memset(mx, 0, sizeof *mx);
    mx->model = model;
    for (slot = 0; slot < VF3_AICA_SLOT_COUNT; ++slot) {
        vf3_aica_mixer_channel *c = &mx->chan[slot];
        c->aeg_state = VF3_AEG_ATTACK;
        c->feg_state = VF3_AEG_ATTACK;
        c->adpcm_quant = 127;
    }
}

vf3_aica_mixer_channel *vf3_aica_mixer_channel_state(vf3_aica_mixer *mx, unsigned slot)
{
    return &mx->chan[slot];
}

void vf3_aica_mixer_decode_all(vf3_aica_mixer *mx)
{
    unsigned slot;
    for (slot = 0; slot < VF3_AICA_SLOT_COUNT; ++slot)
        vf3_aica_decode(mx->model, slot);
}

void vf3_aica_mixer_channel_load(vf3_aica_mixer *mx, unsigned slot,
                                 const vf3_aica_mixer_channel *state)
{
    vf3_aica_mixer_channel *c = &mx->chan[slot];

    *c = *state;
    /* the values the mixer derives from the registers follow the load */
    update_atts(mx, slot);
    update_aeg(mx, slot);
    update_feg(mx, slot);
    /* the LFO's countdown comes from the state, so it is not restarted */
    update_lfo(mx, slot, 1);
}

/* The key-on trigger: the hardware starts the channels whose key-on bit is
 * set and releases the others (the reference's RegWrite, case 0x00/0x01). */
static void key_trigger(vf3_aica_mixer *mx)
{
    unsigned slot;

    for (slot = 0; slot < VF3_AICA_SLOT_COUNT; ++slot) {
        vf3_aica_decode(mx->model, slot);
        if (mx->model->chan[slot].kyonb) key_on(mx, slot);
        else key_off(mx, slot);
    }
}

void vf3_aica_mixer_write(vf3_aica_mixer *mx, uint32_t offset, uint32_t value,
                          unsigned size)
{
    unsigned slot, within;

    vf3_aica_write_bytes(mx->model, offset, value, size);
    if (offset >= VF3_AICA_REG_SIZE) return;

    slot = (unsigned)(offset / VF3_AICA_SLOT_STRIDE);
    within = (unsigned)(offset % VF3_AICA_SLOT_STRIDE);
    if (slot >= VF3_AICA_SLOT_COUNT) {
        /* the common area: the mixer reads the master's volume from it */
        return;
    }

    vf3_aica_decode(mx->model, slot);

    /* the sample's address (the reference's UpdateSA) */
    if (within == 0x00u) update_sa(mx, slot);
    else if (within == 0x01u) { if (size == 2u) update_sa(mx, slot); }
    else if (within == 0x04u || within == 0x05u) update_sa(mx, slot);

    /* the key-on trigger: the hardware takes it when a write reaches the
     * slot's second byte, and clears it before it starts the channels */
    if ((within == 1u || (within == 0u && size == 2u)) && mx->model->chan[slot].kyonex) {
        mx->model->reg[slot * VF3_AICA_SLOT_STRIDE + 1u] &= (uint8_t)~0x80u;
        key_trigger(mx);
    }

    /* the LFO's registers restart the LFO */
    if (within == 0x1Cu || within == 0x1Du) update_lfo(mx, slot, 0);
}

void vf3_aica_mixer_sample(vf3_aica_mixer *mx, int16_t *right, int16_t *left)
{
    int32_t mixl = 0, mixr = 0;
    const uint8_t *common = mx->model->reg + 0x2800u;
    int32_t mvol;
    unsigned slot;

    for (slot = 0; slot < VF3_AICA_SLOT_COUNT; ++slot)
        channel_step(mx, slot, &mixl, &mixr);

    /* the mono mode sums the two channels into one */
    if (common[1] & 0x80u) mixl = mixr = (mixl + mixr) >> 1;

    /* the master's volume */
    mvol = volume_lut[common[0] & 0x0Fu];
    mixl = (int32_t)(((int64_t)mixl * mvol) >> 15);
    mixr = (int32_t)(((int64_t)mixr * mvol) >> 15);

    /* the 18-bit output is scaled down to 16 bits */
    if (common[1] & 0x01u) {
        mixl >>= 2;
        mixr >>= 2;
    }

    if (mixl < -32768) mixl = -32768;
    else if (mixl > 32767) mixl = 32767;
    if (mixr < -32768) mixr = -32768;
    else if (mixr > 32767) mixr = 32767;

    *right = (int16_t)mixr;
    *left = (int16_t)mixl;
}
