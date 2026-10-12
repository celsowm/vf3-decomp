"""Seal the expanded helper milestone after the full accepted-inventory gate."""
from datetime import datetime, timezone
import json
from pathlib import Path
import re
import shutil
from ram_clipping_batch_audit import digest, reference
from regression_status import summarize
from task_completion_audit import freeze
from portcheck import TESTS

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    historical=ROOT/'tools/oracle/replay_transition_historical_archive_v1.json'
    saved=json.loads(historical.read_text())
    for row in saved['references']:assert digest(row['path'])==row['sha256']
    source=CACHE/'scene_batch_integrated_dev_v1_complete_sources/manifest.json'
    native=freeze(source,native=True)
    assert len(json.loads(source.read_text())['files'])==408
    qualification=ROOT/'tools/oracle/replay_transition_qualification_v1.json'
    proof=json.loads(qualification.read_text())
    assert proof['ready_for_promotion'] and proof['marginal_bytes']==420 and proof['strict_cases']==1515
    promotion_path=ROOT/'tools/oracle/replay_transition_v1_manifest.json'
    promotion=json.loads(promotion_path.read_text())
    assert set(promotion['entries'])=={'0x8c099544','0x8c099568','0x8c0a91e6'}
    assert promotion['measured_gain']==420
    assert set(promotion['excluded'])=={'0x8c0a92c8','0x8c0a9444'}
    coverage_path=ROOT/'extract/analysis/coverage.json';coverage=json.loads(coverage_path.read_text())
    assert coverage['ported_unique_bytes']==276578 and coverage['bytes_total']==434656
    bindings=ROOT/'tools/golden_bindings.json'
    log=ROOT/'extract/analysis/replay_transition_all_bindings_accept_v1.log'
    text=log.read_text(encoding='utf-8-sig')
    status=summarize(text,json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings']==1418
    suites=dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b',text.split('\nbinding ',1)[0],re.M))
    assert set(suites)==set(TESTS) and all(value=='PASS' for value in suites.values())
    tests=ROOT/'extract/analysis/replay_transition_tool_tests_accept_v1.log'
    assert re.search(r'Ran 388 tests\b',tests.read_text()) and '\nOK\n' in tests.read_text()
    archive=CACHE/'replay_transition_full_checkpoint_v1'
    output=ROOT/'tools/oracle/replay_transition_full_checkpoint_v1.json'
    assert not archive.exists() and not output.exists()
    refs=[reference(path) for path in (historical,source,native,qualification,promotion_path,log,tests,Path(__file__))]
    paths=[bindings,ROOT/'docs/decomp_status.csv',ROOT/'docs/coverage.md',coverage_path]
    paths += [ROOT/'build'/f'{name}.exe' for name in TESTS]
    for path in paths:
        destination=archive/path.relative_to(ROOT);destination.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,destination);assert digest(destination)==digest(path)
        refs.append(dict(reference(destination),original_path=str(path)))
    output.write_text(json.dumps(dict(completed_utc=datetime.now(timezone.utc).isoformat(),
        verified_c_bytes=276578,frozen_body_bytes=434656,verified_percentage=276578/434656*100,
        target_c_bytes=282527,remaining_to_65=5949,new_owners=3,marginal_c_bytes=420,
        archived_source_inputs=408,binding_inventory=1418,native_suites=39,oracle_tool_tests=388,
        full_regression=status,already_accepted_dependency_credit=0,
        references=refs),indent=2)+'\n')
    print('Full helper checkpoint PASS: 276578 C bytes; 1418 bindings; 39 native suites; 388 tool tests')


if __name__=='__main__':main()
