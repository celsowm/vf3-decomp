"""Build an isolated selection candidate without changing the frozen strip build."""
import hashlib
import json
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    out=CACHE/'selection_unlock_readable_dev_v1'
    out.mkdir(exist_ok=False)
    source=ROOT/'src/fight/matrix_family.c'
    text=source.read_text()
    marker='    if(!vf3_fpu_supported(FPSCR)) return 0;'
    assert text.count(marker)==1
    text=text.replace(marker,marker+'\n    if(entry==0x0c0c3210u) return vf3_selection_unlock_c(s,ram);')
    marker='int vf3_matrix_family(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {'
    text=text.replace(marker,'int vf3_selection_unlock_c(vf3_matrix_state*,const vf3_ram_map*);\n'+marker)
    copy=out/'matrix_family.c';copy.write_text(text)
    candidate=ROOT/'src/fight/selection_unlock.c'
    gcc='C:/msys64/ucrt64/bin/gcc.exe'
    subprocess.run([gcc,'-O3','-DNDEBUG','-std=gnu99','-I'+str(ROOT/'src'),
        str(copy),str(candidate),str(ROOT/'build/CMakeFiles/vf3matrixfamily.dir/tests/matrix_family_replay.c.obj'),
        str(ROOT/'build/libvf3core.a'),'-o',str(out/'vf3matrixfamily.exe')],check=True)
    def ref(path):
        with path.open('rb') as stream:sha=hashlib.file_digest(stream,'sha256').hexdigest()
        return dict(path=str(path),sha256=sha)
    files=[source,copy,candidate,ROOT/'build/libvf3core.a',
        ROOT/'build/CMakeFiles/vf3matrixfamily.dir/tests/matrix_family_replay.c.obj',Path(__file__)]
    (out/'manifest.json').write_text(json.dumps(dict(coverage_credit=False,
        isolated_development_only=True,references=[ref(path) for path in files],
        executable=ref(out/'vf3matrixfamily.exe')),indent=2)+'\n')


if __name__=='__main__':main()
