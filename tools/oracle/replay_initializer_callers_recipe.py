"""Original descriptor JSR inputs for initializer direct and history tails."""
import json
from pathlib import Path
from pointer_seeds import fixture
from tenpp_probe_plan import override_sequence, override_value
ROOT = Path(__file__).resolve().parents[2]


def relocate(value):
    return value+0x100000 if 0x0c400000 <= value < 0x0c480000 else value


def prepare():
    inputs = ROOT/'tools/oracle/percentage_inputs'; entry = '0x8c0a8370'
    memory = json.loads((inputs/'coverage_65_complete_batch_dev_v2_memory.json').read_text())[entry]
    registers = json.loads((inputs/'coverage_65_complete_batch_dev_v2_registers.json').read_text())[entry]
    seed_registers, seed_words = fixture(int(entry, 16)); cases = []
    for variant in (0, 1, 16, 17):
        words = {relocate(a): relocate(v) for a, v in seed_words.items()}
        regs = {f'r{r}': relocate(v) for r, v in seed_registers.items()}
        for address, values in memory.items():
            words[relocate(int(address, 16))] = relocate(override_value(override_sequence(values, address), variant))
        for reg, values in registers.items():
            regs[reg] = relocate(override_value(override_sequence(values, reg), variant))
        descriptor = regs.pop('r4'); words[descriptor] = words.get(descriptor, 0)|1
        # Untouched installer pool establishes this input callback. The
        # original initializer replaces it with the original history callback.
        words[descriptor+12] = 0x0c0a8370
        regs.update(r14=descriptor, r15=0x0c590100, fpscr=0x240001, sr=0x600000f0)
        mode = words[0x0c29ba30]
        cases.append(dict(name=f'initializer_dispatch_{variant}', entry='0x0c09617c',
            registers=regs, memory={hex(a): v for a, v in sorted(words.items())},
            expected_exit='0x0c096188', budget=100000,
            transfer='0x0c0a842a' if mode else '0x0c0a83be', explicit_return_only=True))
    path = ROOT/'tools/oracle/coverage_65_replay_initializer_original_callers_v1.json'
    assert not path.exists(), 'refuse to overwrite caller evidence inputs'
    path.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', fixture_scope='Original descriptor predicate, callback load and JSR argument; callback equals the untouched initializer installer pool. Explicit IMASK=15 CPU input scopes evidence to synchronous calls, preserving both direct and full history-tail paths.',
        cases=cases), indent=2)+'\n')


if __name__ == '__main__': prepare()
