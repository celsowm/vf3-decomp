"""Disjoint typed holdout inputs prepared only after the complete C freeze."""
import hashlib
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
NAME = 'coverage_65_complete_batch_accept_v1'


def changed(value):
    if isinstance(value, dict):
        result = dict(value)
        result['phase'] = result.get('phase', 0)+1
        return result
    if isinstance(value, list):
        return value[1:]+value[:1]
    return value


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    freeze = CACHE/'ram_clipping_batch_qualified_development_freeze_v1.json'
    proof = json.loads(freeze.read_text())
    assert proof['qualified_development_only'] and proof['compiled_inputs'] == 398
    for row in proof['references']:
        path = Path(row['path'])
        assert hashlib.file_digest(path.open('rb'), 'sha256').hexdigest() == row['sha256'], path
    inputs = ROOT/'tools/oracle/percentage_inputs'
    memory, registers = [], []
    for kind, target in (('memory', memory), ('registers', registers)):
        old = json.loads((inputs/f'coverage_65_complete_batch_dev_v2_{kind}.json').read_text())
        target.append({entry: {field: changed(value) for field, value in fields.items()}
                       for entry, fields in old.items()})
    memory, registers = memory[0], registers[0]
    # Change finite attribute values and the normalization scale in the SDK
    # family, while retaining the original layout and selector domains.
    for entry in memory:
        if int(entry, 16) in range(0x8c05152c, 0x8c052c35):
            for index in range(16):
                memory[entry][hex(0x0c440000+8*index)] = bits((index+2)/32)
                memory[entry][hex(0x0c440004+8*index)] = bits(0.75)
            registers[entry]['fr3'] = bits(1/512)
    owners = ROOT/'tools/oracle/coverage_65_complete_batch_dev_v2_owners.json'
    watch = ROOT/f'tools/oracle/{NAME}_watch.txt'
    owner_out = ROOT/f'tools/oracle/{NAME}_owners.json'
    paths = [watch, owner_out, *(inputs/f'{NAME}_{kind}.json' for kind in ('memory', 'registers'))]
    patch = ROOT/f'extract/analysis/{NAME}.patch'
    manifest = ROOT/f'tools/oracle/{NAME}_input_manifest.json'
    assert not any(path.exists() for path in [*paths, patch, manifest]), 'refuse to overwrite holdout evidence'
    watch.write_text((ROOT/'tools/oracle/coverage_65_complete_batch_dev_v2_watch.txt').read_text())
    owner_out.write_text(owners.read_text())
    for path, value in zip(paths[2:], (memory, registers)):
        path.write_text(json.dumps(value, indent=2)+'\n')
    generate(watch, patch, 0x8c0432e2, 384, relocation=0x100000,
             fpscr=0x240001, bounded_arguments=True, holdout_inputs=True,
             preserve_fields=True, register_overrides=registers, memory_overrides=memory)
    manifest.write_text(json.dumps(dict(coverage_credit=False, purpose='Holdout input preparation; capture and qualification remain required',
        development_freeze={'path': str(freeze), 'sha256': hashlib.file_digest(freeze.open('rb'), 'sha256').hexdigest()},
        intended_states=['vf3_28.state', 'vf3_29.state'], relocation='0x100000',
        changes='Rotate typed selector/boundary sequences, shift strided dimensions, change clip attributes/normalization, relocate owned objects and change FPSCR bank and preserved-register inputs',
        files=[{'path': str(path.resolve()), 'sha256': hashlib.file_digest(path.open('rb'), 'sha256').hexdigest()} for path in [*paths, patch]]), indent=2)+'\n')


if __name__ == '__main__': prepare()
