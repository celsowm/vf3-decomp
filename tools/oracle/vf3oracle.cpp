/* Research-only interpreter observer. Game implementations live in src/.
 * VF3_CAPSULE=<file>, VF3_WATCH="pc <entry>" / "exitpc <entry> <transfer>".
 * VF3_ENTRY_PATCH=<file> supports "entry <trigger> <target>",
 * "seed <trigger>" (next seed variant), "reg <trigger> rN|pr|gbr|fpul|fpscr|sr <value>"
 * and "ram <trigger> <address> <value>". At a trigger instruction the hook
 * redirects the next fetch to target and starts a synthetic target capsule.
 * The probe is non-destructive: the pre-trigger register file, depth, the RAM
 * pages it dirties and the emulated operand cache lines covering them are all
 * restored on exit, so the game continues as if the synthetic call had not
 * happened and the trigger can fire again. Seed variants are applied
 * round-robin, so one hot call site sweeps a whole input space.
 * Records include invocation identity, before/after pages, extended state,
 * and executed opcodes. VF3CAP6 records device reads/writes as an ordered
 * tape; interrupts, MMU translation and asynchronous copies still invalidate
 * a specimen rather than being mistaken for game behavior. */
#include "vf3oracle.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_opcode_list.h"
#include "hw/sh4/sh4_cache.h"
#include "hw/sh4/sh4_interrupts.h"
#include "hw/sh4/modules/mmu.h"
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>

namespace {
constexpr unsigned PAGE = 4096, LIMIT = 128;
using State = std::array<unsigned, 63>;
struct Spec { unsigned pc, transfer, count = 0; };
struct Call {
    unsigned long long id;
    unsigned entry, depth, transfer = 0, flags = 0, countdown = 0, invalidAddress = 0;
    State in;
    std::map<unsigned, std::array<unsigned char, PAGE>> pages;
    std::vector<std::array<unsigned, 2>> ops;
    std::vector<std::array<unsigned, 4>> device;
    bool deferRecord = false;
    /* Synthetic entry: the pre-trigger game state, restored on exit so the
     * probed instruction and the run itself are left untouched. */
    /* Synthetic entry: the game state to resume with, captured at the first
     * instruction of the target, plus every RAM page the probe dirties. The
     * capture point matters: the trigger instruction itself has not run yet
     * when the hook fires, so snapshotting here would rewind effects such as
     * a prologue stack push. */
    bool synthetic = false;
    bool needsSnapshot = false;
    /* Set when the probe exceeds its instruction budget: a seed that never
     * returns. The specimen is retired at the next instruction boundary, flagged
     * invalid, and the game is rolled back. */
    bool aborted = false;
    bool skipFetched = false;
    /* The substituted first opcode, recorded explicitly: the target's entry
     * instruction never reaches the hook (it takes the trigger's fetch slot). */
    unsigned subPc = 0;
    unsigned short subOp = 0;
    /* Where the game must resume: the return address the probe was seeded with.
     * ctx->pc at an abort point is still inside the probe, so it cannot be used. */
    unsigned gameResume = 0;
    Sh4Context saved;
    unsigned savedDepth = 0;
    unsigned triggerPc = 0;
    std::map<unsigned, std::array<unsigned char, PAGE>> restorePages;
    std::vector<unsigned char> restoreRam;
};
struct SeedVariant {
    unsigned target = 0;
    std::vector<std::array<unsigned, 2>> regs;
    std::vector<std::array<unsigned, 2>> ram;
};
struct SyntheticPatch {
    unsigned target = 0;
    /* Seed sets applied round-robin, one per probe firing. A single trigger can
     * therefore sweep the input space of one function (branch-directed seeding)
     * instead of needing one hot trigger per input. */
    std::vector<SeedVariant> variants;
    unsigned cursor = 0;
};
FILE *output;
bool initialized, copying, probeOnly;
unsigned depth, samples = 64;
/* Instruction budget for a synthetic probe before it is retired as invalid. */
unsigned probeOps = 20000;
unsigned long long sequence;
unsigned long long completed;
std::string outputPath;
std::string hitsPath;
/* Probe-attempt accounting (VF3_ORACLE_DEBUG=<file>): tells a capture campaign
 * whether a thin synthetic-entry corpus is caused by few trigger hits or by
 * the probe path refusing to fire. */
std::string debugPath;
unsigned long long probes, probeBusy, probeNotWatched, probeSampled, targetArmed, restores;
std::map<unsigned,unsigned long long> probeByTrigger;
/* The redirect takes effect on the NEXT fetch, so the arm suppression has to
 * survive one instruction boundary; otherwise the generic watch re-arms the same
 * target entry and every probe records twice. */
unsigned pendingRedirect;
bool pendingSkip;
/* Opcode substitution: the target's first instruction takes the trigger's place
 * in the fetch stream, so the trigger never executes (see vf3oracle.h). */
unsigned pendingSubPc;
unsigned short pendingSubOp;
/* Context of the instruction currently being dispatched, so the exception hook
 * can finish an in-flight probe without a second context argument. */
const Sh4Context *lastCtx;
std::vector<Spec> specs;
std::vector<Call> active;
std::map<unsigned,std::vector<std::array<unsigned,2>>> entryPatches;
std::map<unsigned,SyntheticPatch> syntheticPatches;
std::map<std::pair<unsigned,unsigned>,unsigned> nonRam;
ReadMem8Func rd8; ReadMem16Func rd16; ReadMem32Func rd32; ReadMem64Func rd64;
WriteMem8Func wr8; WriteMem16Func wr16; WriteMem32Func wr32; WriteMem64Func wr64;

unsigned bits(float f) { unsigned u; std::memcpy(&u, &f, 4); return u; }
State snapshot(const Sh4Context *c) {
    State s{};
    for (unsigned i=0; i<16; ++i) { s[i]=c->r[i]; s[21+i]=bits(c->fr[i]); s[37+i]=bits(c->xf[i]); }
    s[16]=c->pr; s[17]=c->sr.getFull(); s[18]=c->fpscr.full;
    s[19]=c->mac.l; s[20]=c->mac.h; s[53]=c->fpul; s[54]=c->gbr;
    for (unsigned i=0; i<8; ++i) s[55+i]=c->r_bank[i];
    return s;
}
void flushPage(unsigned base) {
    for (unsigned off=0; off<PAGE; off+=32)
        ocache.WriteBack(0x8C000000u+base+off, true, true);
}
void finish(size_t i, unsigned pc, const Sh4Context *ctx) {
    /* Rollback ends every nested observation too. A child still active here
     * did not return within the probe; letting it survive would splice restored
     * game execution onto the child's instruction stream and falsely certify it. */
    if (active[i].synthetic) {
        for (size_t j=active.size(); j-->i+1;) {
            active[j].flags|=4;
            finish(j, pc, ctx);
        }
    }
    auto &c=active[i];
    for (const auto &p:c.pages) flushPage(p.first);
    if (c.invalidAddress) ++nonRam[{c.entry,c.invalidAddress}];
    State out=snapshot(ctx);
    unsigned header[7]={c.entry,pc,c.flags,(unsigned)c.pages.size(),(unsigned)c.ops.size(),63,(unsigned)c.device.size()};
    bool ok=std::fwrite(&c.id,8,1,output)==1 && std::fwrite(header,4,7,output)==7;
    ok = ok && std::fwrite(c.in.data(),4,63,output)==63 && std::fwrite(out.data(),4,63,output)==63;
    for (auto &p:c.pages) {
        unsigned base=0x0C000000u+p.first;
        ok = ok && std::fwrite(&base,4,1,output)==1;
        ok = ok && std::fwrite(p.second.data(),1,PAGE,output)==PAGE;
        ok = ok && std::fwrite(&mem_b[p.first],1,PAGE,output)==PAGE;
    }
    if (!c.ops.empty()) ok = ok && std::fwrite(c.ops.data(),8,c.ops.size(),output)==c.ops.size();
    if (!c.device.empty()) ok = ok && std::fwrite(c.device.data(),16,c.device.size(),output)==c.device.size();
    if (!ok || std::fflush(output)!=0) { std::fprintf(stderr,"[vf3oracle] write failed\n"); std::abort(); }
    /* A synthetic probe is an observation, not an event: undo every RAM page
     * it dirtied and restore the exact game context captured at the trigger,
     * so the following instruction runs as if the probe never happened. */
    if (c.synthetic) {
        Sh4Context *m=const_cast<Sh4Context *>(ctx);
        /* The emulated operand cache is write-back: the probe's stores are still
         * sitting in dirty cache lines, and the game's own dirty lines for the
         * same pages have not reached main memory either. Write every affected
         * line back (preserving game data), drop it, and only then overwrite the
         * pages with the pre-probe images. Skipping this leaves the game reading
         * the probe's values out of the cache and the run diverges within a few
         * hundred frames. */
        ocache.WriteBackAll();
        std::memcpy(&mem_b[0],c.restoreRam.data(),c.restoreRam.size());
        /* The probe's fixture routes the target's return to the instruction
         * after the trigger, so the interpreter has already resumed the game's
         * own instruction stream. Restore every other piece of architectural
         * state while leaving the PC progression the fetch unit chose alone. */
        /* CpuRunning is the host's stop request, not guest architectural state.
         * A rollback must never turn execution back on after Emulator::stop(). */
        const bool running=m->CpuRunning;
        *m=c.saved;
        m->CpuRunning=running;
        if (!running) m->cycle_counter=0;
        /* Fixtures can cover live code pages, and SR's decoded interrupt mask
         * lives outside the copied context. Restore both derived states. */
        icache.Invalidate();
        SRdecode();
        /* Re-fetch the original trigger after restoring its pre-instruction
         * state. Skipping a prologue loses its stack push; skipping a call
         * loses its result. The re-fetch bypasses this observer once. */
        m->pc=c.triggerPc;
        pendingSkip=true;
        /* The SH-4 FPU rounding mode also lives in the host FP environment, which
         * the probe's own FPU instructions may have changed. Without re-applying it
         * the game keeps computing with the probe's rounding mode and its state
         * quietly diverges even though every architectural register was restored. */
        m->restoreHostRoundingMode();
        depth=c.savedDepth;
        ++restores;
    }
    if (c.skipFetched) pendingSkip=true;
    active.erase(active.begin()+i);
    ++completed;
}
void close_output() {
    if (!output) return;
    if (std::fflush(output)!=0 || std::fclose(output)!=0) std::abort();
    output=nullptr;
    FILE *f=std::fopen((outputPath+".summary.json").c_str(),"wb");
    if (!f) std::abort();
    std::fprintf(f,"{\"started\":%llu,\"completed\":%llu,\"armed\":%llu,\"unaccounted\":%lld,\"incomplete\":[",
                 completed+active.size(), completed, sequence,
                 (long long)sequence-(long long)completed-(long long)active.size());
    for (size_t i=0;i<active.size();++i)
        std::fprintf(f,"%s{\"invocation\":%llu,\"entry\":\"0x%08x\",\"flags\":%u}",
                     i?",":"",active[i].id,active[i].entry,active[i].flags|16);
    std::fprintf(f,"],\"non_ram\":[");
    bool first=true;
    for (const auto &item:nonRam) {
        std::fprintf(f,"%s{\"entry\":\"0x%08x\",\"address\":\"0x%08x\",\"count\":%u}",
                     first?"":",",item.first.first,item.first.second,item.second);
        first=false;
    }
    std::fprintf(f,"]}\n");
    if (std::fclose(f)!=0) std::abort();
    if (debugPath[0]) {
        FILE *d=std::fopen(debugPath.c_str(),"wb");
        if (!d) std::abort();
        std::fprintf(d,"{\"probes\":%llu,\"probe_busy\":%llu,\"probe_notwatched\":%llu,"
                        "\"probe_sampled\":%llu,\"target_armed\":%llu,\"restores\":%llu,\"per_trigger\":{",
                     probes, probeBusy, probeNotWatched, probeSampled, 0ull, restores);
        bool first=true;
        for (const auto &item:probeByTrigger) {
            std::fprintf(d,"%s\"0x%08x\":%llu",first?"":",",item.first&0x7FFFFFFFu,item.second);
            first=false;
        }
        std::fprintf(d,"}}\n");
        if (std::fclose(d)!=0) std::abort();
    }
}
void close_hits() {
    if (hitsPath.empty()) return;
    FILE *f=std::fopen(hitsPath.c_str(),"wb");
    if (!f) std::abort();
    if (std::fprintf(f,"entry,hits\n")<0) std::abort();
    for (const auto &s:specs)
        if (std::fprintf(f,"0x%08x,%u\n",s.pc,s.count)<0) std::abort();
    if (std::fclose(f)!=0) std::abort();
}
void applySyntheticRegs(Sh4Context *ctx, const SeedVariant &variant) {
    for (const auto &item:variant.regs) {
        unsigned kind=item[0], value=item[1];
        if (kind<16) ctx->r[kind]=value;
        else if (kind==16) ctx->pr=value;
        else if (kind==17) ctx->gbr=value;
        else if (kind==18) ctx->fpul=value;
        else if (kind==19) {
            ctx->fpscr.full=value;
            Sh4Context::UpdateFPSCR(ctx);
        }
        else if (kind==20) ctx->sr.setFull(value);
        else if (kind==21) ctx->pc=value;
        else if (kind>=32 && kind<48) std::memcpy(&ctx->fr[kind-32],&value,4);
        else if (kind>=48 && kind<64) std::memcpy(&ctx->xf[kind-48],&value,4);
    }
}
void touch(unsigned addr, unsigned size) {
    if (copying || active.empty()) return;
    if (!IsOnRam(addr) || mmu_enabled()) {
        for (auto &c:active) { c.flags|=2; if (!c.invalidAddress) c.invalidAddress=addr; }
        return;
    }
    unsigned first=addr&0x00FFFFFFu;
    if (size>0x01000000u-first) { vf3OracleInvalidate(2); return; }
    for (auto &c:active) for (unsigned a=first&~(PAGE-1); a<=((first+size-1)&~(PAGE-1)); a+=PAGE) {
        if (c.pages.count(a)) continue;
        if (c.pages.size()==LIMIT) { c.flags|=4; continue; }
        /* Nested natural observations must see the parent's cached stores. */
        flushPage(a);
        auto &page=c.pages[a];
        std::memcpy(page.data(), &mem_b[a], PAGE);
        /* A synthetic probe must not leave RAM modified, so keep an
         * independent pre-probe image of the same page for the exit restore. */
        if (c.synthetic && !c.restorePages.count(a) && c.restorePages.size()<LIMIT) {
            auto &saved=c.restorePages[a];
            std::memcpy(saved.data(), &mem_b[a], PAGE);
        }
    }
}
void device(unsigned addr,unsigned size,unsigned value,unsigned write) {
    if (copying) return;
    for (auto &c:active) {
        if (c.device.size()>=16384) { c.flags|=4; continue; }
        c.device.push_back({addr&0x1fffffffu,size,value,write});
    }
}
bool device_address(unsigned a) { return !IsOnRam(a) && !mmu_enabled(); }
bool blockSyntheticDevice(unsigned addr) {
    bool blocked=false;
    for (auto &c:active) if (c.synthetic) {
        /* Device state cannot be restored from RAM pages. Reject the specimen
         * before issuing an access, then restore at the next instruction. */
        c.flags|=2; c.invalidAddress=addr;
        c.aborted=true; c.skipFetched=true; c.countdown=1; blocked=true;
    }
    return blocked;
}
u8 DYNACALL r8(unsigned a) { bool d=device_address(a); if(d && blockSyntheticDevice(a)) return 0; if(!d) touch(a,1); u8 v=rd8(a); if(d) device(a,1,v,0); return v; }
u16 DYNACALL r16(unsigned a) { bool d=device_address(a); if(d && blockSyntheticDevice(a)) return 0; if(!d) touch(a,2); u16 v=rd16(a); if(d) device(a,2,v,0); return v; }
u32 DYNACALL r32(unsigned a) { bool d=device_address(a); if(d && blockSyntheticDevice(a)) return 0; if(!d) touch(a,4); u32 v=rd32(a); if(d) device(a,4,v,0); return v; }
u64 DYNACALL r64(unsigned a) { bool d=device_address(a); if(d && blockSyntheticDevice(a)) return 0; if(!d) touch(a,8); u64 v=rd64(a); if(d) { device(a,4,(u32)v,0); device(a+4,4,(u32)(v>>32),0); } return v; }
void DYNACALL w8(unsigned a,u8 v) { if(device_address(a)) { if(blockSyntheticDevice(a)) return; device(a,1,v,1); } else touch(a,1); wr8(a,v); }
void DYNACALL w16(unsigned a,u16 v) { if(device_address(a)) { if(blockSyntheticDevice(a)) return; device(a,2,v,1); } else touch(a,2); wr16(a,v); }
void DYNACALL w32(unsigned a,u32 v) { if(device_address(a)) { if(blockSyntheticDevice(a)) return; device(a,4,v,1); } else touch(a,4); wr32(a,v); }
void DYNACALL w64(unsigned a,u64 v) { if(device_address(a)) { if(blockSyntheticDevice(a)) return; device(a,4,(u32)v,1); device(a+4,4,(u32)(v>>32),1); } else touch(a,8); wr64(a,v); }
void hooks() {
    if (ReadMem32==r32) return;
    rd8=ReadMem8; rd16=ReadMem16; rd32=ReadMem32; rd64=ReadMem64;
    wr8=WriteMem8; wr16=WriteMem16; wr32=WriteMem32; wr64=WriteMem64;
    ReadMem8=r8; ReadMem16=r16; ReadMem32=r32; ReadMem64=r64;
    WriteMem8=w8; WriteMem16=w16; WriteMem32=w32; WriteMem64=w64;
}
void opcode_oracle(const Sh4Context *ctx) {
    const char *path=std::getenv("VF3_OPCODE_ORACLE");
    if (!path) return;
    FILE *f=std::fopen(path,"wb");
    if (!f) std::abort();
    Sh4Context test=*ctx;
    test.fpscr.full=0x240001u;
    test.restoreHostRoundingMode();
    for (unsigned a=0;a<65536;++a) {
        test.fpul=a; OpPtr[0xF0FD](&test,0xF0FD);
        unsigned pair[2]={bits(test.fr[0]),bits(test.fr[1])};
        if (std::fwrite(pair,4,2,f)!=2) std::abort();
    }
    /* Separate opcode suite, with deterministic edge and randomized inputs. */
    std::fclose(f);
    std::string suite=std::string(path)+".ops";
    f=std::fopen(suite.c_str(),"wb"); if (!f) std::abort();
    unsigned seed=0x564633u;
    unsigned edge[]={0,0x80000000u,1,0x007FFFFFu,0x00800000u,0x3F800000u,0x40000000u,0x7F7FFFFFu,0x7F800000u,0xFF800000u,0x7FC00000u,0xBF800000u};
    for (unsigned mode:{0u,1u,0x40000u,0x40001u,0x240000u,0x240001u})
    for (unsigned op:{0xF37Du,0xF0EDu,0xF1FDu,0xF32Du,0xF33Du,0xF34Eu}) for (unsigned k=0;k<4096;++k) {
        test=*ctx; test.fpscr.full=mode; test.restoreHostRoundingMode();
        for (unsigned j=0;j<16;++j) {
            seed^=seed<<13; seed^=seed>>17; seed^=seed<<5;
            unsigned u=k<12?edge[(k+j)%12]:(seed&0x807FFFFFu)|((100+(seed%50))<<23);
            std::memcpy(&test.fr[j],&u,4);
            seed^=seed<<13; seed^=seed>>17; seed^=seed<<5;
            u=k<12?edge[(k+j+3)%12]:(seed&0x807FFFFFu)|((100+(seed%50))<<23);
            std::memcpy(&test.xf[j],&u,4);
        }
        test.fpul=k<12?edge[k]:seed;
        State before=snapshot(&test);
        OpPtr[op](&test,op);
        State after=snapshot(&test);
        if (std::fwrite(&op,4,1,f)!=1 || std::fwrite(before.data(),4,54,f)!=54 || std::fwrite(after.data(),4,54,f)!=54) std::abort();
    }
    std::fclose(f);
    std::fprintf(stderr,"[vf3oracle] 65536 FSCA angles and 147456 opcode cases exported\n");
    std::fflush(stderr);
    std::_Exit(0); /* Avoid emulator-thread shutdown joining itself. */
}
void init(const Sh4Context *ctx) {
    initialized=true;
    probeOnly=getenv("VF3_PROBE_ONLY")!=nullptr;
    opcode_oracle(ctx);
    /* Development fixtures: "addr value" applies at startup; "entry addr
     * value" applies at that watched entry before its before-state snapshot.
     * Independent acceptance runs leave VF3_RAM_PATCH unset. */
    const char *patch=std::getenv("VF3_RAM_PATCH");
    if (patch && *patch) {
        FILE *f=std::fopen(patch,"r");
        if (!f) { std::fprintf(stderr,"[vf3oracle] cannot open RAM patch %s\n",patch); std::abort(); }
        char line[128]; unsigned addr,value,count=0;
        while (std::fgets(line,sizeof(line),f)) {
            if (line[0]=='#' || line[0]=='\n' || line[0]=='\r') continue;
            unsigned a,b,c;
            int fields=std::sscanf(line,"%x %x %x",&a,&b,&c);
            if (fields==2) { addr=a; value=b; }
            else if (fields==3) { addr=b; value=c; }
            else { std::fprintf(stderr,"[vf3oracle] invalid RAM patch line: %s",line); std::abort(); }
            if (addr<0x0c000000u || addr>0x0cfffffcu || (addr&3u)) {
                std::fprintf(stderr,"[vf3oracle] invalid RAM patch line: %s",line);
                std::abort();
            }
            if (fields==3) entryPatches[a|0x80000000u].push_back({addr,value});
            else std::memcpy(&mem_b[addr&0x00ffffffu],&value,4);
            ++count;
        }
        std::fclose(f);
        std::fprintf(stderr,"[vf3oracle] loaded %u RAM fixture words from %s (%zu entry roots)\n",count,patch,entryPatches.size());
    }
    const char *entryPatch=std::getenv("VF3_ENTRY_PATCH");
    if (entryPatch && *entryPatch) {
        FILE *f=std::fopen(entryPatch,"r");
        if (!f) { std::fprintf(stderr,"[vf3oracle] cannot open entry patch %s\n",entryPatch); std::abort(); }
        char line[256], field[32]; unsigned trigger,value,target;
        size_t variants=0;
        while (std::fgets(line,sizeof(line),f)) {
            if (line[0]=='#' || line[0]=='\n' || line[0]=='\r') continue;
            if (std::sscanf(line,"entry %x %x",&trigger,&target)==2) {
                syntheticPatches[trigger|0x80000000u].target=target|0x80000000u;
            } else if (std::sscanf(line,"target %x %x",&trigger,&target)==2) {
                auto &patch=syntheticPatches[trigger|0x80000000u];
                if (patch.variants.empty()) patch.variants.push_back(SeedVariant{});
                patch.variants.back().target=target;
            } else if (std::sscanf(line,"seed %x",&trigger)==1) {
                /* Start the next seed variant for this trigger: later reg/ram
                 * lines belong to it. Seed sets are applied round-robin, so one
                 * trigger sweeps a whole input space across its firings. */
                auto &patch=syntheticPatches[trigger|0x80000000u];
                if (patch.variants.empty()) patch.variants.push_back(SeedVariant{});
                patch.variants.push_back(SeedVariant{});
                ++variants;
            } else if (std::sscanf(line,"reg %x %31s %x",&trigger,field,&value)==3) {
                unsigned kindCode=0;
                if (std::sscanf(field,"r%u",&kindCode)==1 && kindCode<16) {}
                else if (!std::strcmp(field,"pr")) kindCode=16;
                else if (!std::strcmp(field,"gbr")) kindCode=17;
                else if (!std::strcmp(field,"fpul")) kindCode=18;
                else if (!std::strcmp(field,"fpscr")) kindCode=19;
                else if (!std::strcmp(field,"sr")) kindCode=20;
                else if (!std::strcmp(field,"pc")) kindCode=21;
                else if (std::sscanf(field,"fr%u",&kindCode)==1 && kindCode<16) kindCode+=32;
                else if (std::sscanf(field,"xf%u",&kindCode)==1 && kindCode<16) kindCode+=48;
                else { std::fprintf(stderr,"[vf3oracle] invalid entry register: %s\n",line); std::abort(); }
                auto &patch=syntheticPatches[trigger|0x80000000u];
                if (patch.variants.empty()) patch.variants.push_back(SeedVariant{});
                patch.variants.back().regs.push_back({kindCode,value});
            } else if (std::sscanf(line,"ram %x %x %x",&trigger,&target,&value)==3) {
                if (target<0x0c000000u || target>0x0cfffffcu || (target&3u)) {
                    std::fprintf(stderr,"[vf3oracle] invalid entry RAM patch: %s",line); std::abort();
                }
                auto &patch=syntheticPatches[trigger|0x80000000u];
                if (patch.variants.empty()) patch.variants.push_back(SeedVariant{});
                patch.variants.back().ram.push_back({target,value});
            } else {
                std::fprintf(stderr,"[vf3oracle] invalid entry patch line: %s",line); std::abort();
            }
        }
        std::fclose(f);
        std::fprintf(stderr,"[vf3oracle] loaded %zu synthetic entry triggers from %s (%zu seed variants)\n",
                     syntheticPatches.size(), entryPatch, variants+1);
    }
    const char *path=std::getenv("VF3_CAPSULE");
    const char *hits=std::getenv("VF3_HITS");
    if (path && hits) { std::fprintf(stderr,"[vf3oracle] choose capsule or hits\n"); std::abort(); }
    if (!path && !hits) return;
    if (path) {
        output=std::fopen(path,"wb"); if (!output) std::abort();
        outputPath=path;
        std::atexit(close_output);
        if (std::fwrite("VF3CAP6\0",1,8,output)!=8) std::abort();
    } else { hitsPath=hits; std::atexit(close_hits); }
    const char *n=std::getenv("VF3_CAPSULE_N"); if(n) samples=std::strtoul(n,nullptr,0);
    const char *dbg=std::getenv("VF3_ORACLE_DEBUG"); if(dbg&&*dbg) debugPath=dbg;
    const char *budget=std::getenv("VF3_PROBE_OPS"); if(budget&&*budget) probeOps=std::strtoul(budget,nullptr,0);
    /* Start the round-robin at an offset so successive campaign runs explore a
     * different slice of a long seed plan instead of repeating the first N. */
    const char *cursor=std::getenv("VF3_PROBE_CURSOR");
    if (cursor&&*cursor) {
        unsigned start=std::strtoul(cursor,nullptr,0);
        for (auto &item:syntheticPatches) item.second.cursor=start;
    }
    const char *watch=std::getenv("VF3_WATCH");
    FILE *f=watch?std::fopen(watch,"r"):nullptr;
    if(!f) { std::fprintf(stderr,"[vf3oracle] watch file required\n"); std::abort(); }
    char line[256]; unsigned a,b;
    while(std::fgets(line,sizeof(line),f)) if(std::sscanf(line,"pc %x",&a)==1) {
        a|=0x80000000u;
        if(std::none_of(specs.begin(),specs.end(),[a](const Spec&s){return s.pc==a;})) specs.push_back({a,0,0});
    }
    std::rewind(f);
    while(std::fgets(line,sizeof(line),f)) if(std::sscanf(line,"exitpc %x %x",&a,&b)==2)
        for(auto &s:specs) if(s.pc==(a|0x80000000u)) s.transfer=b|0x80000000u;
    std::fclose(f);
    std::sort(specs.begin(),specs.end(),[](const Spec &a,const Spec &b){return a.pc<b.pc;});
}
}
void vf3OraclePrepare() { if(!initialized) init(&Sh4cntx); }
void vf3OracleInvalidate(unsigned reason) { for(auto &c:active) c.flags|=reason; }
bool vf3OracleTakeSkip() { if (!pendingSkip) return false; pendingSkip=false; return true; }
bool vf3OracleTakeSubstitute(unsigned *pc, unsigned short *op) {
    if (!pendingSubPc) return false;
    *pc=pendingSubPc; *op=pendingSubOp;
    pendingSubPc=0; pendingSubOp=0;
    return true;
}
bool vf3OracleAbortProbe() {
    /* A seed that steers the target into unmapped memory faults. Record the
     * specimen as invalid (it earns no credit), roll the game state back to the
     * trigger and drop the exception. Without this the emulator treats the
     * handler's own state as a nested fault and aborts the run, which would cap
     * every seed campaign at the first poisonous input. */
    if (!output || !lastCtx) return false;
    for (size_t i=active.size();i-->0;) {
        if (!active[i].synthetic) continue;
        active[i].flags|=1;
        active[i].skipFetched=true;
        finish(i, 0, lastCtx);
        return true;
    }
    return false;
}
void vf3OracleBefore(unsigned pc, unsigned short op,const Sh4Context *ctx) {
    if(!initialized) init(ctx);
    lastCtx=ctx;
    /* Exception rollback happens outside ReadNexOp. Its next fetch must replay
     * the trigger before another probe can arm; otherwise the pending skip
     * discards the new target's first instruction instead. */
    if (pendingSkip) {
        const_cast<Sh4Context *>(ctx)->pc=pc;
        return;
    }
    if (!hitsPath.empty()) {
        /* Install the memory hooks before counting: without them the survey runs
         * faster than a capture run, the game lands in a different fight phase and
         * the hit counts describe code the capture would never reach. */
        hooks();
        unsigned canon=pc|0x80000000u;
        auto s=std::lower_bound(specs.begin(),specs.end(),canon,
            [](const Spec &spec,unsigned value){return spec.pc<value;});
        if (s!=specs.end() && s->pc==canon) ++s->count;
        return;
    }
    if(!output) return;
    hooks();
    for(size_t i=active.size();i-->0;) {
        if (!active[i].countdown) continue;
        if (--active[i].countdown) continue;
        if (active[i].aborted) active[i].flags|=4;
        finish(i,pc,ctx);
        if (pendingSkip) return;
    }
    unsigned canon=pc|0x80000000u;
    unsigned redirected=pendingRedirect;
    pendingRedirect=0;
    auto synthetic=syntheticPatches.find(canon);
    if (synthetic!=syntheticPatches.end() && synthetic->second.target) {
        ++probeByTrigger[canon|0x40000000u];
        if (!active.empty()) { ++probeBusy; vf3OracleInvalidate(4); }
        else {
            SyntheticPatch &patch=synthetic->second;
            const SeedVariant variant=patch.variants.empty()? SeedVariant{}
                : patch.variants[patch.cursor++%patch.variants.size()];
            const unsigned targetPc=variant.target? variant.target : patch.target;
            const unsigned watchPc=targetPc|0x80000000u;
            auto target=std::lower_bound(specs.begin(),specs.end(),watchPc,
                [](const Spec &s,unsigned value){return s.pc<value;});
            if (target==specs.end() || target->pc!=watchPc) {
                ++probeNotWatched;
                std::fprintf(stderr,"[vf3oracle] synthetic target 0x%08x is not watched\n",synthetic->second.target); std::abort();
            }
            /* Once full, leave the game context alone. An unrecorded redirect
             * has no Call to restore its RAM or registers. */
            if (target->count>=samples) { ++probeSampled; return; }
            Sh4Context *mutableCtx=const_cast<Sh4Context *>(ctx);
            /* Round-robin the trigger's seed variants so consecutive firings walk
             * the seed plan instead of repeating one input. */
            Call c; c.id=++sequence; c.entry=watchPc; c.depth=depth;
            c.synthetic=true; c.saved=*ctx; c.savedDepth=depth; c.triggerPc=pc;
            /* A callee can perform bulk RAM writes outside the scalar hooks.
             * Such specimens remain invalid, but rollback must undo them too.
             * Flush dirty game lines before taking the complete RAM image. */
            ocache.WriteBackAll();
            c.restoreRam.assign(&mem_b[0],&mem_b[0]+0x01000000u);
            /* No re-snapshot: with opcode substitution the trigger never runs, so
             * the state captured here already is the pre-target state. */
            /* Snapshot the fixture pages before overwriting them, so the exit
             * restore returns RAM to its pre-probe contents. These images are
             * kept apart from the capsule's own before/after pages. */
            for (const auto &word:variant.ram) {
                unsigned base=(word[0]&0x00ffffffu) & ~(PAGE-1);
                if (!c.restorePages.count(base) && c.restorePages.size()<LIMIT) {
                    flushPage(base);
                    auto &page=c.restorePages[base];
                    std::memcpy(page.data(),&mem_b[base],PAGE);
                }
            }
            applySyntheticRegs(mutableCtx,variant);
            /* Seed the fixture. The emulated operand cache is write-back and the
             * game has almost certainly touched these pages already, so a bare
             * host write into mem_b is invisible: the core keeps hitting cached
             * lines and reads something other than the value seeded here. That
             * showed up as a deterministic *inversion* - seeding a gate word
             * open closed the gate, seeding it closed let the body run further
             * (docs/re/entry_patch.md, "OPEN DEFECT"). Write back and drop each
             * affected line before overwriting main memory, exactly as the
             * rollback path does below, so the guest observes the seed. */
            for (const auto &word:variant.ram) {
                unsigned line=word[0]&0x00ffffffu;
                ocache.WriteBack(0x8C000000u+line,true,true);
            }
            for (const auto &word:variant.ram)
                std::memcpy(&mem_b[word[0]&0x00ffffffu],&word[1],4);
            mutableCtx->pc=targetPc;
            redirected=targetPc;
            pendingRedirect=redirected;
            /* Substitute the target's first opcode for the trigger's, so the
             * interpreter never executes the trigger itself. */
            pendingSubPc=redirected;
            pendingSubOp=rd16(redirected&0x1FFFFFFF);
            if (target->count<samples) {
                ++target->count; ++probes; ++probeByTrigger[canon];
                c.transfer=target->transfer; c.in=snapshot(mutableCtx); c.deferRecord=true;
                c.gameResume=mutableCtx->pr;
                c.subPc=pendingSubPc; c.subOp=pendingSubOp;
                active.push_back(std::move(c));
            }
            /* The redirect already owns the target's invocation: the generic watch
             * below would arm a second, near-identical record for the same entry
             * (same instruction stream, one word different in the entry state) and
             * burn half the sample budget on duplicates. */
        }
    }
    auto spec=std::lower_bound(specs.begin(),specs.end(),canon,
        [](const Spec &s,unsigned value){return s.pc<value;});
    if(!probeOnly && canon!=redirected && spec!=specs.end() && spec->pc==canon && spec->count<samples) {
        ++spec->count;
        if(active.size()>=64) vf3OracleInvalidate(4);
        else {
            auto fixture=entryPatches.find(canon);
            if (fixture!=entryPatches.end()) {
                if (!active.empty()) {
                    std::fprintf(stderr,"[vf3oracle] nested entry fixture at %08x\n",canon);
                    std::abort();
                }
                for (const auto &word:fixture->second)
                    std::memcpy(&mem_b[word[0]&0x00ffffffu],&word[1],4);
            }
            Call c; c.id=++sequence; c.entry=pc; c.depth=depth; c.transfer=spec->transfer; c.in=snapshot(ctx);
            active.push_back(std::move(c));
        }
    }
    for(auto &c:active) {
        if (c.deferRecord) {
            c.deferRecord=false;
            if (c.subPc) c.ops.push_back({c.subPc,c.subOp});
            /* Seed diagnostics: this is the instant the target's first (substituted)
             * instruction is about to execute, i.e. the first moment the guest can
             * observe the seed. Compare the register file here against the values
             * the patch asked for. `pr` is honoured but ctx->r[kind] appeared not
             * to be - see docs/re/entry_patch.md "seed variants are inert except
             * pr" - so dump it rather than guess. */
            if (c.synthetic && getenv("VF3_SEED_DEBUG")) {
                std::fprintf(stderr,"[vf3oracle] seed-debug target=%08x subpc=%08x pr=%08x regs:",
                             c.entry,c.subPc,ctx->pr);
                for (int i=0;i<16;i++) std::fprintf(stderr," r%d=%08x",i,ctx->r[i]);
                std::fprintf(stderr,"\n");
            }
            continue;
        }
        /* First instruction actually reached inside the target: the trigger
         * instruction has now run, so this is the state the game must resume
         * with once the probe is rolled back. */
        if (c.needsSnapshot) {
            c.needsSnapshot=false;
            c.saved=*ctx; c.savedDepth=depth;
        }
        if(c.ops.size()<100000) c.ops.push_back({pc,(unsigned)op}); else c.flags|=4;
        /* Retire a probe that never returns: some seeds drive the target into a
         * spin, and a 100k-instruction excursion is long enough to wreck the run
         * (nested exceptions, interrupt bookkeeping inside the probe). Bail at
         * the next instruction boundary so the rollback is clean. */
        if(c.synthetic && !c.aborted && c.ops.size()>=probeOps) {
            c.aborted=true; c.skipFetched=true; c.countdown=1;
        }
        /* Stop recording over-budget natural calls without changing execution.
         * A task entry that never returns must not occupy every capture slot. */
        if(!c.synthetic && c.ops.size()>=probeOps) {
            c.flags|=4; c.countdown=1;
        }
        if(c.transfer==canon) c.countdown=2;
        if(op==0x000B && (c.depth==depth || (ctx->pr==c.in[16] && ctx->r[15]>=c.in[15]))) c.countdown=2;
        /* Interrupt paths are invalid specimens. Retire them after RTE so a
         * watched handler without RTS cannot occupy every capture slot. */
        if(op==0x002B) { c.flags|=1; c.countdown=2; }
    }
    if((op&0xF000)==0xB000 || (op&0xF0FF)==0x400B || (op&0xF0FF)==0x0003) ++depth;
    if(op==0x000B && depth) --depth;
}
