"""Typed original scene-table caller windows for clock/history owners."""
import json
from pathlib import Path
from pointer_seeds import fixture
from tenpp_probe_plan import override_sequence, override_value

ROOT = Path(__file__).resolve().parents[2]


def relocate(value):
    return value+0x100000 if 0x0c400000 <= value < 0x0c480000 else value


def prepare():
    inputs = ROOT/'tools/oracle/percentage_inputs'
    memory = json.loads((inputs/'coverage_65_complete_batch_dev_v2_memory.json').read_text())
    registers = json.loads((inputs/'coverage_65_complete_batch_dev_v2_registers.json').read_text())
    for tag, entry, index, variants in (
        ('round_clock', 0x8c098b3c, 53, (24, 25, 48, 72)),
        ('scene_history', 0x8c099194, 56, (0, 2, 6, 18))):
        seed_registers, seed_words = fixture(entry); cases = []
        for variant in variants:
            words = {relocate(a): relocate(v) for a, v in seed_words.items()}
            regs = {f'r{r}': relocate(v) for r, v in seed_registers.items()}
            for address, values in memory[hex(entry)].items():
                words[relocate(int(address, 16))] = relocate(override_value(override_sequence(values, address), variant))
            for reg, values in registers[hex(entry)].items():
                value = override_value(override_sequence(values, reg), variant)
                regs[reg] = value if reg.startswith(('fr', 'xf')) else relocate(value)
            # Original dispatcher reads byte 10 and loads its immutable table.
            words[0x0c29b86c] = (words.get(0x0c29b86c, 0)&~0x00ff0000)|(index<<16)
            regs.update(r15=0x0c590100, fpscr=0x240001)
            if tag == 'round_clock':
                # Active, nonretiring task flags and positive clock boundaries.
                # These are input flags; actor pointers and all remaining
                # loaded actor data retain the original state context.
                words[0x0c1fefe4] = 3; words[0x0c20138c] = 3
            cases.append(dict(name=f'{tag}_dispatch_{variant}', entry='0x0c0968d0',
                registers=regs, memory={hex(a): v for a, v in sorted(words.items())},
                budget=100000, expected_exit='0x0c0432e4', transfer='0x0c09803c',
                explicit_return_only=True))
        path = ROOT/f'tools/oracle/coverage_65_{tag}_original_scene_callers_v1.json'
        assert not path.exists(), 'refuse to overwrite caller evidence inputs'
        path.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
            trigger='0x8c0432e2', fixture_scope='Original primary scene index, immutable table load and tail jump; typed flags/boundaries and relocated descriptors, with original loaded actor data retained apart from explicit clock task flags',
            cases=cases), indent=2)+'\n')


if __name__ == '__main__': prepare()
