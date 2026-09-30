#pragma once
struct Sh4Context;
void vf3OracleBefore(unsigned pc, unsigned short op, const Sh4Context *ctx);
void vf3OracleInvalidate(unsigned reason);
