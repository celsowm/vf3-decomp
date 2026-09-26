#!/usr/bin/env python3
"""cases_dropwin.py — derive a narrower .cases from a golden capture.

Drops one RAM window (e.g. a callee-owned stack page a scope-cut port does
not reproduce) from every case line and re-slices the concatenated entry /
exit bins to match. Register snapshots are untouched.

Usage:
  python tools/cases_dropwin.py <dir>/f_<pc>.cases <winbase_hex> <suffix>
    -> <dir>/f_<pc>.<suffix>.cases + f_<pc>.<suffix>.ramN.bin (+ .meta)

winbase_hex selects the window to drop (matches the entry base token).
Only lines whose entry/exit window lists both contain it are rewritten;
register-only lines ('- 0 - 0') pass through unchanged.
"""
import os
import sys

def parse_wins(toks, i):
    n = int(toks[i]); i += 1
    wins = []
    for _ in range(n):
        wins.append((toks[i], toks[i + 1])); i += 2
    return wins, i

def main():
    cases_path, dropbase, suffix = sys.argv[1], sys.argv[2].lower(), sys.argv[3]
    d = os.path.dirname(cases_path)
    base = os.path.basename(cases_path)
    assert base.endswith('.cases')
    stem = base[:-len('.cases')]
    out_cases = os.path.join(d, stem + '.' + suffix + '.cases')
    # window sizes come from the first RAM line; entry/exit share layout
    with open(cases_path) as f:
        lines = f.read().splitlines()
    # collect per-line rewrites first (need bin slicing per referenced blob)
    rewritten = []
    for ln in lines:
        t = ln.split()
        if len(t) < 74 + 4:
            rewritten.append((ln, None))
            continue
        rest = t[74:]
        ename = rest[0]
        if ename == '-':
            rewritten.append((ln, None))
            continue
        ewins, i = parse_wins(rest, 1)
        xname = rest[i]; i += 1
        xwins, i = parse_wins(rest, i)
        eb = [w[0].lower() for w in ewins]
        xb = [w[0].lower() for w in xwins]
        if dropbase not in eb or dropbase not in xb:
            rewritten.append((ln, None))
            continue
        di = eb.index(dropbase)
        keep = [k for k in range(len(ewins)) if k != di]
        if [xwins[k] for k in keep] != [ewins[k] for k in keep]:
            rewritten.append((ln, None))
            continue
        sizes = [int(w[1], 16) for w in ewins]
        off = sum(sizes[:di]); ln_drop = sizes[di]
        new_e = [(ewins[k][0], ewins[k][1]) for k in keep]
        elt = t[:74] + [ename + '.tmp']  # placeholder, fixed below
        rewritten.append((ln, (ename, xname, new_e, off, ln_drop, t[:74])))
    # slice each distinct blob once
    cache = {}
    def slice_blob(name, winsizes, dropidx):
        if (name, dropidx) in cache:
            return cache[(name, dropidx)]
        with open(os.path.join(d, name), 'rb') as f:
            blob = f.read()
        assert len(blob) == sum(winsizes), (name, len(blob), sum(winsizes))
        parts, pos = [], 0
        for k, sz in enumerate(winsizes):
            if k != dropidx:
                parts.append(blob[pos:pos + sz])
            pos += sz
        nb = b''.join(parts)
        cache[(name, dropidx)] = nb
        return nb
    out_lines = []
    for ln, rw in rewritten:
        if rw is None:
            out_lines.append(ln)
            continue
        ename, xname, new_e, off, ln_drop, head = rw
        t = ln.split(); rest = t[74:]
        ewins, i = parse_wins(rest, 1)
        sizes = [int(w[1], 16) for w in ewins]
        di = [w[0].lower() for w in ewins].index(dropbase)
        for blobname in (ename, xname):
            nb = slice_blob(blobname, sizes, di)
            oname = blobname.replace('.ram', '.' + suffix + '.ram').replace(
                '.exitram', '.' + suffix + '.exitram')
            with open(os.path.join(d, oname), 'wb') as f:
                f.write(nb)
        en = ename.replace('.ram', '.' + suffix + '.ram')
        xn = xname.replace('.exitram', '.' + suffix + '.exitram')
        toks = list(head) + [en, str(len(new_e))]
        for b, l in new_e:
            toks += [b, l]
        toks += [xn, str(len(new_e))]
        for b, l in new_e:
            toks += [b, l]
        out_lines.append(' '.join(toks))
    with open(out_cases, 'w') as f:
        f.write('\n'.join(out_lines) + '\n')
    # derived metas (for humans; harness ignores them)
    for (blobname, dropidx), nb in cache.items():
        oname = blobname.replace('.ram', '.' + suffix + '.ram').replace(
            '.exitram', '.' + suffix + '.exitram')
        try:
            meta = open(os.path.join(d, blobname + '.meta')).read().splitlines()
        except OSError:
            continue
        kept = [l for k, l in enumerate(meta) if k != dropidx]
        with open(os.path.join(d, oname + '.meta'), 'w') as f:
            f.write('\n'.join(kept) + '\n')
    print(f'cases_dropwin: {out_cases} ({len(out_lines)} lines, '
          f'dropped {dropbase})')

if __name__ == '__main__':
    main()
