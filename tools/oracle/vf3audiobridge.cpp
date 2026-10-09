/* Live-device comparison backend. Game semantics execute from command_encoders.c.
 * Opcode metadata charges the independent C path's fetch/issue cycles only;
 * no original opcode is executed by this backend. */
#include "vf3audiobridge.h"
#include "vf3audio.h"
#include "vf3oracle.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_interpreter.h"
#include "hw/sh4/sh4_core.h"
#include "hw/sh4/modules/mmu.h"
#include "debug/gdb_server.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
extern "C" {
#include "fight/matrix_family.h"
int vf3_audio_queue_c(vf3_matrix_state*,const vf3_ram_map*);
}
namespace {
Sh4Context *cpu;
bool first;
unsigned short previous, deferred;
unsigned instructions;
void toGuest(const vf3_matrix_state *s) {
    for (unsigned i=0;i<16;++i) {
        cpu->r[i]=s->v[i];
        std::memcpy(&cpu->fr[i],&s->v[21+i],4);
        std::memcpy(&cpu->xf[i],&s->v[37+i],4);
    }
    cpu->pr=s->v[16]; cpu->sr.setFull(s->v[17]);
    cpu->fpscr.full=s->v[18]; cpu->mac.l=s->v[19]; cpu->mac.h=s->v[20];
    cpu->fpul=s->v[53]; cpu->gbr=s->gbr;
}
void retire(unsigned nextPc) {
    // RTS's delay-slot opcode retires before its branch issue charge.
    if (previous==0x000b) { deferred=previous; return; }
    Sh4Interpreter::Instance->OracleChargeCycles(previous);
    if (deferred) { Sh4Interpreter::Instance->OracleChargeCycles(deferred); deferred=0; }
    cpu->pc=nextPc;
    if (cpu->cycle_counter<=0) {
        cpu->cycle_counter+=SH4_TIMESLICE;
        if (UpdateSystem_INTC()) {
            vf3OracleInvalidate(1);
            std::exit(2); // incomplete rejected invocation; never resume the game
        }
    }
}
void observe(unsigned pc, unsigned short op) {
    if (vf3AudioBefore(pc,op,cpu)) throw debugger::Stop();
    vf3OracleBefore(pc,op,cpu);
    if (vf3OracleOneShotDone()) throw debugger::Stop();
}
}
extern "C" void vf3_audio_queue_step(vf3_matrix_state *s,unsigned pc) {
    if (++instructions>64) std::abort();
    toGuest(s);
    if (!first) {
        retire(pc);
        cpu->pc=pc+2;
        previous=IReadMem16(pc);
        observe(pc,previous);
    } else first=false; // substituted entry has already been fetched/observed
    // Literal loads in the C body use proven constants, but still consume bus time.
    if ((previous&0xf000)==0xd000)
        (void)ReadMem32(((pc+4)&~3u)+((previous&255)*4));
}
extern "C" uint32_t vf3_matrix_read(const vf3_ram_map*,uint32_t addr,unsigned size) {
    if (size==4) return ReadMem32(addr);
    if (size==2) return ReadMem16(addr);
    if (size==1) return ReadMem8(addr);
    std::abort();
}
extern "C" void vf3_matrix_write(const vf3_ram_map*,uint32_t addr,uint32_t value,unsigned size) {
    if (std::getenv("VF3_AUDIO_CORRUPT_COMMAND") && addr>=0xa0800400u && addr<0xa0800500u)
        value^=1; // deliberate negative control; real bus write, not expected-data mutation
    if (size==4) WriteMem32(addr,value);
    else if (size==2) WriteMem16(addr,value);
    else if (size==1) WriteMem8(addr,value);
    else std::abort();
}
bool vf3AudioReplayQueue(unsigned short op,Sh4Context *ctx) {
    if (!std::getenv("VF3_C_AUDIO_REPLAY") || !vf3OracleOneShotActive()) return false;
    if (!std::getenv("VF3_ONESHOT") || mmu_enabled()) std::abort();
    if (ctx->pc!=0x8c040f20u) return false;
    cpu=ctx; previous=op; deferred=0; first=true; instructions=0;
    vf3_matrix_state s{};
    for (unsigned i=0;i<16;++i) {
        s.v[i]=ctx->r[i]; std::memcpy(&s.v[21+i],&ctx->fr[i],4);
        std::memcpy(&s.v[37+i],&ctx->xf[i],4);
    }
    s.v[16]=ctx->pr; s.v[17]=ctx->sr.getFull(); s.v[18]=ctx->fpscr.full;
    s.v[19]=ctx->mac.l; s.v[20]=ctx->mac.h; s.v[53]=ctx->fpul; s.gbr=ctx->gbr;
    vf3_ram_map ram{};
    std::fprintf(stderr,"[vf3audiobridge] executing C queue with live devices\n");
    if (!vf3_audio_queue_c(&s,&ram)) std::abort();
    toGuest(&s);
    retire(s.pc);
    const unsigned short next=IReadMem16(s.pc);
    ctx->pc=s.pc+2;
    observe(s.pc,next); // completes capsule before the caller's opcode executes
    std::abort(); // matched return must have stopped the interpreter
}
