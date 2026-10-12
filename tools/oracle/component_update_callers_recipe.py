"""Typed inputs for the original component-table update loader and JSR.

The table and callback targets are never patched. This prepares evidence;
only terminating original captures validated by the caller contract prove it.
"""
import json
from pathlib import Path
from pointer_seeds import fixture
from tenpp_probe_plan import override_sequence, override_value

ROOT = Path(__file__).resolve().parents[2]
NAME = 'coverage_65_component_update_original_callers_v1'


def relocate(value):
    return value+0x100000 if 0x0c400000 <= value < 0x0c480000 else value


def prepare():
    inputs = ROOT / 'tools/oracle/percentage_inputs'
    memory = json.loads((inputs / 'coverage_65_complete_batch_dev_v1_memory.json').read_text())
    registers = json.loads((inputs / 'coverage_65_complete_batch_dev_v1_registers.json').read_text())
    cases = []
    for entry, index, rts in ((0x8c08acc0, 2, 0x0c08af4c),
                              (0x8c087e04, 11, 0x0c088136)):
        key = hex(entry)
        seed_registers, seed_words = fixture(entry)
        for variant in range(4):
            words = {relocate(address): relocate(value) for address, value in seed_words.items()}
            regs = {f'r{reg}': relocate(value) for reg, value in seed_registers.items()}
            for address, values in memory[key].items():
                words[relocate(int(address, 16))] = relocate(override_value(override_sequence(values, address), variant))
            for reg, values in registers[key].items():
                value = override_value(override_sequence(values, reg), variant)
                regs[reg] = value if reg.startswith(('fr', 'xf')) else relocate(value)
            # Original mode-12 update: table base is loaded by the original
            # MOV.L, index is multiplied by 28, and JSR reads the table slot.
            regs.update(r8=0, r9=0x0c580000, r12=12, r13=0x0c500000,
                        r14=index+1, r15=0x0c590100, fpscr=0x240001)
            words[0x0c590104] = 0
            words[0x0c29bcc0] = (0, 0x80001, 0, 0)[variant]
            cases.append(dict(name=f'component_{index}_update_{variant}',
                entry='0x0c08b46e', registers=regs,
                memory={hex(address): value for address, value in sorted(words.items())},
                expected_exit='0x0c08b4b2', budget=100000,
                transfer=hex(rts), explicit_return_only=True))
    path = ROOT / f'tools/oracle/{NAME}.json'
    assert not path.exists(), 'refuse to overwrite caller evidence inputs'
    path.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', fixture_scope='Original component table index, mode-12 update callback load, JSR and delay-slot object argument; immutable rows 2 and 11',
        cases=cases), indent=2)+'\n')


if __name__ == '__main__': prepare()
