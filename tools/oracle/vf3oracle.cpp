/* Research-only interpreter observer. Game implementations live in src/.
 * VF3_CAPSULE=<file>, VF3_WATCH="pc <entry>" / "exitpc <entry> <transfer>".
 * Records include invocation identity, before/after pages, extended state,
 * and executed opcodes. Interrupts, MMIO and asynchronous copies invalidate
 * a specimen rather than being mistaken for game behavior. */
#include "vf3oracle.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_opcode_list.h"
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
using State = std::array<unsigned, 55>;
struct Spec { unsigned pc, transfer, count = 0; };
struct Call {
    unsigned long long id;
    unsigned entry, depth, flags = 0, countdown = 0;
    State in;
    std::map<unsigned, std::array<unsigned char, PAGE>> pages;
    std::vector<std::array<unsigned, 2>> ops;
};
FILE *output;
bool initialized, copying;
unsigned depth, samples = 64;
unsigned long long sequence;
unsigned long long completed;
std::string outputPath;
std::string hitsPath;
std::vector<Spec> specs;
std::vector<Call> active;
ReadMem8Func rd8; ReadMem16Func rd16; ReadMem32Func rd32; ReadMem64Func rd64;
WriteMem8Func wr8; WriteMem16Func wr16; WriteMem32Func wr32; WriteMem64Func wr64;

unsigned bits(float f) { unsigned u; std::memcpy(&u, &f, 4); return u; }
State snapshot(const Sh4Context *c) {
    State s{};
    for (unsigned i=0; i<16; ++i) { s[i]=c->r[i]; s[21+i]=bits(c->fr[i]); s[37+i]=bits(c->xf[i]); }
    s[16]=c->pr; s[17]=c->sr.getFull(); s[18]=c->fpscr.full;
    s[19]=c->mac.l; s[20]=c->mac.h; s[53]=c->fpul; s[54]=c->gbr;
    return s;
}
void finish(size_t i, unsigned pc, const Sh4Context *ctx) {
    auto &c=active[i];
    State out=snapshot(ctx);
    unsigned header[6]={c.entry,pc,c.flags,(unsigned)c.pages.size(),(unsigned)c.ops.size(),55};
    bool ok=std::fwrite(&c.id,8,1,output)==1 && std::fwrite(header,4,6,output)==6;
    ok = ok && std::fwrite(c.in.data(),4,55,output)==55 && std::fwrite(out.data(),4,55,output)==55;
    for (auto &p:c.pages) {
        unsigned base=0x0C000000u+p.first;
        ok = ok && std::fwrite(&base,4,1,output)==1;
        ok = ok && std::fwrite(p.second.data(),1,PAGE,output)==PAGE;
        ok = ok && std::fwrite(&mem_b[p.first],1,PAGE,output)==PAGE;
    }
    if (!c.ops.empty()) ok = ok && std::fwrite(c.ops.data(),8,c.ops.size(),output)==c.ops.size();
    if (!ok || std::fflush(output)!=0) { std::fprintf(stderr,"[vf3oracle] write failed\n"); std::abort(); }
    active.erase(active.begin()+i);
    ++completed;
}
void close_output() {
    if (!output) return;
    if (std::fflush(output)!=0 || std::fclose(output)!=0) std::abort();
    output=nullptr;
    FILE *f=std::fopen((outputPath+".summary.json").c_str(),"wb");
    if (!f) std::abort();
    std::fprintf(f,"{\"started\":%llu,\"completed\":%llu,\"incomplete\":[",sequence,completed);
    for (size_t i=0;i<active.size();++i)
        std::fprintf(f,"%s{\"invocation\":%llu,\"entry\":\"0x%08x\",\"flags\":%u}",
                     i?",":"",active[i].id,active[i].entry,active[i].flags|16);
    std::fprintf(f,"]}\n");
    if (std::fclose(f)!=0) std::abort();
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
void touch(unsigned addr, unsigned size) {
    if (copying || active.empty()) return;
    if (!IsOnRam(addr) || mmu_enabled()) { vf3OracleInvalidate(2); return; }
    unsigned first=addr&0x00FFFFFFu;
    if (size>0x01000000u-first) { vf3OracleInvalidate(2); return; }
    for (auto &c:active) for (unsigned a=first&~(PAGE-1); a<=((first+size-1)&~(PAGE-1)); a+=PAGE) {
        if (c.pages.count(a)) continue;
        if (c.pages.size()==LIMIT) { c.flags|=4; continue; }
        auto &page=c.pages[a];
        std::memcpy(page.data(), &mem_b[a], PAGE);
    }
}
u8 DYNACALL r8(unsigned a) { touch(a,1); return rd8(a); }
u16 DYNACALL r16(unsigned a) { touch(a,2); return rd16(a); }
u32 DYNACALL r32(unsigned a) { touch(a,4); return rd32(a); }
u64 DYNACALL r64(unsigned a) { touch(a,8); return rd64(a); }
void DYNACALL w8(unsigned a,u8 v) { touch(a,1); wr8(a,v); }
void DYNACALL w16(unsigned a,u16 v) { touch(a,2); wr16(a,v); }
void DYNACALL w32(unsigned a,u32 v) { touch(a,4); wr32(a,v); }
void DYNACALL w64(unsigned a,u64 v) { touch(a,8); wr64(a,v); }
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
    opcode_oracle(ctx);
    const char *path=std::getenv("VF3_CAPSULE");
    const char *hits=std::getenv("VF3_HITS");
    if (path && hits) { std::fprintf(stderr,"[vf3oracle] choose capsule or hits\n"); std::abort(); }
    if (!path && !hits) return;
    if (path) {
        output=std::fopen(path,"wb"); if (!output) std::abort();
        outputPath=path;
        std::atexit(close_output);
        if (std::fwrite("VF3CAP4\0",1,8,output)!=8) std::abort();
    } else { hitsPath=hits; std::atexit(close_hits); }
    const char *n=std::getenv("VF3_CAPSULE_N"); if(n) samples=std::strtoul(n,nullptr,0);
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
    if (hits) std::sort(specs.begin(),specs.end(),[](const Spec &a,const Spec &b){return a.pc<b.pc;});
}
}
void vf3OracleInvalidate(unsigned reason) { for(auto &c:active) c.flags|=reason; }
void vf3OracleBefore(unsigned pc, unsigned short op,const Sh4Context *ctx) {
    if(!initialized) init(ctx);
    if (!hitsPath.empty()) {
        unsigned canon=pc|0x80000000u;
        auto s=std::lower_bound(specs.begin(),specs.end(),canon,
            [](const Spec &spec,unsigned value){return spec.pc<value;});
        if (s!=specs.end() && s->pc==canon) ++s->count;
        return;
    }
    if(!output) return;
    hooks();
    for(size_t i=active.size();i-->0;) if(active[i].countdown && --active[i].countdown==0) finish(i,pc,ctx);
    unsigned canon=pc|0x80000000u;
    for(auto &s:specs) if(s.pc==canon && s.count<samples) {
        ++s.count;
        if(active.size()>=64) { vf3OracleInvalidate(4); break; }
        Call c; c.id=++sequence; c.entry=pc; c.depth=depth; c.in=snapshot(ctx);
        active.push_back(std::move(c));
    }
    for(auto &c:active) {
        if(c.ops.size()<100000) c.ops.push_back({pc,(unsigned)op}); else c.flags|=4;
        for(const auto &s:specs) if(s.pc==(c.entry|0x80000000u) && s.transfer==canon) c.countdown=2;
        if(op==0x000B && (c.depth==depth || (ctx->pr==c.in[16] && ctx->r[15]>=c.in[15]))) c.countdown=2;
        if(op==0x002B) c.flags|=1; /* rte */
    }
    if((op&0xF000)==0xB000 || (op&0xF0FF)==0x400B || (op&0xF0FF)==0x0003) ++depth;
    if(op==0x000B && depth) --depth;
}
