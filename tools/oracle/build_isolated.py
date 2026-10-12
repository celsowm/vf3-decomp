"""Build routed readable C candidates or a memory diagnostic in a fresh directory."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[2]
ROUTE_MARKER='    if(!vf3_fpu_supported(FPSCR)) return 0;'
FUNCTION_MARKER='int vf3_matrix_family(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {'


def sha(path):
    with Path(path).open('rb') as stream:return hashlib.file_digest(stream,'sha256').hexdigest()


def route_source(text, routes):
    if text.count(ROUTE_MARKER)!=1 or text.count(FUNCTION_MARKER)!=1:
        raise ValueError('matrix dispatcher markers changed; review insertion points')
    declarations=[];branches=[];owned=set()
    for route in routes:
        symbol=route['function']
        if not re.fullmatch(r'[A-Za-z_]\w*',symbol):raise ValueError('invalid C function identifier')
        values=[int(value,0) if isinstance(value,str) else value for value in route['entries']]
        if any(not isinstance(value,int) or isinstance(value,bool) or not 0<=value<=0xffffffff for value in values):
            raise ValueError('routed entries must be uint32 addresses')
        entries=[value&0x1fffffff for value in values]
        if not entries or len(entries)!=len(set(entries)) or owned.intersection(entries):
            raise ValueError('empty or duplicate routed entries')
        owned.update(entries)
        entry_argument=route.get('entry_argument',False)
        if not isinstance(entry_argument,bool):raise ValueError('entry_argument must be boolean')
        declarations.append(f'int {symbol}('+('uint32_t,' if entry_argument else '')+'vf3_matrix_state*,const vf3_ram_map*);')
        condition='||'.join(f'entry==0x{entry:08x}u' for entry in entries)
        arguments='entry,s,ram' if entry_argument else 's,ram'
        branches.append(f'    if({condition}) return {symbol}({arguments});')
    text=text.replace(FUNCTION_MARKER,'\n'.join(declarations)+'\n'+FUNCTION_MARKER)
    return text.replace(ROUTE_MARKER,ROUTE_MARKER+'\n'+'\n'.join(branches))


def diagnostic_header(text):
    marker='if (memcmp(m->shadow[i], m->expect[i], m->wins[i].len) != 0) {'
    if text.count(marker)!=1:raise ValueError('memory comparator marker changed')
    extra='''
            fprintf(stderr,"DIAG window %d base %08x got ",i,m->wins[i].base);
            for(unsigned j=0;j<16 && j<m->wins[i].len;j++) fprintf(stderr,"%02x",m->shadow[i][j]);
            fprintf(stderr," expected ");
            for(unsigned j=0;j<16 && j<m->wins[i].len;j++) fprintf(stderr,"%02x",m->expect[i][j]);
            fputc(10,stderr);'''
    return text.replace(marker,marker+extra)


def build(config_path, output, build_dir, memory_diagnostic=False):
    output=Path(output).resolve();build_dir=Path(build_dir).resolve()
    if output.exists():raise FileExistsError('refusing to replace an isolated executable or its inputs')
    config=json.loads(Path(config_path).read_text()) if config_path else dict(routes=[],sources=[])
    sources=[(ROOT/Path(value)).resolve() for value in config.get('sources',[])]
    if any(not source.is_file() for source in sources):raise FileNotFoundError('candidate source missing')
    matrix=ROOT/'src/fight/matrix_family.c'
    text=route_source(matrix.read_text(),config.get('routes',[]))
    cache=(build_dir/'CMakeCache.txt').read_text()
    match=re.search(r'^CMAKE_C_COMPILER:[^=]+=(.+)$',cache,re.M)
    if not match:raise ValueError('configured C compiler missing')
    compiler=Path(match[1].strip())
    if compiler.stem not in ('gcc','clang','cc'):raise ValueError('requires the configured GCC or Clang compiler')
    library=build_dir/'libvf3core.a'
    runner=ROOT/'tests/matrix_family_replay.c'
    header=ROOT/'tests/port_harness.h'
    inputs=[matrix,library,runner,header,*sources,Path(__file__)]
    if config_path:inputs.append(Path(config_path).resolve())
    expected={str(path):sha(path) for path in inputs}
    output.mkdir(parents=True)
    copied=[]
    for index,source in enumerate(sources):
        destination=output/f'candidate_{index}.c';shutil.copyfile(source,destination);copied.append(destination)
    library_copy=output/'libvf3core.a';shutil.copyfile(library,library_copy)
    matrix_copy=output/'matrix_family.c';matrix_copy.write_text(text)
    runner_copy=output/'matrix_family_replay.c';shutil.copyfile(runner,runner_copy)
    header_copy=output/'port_harness.h'
    header_copy.write_text(diagnostic_header(header.read_text()) if memory_diagnostic else header.read_text())
    executable=output/'vf3matrixfamily.exe'
    include=['-I'+str(ROOT/'src'),'-I'+str(ROOT/'tests')]
    include += ['-I'+str(parent) for parent in sorted({p.parent for p in sources})]
    commands=[];objects=[];dependencies=set()
    for index,source in enumerate([matrix_copy,*copied,runner_copy]):
        obj=output/f'unit_{index}.o';dep=output/f'unit_{index}.d'
        command=[str(compiler),'-O3','-DNDEBUG','-std=c99',*include,'-MMD','-MF',str(dep),'-c',str(source),'-o',str(obj)]
        subprocess.run(command,cwd=ROOT,check=True);commands.append(command);objects.append(obj)
        dependency_text=re.sub(r'\\\r?\n',' ',dep.read_text())
        for name in re.findall(r'[A-Za-z]:[\\/](?:\\[ \t]|[^\s])+',dependency_text):
            path=Path(name.replace('\\ ',' ').replace('\\','/')).resolve()
            if path.is_file() and not path.is_relative_to(output):dependencies.add(path)
    command=[str(compiler),*[str(p) for p in objects],str(library_copy),'-lm','-o',str(executable)]
    subprocess.run(command,cwd=ROOT,check=True);commands.append(command)
    if any(sha(path)!=digest for path,digest in expected.items()):raise ValueError('build inputs changed during linking')
    generated=[matrix_copy,runner_copy,header_copy,library_copy,*copied]
    for index,path in enumerate(sorted(dependencies)):
        destination=output/'dependencies'/str(index)/path.name
        destination.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,destination)
        digest=sha(path)
        if sha(destination)!=digest:raise ValueError('dependency changed while archiving')
        expected.setdefault(str(path),digest);generated.append(destination)
    manifest=dict(coverage_credit=False,isolated_development_only=True,memory_diagnostic=memory_diagnostic,
        commands=commands,inputs=[dict(path=path,sha256=digest) for path,digest in expected.items()],
        archived_inputs=[dict(path=str(path),sha256=sha(path)) for path in generated],
        executable=dict(path=str(executable),sha256=sha(executable)))
    (output/'manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    return executable


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--config',type=Path,help='JSON routes and candidate sources; omit for the existing dispatcher')
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--build',type=Path,default=ROOT/'build')
    parser.add_argument('--memory-diagnostic',action='store_true',help='print failing RAM windows while retaining strict comparisons')
    args=parser.parse_args()
    print(build(args.config,args.out,args.build,args.memory_diagnostic))


if __name__=='__main__':main()
