"""Seal the expanded accepted strip inventory and its immutable evidence."""
from datetime import datetime, timezone
import json
from pathlib import Path
import re
import shutil
from ram_clipping_batch_audit import digest, reference
from regression_status import summarize
from portcheck import TESTS

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    historical = ROOT/'tools/oracle/strip_parent_historical_archive_v1.json'
    old = json.loads(historical.read_text())
    for row in old['references']:
        assert digest(row['path']) == row['sha256'], 'historical strip dependency changed'
    source = Path(old['compiled_source_archive']['path'])
    assert digest(source) == old['compiled_source_archive']['sha256']
    compiled = json.loads(source.read_text())
    assert len(compiled['files']) == 400
    for row in compiled['files']:
        assert digest(source.parent/row['path']) == row['sha256']
    assert digest(compiled['native']) == compiled['native_sha256']
    promotion_path = ROOT/'tools/oracle/strip_parent_v1_manifest.json'
    promotion = json.loads(promotion_path.read_text())
    assert len(promotion['entries']) == 5 and not promotion['excluded'] and promotion['measured_gain'] == 2128
    coverage = json.loads((ROOT/'extract/analysis/coverage.json').read_text())
    assert coverage['ported_unique_bytes'] == 275276 and coverage['bytes_total'] == 434656
    bindings = ROOT/'tools/golden_bindings.json'
    log = ROOT/'extract/analysis/strip_parent_full_633_checkpoint_v1.log'
    text = log.read_text(encoding='utf-8-sig')
    status = summarize(text, json.loads(bindings.read_text()))
    assert status['passed'] and status['expected_bindings'] == 1414
    native_section = text.split('\nbinding ', 1)[0]
    suites = dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b', native_section, re.M))
    assert set(suites) == set(TESTS) and all(v == 'PASS' for v in suites.values())
    tests = ROOT/'extract/analysis/selection_unlock_tool_tests_dev_v1.log'
    assert re.search(r'Ran 330 tests', tests.read_text()) and '\nOK\n' in tests.read_text()
    archive = CACHE/'strip_parent_full_633_checkpoint_v1'
    assert not archive.exists()
    archive.mkdir()
    refs = [reference(p) for p in (historical, source, Path(compiled['native']), promotion_path, log, tests, Path(__file__))]
    for path in (bindings,ROOT/'docs/decomp_status.csv',ROOT/'docs/coverage.md',ROOT/'extract/analysis/coverage.json'):
        destination = archive/path.relative_to(ROOT)
        destination.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(path,destination)
        assert digest(destination) == digest(path)
        refs.append(dict(reference(destination),original_path=str(path)))
    out = ROOT/'tools/oracle/strip_parent_full_633_checkpoint_v1.json'
    assert not out.exists()
    out.write_text(json.dumps(dict(completed_utc=datetime.now(timezone.utc).isoformat(),
        verified_c_bytes=275276,frozen_body_bytes=434656,verified_percentage=275276/434656*100,
        target_c_bytes=282527,remaining_to_65=7251,new_owners=5,marginal_c_bytes=2128,
        archived_source_inputs=400,binding_inventory=1414,native_suites=39,
        oracle_tool_tests=330,full_regression=status,selection_unlock_credit=0,
        references=refs),indent=2)+'\n')
    print('Full strip checkpoint PASS: 275276 verified C bytes, 1414 bindings, 39 native suites')


if __name__=='__main__':
    main()
