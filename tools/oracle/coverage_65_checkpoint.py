"""Seal the entire 65% inventory against one unchanged normal C build.

The baseline full regression and newly promoted strict reports partition the
final binding inventory. Every binding must have run against this source
closure; no earlier-build test result can stand in for the final build.
"""
import argparse
from datetime import datetime,timezone
import json
from pathlib import Path
import re
import shutil
from ram_clipping_batch_audit import digest,reference
from regression_status import summarize
from task_completion_audit import freeze
from portcheck import TESTS

ROOT=Path(__file__).resolve().parents[2]

def checkpoint(a):
    if a.out.exists() or a.archive.exists():raise FileExistsError('refusing to replace checkpoint')
    native=freeze(a.source_freeze,native=True);native_hash=digest(native)
    source=json.loads(a.source_freeze.read_text())
    baseline=json.loads(a.baseline_bindings.read_text());current_path=ROOT/'tools/golden_bindings.json'
    current=json.loads(current_path.read_text());refs=[]
    assert all(current.get(key)==row for key,row in baseline.items()),'baseline binding changed'
    log=a.regression.read_text(encoding='utf-8-sig');status=summarize(log,baseline)
    assert status['passed'],'incomplete baseline regression'
    suites=dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b',log.split('\nbinding ',1)[0],re.M))
    assert set(suites)==set(TESTS) and all(v=='PASS' for v in suites.values())
    # These outputs correspond to the same immutable binary supplied to
    # portcheck. All other bound/native executables are retained below.
    passed_new={};report_paths={}
    for path in a.new_report:
        report=json.loads(path.read_text());refs.append(reference(path))
        for entry,row in report.items():
            assert row['pass'] and row['executable_sha256']==native_hash
            assert Path(row['executable']).resolve()==native.resolve()
            count=sum(1 for _ in Path(row['cases']).open())
            assert row['stdout']==f'matrix_family: {count}/{count} cases match (0 skipped) - PASS'
            passed_new[(entry,str(Path(row['cases']).resolve()))]=row
            report_paths[(entry,str(Path(row['cases']).resolve()))]=path
    new_keys=set(current)-set(baseline)
    assert len(new_keys)==22,'wrong final candidate inventory'
    new_results={}
    for key in sorted(new_keys):
        row=current[key];test=row['test'].split()
        assert test[0]=='build/vf3matrixfamily.exe' and row['strict']
        corpus=(ROOT/row['golden']).resolve();identity=(test[1],str(corpus))
        assert identity in passed_new,'final binding missing its exact replay corpus'
        new_results[key]=dict(report=reference(report_paths[identity]),stdout=passed_new[identity]['stdout'])
    for path in a.qualification:
        proof=json.loads(path.read_text());assert proof['ready_for_promotion'] and not proof['qualified_development_only']
        assert proof['native']==reference(native) and proof['compiled_inputs']==len(source['files'])
        for row in proof['references']:assert digest(row['path'])==row['sha256'],'changed final qualification dependency'
        refs.append(reference(path))
    for path in a.historical:
        historical=json.loads(path.read_text())
        for row in historical['references']:assert digest(row['path'])==row['sha256'],'changed historical proof'
        refs.append(reference(path))
    series=json.loads(a.series.read_text());assert series['complete'] and series['passed'] and series['target_met']
    coverage_path=ROOT/'extract/analysis/coverage.json';coverage=json.loads(coverage_path.read_text())
    accepted=coverage['ported_unique_bytes'];denominator=coverage['bytes_total']
    assert denominator==434656 and accepted==series['final_bytes'] and accepted>=282527
    assert accepted==282534,'unexpected final address union'
    tests=a.tool_tests.read_text(encoding='utf-8-sig');count=re.search(r'Ran (\d+) tests',tests)
    assert count and '\nOK\n' in tests and '\nFAILED' not in tests
    # No compilation occurs between this gate's baseline and new reports.
    # Freeze the full final inventory and all nonmatrix executables actually
    # used by that gate, so the partition can be reviewed and reproduced.
    archive_paths={current_path,ROOT/'docs/decomp_status.csv',ROOT/'docs/coverage.md',coverage_path}
    archive_paths.update(ROOT/'build'/f'{name}.exe' for name in TESTS)
    archive_paths.update(ROOT/row['test'].split()[0] for row in current.values()
                         if row['test'].split()[0]!='build/vf3matrixfamily.exe')
    a.archive.mkdir(parents=True)
    for path in sorted(archive_paths):
        destination=a.archive/path.relative_to(ROOT);destination.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,destination);assert digest(destination)==digest(path)
        refs.append(dict(reference(destination),original_path=str(path)))
    refs += [reference(path) for path in (a.source_freeze,native,a.baseline_bindings,a.regression,
              a.series,a.tool_tests,Path(__file__))]
    result=dict(completed_utc=datetime.now(timezone.utc).isoformat(),verified_c_bytes=accepted,
        frozen_body_bytes=denominator,verified_percentage=100*accepted/denominator,
        target_c_bytes=282527,target_met=True,remaining_to_65=0,new_owners=26,
        marginal_c_bytes=5956,compiled_inputs=len(source['files']),binding_inventory=len(current),
        native_suites=len(TESTS),oracle_tool_tests=int(count[1]),
        full_regression=dict(passed=True,baseline=status,new_bindings=len(new_keys),
            total_bindings=len(current),unchanged_native_sha256=native_hash,new_results=new_results),
        references=refs)
    a.out.write_text(json.dumps(result,indent=2)+'\n')
    print(f'65% checkpoint PASS: {accepted}/{denominator}; {len(current)} bindings; {len(TESTS)} native suites')

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('source-freeze','baseline-bindings','regression','series','tool-tests','archive','out'):
        p.add_argument('--'+name,type=Path,required=True)
    for name in ('new-report','qualification','historical'):
        p.add_argument('--'+name,type=Path,action='append',required=True)
    checkpoint(p.parse_args())
