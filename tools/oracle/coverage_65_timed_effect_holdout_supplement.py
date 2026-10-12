"""Original one-shot inputs for the missed first boundary in holdout v2.

Keep the v17 C freeze unchanged. Cross positive actor X, bounded Z, clear
boundary flags and an active task clock explicitly, rather than correlating
all dimensions through one shifted phase. This prepares inputs, not outputs.
"""
import hashlib
import json
from pathlib import Path
import struct
from pointer_seeds import fixture
from tenpp_probe_plan import override_sequence, override_value

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
NAME = 'coverage_65_timed_effect_holdout_supplement_v1'


def relocated(value):
    return value+0x200000 if 0x0c400000 <= value < 0x0c480000 else value


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    entry = 0x8c08acc0
    prefix = ROOT/'tools/oracle/percentage_inputs/coverage_65_complete_batch_accept_v2'
    memory = json.loads(Path(str(prefix)+'_memory.json').read_text())[hex(entry)]
    registers = json.loads(Path(str(prefix)+'_registers.json').read_text())[hex(entry)]
    seed_regs, seed_words = fixture(entry)
    cases = []
    for variant in range(8):
        words = {relocated(a): relocated(v) for a, v in seed_words.items()}
        regs = {f'r{reg}': relocated(seed_regs.get(reg, (variant+13*reg+256)&(7 if reg<8 else 511))) for reg in range(15)}
        for address, value in memory.items():
            words[relocated(int(address,16))] = relocated(override_value(override_sequence(value,address), variant))
        for reg, value in registers.items():
            regs[reg] = relocated(override_value(override_sequence(value,reg), variant))
        # Task +18 is the signed boundary clock; +16 is the lifetime counter.
        words[relocated(0xc400010)] = (variant*17)|((variant*31)<<16)
        words[0xc29bcc0] = 0; words[0xc29b868] = 0
        words[0xc29bccc] = 0
        for actor in (0xc1fefe4, 0xc20138c):
            words[actor+0x430] = bits(1024+variant*13)
            words[actor+0x438] = bits(variant/16)
            words[(actor+0x2265)&~3] = (variant%2)*0x200
        regs.update(r15=0xc690100, fpscr=0x240001)
        cases.append(dict(name=f'positive_x_clear_boundary_{variant}',
            entry='0x0c08acc0', registers=regs,
            memory={hex(a): v for a,v in sorted(words.items())},
            budget=100000, expected_exit='0x0c0432e4', transfer='0x0c08af4c',
            explicit_return_only=True, trigger_ordinal=16))
    out = ROOT/f'tools/oracle/{NAME}.json'
    assert not out.exists(), 'refuse to overwrite supplemental input evidence'
    freeze = CACHE/'ram_clipping_batch_qualified_development_freeze_v2.json'
    with freeze.open('rb') as stream:
        frozen_hash = hashlib.file_digest(stream,'sha256').hexdigest()
    out.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', cases=cases,
        development_freeze=dict(path=str(freeze),sha256=frozen_hash),
        fixture_scope='Supplement first-boundary execution in both held states; original pools/helpers and v17 C are unchanged; prior partial specimens remain retained'),indent=2)+'\n')


if __name__ == '__main__':
    prepare()
