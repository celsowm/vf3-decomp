"""Narrow input hypotheses justified by the first two original pilots.

The list comparison is FR15 > FR14; the history index comes from descriptor
+16; menu bounds must be crossed with both directions. This pilot preserves
all previous failures and grants no coverage.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c09bc1c: 0x8c09bc2e, 0x8c08f632: 0x8c08f642,
          0x8c099194: 0x8c0991a2, 0x8c08acc0: 0x8c08acd8}


def prepare():
    name = 'coverage_65_batch_boundary_dev_v1'
    prefix = ROOT / 'tools/oracle/percentage_inputs/coverage_65_batch_screen_dev_v2'
    prior = json.loads(Path(str(prefix) + '_memory.json').read_text())
    old_registers = json.loads(Path(str(prefix) + '_registers.json').read_text())
    memory, registers = {}, {}
    count = 192
    for entry in OWNERS:
        key = hex(entry)
        fields = dict(prior[key])
        if entry == 0x8c09bc1c:
            limits = [5, 3, 3, 400, 400, 1, 2, 1, 0, 0, 0, 0]
            controls = [0, 16, 32, 64, 128, 4, 2, 8]
            fields['0xc29ba84'] = [i // 8 % 12 for i in range(count)]
            fields['0xc2cf83c'] = [controls[i % 8] for i in range(count)]
            fields['0xc29ba80'] = [
                (0 if i < 96 else limits[i // 8 % 12]) if i % 8 == 3
                else (limits[i // 8 % 12] if i < 96 else 0) if i % 8 == 4
                else [0, 1, 2, 3, 5, 160, 400, 401][i % 8]
                for i in range(count)]
            fields['0xc29bccc'] = 0
        elif entry == 0x8c08f632:
            fields['0xc400338'] = [0, 0x3f000000, 0x3f800000, 0x40000000] * 48
            fields['0xc40033c'] = [0x3f800000, 0x40000000, 0x40000000, 0] * 48
            nodes = [0xc420000, 0xc42000c, 0xc420018, 0xc420024]
            fields['0xc400330'] = [nodes[0], nodes[1]] * 96
            fields['0xc400334'] = [nodes[i // 4 % 4] for i in range(count)]
            for i in range(4):
                fields[hex(0xc430000 + 32*i)] = {
                    'values': [[0, 0x3f800000, 0x40000000, 0x40400000][i],
                               0, 0x3f800000], 'stride': 16}
        elif entry == 0x8c099194:
            fields['0xc468010'] = [0, 1, 319, 320] * 48
            fields['0xc29bcdc'] = [0, 2, 0x200, 0x202] * 48
            fields['0xc29bcec'] = {
                'values': [0x01000000, 0x01000300, 0x08000000, 0x09000000], 'stride': 8}
            fields['0xc29bccc'] = {'values': [0, 0x20000, 0x40000000, 0x40000004], 'stride': 4}
            fields['0xc29bb94'] = 0xc1fefe4
            fields['0xc29bb98'] = 0xc20138c
        elif entry == 0x8c08acc0:
            for actor in (0xc1fefe4, 0xc20138c):
                fields[hex(actor + 0x430)] = {'values': [0, 0x42c80000, 0xc2c80000], 'stride': 4}
                fields[hex(actor + 0x438)] = {'values': [0xc2c80000, 0, 0x42c80000], 'stride': 8}
                aligned = (actor + 0x2265) & ~3
                fields[hex(aligned)] = {'values': [0, 0x100, 0x200, 0x300], 'stride': 16}
        memory[key] = fields
        registers[key] = old_registers[key]
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (ROOT / f'tools/oracle/percentage_inputs/{name}_{suffix}.json').write_text(
            json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
