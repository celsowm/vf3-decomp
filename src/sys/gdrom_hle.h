#pragma once
/* sys/gdrom_hle.h - functional model of the BIOS GD-ROM syscall (vector 0x8C0000BC, r6 = 0) as the loader uses it.
 *
 * The retail loader polls EXEC_SERVER (r7 = 2) and GET_CMD_STAT (r7 = 1) through the stubs at 0x8C0430A0 / 0x8C0430B4
 * and queues reads with REQ_CMD (r7 = 0, command 0x11 = DMA read). The model mirrors the REIOS command state, so a
 * state dumped by tools/gd_state_dump.py can be loaded and run forward. Transfers advance in steps of up to 5 sectors
 * per vf3_gd_sched_step() call (the original advances them from a scheduler timer; the model has no clock, so the
 * caller decides when a step happens). */
#include <stddef.h>
#include <stdint.h>

enum {
    VF3_GDC_ERR = -1,
    VF3_GDC_OK = 0,        /* idle */
    VF3_GDC_BUSY = 1,
    VF3_GDC_COMPLETE = 2,
    VF3_GDC_CONTINUE = 3,
};

enum {
    VF3_GD_REQ_CMD = 0,
    VF3_GD_GET_CMD_STAT = 1,
    VF3_GD_EXEC_SERVER = 2,
    VF3_GD_INIT_SYSTEM = 3,
    VF3_GD_GET_DRV_STAT = 4,
    VF3_GD_G1_DMA_END = 5,
    VF3_GD_REQ_DMA_TRANS = 6,
    VF3_GD_CHECK_DMA_TRANS = 7,
    VF3_GD_READ_ABORT = 8,
    VF3_GD_RESET = 9,
    VF3_GD_CHANGE_DATA_TYPE = 10,
    VF3_GD_REQ_PIO_TRANS = 12,
    VF3_GD_CHECK_PIO_TRANS = 13,
};

enum { VF3_GDCC_NONE = 0, VF3_GDCC_PIOREAD = 0x10, VF3_GDCC_DMAREAD = 0x11 };

#define VF3_GD_SECTOR 2048u

typedef struct {
    uint32_t start_fad;
    uint32_t sector_size;      /* bytes per sector in the track file: 2048 or 2352 */
    uint32_t ctrl;
    uint32_t file_offset;
    char path[512];
} vf3_gdi_track;

typedef struct {
    vf3_gdi_track track[16];
    int ntracks;
} vf3_gdi;

/* parse a .gdi (tracks are resolved relative to the .gdi's directory); 0 on success */
int vf3_gdi_open(vf3_gdi *gdi, const char *gdi_path);
/* read the 2048 user bytes of one sector; 0 on success */
int vf3_gdi_read_sector(const vf3_gdi *gdi, uint32_t fad, uint8_t out[VF3_GD_SECTOR]);

typedef struct {
    uint32_t last_request_id;
    uint32_t next_request_id;
    int32_t status;
    uint32_t command;
    uint32_t params[4];
    uint32_t result[4];
    uint32_t cur_sector;
    uint32_t multi_read_sector;
    uint32_t multi_read_offset;     /* destination address of the next sector */
    uint32_t multi_read_count;
    uint32_t multi_read_total;
} vf3_gd_state;

/* destination writer: copy len bytes to guest address addr */
typedef void (*vf3_gd_write_fn)(void *ctx, uint32_t addr, const uint8_t *data, uint32_t len);

typedef struct {
    vf3_gd_state st;
    const vf3_gdi *disc;
    vf3_gd_write_fn write;
    void *write_ctx;
} vf3_gdrom;

void vf3_gd_init(vf3_gdrom *gd, const vf3_gdi *disc, vf3_gd_write_fn write, void *ctx);

/* REQ_CMD: returns the request id, 0 when the drive is not idle. params may be NULL (read as zeros). */
uint32_t vf3_gd_req_cmd(vf3_gdrom *gd, uint32_t command, const uint32_t params[4]);
/* GET_CMD_STAT: returns the status code and fills ext[4] (error, error1, size, wait state) */
int32_t vf3_gd_get_cmd_stat(vf3_gdrom *gd, uint32_t request_id, uint32_t ext[4]);
/* EXEC_SERVER: processes the queued command (DMA read: arms the transfer) */
void vf3_gd_exec_server(vf3_gdrom *gd);
/* one scheduler tick of the armed transfer: up to 5 sectors; returns sectors moved */
uint32_t vf3_gd_sched_step(vf3_gdrom *gd);
