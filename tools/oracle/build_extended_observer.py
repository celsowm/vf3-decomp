"""Build a separate larger-record observer from unchanged original linked objects.

Only the recorder's format tag and instruction-vector bound change. Existing
objects, emulator sources, FPU code and the original executable are read-only.
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


def response_paths(path):
    return [Path(value.strip('"')) for value in shlex.split(path.read_text(), posix=False)]


def main():
    baseline = CACHE / 'task_return_boundary_v1_linked_sources/manifest.json'
    original = json.loads(baseline.read_text())
    assert digest(original['executable']) == digest(BUILD / 'flycast.exe') == original['sha256']
    assert original['sha256'] == 'b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
    for row in original['files']:
        assert digest(ROOT / row['path']) == row['sha256'], 'original linked source changed'
        assert digest(baseline.parent / row['path']) == row['sha256'], 'original source archive changed'
    source = ROOT / 'tools/emu/flycast/core/vf3oracle.cpp'
    text = source.read_text()
    assert text.count('c.ops.size()<100000') == 1 and text.count('"VF3CAP6\\0"') == 1
    extended = text.replace('c.ops.size()<100000', 'c.ops.size()<500000').replace('"VF3CAP6\\0"', '"VF3CAP7\\0"')
    directory = CACHE / 'capsule_extended_observer_v1_build'
    executable = CACHE / 'flycast_capsule_extended_v1.exe'
    assert not directory.exists() and not executable.exists()
    flags_path = BUILD / 'CMakeFiles/flycast.dir/flags.make'
    objects_path = BUILD / 'CMakeFiles/flycast.dir/objects1.rsp'
    includes_path = BUILD / 'CMakeFiles/flycast.dir/includes_CXX.rsp'
    libraries_path = BUILD / 'CMakeFiles/flycast.dir/linkLibs.rsp'
    objects = [(BUILD / path).resolve() for path in response_paths(objects_path)]
    replaced = [path for path in objects if path.name == 'vf3oracle.cpp.obj']
    assert len(replaced) == 1
    libraries = [(BUILD / path).resolve() for path in response_paths(libraries_path)
                 if str(path).endswith('.a')]
    inputs = [baseline, source, flags_path, objects_path, includes_path, libraries_path,
              BUILD / 'flycast.exe', Path(original['executable']), *objects, *libraries,
              *[ROOT / row['path'] for row in original['files']]]
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
               '-MD', '-MF', str(directory/'vf3oracle.cpp.obj.d'), '-c', str(changed_source), '-o', str(changed_object)]
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
        assert digest(path) == expected_hash, 'original build dependency changed'
    manifest = dict(coverage_credit=False, diagnostic_observer_only=True, format='VF3CAP7',
        maximum_recorded_instructions=500000, original_observer=reference(original['executable']),
        executable=reference(executable), original_linked_sources=reference(baseline),
        replacement_scope=['recorder format tag', 'recorded instruction count bound'],
        unchanged_fpu_and_simulation=True, compile_command=command, link_command=link,
        references=[reference(path) for path in [*inputs, changed_source, changed_object, response, archive, Path(__file__)]])
    (directory / 'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print('Separate extended observer built; original linked objects unchanged; controls still required')


if __name__ == '__main__':
    main()
