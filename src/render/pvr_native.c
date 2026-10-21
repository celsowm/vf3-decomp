#include "render/pvr_native.h"
#include "fight/native_tick.h"

static int pvr_read(void *context, uint32_t address, unsigned size, uint32_t *value)
{
    return vf3_pvr_read((vf3_pvr *)context, address, size, value);
}
static int pvr_write(void *context, uint32_t address, unsigned size, uint32_t value)
{
    return vf3_pvr_write((vf3_pvr *)context, address, size, value);
}
int vf3_native_attach_pvr(vf3_pvr *pvr)
{
    const vf3_native_device_bus bus = {pvr_read, pvr_write, pvr};
    return vf3_native_attach_device_bus(pvr ? &bus : NULL);
}
