/* tests/aica_model_replay.c - the AICA's register file, as the hardware reads
 * it.
 *
 * The fixture is the reference's own ARM trace: the writes the ARM7 made into
 * the AICA's register file in the fight states
 * (extract/analysis/audio_arm_state28_v2.json).  Four channels are enough to
 * cover what the driver does:
 *
 *   - slot 0:  a PCM8 voice, playing;
 *   - slot 18: a PCM16 voice, playing;
 *   - slot 26: an ADPCM voice, playing;
 *   - slot 17: a channel the driver silences (the total level 0xFF) and that
 *              carries the key-on trigger for the others.
 *
 * The decoder itself is checked against the whole trace by
 * tools/aica_voice_regs.py, which prints the same table from the trace.
 *
 *   build/vf3aica
 */
#include <stdio.h>
#include <string.h>

#include "sys/aica_model.h"

static int failures;

static void expect(const char *what, unsigned long got, unsigned long want)
{
    if (got == want) return;
    fprintf(stderr, "aica_model_replay: FAIL - %s: %lu, want %lu\n", what, got, want);
    ++failures;
}

struct write {
    unsigned char off;
    unsigned char size;
    unsigned long value;
};

/* The writes the ARM7 made into slot 0's registers (a PCM8 voice). */
static const struct write slot0[] = {
    {0x10, 4, 0x0000421fu}, {0x14, 4, 0x000002b1u}, {0x1c, 4, 0x0000bc00u},
    {0x28, 1, 0x00000020u}, {0x24, 1, 0x00000000u}, {0x25, 1, 0x0000000au},
    {0x20, 1, 0x00000061u}, {0x04, 4, 0x00006660u}, {0x00, 4, 0x00000297u},
    {0x08, 4, 0x00004f64u}, {0x0c, 4, 0x00008492u}, {0x18, 4, 0x0000738du},
    {0x29, 1, 0x00000014u}, {0x01, 1, 0x00000042u}, {0x1d, 1, 0x0000003cu},
    {0x01, 1, 0x000000c2u},
};

/* Slot 18: a PCM16 voice. */
static const struct write slot18[] = {
    {0x10, 4, 0x0000001fu}, {0x14, 4, 0x0000001fu}, {0x1c, 4, 0x00008000u},
    {0x28, 1, 0x00000020u}, {0x24, 1, 0x0000000cu}, {0x25, 1, 0x0000000du},
    {0x20, 1, 0x00000060u}, {0x04, 4, 0x0000ce34u}, {0x00, 4, 0x0000000au},
    {0x08, 4, 0x00000000u}, {0x0c, 4, 0x0000de7eu}, {0x18, 4, 0x0000003du},
    {0x29, 1, 0x0000001du}, {0x01, 1, 0x00000040u}, {0x1d, 1, 0x00000000u},
    {0x01, 1, 0x000000c0u},
};

/* Slot 26: an ADPCM voice. */
static const struct write slot26[] = {
    {0x10, 4, 0x0000001fu}, {0x14, 4, 0x0000001fu}, {0x1c, 4, 0x0000bc00u},
    {0x28, 1, 0x00000020u}, {0x24, 1, 0x00000000u}, {0x25, 1, 0x0000000du},
    {0x20, 1, 0x00000000u}, {0x04, 4, 0x0000d95eu}, {0x00, 4, 0x00000316u},
    {0x08, 4, 0x000023e4u}, {0x0c, 4, 0x000035ceu}, {0x18, 4, 0x0000705cu},
    {0x29, 1, 0x0000000cu}, {0x01, 1, 0x00000043u}, {0x1d, 1, 0x0000003cu},
    {0x01, 1, 0x000000c3u},
};

/* Slot 17: the channel the driver silences, and the one that carries the
 * key-on trigger. */
static const struct write slot17[] = {
    {0x29, 1, 0x000000ffu}, {0x28, 1, 0x00000020u}, {0x40, 4, 0x00001f1fu},
    {0x44, 4, 0x00001f1fu}, {0x14, 4, 0x00003c1fu}, {0x01, 1, 0x00000080u},
    {0x00, 4, 0x00000000u}, {0x04, 4, 0x00000000u}, {0x08, 4, 0x00000000u},
    {0x0c, 4, 0x00000000u}, {0x18, 4, 0x00000000u}, {0x1c, 4, 0x00000000u},
    {0x20, 4, 0x00000000u}, {0x24, 4, 0x00000000u},
};

static void apply(vf3_aica_model *m, unsigned slot, const struct write *w, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; ++i)
        vf3_aica_write(m, slot * VF3_AICA_SLOT_STRIDE + w[i].off,
                       (uint32_t)w[i].value, w[i].size);
}

int main(void)
{
    static uint8_t ram[VF3_AICA_RAM_SIZE];
    vf3_aica_model m;
    const vf3_aica_channel *c;

    vf3_aica_init(&m, ram);

    /* slot 0: the PCM8 voice */
    apply(&m, 0, slot0, sizeof slot0 / sizeof *slot0);
    c = &m.chan[0];
    expect("slot 0: the sample format", c->pcms, VF3_AICA_PCM8);
    expect("slot 0: the sample address", c->sa, 0x176660u);
    expect("slot 0: the loop start", c->lsa, 0x4f64u);
    expect("slot 0: the loop end", c->lea, 0x8492u);
    expect("slot 0: the attack rate", c->ar, 31u);
    expect("slot 0: the decay 1 rate", c->d1r, 8u);
    expect("slot 0: the decay 2 rate", c->d2r, 8u);
    expect("slot 0: the release rate", c->rr, 17u);
    expect("slot 0: the decay level", c->dl, 21u);
    expect("slot 0: the frequency number", c->fns, 909u);
    expect("slot 0: the octave", c->oct, 14u);
    expect("slot 0: the playback rate", c->rate, 483u);
    expect("slot 0: the total level", c->tl, 20u);
    expect("slot 0: the digital pan", c->dipan, 0u);
    expect("slot 0: the direct send level", c->disdl, 10u);
    expect("slot 0: the input selector", c->isel, 1u);
    expect("slot 0: the send level", c->imxl, 6u);
    expect("slot 0: the key-on bit", c->kyonb, 1u);
    expect("slot 0: the key-on trigger is cleared", c->kyonex, 0u);
    expect("slot 0: the channel is on", m.keyed[0], 1u);
    expect("slot 0: the current address", m.ca[0], 0x176660u);

    /* slot 18: the PCM16 voice */
    apply(&m, 18, slot18, sizeof slot18 / sizeof *slot18);
    c = &m.chan[18];
    expect("slot 18: the sample format", c->pcms, VF3_AICA_PCM16);
    expect("slot 18: the sample address", c->sa, 0x0ace34u);
    expect("slot 18: the loop end", c->lea, 0xde7eu);
    expect("slot 18: the frequency number", c->fns, 61u);
    expect("slot 18: the octave", c->oct, 0u);
    expect("slot 18: the playback rate", c->rate, 1085u);
    expect("slot 18: the total level", c->tl, 29u);
    expect("slot 18: the digital pan", c->dipan, 12u);
    expect("slot 18: the direct send level", c->disdl, 13u);
    expect("slot 18: the channel is on", m.keyed[18], 1u);

    /* slot 26: the ADPCM voice */
    apply(&m, 26, slot26, sizeof slot26 / sizeof *slot26);
    c = &m.chan[26];
    expect("slot 26: the sample format", c->pcms, VF3_AICA_ADPCM);
    expect("slot 26: the sample address", c->sa, 0x16d95eu);
    expect("slot 26: the loop start", c->lsa, 0x23e4u);
    expect("slot 26: the loop end", c->lea, 0x35ceu);
    expect("slot 26: the frequency number", c->fns, 92u);
    expect("slot 26: the octave", c->oct, 14u);
    expect("slot 26: the playback rate", c->rate, 279u);
    expect("slot 26: the total level", c->tl, 12u);
    expect("slot 26: the channel is on", m.keyed[26], 1u);

    /* slot 17: the silenced channel, and the trigger that starts the others */
    apply(&m, 17, slot17, sizeof slot17 / sizeof *slot17);
    c = &m.chan[17];
    expect("slot 17: the total level", c->tl, 0xffu);
    expect("slot 17: the key-on bit", c->kyonb, 0u);
    expect("slot 17: the channel is off", m.keyed[17], 0u);
    expect("slot 17: the filter's attack rate", c->far, 31u);
    expect("slot 17: the filter's release rate", c->frr, 31u);
    /* the trigger starts every channel whose key-on bit is set */
    expect("slot 0 is still on", m.keyed[0], 1u);
    expect("slot 18 is still on", m.keyed[18], 1u);
    expect("slot 26 is still on", m.keyed[26], 1u);

    /* the register file keeps the bytes the driver wrote - except the key-on
     * trigger, which the hardware clears when it starts the channels (the
     * word at +0x00 was 0xC297, the trigger is its bit 15) */
    expect("the register file: slot 0's pitch",
           vf3_aica_read(&m, 0 * VF3_AICA_SLOT_STRIDE + 0x18, 4), 0x738du);
    expect("the register file: slot 0's total level",
           vf3_aica_read(&m, 0 * VF3_AICA_SLOT_STRIDE + 0x28, 2), 0x1420u);
    expect("the register file: slot 0's key byte",
           vf3_aica_read(&m, 0 * VF3_AICA_SLOT_STRIDE + 0x00, 2), 0x4297u);

    if (failures) {
        fprintf(stderr, "aica_model_replay: %d check(s) failed\n", failures);
        return 1;
    }
    printf("aica_model_replay: the AICA's register file reads as the driver wrote it\n");
    return 0;
}
