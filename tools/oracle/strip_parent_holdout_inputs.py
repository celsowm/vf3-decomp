"""Prepare disjoint strip inputs only after complete integrated development."""
import hashlib
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]
CACHE=Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def digest(path):
    with Path(path).open('rb') as handle:return hashlib.file_digest(handle,'sha256').hexdigest()


def bits(value):return struct.unpack('<I',struct.pack('<f',value))[0]
def number(value):return struct.unpack('<f',struct.pack('<I',value))[0]
def relocated(value):return value+0x100000 if 0xc400000<=value<0xc480000 else value


def prepare():
    name='coverage_65_strip_parent_accept_v1';prior='coverage_65_strip_parent_screen_v3'
    frozen=CACHE/'strip_parent_qualified_development_freeze_v1.json'
    proof=json.loads(frozen.read_text())
    assert proof['qualified_development_only'] and proof['compiled_inputs']==400
    for ref in proof['references']:assert digest(ref['path'])==ref['sha256'],'changed complete development evidence'
    base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    old=json.loads((inputs/f'{prior}_memory.json').read_text());oldregs=json.loads((inputs/f'{prior}_registers.json').read_text())
    memory={};registers={}
    for entry,fields in old.items():
        new={}
        for address,value in fields.items():
            at=int(address,16)
            if isinstance(value,list):value=value[17:]+value[:17]
            elif isinstance(value,dict):value={**value,'phase':value.get('phase',0)+3}
            if 0xc430000<=at<0xc430080 and at%16 in (0,4):
                value=[bits(number(x)+11/32) for x in value]
            elif 0xc430000<=at<0xc430080 and at%16==8:
                value={**value,'values':[bits(.375),bits(1.75)]}
            if isinstance(value,int):value=relocated(value)
            elif isinstance(value,list):value=[relocated(x) for x in value]
            elif isinstance(value,dict):value={**value,'values':[relocated(x) for x in value['values']]}
            new[hex(relocated(at))]=value
        memory[entry]=new
        registers[entry]={reg:relocated(value) for reg,value in oldregs[entry].items()}
        registers[entry].update(r10=bits(1.125),fr3=bits(1/1024))
    paths=[base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    manifest=base/f'{name}_input_manifest.json'
    assert not any(path.exists() for path in [*paths,manifest]),'refuse to overwrite held-out inputs'
    paths[0].write_text((base/f'{prior}_watch.txt').read_text());paths[1].write_text((base/f'{prior}_owners.json').read_text())
    for path,data in zip(paths[2:4],(memory,registers)):path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,256,fpscr=0x40001,bounded_arguments=True,preserve_fields=True,register_overrides=registers,memory_overrides=memory)
    manifest.write_text(json.dumps(dict(coverage_credit=False,development_freeze={'path':str(frozen),'sha256':digest(frozen)},
        original_states=[str(CACHE/'data/vf3_45.state'),str(CACHE/'data/vf3_46.state')],
        files=[{'path':str(path.resolve()),'sha256':digest(path)} for path in paths],
        hypothesis='Disjoint owned buffers, strip phases, finite positions/depths and thresholds; original initialized contexts and all code/pools remain intact.'),indent=2)+'\n')


if __name__=='__main__':prepare()
