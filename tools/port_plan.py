#!/usr/bin/env python3
"""port_plan.py — regenerable port roadmap joining heat, call graph and claims.

Joins:
  extract/analysis/funcs_1ST_READ.unsc.bin.csv      baseline inventory
  extract/analysis/port_backlog.csv                 heat (hits/leaf/out_calls)
  extract/analysis/disasm_1ST_READ.unsc.bin.calls.csv  static call edges
  extract/analysis/sh4_calls.csv                    machine-decoded bsr/dyn
                                                    cross-check (tools/sh4_calls.py)
  extract/analysis/trace_fn_hits.csv                executed set (containment)
  SDK/libmask claim CSVs + docs/decomp_status.csv   accounted set

Call-edge policy (2026-09-26, see docs/re/sh4_calls.md): Ghidra's calls.csv
is ~95% phantom call_sites (delay slots, return addrs, pool words), so only
rows whose site word is a real bsr/jsr/bsrf feed closure; the rest count in
g_phantom. sh4_calls.csv (recursive descent from the image) is the primary
static source; unresolved dynamic jsr/bsrf sites force closure_ok off.

and emits extract/analysis/port_plan.csv with a campaign tag:
  A  hot small (hits>=10k)
  B  executed but not hot
  C  never executed (lowest priority)
plus closure_ok (all resolved callees already ported/accounted) and effort.

Usage: python tools/port_plan.py [--out extract/analysis/port_plan.csv]
"""
from __future__ import annotations

import argparse
import bisect
import csv
from collections import defaultdict
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
AN = REPO / "extract" / "analysis"


def load_funcs():
    rows = []
    with open(AN / "funcs_1ST_READ.unsc.bin.csv", newline="") as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"]), r.get("name", "")))
    rows.sort()
    return rows


def containing(starts, funcs, addr):
    i = bisect.bisect_right(starts, addr) - 1
    if i < 0:
        return None
    ent, size, _ = funcs[i]
    if addr < ent + size:
        return ent
    return None


def sdk_claims():
    """Entry set that is SDK-attributed (full-body)."""
    out = set()
    for name, key in (("libmask_matches.csv", None),
                      ("libmask2_matches.csv", None),
                      ("v040_shinobi_libmask.csv", None),
                      ("v040_ninja_libmask.csv", None)):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            out.add(int(r["game_start"], 16))       # region roots
    for name in ("sdk053_matches.csv", "sdk_union_matches.csv"):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            if int(r["span_words"]) * 2 >= int(r["size"]):
                out.add(int(r["entry"], 16))
    return out


def region_claims():
    regs = []
    for name in ("libmask_matches.csv", "libmask2_matches.csv",
                 "v040_shinobi_libmask.csv", "v040_ninja_libmask.csv"):
        p = AN / name
        if not p.exists():
            continue
        for r in csv.DictReader(open(p, newline="")):
            regs.append((int(r["game_start"], 16), int(r["game_end"], 16)))
    regs.sort()
    return regs


def in_regions(regs, addr):
    for a, b in regs:
        if a <= addr < b:
            return True
        if a > addr:
            return False
    return False


def ported():
    out = set()
    p = REPO / "docs" / "decomp_status.csv"
    if p.exists():
        for r in csv.DictReader(open(p, newline="")):
            if r.get("status", "").startswith("ported"):
                out.add(int(r["entry"], 16))
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="extract/analysis/port_plan.csv")
    a = ap.parse_args()

    funcs = load_funcs()
    starts = [e for e, _, _ in funcs]
    F = {e: (s, n) for e, s, n in funcs}

    hits = {}
    with open(AN / "trace_fn_hits.csv", newline="") as f:
        for r in csv.DictReader(f):
            ent = containing(starts, funcs, int(r["fn"], 16))
            if ent is not None:
                hits[ent] = hits.get(ent, 0) + int(r["hits"])
    executed = set(hits)

    backlog = {}
    with open(AN / "port_backlog.csv", newline="") as f:
        for r in csv.DictReader(f):
            ent = int(r["entry"], 16)
            backlog[ent] = r
            bh = int(r.get("hits", 0))
            if bh > 0:
                executed.add(ent)
            if bh > hits.get(ent, 0):
                hits[ent] = bh

    calls = defaultdict(set)
    g_phantom = defaultdict(int)   # call_site word is not a call instruction
    img = (REPO / "extract" / "exe" / "1ST_READ.unsc.bin").read_bytes()
    def call_word(site):
        import struct as _st
        off = site - 0x8C010000
        if off < 0 or off + 2 > len(img):
            return None
        w = _st.unpack_from("<H", img, off)[0]
        if w & 0xF000 == 0xB000 or w & 0xF0FF == 0x400B or w & 0xF00F == 0x0003:
            return w                      # bsr / jsr @Rn / bsrf only;
        return False                      # (jmp @Rn is a tail transfer, not a call)
    with open(AN / "disasm_1ST_READ.unsc.bin.calls.csv", newline="") as f:
        for r in csv.DictReader(f):
            caller = containing(starts, funcs, int(r["call_site"], 16))
            if caller is None:
                continue
            if call_word(int(r["call_site"], 16)) is False:
                g_phantom[caller] += 1    # ~95% phantom: delay slots,
                continue                  # return addrs, pool words, ASCII
            target = int(r["target"], 16)
            callee = containing(starts, funcs, target)
            calls[caller].add(callee if callee is not None else target)

    # sh4_calls.csv cross-check (tools/sh4_calls.py): machine-decoded bsr
    # edges + dynamic jsr/bsrf sites straight from the image. Ghidra's
    # calls.csv misses sites in seed-fragmented bodies, which made
    # closure_ok vacuously true (e.g. 0x8C08B7EE, 0x8C0AF734, 0x8C0B1560).
    sh4_static = defaultdict(set)   # caller -> {targets}
    sh4_dyn = defaultdict(set)      # caller -> {dyn sites}
    sh4_tail = defaultdict(int)     # caller -> n jmp@Rn tail sites
    sh4_fixed = defaultdict(set)    # caller -> {fixed off-image targets}
    shp = AN / "sh4_calls.csv"
    if shp.exists():
        with open(shp, newline="") as f:
            for r in csv.DictReader(f):
                ent = int(r["entry"], 16)
                for t in r["static_targets"].split():
                    target = int(t, 16)
                    callee = containing(starts, funcs, target)
                    sh4_static[ent].add(callee if callee is not None else target)
                for d in r["dyn_sites"].split():
                    sh4_dyn[ent].add(int(d, 16))
                sh4_tail[ent] = int(r["n_tail"])
        for caller, tgts in sh4_static.items():
            calls[caller] |= tgts
    # sh4_resolved.csv (tools/sh4_resolve.py): STATIC resolutions become
    # call edges (containing-or-raw, like bsr); FIXED off-image targets
    # fail closure with ram@ tokens; UNKNOWNs keep their dyn@ tokens.
    shp2 = AN / "sh4_resolved.csv"
    if shp2.exists():
        with open(shp2, newline="") as f:
            for r in csv.DictReader(f):
                if r["class"] == "STATIC" and r["target"]:
                    ent = int(r["caller"], 16)
                    target = int(r["target"], 16)
                    callee = containing(starts, funcs, target)
                    tgt = callee if callee is not None else target
                    sh4_static[ent].add(tgt)
                    calls[ent].add(tgt)
                    sh4_dyn[ent].discard(int(r["site"], 16))
                elif r["class"] == "FIXED" and r["target"]:
                    ent = int(r["caller"], 16)
                    sh4_fixed[ent].add(int(r["target"], 16))
                    sh4_dyn[ent].discard(int(r["site"], 16))

    sdk = sdk_claims()
    regs = region_claims()
    done = ported()
    # an entry is accounted if it is SDK-matched, inside an SDK region, or ported
    def accounted(e):
        return e in sdk or in_regions(regs, e) or e in done

    rows = []
    for ent, size, name in funcs:
        h = hits.get(ent, 0)
        bl = backlog.get(ent, {})
        callees = sorted(calls.get(ent, set()))
        resolved = [c for c in callees if c in F]
        unresolved = [c for c in callees if c not in F]
        missing = [c for c in resolved if c != ent and not accounted(c)]
        dyn = sorted(sh4_dyn.get(ent, set()))
        fixed = sorted(sh4_fixed.get(ent, set()))
        # gap code: in-image targets with no containing function (Ghidra
        # never formed them). Unaccounted code = closure fails, named.
        img_lo, img_hi = 0x8C010000, 0x8C010000 + len(img)
        gap = [c for c in unresolved
               if img_lo <= c < img_hi and not in_regions(regs, c)]
        outside = [c for c in unresolved if not (img_lo <= c < img_hi)]
        closure_ok = (len(missing) == 0 and len(dyn) == 0
                      and len(fixed) == 0 and len(gap) == 0
                      and len(outside) == 0)
        miss_txt = " ".join(f"0x{c:08X}" for c in missing[:8])
        if dyn:
            miss_txt = (miss_txt + " " if miss_txt else "") + " ".join(
                f"dyn@0x{d:08X}" for d in dyn[:4])
        if fixed:
            miss_txt = (miss_txt + " " if miss_txt else "") + " ".join(
                f"ram@0x{d:08X}" for d in fixed[:2])
        if gap:
            miss_txt = (miss_txt + " " if miss_txt else "") + " ".join(
                f"gap@0x{d:08X}" for d in gap[:4])
        if outside:
            miss_txt = (miss_txt + " " if miss_txt else "") + " ".join(
                f"unk@0x{d:08X}" for d in outside[:2])
        if accounted(ent):
            camp = "accounted"
        elif h >= 10000:
            camp = "A"
        elif ent in executed:
            camp = "B"
        elif bl:
            camp = "C"
        else:
            camp = "D"
        if size <= 64:
            effort = "S"
        elif size <= 256:
            effort = "M"
        elif size <= 1024:
            effort = "L"
        else:
            effort = "XL"
        rows.append({
            "entry": f"0x{ent:08X}", "name": name, "size": size,
            "hits": h, "leaf": bl.get("leaf", ""),
            "out_calls": bl.get("out_calls", len(callees)),
            "campaign": camp, "effort": effort,
            "executed": "Y" if ent in executed else "-",
            "closure_ok": "Y" if closure_ok else "-",
            "missing_callees": miss_txt,
            "leaf_sh4": "1" if (len(sh4_static.get(ent, ())) == 0
                                and len(dyn) == 0
                                and len(fixed) == 0
                                and sh4_tail.get(ent, 0) == 0) else "",
            "sh4_static": len(sh4_static.get(ent, ())),
            "sh4_dyn": len(dyn),
            "sh4_fixed": len(fixed),
            "sh4_tail": sh4_tail.get(ent, 0),
            "g_phantom": g_phantom.get(ent, 0),
            "page": f"0x{(ent >> 16):02x}",
            "score": h * max(size, 16),
        })
    rows.sort(key=lambda r: (-r["score"], r["entry"]))
    outp = Path(a.out)
    with open(outp, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["entry", "name", "size", "hits",
                                          "leaf", "out_calls", "campaign",
                                          "effort", "executed", "closure_ok",
                                          "missing_callees", "leaf_sh4",
                                          "sh4_static", "sh4_dyn", "sh4_fixed",
                                          "sh4_tail", "g_phantom", "page",
                                          "score"])
        w.writeheader()
        w.writerows(rows)
    by_camp = defaultdict(lambda: [0, 0])
    for r in rows:
        by_camp[r["campaign"]][0] += 1
        by_camp[r["campaign"]][1] += r["size"]
    print(f"port_plan: {outp}")
    for c in sorted(by_camp):
        n, b = by_camp[c]
        print(f"  campaign {c}: {n} fns / {b} B")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())