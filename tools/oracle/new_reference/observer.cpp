// New-reference instrumentation only. SPDX-License-Identifier: GPL-2.0-or-later
// Passive snapshots: no fixture seeding, memory writes, cache flushes or C replay.
#include "vf3_new_reference.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_cache.h"
#include "hw/sh4/sh4_sched.h"
#include "hw/sh4/sh4_mmr.h"
#include "hw/pvr/pvr_mem.h"
#include "hw/pvr/pvr_regs.h"
#include "hw/aica/aica_if.h"
#include "hw/aica/aica_mem.h"
#include "hw/holly/sb.h"
#include "debug/gdb_server.h"
#include "serialize.h"
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

void vf3NewGdSnapshot(unsigned out[22]);
namespace {
bool initialized, done, armed;
unsigned maximum = 4, captured, countdown, entryPr, entrySp;
std::vector<unsigned> targets, seenTargets;
unsigned long long instructions, limit = 2000000000ull, hits;
unsigned long long interrupts, exceptions;
std::string directory;
unsigned bits(float f) { unsigned v; std::memcpy(&v, &f, 4); return v; }
void write(const std::string &name, const void *data, size_t size) {
    FILE *f = std::fopen((directory + "/" + name).c_str(), "wb");
    if (!f || std::fwrite(data, 1, size, f) != size || std::fclose(f)) std::abort();
}
void snapshot(const char *kind, unsigned pc, unsigned short op, const Sh4Context *c) {
    char stem[80]; std::snprintf(stem, sizeof(stem), "%04u_%s_%08x", captured, kind, pc);
    const std::string name(stem);
    std::array<unsigned, 63> s{};
    for (unsigned i=0;i<16;++i) { s[i]=c->r[i]; s[21+i]=bits(c->fr[i]); s[37+i]=bits(c->xf[i]); }
    s[16]=c->pr; s[17]=c->sr.getFull(); s[18]=c->fpscr.full;
    s[19]=c->mac.l; s[20]=c->mac.h; s[53]=c->fpul; s[54]=c->gbr;
    for (unsigned i=0;i<8;++i) s[55+i]=c->r_bank[i];
    write(name+".ram.bin", &mem_b[0], 0x1000000);
    write(name+".vram.bin", &vram[0], 0x800000);
    write(name+".aica-ram.bin", &aica::aica_ram[0], 0x200000);
    write(name+".pvr-regs.bin", pvr_regs, sizeof(pvr_regs));
    write(name+".aica-regs.bin", aica::aica_reg, sizeof(aica::aica_reg));
    write(name+".holly-regs.bin", sb_regs, sizeof(sb_regs));
    // Diagnostic upstream serialization at a fetched-opcode boundary. Its
    // internal CPU PC is pc+2: it is not advertised as a resumable savestate.
    Serializer machineSize; dc_serialize(machineSize);
    std::vector<unsigned char> machine(machineSize.size());
    Serializer machineSerial(machine.data(),machine.size()); dc_serialize(machineSerial);
    write(name+".machine.bin",machine.data(),machine.size());
    Serializer size; icache.Serialize(size); ocache.Serialize(size);
    std::vector<unsigned char> cache(size.size());
    Serializer serial(cache.data(), cache.size()); icache.Serialize(serial); ocache.Serialize(serial);
    write(name+".cache.bin", cache.data(), cache.size());
    unsigned gd[22]; vf3NewGdSnapshot(gd);
    FILE *f=std::fopen((directory+"/"+name+".json").c_str(), "w");
    if (!f) std::abort();
    std::fprintf(f, "{\"schema\":\"vf3-new-reference-v3\",\"kind\":\"%s\",\"pc\":%u,\"opcode\":%u,\"instruction\":%llu,\"cycles\":%llu,\"hit\":%llu,\"interrupts\":%llu,\"exceptions\":%llu,\"raw_ram\":true,\"cache_flushed\":false,\"machine_state_resume_validated\":false,\"operand_cache_handler_active\":%s,\"registers\":[", kind,pc,op,instructions,(unsigned long long)sh4_sched_now64(),hits,interrupts,exceptions,ReadMem8==&ReadCachedMem<u8>?"true":"false");
    for (unsigned i=0;i<s.size();++i) std::fprintf(f,"%s%u",i?",":"",s[i]);
    std::fprintf(f,"],\"vbr\":%u,\"spc\":%u,\"ssr\":%u,\"sgr\":%u,\"dbr\":%u,\"ccr\":%u,\"mmucr\":%u,\"cache_serializer_version\":%u,\"gd\":[",c->vbr,c->spc,c->ssr,c->sgr,c->dbr,CCN_CCR.reg_data,CCN_MMUCR.reg_data,(unsigned)Serializer::Current);
    for (unsigned i=0;i<22;++i) std::fprintf(f,"%s%u",i?",":"",gd[i]);
    std::fprintf(f,"]}\n"); if (std::fclose(f)) std::abort();
    std::fprintf(stderr,"[vf3-new] snapshot %s instruction=%llu\n",stem,instructions);
    ++captured;
    if (captured >= maximum) done=true;
}
}
extern "C" bool vf3_new_reference_done() { return done; }
void vf3NewReferenceEvent(bool interrupt, unsigned code, unsigned pc) {
    if (interrupt) ++interrupts; else ++exceptions;
    if (directory.empty() || !armed) return;
    FILE *f=std::fopen((directory+"/events.jsonl").c_str(),"a");
    if (!f) std::abort();
    std::fprintf(f,"{\"instruction\":%llu,\"cycles\":%llu,\"interrupt\":%s,\"event\":%u,\"pc\":%u}\n",instructions,(unsigned long long)sh4_sched_now64(),interrupt?"true":"false",code,pc);
    if (std::fclose(f)) std::abort();
}
void vf3NewReferenceBefore(unsigned pc, unsigned short op, const Sh4Context *ctx) {
    if (!initialized) {
        initialized=true;
        const char *out=std::getenv("VF3_NEW_OUT");
        if (out) directory=out;
        const char *p=std::getenv("VF3_NEW_PC");
        if (!p) p="0x0c09616a";
        while (*p) {
            char *end; unsigned target=std::strtoul(p,&end,0);
            if (end==p || (*end && *end!=',')) std::abort();
            targets.push_back(target&0x1fffffffu); p=*end?end+1:end;
        }
        if ((p=std::getenv("VF3_NEW_MAX"))) maximum=std::strtoul(p,nullptr,0);
        if ((p=std::getenv("VF3_NEW_MAX_INSTRUCTIONS"))) limit=std::strtoull(p,nullptr,0);
        if (!maximum || maximum>16 || !limit) std::abort();
    }
    if (directory.empty()) return;
    ++instructions;
    if (done || instructions>limit) { done=true; throw debugger::Stop(); }
    if (countdown && !--countdown) {
        if (pc==entryPr) { snapshot("exit",pc,op,ctx); armed=false; }
        else countdown=1; // an interrupt may precede the caller's fetch
    }
    const unsigned canonical=pc&0x1fffffffu;
    bool watched=false;
    for (unsigned target:targets) if(canonical==target) watched=true;
    if (targets.size()>1) {
        for(unsigned seen:seenTargets) if(seen==canonical) watched=false;
        if (!done && watched) { ++hits; snapshot("entry",pc,op,ctx); seenTargets.push_back(canonical); }
        return;
    }
    if (!done && !armed && watched) {
        ++hits; snapshot("entry",pc,op,ctx); armed=true; entryPr=ctx->pr; entrySp=ctx->r[15];
    }
    // Return snapshot occurs after the delay slot, before the caller's next opcode.
    if (armed && op==0x000b && ctx->pr==entryPr && ctx->r[15]>=entrySp) countdown=2;
}
