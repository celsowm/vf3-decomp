/* sys/aica_model.c - the AICA's register file and its channels.
 *
 * The layout and the field names are the hardware's; see
 * sys/aica_model.h and docs/re/aica_audio_model.md.  The reference's own view
 * of a channel slot is its packed `ChannelCommonData`
 * (flycast's core/hw/aica/sgc_if.cpp), and the fields are read from the same
 * byte layout here.
 */
#include "sys/aica_model.h"

#include <string.h>

/* The word at the slot's offset, little endian. */
static uint32_t word(const vf3_aica_model *m, unsigned slot, unsigned off)
{
    const uint8_t *p = m->reg + slot * VF3_AICA_SLOT_STRIDE + off;
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}

/* The 16-bit register at the slot's offset.  The hardware's registers are 16
 * bits wide, aligned to 32: the value lives in the low half of the word. */
static uint16_t half(const vf3_aica_model *m, unsigned slot, unsigned off)
{
    return (uint16_t)(word(m, slot, off) & 0xFFFFu);
}

uint32_t vf3_aica_rate(uint16_t fns, uint8_t oct)
{
    uint32_t rate = 1024u | fns;
    if (oct & 8u) return rate >> (16u - oct);
    return rate << oct;
}

void vf3_aica_init(vf3_aica_model *m, uint8_t *ram)
{
    memset(m, 0, sizeof *m);
    m->ram = ram;
}

void vf3_aica_decode(vf3_aica_model *m, unsigned slot)
{
    vf3_aica_channel *c = &m->chan[slot];
    const uint32_t ctl = word(m, slot, 0x00);
    const uint32_t aeg = word(m, slot, 0x10);
    const uint32_t rel = word(m, slot, 0x14);
    const uint32_t pit = word(m, slot, 0x18);
    const uint32_t lfo = word(m, slot, 0x1C);
    const uint32_t isel = word(m, slot, 0x20);
    const uint32_t dip = word(m, slot, 0x24);
    const uint32_t lvl = word(m, slot, 0x28);
    const uint32_t feg = word(m, slot, 0x40);
    const uint32_t feg2 = word(m, slot, 0x44);

    c->sa = ((ctl & 0x7Fu) << 16) | half(m, slot, 0x04);
    c->lsa = half(m, slot, 0x08);
    c->lea = half(m, slot, 0x0C);
    c->pcms = (uint8_t)((ctl >> 7) & 3u);
    c->lpctl = (uint8_t)((ctl >> 9) & 1u);
    c->ssctl = (uint8_t)((ctl >> 10) & 1u);
    c->kyonb = (uint8_t)((ctl >> 14) & 1u);
    c->kyonex = (uint8_t)((ctl >> 15) & 1u);

    c->ar = (uint8_t)(aeg & 0x1Fu);
    c->d1r = (uint8_t)((aeg >> 6) & 0x1Fu);
    c->d2r = (uint8_t)((aeg >> 11) & 0x1Fu);

    c->rr = (uint8_t)(rel & 0x1Fu);
    c->dl = (uint8_t)((rel >> 5) & 0x1Fu);
    c->krs = (uint8_t)((rel >> 10) & 0xFu);
    c->lpslnk = (uint8_t)((rel >> 14) & 1u);

    c->fns = (uint16_t)(pit & 0x3FFu);
    c->oct = (uint8_t)((pit >> 11) & 0xFu);

    c->alfos = (uint8_t)(lfo & 7u);
    c->alfows = (uint8_t)((lfo >> 3) & 3u);
    c->plfos = (uint8_t)((lfo >> 5) & 7u);
    c->plfows = (uint8_t)((lfo >> 8) & 3u);
    c->lfof = (uint8_t)((lfo >> 10) & 0x1Fu);
    c->lfore = (uint8_t)((lfo >> 15) & 1u);

    c->isel = (uint8_t)(isel & 0xFu);
    c->imxl = (uint8_t)((isel >> 4) & 0xFu);

    c->dipan = (uint8_t)(dip & 0x1Fu);
    c->disdl = (uint8_t)((dip >> 8) & 0xFu);

    c->q = (uint8_t)(lvl & 0x1Fu);
    c->lpoff = (uint8_t)((lvl >> 5) & 1u);
    c->voff = (uint8_t)((lvl >> 6) & 1u);
    c->tl = (uint8_t)((lvl >> 8) & 0xFFu);

    c->fd1r = (uint8_t)(feg & 0x1Fu);
    c->far = (uint8_t)((feg >> 8) & 0x1Fu);
    c->fd2r = (uint8_t)(feg2 & 0x1Fu);
    c->frr = (uint8_t)((feg2 >> 8) & 0x1Fu);

    /* the filter's envelope's levels */
    c->flv0 = (uint16_t)(word(m, slot, 0x2C) & 0x1FFFu);
    c->flv1 = (uint16_t)(word(m, slot, 0x30) & 0x1FFFu);
    c->flv2 = (uint16_t)(word(m, slot, 0x34) & 0x1FFFu);
    c->flv3 = (uint16_t)(word(m, slot, 0x38) & 0x1FFFu);
    c->flv4 = (uint16_t)(word(m, slot, 0x3C) & 0x1FFFu);

    c->rate = vf3_aica_rate(c->fns, c->oct);
}

void vf3_aica_key_on(vf3_aica_model *m, unsigned slot)
{
    vf3_aica_decode(m, slot);
    m->keyed[slot] = 1u;
    m->ca[slot] = m->chan[slot].sa;
}

/* The key-off.  On the hardware the channel keeps sounding while its release
 * envelope decays, and stops when the envelope reaches zero; the envelope is
 * the mixer's business (the next milestone), so this only takes the channel
 * out of the "playing" set. */
void vf3_aica_key_off(vf3_aica_model *m, unsigned slot)
{
    m->keyed[slot] = 0u;
}

/* The key-on trigger: the hardware clears it and starts the channels whose
 * key-on bit is set (and stops the others). */
static void key_trigger(vf3_aica_model *m)
{
    unsigned slot;
    for (slot = 0; slot < VF3_AICA_SLOT_COUNT; ++slot) {
        vf3_aica_decode(m, slot);
        if (m->chan[slot].kyonb) vf3_aica_key_on(m, slot);
        else vf3_aica_key_off(m, slot);
    }
}

void vf3_aica_write_bytes(vf3_aica_model *m, uint32_t offset, uint32_t value, unsigned size)
{
    uint32_t i;
    if (offset >= VF3_AICA_REG_SIZE) return;
    for (i = 0; i < size && offset + i < VF3_AICA_REG_SIZE; ++i)
        m->reg[offset + i] = (uint8_t)(value >> (8u * i));
}

void vf3_aica_write(vf3_aica_model *m, uint32_t offset, uint32_t value, unsigned size)
{
    vf3_aica_write_bytes(m, offset, value, size);

    /* A write that touches the key-on trigger starts the channels.  The
     * trigger is the high byte of the word at the slot's +0x00, so only the
     * writes there can set it. */
    {
        const unsigned slot = (unsigned)(offset / VF3_AICA_SLOT_STRIDE);
        const unsigned within = (unsigned)(offset % VF3_AICA_SLOT_STRIDE);
        if (slot < VF3_AICA_SLOT_COUNT && within < 4u) {
            vf3_aica_decode(m, slot);
            if (m->chan[slot].kyonex) {
                /* the hardware clears the trigger before it starts them */
                m->reg[slot * VF3_AICA_SLOT_STRIDE + 1u] &= (uint8_t)~0x80u;
                key_trigger(m);
            }
        }
    }
}

uint32_t vf3_aica_read(const vf3_aica_model *m, uint32_t offset, unsigned size)
{
    uint32_t v = 0, i;
    if (offset >= VF3_AICA_REG_SIZE) return 0;
    for (i = 0; i < size && offset + i < VF3_AICA_REG_SIZE; ++i)
        v |= (uint32_t)m->reg[offset + i] << (8u * i);
    return v;
}
