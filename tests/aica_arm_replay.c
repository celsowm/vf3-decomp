/* tests/aica_arm_replay.c - the AICA's ARM7 and the chip around it.
 *
 * The fixture is the game's own sound firmware, extract/gamedata/SNDDRV.BIN,
 * the 53,120-byte image the SH-4 uploads into the sound RAM.  The test runs
 * it on the ARM7 interpreter through the chip model (sys/aica_arm.c):
 *
 *   - the release runs the firmware to its "INIT" publication at sound RAM
 *     +0x5C, which is the word the guest's loader polls;
 *   - after the release, the timers run once per sample and Timer B - the
 *     firmware's own tick, enabled in SCIEB - raises its bit in SCIPD, the
 *     e68k latch picks it up, the ARM7 takes the FIQ at 0x1C and the handler
 *     accepts it through REG_M (so the latch clears and comes back on the
 *     next wrap);
 *   - the interrupt registers keep the hardware's read-only and
 *     write-one-to-clear behaviour.
 *
 *   build/vf3aicaarm [firmware.bin]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sys/aica_arm.h"
#include "sys/aica_mixer.h"
#include "sys/aica_model.h"

#define RAM_LEN 0x00200000u
#define FIRMWARE_MAX 0x00100000u

static uint8_t ram[RAM_LEN];
static vf3_aica_model model;
static vf3_aica_mixer mixer;
static unsigned failures;

static int expect(int ok, const char *what)
{
    printf("  %-72s %s\n", what, ok ? "PASS" : "FAIL");
    if (!ok) ++failures;
    return ok;
}

static uint8_t *load_file(const char *path, size_t *size)
{
    FILE *f = fopen(path, "rb");
    uint8_t *data;
    long n;

    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (n <= 0 || (size_t)n > FIRMWARE_MAX) { fclose(f); return NULL; }
    data = (uint8_t *)malloc((size_t)n);
    if (!data || fread(data, 1, (size_t)n, f) != (size_t)n) {
        free(data);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *size = (size_t)n;
    return data;
}

static uint32_t reg_word(uint32_t offset)
{
    uint32_t v = 0;
    memcpy(&v, model.reg + offset, 4);
    return v;
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "extract/gamedata/SNDDRV.BIN";
    size_t size = 0;
    uint8_t *image;
    vf3_aica_arm arm;
    unsigned i;

    image = load_file(path, &size);
    if (!image) {
        fprintf(stderr, "aica_arm_replay: cannot read %s\n", path);
        return 2;
    }
    printf("aica_arm_replay: %s (%llu bytes)\n", path,
           (unsigned long long)size);
    memset(ram, 0, sizeof ram);
    memcpy(ram, image, size);
    free(image);

    vf3_aica_init(&model, ram);
    vf3_aica_mixer_init(&mixer, &model);
    vf3_aica_arm_init(&arm, &model, &mixer);

    /* ---- the release: the firmware publishes INIT ---------------------- */
    if (!expect(vf3_aica_arm_release(&arm, 40000000u) == 1,
                "the firmware publishes INIT at sound RAM + 0x5C")) {
        return 1;
    }
    printf("  release: %llu instructions, %llu cycles, %llu samples, "
           "%llu register writes, pc %08x\n",
           (unsigned long long)arm.cpu.instructions,
           (unsigned long long)arm.cpu.cycles,
           (unsigned long long)arm.samples,
           (unsigned long long)arm.reg_writes, arm.cpu.last_pc);
    expect(vf3_aica_arm_word(&arm, 0x5C) == 0x54494E49u,
           "the INIT word survives as the driver left it");
    printf("  sound RAM +0x88 = %08x (the free-size limit)\n",
           vf3_aica_arm_word(&arm, 0x88));
    expect(arm.cpu.r[13] >= 0x8000u && arm.cpu.r[13] < RAM_LEN,
           "the firmware's stack is inside the sound RAM");

    /* ---- the timers, the latch and the FIQ ----------------------------- */
    {
        const uint32_t scy = reg_word(0x289Cu);      /* SCIEB */
        const uint32_t mcieb = reg_word(0x28B4u);    /* MCIEB */
        printf("  SCIEB %08x  MCIEB %08x\n", scy, mcieb);
        expect((scy & 0x80u) != 0, "the firmware enables Timer B in SCIEB");
        expect((scy & 0x08u) != 0, "the firmware enables MIDI-IN in SCIEB");
        expect((reg_word(0x2894u) & 0xFFFFFF00u) == 0,
               "Timer B's count runs with the prescaler md = 0");
    }
    {
        const unsigned before = arm.fiq_count;
        for (i = 0; i < 2000; ++i) {
            int16_t r = 0, l = 0;
            vf3_aica_arm_sample(&arm, &r, &l);
        }
        printf("  after 2000 samples: fiq %u, latch %d, sci pd %08x, "
               "pc %08x, reg writes %llu\n",
               arm.fiq_count, arm.e68k_out, reg_word(0x28A0u),
               arm.cpu.last_pc, (unsigned long long)arm.reg_writes);
        expect(arm.fiq_count > before, "Timer B's wrap raises the FIQ");
        expect((reg_word(0x28A0u) & 0x80u) == 0,
               "the FIQ handler clears Timer B in SCIPD (a SCIRE write)");
        expect(arm.e68k_out == 0,
               "the FIQ handler accepts the interrupt through REG_M");
        expect(arm.samples >= 2000u,
               "the sample counter keeps stepping");
        expect(arm.cpu.last_pc < size,
               "the ARM7 is executing the firmware, not empty RAM");
    }

    /* ---- the interrupt registers' read/write rules --------------------- */
    {
        vf3_aica_arm fresh;
        const uint32_t pending_before = reg_word(0x28A0u);
        vf3_aica_arm_init(&fresh, &model, &mixer);
        vf3_aica_arm_note_write(&fresh, 0x28A0u, 0x0000FFDFu, 4);
        expect(reg_word(0x28A0u) == pending_before,
               "SCIPD ignores writes of the hardware-owned bits");
        vf3_aica_arm_note_write(&fresh, 0x28A0u, 0x00000020u, 4);
        expect((reg_word(0x28A0u) & 0x20u) != 0,
               "SCIPD takes the SCPU bit the CPU may write");
        vf3_aica_arm_note_write(&fresh, 0x28A4u, 0x00000020u, 4);
        expect((reg_word(0x28A0u) & 0x20u) == 0,
               "SCIRE clears the bit it is written with");

        /* Timer B: a count of 0xFE wraps to zero after two samples, sets its
         * bit in SCIPD, and the enabled bit raises the e68k latch (the ARM7's
         * FIQ line).  The latch survives a cleared SCIRE until REG_M accepts
         * it - that is the reference's e68k_out. */
        vf3_aica_arm_note_write(&fresh, 0x289Cu, 0x00000080u, 4);  /* SCIEB */
        vf3_aica_arm_note_write(&fresh, 0x2894u, 0x000000FEu, 4);  /* Timer B */
        {
            int16_t r = 0, l = 0;
            vf3_aica_arm_sample(&fresh, &r, &l);
        }
        expect((reg_word(0x28A0u) & 0x80u) == 0,
               "Timer B does not raise its bit before it wraps");
        {
            int16_t r = 0, l = 0;
            vf3_aica_arm_sample(&fresh, &r, &l);
        }
        expect((reg_word(0x28A0u) & 0x80u) != 0,
               "Timer B raises its bit when its count wraps");
        expect(fresh.e68k_out == 1,
               "the enabled bit reaches the e68k latch (the FIQ line)");
        vf3_aica_arm_note_write(&fresh, 0x28A4u, 0x00000080u, 4);  /* SCIRE */
        expect((reg_word(0x28A0u) & 0x80u) == 0,
               "SCIRE clears Timer B's pending bit");
        expect(fresh.e68k_out == 1,
               "the latch holds until the CPU accepts it through REG_M");
    }

    if (failures) {
        printf("aica_arm_replay: %u FAIL\n", failures);
        return 1;
    }
    printf("aica_arm_replay: OK\n");
    return 0;
}
