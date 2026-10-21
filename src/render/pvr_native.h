#ifndef VF3_PVR_NATIVE_H
#define VF3_PVR_NATIVE_H
#include "render/pvr_ta.h"

/* Attach the caller-owned PVR to native function/device execution. State and
 * VRAM survive calls; TA_LIST_INIT starts a new scene, STARTRENDER renders it.
 * NULL detaches. Returns 0 if execution is active. Detach/reset native before
 * destroying the PVR. DMA payload scheduling is a separate runtime service. */
int vf3_native_attach_pvr(vf3_pvr *pvr);
#endif
