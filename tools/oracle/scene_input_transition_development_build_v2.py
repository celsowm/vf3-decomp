"""Build an isolated readable scene predicate for strict diagnostic replay."""
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    out = CACHE/'scene_input_transition_readable_dev_v2'
    out.mkdir(exist_ok=False)
    source = ROOT/'src/fight/matrix_family.c'
    text = source.read_text()
    marker = '    if(!vf3_fpu_supported(FPSCR)) return 0;'
    assert text.count(marker) == 1
    text = text.replace(marker, marker+'\n    if(entry==0x0c0993e0u) return vf3_scene_input_transition_c(s,ram);')
    marker = 'int vf3_matrix_family(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {'
    assert text.count(marker) == 1
    text = text.replace(marker, 'int vf3_scene_input_transition_c(vf3_matrix_state*,const vf3_ram_map*);\n'+marker)
    text = text.replace(marker, 'int vf3_scene_replay_transition_c(uint32_t,vf3_matrix_state*,const vf3_ram_map*);\n'+marker)
    text = text.replace('    if(!vf3_fpu_supported(FPSCR)) return 0;','    if(!vf3_fpu_supported(FPSCR)) return 0;\n    if(entry==0x0c099540u||entry==0x0c099560u) return vf3_scene_replay_transition_c(entry,s,ram);')
    copy = out/'matrix_family.c'
    copy.write_text(text)
    candidate = ROOT/'src/fight/scene_input_transition.c'
    helper = ROOT/'src/fight/scene_replay_transition.c'
    library = ROOT/'build/libvf3core.a'
    runner = ROOT/'build/CMakeFiles/vf3matrixfamily.dir/tests/matrix_family_replay.c.obj'
    executable = out/'vf3matrixfamily.exe'
    subprocess.run(['C:/msys64/ucrt64/bin/gcc.exe', '-O3', '-DNDEBUG', '-std=gnu99',
                    '-I'+str(ROOT/'src'), str(copy), str(candidate), str(helper), str(runner),
                    str(library), '-o', str(executable)], check=True)
    def ref(path):
        with path.open('rb') as stream:
            sha = hashlib.file_digest(stream, 'sha256').hexdigest()
        return dict(path=str(path), sha256=sha)
    (out/'manifest.json').write_text(json.dumps(dict(coverage_credit=False,
        isolated_development_only=True, references=[ref(p) for p in
        (source, copy, candidate, helper, library, runner, Path(__file__))],
        executable=ref(executable)), indent=2)+'\n')


if __name__ == '__main__':
    main()
