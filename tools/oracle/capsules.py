#!/usr/bin/env python3
"""Convert invocation-addressed VF3CAP3/4 specimens into compatible .cases.

The fingerprint includes registers, XF, FPUL and initial RAM. Repeated inputs
with different exits are errors, never silently deduplicated. Invalid samples
are retained in the manifest but excluded from replay. All reads are bounded.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct

PAGE = 4096

def records(path):
    with Path(path).open("rb") as f:
        def take(n):
            data = f.read(n)
            if len(data) != n:
                raise ValueError(f"{path}: truncated record at {f.tell()}")
            return data
        magic=take(8)
        if magic not in (b"VF3CAP3\0",b"VF3CAP4\0"):
            raise ValueError(f"{path}: unsupported capsule format")
        seen = set()
        while True:
            raw = f.read(8)
            if not raw:
                break
            if len(raw) != 8:
                raise ValueError(f"{path}: truncated invocation ID")
            ident, = struct.unpack("<Q", raw)
            if ident in seen or not ident:
                raise ValueError(f"{path}: duplicate/zero invocation ID {ident}")
            seen.add(ident)
            entry, exitpc, flags, npage, nop, nstate = struct.unpack("<6I", take(24))
            if npage > 128 or nop > 100000 or nstate != (55 if magic==b"VF3CAP4\0" else 54):
                raise ValueError(f"{path}: invalid record sizes")
            before, after = take(nstate*4), take(nstate*4)
            pages = []
            bases = set()
            for _ in range(npage):
                base, = struct.unpack("<I", take(4))
                if base in bases or base % PAGE or not 0x0C000000 <= base < 0x0D000000:
                    raise ValueError(f"{path}: invalid RAM page {base:08x}")
                bases.add(base)
                pages.append((base, take(PAGE), take(PAGE)))
            ops = list(struct.iter_unpack("<2I", take(nop * 8)))
            if not ops or (ops[0][0] & 0x1FFFFFFF) != (entry & 0x1FFFFFFF):
                raise ValueError(f"{path}: missing invocation entry instruction")
            yield dict(id=ident, entry=entry, exitpc=exitpc, flags=flags,
                       before=before, after=after, pages=sorted(pages), ops=ops, nstate=nstate)

def convert(paths, out, entries=None):
    out = Path(out)
    grouped, invalid, runs = defaultdict(dict), [], []
    for path in paths:
        summary=Path(str(path)+'.summary.json')
        run=json.loads(summary.read_text()) if summary.exists() else {"summary_missing":True}
        count=0
        for r in records(path):
            count+=1
            source = dict(source=str(path), invocation=r["id"], entry=f'0x{r["entry"]:08x}',
                          exit=f'0x{r["exitpc"]:08x}')
            if r["flags"]:
                invalid.append({**source, "flags": r["flags"]})
                continue
            if entries is not None and (r['entry']|0x80000000) not in entries:
                continue
            key = hashlib.sha256(r["before"] + b"".join(struct.pack("<I", b)+a for b,a,_ in r["pages"])).hexdigest()
            signature = hashlib.sha256(r["after"] + struct.pack("<I",r["exitpc"])+b"".join(z for _,_,z in r["pages"])).hexdigest()
            bucket = grouped[r["entry"] | 0x80000000]
            if key in bucket:
                if bucket[key]["signature"] != signature:
                    raise ValueError(f"Nondeterministic exit for {source}")
                bucket[key]["sources"].append(source)
            else:
                bucket[key] = {**r, "signature":signature, "sources":[source]}
        if not run.get('summary_missing'):
            if run['completed']!=count or run['started']!=count+len(run['incomplete']):
                raise ValueError(f'{path}: invocation summary disagrees with records')
        runs.append({"source":str(path),**run})
    out.mkdir(parents=True, exist_ok=True)
    manifest = {"format":"VF3CAP4 (CAP3 compatible)", "inputs":[str(p) for p in paths], "runs":runs,"invalid":invalid, "entries":{}}
    if entries is not None: manifest['selected_entries']=[hex(e) for e in sorted(entries)]
    for entry, bucket in sorted(grouped.items()):
        stem = f"f_{entry:08x}"
        lines, xfin, xfout, extras, gbrs, cases = [], bytearray(), bytearray(), bytearray(), bytearray(), []
        allops = {}
        for i, r in enumerate(bucket.values()):
            # Merge adjacent pages to fit older replay runners efficiently.
            wins = []
            for base,a,z in r["pages"]:
                if wins and wins[-1][0]+len(wins[-1][1]) == base:
                    wins[-1][1].extend(a); wins[-1][2].extend(z)
                else:
                    wins.append([base, bytearray(a), bytearray(z)])
            if not wins:
                # Register-only helpers still need a harmless RAM mapping.
                wins = [[0x0C000000, bytearray(4), bytearray(4)]]
            a, z = f"{stem}_{i}.in.bin", f"{stem}_{i}.out.bin"
            (out/a).write_bytes(b"".join(w[1] for w in wins))
            (out/z).write_bytes(b"".join(w[2] for w in wins))
            window = str(len(wins))+" "+" ".join(f"{b:08x} {len(v):x}" for b,v,_ in wins)
            before=struct.unpack(f'<{r["nstate"]}I',r["before"]); after=struct.unpack(f'<{r["nstate"]}I',r["after"])
            lines.append(" ".join(f"{v:08x}" for v in (*before[:37],*after[:37]))+f" {a} {window} {z} {window}")
            xfin.extend(r["before"][148:212]); xfout.extend(r["after"][148:212])
            extras.extend(struct.pack("<4I",before[53],after[53],r["entry"],r["exitpc"]))
            gbrs.extend(struct.pack("<3I",before[54] if r["nstate"]==55 else 0,after[54] if r["nstate"]==55 else 0,r["nstate"]==55))
            cases.append({"sources":r["sources"], "instructions":len(r["ops"]), "pages":len(r["pages"])})
            for pc,op in r["ops"]:
                if pc in allops and allops[pc]!=op:
                    raise ValueError(f"Self-modifying code at {pc:08x}")
                allops[pc]=op
        (out/f"{stem}.cases").write_text("\n".join(lines)+"\n",encoding="ascii")
        (out/f"{stem}.xfin.bin").write_bytes(xfin); (out/f"{stem}.xfout.bin").write_bytes(xfout)
        (out/f"{stem}.extra.bin").write_bytes(extras)
        (out/f"{stem}.gbr.bin").write_bytes(gbrs)
        (out/f"{stem}.ops.json").write_text(json.dumps({f"{pc:08x}":f"{op:04x}" for pc,op in sorted(allops.items())},indent=1))
        manifest["entries"][f"0x{entry:08x}"] = cases
        print(f"{stem}: {len(lines)} distinct complete cases, {len(allops)} executed PCs")
    (out/"capsule_manifest.json").write_text(json.dumps(manifest,indent=1),encoding="utf-8")
    print("Rejected specimens:",dict(Counter(r["flags"] for r in invalid)))
    return manifest

if __name__ == "__main__":
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("capsules", nargs="+")
    ap.add_argument("--out",required=True)
    a=ap.parse_args()
    convert(a.capsules,a.out)
