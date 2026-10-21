"""Build the 500,000-instruction observer from the *current* patched oracle.

v1 of this recorder was built from the pristine oracle source, so it carried
neither the device-read policy nor the 1024-page RAM budget that
docs/re/oracle_device_reads.md added later.  A probe that touches a device
register or spreads over more than 128 pages was therefore rejected by the
recorder itself, and the corpus-less pool never got past the wall.

This build takes the live `tools/emu/flycast/core/vf3oracle.cpp` (the source
the main oracle is compiled from) and changes exactly two things:

  * the recorded instruction-vector bound   100000 -> 500000
  * the recorder format tag                  VF3CAP6 -> VF3CAP7

Everything else - the device-read policy, the page budget, the FPU handling
and the simulation itself - is inherited verbatim from the current oracle, so
the recorder differs from the main oracle only in how much it is willing to
remember.  Every input is pinned by digest in the manifest; the main oracle
and its objects are read-only here.
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
    for path in (source, pristine, patch):
        assert path.is_file(), f'missing {path}'
    text = source.read_text()
    assert text.count(OLD_BOUND) == 1, 'record bound marker not found exactly once'
    assert text.count('"VF3CAP6\\0"') == 1, 'format tag marker not found exactly once'
    extended = text.replace(OLD_BOUND, NEW_BOUND).replace('"VF3CAP6\\0"', '"VF3CAP7\\0"')

    directory = CACHE / 'capsule_extended_observer_v2_build'
    executable = CACHE / 'flycast_capsule_extended_v2.exe'
    assert not directory.exists() and not executable.exists(), 'refuse to replace the v2 observer'

    flags_path = BUILD / 'CMakeFiles/flycast.dir/flags.make'
    objects_path = BUILD / 'CMakeFiles/flycast.dir/objects1.rsp'
    includes_path = BUILD / 'CMakeFiles/flycast.dir/includes_CXX.rsp'
    libraries_path = BUILD / 'CMakeFiles/flycast.dir/linkLibs.rsp'
    objects = [(BUILD / path).resolve() for path in response_paths(objects_path)]
    replaced = [path for path in objects if path.name == 'vf3oracle.cpp.obj']
    assert len(replaced) == 1, 'the oracle object is not in the link line'
    libraries = [(BUILD / path).resolve() for path in response_paths(libraries_path)
                 if str(path).endswith('.a')]

    inputs = [source, pristine, patch, flags_path, objects_path, includes_path,
              libraries_path, BUILD / 'flycast.exe', *objects, *libraries]
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
        built_from='tools/emu/flycast/core/vf3oracle.cpp (device-read policy + 1024-page budget applied)',
        main_observer=reference(BUILD / 'flycast.exe'),
        pristine_oracle_source=reference(pristine),
        oracle_device_reads_patch=reference(patch),
        executable=reference(executable),
        replacement_scope=['recorder format tag', 'recorded instruction count bound'],
        unchanged_device_and_page_policy=True,
        unchanged_fpu_and_simulation=True,
        compile_command=command,
        link_command=link,
        references=[reference(path) for path in
                    [*inputs, changed_source, changed_object, response, archive, Path(__file__)]])
    (directory / 'manifest.json').write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'v2 extended observer built: {executable} (bound {RECORD_BOUND}, format VF3CAP7)')
    print('the main oracle and its objects were not modified; controls are still required')


if __name__ == '__main__':
    main()
