"""Additional original RAM candidates for the one-session 65% work pool.

These are screening inputs, not expected results or accepted C coverage.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {
    0x8c09c1de: 0x8c09c1f4,
    0x8c0c3210: 0x8c0c321e,
    0x8c0c2f3c: 0x8c0c2f4e,
    0x8c098b3c: 0x8c098b40,
    0x8c08984c: 0x8c089864,
    0x8c0996f4: 0x8c09970a,
    0x8c09b040: 0x8c09b04e,
}


def prepare():
    name = 'coverage_65_batch_expand_dev_v1'
    prior = ROOT / 'tools/oracle/percentage_inputs/coverage_65_batch_screen_dev_v1_memory.json'
    base = json.loads(prior.read_text())['0x8c0a8370']
    memory, registers = {}, {}
    for entry in OWNERS:
        fields = dict(base)
        fields.update({
            '0xc29b864': [0, 0x100, 0x200, 0],
            '0xc29bcc0': {'values': [0, 1, 0x80001, 0], 'stride': 16},
            '0xc29bccc': {'values': [0, 4, 0x80000000, 0x40000000], 'stride': 4},
            '0xc2cf834': [0, 0xfffffffe], '0xc2cf848': [0, 0xfffffffe],
            '0xc2cf83c': [0, 4, 8, 16, 32, 64, 128, 0x200, 0x400, 0x100],
            '0xc2cf850': [0, 4, 8, 16, 32, 64, 128, 0x200, 0x400, 0x100],
            '0xc29ba98': {'values': [0, 1, 8, 0x10], 'stride': 4},
            '0xc29ba9c': {'values': [0, 1, 8, 0x10], 'stride': 4},
            '0xc29baa0': {'values': [0, 1, 8, 9], 'stride': 8},
            '0xc29baa4': {'values': [0, 1, 8, 9], 'stride': 8},
            '0xc400000': [0, 2, 8, 0], '0xc400004': [0, 1],
            '0xc400030': [0, 0x100, 0x200, 0x300],
            '0xc400034': [0, 1, 2, 0x100],
        })
        if entry in (0x8c0c3210, 0x8c0c2f3c):
            fields['0xc29b864'] = {'values': [0, 0x100, 0x200], 'stride': 16}
        if entry == 0x8c08984c:
            fields['0xc400010'] = [0, 0x3f800000, 0x40000000]
            fields['0xc400014'] = [0, 1, 127, 128]
            fields['0xc29bba4'] = 0xc470000
            fields['0xc470450'] = [0, 2]
            for i in range(32):
                fields[hex(0xc400018 + 40*i)] = [0, 1, 126, 127]
                fields[hex(0xc400020 + 40*i)] = [0, 1, 0xffff, 0x4000]
                fields[hex(0xc400020 + 40*i + 4)] = [0, 0x01000000]
                for offset in (12, 16, 20):
                    fields[hex(0xc400018 + 40*i + offset)] = [0, 0x3f800000, 0xbf800000]
        memory[hex(entry)] = fields
        registers[hex(entry)] = {'r4': 0xc400000}
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text(''.join(f'pc {entry:#x}\n' for entry in OWNERS))
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (ROOT / f'tools/oracle/percentage_inputs/{name}_{suffix}.json').write_text(
            json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, 64,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
