/* Compare the native selector with its retained instruction translation. */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "terrain_region.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_advance_worker_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);

#define BASE 0x0c010000u
#define SIZE 0x100000u
#define GLOBAL 0x0c020000u
#define OWNER 0x0c021000u
#define RECORDS 0x0c022000u

static void put32(unsigned char *p, uint32_t addr, uint32_t v)
{ memcpy(p + addr - BASE, &v, 4); }
static void put16(unsigned char *p, uint32_t addr, uint16_t v)
{ memcpy(p + addr - BASE, &v, 2); }
static void putf(unsigned char *p, uint32_t addr, float f)
{ put32(p, addr, vf3_aim_ubits(f)); }

static int run(unsigned scenario, uint32_t fpscr)
{
    unsigned char *guest = calloc(1, SIZE), *native = calloc(1, SIZE);
    if (!guest || !native) exit(2);
    put32(guest, 0x0c087b60u, GLOBAL);
    put16(guest, 0x0c087b56u, 12);
    put16(guest, 0x0c087b58u, 16);
    put16(guest, 0x0c087b5au, 0);
    put16(guest, 0x0c087b5cu, 32);
    putf(guest, 0x0c087b64u, 0.5f);
    putf(guest, 0x0c087b68u, 0.0f);
    putf(guest, 0x0c087b6cu, 0.0f);
    put32(guest, GLOBAL, OWNER);
    put32(guest, OWNER + 12, scenario ? RECORDS : 0);
    for (unsigned i = 0; i < 8; ++i) {
        uint32_t p = RECORDS + 16 + 32 * i;
        putf(guest, p, 2.0f); putf(guest, p + 4, 2.0f);
        putf(guest, p + 8, (float)i * 4.0f);
        putf(guest, p + 16, 0.0f);
    }
    memcpy(native, guest, SIZE);
    vf3_ram_win win = {0}; win.base = BASE; win.len = SIZE; win.data = guest;
    vf3_ram_map map = {0}; map.wins = &win; map.n = 1;
    vf3_matrix_state s = {0};
    vf3_native_aim a = {0}; a.ram = (float *)native; a.ram_base = BASE;
    for (unsigned i = 0; i < 16; ++i) {
        s.v[i] = a.r[i] = 0x12340000u + i;
        s.v[VF3_REG_FR0 + i] = vf3_aim_ubits(a.fr[i] = (float)i / 8.0f);
    }
    float x = scenario == 9 ? 100.0f : (scenario >= 10 ? 0.0f : (scenario ? (float)(scenario - 1) * 4.0f : 0.0f));
    float z = 0.0f;
    if (scenario == 10) x = -1.0f;
    if (scenario == 11) x = 1.0f;
    if (scenario == 12) z = -1.0f;
    if (scenario == 13) z = 1.0f;
    if (scenario == 14) { x = 0.5f; z = -0.5f; }
    s.v[VF3_REG_FR0 + 4] = vf3_aim_ubits(a.fr[4] = x);
    s.v[VF3_REG_FR0 + 5] = vf3_aim_ubits(a.fr[5] = z);
    s.v[16] = a.pr = 0x0c012000u;
    s.v[17] = a.sr = 0x60000000u;
    s.v[18] = a.fpscr = fpscr;
    s.budget = 10000;
    int ok = vf3_advance_worker_adapter(0x0c087a40u, &s, &map);
    vf3_native_terrain_region(&a);
    int bad = !ok || map.oob || s.pc != a.pr || s.v[17] != a.sr;
    for (unsigned i = 0; i < 16; ++i) {
        if (s.v[i] != a.r[i]) {
            fprintf(stderr, "case %u r%u: %08x != %08x\n", scenario, i, s.v[i], a.r[i]); bad = 1;
        }
        if (s.v[VF3_REG_FR0+i] != vf3_aim_ubits(a.fr[i])) {
            fprintf(stderr, "case %u fr%u: %08x != %08x\n", scenario, i, s.v[VF3_REG_FR0+i], vf3_aim_ubits(a.fr[i])); bad = 1;
        }
    }
    if (memcmp(guest, native, SIZE)) { fprintf(stderr, "case %u RAM differs\n", scenario); bad = 1; }
    free(guest); free(native);
    return bad;
}

int main(void)
{
    int bad = 0;
    for (unsigned i = 0; i < 15; ++i) {
        bad |= run(i, 0x240001u);
        bad |= run(i, 0x40001u);
    }
    puts(bad ? "terrain region replay failed" : "terrain region: 30 cases match");
    return bad;
}
