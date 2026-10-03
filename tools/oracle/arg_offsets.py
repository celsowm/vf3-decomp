import re
import sys
from pathlib import Path

# Track `mov #imm,rN` and resolve later `@(rN,r14)` uses, so register-indirect
# byte/word reads of the r14 argument object are counted as real offsets.
p = Path(sys.argv[1] if len(sys.argv) > 1 else "extract/analysis/dis_8c0c321e.txt")
reg = sys.argv[2] if len(sys.argv) > 2 else "r14"

cur: dict[str, int] = {}
hits: dict[int, list[str]] = {}
for line in p.read_text(encoding="utf-8", errors="replace").splitlines():
    m = re.match(r"^([0-9a-f]{8})\s+([0-9a-f]{4})\s+(\S.*)$", line)
    if not m:
        continue
    pc, _, txt = m.groups()
    src = txt.lstrip("_").strip()
    t = re.match(r"^mov\s+#(-?(?:0x)?[0-9a-f]+),(r\d+)$", src)
    if t:
        v = t.group(1)
        cur[t.group(2)] = int(v, 16) if v.startswith("0x") else int(v, 0)
        continue
    dst = re.search(r",(r\d+)$", src)
    if re.match(r"^mova\b|^mov\.l\s+0x", src) and dst:
        cur.pop(dst.group(1), None)
    for a in re.finditer(rf"@\((\d+|0x[0-9a-f]+|\w+),{reg}\)", src):
        tok = a.group(1)
        if tok in cur:
            hits.setdefault(cur[tok] & 0xFFFF, []).append(pc)
        elif tok.isdigit() or tok.startswith("0x"):
            v = int(tok, 16) if tok.startswith("0x") else int(tok)
            hits.setdefault(v & 0xFFFF, []).append(pc)

for off in sorted(hits):
    print(f"  {reg}+0x{off:02x} ({off:5d})  x{len(hits[off]):<3} first={hits[off][0]}")
print(f"distinct {reg} displacements: {len(hits)}")
