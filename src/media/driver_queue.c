/* SNDDRV.BIN 0x65c..0x728 and 0x2454..0x2470: A0 mailbox handoff.
 * The SH-4 posts a little-endian word at 0x400. The ARM consumer reverses
 * its bytes, sets bit 6, and appends it to the internal 0xa400 ring.
 * Later command dispatch and voice register writes remain unrecovered.
 * Runtime evidence: nine ordered handoffs in audio_arm_observer_v2 state26.
 * This is a protocol operation, not an instruction/cycle emulator. */
#include "driver_queue.h"

int vf3_driver_handoff_a0(const vf3_driver_memory *m)
{
    uint32_t pop,word,confirmed,forward,swapped;
    unsigned byte;
    if (!m || !m->read32 || !m->write32 || !m->write8)
        return VF3_DRIVER_INVALID_INPUT;
    pop=m->read32(m->context,0x44);
    if ((pop&3) || pop>=0x100) return VF3_DRIVER_INVALID_INPUT;
    word=m->read32(m->context,0x400+pop);
    if (!word) return VF3_DRIVER_EMPTY;
    confirmed=m->read32(m->context,0x400+pop);
    /* The original unequal-read branch consumes the second value. This
     * bounded operation accepts only the observed A0 class; callers retain
     * ownership of unsupported values, without any publication. */
    if ((confirmed&255)!=0xa0) return VF3_DRIVER_UNSUPPORTED;
    forward=m->read32(m->context,0xa210);
    if ((forward&3) || forward>=0x400) return VF3_DRIVER_INVALID_INPUT;
    m->write32(m->context,0x48,confirmed);
    m->write32(m->context,0x400+pop,0);
    m->write32(m->context,0x44,pop+4==0x100?0:pop+4);
    swapped=0;
    for (byte=0;byte<4;++byte) {
        uint8_t value=(uint8_t)(confirmed>>(8*byte));
        m->write8(m->context,0x4f-byte,value);
        swapped|=(uint32_t)value<<(24-8*byte);
    }
    m->write32(m->context,0xa400+forward,swapped|0x40);
    m->write32(m->context,0xa210,forward+4==0x400?0:forward+4);
    return VF3_DRIVER_HANDED_OFF;
}
