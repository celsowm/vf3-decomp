import re, glob, os

nat = set()
for f in glob.glob('src/native/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'0[xX]([0-9a-fA-F]{6,8})\b', s):
        nat.add(m.group(1).lower()[-6:])

reg = {}
for f in glob.glob('src/fight/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'\{\s*0x0c([0-9a-fA-F]{6})u?\s*,\s*"([a-zA-Z0-9_]+)"\s*,\s*([a-zA-Z0-9_]+)\s*,\s*([^}]*)\}', s):
        a = m.group(1).lower()
        if a not in reg:
            reg[a] = (m.group(2), m.group(3))

def canon0(tok):
    tok = tok.strip()
    m = re.match(r'^0[xX]([0-9a-fA-F]+)', tok)
    if not m: return None
    return '%06x' % (int(m.group(1), 16) & 0xFFFFFF)

cache = {}
def def_file(name):
    if name in cache: return cache[name]
    for f in glob.glob('src/fight/*.c') + glob.glob('src/native/*.c'):
        if os.path.basename(f) == 'readable.c': continue
        t = open(f, encoding='utf-8', errors='replace').read()
        if re.search(r'\bint\s+vf3_'+re.escape(name)+r'_entry\s*\(', t):
            consts = {}
            for m in re.finditer(r'#define\s+([A-Za-z_]\w*)[ \t]+\(?\s*(0[xX][0-9a-fA-F]+|\d+)', t):
                consts[m.group(1)] = m.group(2).lower()
            for m in re.finditer(r'\b([A-Z][A-Z0-9_]{2,})\s*=\s*(0[xX][0-9a-fA-F]+)', t):
                consts[m.group(1)] = m.group(2).lower()
            cache[name] = (t, consts)
            return cache[name]
    cache[name] = (None, {})
    return cache[name]

unserved = [a for a in reg if a not in nat]

def canon(tok, consts):
    tok = tok.strip()
    if tok in consts: tok = consts[tok]
    return canon0(tok)

result = {}
for a in sorted(unserved):
    name = reg[a][0]
    t, consts = def_file(name)
    if not t:
        result[a] = ('NOFILE', [], False)
        continue
    targets = set(); runtime = False
    rholder = {'runtime': False}
    def add(tok):
        c = canon(tok, consts)
        if c: targets.add(c)
        else: rholder['runtime'] = True
    rconst = {}
    for m in re.finditer(r'\bR\(\s*(\d+)\s*\)\s*=\s*(0[xX][0-9a-fA-F]+|[A-Z][A-Z0-9_]{2,})\s*;', t):
        v = m.group(2)
        v2 = v if v[0].lower()=='0' and len(v)>2 else consts.get(v, v)
        rconst[int(m.group(1))] = v2
    for m in re.finditer(r'vf3_guest_call\s*\(', t):
        seg = t[m.end():m.end()+160]
        parts=[]; depth=0; cur=''
        for ch in seg:
            if ch in '([{': depth+=1
            elif ch in ')]}': depth-=1
            if ch==',' and depth==0: parts.append(cur); cur=''
            elif depth>=0: cur+=ch
            if len(parts)>=3: break
        if len(parts)>=3:
            tgt = parts[2].strip()
            mm = re.match(r'^R\(\s*(\d+)\s*\)$', tgt)
            if mm:
                rv = rconst.get(int(mm.group(1)))
                if rv: add(rv)
                else: runtime = True
            else: add(tgt)
    for m in re.finditer(r'vf3_guest_tail_call\s*\(([^)]*)\)', t):
        ps=[p.strip() for p in m.group(1).split(',')]
        if len(ps)>=3:
            tgt=ps[2]; mm=re.match(r'^R\(\s*(\d+)\s*\)$',tgt)
            if mm:
                rv=rconst.get(int(mm.group(1)))
                if rv: add(rv)
                else: runtime=True
            else: add(tgt)
    for m in re.finditer(r'\bCALL\s*\(([^)]*)\)', t):
        ps=[p.strip() for p in m.group(1).split(',')]
        if ps:
            mm=re.match(r'^R\(\s*(\d+)\s*\)$',ps[0])
            if mm:
                rv=rconst.get(int(mm.group(1)))
                if rv: add(rv)
                else: runtime=True
            else: add(ps[0])
    for m in re.finditer(r'vf3_matrix_family\s*\(([^)]*)\)', t):
        ps=[p.strip() for p in m.group(1).split(',')]
        if ps:
            mm=re.match(r'^R\(\s*(\d+)\s*\)$',ps[0])
            if mm:
                rv=rconst.get(int(mm.group(1)))
                if rv: add(rv)
                else: runtime=True
            else: add(ps[0])
    nn = sorted(x for x in targets if x not in nat)
    result[a] = (name, nn, runtime)

# print full classification
for a in sorted(unserved):
    name, nn, runtime = result[a]
    if runtime:
        tag='RUNTIME?'
    elif nn:
        tag='blocked nonnative=%s'%nn
    else:
        tag='CLEAN-WIN'
    print('%-20s %s %s'%(name, a, tag))
