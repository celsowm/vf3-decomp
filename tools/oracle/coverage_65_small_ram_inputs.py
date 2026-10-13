"""Bounded inputs for four RAM candidates to supplement actor registration."""
import argparse
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c0885c4: 0x8c0885d8, 0x8c07b6f4: 0x8c07b6f4,
          0x8c08c054: 0x8c08c054, 0x8c0860c2: 0x8c0860c6}


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare(output, variants, development_freeze=None):
    import hashlib
    frozen=None
    if development_freeze:
        frozen=json.loads(development_freeze.read_text())
        assert frozen['qualified_development_only'],'need qualified frozen development'
        for ref in frozen['references']:
            with Path(ref['path']).open('rb') as f:
                assert hashlib.file_digest(f,'sha256').hexdigest()==ref['sha256']
    output.mkdir(parents=True, exist_ok=True)
    watch, patch, recipe = output/'watch.txt', output/'entry.patch', output/'inputs.json'
    if any(p.exists() for p in (watch, patch, recipe)):
        raise FileExistsError('refusing to replace RAM inputs')
    registers, memory = {}, {}
    for entry in OWNERS:
        fields = {}
        key = hex(entry)
        if entry == 0x8c0885c4:
            registers[key] = dict(r4=0xc400000, r5=0xc404000, r6=0xc408000, r7=0xc40c000)
            for index, offset in enumerate((0, 4, 8)):
                fields[hex(0xc400000+offset)] = [bits(v) for v in ((-120,-3,0.125,3,90,220) if frozen else (-100, -1, 0, 1, 100, 200))]
                fields[hex(0xc404000+offset)] = {'values': [bits(v) for v in ((-3,0.125,0.75,3) if frozen else (-2, 0, 0.25, 2))],
                                               'stride': 2+index}
            fields.update({'0xc40c000': {'values': [0, 1, 2, 3], 'stride': 4},
                '0xc414000': {'values': [0, 1, 15, 16, 31, 32, 33], 'stride': 2},
                '0xc690100': 0xc410000, '0xc690104': 0xc414000, '0xc690108': 0xc418000,
                '0xc410000': [0, 0x1000, 0x2000, 0x7fff], '0xc418000': 0,
                '0xc1b9610': 0, '0xc29b880': 0})
        elif entry == 0x8c07b6f4:
            registers[key] = dict(r4=[0x050a,0x060c,0x070e,0x0810] if frozen else [0x0102, 0x0204, 0x0306, 0x0408],
                                 r5=[0, 1, 2, 3], r6=0xc400000, r7=0)
            fields['0xc40000c'] = 0xc420000
            fields.update({'0xc690100': 0, '0xc690104': 0})
            for index in range(120):
                base = 0xc420000+68*index
                fields[hex(base)] = [0, 0x10001, 0x20001, 0x30001]
                fields[hex(base+4)] = 1 << 16
                fields[hex(base+8)] = 2
        elif entry == 0x8c08c054:
            registers[key] = dict(r4=0xc1fefe4, r5=0xc404000)
            fields.update({'0xc404000': [0, 1, 4, 0x8000],
                '0xc404010': {'values': [0, 0x10000, 0x8000, 0x20000, 0x8020000], 'stride': 4},
                '0xc404014': {'values': [0, 0x2000], 'stride': 8},
                '0xc40404c': 0xc20138c,
                '0xc2013c8': {'values': [0, 0x631, 0x338, 0x339, 0x33a, 0x33b, 0x33c], 'stride': 2},
                '0xc2013dc': {'values': [0, 0x80000], 'stride': 16}})
        else:
            # The retail code explicitly zero-extends each selector byte.
            # Exercise that byte's boundaries without changing its table:
            # every resulting indexed read remains inside the retail image.
            selectors = [0, 1, 8, 12, 21, 25, 31, 63, 127, 255]
            registers[key] = dict(r4=0xc400000)
            fields.update({'0xc29bb94': 0xc1fefe4, '0xc29bb98': 0xc20138c,
                '0xc1ff044': [selectors[i%len(selectors)] for i in range(variants)],
                '0xc2013ec': [selectors[(i//len(selectors)+i)%len(selectors)] for i in range(variants)]})
        memory[key] = fields
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (output/'owners.json').write_text(json.dumps({hex(e): hex(o) for e, o in OWNERS.items()}, indent=2)+'\n')
    data=dict(coverage_credit=False,registers=registers,memory=memory,variants=variants)
    if frozen:data['development_freeze']=dict(path=str(development_freeze.resolve()),sha256=hashlib.sha256(development_freeze.read_bytes()).hexdigest())
    recipe.write_text(json.dumps(data, indent=2)+'\n')
    generate(watch, patch, 0x8c0432e2, variants, fpscr=0x240001 if frozen else 0x40001,
             relocation=0x100000 if frozen else 0,holdout_inputs=bool(frozen),bounded_arguments=True,
             preserve_fields=True, register_overrides=registers, memory_overrides=memory)
    lines = []
    for line in patch.read_text().splitlines():
        lines.append(line)
        if line.startswith('reg 0x8c0432e2 pr '):
            lines.append('reg 0x8c0432e2 r15 0x0c690100')
    patch.write_text('\n'.join(lines)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--development-freeze',type=Path)
    args = parser.parse_args()
    prepare(args.out, args.variants,args.development_freeze)
