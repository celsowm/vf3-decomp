"""Prepare disjoint original-image inputs for the selected-port getter."""
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]
ENTRY = '0x8c09b006'


def prepare():
    watch = ROOT / 'tools/oracle/coverage_65_controller_port_watch_v1.txt'
    for holdout, label in [(False, 'dev'), (True, 'accept')]:
        values = [0xfffffffe, 0, 1, 0xffffffff]
        if holdout:
            values = [0x80000000, 0xfffffffe, 2, 0xfffffffd]
        memory = {ENTRY: {
            '0x0c2cf834': [values[(i//2) % 4] for i in range(64)],
            '0x0c2cf848': [values[(i//2+1) % 4] for i in range(64)],
            '0x0c2cf83c': [(0xa55a1234 if holdout else 0x13579bdf) ^ (i*0x1020305) for i in range(64)],
            '0x0c2cf850': [(0x5aa5fedc if holdout else 0x2468ace0) ^ (i*0x314159) for i in range(64)],
        }}
        registers = {ENTRY: {'r4': [i % 2 for i in range(64)]}}
        name = f'coverage_65_controller_port_{label}_v1'
        for kind, data in [('memory', memory), ('registers', registers)]:
            path = ROOT / f'tools/oracle/percentage_inputs/{name}_{kind}.json'
            path.write_text(json.dumps(data, indent=2)+'\n')
        generate(watch, ROOT / f'extract/analysis/{name}.patch', 0x8c0432e2, 64,
                 relocation=0x100000 if holdout else 0,
                 fpscr=0x240001 if holdout else 0x40001,
                 bounded_arguments=True, preserve_fields=True, holdout_inputs=holdout,
                 register_overrides=registers, memory_overrides=memory)


if __name__ == '__main__':
    prepare()
