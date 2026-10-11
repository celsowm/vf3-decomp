"""Regenerate history-record probes from the explicit frozen typed vectors."""
import json
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
def prepare():
    for held,label in [(False,'dev'),(True,'accept')]:
        memory=json.loads((ROOT/f'tools/oracle/percentage_inputs/coverage_65_history_record_{label}_v1_memory.json').read_text())
        registers=json.loads((ROOT/f'tools/oracle/percentage_inputs/coverage_65_history_record_{label}_v1_registers.json').read_text())
        generate(ROOT/'tools/oracle/coverage_65_history_record_watch_v1.txt',
            ROOT/f'extract/analysis/coverage_65_history_record_{label}_v1.patch',0x8c0432e2,64,
            relocation=0x100000 if held else 0,fpscr=0x240001 if held else 0x40001,
            bounded_arguments=True,preserve_fields=True,holdout_inputs=held,
            memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
