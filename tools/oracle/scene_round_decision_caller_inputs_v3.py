"""Use four complete round caller frames; keep IRQ-invalid mode-one probes."""
import copy
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def main():
    recipe=json.loads((ROOT/'tools/oracle/scene_round_decision_original_dispatch_v2.json').read_text())
    # The fourth frame still varies every saved GPR, but uses the shorter
    # original mode-three callback path instead of the IRQ-invalid mode-one
    # window. Whole-owner development retains the mode-one branch specimens.
    recipe['cases'][3]['memory']=copy.deepcopy(recipe['cases'][2]['memory'])
    recipe['cases'][3]['name']='round_scene54_alternate_saved_frame'
    recipe['fixture_scope']+=' Fourth saved frame uses original mode-three inputs; rejected mode-one caller specimens remain in v1/v2.'
    out=ROOT/'tools/oracle/scene_round_decision_original_dispatch_v3.json';assert not out.exists()
    out.write_text(json.dumps(recipe,indent=2)+'\n')


if __name__=='__main__':main()
