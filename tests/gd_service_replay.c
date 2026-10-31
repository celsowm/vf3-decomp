/* gd_service_replay.c - the REIOS GD-ROM service must answer the BIOS vector
 * from the drive that is attached to the run.
 *
 * The loader reaches the disc through the BIOS syscall vector (0x8C001006).
 * The matrix chain's REIOS stub owns that entry, and it used to answer every
 * call from an idle drive - "no transfer, no request" - even when a drive with
 * a disc was attached to the run, so the loader's file reads never completed.
 * The service now lives in native_tick.c (vf3_native_gd_syscall), which both
 * doors (the chain's stub and the unowned hook) call, and the drive attached
 * to the native run answers it.
 *
 * The test drives the stub the way the loader does - REQ_CMD, EXEC_SERVER,
 * then the GET_CMD_STAT poll - against a synthetic disc, and requires:
 *   1. the command to be accepted (the drive answers with a request id),
 *   2. the sectors to land in the caller's RAM window, byte for byte,
 *   3. the status to reach COMPLETE with the byte count the loader expects,
 *   4. the idle behaviour to stay in place when no drive is attached (the
 *      corpora recorded a drive with no transfer in flight, and their replay
 *      depends on that answer).
 *
 *   vf3gdservice
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/matrix_family.h"
#include "fight/native_tick.h"
#include "sys/gdrom_hle.h"

static int failures;
#define CHECK(c, ...) do { if (!(c)) { ++failures; printf("FAIL %s:%d: ", __FILE__, __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

#define TRACK_SECTORS 8
#define RAW_SECTOR 2352u          /* 16 bytes of sync+header, then the 2048 user bytes */
#define USER 2048u

/* the disc: one raw track whose every sector carries its own number */
static void build_track(uint8_t *track)
{
    for (int s = 0; s < TRACK_SECTORS; ++s) {
        uint8_t *p = track + (size_t)s * RAW_SECTOR;
        memset(p, 0, RAW_SECTOR);
        p[1] = 0x02;                       /* the sector header's type */
        p[2] = (uint8_t)s;                /* and its number */
        for (uint32_t i = 0; i < USER; ++i) p[16 + i] = (uint8_t)(s * 7 + i);
    }
}

static const char *temp_path(const char *name)
{
    static char path[512];
    const char *dir = getenv("TMPDIR");
    if (!dir || !*dir) dir = getenv("TEMP");
    if (!dir || !*dir) dir = getenv("TMP");
    if (!dir || !*dir) dir = ".";
    snprintf(path, sizeof path, "%s/%s", dir, name);
    return path;
}

int main(void)
{
    /* the corpus path (a recorded drive state) and the no-clock path must not
     * take the test's calls away from the drive under test */
#ifdef _WIN32
    _putenv("VF3_GD_STATE=");
    _putenv("VF3_GD_NOCLOCK=");
#else
    unsetenv("VF3_GD_STATE");
    unsetenv("VF3_GD_NOCLOCK");
#endif

    uint8_t *track = malloc((size_t)TRACK_SECTORS * RAW_SECTOR);
    if (!track) { printf("no memory for the track\n"); return 1; }
    build_track(track);
    const char *track_path = temp_path("vf3_gd_service_track.bin");
    FILE *f = fopen(track_path, "wb");
    if (!f) { printf("cannot write %s\n", track_path); free(track); return 1; }
    fwrite(track, 1, (size_t)TRACK_SECTORS * RAW_SECTOR, f);
    fclose(f);

    /* the disc: one track, starting at LBA 0 */
    vf3_gdi gdi;
    memset(&gdi, 0, sizeof gdi);
    gdi.ntracks = 1;
    gdi.track[0].start_fad = 0;
    gdi.track[0].sector_size = RAW_SECTOR;
    gdi.track[0].ctrl = 4;
    gdi.track[0].file_offset = 0;
    snprintf(gdi.track[0].path, sizeof gdi.track[0].path, "%s", track_path);

    /* the guest's RAM: the 16 MiB window the native run uses */
    uint8_t *ram = calloc(1, VF3_NATIVE_RAM_LEN);
    if (!ram) { printf("no memory for the RAM\n"); free(track); return 1; }
    vf3_ram_win win = { ram, VF3_NATIVE_RAM_BASE, VF3_NATIVE_RAM_LEN };
    vf3_ram_map map = { &win, 1, 0, NULL, NULL, NULL };

    vf3_gdrom gd;
    vf3_gd_init(&gd, &gdi, NULL, NULL);
    vf3_native_attach_gdrom(&gd);

    const uint32_t params = VF3_NATIVE_RAM_BASE + 0x1000u;   /* the parameter block */
    const uint32_t quad   = VF3_NATIVE_RAM_BASE + 0x1100u;   /* the extended status quad */
    const uint32_t dest   = VF3_NATIVE_RAM_BASE + 0x2000u;   /* where the sectors land */
    const uint32_t ret    = 0x0c0c0c0cu;                     /* the loader's return address */
    const uint32_t first  = 2;                               /* the first sector of the track */
    const uint32_t count  = 3;

    vf3_matrix_write(&map, params + 0, 150u + first, 4);     /* the FAD */
    vf3_matrix_write(&map, params + 4, count, 4);             /* the sector count */
    vf3_matrix_write(&map, params + 8, dest, 4);              /* the destination */
    vf3_matrix_write(&map, params + 12, 0, 4);

    vf3_matrix_state st;
    memset(&st, 0, sizeof st);
    st.budget = 16;
    st.v[4] = VF3_GDCC_DMAREAD;
    st.v[5] = params;
    st.v[6] = 0;
    st.v[7] = VF3_GD_REQ_CMD;
    st.v[16] = ret;

    /* 1. the command must be accepted by the drive */
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &st, &map), "REQ_CMD was not served");
    CHECK(st.v[0] == 2, "the drive must answer with the request id (got %u)", st.v[0]);
    CHECK(st.pc == ret, "the run must continue at the return address (got %08x)", st.pc);
    const uint32_t req_id = st.v[0];

    /* 2. EXEC_SERVER arms the transfer and leaves r0 alone */
    st.v[7] = VF3_GD_EXEC_SERVER;
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &st, &map), "EXEC_SERVER was not served");
    CHECK(st.v[0] == req_id, "EXEC_SERVER must leave r0 alone (got %u)", st.v[0]);
    CHECK(st.pc == ret, "the run must continue at the return address (got %08x)", st.pc);

    /* 3. the poll: the drive moves the sectors and reports the completion */
    st.v[4] = req_id;
    st.v[5] = quad;
    st.v[7] = VF3_GD_GET_CMD_STAT;
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &st, &map), "GET_CMD_STAT was not served");
    CHECK((int32_t)st.v[0] == VF3_GDC_COMPLETE, "the transfer must be complete (status %d)", (int32_t)st.v[0]);
    CHECK(vf3_matrix_read(&map, quad + 8, 4) == count * USER, "the size word must carry the bytes moved (%u)",
          vf3_matrix_read(&map, quad + 8, 4));

    /* 4. the sectors must be the disc's own bytes */
    unsigned bad = 0;
    for (uint32_t s = 0; s < count; ++s)
        for (uint32_t i = 0; i < USER; ++i) {
            const uint32_t got = vf3_matrix_read(&map, dest + s * USER + i, 1);
            const uint8_t want = (uint8_t)((first + s) * 7 + i);
            if (got != want) ++bad;
        }
    CHECK(bad == 0, "%u bytes differ from the disc", bad);

    /* 5. INIT_SYSTEM resets the drive: the request counter starts over, the
     *    drive is idle again and r0 is left alone (reios/gdrom_hle.cpp,
     *    GDROM_INIT_SYSTEM: "gd_hle_state = {}") */
    st.v[7] = VF3_GD_INIT_SYSTEM;
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &st, &map), "INIT_SYSTEM was not served");
    CHECK(st.v[0] == req_id, "INIT_SYSTEM must leave r0 alone (got %u)", st.v[0]);
    st.v[4] = VF3_GDCC_DMAREAD;
    st.v[5] = params;
    st.v[7] = VF3_GD_REQ_CMD;
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &st, &map), "REQ_CMD after INIT_SYSTEM was not served");
    CHECK(st.v[0] == 2, "the request counter must start over after INIT_SYSTEM (got %u)", st.v[0]);

    /* 6. without a drive the vector keeps the idle answer the corpora recorded */
    vf3_native_attach_gdrom(NULL);
    vf3_matrix_state idle;
    memset(&idle, 0, sizeof idle);
    idle.budget = 16;
    idle.v[4] = VF3_GDCC_DMAREAD;
    idle.v[5] = params;
    idle.v[6] = 0;
    idle.v[7] = VF3_GD_REQ_CMD;
    idle.v[16] = ret;
    CHECK(vf3_aica_stub_adapter(0x0c001006u, &idle, &map), "REQ_CMD without a drive must still be served");
    CHECK(idle.v[0] == 0, "an idle drive refuses the command (got %u)", idle.v[0]);
    CHECK(idle.pc == ret, "the run must continue at the return address (got %08x)", idle.pc);

    printf("gd service: %u sectors, %u bytes differ, idle answer %u\n", count, bad, idle.v[0]);
    printf(failures ? "gd_service: %d FAILURES\n" : "gd_service: all checks passed\n", failures);
    remove(track_path);
    free(ram);
    free(track);
    return failures != 0;
}
