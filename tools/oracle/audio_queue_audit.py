"""Seal bounded live-C queue evidence; this does not award decompilation credit."""
import argparse
import hashlib
import json
from pathlib import Path
from audio_determinism import checkpoints, first_difference, sha
from audio_replay_compare import evaluate


def artifact(path):
    return dict(path=str(path), sha256=sha(path), manifest=json.loads(path.read_text()))


def audit(root):
    frozen_sources = artifact(root/'audio_queue_v1_frozen_sources.json')
    for source in frozen_sources['manifest']:
        if sha(source['path']) != source['sha256']:
            raise ValueError('frozen source archive changed')
    pairs = [
        ('event', 'audio_queue_event_original_final', 'audio_queue_event_c_final'),
        ('timer', 'audio_queue_timer_original_v1', 'audio_queue_timer_c_v1'),
        ('arm_disabled', 'audio_queue_arm_original_v1', 'audio_queue_arm_c_v1'),
        ('paths', 'audio_queue_paths_original_v2', 'audio_queue_paths_c_v2'),
        ('corrupt_command', 'audio_queue_negative_original_v1', 'audio_queue_mutant_c_v1'),
    ]
    comparisons, artifacts = {}, []
    for name, left, right in pairs:
        original, c = [root/p/'manifest.json' for p in (left, right)]
        result = evaluate(original, c)
        comparisons[name] = result
        artifacts.extend([artifact(original), artifact(c)])
        if result['passed'] != (name != 'corrupt_command'):
            raise ValueError(f'{name}: unexpected comparison outcome')
        if name == 'corrupt_command':
            if not any('device' in r['different_fields'] and
                       not r['audio']['equal'] and r['audio']['section'] == 'aica'
                       for r in result['comparisons']):
                raise ValueError('command corruption did not reach actual bus/AICA state')
    baseline = json.loads((root/'audio_queue_event_original_final/manifest.json').read_text())
    changed_inputs = []
    for control, directory in [('timer', 'audio_queue_timer_original_v1'),
                               ('arm_disabled', 'audio_queue_arm_original_v1')]:
        controlled = json.loads((root/directory/'manifest.json').read_text())
        for row in controlled['runs']:
            reference = next(r for r in baseline['runs'] if r['state'] == row['state']
                             and r['case'] == row['case'] and r['repetition'] == row['repetition'])
            initial = next(checkpoints(reference['audio']['path']))
            changed = next(checkpoints(row['audio']['path']))
            if initial['blocks'][1] != changed['blocks'][1]:
                raise ValueError('device control unexpectedly changed entry architecture')
            a, b = initial['blocks'][3], changed['blocks'][3]
            if a == b:
                raise ValueError('device control did not change real AICA input')
            changed_inputs.append(dict(control=control, state=row['state'],
                initial_aica_first_difference=first_difference(a, b),
                baseline_aica_sha256=hashlib.sha256(a).hexdigest(),
                controlled_aica_sha256=hashlib.sha256(b).hexdigest()))
    return dict(advisory=True, coverage_credit=False, passed=True,
        scope='live readable-C enqueue only; research ARM/DSP dependency retained',
        positive_comparisons=sum(len(v['comparisons']) for k,v in comparisons.items()
                                 if k != 'corrupt_command'),
        comparisons=comparisons, changed_device_inputs=changed_inputs, artifacts=artifacts,
        frozen_sources=frozen_sources)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--root', type=Path, default=Path('extract/analysis'))
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    result = audit(a.root)
    result['auditor'] = dict(path=__file__, sha256=sha(__file__))
    a.out.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(f"{result['positive_comparisons']} live-C comparisons and genuine negative/input controls pass")


if __name__ == '__main__':
    main()
