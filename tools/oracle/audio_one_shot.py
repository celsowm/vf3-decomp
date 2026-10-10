"""Process-owned original invocation pilots. No C/device acceptance or credit."""
import argparse
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
from audio_determinism import ROOT, sha, describe, checkpoints, emulator_lock, compare, compress_checkpoint
from capsules import records
from audio_deduplicate import retain_hard_link


def run(a):
    if not a.out.resolve().is_relative_to((ROOT/'extract/analysis').resolve()) and not any(
            a.out.resolve().is_relative_to(p.resolve()) for p in a.evidence_root):
        raise ValueError('external evidence output requires an explicit evidence root')
    shared_audio = {}
    for directory in a.dedup_dir:
        for path in sorted(directory.glob('*.audio.gz')):
            shared_audio.setdefault(sha(path),path)
    if a.dedup_dir and not a.compress:
        raise ValueError('deduplication requires verified compressed evidence')
    recipe = json.loads(a.recipe.read_text())
    out = a.out.resolve()
    out.mkdir(parents=True, exist_ok=True)
    manifest = dict(advisory=True, coverage_credit=False, passed=False, runs=[],
        mode='rollback_guard_control' if a.rollback else 'nonrollback_one_shot',
        execution=('readable_c_callers' if all(int(c['entry'],0) in (0x8c0c5c94,0x8c0c9f54,0x8c099060) for c in recipe['cases'])
                   else 'readable_c_encoder' if all(int(c['entry'],0)==0x8c040b7c for c in recipe['cases'])
                   else 'readable_c_submission_family' if any(int(c['entry'],0) in (0x8c0c5d86,0x8c0ca05c,0x8c098040) for c in recipe['cases'])
                   else 'readable_c_channels' if all(int(c['entry'],0)==0x8c040fa4 for c in recipe['cases'])
                   else 'readable_c_queue') if a.c_replay else 'original_sh4',
        device_control=a.control, corrupt_command=a.corrupt_command,
        provenance={str(p): sha(p) for p in [a.emulator, a.recipe,
            ROOT/'tools/oracle/vf3oracle.cpp', ROOT/'tools/oracle/vf3audio.cpp',
            ROOT/'tools/oracle/install.py', ROOT/'tools/oracle/vf3audiobridge.cpp',
            ROOT/'src/fight/command_encoders.c', ROOT/'extract/gamedata/1ST_READ.BIN',
            ROOT/'src/fight/audio_channels.c',
            ROOT/'src/fight/audio_submission.c',
            ROOT/'src/fight/audio_actor_clear.c',
            ROOT/'src/fight/audio_encoder.c',
            ROOT/'src/fight/audio_request.c',ROOT/'src/fight/audio_input.c',
            ROOT/'src/fight/audio_fight.c',ROOT/'src/fight/audio_fight_scene.c',
            ROOT/'src/fight/audio_fight_render.c',ROOT/'src/fight/audio_fight_internal.h',
            Path(__file__)]})
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
                    env['VF3_ONESHOT_TRIGGER_N'] = str(case.get('trigger_ordinal', 1))
                    if case.get('event_window'):
                        env['VF3_ONESHOT_WAIT_AICA'] = '1'
                control = case.get('control', a.control)
                for key, value in case.get('audio_inputs', {}).items():
                    if a.rollback or key not in ('allocation_boundary', 'allocation_start'):
                        raise ValueError('unsupported live audio input')
                    value = int(value,0) if isinstance(value,str) else value
                    if not 0 <= value <= 0xffffffff:
                        raise ValueError('audio input must be an unsigned 32-bit value')
                    env['VF3_AUDIO_'+key.upper()] = hex(value)
                if control:
                    if a.rollback:
                        raise ValueError('device input controls require one-shot mode')
                    env['VF3_AUDIO_CONTROL'] = control
                if a.corrupt_command:
                    if not a.c_replay:
                        raise ValueError('command corruption is a live C negative control')
                    env['VF3_AUDIO_CORRUPT_COMMAND'] = '1'
                if a.c_replay:
                    if entry not in (0x8c040f1e,0x8c040fa4,0x8c0c5d86,0x8c0ca05c,0x8c098040,0x8c040b7c,0x8c0c5c94,0x8c0c9f54,0x8c099060) or a.rollback:
                        raise ValueError('unsupported live C audio entry')
                    env['VF3_C_AUDIO_REPLAY'] = '1'
                with log.open('wb') as f:
                    try:
                        proc = subprocess.run([str(a.emulator.resolve()), str(ROOT/'rom/vf3.gdi')],
                            cwd=a.emulator.resolve().parent, env=env, stdout=f,
                            stderr=subprocess.STDOUT, timeout=a.timeout)
                        code = proc.returncode
                    except subprocess.TimeoutExpired:
                        code = 'timeout'
                row = dict(state=str(state), case=case['name'], repetition=repeat+1,
                    device_control=control,
                    returncode=code, log=str(log), log_sha256=sha(log),
                    patch_sha256=sha(patch), passed=False)
                try:
                    samples = list(records(capsule))
                    summary_path = Path(str(capsule)+'.summary.json')
                    summary = json.loads(summary_path.read_text())
                    if a.compress:
                        audio, raw_hash = compress_checkpoint(audio)
                        row['audio_raw_sha256'] = raw_hash
                    row.update(capsule=str(capsule), capsule_sha256=sha(capsule),
                        summary=summary, audio=describe(audio))
                    digest=row['audio']['sha256']
                    if digest in shared_audio and retain_hard_link(audio,shared_audio[digest],digest,a.evidence_root):
                        row['shared_audio_source']=str(shared_audio[digest])
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
    ap.add_argument('--c-replay', action='store_true', help='execute verified queue C against live devices')
    ap.add_argument('--control', choices=['timer', 'arm_disabled', 'queue_busy'], help='controlled genuine device input')
    ap.add_argument('--corrupt-command', action='store_true', help='negative control: corrupt C queue writes')
    ap.add_argument('--compress', action='store_true', help='hash-verified gzip storage for new audio evidence')
    ap.add_argument('--dedup-dir', type=Path, action='append', default=[],
                    help='retain identical generated output via verified hard links')
    ap.add_argument('--evidence-root',type=Path,action='append',default=[],
                    help='explicit local cache root for captures outside extract/analysis')
    a = ap.parse_args()
    with emulator_lock(a.emulator):
        return run(a)


if __name__ == '__main__':
    raise SystemExit(main())
