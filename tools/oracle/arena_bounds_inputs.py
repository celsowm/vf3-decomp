"""Combine independently piloted arena and radial correction input domains."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]

def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        inputs={}
        for kind in ['memory','registers']:
            combined={}
            for name in ['ring_bound','radial_bound']:
                part=json.loads((ROOT/f'tools/oracle/percentage_inputs/coverage_65_{name}_{label}_v1_{kind}.json').read_text())
                assert not combined.keys() & part.keys()
                combined.update(part)
            inputs[kind]=combined
            (ROOT/f'tools/oracle/percentage_inputs/coverage_65_arena_bounds_{label}_v1_{kind}.json').write_text(json.dumps(combined,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_arena_bounds_watch_v1.txt',ROOT/f'extract/analysis/coverage_65_arena_bounds_{label}_v1.patch',0x8c0432e2,64,
            relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
            memory_overrides=inputs['memory'],register_overrides=inputs['registers'])
if __name__=='__main__':prepare()
