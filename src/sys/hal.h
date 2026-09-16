/* Platform abstraction layer for the VF3tb source port.
 * Dreamcast hardware services (PVR/PowerVR video, AICA audio, GD-ROM,
 * Maple controllers, VBlank) are re-implemented behind this interface.
 */
#ifndef VF3_SYS_HAL_H
#define VF3_SYS_HAL_H

void hal_log(const char *msg);

#endif /* VF3_SYS_HAL_H */
