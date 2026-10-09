#pragma once
struct Sh4Context;
/* Runs only the verified C queue body; no recorded replies or guest opcodes. */
bool vf3AudioReplayQueue(unsigned short op, Sh4Context *ctx);
