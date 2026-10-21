// New-reference instrumentation only. SPDX-License-Identifier: GPL-2.0-or-later
#pragma once
struct Sh4Context;
void vf3NewReferenceBefore(unsigned pc, unsigned short op, const Sh4Context *ctx);
void vf3NewReferenceEvent(bool interrupt, unsigned code, unsigned pc);
extern "C" bool vf3_new_reference_done();
