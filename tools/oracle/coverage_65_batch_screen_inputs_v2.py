"""Target missing branches from the excluded first original-image pilot.

Each change is a typed input hypothesis: independent controller dimensions,
bounded history indices, observed actors, and circular list topology. No
callback output, original instruction or immutable table is patched.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate
from coverage_65_batch_screen_inputs import OWNERS

ROOT = Path(__file__).resolve().parents[2]


def prepare():
    name = 'coverage_65_batch_screen_dev_v2'
    previous = ROOT / 'tools/oracle/percentage_inputs/coverage_65_batch_screen_dev_v1'
    memory = json.loads(Path(str(previous) + '_memory.json').read_text())
    registers = json.loads(Path(str(previous) + '_registers.json').read_text())
    count = 128
    controls = [0, 16, 32, 64, 128, 4, 2, 8]
    for key, fields in memory.items():
        entry = int(key, 16)
        fields['0xc2cf83c'] = [controls[i % 8] for i in range(count)]
        fields['0xc2cf844'] = [0 if i < 64 else (8 if i % 2 else 0x400)
                                for i in range(count)]
        fields['0xc29bcc0'] = [0 if i % 16 else 1 for i in range(count)]
        fields['0xc29ba54'] = [i // 8 % 4 for i in range(count)]
        fields['0xc29ba58'] = [i // 8 % 7 for i in range(count)]
        fields['0xc29ba5c'] = [i // 16 % 2 for i in range(count)]
        fields['0xc29ba6c'] = [i // 8 % 6 for i in range(count)]  # +0x208
        # Menu selectors are mode-base offsets, not scene-base offsets.
        fields['0xc29ba84'] = [i // 8 % 12 for i in range(count)]  # +0x220
        fields['0xc29ba80'] = [0, 1, 2, 3, 5, 160, 400, 401] * 16  # +0x21c
        fields['0xc29bb3c'] = [i // 8 % 4 for i in range(count)]  # +0x2d8
        fields['0xc29bb38'] = [0, 1, 30, 171, 219, 0, 1, 30] * 16
        for offset in (0x2dc, 0x2e0, 0x2e4):
            fields[hex(0xc29b864 + offset)] = [0, 1, 2, 0, 1, 2, 0, 1] * 16
        fields['0xc29b870'] = [0 if i // 8 % 2 == 0 else 1 for i in range(count)]
        fields['0xc29c068'] = [0, 1, 30, 239, 319, 0, 1, 30] * 16
        fields['0xc29c060'] = [0, 1, 30, 239, 319, 0, 1, 30] * 16
        for i, offset in enumerate((96, 100, 104, 108)):
            address = 0xc470000 + i * 0x1000
            fields[hex(0xc29bb84 + offset)] = address
            fields[hex(address)] = [0, 1, 3, 1] * 32
        if entry == 0x8c0a8f8c:
            fields['0xc200f9c'] = [0, 1, 2, 3, 1, 2, 3, 4] * 16
            fields['0xc404024'] = [1, 2, 1, 2, 3, 1, 2, 3] * 16
            fields['0xc404000'] = [0, 0x20000000] * 64
        if entry == 0x8c08acc0:
            # Word +18 is packed into the upper half of the aligned DWORD.
            fields['0xc400010'] = [v << 16 for v in
                ([0, 0x22e, 0x22f, 0x230, 0x705, 0x706, 0x707, 0x7ff] * 16)]
            fields['0xc29b868'] = [0 if i % 16 else 0xc0030000 for i in range(count)]
        if entry == 0x8c08f632:
            sentinel, free = 0xc4002a0, 0xc400234
            nodes = [0xc420000, 0xc42000c, 0xc420018, 0xc420024]
            fields[hex(sentinel)] = nodes[-1]
            fields[hex(sentinel + 4)] = nodes[0]
            fields[hex(free)] = free
            fields[hex(free + 4)] = free
            fields['0xc400330'] = [nodes[0], nodes[1], nodes[2], nodes[3]] * 32
            fields['0xc400334'] = nodes[1]
            fields['0xc400338'] = [0, 0x3f000000, 0x3f800000, 0x40000000] * 32
            fields['0xc40033c'] = [0, 0x3f000000, 0, 0x3f800000] * 32
            for i, node in enumerate(nodes):
                data = 0xc430000 + i * 32
                fields[hex(node)] = sentinel if i == 0 else nodes[i - 1]
                fields[hex(node + 4)] = sentinel if i == 3 else nodes[i + 1]
                fields[hex(node + 8)] = data
                fields[hex(data)] = [0, 0x3f800000, 0x40000000, 0x40400000][i]
                for offset in range(4, 32, 4):
                    fields[hex(data + offset)] = [0, 0x3f800000, 0xbf800000, 0x40000000][i]
            for offset in range(0x340, 0x378, 4):
                fields[hex(0xc400000 + offset)] = 0
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (ROOT / f'tools/oracle/percentage_inputs/{name}_{suffix}.json').write_text(
            json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
