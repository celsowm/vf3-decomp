/* oracle_sidecars.h - the per-case sidecars of an oracle .cases corpus.
 *
 * A corpus row carries the register file and the RAM windows; the sidecars
 * carry what the row does not:
 *
 *   .xfin.bin / .xfout.bin  the XF registers before and after the specimen;
 *   .extra.bin              the FPUL, the FPUL after, the exit PC and one word;
 *   .gbr.bin                the GBR, the GBR after and whether it is known;
 *   .bank.bin               the banked registers (the FP bank and the status);
 *   .gd.bin                 the REIOS drive state, which is not SH-4 RAM;
 *   .dev.bin                the device tape: every device read and write the
 *                           specimen made, in order.
 *
 * tests/matrix_family_replay.c (the generated chain) and
 * tests/queue_ops_oracle.c (the readable ports) share this loader, so a port
 * can be proved inside a corpus whose call tree reaches it even when that
 * corpus touches a device register.
 */
#ifndef VF3_ORACLE_SIDECARS_H
#define VF3_ORACLE_SIDECARS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "port_harness.h"
#include "fight/matrix_family.h"

typedef struct { uint32_t address,size,value,write; } vf3h_device_access;

typedef struct {
    FILE *xfin,*xfout,*extra,*gbr,*bank,*gd,*dev;
    long *dev_offsets;
    uint32_t dev_records,dev_capacity,dev_count,dev_pos,dev_bad,dev_first_bad;
    vf3h_device_access *dev_events,dev_expected,dev_actual;
    /* the expectations of the row that was loaded last */
    uint32_t wantxf[16];      /* the XF registers after the specimen */
    uint32_t aux[4];          /* the FPUL before, the FPUL after, ?, the exit PC */
    uint32_t global[3];       /* the GBR before, after, and whether it is known */
    uint32_t bank_state[17];  /* the banked registers, and whether they are known */
    int bank_valid;
} vf3h_sidecars;

static void vf3h_dev_mismatch(vf3h_sidecars *sc, vf3h_device_access actual,
                              vf3h_device_access expected)
{
    if(!sc->dev_bad) {
        sc->dev_first_bad=sc->dev_pos?sc->dev_pos-1:0;
        sc->dev_expected=expected; sc->dev_actual=actual;
    }
    sc->dev_bad=1;
}

static uint32_t vf3h_dev_read(void *context,uint32_t address,unsigned size)
{
    vf3h_sidecars *sc=(vf3h_sidecars *)context;
    if(sc->dev_pos>=sc->dev_count) {
        vf3h_dev_mismatch(sc,(vf3h_device_access){address,size,0,0},(vf3h_device_access){0});
        return 0;
    }
    vf3h_device_access event=sc->dev_events[sc->dev_pos++];
    if(event.address!=address || event.size!=size || event.write)
        vf3h_dev_mismatch(sc,(vf3h_device_access){address,size,event.value,0},event);
    return event.value;
}

static void vf3h_dev_write(void *context,uint32_t address,unsigned size,uint32_t value)
{
    vf3h_sidecars *sc=(vf3h_sidecars *)context;
    if(sc->dev_pos>=sc->dev_count) {
        vf3h_dev_mismatch(sc,(vf3h_device_access){address,size,value,1},(vf3h_device_access){0});
        return;
    }
    vf3h_device_access event=sc->dev_events[sc->dev_pos++];
    if(event.address!=address || event.size!=size || !event.write || event.value!=value)
        vf3h_dev_mismatch(sc,(vf3h_device_access){address,size,value,1},event);
}

/* Open the sidecars of the corpus whose stem is `stem` (the .cases path
 * without its extension).  The three XF/FPUL/PC sidecars are required; the
 * others are optional.  Returns 1 on success. */
static int vf3h_sidecars_open(vf3h_sidecars *sc,const char *stem)
{
    char path[1400];
    memset(sc,0,sizeof *sc);
    snprintf(path,sizeof path,"%s.xfin.bin",stem); sc->xfin=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.xfout.bin",stem); sc->xfout=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.extra.bin",stem); sc->extra=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.gbr.bin",stem); sc->gbr=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.bank.bin",stem); sc->bank=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.gd.bin",stem); sc->gd=fopen(path,"rb");
    snprintf(path,sizeof path,"%s.dev.bin",stem); sc->dev=fopen(path,"rb");
    if(!sc->xfin||!sc->xfout||!sc->extra) return 0;
    if(sc->dev) {
        /* Device tapes are variable-length; index them by .cases row. */
        uint32_t capacity=0,count;
        while(fread(&count,4,1,sc->dev)==1) {
            if(count>16384) { fclose(sc->dev); sc->dev=NULL; break; }
            if(sc->dev_records==capacity) {
                capacity=capacity?capacity*2:64;
                long *grown=realloc(sc->dev_offsets,(size_t)capacity*sizeof(*grown));
                if(!grown) { fclose(sc->dev); sc->dev=NULL; break; }
                sc->dev_offsets=grown;
            }
            sc->dev_offsets[sc->dev_records++]=ftell(sc->dev)-4;
            if(fseek(sc->dev,(long)count*sizeof(vf3h_device_access),SEEK_CUR)) {
                fclose(sc->dev); sc->dev=NULL; break;
            }
        }
        if(sc->dev) rewind(sc->dev);
    }
    return 1;
}

static void vf3h_sidecars_close(vf3h_sidecars *sc)
{
    if(sc->xfin) fclose(sc->xfin);
    if(sc->xfout) fclose(sc->xfout);
    if(sc->extra) fclose(sc->extra);
    if(sc->gbr) fclose(sc->gbr);
    if(sc->bank) fclose(sc->bank);
    if(sc->gd) fclose(sc->gd);
    if(sc->dev) fclose(sc->dev);
    free(sc->dev_events); free(sc->dev_offsets);
    memset(sc,0,sizeof *sc);
}

/* Load the sidecars of row `c` into `state` and `ram`.  Returns 1 on
 * success; on failure it writes the reason into `err`. */
static int vf3h_sidecars_load(vf3h_sidecars *sc,const vf3_case *c,
                               vf3_matrix_state *state,vf3_ram_map *ram,
                               char *err,size_t errlen)
{
    uint32_t wantxf[16],aux[4],global[3]={0};
    /* The sidecars are written one record per .cases row, including rows whose
     * RAM shadow is unavailable.  Seek by row so a skipped row cannot shift
     * every later FPUL/XF/GBR expectation. */
    if(fseek(sc->xfin,(long)c->ordinal*64,SEEK_SET)||
       fseek(sc->xfout,(long)c->ordinal*64,SEEK_SET)||
       fseek(sc->extra,(long)c->ordinal*16,SEEK_SET)) {
        snprintf(err,errlen,"missing extended state"); return 0;
    }
    if(fread(state->v+37,4,16,sc->xfin)!=16||
       fread(wantxf,4,16,sc->xfout)!=16||
       fread(aux,4,4,sc->extra)!=4) {
        snprintf(err,errlen,"missing extended state"); return 0;
    }
    memcpy(sc->wantxf,wantxf,sizeof wantxf);
    memcpy(sc->aux,aux,sizeof aux);
    state->v[53]=aux[0];
    if(sc->gbr) {
        if(fseek(sc->gbr,(long)c->ordinal*12,SEEK_SET)) {
            snprintf(err,errlen,"missing GBR state"); return 0;
        }
        if(fread(global,4,3,sc->gbr)!=3) {
            snprintf(err,errlen,"missing GBR state"); return 0;
        }
    }
    memcpy(sc->global,global,sizeof global);
    state->gbr=global[0]; state->gbr_known=global[2];
    if(sc->bank) {
        uint32_t bank_state[17];
        if(fseek(sc->bank,(long)c->ordinal*68,SEEK_SET)) {
            snprintf(err,errlen,"missing banked registers"); return 0;
        }
        if(fread(bank_state,4,17,sc->bank)!=17) {
            snprintf(err,errlen,"missing banked registers"); return 0;
        }
        memcpy(sc->bank_state,bank_state,sizeof bank_state);
        sc->bank_valid=1;
        state->bank_known=bank_state[0];
        memcpy(state->bank,bank_state+1,sizeof(state->bank));
    } else {
        sc->bank_valid=0;
    }
    if(sc->gd) {
        if(fseek(sc->gd,(long)c->ordinal*64,SEEK_SET)) {
            snprintf(err,errlen,"missing GD drive state"); return 0;
        }
        if(fread(state->gd_state,4,16,sc->gd)!=16) {
            snprintf(err,errlen,"missing GD drive state"); return 0;
        }
        state->gd_state_known=1;
    }
    if(sc->dev) {
        uint32_t count;
        if(c->ordinal>=sc->dev_records) {
            snprintf(err,errlen,"missing device tape"); return 0;
        }
        if(fseek(sc->dev,sc->dev_offsets[c->ordinal],SEEK_SET)) {
            snprintf(err,errlen,"missing device tape"); return 0;
        }
        if(fread(&count,4,1,sc->dev)!=1||count>16384) {
            snprintf(err,errlen,"invalid device tape"); return 0;
        }
        if(count>sc->dev_capacity) {
            vf3h_device_access *events=realloc(sc->dev_events,(size_t)count*sizeof(*events));
            if(!events) { snprintf(err,errlen,"device tape allocation failed"); return 0; }
            sc->dev_events=events; sc->dev_capacity=count;
        }
        if(fread(sc->dev_events,sizeof(vf3h_device_access),count,sc->dev)!=count) {
            snprintf(err,errlen,"short device tape"); return 0;
        }
        sc->dev_count=count; sc->dev_pos=sc->dev_bad=0;
        ram->device_read=vf3h_dev_read; ram->device_write=vf3h_dev_write;
        ram->device_context=sc;
    }
    return 1;
}

/* Check that the device tape was consumed exactly.  Returns 1 when it was. */
static int vf3h_sidecars_devices_ok(vf3h_sidecars *sc,char *err,size_t errlen)
{
    if(!sc->dev) return 1;
    if(sc->dev_bad) {
        snprintf(err,errlen,"device access mismatch at %u/%u: got %c %08x/%u=%08x, expected %c %08x/%u=%08x",
                 sc->dev_first_bad,sc->dev_count,
                 sc->dev_actual.write?'W':'R',sc->dev_actual.address,sc->dev_actual.size,sc->dev_actual.value,
                 sc->dev_expected.write?'W':'R',sc->dev_expected.address,sc->dev_expected.size,sc->dev_expected.value);
        return 0;
    }
    if(sc->dev_pos!=sc->dev_count) {
        snprintf(err,errlen,"device tape has %u unconsumed events",sc->dev_count-sc->dev_pos);
        return 0;
    }
    return 1;
}

#endif /* VF3_ORACLE_SIDECARS_H */
