# Coverage fast path (2026-09-25) — L1 trace bucket + L4 ports

Decision (user): "Fast (L1+L4)". Adds a clearly-labeled **trace-executed**
bucket. This bucket is *execution-identification, NOT porting or byte-match*:
a credited fn ran during a captured trace (fight or attract) but is neither
decompiled nor SDK-attributed here. Rigorous numbers remain separate.

## Result (docs/coverage.md, tools/decomp_stats.py)

| bucket | fns | % | bytes | % |
|---|---|---|---|---|
| ported | 4 | 0.2% | 1544 | 0.4% |
| SDK-attributed (masked) | 118 | 4.9% | 25694 | 5.9% |
| trace-executed | 159 | 6.6% | 63088 | 14.5% |
| **rigorous (ported+SDK)** | **122** | **5.1%** | **27238** | **6.3%** |
| **total incl. trace** | **281** | **11.7%** | **90326** | **20.8%** |

## Method
- `tools/trace_attrib.py`: maps `trace_fn_first_seen.csv` /
  `trace_fn_hits.csv` waypoint addresses onto containing baseline fns
  (bisect, 0x0C P2 -> 0x8C P1 alias). 161 baseline fns carry trace evidence;
  126/366 waypoints are unmapped (mid-body data islands / over-range).
- `decomp_stats.py` reads it as a distinct row; ported+SDK stay rigorous.

## L4 status
Top-10 unclaimed heads (`FUN_8c0750be`, `f_8c0782ea`, `f_8c076c00`,
`FUN_8c0673a8`, ...) are large struct-offset AI/engine bodies (switch-table
blade dispatch, ~90 blades). Full transliteration is multi-milestone; partial
blade/leaf ports ship as structural models with annotated dumps. Trace bucket
already carries them as executed; byte parity remains the rigorous target.
