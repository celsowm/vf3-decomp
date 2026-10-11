"""Close the resident character/stage menu's remaining typed input paths.

The original stage lookup uses bytes, not DWORD rows. Bounded adjacent
selectors remain RAM input cases, while actual ROM tables stay untouched.
Equal alternate characters, secondary buttons and player swapping are
independent dimensions. The reset-settings owner is deliberately excluded:
its original reset helper zeroes option 14 before the allegedly missing test.
"""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
OWNERS = {0x8c09b36c: 0x8c09b37e}


def prepare():
    name = 'coverage_65_batch_resident_dev_v2'
    directory = ROOT / 'tools/oracle/percentage_inputs'
    original = json.loads((directory / 'coverage_65_batch_resident_dev_v1_memory.json').read_text())
    old_regs = json.loads((directory / 'coverage_65_batch_resident_dev_v1_registers.json').read_text())
    key = '0x8c09b36c'
    fields = dict(original[key])
    count = 256
    fields['0xc29bcc0'] = 0
    fields['0xc29ba54'] = [i // 8 % 4 for i in range(count)]
    fields['0xc29ba58'] = [[0, 5, 6, 7, 8, 9][i // 32 % 6] for i in range(count)]
    fields['0xc29ba5c'] = [i // 128 % 2 for i in range(count)]
    fields['0xc29ba6c'] = 5
    fields['0xc29ba60'] = 22
    fields['0xc29ba64'] = 22
    fields['0xc29bccc'] = [0 if i // 64 % 2 else 0x10000000 for i in range(count)]
    fields['0xc2cf844'] = [[0, 8, 0x400, 0x408][i // 32 % 4] for i in range(count)]
    fields['0xc29b870'] = 0
    fields['0xc29ba68'] = 0
    fields['0xc110594'] = 357  # Original song-kit pair for stage 0 request 1.
    memory, registers = {key: fields}, {key: old_regs[key]}
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    watch.write_text('pc 0x8c09b36c\n')
    (ROOT / f'tools/oracle/{name}_owners.json').write_text(
        json.dumps({hex(entry): hex(owner) for entry, owner in OWNERS.items()}, indent=2) + '\n')
    for suffix, value in [('memory', memory), ('registers', registers)]:
        (directory / f'{name}_{suffix}.json').write_text(json.dumps(value, indent=2) + '\n')
    generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, count,
             fpscr=0x40001, bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
