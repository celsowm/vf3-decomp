/* sys/gdfs.c — VF3 GDFS resource-name lookup (M21 port).
 *
 * The game embeds 222 `.BIN` filename records in 1ST_READ
 * (extract/analysis/bin_names.csv; generator tools/bin_names.py). Loader
 * resolves a resource by NAME then reads the record's 4-byte tag/flags,
 * feeds offset+LBA through the GD driver, and delivers the contents to the
 * rise resident buffers.
 *
 * This module covers NAME->tag/offset decoding (address, stride) and ports
 * the decode logic of `_xx` tag categories ("_hi"=high-priority overlay,
 * "_ak"=AIK motion, "_du"=BGM/dump, "_te"=stage table,
 * "_ka"=canvas package, "_su"/"_yu" etc.) observed in the table.
 */
#include <stdint.h>
#include <string.h>

#include "gdfs.h"

/* Compiled-in table mirror: generated from extract/analysis/bin_names.csv;
 * layout is (name, tag). The data source is CSV at build time — regen via
 * tools/bin_names.py — no game bytes embedded. */
typedef struct VF3_GdfsEntry_ {
    char name[13];
    char tag[9];
} VF3_GdfsEntry_;
#include "gdfs_table.h"

/* Alias to the generated type (it's compatible with the header typedef). */
static inline void use_gen(void)
{
    vf3_gdfs_mount_table(
        (const VF3_GdfsEntry *)vf3_gdfs_table, VF3_GDFS_TABLE_COUNT);
}

/* A lightweight live API using a caller-provided table (loaded from the
 * SV at runtime by the host bootstrapper — in RE assets land as generated
 * header). Lookup rule: exact case-sensitive name. */
static const VF3_GdfsEntry *g_table = NULL;
static unsigned g_count = 0;

void vf3_gdfs_mount_table(const VF3_GdfsEntry *table, unsigned count)
{
    g_table = table;
    g_count = count;
}

int vf3_gdfs_find(const char *name)
{
    for (unsigned i = 0; i < g_count; ++i)
        if (strcmp(g_table[i].name, name) == 0)
            return (int)i;
    return -1;
}

const char *vf3_gdfs_tag(int slot)
{
    if (slot < 0 || (unsigned)slot >= g_count || !g_table)
        return "";
    return g_table[slot].tag;
}

/* category for the tag, for schedule shaping */
int vf3_gdfs_kind(int slot)
{
    const char *t = vf3_gdfs_tag(slot);
    if (t[0] == '_' && t[1] == 'h' && t[2] == 'i') return VF3_GDFS_KIND_HI;
    if (t[0] == '_' && t[1] == 'a' && t[2] == 'k') return VF3_GDFS_KIND_AK;
    if (t[0] == '_' && t[1] == 'd' && t[2] == 'u') return VF3_GDFS_KIND_DU;
    if (t[0] == '_' && t[1] == 't' && t[2] == 'e') return VF3_GDFS_KIND_TE;
    if (t[0] == '_' && t[1] == 'k' && t[2] == 'a') return VF3_GDFS_KIND_KA;
    return VF3_GDFS_KIND_OTHER;
}
