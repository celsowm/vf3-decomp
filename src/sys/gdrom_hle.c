/* sys/gdrom_hle.c - functional model of the BIOS GD-ROM syscall for the loader's DMA-read path (see gdrom_hle.h).
 *
 * The behavior follows the REIOS command state machine: REQ_CMD stores the parameter block and goes BUSY, EXEC_SERVER
 * arms a DMA read once (multi_read_* from params), the scheduler tick moves up to 5 sectors per step and flips the
 * state to COMPLETE when the last one lands, and GET_CMD_STAT reports and then clears a completed request. */
#include "sys/gdrom_hle.h"

#include <stdio.h>
#include <string.h>

static void dir_of(const char *path, char *dir, size_t n)
{
    const char *slash = strrchr(path, '/');
    const char *bslash = strrchr(path, '\\');
    if (bslash && (!slash || bslash > slash)) slash = bslash;
    size_t len = slash ? (size_t)(slash - path + 1) : 0;
    if (len >= n) len = n - 1;
    memcpy(dir, path, len);
    dir[len] = '\0';
}

int vf3_gdi_open(vf3_gdi *gdi, const char *gdi_path)
{
    char dir[512], line[1024];
    FILE *f = fopen(gdi_path, "r");
    if (!f) return -1;
    memset(gdi, 0, sizeof *gdi);
    dir_of(gdi_path, dir, sizeof dir);
    int expect = -1;
    if (!fgets(line, sizeof line, f) || sscanf(line, "%d", &expect) != 1) { fclose(f); return -1; }
    while (gdi->ntracks < 16 && fgets(line, sizeof line, f)) {
        unsigned idx, start, ctrl, size, off;
        char name[400];
        if (sscanf(line, "%u %u %u %u \"%399[^\"]\" %u", &idx, &start, &ctrl, &size, name, &off) != 6) continue;
        vf3_gdi_track *t = &gdi->track[gdi->ntracks++];
        t->start_fad = start;
        t->ctrl = ctrl;
        t->sector_size = size;
        t->file_offset = off;
        snprintf(t->path, sizeof t->path, "%s%s", dir, name);
    }
    fclose(f);
    return gdi->ntracks > 0 && (expect < 0 || gdi->ntracks == expect) ? 0 : -1;
}

int vf3_gdi_read_sector(const vf3_gdi *gdi, uint32_t fad, uint8_t out[VF3_GD_SECTOR])
{
    const vf3_gdi_track *best = NULL;
    for (int i = 0; i < gdi->ntracks; ++i)
        if (gdi->track[i].start_fad <= fad && (!best || gdi->track[i].start_fad > best->start_fad)) best = &gdi->track[i];
    if (!best) return -1;
    /* raw 2352-byte sectors carry a 16-byte sync + header in front of the user data (mode 1) */
    const uint64_t pos = (uint64_t)(fad - best->start_fad) * best->sector_size + best->file_offset +
                         (best->sector_size == 2352 ? 16u : 0u);
    FILE *f = fopen(best->path, "rb");
    if (!f) return -1;
    int rc = -1;
#ifdef _WIN32
    if (_fseeki64(f, (long long)pos, SEEK_SET) == 0)
#else
    if (fseeko(f, (off_t)pos, SEEK_SET) == 0)
#endif
        rc = fread(out, 1, VF3_GD_SECTOR, f) == VF3_GD_SECTOR ? 0 : -1;
    fclose(f);
    return rc;
}

void vf3_gd_init(vf3_gdrom *gd, const vf3_gdi *disc, vf3_gd_write_fn write, void *ctx)
{
    memset(gd, 0, sizeof *gd);
    gd->st.last_request_id = 0xFFFFFFFFu;
    gd->st.next_request_id = 2;
    gd->st.status = VF3_GDC_OK;
    gd->disc = disc;
    gd->write = write;
    gd->write_ctx = ctx;
}

uint32_t vf3_gd_req_cmd(vf3_gdrom *gd, uint32_t command, const uint32_t params[4])
{
    vf3_gd_state *st = &gd->st;
    if (st->status != VF3_GDC_OK) return 0;
    for (int i = 0; i < 4; ++i) st->params[i] = params ? params[i] : 0;
    memset(st->result, 0, sizeof st->result);
    if (st->next_request_id == ~0u || st->next_request_id == 0) st->next_request_id = 1;
    st->last_request_id = st->next_request_id++;
    st->status = VF3_GDC_BUSY;
    st->command = command;
    st->multi_read_count = 0;
    return st->last_request_id;
}

int32_t vf3_gd_get_cmd_stat(vf3_gdrom *gd, uint32_t request_id, uint32_t ext[4])
{
    vf3_gd_state *st = &gd->st;
    memcpy(ext, st->result, sizeof st->result);
    if (st->status == VF3_GDC_OK || st->status == VF3_GDC_BUSY) return st->status;
    if (request_id != st->last_request_id) return VF3_GDC_OK;     /* no such request active */
    const int32_t ret = st->status;
    if (st->status == VF3_GDC_CONTINUE && st->multi_read_count == 0) {
        st->status = VF3_GDC_COMPLETE;
        st->result[3] = 0;
    } else if (st->status != VF3_GDC_CONTINUE) {
        st->status = VF3_GDC_OK;
        st->last_request_id = 0xFFFFFFFFu;
    }
    return ret;
}

void vf3_gd_exec_server(vf3_gdrom *gd)
{
    vf3_gd_state *st = &gd->st;
    if (st->status != VF3_GDC_BUSY) return;
    switch (st->command) {
    case VF3_GDCC_DMAREAD:
        /* arm once; the request stays BUSY until the transfer tick finishes it */
        if (st->multi_read_count == 0) {
            st->cur_sector = st->params[0] & 0xFFFFFFu;
            st->multi_read_sector = st->cur_sector;
            st->multi_read_offset = st->params[2];
            st->multi_read_count = st->params[1];
            st->multi_read_total = st->params[1];
            st->result[2] = 0;
            st->result[3] = 0;
        }
        return;
    default:
        break;
    }
    st->status = VF3_GDC_COMPLETE;       /* commands the loader never waits on complete at once */
    st->command = VF3_GDCC_NONE;
}

uint32_t vf3_gd_sched_step(vf3_gdrom *gd)
{
    vf3_gd_state *st = &gd->st;
    if (st->status != VF3_GDC_BUSY || st->command != VF3_GDCC_DMAREAD || st->multi_read_count == 0) return 0;
    const uint32_t sect = st->multi_read_count < 5u ? st->multi_read_count : 5u;
    uint8_t buf[VF3_GD_SECTOR];
    for (uint32_t i = 0; i < sect; ++i) {
        if (vf3_gdi_read_sector(gd->disc, st->multi_read_sector + i, buf) != 0) memset(buf, 0, sizeof buf);
        gd->write(gd->write_ctx, st->multi_read_offset + i * VF3_GD_SECTOR, buf, VF3_GD_SECTOR);
    }
    st->multi_read_count -= sect;
    st->multi_read_sector += sect;
    st->cur_sector = st->multi_read_sector;
    st->multi_read_offset += sect * VF3_GD_SECTOR;
    if (st->multi_read_count == 0) {
        st->result[3] = 0;                   /* GDC_WAIT_INTERNAL */
        st->status = VF3_GDC_COMPLETE;
    }
    st->result[2] = (st->multi_read_total - st->multi_read_count) * VF3_GD_SECTOR;
    return sect;
}
