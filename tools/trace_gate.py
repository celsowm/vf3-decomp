"""Show first-seen index + hit counts for key candidate functions."""
import csv, os, sys

AN = r"E:\vf3-decomp\extract\analysis"
funcs = {int(r["entry"], 16): r["name"]
         for r in csv.DictReader(open(os.path.join(AN, "funcs_1ST_READ.unsc.bin.csv")))}
fs = {int(r["fn"], 16): int(r["first_trace_idx"])
      for r in csv.DictReader(open(os.path.join(AN, "trace_fn_first_seen.csv")))}
hits = {int(r["fn"], 16): int(r["hits"])
        for r in csv.DictReader(open(os.path.join(AN, "trace_fn_hits.csv")))}

cands = [
    ("mt_loader",     "0x8C02DCEC"),
    ("stage_load",    "0x8C0B7302"),
    ("stage_update",  "0x8C0B744C"),
    ("coli_run",      "0x8C09AAE2"),
    ("bjload_run",    "0x8C0CBC40"),
    ("load_mt_pai",   "0x8C04BDA2"),
    ("load_mt_aki",   "0x8C08232E"),
    ("task_run_A",    "0x8C05E64E"),
    ("task_run_B",    "0x8C05B086"),
    ("task_run_C",    "0x8C0796F4"),
    ("scene_mgr_A",   "0x8C07D368"),
    ("scene_mgr_B",   "0x8C063F58"),
    ("scene_mgr_C",   "0x8C0516A8"),
]

print(f"{'addr':<12s} {'first_seen':>12s} {'hits':>10s}")
for label, a in cands:
    addr = int(a, 16)
    print(f"{label:<12s} 0x{addr:08X}  {fs.get(addr,0):>12,} {hits.get(addr,0):>10,}")

# also dump what comes in the first 5 distinct functions in the
# f_8c05/06/07 region (scene candidates)
print("\nfirst-seen order, region 0x8C020000-0x8C07FFFF:")
rows = sorted((ti, a) for a, ti in fs.items() if 0x8C020000 <= a < 0x8C080000)
for ti, a in rows[:28]:
    print(f"  trace#{ti:>12,}  0x{a:08X}  {funcs.get(a,'?')}")
