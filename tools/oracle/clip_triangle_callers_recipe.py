"""Original literal-JSR caller inputs for the seven uncredited clip kernels."""
import json
from pathlib import Path
import sys
from pointer_seeds import fixture
from tenpp_probe_plan import override_sequence, override_value
ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from callable_clip_triangle import CALLERS, RESTORE


def relocate(value):
    return value+0x100000 if 0x0c400000 <= value < 0x0c480000 else value


def prepare():
    inputs = ROOT / 'tools/oracle/percentage_inputs'
    memory = json.loads((inputs/'coverage_65_batch_clip_dev_v1_memory.json').read_text())
    registers = json.loads((inputs/'coverage_65_batch_clip_dev_v1_registers.json').read_text())
    cases = []
    for entry, (_, load, restore) in CALLERS.items():
        seed_registers, seed_words = fixture(entry)
        for variant in (0, 1, 33, 37):
            words = {relocate(address): relocate(value) for address, value in seed_words.items()}
            regs = {f'r{reg}': relocate(value) for reg, value in seed_registers.items()}
            for address, values in memory[hex(entry)].items():
                words[relocate(int(address, 16))] = relocate(override_value(override_sequence(values, address), variant))
            for reg, values in registers[hex(entry)].items():
                value = override_value(override_sequence(values, reg), variant)
                regs[reg] = value if reg.startswith(('fr', 'xf')) else relocate(value)
            # The original delay instruction moves R0 into R4. R12 remains
            # the inherited writable stream cursor, without a PVR substitute.
            regs['r0'] = regs.pop('r4')
            regs.update(r15=0x0c590100, fpscr=0x240001)
            cases.append(dict(name=f'clip_{entry&0xffffff:06x}_{variant}',
                entry=hex(load&0x1fffffff), registers=regs,
                memory={hex(address): value for address, value in sorted(words.items())},
                expected_exit=hex((load+6)&0x1fffffff), budget=100000,
                transfer=hex((restore+2*(len(RESTORE)-2))&0x1fffffff),
                explicit_return_only=True))
    path = ROOT/'tools/oracle/coverage_65_clip_triangle_original_callers_v1.json'
    assert not path.exists(), 'refuse to overwrite caller evidence inputs'
    path.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', fixture_scope='Untouched original literal load, JSR and delay-slot selector; inherited typed RAM strip, scalar attributes and output stream',
        cases=cases), indent=2)+'\n')


if __name__ == '__main__': prepare()
