/* Read-only audio determinism checkpoints. No cache flush or device tick.
 * This is research instrumentation, not a game-side audio implementation. */
#include "vf3audio.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_cache.h"
#include "hw/sh4/sh4_sched.h"
#include "hw/aica/aica_if.h"
#include "hw/arm7/arm7.h"
#include "serialize.h"
#include <array>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace aica { extern int aica_schid, rtc_schid, dma_sched_id; }
extern int gdrom_schid, maple_schid, render_end_schid, vblank_schid, tmu_sched[3];

namespace {
FILE *out;
bool ready, done, callMode, inCall;
unsigned long long count;
size_t cursor;
std::vector<unsigned long long> points;
std::vector<short> pcm;
std::vector<std::array<unsigned,6>> events;
unsigned bits(float f) { unsigned u; std::memcpy(&u,&f,4); return u; }
void write(const void *p, size_t n) {
    if (std::fwrite(p,1,n,out)!=n) std::abort();
}
template<class F> std::vector<unsigned char> serialized(F emit) {
    Serializer size;
    emit(size);
    std::vector<unsigned char> data(size.size());
    Serializer ser(data.data(),data.size());
    emit(ser);
    if (ser.size()!=data.size()) std::abort();
    return data;
}
void block(unsigned kind, const void *data, unsigned size) {
    const unsigned header[2]={kind,size};
    write(header,sizeof(header)); write(data,size);
}
void close() {
    if (out && std::fclose(out)) std::abort();
    out=nullptr;
}
void checkpoint(unsigned pc, unsigned short op, const Sh4Context *c);
}
void vf3AudioPrepare() {
    if (ready) return;
    ready=true;
    const char *path=std::getenv("VF3_AUDIO_CHECKPOINTS");
    if (!path || !*path) return;
    callMode=std::getenv("VF3_ONESHOT")!=nullptr;
    const char *p=std::getenv("VF3_AUDIO_POINTS");
    if (!p && !callMode) { std::fprintf(stderr,"[vf3audio] VF3_AUDIO_POINTS required\n"); std::abort(); }
    if (p && callMode) std::abort();
    while (p && *p) {
        char *end;
        auto value=std::strtoull(p,&end,0);
        if (end==p || !value || value>1000000000ull || (*end && *end!=',')) std::abort();
        points.push_back(value);
        p=*end?end+1:end;
    }
    if ((!callMode && points.empty()) || points.size()>64 || !std::is_sorted(points.begin(),points.end()) ||
        std::adjacent_find(points.begin(),points.end())!=points.end()) std::abort();
    out=std::fopen(path,"wb");
    if (!out) std::abort();
    write("VF3AUD1\0",8);
    std::atexit(close);
}
bool vf3AudioDone() { return done; }
void vf3AudioSample(int right, int left) {
    if (!out || done || (callMode && !inCall)) return;
    if (pcm.size()>=32*1024*1024) std::abort();
    pcm.push_back((short)right); pcm.push_back((short)left);
}
void vf3AudioEvent(int id, int tag, int duration, int jitter) {
    if (!out || done || (callMode && !inCall)) return;
    if (events.size()>=1000000) std::abort();
    const auto time=sh4_sched_now64();
    const int ids[]={aica::aica_schid,aica::rtc_schid,gdrom_schid,maple_schid,
                     aica::dma_sched_id,render_end_schid,vblank_schid,
                     tmu_sched[0],tmu_sched[1],tmu_sched[2]};
    unsigned role=0;
    for (unsigned i=0;i<10;++i) if (ids[i]==id) role=i+1;
    // Unknown callbacks keep a high-bit marker; known IDs become device roles.
    if (!role) role=0x80000000u|(unsigned)id;
    events.push_back({(unsigned)time,(unsigned)(time>>32),role,
                     (unsigned)tag,(unsigned)duration,(unsigned)jitter});
}
namespace {
void checkpoint(unsigned pc, unsigned short op, const Sh4Context *c) {
    const unsigned long long cycles=sh4_sched_now64();
    const unsigned header[4]={pc,op,(unsigned)c->cycle_counter,(unsigned)c->sh4_sched_next};
    write(&count,8); write(&cycles,8); write(header,sizeof(header));
    std::array<unsigned,63> state{};
    for (unsigned i=0;i<16;++i) {
        state[i]=c->r[i]; state[21+i]=bits(c->fr[i]); state[37+i]=bits(c->xf[i]);
    }
    state[16]=c->pr; state[17]=c->sr.getFull(); state[18]=c->fpscr.full;
    state[19]=c->mac.l; state[20]=c->mac.h; state[53]=c->fpul; state[54]=c->gbr;
    for (unsigned i=0;i<8;++i) state[55+i]=c->r_bank[i];
    block(1,state.data(),sizeof(state));
    block(2,&mem_b[0],0x1000000);
    auto aica=serialized([](Serializer &s){aica::serialize(s);});
    block(3,aica.data(),(unsigned)aica.size());
    auto cache=serialized([](Serializer &s){icache.Serialize(s);ocache.Serialize(s);});
    block(4,cache.data(),(unsigned)cache.size());
    auto sched=serialized([](Serializer &s){sh4_sched_serialize(s);});
    block(5,sched.data(),(unsigned)sched.size());
    block(6,pcm.data(),(unsigned)(pcm.size()*sizeof(short)));
    block(7,events.data(),(unsigned)(events.size()*sizeof(events[0])));
    if (std::fflush(out)) std::abort();
    std::fprintf(stderr,"[vf3audio] checkpoint %llu pc=%08x cycle=%llu\n",count,pc,cycles);
}
}
bool vf3AudioBefore(unsigned pc, unsigned short op, const Sh4Context *c) {
    if (!out || done) return false;
    ++count;
    if (callMode || count!=points[cursor]) return false;
    checkpoint(pc,op,c);
    if (++cursor==points.size()) { done=true; close(); return true; }
    return false;
}
void vf3AudioBegin(unsigned pc, unsigned short op, const Sh4Context *c) {
    if (!out || !callMode || inCall || done) std::abort();
    inCall=true;
    const char *control=std::getenv("VF3_AUDIO_CONTROL");
    if (control) {
        if (!std::strcmp(control,"timer"))
            aica::writeAicaReg<unsigned>(0x2890,aica::readAicaReg<unsigned>(0x2890)^0x100u);
        else if (!std::strcmp(control,"arm_disabled")) {
            aica::arm::enable(false);
        } else if (!std::strcmp(control,"queue_busy")) {
            // Genuine device input: occupy the current slot through the live bus.
            const unsigned slot=ReadMem32(0x0c19e218);
            if (slot<0xa0800400u || slot>=0xa0800500u || (slot&3)) std::abort();
            WriteMem32(slot,1);
        } else std::abort();
    }
    checkpoint(pc,op,c);
}
void vf3AudioEnd(unsigned pc, const Sh4Context *c) {
    if (!out || !callMode || !inCall || done) std::abort();
    checkpoint(pc,0,c); // return-boundary opcode is not executed or part of the call
    done=true; inCall=false; close();
}
bool vf3AudioQueueWindow(const Sh4Context *c) {
    // Read-only selection of a natural trigger; never move an event or CPU clock.
    if (c->cycle_counter<=0 || c->cycle_counter>128) return false;
    const auto sched=serialized([](Serializer &s){sh4_sched_serialize(s);});
    // Pinned serializer: version/RAM-size (8), base clock (8), AICA tag/start/end.
    if (sched.size()!=100) std::abort();
    unsigned end;
    std::memcpy(&end,sched.data()+24,4);
    const unsigned remaining=end-(unsigned)sh4_sched_now64();
    return remaining>0 && remaining<SH4_TIMESLICE;
}
