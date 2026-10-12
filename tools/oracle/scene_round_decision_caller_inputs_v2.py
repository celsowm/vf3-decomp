"""Recapture the original round caller after one IRQ-invalid first window."""
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def main():
    prior=ROOT/'tools/oracle/scene_round_decision_original_dispatch_v1.json'
    recipe=json.loads(prior.read_text())
    for case in recipe['cases']:
        case['trigger_ordinal']=2
    recipe['fixture_scope']+=' Second natural trigger avoids the first-window pending interrupt; no instruction, callback result or table change.'
    out=ROOT/'tools/oracle/scene_round_decision_original_dispatch_v2.json';assert not out.exists()
    out.write_text(json.dumps(recipe,indent=2)+'\n')


if __name__=='__main__':main()
