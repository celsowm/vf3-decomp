#pragma once
struct Sh4Context;
/* Research diagnostics only. Prepare while guest execution is stopped. */
void vf3AudioPrepare();
/* Checkpoint after fetch, before dispatch; true requests a safe interpreter stop. */
bool vf3AudioBefore(unsigned pc, unsigned short op, const Sh4Context *ctx);
bool vf3AudioDone();
void vf3AudioSample(int right, int left);
void vf3AudioEvent(int id, int tag, int duration, int jitter);
void vf3AudioBegin(unsigned pc, unsigned short op, const Sh4Context *ctx);
void vf3AudioEnd(unsigned pc, const Sh4Context *ctx);
bool vf3AudioQueueWindow(const Sh4Context *ctx);
