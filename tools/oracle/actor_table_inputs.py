"""Prepare bounded pointer inputs for original actor-table setter calls.

Expected values are obtained only by executing the original game. The static
command extraction narrows the initialized command slots; it grants no credit.
"""
import argparse
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c0a3242: 0x8c0a3246, 0x8c0a3504: 0x8c0a3508,
          0x8c0a38ae: 0x8c0a38b2, 0x8c0a3af2: 0x8c0a3af6}
EXTRA_OWNERS = {0x8c0a4664: 0x8c0a4668, 0x8c0a4d3c: 0x8c0a4d40,
                0x8c0a5758: 0x8c0a575c, 0x8c0a5b50: 0x8c0a5b54,
                0x8c0a5d98: 0x8c0a5d9c, 0x8c0a3e1e: 0x8c0a3e22,
                0x8c0a52ec: 0x8c0a52f0, 0x8c0a4410: 0x8c0a4414,
                0x8c0a423a: 0x8c0a423e, 0x8c0a4b5e: 0x8c0a4b62,
                0x8c0a61fa: 0x8c0a61fe, 0x8c0a40ac: 0x8c0a40b0,
                0x8c0a486e: 0x8c0a4872, 0x8c0a49e2: 0x8c0a49e6,
                0x8c0a4efc: 0x8c0a4f00, 0x8c0a5068: 0x8c0a506c,
                0x8c0a5f52: 0x8c0a5f56, 0x8c0a609a: 0x8c0a609e}


def command_ids(entry):
    import sys
    sys.path.insert(0, str(ROOT / 'tools'))
    from batch_plan import implementation_graph
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    pcs, _, _ = implementation_graph(image, {})(entry)
    commands = set()
    for pc in pcs:
        w = struct.unpack_from('<H', image, pc - 0x8c010000)[0]
        if w & 0xff00 == 0xe400:
            value = w & 255
            if value & 128:
                value -= 256
            commands.add(value)
        elif w & 0xff00 == 0x9400:
            pool = pc + 4 + (w & 255)*2
            commands.add(struct.unpack_from('<h', image, pool - 0x8c010000)[0])
    assert commands and min(commands) >= 0 and max(commands) < 0x1000
    return sorted(commands)


def prepare(name, output, variants, development_freeze=None, extra=False):
    owners_by_entry = EXTRA_OWNERS if extra else OWNERS
    frozen = None
    if development_freeze:
        import hashlib
        frozen = json.loads(development_freeze.read_text())
        assert frozen['qualified_development_only'], 'need qualified frozen development'
        for ref in frozen['references']:
            with Path(ref['path']).open('rb') as stream:
                assert hashlib.file_digest(stream, 'sha256').hexdigest() == ref['sha256']
    output.mkdir(parents=True, exist_ok=True)
    watch = output / f'{name}_watch.txt'
    patch = output / f'{name}.patch'
    owners = output / f'{name}_owners.json'
    recipe = output / f'{name}_inputs.json'
    if any(p.exists() for p in (watch, patch, owners, recipe)):
        raise FileExistsError('refusing to overwrite retained table inputs')
    memory, registers = {}, {}
    for entry in owners_by_entry:
        commands = command_ids(entry)
        fields = {'0xc400010': 0xc420000}
        if extra:
            fields.update({'0xc29bb94': 0xc1fefe4, '0xc29bb98': 0xc20138c,
                           '0xc1ff044': 0, '0xc2013ec': 0})
        for index in range(58):
            node = 0xc430000 + 16*index
            fields[hex(0xc420000 + 4*index)] = node
            fields[hex(node)] = [(index*0x10001 + v*0x101 + (0xa5000037 if frozen else 0)) & 0xffffffff
                                 for v in range(variants)]
            fields[hex(node+4)] = [0x80000003, 2, 0x100, 5] if frozen else [0, 1, 2, 3]
        for index, command in enumerate(commands):
            fields[hex(0xc2a1c3c+4*command)] = {'values': [0, 0xffffffff, 0xc430000+16*(index%58)],
                                                          'stride': 5 if frozen else 4,
                                                          'phase': (index+7 if frozen else index)%3}
        memory[hex(entry)] = fields
        registers[hex(entry)] = {'r4': 0xc400000}
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in owners_by_entry))
    owners.write_text(json.dumps({hex(e): hex(o) for e, o in owners_by_entry.items()}, indent=2)+'\n')
    data = dict(advisory=True, coverage_credit=False, variants=variants,
                memory=memory, registers=registers, relocation='0x100000' if frozen else '0x0')
    if frozen:
        data['development_freeze'] = dict(path=str(development_freeze.resolve()),
            sha256=hashlib.sha256(development_freeze.read_bytes()).hexdigest())
    recipe.write_text(json.dumps(data, indent=2)+'\n')
    generate(watch, patch, 0x8c0432e2, variants, fpscr=0x240001 if frozen else 0x40001,
             relocation=0x100000 if frozen else 0, holdout_inputs=bool(frozen),
             bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)
    print(watch)
    print(patch)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--name', required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=128)
    parser.add_argument('--development-freeze', type=Path)
    parser.add_argument('--extra', action='store_true')
    args = parser.parse_args()
    prepare(args.name, args.out, args.variants, args.development_freeze, args.extra)
