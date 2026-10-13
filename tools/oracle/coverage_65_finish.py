"""Run the frozen final coverage campaign, with explicit proof-gated stages."""
import argparse
import json
from pathlib import Path
import subprocess
import sys
from regression_status import summarize

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('D:/vf3-captures')
RAM=CACHE/'coverage_65_small_ram_dev_v1'
ACTOR=CACHE/'coverage_65_actor_tables_expanded_dev_v1'
NATIVE=RAM/'vf3matrixfamily_v2.exe'
OBSERVER=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence/flycast_task_return_boundary_v1.exe')
GROUPS=(dict(name='actor_tables_expanded',dev=ACTOR,owners=ACTOR/'coverage_65_actor_tables_expanded_dev_v1_owners.json',
    callables=ROOT/'tools/oracle/actor_tables_expanded_callable_v1.json',report='actor_tables_expanded_dev_v3_native.json',
    count=18,gain=4164,variants=128,port='src/fight/actor_table_literal.c'),
    dict(name='small_ram',dev=RAM,owners=RAM/'owners.json',callables=ROOT/'tools/oracle/small_ram_callable_v1.json',
    report='small_ram_dev_v3_native.json',count=4,gain=556,variants=256,port='src/fight/small_ram_callbacks.c'))

def run(script,*args):
    command=[sys.executable,str(ROOT/script),*(str(v) for v in args)]
    print('Running '+script,flush=True)
    subprocess.run(command,cwd=ROOT,check=True)

def common(group):
    return ['--development',group['dev']/'export','--development-report',ROOT/'extract/analysis'/group['report'],
        '--source-freeze',RAM/'compiled_sources/manifest.json','--owners',group['owners'],'--callables',group['callables'],
        '--full-regression',RAM/'full_regression.log','--bindings',RAM/'baseline_bindings.json',
        '--tool-tests',RAM/'tool_tests_v2.log','--expected-owners',group['count'],'--expected-gain',group['gain'],
        '--negative-controls',group['dev']/'caller_negative_controls.json']

def development():
    status=summarize((RAM/'full_regression.log').read_text(encoding='utf-8-sig'),
                     json.loads((RAM/'baseline_bindings.json').read_text()))
    assert status['passed'],'complete full regression required before development qualification'
    for g in GROUPS:run('tools/oracle/actor_tables_qualification.py',*common(g),'--out',g['dev']/'qualified_development.json')

def acceptance():
    for g in GROUPS:
        name=f'coverage_65_{g["name"]}_accept_v1';held=CACHE/name
        frozen=g['dev']/'qualified_development.json'
        if g['name']=='small_ram':
            run('tools/oracle/coverage_65_small_ram_inputs.py','--out',held,'--variants',g['variants'],'--development-freeze',frozen)
            watch,patch,inputs=held/'watch.txt',held/'entry.patch',held/'inputs.json'
        else:
            run('tools/oracle/actor_table_inputs.py','--extra','--name',name,'--out',held,
                '--variants',g['variants'],'--development-freeze',frozen)
            watch,patch,inputs=held/f'{name}_watch.txt',held/f'{name}.patch',held/f'{name}_inputs.json'
        run('tools/golden_batch.py','--name',name,'--watch',watch,'--entry-patch',patch,'--trace-dir',held,
            '--out',held/'export','--emulator',OBSERVER,'--capsule','--probe-only','--probe-debug','--probe-ops',100000,
            '--max-samples',g['variants'],'--timeout',220,
            '--run','s45:tools/emu/flycast-build/data/vf3_45.state::4000',
            '--run','s46:tools/emu/flycast-build/data/vf3_46.state::4000')
        report=ROOT/f'extract/analysis/{g["name"]}_accept_v1_native.json'
        run('tools/oracle/verify_matrix.py',held/'export','--out',report,'--jobs',4,'--executable',NATIVE)
        run('tools/oracle/actor_tables_qualification.py',*common(g),'--acceptance',held/'export',
            '--acceptance-report',report,'--development-freeze',frozen,'--holdout-inputs',inputs,
            '--out',ROOT/f'tools/oracle/{g["name"]}_qualification_v1.json')

def promote():
    # Both proofs must be complete before either ledger change is attempted.
    for g in GROUPS:
        proof=json.loads((ROOT/f'tools/oracle/{g["name"]}_qualification_v1.json').read_text())
        assert proof['ready_for_promotion'] and proof['marginal_candidate_bytes']==g['gain']
    for g in GROUPS:
        held=CACHE/f'coverage_65_{g["name"]}_accept_v1'
        run('tools/oracle/promote_tenpp_batch.py','--baseline','tools/oracle/replay_transition_coverage_baseline_v1.json',
            '--development',g['dev']/'export','--development-report',ROOT/'extract/analysis'/g['report'],
            '--acceptance',held/'export','--acceptance-report',ROOT/f'extract/analysis/{g["name"]}_accept_v1_native.json',
            '--manifest',ROOT/f'tools/oracle/{g["name"]}_v1_manifest.json','--port',g['port'],
            '--label',f'vf3_{g["name"]}_v1','--note','Immutable 409-input normal C build; full baseline regression; '
            'original callers; independently whole in each development and holdout state; zero strict replay skips.',
            '--evidence-root',CACHE,'--callable-map',g['callables'])
    run('tools/decomp_stats.py')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('stage',choices=('development','acceptance','promote'))
    a=p.parse_args();globals()[a.stage]()
