"""Build the v3 observer: the v2 recorder plus the per-specimen drive-state record.

v2 (tools/oracle/build_extended_observer_v2.py) took the live oracle source and
raised only the recorded-instruction bound and the capsule format tag.  It still
logged the REIOS drive state (`VF3_GDLOG`) only at the *natural* watch arm, so a
specimen reached through a synthetic redirect (`VF3_ENTRY_PATCH`) carried its
drive state at the exit but not at the entry - and the entry state is what the
port needs to answer `GDROM_REQ_CMD` (the drive has to be GDC_OK for the
command to be accepted, and the request id it returns is the counter the drive
carries at that moment).

v3 therefore adds one line to the synthetic arm:

    logGd('S', c.id, c.entry);

Everything else - the device-read policy, the 1024-page RAM budget, the FPU
handling and the simulation itself - is inherited verbatim from the current
oracle, and the main oracle's binary and objects are left untouched.

    python tools/oracle/build_extended_observer_v3.py
"""
import json
from pathlib import Path
import re
import shlex
import subprocess
from ram_clipping_batch_audit import digest, reference

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')
BUILD = ROOT / 'tools/emu/flycast-build'

RECORD_BOUND = 500000
OLD_BOUND = 'c.ops.size()<100000'
NEW_BOUND = f'c.ops.size()<{RECORD_BOUND}'


def response_paths(path):
    return [Path(value.strip('"')) for value in shlex.split(path.read_text(), posix=False)]


def main():
    source = ROOT / 'tools/emu/flycast/core/vf3oracle.cpp'
    pristine = ROOT / 'tools/oracle/vf3oracle.cpp'
    patch = ROOT / 'docs/re/patches/oracle_device_reads.patch'
    drive_state_patch = ROOT / 'docs/re/patches/oracle_drive_state.patch'
    for path in (source, pristine, patch, drive_state_patch):
        assert path.is_file(), f'missing {path}'
    text = source.read_text()
    assert text.count(OLD_BOUND) == 1, 'record bound marker not found exactly once'
    assert text.count('"VF3CAP6\\0"') == 1, 'format tag marker not found exactly once'
    # The synthetic arm must carry the drive-state record, otherwise a redirected
    # specimen has no entry state at all.
    assert text.count("logGd('S', c.id, c.entry);") == 2, \
        'the synthetic arm does not log the drive state'
    extended = text.replace(OLD_BOUND, NEW_BOUND).replace('"VF3CAP6\\0"', '"VF3CAP7\\0"')

    directory = CACHE / 'capsule_extended_observer_v3_build'
    executable = CACHE / 'flycast_capsule_extended_v3.exe'
    assert not directory.exists() and not executable.exists(), 'refuse to replace the v3 observer'

    flags_path = BUILD / 'CMakeFiles/flycast.dir/flags.make'
    objects_path = BUILD / 'CMakeFiles/flycast.dir/objects1.rsp'
    includes_path = BUILD / 'CMakeFiles/flycast.dir/includes_CXX.rsp'
    libraries_path = BUILD / 'CMakeFiles/flycast.dir/linkLibs.rsp'
    objects = [(BUILD / path).resolve() for path in response_paths(objects_path)]
    replaced = [path for path in objects if path.name == 'vf3oracle.cpp.obj']
    assert len(replaced) == 1, 'the oracle object is not in the link line'
    libraries = [(BUILD / path).resolve() for path in response_paths(libraries_path)
                 if str(path).endswith('.a')]

    inputs = [source, pristine, patch, drive_state_patch, flags_path, objects_path,
              includes_path, libraries_path, BUILD / 'flycast.exe', *objects, *libraries]
    expected = {str(path): digest(path) for path in inputs}

    directory.mkdir()
    changed_source = directory / 'vf3oracle.cpp'
    changed_source.write_text(extended)
    changed_object = directory / 'vf3oracle.cpp.obj'
    flags = flags_path.read_text()
    definitions = re.search(r'^CXX_DEFINES = (.*)$', flags, re.M).group(1).split()
    options = re.search(r'^CXX_FLAGS = (.*)$', flags, re.M).group(1).split()
    compiler = 'C:/msys64/ucrt64/bin/c++.exe'
    command = [compiler, *definitions, '@'+str(includes_path), *options,
               '-MD', '-MF', str(directory/'vf3oracle.cpp.obj.d'), '-c',
               str(changed_source), '-o', str(changed_object)]
    subprocess.run(command, cwd=BUILD, check=True)
    response = directory / 'objects.rsp'
    response.write_text(' '.join('"'+str(changed_object if path == replaced[0] else path).replace('\\','/')+'"' for path in objects))
    archive = directory / 'objects.a'
    subprocess.run(['C:/msys64/ucrt64/bin/ar.exe', 'qc', str(archive), '@'+str(response)], cwd=BUILD, check=True)
    link = [compiler, '-DVF3_HEADLESS', '-DVF3_ALWAYS_INTERPRETER', '-O2', '-g', '-DNDEBUG',
            '-mconsole', '-mwindows', '-fopenmp', '-static', '-Wl,--whole-archive', str(archive),
            '-Wl,--no-whole-archive', '-o', str(executable), '@'+str(libraries_path)]
    subprocess.run(link, cwd=BUILD, check=True)
    for path, expected_hash in expected.items():
        assert digest(path) == expected_hash, 'build dependency changed during the build'

    manifest = dict(
        coverage_credit=False,
        diagnostic_observer_only=True,
        format='VF3CAP7',
        maximum_recorded_instructions=RECORD_BOUND,
        built_from='tools/emu/flycast/core/vf3oracle.cpp (device-read policy + 1024-page budget + synthetic-arm drive-state record)',
        main_observer=reference(BUILD / 'flycast.exe'),
        pristine_oracle_source=reference(pristine),
        oracle_device_reads_patch=reference(patch),
        oracle_drive_state_patch=reference(drive_state_patch),
        executable=reference(executable),
        replacement_scope=['recorder format tag', 'recorded instruction count bound',
                           'drive-state record at the synthetic arm'],
        unchanged_device_and_page_policy=True,
        unchanged_fpu_and_simulation=True,
        compile_command=command,
        link_command=link,
        references=[reference(path) for path in
                    [*inputs, changed_source, changed_object, response, archive, Path(__file__)]])
    (directory / 'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'v3 extended observer built: {executable} (bound {RECORD_BOUND}, format VF3CAP7)')
    print('the main oracle and its objects were not modified; controls are still required')


if __name__ == '__main__':
    main()
