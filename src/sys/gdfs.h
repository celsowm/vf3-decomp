#pragma once
#include <stdint.h>

typedef struct VF3_GdfsEntry {
    char name[13];
    char tag[9];
} VF3_GdfsEntry;

enum {
    VF3_GDFS_KIND_OTHER = 0,
    VF3_GDFS_KIND_HI,      /* _hi  high-priority overlay      */
    VF3_GDFS_KIND_AK,      /* _ak  motion package             */
    VF3_GDFS_KIND_DU,      /* _du  dump / BGM staging         */
    VF3_GDFS_KIND_TE,      /* _te  stage table data           */
    VF3_GDFS_KIND_KA,      /* _ka  canvas package             */
};

void vf3_gdfs_mount_table(const VF3_GdfsEntry *table, unsigned count);
int  vf3_gdfs_find(const char *name);
const char *vf3_gdfs_tag(int slot);
int vf3_gdfs_kind(int slot);

/* one snapshot of the compiled resource table (from bin_names.csv); ships
 * as src/sys/gdfs_table.h when finalized. */
