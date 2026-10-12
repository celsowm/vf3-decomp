"""Typed original replay-BSR and list literal-JSR caller windows."""
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
    for tag, entry, start, returned, rts in (
        ('replay_interpolate', 0x8c0a8f8c, 0x0c0a9062, 0x0c0a906a, 0x0c0a9032),
        ('list_interpolation', 0x8c08f632, 0x0c090b76, 0x0c090b7c, 0x0c08f8ba)):
        cases = []
        seed_registers, seed_words = fixture(entry)
        for variant in range(4):
            words = {relocate(address): relocate(value) for address, value in seed_words.items()}
            regs = {f'r{reg}': relocate(value) for reg, value in seed_registers.items()}
            for address, values in memory[hex(entry)].items():
                words[relocate(int(address, 16))] = relocate(override_value(override_sequence(values, address), variant))
            for reg, values in registers[hex(entry)].items():
                value = override_value(override_sequence(values, reg), variant)
                regs[reg] = value if reg.startswith(('fr', 'xf')) else relocate(value)
            regs['r13'] = regs.pop('r4')
            if tag == 'replay_interpolate':
                regs['r14'] = regs.pop('r5')
                words[0x0c590104] = 0
            regs.update(r15=0x0c590100, fpscr=0x240001)
            cases.append(dict(name=f'{tag}_{variant}', entry=hex(start),
                registers=regs, memory={hex(a): v for a, v in sorted(words.items())},
                budget=100000, expected_exit=hex(returned), transfer=hex(rts),
                explicit_return_only=True))
        path = ROOT/f'tools/oracle/coverage_65_{tag}_original_callers_v1.json'
        assert not path.exists(), 'refuse to overwrite original caller inputs'
        path.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
            trigger='0x8c0432e2', fixture_scope='Original caller argument setup and call instruction, with typed writable replay/list records relocated and actual loaded actors preserved',
            cases=cases), indent=2)+'\n')


if __name__ == '__main__': prepare()
