# 070x fragment candidate triage (2026-09-29)

## 0x8C070874

A 600-frame capture watched entry `0x8C070874`, alternate tail `0x8C070884`,
and candidate fragment end `0x8C0708AC`, with broad stack/object/vector RAM
windows. It recorded 1,002 entry hits and 26,636 hits at `0x8C0708AC`, but
`pair_cases.py` could not pair an entry with either boundary before the next
`0x8C070874` hit. The fragment is part of a loop-carried pipeline, so the
observed checkpoints do not isolate one invocation. Keep it uncredited.

Watch recipe: `tools/watch/vf3_070874_boundary.txt`.

## 0x8C071E3A

A 600-frame capture recorded 1,606 entry hits, no hits at the alternate tail
`0x8C071E50`, and 6,436 checkpoint hits at the inventory boundary
`0x8C071E76`. Same-invocation pairing yielded only 15 distinct rows at the
boundary. The 60-byte body has a long FPU stream and the observed rows do not
yet explain its register results from the entry state; keep it uncredited.

Watch recipe: `tools/watch/vf3_071e3a_boundary.txt`.
