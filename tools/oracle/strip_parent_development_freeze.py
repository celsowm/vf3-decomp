"""Seal complete strip development before generating independent holdout inputs."""
from datetime import datetime, timezone
import json
from pathlib import Path
import re

from ram_clipping_batch_audit import campaign, caller_files, digest, reference
from regression_status import summarize
from task_completion_audit import freeze

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    archive = CACHE/'strip_parent_integrated_dev_v1_complete_sources/manifest.json'
    native = freeze(archive, native=True)
    assert len(json.loads(archive.read_text())['files']) == 400
    owners_path = ROOT/'tools/oracle/coverage_65_strip_parent_screen_v3_owners.json'
    owners = json.loads(owners_path.read_text())
    image_path = ROOT/'extract/gamedata/1ST_READ.BIN'
    states, inputs, proofs, refs = campaign(
        CACHE/'coverage_65_strip_parent_screen_v3_export',
        ROOT/'extract/analysis/strip_parent_integrated_dev_v2_frozen_native.json',
        owners, native, image_path.read_bytes())
    assert len(states) == 2 and len(owners) == 5
    log = ROOT/'extract/analysis/strip_parent_integrated_all_bindings_dev_v1.log'
    bindings = ROOT/'tools/golden_bindings.json'
    status = summarize(log.read_text(encoding='utf-8-sig'), json.loads(bindings.read_text()))
    assert status['passed'], 'wait for the full current regression to finish'
    from portcheck import TESTS
    text = log.read_text(encoding='utf-8-sig')
    native_section = text.split('\nbinding ', 1)[0]
    suite_rows = dict(re.findall(r'^  (vf3\S+)\s+(PASS|FAIL|missing)\b', native_section, re.M))
    assert set(suite_rows) == set(TESTS) and all(value == 'PASS' for value in suite_rows.values())
    tests = ROOT/'extract/analysis/strip_parent_integrated_tool_tests_dev_v1.log'
    assert re.search(r'Ran 325 tests', tests.read_text()) and '\nOK\n' in tests.read_text()
    attribution_path = ROOT/'tools/oracle/strip_parent_callable_v1.json'
    attributions = json.loads(attribution_path.read_text())
    from body_cover import body_spans
    from callable_body import validate
    spans = body_spans()
    for owner, attribution in attributions.items():
        validate(int(owner, 16), attribution, spans[int(owner, 16)],
                 CACHE/'coverage_65_strip_parent_screen_v3_export', image_path.read_bytes())
    refs += caller_files(attributions)
    refs += [reference(path) for path in (archive, native, image_path, owners_path,
              attribution_path, log, bindings, tests, Path(__file__),
              ROOT/'tools/oracle/strip_parent_holdout_inputs.py')]
    refs += [reference(ROOT/'build'/f'{name}.exe') for name in TESTS]
    out = CACHE/'strip_parent_qualified_development_freeze_v1.json'
    assert not out.exists(), 'refuse to replace a qualified freeze'
    out.write_text(json.dumps(dict(coverage_credit=False, qualified_development_only=True,
        frozen_at_utc=datetime.now(timezone.utc).isoformat(), compiled_inputs=400,
        entries=5, distinct_valid_inputs=len(inputs), native_suites_passed=39,
        oracle_tests_passed=325, full_regression=status, scenarios=proofs,
        references=list({row['path']: row for row in refs}.values())), indent=2)+'\n')
    print('Five strip parents: complete development freeze PASS; no new coverage credit')


if __name__ == '__main__':
    main()
