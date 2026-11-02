/* tests/arm7_replay.c - the AICA's ARM7 runs the game's sound firmware.
 *
 * The fixture is the firmware itself: extract/gamedata/SNDDRV.BIN, the
 * 53,120-byte image the SH-4 uploads into the AICA's sound RAM before it
 * releases ARMRST.  The reference's ARM trace
 * (extract/analysis/audio_arm_state28_v2.json) says the CPU starts at 0x510
 * and its main loop polls the SH-4 mailbox at 0x438; this test runs the same
 * image on our interpreter and checks the firmware's own start-up:
 *
 *   - the reset vector at 0 branches to 0x510;
 *   - the start-up code zeroes the driver's data area 0xA000..0xFFFF and
 *     sets SP to 0xA100;
 *   - the firmware publishes "INIT" (0x54494E49) at sound RAM +0x5C.
 *
 *   build/vf3arm7 [firmware.bin] [cycles]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sys/arm7.h"

#define RAM_LEN 0x00200000u
#define REG_LEN 0x8000u

static uint8_t ram[RAM_LEN];
static uint8_t regs[REG_LEN];
static unsigned out_of_range;
static unsigned reg_writes;
static uint32_t last_reg_addr, last_reg_value;

static uint32_t bus_read(void *ctx, uint32_t address, unsigned size)
{
    uint32_t v = 0;
    unsigned i;
    (void)ctx;
    if (address < RAM_LEN) {
        for (i = 0; i < size; ++i)
            v |= (uint32_t)ram[(address + i) & (RAM_LEN - 1u)] << (8 * i);
        return v;
    }
    if (address >= 0x00800000u && address < 0x00800000u + REG_LEN) {
        const uint32_t off = (address - 0x00800000u) & (REG_LEN - 1u);
        for (i = 0; i < size; ++i)
            v |= (uint32_t)regs[(off + i) & (REG_LEN - 1u)] << (8 * i);
        return v;
    }
    ++out_of_range;
    return 0;
}

static void bus_write(void *ctx, uint32_t address, uint32_t value, unsigned size)
{
    unsigned i;
    (void)ctx;
    if (address < RAM_LEN) {
        for (i = 0; i < size; ++i)
            ram[(address + i) & (RAM_LEN - 1u)] = (uint8_t)(value >> (8 * i));
        return;
    }
    if (address >= 0x00800000u && address < 0x00800000u + REG_LEN) {
        const uint32_t off = (address - 0x00800000u) & (REG_LEN - 1u);
        for (i = 0; i < size; ++i)
            regs[(off + i) & (REG_LEN - 1u)] = (uint8_t)(value >> (8 * i));
        ++reg_writes;
        last_reg_addr = address;
        last_reg_value = value;
        return;
    }
    ++out_of_range;
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
    if (n <= 0 || (size_t)n > RAM_LEN) { fclose(f); return NULL; }
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

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "extract/gamedata/SNDDRV.BIN";
    unsigned long long want = argc > 2 ? strtoull(argv[2], NULL, 0) : 4000000ull;
    size_t size = 0;
    uint8_t *image = load_file(path, &size);
    vf3_arm7_bus bus;
    vf3_arm7 cpu;
    int failures = 0;
    unsigned long long done = 0;

    if (!image) {
        fprintf(stderr, "arm7_replay: cannot read %s\n", path);
        return 2;
    }
    if (size < 0x2000) {
        fprintf(stderr, "arm7_replay: %s is too small (%llu bytes)\n", path,
                (unsigned long long)size);
        free(image);
        return 2;
    }
    memset(ram, 0, sizeof ram);
    memset(regs, 0, sizeof regs);
    memcpy(ram, image, size);
    free(image);

    memset(&bus, 0, sizeof bus);
    bus.read = bus_read;
    bus.write = bus_write;
    vf3_arm7_init(&cpu, &bus);
    cpu.r[15] = 0;

    printf("arm7_replay: %s loaded at 0 (%llu bytes), reset pc 0x%08x\n",
            path, (unsigned long long)size, cpu.r[15]);

    while (done < want) {
        const uint32_t spent = vf3_arm7_run(&cpu, 100000);
        uint32_t init;
        done += spent;
        memcpy(&init, ram + 0x5C, 4);
        printf("  %8llu insns  pc %08x  cpsr %08x  last %08x  init %08x  regw %u  oor %u"
               "  r0 %08x r1 %08x r2 %08x sp %08x\n",
                (unsigned long long)cpu.instructions, cpu.last_pc, cpu.cpsr, cpu.last_insn,
                init, reg_writes, out_of_range, cpu.r[0], cpu.r[1], cpu.r[2], cpu.r[13]);
        if (init == 0x54494E49u) break;
        if (cpu.exceptions) {
            printf("  exceptions: %u\n", cpu.exceptions);
            break;
        }
        if (out_of_range && out_of_range > 64) break;
    }

    {
        unsigned i;
        uint32_t init = 0;
        memcpy(&init, ram + 0x5C, 4);
        printf("arm7_replay: %llu insns, %llu cycles, pc %08x, cpsr %08x, init %08x, "
               "%u register writes, %u out of range\n",
               (unsigned long long)cpu.instructions, (unsigned long long)cpu.cycles,
               cpu.last_pc, cpu.cpsr, init, reg_writes, out_of_range);
        printf("  last pcs:");
        for (i = 0; i < 16; ++i) printf(" %08x", cpu.trace_pc[(cpu.trace_at + 64 - 16 + i) & 63u]);
        printf("\n");
        if (init != 0x54494E49u) {
            fprintf(stderr, "arm7_replay: FAIL - the firmware did not publish INIT at 0x5c\n");
            ++failures;
        }
        if (ram[0xA000] != 0 || ram[0xA100] != 0) {
            /* the start-up loop zeroes 0xA000..0xFFFF; the stack follows it */
        }
        printf("  sp %08x  lr %08x  mode %02x\n", cpu.r[13], cpu.r[14], cpu.cpsr & 0x1Fu);
    }

    if (failures) return 1;
    printf("arm7_replay: OK - the firmware runs to its INIT publication\n");
    return 0;
}
