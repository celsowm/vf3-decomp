"""Prepare three selection input groups after the complete development freeze."""
import json
from pathlib import Path
from ram_clipping_batch_audit import digest, reference
from tenpp_probe_plan import generate, override_sequence, override_value

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
ENTRY = '0x8c0c3210'


def relocated(value):
    return value+0x200000 if 0x0c400000 <= value < 0x0c480000 else value


def prepare():
    frozen = CACHE/'selection_unlock_qualified_development_freeze_v1.json'
    proof = json.loads(frozen.read_text())
    assert proof['qualified_development_only'] and proof['archived_inputs'] == 401
    for ref in proof['references']:
        assert digest(ref['path']) == ref['sha256'], 'changed complete development evidence'
    base = ROOT/'tools/oracle'
    inputs = base/'percentage_inputs'
    all_paths = []
    for version in (1,2,3):
        prior = f'coverage_65_selection_unlock_screen_v{version}'
        name = f'coverage_65_selection_unlock_accept_v{version}'
        fields = json.loads((inputs/f'{prior}_memory.json').read_text())[ENTRY]
        regs = json.loads((inputs/f'{prior}_registers.json').read_text())[ENTRY]
        memory = {}
        for address, values in fields.items():
            sequence = override_sequence(values, address)
            sampled = [relocated(override_value(sequence, (variant+37)%256)) for variant in range(256)]
            if int(address,16) == 0x0c29bcf0:
                sampled = [value+7 if value else value for value in sampled]
            memory[hex(relocated(int(address,16)))] = sampled
        registers = {reg: [relocated(override_value(override_sequence(values,reg), (variant+37)%256))
                           for variant in range(256)] for reg, values in regs.items()}
        paths = [base/f'{name}_watch.txt', base/f'{name}_owners.json',
                 inputs/f'{name}_memory.json', inputs/f'{name}_registers.json',
                 ROOT/f'extract/analysis/{name}.patch']
        assert not any(p.exists() for p in paths), 'refuse to overwrite held inputs'
        paths[0].write_text('pc '+ENTRY+'\n')
        paths[1].write_text(json.dumps({ENTRY:'0x8c0c321e'},indent=2)+'\n')
        for path, data in zip(paths[2:4], ({ENTRY:memory}, {ENTRY:registers})):
            path.write_text(json.dumps(data,indent=2)+'\n')
        generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,
                 bounded_arguments=True,preserve_fields=True,
                 register_overrides={ENTRY:registers},memory_overrides={ENTRY:memory})
        all_paths += paths
    manifest = base/'coverage_65_selection_unlock_accept_input_manifest_v1.json'
    assert not manifest.exists()
    manifest.write_text(json.dumps(dict(coverage_credit=False, development_freeze=reference(frozen),
        original_states=[reference(ROOT/f'tools/emu/flycast-build/data/vf3_{index}.state') for index in (45,46)],
        files=[reference(p) for p in all_paths],
        hypothesis='Independent original states; disjoint descriptor buffers, permuted input groups and changed positive timers. Original code and literal pools remain unchanged.'),indent=2)+'\n')


if __name__ == '__main__':
    prepare()
