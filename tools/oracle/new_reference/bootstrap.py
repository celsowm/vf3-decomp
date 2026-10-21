#!/usr/bin/env python3
"""Fetch/build a new pinned passive Flycast reference, without global installs."""
import argparse
import hashlib
import json
import platform
from pathlib import Path
import shutil
import subprocess
import sys
from install import PIN, install

URL='https://github.com/flyinghead/flycast.git'
SUBMODULES=['core/deps/asio','core/deps/libchdr','core/deps/tinygettext']

def digest(path):
    with Path(path).open('rb') as f:
        return hashlib.file_digest(f,'sha256').hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--work-dir',type=Path,required=True)
    parser.add_argument('--jobs',type=int,default=4)
    parser.add_argument('--cache-bypass',action='store_true',help='Diagnostic non-strict control only; not architectural SH4 validation')
    a=parser.parse_args()
    if platform.system() not in ('Darwin','Linux'):
        parser.error('This bootstrap currently supports Darwin/Linux hosts; no Windows build is claimed.')
    root=a.work_dir.resolve(); root.mkdir(parents=True,exist_ok=True)
    if shutil.disk_usage(root).free<4*1024**3:
        parser.error('Fewer than 4 GiB free; refusing reference build')
    commands=[]
    def run(cmd,where=root,log=None):
        commands.append(dict(argv=[str(x) for x in cmd],cwd=str(where)))
        if log:
            with (root/log).open('wb') as f:
                subprocess.run(cmd,cwd=where,stdout=f,stderr=subprocess.STDOUT,check=True)
        else:
            subprocess.run(cmd,cwd=where,check=True)
    source=root/'flycast'; build=root/('build-bypass' if a.cache_bypass else 'build-strict')
    if not source.exists():
        run(['git','init',str(source)])
        run(['git','remote','add','origin',URL],source)
        run(['git','fetch','--depth','1','origin',PIN],source)
        run(['git','checkout','--detach',PIN],source)
    actual=subprocess.check_output(['git','rev-parse','HEAD'],cwd=source,text=True).strip()
    if actual!=PIN:
        parser.error(f'Existing checkout is {actual}; expected {PIN}, refusing reset')
    run(['git','submodule','update','--init','--depth','1',*SUBMODULES],source)
    run(['git','submodule','update','--init','--recursive','--depth','1'],source/'core/deps/tinygettext')
    install(source)
    cmake=['cmake','-S',str(source),'-B',str(build),'-G','Ninja','-DLIBRETRO=ON',
        '-DCMAKE_BUILD_TYPE=Release','-DUSE_OPENGL=OFF','-DUSE_VULKAN=OFF','-DUSE_DX9=OFF',
        '-DUSE_DX11=OFF','-DUSE_LUA=OFF','-DUSE_BREAKPAD=OFF','-DUSE_OPENMP=OFF',
        '-DUSE_HOST_LIBZIP=OFF','-DENABLE_LOG=OFF','-DCMAKE_C_COMPILER_LAUNCHER=',
        '-DCMAKE_CXX_COMPILER_LAUNCHER=', '-DVF3_REFERENCE_STRICT='+('OFF' if a.cache_bypass else 'ON')]
    if platform.system()=='Darwin': cmake.append('-DCMAKE_OSX_ARCHITECTURES='+platform.machine())
    run(cmake,log='configure.log')
    run(['cmake','--build',str(build),'--target','flycast_libretro','-j',str(max(1,min(a.jobs,8)))],log='build.log')
    library=build/('flycast_libretro.dylib' if platform.system()=='Darwin' else 'flycast_libretro.so')
    driver=build/'vf3-reference'
    compiler=shutil.which('clang++') or shutil.which('c++')
    here=Path(__file__).resolve().parent
    run([compiler,'-std=c++17',str(here/'driver.cpp'),'-I'+str(source/'core/deps/libretro-common/include'),
         str(library),'-Wl,-rpath,'+str(build),'-o',str(driver)],log='driver-build.log')
    patch=subprocess.check_output(['git','diff','--binary'],cwd=source)
    (root/'flycast-overlay.patch').write_bytes(patch)
    files=[library,driver,build/'CMakeCache.txt',root/'flycast-overlay.patch',
           *sorted(here.glob('*.py')),*sorted(here.glob('*.cpp')),*sorted(here.glob('*.h'))]
    manifest=dict(schema='vf3-new-reference-build-v1',historical_seal_reproduced=False,
        source_url=URL,commit=PIN,driver_path=str(driver),host=dict(system=platform.system(),machine=platform.machine()),
        policy=dict(sh4='interpreter',bios='HLE',renderer='null',threaded=False,guest_patch=False,
                    protected_sdk_import=False,coverage_credit=False,strict_mode=not a.cache_bypass,
                    target_no_rec=not a.cache_bypass),
        submodules=subprocess.check_output(['git','submodule','status','--recursive'],cwd=source,text=True).splitlines(),
        commands=commands,compiler=subprocess.check_output([compiler,'--version'],text=True),
        files=[dict(path=str(p),sha256=digest(p),bytes=p.stat().st_size) for p in files])
    (root/'build-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(driver)

if __name__=='__main__': main()
