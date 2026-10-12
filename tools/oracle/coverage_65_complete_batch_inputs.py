"""Prepare the complete RAM/clipping development batch from retained inputs.

This combines the successful typed input hypotheses without dropping failure
specimens. Capture, whole-owner, caller and native gates remain separate.
"""
import json
import argparse
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
NAME = 'coverage_65_complete_batch_dev_v1'
SOURCES = {
    'coverage_65_batch_screen_dev_v2': {
        0x8c0a8370: 0x8c0a8370, 0x8c0a8f8c: 0x8c0a8f98,
        0x8c087e04: 0x8c087e1c},
    'coverage_65_batch_boundary_dev_v1': {0x8c08f632: 0x8c08f642},
    'coverage_65_selection_boundary_dev_v1': {0x8c098b3c: 0x8c098b40},
    'coverage_65_batch_resident_dev_v1': {
        0x8c099194: 0x8c0991a2, 0x8c08acc0: 0x8c08acd8},
    'coverage_65_batch_clip_dev_v1': {
        0x8c05152c: 0x8c05156a, 0x8c051918: 0x8c051956,
        0x8c051c2c: 0x8c051c6a, 0x8c051f50: 0x8c051f8e,
        0x8c05228c: 0x8c0522ca, 0x8c0525c0: 0x8c0525fe,
        0x8c05291c: 0x8c05295a, 0x8c052c34: 0x8c052c72},
}


def prepare(name=NAME):
    inputs = ROOT / 'tools/oracle/percentage_inputs'
    memory, registers, owners = {}, {}, {}
    for source, entries in SOURCES.items():
        old_memory = json.loads((inputs / f'{source}_memory.json').read_text())
        old_registers = json.loads((inputs / f'{source}_registers.json').read_text())
        for entry, owner in entries.items():
            key = hex(entry)
            memory[key], registers[key] = old_memory[key], old_registers[key]
            owners[key] = hex(owner)
    assert name.startswith('coverage_65_complete_batch_dev_v') and name.rsplit('_v', 1)[1].isdigit(), 'invalid development evidence name'
    watch = ROOT / f'tools/oracle/{name}_watch.txt'
    paths = [watch, ROOT / f'tools/oracle/{name}_owners.json']
    paths += [inputs / f'{name}_{suffix}.json' for suffix in ('memory', 'registers')]
    patch = ROOT / f'extract/analysis/{name}.patch'
    assert not any(path.exists() for path in [*paths, patch]), 'refuse to overwrite evidence'
    watch.write_text(''.join(f'pc {entry}\n' for entry in owners))
    for path, value in zip(paths[1:], (owners, memory, registers)):
        path.write_text(json.dumps(value, indent=2) + '\n')
    generate(watch, patch, 0x8c0432e2, 384, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True,
             register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--name', default=NAME)
    prepare(parser.parse_args().name)
