import re, glob, os

# registry
reg = {}
for f in glob.glob('src/fight/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'\{\s*0x0c([0-9a-fA-F]{6})u?\s*,\s*"([a-zA-Z0-9_]+)"\s*,\s*([a-zA-Z0-9_]+)\s*,\s*([^}]*)\}', s):
        a = m.group(1).lower()
        if a not in reg:
            reg[a] = (m.group(2), m.group(3))

# native-served low6
nat = set()
for f in glob.glob('src/native/*.c'):
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'0[xX]([0-9a-fA-F]{6,8})\b', s):
        nat.add(m.group(1).lower()[-6:])

# find port source: name->(file, entry fn body)
portsrc = {}
for f in glob.glob('src/fight/*.c') + glob.glob('src/native/*.c'):
    if os.path.basename(f) == 'readable.c': continue
    s = open(f, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'vf3_([a-zA-Z0-9_]+)_entry\s*\(', s):
        portsrc.setdefault(m.group(1), set()).add(f)

unserved = [a for a in reg if a not in nat]

def count_calls(name):
    # count call-like forms in the whole file (approximate)
    if name not in portsrc: return None
    files = portsrc[name]
    tot = 0
    callkinds = set()
    for f in files:
        s = open(f, encoding='utf-8', errors='replace').read()
        tot += len(re.findall(r'vf3_guest_call\s*\(', s))
        tot += len(re.findall(r'vf3_guest_tail_call\s*\(', s))
        tot += len(re.findall(r'\bCALL\s*\(', s))
        tot += len(re.findall(r'vf3_matrix_family\s*\(', s))
        if re.search(r'vf3_guest_call', s): callkinds.add('guest_call')
        if re.search(r'vf3_guest_tail_call', s): callkinds.add('tail_call')
        if re.search(r'\bCALL\s*\(', s): callkinds.add('CALL')
        if re.search(r'vf3_matrix_family', s): callkinds.add('matrix_family')
    return tot, callkinds, files

print("=== call-heavy analysis (unserved entries) ===")
rows=[]
for a in sorted(unserved):
    name = reg[a][0]
    r = count_calls(name)
    if r and r[0] == 0:
        rows.append((a,name,'CALL-FREE(0 calls)',r[2]))
    elif r is None:
        rows.append((a,name,'NO-PORT-SRC',[]))
for a,name,tag,files in rows:
    print('%-20s %s %s %s'%(name,a,tag, os.path.basename(list(files)[0]) if files else ''))
