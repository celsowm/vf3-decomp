"""Test the reset scan with the original kernel SR and interrupt mask raised.

This is a new architectural input hypothesis, not an accepted caller context.
Code, callbacks and scan length remain original. No coverage is awarded.
"""
import argparse
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def prepare(output):
    output.mkdir(parents=True, exist_ok=True)
    watch, patch = output/'watch.txt', output/'entry.patch'
    if watch.exists() or patch.exists():
        raise FileExistsError('refusing to replace pilot')
    entry = '0x8c096afc'
    memory = json.loads((ROOT/'tools/oracle/percentage_inputs/coverage_65_scene_retire_dev_v2_memory.json').read_text())
    watch.write_text('pc '+entry+'\n')
    generate(watch, patch, 0x8c0432e2, 4, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True, memory_overrides=memory)
    lines = []
    for line in patch.read_text().splitlines():
        lines.append(line)
        if line.startswith('reg 0x8c0432e2 pr '):
            lines.append('reg 0x8c0432e2 sr 0x600000f0')
    patch.write_text('\n'.join(lines)+'\n')
    (output/'recipe.json').write_text(json.dumps(dict(coverage_credit=False,
        hypothesis='Interrupt masking lets the fixed 4096-entry scan reach its real return.',
        sr='0x600000f0', preserved_sr_mode='0x60000000', variants=4), indent=2)+'\n')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    prepare(parser.parse_args().out)
