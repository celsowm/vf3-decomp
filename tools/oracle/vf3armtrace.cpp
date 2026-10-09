/* Observe actual ARM memory accesses; never execute or replace driver code.
 * Time is the enclosing SH-4 scheduler callback, not an exact ARM cycle. */
#include "vf3armtrace.h"
#include "hw/arm7/arm7.h"
#include "hw/aica/aica_if.h"
#include "hw/sh4/sh4_sched.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>

unsigned vf3ArmTracePc;
namespace {
FILE *out;
bool initialized, truncated;
uint64_t ordinal;
void finish() {
    if (!out) return;
    std::fprintf(stderr,"[vf3armtrace] events=%llu truncated=%u\n",
        (unsigned long long)ordinal,unsigned(truncated));
    if (std::fclose(out)) std::abort();
    out=nullptr;
}
void write(const void *p, size_t n) {
    if (std::fwrite(p,1,n,out)!=n) std::abort();
}
}
void vf3ArmTraceMemory(unsigned addr, unsigned data, unsigned size, bool store) {
    if (!initialized) {
        initialized=true;
        if (const char *path=std::getenv("VF3_ARM_TRACE")) {
            out=std::fopen(path,"wb");
            if (!out) std::abort();
            write("VF3ARM1\0",8);
            std::atexit(finish);
        }
    }
    if (!out) return;
    addr &= 0x00ffffff;
    // Retain all wave-RAM stores and protocol reads; hardware-register stores.
    if (!store && (addr & 0x1fffff)>=0x600) return;
    if (addr>=0x800000 && (!store || addr>=0x808000)) return;
    if (ordinal>=2000000) { truncated=true; return; }
    uint64_t seq=++ordinal, cycle=sh4_sched_now64();
    unsigned pc=vf3ArmTracePc;
    unsigned opcode=*(const unsigned *)&aica::aica_ram[pc & 0x1ffffc];
    unsigned words[]={pc,opcode,addr,data,size,unsigned(store)};
    write(&seq,8); write(&cycle,8); write(words,sizeof(words));
}
