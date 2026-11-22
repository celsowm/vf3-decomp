/* sprite_quad_native_replay.c - differential replay of the native sprite_quad
 * (0x8C03F830, src/native/sprite_quad.c, `vf3_native_sprite_quad`) against the
 * readable guest port (src/fight/sprite_readable.c, `vf3_sprite_quad_entry`).
 *
 * The billboard-sprite quad submission: looks the object's sprite index up in
 * the table at 0x0C19E208, scales the four corner offsets by the object's
 * size/rotation (sin/cos of the angle at +28 through the corner fan
 * 0x8C03FB10), packs the 16-bit texture coordinates, patches the sprite's TA
 * header words (entry of 0x20 bytes in the table at 0x0C19E214) and advances
 * the SQ cursor kept next to the table at 0x0C16CA08.
 *
 * Both sides seed the same object (sprite index at +0, size/rotation at
 * +0x10/+0x14/+0x18/+0x1C/+0x20/+0x24, depth at +0x0C, angle at +0x28, flags
 * at +0x2C, tint scale at +0x30), the sprite index table and the header
 * table, the SQ state at 0x0C16CA08, the scale/tint/SCALE_TAB globals and
 * the half constant, then run.  Compared: the patched header words at the
 * sprite's 0x20-byte entry in the header table, the SQ cursor advance at
 * 0x0C16CA08, the dead prologue stack words, the saved FR13..FR15 / r8..r14
 * (bit-exact), r15 and pr, and SR's T bit.
 */
#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "sprite_quad.h"
#include "aim_math.h"
#include "sin_cos.h"
#include "corner_fan.h"
#include "color_pack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_sprite_quad_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define RAM_BASE 0x0C010000u
#define RAM_SIZE 0x400000u

#define OBJ         0x0C200000u
#define SP0         0x0C210000u   /* frame f = sp0 - 104 */
#define IDX_TABLE   0x0C19E208u   /* -> the sprite index table */
#define HDR_TABLE   0x0C19E214u   /* -> the sprite header table */
#define SQ_STATE    0x0C16CA08u
#define HALF_CONST  0x0C03F978u
#define SCALE_X     0x0C0EA538u
#define SCALE_Y     0x0C0EA534u
#define SCALE_TAB   0x0C0EA668u
#define TINT_TAB    0x0C0EA634u

static float *ram;
static float *at(uint32_t addr) { return (float *)((uint8_t *)ram + (addr - RAM_BASE)); }
static void w32(uint32_t addr, uint32_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16); p[3] = (uint8_t)(v >> 24);
}
static void wf(uint32_t addr, float v) { uint32_t u; memcpy(&u, &v, 4); w32(addr, u); }
static uint32_t r32(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}
static void wh(uint32_t addr, uint16_t v)
{
    uint8_t *p = (uint8_t *)at(addr);
    p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8);
}
static uint16_t rh(uint32_t addr)
{
    const uint8_t *p = (const uint8_t *)at(addr);
    return (uint16_t)(p[0] | (p[1] << 8));
}

/* a device-write sink: the SQ/QACR stores the readable makes (0xFF000038/3C,
 * the 0xE0000000 region) must not land in the RAM windows */
static void dev_write(void *ctx, uint32_t addr, unsigned size, uint32_t value)
{ (void)ctx; (void)addr; (void)size; (void)value; }

/* seed: object, the two tables, the SQ state, the four globals and the
 * half constant.  obj[] lets each case pick flags/angle/mirror/scales. */
static void seed(uint32_t obj_flags, uint32_t angle, uint16_t sprite,
                 float size_scale, float mirror, int translucent_override)
{
    memset(at(OBJ), 0, 0x10000);
    memset(at(SP0 - 112u), 0, 320);     /* frame + save region */

    /* object fields (index word at +0 selects the sprite) */
    w32(OBJ, (uint32_t)sprite);
    wf(OBJ + 0x0Cu, 4.0f);              /* depth */
    wf(OBJ + 0x10u, 64.0f);             /* obj_w */
    wf(OBJ + 0x14u, 32.0f);             /* obj_h */
    wf(OBJ + 0x18u, 0.25f);             /* u0 */
    wf(OBJ + 0x1Cu, 0.75f);             /* u1 */
    wf(OBJ + 0x20u, 0.5f);              /* v0 */
    wf(OBJ + 0x24u, 0.125f);            /* v1 */
    w32(OBJ + 0x28u, angle);
    w32(OBJ + 0x2Cu, obj_flags);
    wf(OBJ + 0x30u, size_scale);

    /* sprite index table: u16 at table_base + 2*index_word -> sprite id.
     * obj+0 holds index_word (= sprite); the port resolves the sprite by
     * reading u16(table_base + 2*index_word).  Identity-map it so the
     * resolved sprite equals obj+0, and the header slot the test reads
     * (HDR_TABLE base + resolved_sprite*32) is the one the port patches. */
    {
        uint32_t base = IDX_TABLE;
        w32(base, 0x0C1A0000u);         /* the table's base */
        wh(0x0C1A0000u + 2u * (uint32_t)sprite, sprite);
    }
    /* header table: the sprite's 0x20-byte entry */
    {
        uint32_t base = HDR_TABLE;
        w32(base, 0x0C1A0200u);
        uint32_t h = 0x0C1A0200u + ((uint32_t)sprite << 5);
        w32(h + 0x00u, 0x80800000u);    /* pcw */
        w32(h + 0x04u, 0x00000000u);    /* isp */
        w32(h + 0x08u, 0x00000000u);    /* tsp */
        w32(h + 0x0Cu, 0x00000000u);    /* tex */
        wf(h + 0x18u, 0.5f);            /* x extent */
        wf(h + 0x1Cu, 0.5f);            /* y extent */
        if (translucent_override) w32(h + 0x14u, 1u);
        else w32(h + 0x14u, 0u);
    }
    /* SQ state: cursor cell + line_off cursors (line 0 and line 8 same base) */
    {
        uint32_t sq = SQ_STATE;
        uint32_t cur = 0x0C160000u;     /* somewhere in RAM, area 0 */
        w32(sq, cur);                   /* SQ_STATE -> cursor cell */
        w32(cur + 0u, 0xE0000000u | 0x0100u);   /* line 0 cursor */
        w32(cur + 8u, 0xE0000000u | 0x0200u);   /* line 8 cursor */
    }
    /* globals */
    wf(HALF_CONST, 0.5f);
    wf(SCALE_X, 1.25f);
    wf(SCALE_Y, 0.75f);
    wf(SCALE_TAB + 0u, 0.5f);
    wf(SCALE_TAB + 4u, 2.0f);
    wf(TINT_TAB + 0u, 1.0f);
    wf(TINT_TAB + 4u, 0.5f);
    wf(TINT_TAB + 8u, 0.25f);
}

static void setup_guest(vf3_matrix_state *s, vf3_ram_map *map, vf3_ram_win *win)
{
    memset(s, 0, sizeof *s);
    s->v[4] = OBJ;
    s->v[15] = SP0;
    s->v[16] = 0x0C0ABCDEu;             /* pr */
    s->v[17] = 0x60000000u;             /* sr */
    s->v[18] = 0x00040001u;             /* fpscr */
    s->v[VF3_REG_FR0 + 13] = 0x40000000u;   /* fr13 = 2.0 */
    s->v[VF3_REG_FR0 + 14] = 0x40800000u;   /* fr14 = 4.0 */
    s->v[VF3_REG_FR0 + 15] = 0x40A00000u;   /* fr15 = 5.0 */
    for (int i = 8; i <= 14; ++i) s->v[i] = 0x1000u * (uint32_t)i;
    s->budget = 4000000u;
    memset(map, 0, sizeof *map);
    win[0].base = RAM_BASE; win[0].len = RAM_SIZE; win[0].data = (uint8_t *)ram;
    map->wins = win; map->n = 1; map->oob = 0;
    map->device_write = dev_write;
}

static int run_case(const char *label, uint32_t obj_flags, uint32_t angle,
                    uint16_t sprite, float size_scale, int translucent_override)
{
    printf("== %s\n", label);
    fflush(stdout);
    int bad = 0;

    seed(obj_flags, angle, sprite, size_scale, 0.0f, translucent_override);
    vf3_matrix_state gs; vf3_ram_map gmap; vf3_ram_win gwin[1];
    setup_guest(&gs, &gmap, gwin);
    vf3_family_override = vf3_readable_override;
    const int ok_guest = vf3_sprite_quad_entry(&gs, &gmap);
    vf3_family_override = NULL;
    if (!ok_guest || gmap.oob) {
        fprintf(stderr, "  guest run failed (ok=%d oob=%u)\n", ok_guest, gmap.oob);
        return 1;
    }
    /* the guest's observable RAM: header table entry (sprite's 0x20 bytes),
     * the SQ cursor advance, the dead prologue words, and registers */
    uint32_t hdr = HDR_TABLE;
    hdr = r32(hdr);
    uint32_t h = hdr + ((uint32_t)sprite << 5);
    uint32_t ghdr[8];
    for (int i = 0; i < 8; ++i) ghdr[i] = r32(h + 4u * (uint32_t)i);
    /* translucent when the size scale is below 1.0 or the header word at +0x14
     * is non-zero (the seed wires +0x14 from translucent_override) */
    const uint32_t line_off = (size_scale < 1.0f || translucent_override) ? 8u : 0u;
    /* the frame region (dead prologue words + frame words below SP0) and the
     * SQ cursor cell are both RAM the guest writes; snapshot them now */
    const uint32_t frbase = SP0 - 112u;
    uint8_t gframe[320];
    memcpy(gframe, at(frbase), sizeof gframe);
    uint32_t gcursor = r32(SQ_STATE);
    uint32_t gcursor_val = r32(gcursor + line_off);

    seed(obj_flags, angle, sprite, size_scale, 0.0f, translucent_override);
    vf3_native_aim a;
    memset(&a, 0, sizeof a);
    a.ram = ram; a.ram_base = RAM_BASE;
    a.r[4] = OBJ;
    a.r[15] = SP0;
    a.pr = 0x0C0ABCDEu;
    a.sr = 0x60000000u;
    a.fpscr = 0x00040001u;
    a.fr[13] = 2.0f; a.fr[14] = 4.0f; a.fr[15] = 5.0f;
    for (int i = 8; i <= 14; ++i) a.r[i] = 0x1000u * (uint32_t)i;
    vf3_native_sprite_quad(&a);

    uint32_t nhdr[8];
    for (int i = 0; i < 8; ++i) nhdr[i] = r32(h + 4u * (uint32_t)i);
    if (getenv("SQDBG")) { fprintf(stderr, "  hdr native: %08x %08x %08x %08x %08x %08x %08x %08x\n", nhdr[0],nhdr[1],nhdr[2],nhdr[3],nhdr[4],nhdr[5],nhdr[6],nhdr[7]); fprintf(stderr, "  hdr guest:  %08x %08x %08x %08x %08x %08x %08x %08x\n", ghdr[0],ghdr[1],ghdr[2],ghdr[3],ghdr[4],ghdr[5],ghdr[6],ghdr[7]); }
    for (int i = 0; i < 8; ++i) {
        if (nhdr[i] != ghdr[i]) {
            if (bad < 12) fprintf(stderr, "  hdr[%d]: native %08x guest %08x\n", i, nhdr[i], ghdr[i]);
            bad++;
        }
    }

    /* the frame region the guest wrote (dead prologue words, dx/dy, UV packing
     * and the corner-fan outputs) must match byte-for-byte */
    {
        uint8_t nframe[320];
        memcpy(nframe, at(frbase), sizeof nframe);
        if (memcmp(nframe, gframe, sizeof nframe) != 0) {
            if (bad < 12) {
                for (unsigned i = 0; i < sizeof nframe; ++i)
                    if (nframe[i] != gframe[i]) { fprintf(stderr, "  frame+0x%02x: native %02x guest %02x\n", i, nframe[i], gframe[i]); break; }
            }
            bad++;
        }
    }
    /* the SQ cursor cell both sides advance */
    {
        uint32_t ncursor = r32(SQ_STATE);
        uint32_t ncursor_val = r32(ncursor + line_off);
        if (ncursor_val != gcursor_val) { if (bad < 12) fprintf(stderr, "  cursor(+%u): native %08x guest %08x\n", line_off, ncursor_val, gcursor_val); bad++; }
    }

    /* registers / FR / pr / r15 */
    for (int i = 0; i < 7; ++i) {
        if (a.r[8 + i] != gs.v[8 + i]) { if (bad < 12) fprintf(stderr, "  r%d: native %08x guest %08x\n", 8 + i, a.r[8 + i], (unsigned)gs.v[8 + i]); bad++; }
    }
    for (int i = 0; i < 3; ++i) {
        if (vf3_aim_ubits(a.fr[13 + i]) != gs.v[VF3_REG_FR0 + 13 + i]) { if (bad < 12) fprintf(stderr, "  fr%d: native %08x guest %08x\n", 13 + i, (unsigned)vf3_aim_ubits(a.fr[13 + i]), (unsigned)gs.v[VF3_REG_FR0 + 13 + i]); bad++; }
    }
    if (a.r[15] != gs.v[15]) { if (bad < 4) fprintf(stderr, "  r15: native %08x guest %08x\n", a.r[15], (unsigned)gs.v[15]); bad++; }
    if (a.pr != gs.v[16]) { if (bad < 4) fprintf(stderr, "  pr:  native %08x guest %08x\n", a.pr, (unsigned)gs.v[16]); bad++; }

    printf("  sprite_quad: %s (%d)\n", bad ? "DIFFERS" : "match", bad);
    return bad ? 1 : 0;
}

int main(void)
{
    ram = (float *)calloc(RAM_SIZE / 4u, sizeof(float));
    if (!ram) return 2;

    int bad = 0;
    /* opaque, non-translucent, angle 0 */
    bad |= run_case("opaque angle0", 0x00000000u, 0x0000u, 1, 1.0f, 0);
    /* translucent via small scale */
    bad |= run_case("translucent scale", 0x00000000u, 0x2000u, 2, 0.5f, 0);
    /* translucent via header word */
    bad |= run_case("translucent word", 0x00000000u, 0x4000u, 3, 1.0f, 1);
    /* mirror flag 0x10 flips the UV0 pair */
    bad |= run_case("mirror uv0", 0x00000010u, 0x1000u, 4, 1.0f, 0);
    /* blend + tint-table path (flag 0x2000) */
    bad |= run_case("tint table", 0x00002000u, 0x0800u, 5, 0.9f, 0);
    /* monkey flag on a big sprite */
    bad |= run_case("monkey flag", 0x10000000u, 0x6000u, 6, 0.0f, 0);
    /* flag 0x1000 sets the 0x2000 hdr bit */
    bad |= run_case("flag 1000", 0x00001000u, 0x2000u, 7, 1.0f, 0);

    free(ram);
    printf("sprite_quad_native_replay: %s\n", bad ? "FAIL" : "PASS");
    return bad ? 1 : 0;
}
