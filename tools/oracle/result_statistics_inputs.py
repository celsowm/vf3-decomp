"""Standalone diagnostic inputs for the unfrozen result-statistics leaf helper."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c09d138'


def main():
    name='coverage_65_result_statistics_dev_v1';base=ROOT/'tools/oracle';inputs=base/'percentage_inputs'
    fields=copy.deepcopy(json.loads((inputs/'coverage_65_scene_round_decision_dev_v1_memory.json').read_text())['0x8c098c62'])
    fields['0xc29bcec']=[v<<8 for v in [1,2,3,3]*64]
    fields['0xc29bcdc']=[v<<8 for v in [0,1,2,1]*64]
    fields['0xc29bcdc']=[v|((i%3)<<0) for i,v in enumerate(fields['0xc29bcdc'])]
    fields['0xc29be88']=[0xc1fefe4,0xc20138c]*128 # scene +0x1c4 winner
    fields['0xc1ff044']=[((i//4)%13)<<8 for i in range(256)] # actor +97 character
    fields['0xc2013ec']=[((i//8)%13)<<8 for i in range(256)]
    fields['0xc10baa0']=[0xffffffff,0,1,0]*64
    for char in range(13):
        fields[hex(0xc2cf888+4*char)]={'values':[0,998,999,1000],'phase':char}
        fields[hex(0xc2cf8bc+4*char)]={'values':[0,997,999,1001],'phase':char}
        for offset in (0x2e8,0x31c,0xb70):
            fields[hex(0xc11e8b0+offset+4*char)]={'values':[0,0x3f800000,0x44798000,0x4479c000],'phase':char}
        for offset in (0x350,0x384,0x3b8):
            fields[hex(0xc11e8b0+offset+4*char)]={'values':[0,998,999,1000],'phase':char}
        for peer in range(13):
            for offset in (0x3ec,0x690):
                fields[hex(0xc11e8b0+offset+4*(char*13+peer))]={'values':[0,0x3f800000,0x4479c000,0x447a0000],'phase':char+peer}
    registers={ENTRY:dict(r4=0xc400000)}
    paths=[base/f'{name}_watch.txt',inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(p.exists() for p in paths)
    paths[0].write_text('pc '+ENTRY+'\n')
    for path,data in zip(paths[1:3],({ENTRY:fields},registers)):path.write_text(json.dumps(data,indent=2)+'\n')
    generate(paths[0],paths[3],0x8c0432e2,256,fpscr=0x40001,bounded_arguments=True,
        preserve_fields=True,register_overrides=registers,memory_overrides={ENTRY:fields})


if __name__=='__main__':main()
