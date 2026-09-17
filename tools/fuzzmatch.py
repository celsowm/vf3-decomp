#!/usr/bin/env python3
"""Fuzzy function matcher (Phase A).

Two matching directions:

1. corpus fuzzy  (byte-level, normalized via fingerprint.normalize):
   Kamui/Katana named corpus <-> Ghidra-known function bodies of a target
   binary.  Scores functions by shared word-shingles (rarity-weighted),
   then difflib ratio on the normalized word streams.

2. cross-build fuzzy (mnemonic-level):
   1ST_READ <-> VF3TBE3 (+ RELOAD) using Ghidra mnemonic exports.
   Same shingle index approach over mnemonic streams.

Outputs (extract/analysis/):
  fuzzy_<target>.csv    addr,name,score,tier   (tier in {auto,cand})
  crossbuild_map.csv    retail_addr,e3_addr,score
and docs/matches_fuzzy.md summary.
"""
import csv
import difflib
import math
import os
import sys
from collections import defaultdict

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ANALYSIS = os.path.join(REPO, "extract", "analysis")
TARGET_BASE = 0x8C010000

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import fingerprint  # noqa: E402

AUTO_T = 0.92          # auto-name threshold
CAND_T = 0.80          # review threshold
SHINGLE = 4            # word shingle size (byte-level corpus path)
MSHINGLE = 4           # mnemonic shingle size (cross-build path)
MIN_TOKS = 6           # minimum tokenised length to index a function


# ---------------------------------------------------------------- funcs csv
def load_funcs(name):
    path = os.path.join(ANALYSIS, f"funcs_{name}.csv")
    rows = []
    with open(path) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["entry"], 16), int(r["size"])))
    return rows


def load_export(name):
    """export_<name>.txt -> {addr:int -> [mnemonics]} (underscore = delay slot marker)."""
    path = os.path.join(ANALYSIS, f"export_{name}.txt")
    funcs = {}
    cur_addr, cur = None, None
    with open(path) as f:
        for line in f:
            if line.startswith("FN "):
                if cur is not None:
                    funcs[cur_addr] = cur
                t = line.split()
                cur_addr = int(t[1], 16)
                cur = []
            elif cur is not None:
                cur.append(line.strip().lstrip("_"))
    if cur is not None:
        funcs[cur_addr] = cur
    return funcs


# ------------------------------------------------------------- shingle index
class ShingleIndex(object):
    def __init__(self, k):
        self.k = k
        self.index = defaultdict(list)     # shingle -> [id]
        self.items = {}                    # id -> token list
        self.shcounts = {}                 # id -> shingle count

    def shingles(self, toks):
        k = self.k
        if len(toks) < k:
            return {hash(tuple(toks))}
        return {hash(tuple(toks[i:i + k])) for i in range(len(toks) - k + 1)}

    def add(self, ident, toks):
        self.items[ident] = toks
        sh = self.shingles(toks)
        self.shcounts[ident] = max(len(sh), 1)
        for s in sh:
            self.index[s].append(ident)

    def candidates(self, toks, exclude_ids=None, top=20):
        """Score = sum(1/(1+df)) / sqrt(shcount*own) — rarity-weighted overlap."""
        scores = defaultdict(float)
        qs = self.shingles(toks)
        for s in qs:
            posts = self.index.get(s)
            if not posts:
                continue
            w = 1.0 / (1 + len(posts))
            for ident in posts:
                if exclude_ids and ident in exclude_ids:
                    continue
                scores[ident] += w
        own = math.sqrt(len(qs)) if qs else 1.0
        out = [(idt, sc / (own * math.sqrt(self.shcounts.get(idt, 1))))
               for idt, sc in scores.items()]
        out.sort(key=lambda t: -t[1])
        return out[:top]


# ---------------------------------------------------------------- corpus side
def corpus_fuzzy(target_name):
    """Return [(addr, name, score, tier)]."""
    corpus = fingerprint.build_corpus()
    norm_corpus = {}
    for nm, blob in corpus.items():
        toks = tuple(fingerprint.norm_word(blob[i] | (blob[i + 1] << 8))
                     for i in range(0, len(blob) - 1, 2))
        norm_corpus[nm] = toks
    print(f"corpus: {len(norm_corpus)} named functions")

    target_bin = os.path.join(REPO, "extract", "exe",
                              target_name + ".unsc.bin")
    tb = open(target_bin, "rb").read()

    # index target functions (normalized word streams)
    tindex = ShingleIndex(SHINGLE)
    fn_toks = {}
    for addr, size in load_funcs(target_name + ".unsc.bin"):
        off = addr - TARGET_BASE
        if off < 0 or off + size > len(tb) or size < MIN_TOKS * 2:
            continue
        blob = tb[off:off + size]
        toks = tuple(fingerprint.norm_word(blob[i] | (blob[i + 1] << 8))
                     for i in range(0, size - 1, 2))
        if len(toks) < MIN_TOKS:
            continue
        fn_toks[addr] = toks
        tindex.add(addr, toks)
    print(f"{target_name}: {len(fn_toks)} target functions indexed")

    results = []
    for nm, ctoks in norm_corpus.items():
        if len(ctoks) < MIN_TOKS:
            continue
        cands = tindex.candidates(ctoks, top=30)
        best = None
        for addr, wsc in cands:
            ttoks = fn_toks[addr]
            # quick length sanity
            r = len(ctoks) / float(len(ttoks))
            if r < 0.5 or r > 2.0:
                continue
            ratio = difflib.SequenceMatcher(
                None, ctoks, ttoks, autojunk=False).ratio()
            # size-similarity bonus for near-identical lengths
            if best is None or ratio > best[1]:
                best = (addr, ratio)
        if best and best[1] >= CAND_T:
            tier = "auto" if best[1] >= AUTO_T else "cand"
            results.append((best[0], nm, round(best[1], 4), tier))
    results.sort()
    return results


# ------------------------------------------------------------- cross build
def crossbuild(a_name, b_name):
    A = load_export(a_name)
    B = load_export(b_name)
    print(f"{a_name}: {len(A)} fns ; {b_name}: {len(B)} fns exported")
    exactB = defaultdict(list)
    for baddr, btoks in B.items():
        exactB[tuple(btoks)].append(baddr)
    bindex = ShingleIndex(MSHINGLE)
    for addr, toks in B.items():
        if len(toks) >= MIN_TOKS:
            bindex.add(addr, tuple(toks))
    pairs = []
    n_exact = 0
    for addr, atoks in A.items():
        hit = exactB.get(tuple(atoks))
        if hit:
            pairs.append((addr, hit[0], 1.0))
            n_exact += 1
            continue
        if len(atoks) < MIN_TOKS:
            continue
        cands = bindex.candidates(tuple(atoks), top=20)
        best = None
        for baddr, wsc in cands:
            btoks = B[baddr]
            r = len(atoks) / float(len(btoks))
            if r < 0.55 or r > 1.8:
                continue
            ratio = difflib.SequenceMatcher(
                None, tuple(atoks), tuple(btoks), autojunk=False).ratio()
            if best is None or ratio > best[1]:
                best = (baddr, ratio)
        if best and best[1] >= CAND_T:
            pairs.append((addr, best[0], round(best[1], 4)))
    pairs.sort()
    print(f"  exact={n_exact} fuzzy={len(pairs) - n_exact}")
    return pairs


def main():
    # 1) corpus fuzzy per binary
    all_res = {}
    for tgt in ("1ST_READ", "VF3TBE3", "RELOAD"):
        res = corpus_fuzzy(tgt)
        all_res[tgt] = res
        auto = sum(1 for r in res if r[3] == "auto")
        print(f"{tgt}: fuzzy corpus matches {len(res)} (auto {auto})")
        with open(os.path.join(ANALYSIS, f"fuzzy_{tgt}.csv"),
                  "w", newline="") as c:
            w = csv.writer(c)
            w.writerow(["addr", "name", "score", "tier"])
            for addr, nm, sc, tier in res:
                w.writerow([f"0x{addr:08X}", nm, f"{sc:.4f}", tier])

    # 2) cross-build map
    pairs = crossbuild("1ST_READ.unsc.bin", "VF3TBE3.unsc.bin")
    with open(os.path.join(ANALYSIS, "crossbuild_map.csv"), "w", newline="") as c:
        w = csv.writer(c)
        w.writerow(["retail_addr", "e3_addr", "score"])
        for a, b, sc in pairs:
            w.writerow([f"0x{a:08X}", f"0x{b:08X}", f"{sc:.4f}"])
    auto_p = sum(1 for p in pairs if p[2] >= AUTO_T)
    print(f"crossbuild pairs: {len(pairs)} (auto>=0.92: {auto_p})")

    # 3) summary doc
    with open(os.path.join(REPO, "docs", "matches_fuzzy.md"), "w",
              newline="\n", encoding="utf-8") as d:
        d.write("# Fuzzy matching results (Phase A)\n\n")
        d.write("Byte-level corpus fuzzy: difflib over normalized instruction words,\n"
                "shingle-pruned candidates.  Cross-build: mnemonic-stream fuzzy between\n"
                "retail and E3 builds.\n\n")
        for tgt, res in all_res.items():
            auto = [r for r in res if r[3] == "auto"]
            d.write(f"\n## {tgt} — {len(res)} corpus fuzzy matches "
                    f"({len(auto)} auto)\n\n")
            d.write("| addr | name | score | tier |\n|---|---|---|---|\n")
            for addr, nm, sc, tier in sorted(res, key=lambda r: -r[2])[:200]:
                d.write(f"| 0x{addr:08X} | {nm} | {sc:.4f} | {tier} |\n")
        d.write(f"\n## Cross-build 1ST_READ <-> VF3TBE3: {len(pairs)} pairs "
                f"({auto_p} auto)\n\n")
        d.write("| retail | e3 | score |\n|---|---|---|\n")
        for a, b, sc in sorted(pairs, key=lambda p: -p[2])[:300]:
            d.write(f"| 0x{a:08X} | 0x{b:08X} | {sc:.4f} |\n")


if __name__ == "__main__":
    main()
