// tick_oracle.cpp - replay one VF3_FULL whole-RAM entry/exit pair (tools/tick_capture.py) on the
// statically recompiled VF3tb and diff against the emulator's exit state.
//   vf3tb_tick <entry> <trace.bin> [pair] [--dump out.bin]
// Local scaffold (links GPL dream-recomp); never committed. Output format mirrors tests/tick_replay.c.
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <functional>
#include <map>
#include <set>
#include <vector>

#include "dream/runtime/system.h"
#include "dream/runtime/fenv.h"
#include "dream/runtime/devinterp/interpreter.h"
#include "dream/runtime/sh4/abi.h"

namespace {
constexpr std::uint32_t RAM_BASE = 0x0C000000u, RAM_LEN = 0x01000000u;
struct Snap {
    std::uint32_t regs[37] = {};
    std::vector<std::uint8_t> ram;
    bool have_regs = false;
};
bool rd(FILE* f, std::uint64_t& v) { return std::fread(&v, 8, 1, f) == 1; }

bool load_pair(const char* path, unsigned idx, Snap& in, Snap& out) {
    FILE* f = std::fopen(path, "rb");
    if (!f) return false;
    std::uint64_t v;
    unsigned pair = 0;
    int stage = 0;  // 0 wait entry, 1 entry ram, 2 wait exit, 3 exit ram
    while (rd(f, v)) {
        std::uint32_t m = v & 0xFFFF;
        if ((v >> 16) == 0 || m < 0xFA30) continue;
        if (m == 0xFA30 || m == 0xFA32) {
            Snap& s = (m == 0xFA30) ? in : out;
            if (m == 0xFA30 && stage != 0) continue;
            if (m == 0xFA32 && stage != 2) continue;
            if (pair != idx) {
                if (m == 0xFA32) { ++pair; stage = 0; } else stage = 2;
                continue;
            }
            for (int i = 0; i < 37; ++i) { if (!rd(f, v)) goto done; s.regs[i] = (std::uint32_t)v; }
            s.have_regs = true;
            stage = (m == 0xFA30) ? 1 : 3;
        } else if ((m == 0xFA50 && stage == 1) || (m == 0xFA60 && stage == 3)) {
            Snap& s = (m == 0xFA50) ? in : out;
            if (!rd(f, v)) goto done;
            std::uint32_t nwin = (std::uint32_t)v;
            for (std::uint32_t w = 0; w < nwin; ++w) {
                std::uint64_t b, l;
                if (!rd(f, b) || !rd(f, l)) goto done;
                std::uint32_t base = (std::uint32_t)b, len = (std::uint32_t)l;
                bool ram = base == RAM_BASE && len == RAM_LEN;
                if (ram) s.ram.assign(RAM_LEN, 0);
                for (std::uint32_t i = 0; i < len / 4; ++i) {
                    if (!rd(f, v)) goto done;
                    if (ram) { std::uint32_t x = (std::uint32_t)v; std::memcpy(&s.ram[i * 4], &x, 4); }
                }
            }
            if (m == 0xFA50) stage = 2;
            else { std::fclose(f); return in.have_regs && !in.ram.empty() && out.have_regs && !out.ram.empty(); }
        }
    }
done:
    std::fclose(f);
    return false;
}

// ---- device access log -------------------------------------------------------------------
// Every access outside main RAM (hardware registers, VRAM, ...) is logged in program order with the
// value the oracle's device model returned, plus enter/exit markers of the recorded calls. The
// native harness replays reads from this log and skips the span of a replayed (stubbed) call.
//   kind 1 read (addr,size,value)  2 write (addr,size,value)  3 enter (entry,seq)  4 exit (entry,seq)
FILE* g_devlog = nullptr;
std::uint64_t g_devn = 0;
void devrec(std::uint32_t kind, std::uint32_t a, std::uint32_t b, std::uint32_t c) {
    if (!g_devlog) return;
    std::uint32_t w[4] = {kind, a, b, c};
    std::fwrite(w, 4, 4, g_devlog);
    ++g_devn;
}
// Store-queue bursts into RAM never pass through on_watch_write; the recorder gets them here so a
// stubbed callee's effect includes its SQ output (vertex streams) and not only its plain stores.
static std::function<void(std::uint32_t, std::uint32_t)> g_ramburst;

class SpyMemory final : public dream::Memory {
public:
    explicit SpyMemory(dream::Memory& m) : m_(m) {}
    static bool is_ram(std::uint32_t a) { return (a >> 29) <= 5 && (a & 0x1C000000u) == 0x0C000000u; }
    std::uint8_t read8(std::uint32_t a) override { auto v = m_.read8(a); if (!is_ram(a)) devrec(1, a, 1, v); return v; }
    std::uint16_t read16(std::uint32_t a) override { auto v = m_.read16(a); if (!is_ram(a)) devrec(1, a, 2, v); return v; }
    std::uint32_t read32(std::uint32_t a) override { auto v = m_.read32(a); if (!is_ram(a)) devrec(1, a, 4, v); return v; }
    std::uint64_t read64(std::uint32_t a) override {
        auto v = m_.read64(a);
        if (!is_ram(a)) { devrec(1, a, 4, (std::uint32_t)v); devrec(1, a + 4, 4, (std::uint32_t)(v >> 32)); }
        return v;
    }
    void write8(std::uint32_t a, std::uint8_t v) override { if (!is_ram(a)) devrec(2, a, 1, v); m_.write8(a, v); }
    void write16(std::uint32_t a, std::uint16_t v) override { if (!is_ram(a)) devrec(2, a, 2, v); m_.write16(a, v); }
    void write32(std::uint32_t a, std::uint32_t v) override {
        if (!is_ram(a)) devrec(2, a, 4, v);
        if ((a & 0x1FFFFFFFu) == 0x1F000038u || (a & 0x1FFFFFFFu) == 0x1F00003Cu) qacr_[(a >> 2) & 1] = v & 0x1Cu;
        if ((a & 0xFC000000u) == 0xE0000000u) sq_[(a >> 5) & 1][(a >> 2) & 7] = v;
        m_.write32(a, v);
    }
    void write64(std::uint32_t a, std::uint64_t v) override {
        if (!is_ram(a)) { devrec(2, a, 4, (std::uint32_t)v); devrec(2, a + 4, 4, (std::uint32_t)(v >> 32)); }
        if ((a & 0xFC000000u) == 0xE0000000u) {
            sq_[(a >> 5) & 1][(a >> 2) & 7] = (std::uint32_t)v;
            sq_[((a + 4) >> 5) & 1][((a + 4) >> 2) & 7] = (std::uint32_t)(v >> 32);
        }
        m_.write64(a, v);
    }
    void sq_write32(std::uint32_t a, std::uint32_t v) override { sq_[(a >> 5) & 1][(a >> 2) & 7] = v; m_.sq_write32(a, v); }
    void sq_flush(std::uint32_t a) override {
        const unsigned n = (a >> 5) & 1;
        const std::uint32_t dest = (qacr_[n] << 24) | (a & 0x03FFFFE0u);
        if (g_ramburst && is_ram(dest)) for (unsigned i = 0; i < 8; ++i) g_ramburst(dest + 4 * i, sq_[n][i]);
        m_.sq_flush(a);
    }
private:
    dream::Memory& m_;
    std::uint32_t sq_[2][8] = {}, qacr_[2] = {};
};

// ---- call-effect recorder ---------------------------------------------------------------
// Every call (jsr/bsr/bsrf) seen by the stepper becomes one record: entry state, ordered stores,
// exit state. Written in the layout of vf3_matrix_state.v[54] (r0-r15, pr, sr, fpscr, macl, mach,
// fr0-15, xf0-15, fpul) so the native harness can apply an unported callee's effect verbatim.
struct Rec {
    std::uint32_t entry, seq, depth;
    std::uint32_t in[54], out[54];
    std::vector<std::uint32_t> w;  // addr,size,value triples
    std::uint64_t steps = 0;
};
struct Frame { std::uint32_t entry, ret, sp; std::size_t widx; std::size_t rec; std::uint64_t steps0; };
struct Recorder {
    dream::System& sys;
    dream::sh4::Ctx& c;
    FILE* f = nullptr;
    std::vector<std::uint32_t> wlog;
    std::vector<Frame> stack;
    std::vector<Rec> recs;
    std::map<std::uint32_t, std::uint32_t> seq;
    struct Stat { std::uint64_t calls = 0, self = 0, incl = 0, writes = 0; };
    std::map<std::uint32_t, Stat> stats;
    std::uint32_t maxdepth = 12;
    Recorder(dream::System& s, dream::sh4::Ctx& cc) : sys(s), c(cc) {
        if (const char* d = std::getenv("TICK_REC_DEPTH")) maxdepth = (std::uint32_t)std::strtoul(d, nullptr, 0);
        sys.memory.watch_lo = 0; sys.memory.watch_hi = 0x20000000u;
        g_ramburst = [this](std::uint32_t a, std::uint32_t v) {
            static const std::uint32_t bw = std::getenv("TICK_BURSTW") ? (std::uint32_t)std::strtoul(std::getenv("TICK_BURSTW"), nullptr, 0) : 1u;
            if (a >= bw && a < bw + 0x20u) {
                std::printf("BURST %08x=%08x pc %08x depth %zu stack:", a, v, c.pc, stack.size());
                for (auto& fr : stack) std::printf(" %08x", fr.entry);
                std::putchar(10);
            }
            if (!stack.empty()) { wlog.push_back(a); wlog.push_back(4); wlog.push_back(v); } };
        sys.memory.on_watch_write = [this](std::uint32_t a, std::uint32_t v, unsigned sz) {
            static const std::uint32_t wlo = std::getenv("TICK_WATCHW") ? (std::uint32_t)std::strtoul(std::getenv("TICK_WATCHW"), nullptr, 0) : 1u;
            static const std::uint32_t whi = std::getenv("TICK_WATCHW") ? wlo + 0x100u : 0u;
            static int wprinted = 0;
            if (a >= wlo && a < whi && wprinted < 6) {
                ++wprinted;
                std::printf("WATCH write %08x/%u=%08x pc %08x depth %zu stack:", a, sz, v, c.pc, stack.size());
                for (auto& fr : stack) std::printf(" %08x", fr.entry);
                std::printf("\n");
            }
            if (!stack.empty()) { wlog.push_back(a); wlog.push_back(sz); wlog.push_back(v); }
        };
    }
    void open(const char* p) { f = std::fopen(p, "wb"); if (f) { std::uint32_t m = 0x31584656u; std::fwrite(&m, 4, 1, f); } }
    bool classify(std::uint32_t pc, std::uint32_t& tgt) {
        std::uint16_t op = sys.memory.read16(pc);
        if ((op & 0xF0FF) == 0x400B) { tgt = c.r[(op >> 8) & 15]; return true; }
        if ((op & 0xF000) == 0xB000) { int d = op & 0xFFF; if (d & 0x800) d -= 0x1000; tgt = pc + 4 + (std::uint32_t)(d * 2); return true; }
        if ((op & 0xF0FF) == 0x0003) { tgt = pc + 4 + c.r[(op >> 8) & 15]; return true; }
        return false;
    }
    void snap(std::uint32_t* v) {
        for (int i = 0; i < 16; ++i) v[i] = c.r[i];
        v[16] = c.pr; v[17] = c.sr; v[18] = c.fpscr; v[19] = c.macl; v[20] = c.mach;
        for (int i = 0; i < 16; ++i) std::memcpy(&v[21 + i], &c.fr[i], 4);
        for (int i = 0; i < 16; ++i) std::memcpy(&v[37 + i], &c.xf[i], 4);
        v[53] = c.fpul;
    }
    std::uint64_t gsteps = 0;
    bool snapped = false; unsigned traced = 0;
    void account(std::uint32_t) { ++gsteps; if (!stack.empty()) { stats[stack.back().entry].self++; } }
    void enter(std::uint32_t ret) {
        if (stack.size() >= maxdepth + 8) { stack.push_back({c.pc, ret, c.r[15], ~(std::size_t)0, ~(std::size_t)0, 0}); return; }
        Frame fr{c.pc, ret, c.r[15], wlog.size(), ~(std::size_t)0, gsteps};
        if (stack.size() < maxdepth) {
            Rec r; r.entry = c.pc; r.seq = seq[c.pc]++; r.depth = (std::uint32_t)stack.size();
            snap(r.in);
            if (const char* sn = std::getenv("TICK_SNAP")) {  // TICK_SNAP=<entry hex>,<ordinal>,<file>: whole-RAM image at that call's entry
                unsigned se = 0, sq = 0; char path[512] = {};
                if (std::sscanf(sn, "%x,%u,%511s", &se, &sq, path) == 3 && se == r.entry && sq == r.seq) {
                    snapped = true;
                    if (FILE* d = std::fopen(path, "wb")) {
                        std::fwrite(r.in, 4, 54, d);
                        std::fwrite(sys.memory.ram(), 1, 0x01000000u, d);
                        std::fclose(d);
                    }
                }
            }
            fr.rec = recs.size();
            devrec(3, r.entry, r.seq, 0);
            recs.push_back(std::move(r));
        }
        stats[c.pc].calls++;
        stack.push_back(fr);
    }
    void maybe_exit() {
        while (!stack.empty() && c.pc == stack.back().ret && c.r[15] == stack.back().sp) {
            Frame fr = stack.back(); stack.pop_back();
            if (fr.rec != ~(std::size_t)0) {
                Rec& r = recs[fr.rec];
                devrec(4, r.entry, r.seq, 0);
                snap(r.out);
                r.steps = gsteps - fr.steps0;
                r.w.assign(wlog.begin() + (std::ptrdiff_t)fr.widx, wlog.end());
                stats[r.entry].writes += r.w.size() / 3;
            }
            if (stack.empty()) wlog.clear();
        }
    }
    void finish() {
        if (!f) return;
        // order by call start (already in recs order); write each record
        for (auto& r : recs) {
            std::uint32_t hdr[4] = {r.entry, r.seq, r.depth, (std::uint32_t)r.steps};
            std::fwrite(hdr, 4, 4, f);
            std::fwrite(r.in, 4, 54, f);
            std::fwrite(r.out, 4, 54, f);
            std::uint32_t nw = (std::uint32_t)(r.w.size() / 3);
            std::fwrite(&nw, 4, 1, f);
            if (nw) std::fwrite(r.w.data(), 4, r.w.size(), f);
        }
        std::fclose(f);
        std::printf("recorded %zu calls\n", recs.size());
        if (const char* sp = std::getenv("TICK_STATS")) {
            FILE* g = std::fopen(sp, "w");
            std::fprintf(g, "entry,calls,self_steps,writes\n");
            for (auto& kv : stats) std::fprintf(g, "0x%08x,%llu,%llu,%llu\n", kv.first, (unsigned long long)kv.second.calls, (unsigned long long)kv.second.self, (unsigned long long)kv.second.writes);
            std::fclose(g);
        }
    }
};
}  // namespace

int main(int argc, char** argv) {
    if (argc < 3) { std::fprintf(stderr, "usage: vf3tb_tick entry trace.bin [pair]\n"); return 2; }
    std::uint32_t entry = (std::uint32_t)std::strtoul(argv[1], nullptr, 0);
    unsigned idx = argc > 3 ? (unsigned)std::strtoul(argv[3], nullptr, 0) : 0;
    Snap in, out;
    if (!load_pair(argv[2], idx, in, out)) { std::fprintf(stderr, "pair %u not found\n", idx); return 2; }

    dream::System sys;
    sys.reset();
    sys.install();
    std::memcpy(sys.memory.ram(), in.ram.data(), RAM_LEN);
    auto& c = sys.ctx;
    for (int i = 0; i < 16; ++i) c.r[i] = in.regs[i];
    c.pr = in.regs[16];
    c.sr = in.regs[17];
    c.fpscr = in.regs[18];
    c.macl = in.regs[19];
    c.mach = in.regs[20];
    for (int i = 0; i < 16; ++i) std::memcpy(&c.fr[i], &in.regs[21 + i], 4);
    c.t = c.sr & 1;
    if (const char* g = std::getenv("TICK_GBR")) c.gbr = (std::uint32_t)std::strtoul(g, nullptr, 0);  // not part of the capture format
    c.next_event = ~0ull;  // no interrupts: a pure function-level diff
    int rc = 0;
    try {
        if (std::getenv("TICK_INTERP")) {
            // pure interpreter, one step at a time, with a pc ring for fault triage
            dream::devinterp::Options o;
            o.call_translated = false;
            o.catch_nonlocal = true;
            o.max_instructions = 1;
            const std::uint32_t ret = 0xDEAD0000u;
            c.pr = ret;
            c.pc = entry;
            std::uint32_t ring[64] = {};
            unsigned n = 0;
            std::uint64_t steps = 0;
            std::uint64_t cap = std::getenv("TICK_STEPS") ? std::strtoull(std::getenv("TICK_STEPS"), nullptr, 0) : 200000000ull;
            SpyMemory spy(sys.memory);
            if (const char* dl = std::getenv("TICK_DEVLOG")) g_devlog = std::fopen(dl, "wb");
            Recorder rec(sys, c);
            const char* pcspath = std::getenv("TICK_PCS");
            const bool pcs_on = pcspath != nullptr;
            std::set<std::uint32_t> executed;
            std::map<std::uint32_t, std::set<std::uint32_t>> ind;
            std::uint32_t jsite = 0;
            const char* recpath = std::getenv("TICK_REC");
            if (recpath) rec.open(recpath);
            try {
                for (;; ++steps) {
                    ring[n++ & 63] = c.pc;
                    std::uint32_t pc0 = c.pc, tgt = 0;
                    bool call = false;
                    if (recpath) call = rec.classify(pc0, tgt);
                    if (pcs_on) {
                        const std::uint32_t pm = pc0 & 0x1FFFFFFFu;
                        if (jsite) { if (pm == jsite + 2) { /* delay slot */ } else { ind[jsite].insert(pm); jsite = 0; } }
                        if (pm >= 0x0c010000u && pm < 0x0d000000u) {
                            executed.insert(pm);
                            const std::uint16_t op = sys.memory.read16(pc0);
                            if ((op & 0xF0FFu) == 0x402Bu || (op & 0xF0FFu) == 0x0023u) jsite = pm;
                        }
                    }
                    auto st = dream::devinterp::run(c, spy, ret, o);
                    if (recpath && rec.snapped && rec.traced < 120 && (pc0 & 0x1FFFFFFFu) >= 0x0c048cc0u && (pc0 & 0x1FFFFFFFu) < 0x0c048d40u) {
                        ++rec.traced;
                        auto m = dream::fenv::current();
                        std::printf("TRACE %08x fpscr %08x host_rz %d fr0-5 %08x %08x %08x %08x %08x %08x\n", pc0, c.fpscr,
                                    (int)(m.rounding == dream::fenv::Rounding::TowardZero), *(std::uint32_t*)&c.fr[0], *(std::uint32_t*)&c.fr[1],
                                    *(std::uint32_t*)&c.fr[2], *(std::uint32_t*)&c.fr[3], *(std::uint32_t*)&c.fr[4], *(std::uint32_t*)&c.fr[5]);
                    }
                    if (recpath) {
                        rec.account(c.pc);
                        if (call && c.pr == pc0 + 4) rec.enter(pc0 + 4);
                        rec.maybe_exit();
                    }
                    if (st == dream::devinterp::Stop::Returned) break;
                    if (steps >= cap) { std::printf("step cap\n"); break; }
                }
                std::printf("run: completed (interp, %llu steps)\n", (unsigned long long)steps);
                if (recpath) rec.finish();
                if (pcs_on) {
                    // executed guest PCs (one hex word per line) and indirect jmp/braf site -> targets
                    FILE* pf = std::fopen(pcspath, "w");
                    for (auto a : executed) std::fprintf(pf, "pc %08x\n", a);
                    for (auto& kv : ind) {
                        std::fprintf(pf, "ind %08x", kv.first);
                        for (auto t : kv.second) std::fprintf(pf, " %08x", t);
                        std::fputc(10, pf);
                    }
                    std::fclose(pf);
                }
            } catch (const std::exception& e) {
                std::printf("run: FAULT %s after %llu steps; last pcs:", e.what(), (unsigned long long)steps);
                for (unsigned i = 0; i < 48; ++i) std::printf(" %08x", ring[(n + 16 + i) & 63]);
                std::printf("\n");
                rc = 1;
            }
        } else {
            dream::sh4::run_guest(c, sys.memory, entry);
            std::printf("run: completed\n");
        }
    } catch (const std::exception& e) {
        std::printf("run: FAULT %s\n", e.what());
        rc = 1;
    }
    if (const char* dp = std::getenv("TICK_DUMP")) {
        FILE* d = std::fopen(dp, "wb");
        std::uint32_t v[54];
        for (int i = 0; i < 16; ++i) v[i] = c.r[i];
        v[16] = c.pr; v[17] = c.sr; v[18] = c.fpscr; v[19] = c.macl; v[20] = c.mach;
        for (int i = 0; i < 16; ++i) std::memcpy(&v[21 + i], &c.fr[i], 4);
        for (int i = 0; i < 16; ++i) std::memcpy(&v[37 + i], &c.xf[i], 4);
        v[53] = c.fpul;
        std::fwrite(v, 4, 54, d);
        std::fwrite(sys.memory.ram(), 1, RAM_LEN, d);
        std::fclose(d);
    }
    if (const char* xp = std::getenv("TICK_EXITDUMP")) {  // the captured hardware (flycast) exit RAM
        FILE* d = std::fopen(xp, "wb");
        std::fwrite(out.ram.data(), 1, out.ram.size(), d);
        std::fclose(d);
    }
    static const char* names[37] = {"r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11","r12","r13",
        "r14","r15","pr","sr","fpscr","macl","mach","fr0","fr1","fr2","fr3","fr4","fr5","fr6","fr7","fr8","fr9",
        "fr10","fr11","fr12","fr13","fr14","fr15"};
    std::uint32_t got[37];
    for (int i = 0; i < 16; ++i) got[i] = c.r[i];
    got[16] = c.pr; got[17] = c.sr; got[18] = c.fpscr; got[19] = c.macl; got[20] = c.mach;
    for (int i = 0; i < 16; ++i) std::memcpy(&got[21 + i], &c.fr[i], 4);
    int regdiff = 0;
    for (int i = 0; i < 37; ++i)
        if (got[i] != out.regs[i]) {
            if (++regdiff <= 40) std::printf("  reg %-5s got %08x want %08x\n", names[i], got[i], out.regs[i]);
        }
    std::printf("reg diffs: %d\n", regdiff);
    const std::uint8_t* g = sys.memory.ram();
    unsigned runs = 0, total = 0;
    std::uint32_t s0 = 0, last = 0;
    bool open = false;
    for (std::uint32_t i = 0; i <= RAM_LEN; ++i) {
        bool d = i < RAM_LEN && g[i] != out.ram[i];
        if (d) {
            ++total;
            if (!open) { s0 = i; open = true; }
            else if (i - last > 16) {
                if (runs < 60) std::printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last);
                ++runs; s0 = i;
            }
            last = i;
        }
    }
    if (open) { if (runs < 60) std::printf("  ram diff %08x..%08x\n", RAM_BASE + s0, RAM_BASE + last); ++runs; }
    std::printf("ram diff bytes: %u in %u runs\n", total, runs);
    return rc || regdiff || total ? 1 : 0;
}
