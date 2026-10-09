"""Process-owned original invocation pilots. No C/device acceptance or credit."""
import argparse
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
from audio_determinism import ROOT, sha, describe, checkpoints, emulator_lock, compare
from capsules import records


def run(a):
    recipe = json.loads(a.recipe.read_text())
    out = a.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    manifest = dict(advisory=True, coverage_credit=False, passed=False, runs=[],
        mode='rollback_guard_control' if a.rollback else 'nonrollback_one_shot',
        provenance={str(p): sha(p) for p in [a.emulator, a.recipe,
            ROOT/'tools/oracle/vf3oracle.cpp', ROOT/'tools/oracle/vf3audio.cpp',
            ROOT/'tools/oracle/install.py', Path(__file__)]})
    target_manifest = out/'manifest.json'
    def save():
        target_manifest.write_text(json.dumps(manifest, indent=2)+'\n', encoding='utf-8')
    for state in a.state:
        manifest['provenance'][str(state)] = sha(state)
        for case in recipe['cases']:
            if a.rollback and not case.get('event_crossing'):
                continue
            for repeat in range(a.repetitions):
                if shutil.disk_usage(out).free < 4*1024**3:
                    raise RuntimeError('4 GiB capture reserve reached')
                stem = f'{state.stem}_{case["name"]}_{repeat+1}'
                watch, patch, capsule, audio, log = [out/f'{stem}.{ext}' for ext in
                                                    ['watch', 'patch', 'capsule', 'audio', 'log']]
                trigger, entry = int(recipe['trigger'], 0), int(case['entry'], 0)
                watch.write_text(f'pc {entry:08x}\n', encoding='ascii')
                if 'transfer' in case:
                    with watch.open('a') as f:
                        f.write(f'exitpc {entry:08x} {int(case["transfer"],0):08x}\n')
                lines = [f'entry {trigger:08x} {entry:08x}',
                         f'reg {trigger:08x} pr {trigger+2:08x}']
                for reg, value in case.get('registers', {}).items():
                    value = int(value, 0) if isinstance(value, str) else value
                    lines.append(f'reg {trigger:08x} {reg} {value&0xffffffff:08x}')
                for addr, value in case.get('memory', {}).items():
                    value = int(value, 0) if isinstance(value, str) else value
                    lines.append(f'ram {trigger:08x} {int(addr,0):08x} {value&0xffffffff:08x}')
                patch.write_text('\n'.join(lines)+'\n', encoding='ascii')
                env = {k: v for k, v in os.environ.items() if not k.startswith('VF3_')}
                env.update(VF3_STATE=str(state.resolve()), VF3_INTERPRETER='1',
                    VF3_CAPSULE=str(capsule), VF3_CAPSULE_N='1', VF3_WATCH=str(watch),
                    VF3_ENTRY_PATCH=str(patch), VF3_PROBE_ONLY='1',
                    VF3_PROBE_OPS=str(case.get('budget', 20000)),
                    VF3_TRACE_FRAMES=str(a.frames), VF3_AUDIO_CHECKPOINTS=str(audio))
                if a.rollback:
                    env.update(VF3_ROLLBACK_AICA_RAM='1', VF3_AUDIO_POINTS='1,1048576')
                else:
                    env['VF3_ONESHOT'] = '1'
                with log.open('wb') as f:
                    try:
                        proc = subprocess.run([str(a.emulator.resolve()), str(ROOT/'rom/vf3.gdi')],
                            cwd=a.emulator.resolve().parent, env=env, stdout=f,
                            stderr=subprocess.STDOUT, timeout=a.timeout)
                        code = proc.returncode
                    except subprocess.TimeoutExpired:
                        code = 'timeout'
                row = dict(state=str(state), case=case['name'], repetition=repeat+1,
                    returncode=code, log=str(log), log_sha256=sha(log),
                    patch_sha256=sha(patch), passed=False)
                try:
                    samples = list(records(capsule))
                    summary_path = Path(str(capsule)+'.summary.json')
                    summary = json.loads(summary_path.read_text())
                    row.update(capsule=str(capsule), capsule_sha256=sha(capsule),
                        summary=summary, audio=describe(audio))
                    if len(samples) == 1:
                        s = samples[0]
                        row.update(flags=s['flags'], exit=hex(s['exitpc']),
                            result=struct.unpack_from('<I', s['after'])[0],
                            instructions=len(s['ops']), device_accesses=len(s['device']))
                        audio_rows = list(checkpoints(audio))
                        events = audio_rows[-1]['blocks'][7]
                        row['aica_events'] = sum(event[2] == 1 for event in struct.iter_unpack('<6I', events))
                        expected = case.get('expected_result')
                        result_ok = expected is None or row['result'] == expected&0xffffffff
                        if 'expected_exit' in case:
                            result_ok &= (s['exitpc']&0x1fffffff) == (int(case['expected_exit'],0)&0x1fffffff)
                        if a.rollback:
                            row['passed'] = bool(s['flags'] & 4) and summary['aica_timeslice_aborts'] > 0 if case.get('event_crossing') else not s['flags'] and result_ok
                        else:
                            row['passed'] = (code == 0 and summary.get('one_shot_done')
                                and summary['started'] == summary['completed'] == 1
                                and not summary['incomplete'] and not summary['unaccounted']
                                and len(audio_rows) == 2 and not s['flags'] and result_ok
                                and (not case.get('event_crossing') or row['aica_events'] > 0))
                            if case.get('rejected'):
                                row['passed'] = (code == 0 and len(audio_rows) == 2
                                    and s['flags'] == 4 and summary.get('one_shot_done')
                                    and summary['started'] == summary['completed'] == 1
                                    and not summary['incomplete'] and not summary['unaccounted']
                                    and summary.get('restores', 0) == 0)
                except (ValueError, FileNotFoundError, KeyError) as e:
                    row['error'] = str(e)
                manifest['runs'].append(row)
                save()
                print(f'{stem}: passed={row["passed"]} flags={row.get("flags")} result={row.get("result")} AICA events={row.get("aica_events")}', flush=True)
    manifest['passed'] = bool(manifest['runs']) and all(row['passed'] for row in manifest['runs'])
    manifest['repeatability'] = []
    if not a.rollback:
        for state in a.state:
            for case in recipe['cases']:
                rows = [r for r in manifest['runs'] if r['state'] == str(state) and r['case'] == case['name']]
                for row in rows[1:]:
                    result = compare(rows[0]['audio']['path'], row['audio']['path']) if 'audio' in rows[0] and 'audio' in row else dict(equal=False)
                    manifest['repeatability'].append(dict(state=str(state), case=case['name'], **result))
                    manifest['passed'] &= result['equal']
    save()
    return 0 if manifest['passed'] else 2


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--state', type=Path, action='append', required=True)
    ap.add_argument('--recipe', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--emulator', type=Path, default=ROOT/'tools/emu/flycast-build/flycast.exe')
    ap.add_argument('--repetitions', type=int, choices=range(1, 5), default=3)
    ap.add_argument('--frames', type=int, default=30)
    ap.add_argument('--timeout', type=int, default=30)
    ap.add_argument('--rollback', action='store_true', help='control using existing RAM-only guard')
    a = ap.parse_args()
    with emulator_lock(a.emulator):
        return run(a)


if __name__ == '__main__':
    raise SystemExit(main())
