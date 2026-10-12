"""Run four scene acceptance campaigns against the unchanged original observer."""
import json
from pathlib import Path
import subprocess
import sys
from ram_clipping_batch_audit import digest

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def main():
    inputs=ROOT/'tools/oracle/coverage_65_scene_batch_accept_input_manifest_v1.json'
    held=json.loads(inputs.read_text());frozen=Path(held['development_freeze']['path'])
    assert digest(frozen)==held['development_freeze']['sha256']
    development=json.loads(frozen.read_text());assert development['qualified_development_only']
    assert inputs.stat().st_mtime_ns>=frozen.stat().st_mtime_ns
    for row in [*development['references'],*held['files'],*held['original_states']]:assert digest(row['path'])==row['sha256']
    observer=CACHE/'flycast_task_return_boundary_v1.exe'
    assert digest(observer)=='b84119778244e85e247a85481900a0de9f9b11e99dd0b85830136942bf2fb3c2'
    for group in held['groups']:
        name=group['name'];out=CACHE/(name+'_export');raw=CACHE/(name+'_raw')
        assert not out.exists() and not raw.exists()
        print('Starting original acceptance '+name,flush=True)
        subprocess.run([sys.executable,str(ROOT/'tools/golden_batch.py'),'--name',name,
            '--watch',str(ROOT/f'tools/oracle/{name}_watch.txt'),'--out',str(out),'--trace-dir',str(raw),
            '--emulator',str(observer),'--entry-patch',str(ROOT/f'extract/analysis/{name}.patch'),
            '--capsule','--probe-only','--probe-debug','--probe-ops','100000','--max-samples','256','--timeout','500',
            '--run','s45:tools/emu/flycast-build/data/vf3_45.state::4000',
            '--run','s46:tools/emu/flycast-build/data/vf3_46.state::4000'],cwd=ROOT,check=True)
    print('All scene original acceptance campaigns terminal; full acceptance audit still required',flush=True)


if __name__=='__main__':main()
