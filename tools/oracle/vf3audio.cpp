/* Read-only audio determinism checkpoints. No cache flush or device tick.
 * This is research instrumentation, not a game-side audio implementation. */
#include "vf3audio.h"
#include "hw/sh4/sh4_mem.h"
#include "hw/sh4/sh4_cache.h"
#include "hw/sh4/sh4_sched.h"
#include "hw/aica/aica_if.h"
#include "serialize.h"
#include <array>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
FILE *out;
bool ready, done;
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
}
void vf3AudioPrepare() {
    if (ready) return;
    ready=true;
    const char *path=std::getenv("VF3_AUDIO_CHECKPOINTS");
    if (!path || !*path) return;
    const char *p=std::getenv("VF3_AUDIO_POINTS");
    if (!p) { std::fprintf(stderr,"[vf3audio] VF3_AUDIO_POINTS required\n"); std::abort(); }
    while (*p) {
        char *end;
        auto value=std::strtoull(p,&end,0);
        if (end==p || !value || value>1000000000ull || (*end && *end!=',')) std::abort();
        points.push_back(value);
        p=*end?end+1:end;
    }
    if (points.empty() || points.size()>64 || !std::is_sorted(points.begin(),points.end()) ||
        std::adjacent_find(points.begin(),points.end())!=points.end()) std::abort();
    out=std::fopen(path,"wb");
    if (!out) std::abort();
    write("VF3AUD1\0",8);
    std::atexit(close);
}
bool vf3AudioDone() { return done; }
void vf3AudioSample(int right, int left) {
    if (!out || done) return;
    if (pcm.size()>=32*1024*1024) std::abort();
    pcm.push_back((short)right); pcm.push_back((short)left);
}
void vf3AudioEvent(int id, int tag, int duration, int jitter) {
    if (!out || done) return;
    if (events.size()>=1000000) std::abort();
    const auto time=sh4_sched_now64();
    events.push_back({(unsigned)time,(unsigned)(time>>32),(unsigned)id,
                     (unsigned)tag,(unsigned)duration,(unsigned)jitter});
}
bool vf3AudioBefore(unsigned pc, unsigned short op, const Sh4Context *c) {
    if (!out || done) return false;
    ++count;
    if (count!=points[cursor]) return false;
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
    if (++cursor==points.size()) { done=true; close(); return true; }
    return false;
}
