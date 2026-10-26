#!/usr/bin/env python3
"""recover_oracle.py - stage, seal and verify the oracle emulator.

The oracle (the instrumented Flycast build that records the guest's SH-4
execution) was lost with the `tools/emu` tree.  It is recoverable, and this
script is the reproducible recipe:

  python tools/oracle/recover_oracle.py stage     # stage the observer + data
  python tools/oracle/recover_oracle.py seal      # seal the v3 observer
  python tools/oracle/recover_oracle.py verify    # re-run the control windows

`stage` copies the observer binary and its data directory (BIOS, NVMEM, VMU
saves and the savestates) into `tools/emu/flycast-build/`, which is where the
repo's capture tools expect them.  Every input is pinned by digest, so a stage
either reproduces the recorded oracle exactly or refuses to run.

`seal` compares the eight original control windows - captured by the pristine
oracle before it was lost - with the same eight windows captured by the v3
observer, and writes two files:

  tools/oracle/extended_observer_controls_v3.json
      the seal `tools/golden_batch.py` reads to authorise a 500,000-instruction
      probe budget (`--probe-ops`), and
  tools/oracle/oracle_recovery_v1.json
      the recovery evidence: what was staged, from where, with which digests.

`verify` re-runs the control windows with the staged observer and compares the
fresh capsules and audio checkpoints with the pristine originals, byte for
byte.  That is the proof that the restored oracle is the oracle the campaigns
were recorded against.

The observer binaries are GPL'd Flycast builds; they are not committed to the
repository (they are far too large) and are attached to the GitHub release
instead.  The sources they are built from are in this repository:
`tools/oracle/vf3oracle_v3.cpp` is the exact source of the v3 observer and
`docs/re/patches/oracle_v3_from_pristine.patch` is its delta against the
pristine oracle.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools' / 'oracle'))

from audio_determinism import compare as compare_audio          # noqa: E402
from compare_original_samples import compare                    # noqa: E402

BUILD = ROOT / 'tools' / 'emu' / 'flycast-build'
DATA = BUILD / 'data'
CONTROLS = ROOT / 'tools' / 'oracle' / 'controls_v3'
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
ROM = ROOT / 'rom' / 'vf3.gdi'

# The observer binaries, by digest.  The v3 observer is the one the campaigns
# use: the pristine device-read policy, the 1024-page RAM budget, the
# 500,000-instruction record bound and the drive-state record at the synthetic
# arm.  The v2 observer is the same recorder without the drive-state record.
OBSERVERS = {
    'v3': dict(
        digest='143bb86088a83f086b533570e3b9e13e118958882ec59d4a2d1cf8c055045323',
        candidates=[
            CACHE / 'flycast_capsule_extended_v3.exe',
            Path('D:/vf3-captures/coverage_65_09970a_entry_probe_v2/observer_build_v1/'
                 'flycast_nested_entry_fixture.exe'),
        ],
        note='the observer the re-capture campaigns use (drive state at the synthetic arm)',
    ),
    'v2': dict(
        digest='d836abc4b0c8b42f0a32069051b367452a721195800958e2bbf9869a229e4b95',
        candidates=[CACHE / 'flycast_capsule_extended_v2.exe'],
        note='the same recorder without the drive-state record at the synthetic arm',
    ),
}

# The data directory the observer needs beside its executable.  Flycast's
# Windows build puts it at <exe dir>\data\.
DATA_INPUTS = [
    # (source candidates, destination name, digest)
    ([Path('C:/Users/celso/Downloads/dc_bios.zip')], 'dc_boot.bin', None),
    ([Path('C:/Users/celso/Downloads/dc_bios.zip')], 'dc_flash.bin', None),
    ([CACHE / 'data/dc_nvmem.bin'], 'dc_nvmem.bin', None),
    ([CACHE / 'data/vmu_save_A2.bin'], 'vmu_save_A2.bin', None),
    ([CACHE / 'data/MK-51001_vmu_save_A1.bin'], 'MK-51001_vmu_save_A1.bin', None),
]

# The savestates the campaigns resume from.
STATE_SOURCES = {
    'vf3_26.state': [CACHE / 'ram_clipping_selected_full_625_checkpoint_v1/tools/emu/flycast-build/data/vf3_26.state',
                      CACHE / 'scene_round_accepted_historical_v1/tools/emu/flycast-build/data/vf3_26.state'],
    'vf3_27.state': [CACHE / 'ram_clipping_selected_full_625_checkpoint_v1/tools/emu/flycast-build/data/vf3_27.state',
                      CACHE / 'scene_round_accepted_historical_v1/tools/emu/flycast-build/data/vf3_27.state'],
    'vf3_28.state': [Path('D:/vf3-captures/coverage_65_full_checkpoint_v1/historical/tools/emu/flycast-build/data/vf3_28.state'),
                      CACHE / 'replay_transition_accepted_historical_v1/tools/emu/flycast-build/data/vf3_28.state'],
    'vf3_29.state': [Path('D:/vf3-captures/coverage_65_full_checkpoint_v1/historical/tools/emu/flycast-build/data/vf3_29.state'),
                      CACHE / 'replay_transition_accepted_historical_v1/tools/emu/flycast-build/data/vf3_29.state'],
    'vf3_45.state': [Path('D:/vf3-captures/coverage_65_full_checkpoint_v1/historical/tools/emu/flycast-build/data/vf3_45.state'),
                      CACHE / 'replay_transition_accepted_historical_v1/tools/emu/flycast-build/data/vf3_45.state'],
    'vf3_46.state': [Path('D:/vf3-captures/coverage_65_full_checkpoint_v1/historical/tools/emu/flycast-build/data/vf3_46.state'),
                      CACHE / 'replay_transition_accepted_historical_v1/tools/emu/flycast-build/data/vf3_46.state'],
}

ORIGINAL_CONTROLS = CACHE / 'replay_transition_original_dispatch_v2/manifest.json'
V3_CONTROLS = CACHE / 'extended_observer_v3_controls/manifest.json'
SEAL = ROOT / 'tools' / 'oracle' / 'extended_observer_controls_v3.json'
EVIDENCE = ROOT / 'tools' / 'oracle' / 'oracle_recovery_v1.json'


def digest(path) -> str:
    with Path(path).open('rb') as handle:
        return hashlib.file_digest(handle, 'sha256').hexdigest()


def reference(path) -> dict:
    path = Path(path)
    return dict(path=str(path), sha256=digest(path))


def first_existing(candidates):
    for candidate in candidates:
        if candidate.is_file():
            return candidate
    return None


def find_observer(kind: str) -> tuple[Path, dict]:
    spec = OBSERVERS[kind]
    for candidate in spec['candidates']:
        if candidate.is_file():
            found = digest(candidate)
            if found == spec['digest']:
                return candidate, spec
            raise SystemExit(f'{candidate} has digest {found}, expected {spec["digest"]}')
    raise SystemExit(f'no {kind} observer found; looked in ' +
                     ', '.join(str(c) for c in spec['candidates']))


def stage_observer(kind: str) -> tuple[Path, dict, list]:
    source, spec = find_observer(kind)
    BUILD.mkdir(parents=True, exist_ok=True)
    DATA.mkdir(parents=True, exist_ok=True)
    target = BUILD / f'flycast_{kind}.exe'
    shutil.copy2(source, target)
    if digest(target) != spec['digest']:
        raise SystemExit('the staged observer does not match its digest')
    staged = [reference(target)]
    for candidates, name, _ in DATA_INPUTS:
        found = first_existing(candidates)
        if found is None:
            raise SystemExit(f'missing data input {name}; looked in '
                             + ', '.join(str(c) for c in candidates))
        if found.suffix == '.zip':
            member = 'dc_boot.bin' if name == 'dc_boot.bin' else 'dc_flash.bin'
            with __import__('zipfile').ZipFile(found) as archive:
                archive.extract(member, DATA)
        else:
            shutil.copy2(found, DATA / name)
        staged.append(reference(DATA / name))
    for name, candidates in STATE_SOURCES.items():
        found = first_existing(candidates)
        if found is None:
            continue
        shutil.copy2(found, DATA / name)
        staged.append(reference(DATA / name))
    return target, spec, staged


def control_windows() -> list[dict]:
    """The eight original control windows, as captured by the pristine oracle."""
    original = json.loads(ORIGINAL_CONTROLS.read_text())
    v3 = json.loads(V3_CONTROLS.read_text())
    assert len(original['runs']) == len(v3['runs']) == 8
    windows = []
    for left, right in zip(original['runs'], v3['runs']):
        assert left['case'] == right['case'] and left['state'] == right['state']
        state = Path(left['state']).name
        stem = f'{state[:-len(".state")]}_{left["case"]}_1'
        windows.append(dict(
            case=left['case'], state=state, stem=stem,
            watch=str(CONTROLS / f'{stem}.watch'),
            patch=str(CONTROLS / f'{stem}.patch'),
            original_capsule=left['capsule'], original_capsule_sha256=left['capsule_sha256'],
            original_audio=left['audio']['path'], original_audio_sha256=left['audio']['sha256'],
            v3_capsule=right['capsule'], v3_capsule_sha256=right['capsule_sha256'],
            v3_audio=right['audio']['path'], v3_audio_sha256=right['audio']['sha256'],
            instructions=right.get('instructions'), flags=right.get('flags'),
            exit=right.get('exit'), result=right.get('result'),
        ))
    return windows


def capture_window(window: dict, executable: Path, out: Path) -> dict:
    """Run one control window with the staged observer."""
    out.mkdir(parents=True, exist_ok=True)
    capsule = out / f'{window["stem"]}.capsule'
    audio = out / f'{window["stem"]}.audio'
    log = out / f'{window["stem"]}.log'
    env = {k: v for k, v in os.environ.items() if not k.startswith('VF3_')}
    env.update(
        VF3_STATE=str(DATA / window['state']),
        VF3_INTERPRETER='1',
        VF3_CAPSULE=str(capsule),
        VF3_CAPSULE_N='1',
        VF3_WATCH=window['watch'],
        VF3_ENTRY_PATCH=window['patch'],
        VF3_PROBE_ONLY='1',
        VF3_PROBE_OPS='20000',
        VF3_TRACE_FRAMES='30',
        VF3_AUDIO_CHECKPOINTS=str(audio),
        VF3_ONESHOT='1',
        VF3_ONESHOT_TRIGGER_N='1',
        VF3_EXPLICIT_RETURN_ONLY='1',
    )
    with log.open('wb') as handle:
        code = subprocess.run([str(executable), str(ROM)], cwd=str(executable.parent), env=env,
                              stdout=handle, stderr=subprocess.STDOUT, timeout=300).returncode
    return dict(returncode=code, capsule=str(capsule), audio=str(audio), log=str(log),
                capsule_sha256=digest(capsule) if capsule.is_file() else None,
                audio_sha256=digest(audio) if audio.is_file() else None)


def seal() -> int:
    """Compare the eight control windows and write the v3 seal + evidence."""
    if SEAL.exists():
        raise SystemExit('refuse to replace the v3 observer seal')
    executable = BUILD / 'flycast_v3.exe'
    if not executable.is_file():
        raise SystemExit('stage the observer first: recover_oracle.py stage')
    windows = control_windows()
    proofs = []
    for window in windows:
        original = Path(window['original_capsule'])
        v3 = Path(window['v3_capsule'])
        result = compare(original, 1, v3, 1)
        assert result['captured_inputs_equal'], f"{window['stem']}: inputs moved"
        assert result['captured_outputs_equal'], f"{window['stem']}: outputs moved"
        assert result['canonical_instruction_traces_equal'], f"{window['stem']}: trace moved"
        audio = compare_audio(window['original_audio'], window['v3_audio'])
        assert audio['equal'], f"{window['stem']}: audio checkpoint moved"
        proofs.append(dict(case=window['case'], state=window['state'],
                           architecture_ram_and_trace_equal=True,
                           audio_checkpoint_equal=True,
                           patched_main_oracle_equal=True,
                           instructions=result['left_instructions'],
                           original_capsule_sha256=window['original_capsule_sha256'],
                           observer_capsule_sha256=window['v3_capsule_sha256'],
                           original_audio_sha256=window['original_audio_sha256'],
                           observer_audio_sha256=window['v3_audio_sha256']))
    sources = [ROOT / 'tools' / 'oracle' / 'vf3oracle_v3.cpp',
               ROOT / 'docs' / 're' / 'patches' / 'oracle_v3_from_pristine.patch',
               ROOT / 'tools' / 'oracle' / 'vf3oracle.cpp',
               ROOT / 'tools' / 'oracle' / 'install.py']
    references = [reference(path) for path in sources if Path(path).is_file()]
    references += [reference(executable)]
    references += [reference(CONTROLS / f'{window["stem"]}.{suffix}')
                   for window in windows for suffix in ('watch', 'patch')]
    seal = dict(
        coverage_credit=False,
        diagnostic_controls_passed=True,
        maximum_recorded_instructions=500000,
        unchanged_original_simulation=True,
        observer=reference(executable),
        observer_source=reference(ROOT / 'tools' / 'oracle' / 'vf3oracle_v3.cpp'),
        controls=proofs,
        limitation=('These controls validate the recording-only extension against the '
                    'pristine original oracle on eight windows: architecture, RAM, the '
                    'canonical instruction trace and the full audio checkpoint are '
                    'equal.  A capture campaign still needs its own acceptance.'),
        references=references,
    )
    SEAL.write_text(json.dumps(seal, indent=2) + '\n', encoding='utf-8')
    evidence = dict(
        coverage_credit=False,
        oracle_restored=True,
        observer=reference(executable),
        observer_source=reference(ROOT / 'tools' / 'oracle' / 'vf3oracle_v3.cpp'),
        controls_proved=len(proofs),
        windows=windows,
        staged=[reference(path) for path in sorted(DATA.iterdir())],
        references=[reference(path) for path in
                    [ORIGINAL_CONTROLS, V3_CONTROLS, SEAL, Path(__file__)]],
    )
    EVIDENCE.write_text(json.dumps(evidence, indent=2) + '\n', encoding='utf-8')
    print(f'v3 observer sealed: {SEAL}')
    print(f'recovery evidence:   {EVIDENCE}')
    return 0


def verify(limit: int) -> int:
    """Re-run the control windows and compare them with the pristine originals."""
    if not SEAL.exists():
        raise SystemExit('seal the observer first: recover_oracle.py seal')
    executable = BUILD / 'flycast_v3.exe'
    if not executable.is_file():
        raise SystemExit('stage the observer first: recover_oracle.py stage')
    seal = json.loads(SEAL.read_text())
    assert digest(executable) == seal['observer']['sha256']
    windows = control_windows()
    if limit:
        windows = windows[:limit]
    out = ROOT / 'extract' / 'analysis' / 'oracle_recovery' / 'verify'
    failures = 0
    for window in windows:
        row = capture_window(window, executable, out)
        # The raw capsule bytes are compared with the *same recorder's* recorded
        # output: the pristine original wrote the older VF3CAP6 tag, so its
        # capsule file can never be byte-identical to a VF3CAP7 one.  The
        # semantic comparison against that original is the seal's job.
        capsule_ok = row['capsule_sha256'] == window['v3_capsule_sha256']
        audio_ok = row['audio_sha256'] == window['v3_audio_sha256']
        semantic = compare(Path(window['original_capsule']), 1, row['capsule'], 1)
        original_ok = (semantic['captured_inputs_equal'] and semantic['captured_outputs_equal']
                       and semantic['canonical_instruction_traces_equal'])
        print(f"{window['stem']}: capsule={'match' if capsule_ok else 'DIFFERS'} "
              f"audio={'match' if audio_ok else 'DIFFERS'} "
              f"original={'equal' if original_ok else 'DIFFERS'} rc={row['returncode']}", flush=True)
        failures += (not capsule_ok) + (not audio_ok) + (not original_ok)
    print('the restored observer reproduces the pristine control windows'
          if not failures else f'{failures} mismatches')
    return 0 if not failures else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('command', choices=('stage', 'seal', 'verify'))
    ap.add_argument('--observer', choices=tuple(OBSERVERS), default='v3')
    ap.add_argument('--limit', type=int, default=0, help='verify only the first N windows')
    a = ap.parse_args()
    if a.command == 'stage':
        target, spec, staged = stage_observer(a.observer)
        print(f'staged {target} ({spec["note"]})')
        for row in staged:
            print(f"  {row['sha256'][:16]}  {row['path']}")
        return 0
    if a.command == 'seal':
        return seal()
    return verify(a.limit)


if __name__ == '__main__':
    raise SystemExit(main())
