"""One targeted original pilot for missing selection/unlock branches.

The earlier pilot varied +0x13c, but the unlock test reads scene +0x138.
The configuration editor's mutable byte +0x16 gates the final list scan;
both earlier original scenarios captured its containing word as zero.
No instructions, literal pools, tables of callbacks or returns are changed.
"""
import json
import argparse
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
ENTRY = '0x8c0c3210'
NAME = 'coverage_65_selection_unlock_screen_v1'


def prepare():
    directory = ROOT/'tools/oracle/percentage_inputs'
    prior = 'coverage_65_selection_boundary_dev_v1'
    fields = json.loads((directory/f'{prior}_memory.json').read_text())[ENTRY]
    registers = json.loads((directory/f'{prior}_registers.json').read_text())[ENTRY]
    count = 256
    fields.update({
        '0xc29b864': [0x100 if i%64 == 0 else 0x200 if i%64 == 1 else 0 for i in range(count)],
        '0xc400000': [2 if i%64 == 2 else 8 if i%64 == 3 else 0 for i in range(count)],
        '0xc29b99c': {'values': [0, 16, 32, 48], 'stride': 2},
        '0xc29b94c': {'values': [0, 3], 'stride': 16},
        '0xc29c170': {'values': [0, 0x0101, 0x0303, 0x0505], 'stride': 4},
        '0xc29b8fc': {'values': [0, 0x80000000, 0x00400000, 0xffffffff], 'stride': 32},
        '0xc11e518': {'values': [0, 0x00010000], 'stride': 64},
        '0xc400034': [(0, 1, 3, 9, 13, 22, 25)[i%7]<<8 for i in range(count)],
    })
    # Original list bases are status +0x415 and +0x41a, each five bytes.
    packed = bytearray(16)
    packed[1:6] = bytes((0, 1, 3, 9, 13))
    packed[6:11] = bytes((0, 1, 3, 22, 25))
    for offset in range(0, 16, 4):
        fields[hex(0xc29c0d8+offset)] = int.from_bytes(packed[offset:offset+4], 'little')
    # Original actor records provide the peer selection at bytes +0x60/+0x61.
    for actor in (0xc1fefe4, 0xc20138c):
        fields[hex(actor+0x60)] = {'values': [0, 0x0303, 0x0909, 0x0d0d], 'stride': 8}
    watch = ROOT/f'tools/oracle/{NAME}_watch.txt'
    patch = ROOT/f'extract/analysis/{NAME}.patch'
    paths = [watch, ROOT/f'tools/oracle/{NAME}_owners.json']
    paths += [directory/f'{NAME}_{kind}.json' for kind in ('memory', 'registers')]
    assert not any(path.exists() for path in [*paths, patch]), 'refuse to overwrite evidence'
    watch.write_text(f'pc {ENTRY}\n')
    for path, value in zip(paths[1:], ({ENTRY: '0x8c0c321e'}, {ENTRY: fields}, {ENTRY: registers})):
        path.write_text(json.dumps(value, indent=2)+'\n')
    generate(watch, patch, 0x8c0432e2, count, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True,
             register_overrides={ENTRY: registers}, memory_overrides={ENTRY: fields})


def prepare_followup(version=2):
    """Cross the remaining list/configuration predicates independently."""
    assert version in (2,3)
    name=f'coverage_65_selection_unlock_screen_v{version}'
    base=ROOT/'tools/oracle';directory=base/'percentage_inputs'
    prior=NAME if version==2 else 'coverage_65_selection_unlock_screen_v2'
    memory=json.loads((directory/f'{prior}_memory.json').read_text())
    registers=json.loads((directory/f'{prior}_registers.json').read_text())
    fields=memory[ENTRY]
    fields.update({
        '0xc400004':{'values':[0,1],'stride':2},
        '0xc29b890':{'values':[0,63,64,128],'stride':4},
        '0xc29b8fc':{'values':[0,0x80000000,0x00400000,0xffffffff],'stride':1},
        '0xc11e518':{'values':[0,0x00010000],'stride':16},
        '0xc29b94c':{'values':[0,1,2,3],'stride':8},
        '0xc29b99c':{'values':[0,16,32,48],'stride':32},
        '0xc29c170':{'values':[0x0101,0x0303,0x0505],'stride':64}})
    packed=bytearray(16)
    packed[1:6]=bytes((13,22,25,0,9));packed[6:11]=bytes((25,13,22,1,3))
    for offset in range(0,16,4):
        fields[hex(0xc29c0d8+offset)]=int.from_bytes(packed[offset:offset+4],'little')
    if version==3:
        # Independent groups reach the actual status +44 counter, the
        # per-player masks at R9+4/+8 and status's +413 list capacity.
        fields.update({
            '0xc29bccc':4,'0xc29b94c':3,
            '0xc29b99c':[48 if i<64 else 0 for i in range(256)],
            '0xc29b8fc':0,'0xc11e518':0x10000,
            '0xc29bcf0':[64 if 64<=i<128 else 0 for i in range(256)],
            '0xc29c174':[0xffffffff if 64<=i<128 else 0 for i in range(256)],
            '0xc29c178':[0xffffffff if 64<=i<128 else 0 for i in range(256)],
            '0xc29c0d4':5<<24,
            '0xc29c170':{'values':[0,0x0101,0x0303],'stride':4},
            '0xc400004':{'values':[0,1],'stride':1}})
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',
           directory/f'{name}_memory.json',directory/f'{name}_registers.json',
           ROOT/f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths),'refuse to overwrite followup inputs'
    paths[0].write_text((base/f'{NAME}_watch.txt').read_text())
    paths[1].write_text((base/f'{NAME}_owners.json').read_text())
    for path,value in zip(paths[2:4],(memory,registers)):
        path.write_text(json.dumps(value,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,
             bounded_arguments=True,preserve_fields=True,
             register_overrides=registers,memory_overrides=memory)


if __name__ == '__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--version',type=int,choices=(1,2,3),default=1)
    args=parser.parse_args()
    prepare() if args.version==1 else prepare_followup(args.version)
