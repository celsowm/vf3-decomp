"""Original strip-parent followup: independent winding, depth and two strips.

States 28/29 retain the original initialized bank3 publication pointer.
Inputs confer no coverage credit and never alter instructions or pools.
"""
import json
from pathlib import Path
import struct
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def prepare():
    name, prior, count = 'coverage_65_strip_parent_screen_v3', 'coverage_65_strip_parent_screen_v2', 256
    base = ROOT/'tools/oracle'; inputs = base/'percentage_inputs'
    memory = json.loads((inputs/f'{prior}_memory.json').read_text())
    registers = json.loads((inputs/f'{prior}_registers.json').read_text())
    owners = json.loads((base/f'{prior}_owners.json').read_text())
    for entry, fields in memory.items():
        stride = 6 if int(entry,16) in (0x8c057480,0x8c057c60) else 10 if int(entry,16)==0x8c057fa0 else 2
        packed = []
        for variant in range(count):
            data = bytearray(256); vertices = 3+variant%6; strips = 1+(variant//128)%2
            struct.pack_into('<HH',data,4,strips,(-vertices if variant//8%2 else vertices)&65535)
            offset = 8
            for strip in range(strips):
                if strip:
                    struct.pack_into('<H',data,offset,(-vertices if variant//16%2 else vertices)&65535); offset += 2
                for index in range(vertices):
                    struct.pack_into('<H',data,offset,index)
                    if stride>=6: struct.pack_into('<I',data,offset+2,bits((index+1)/8))
                    if stride==10: struct.pack_into('<I',data,offset+6,bits((index+1)/16))
                    offset += stride
            packed.append(data)
        for offset in range(4,256,4):
            fields[hex(0xc400000+offset)] = [struct.unpack_from('<I',data,offset)[0] for data in packed]
        for index in range(8):
            fields[hex(0xc430000+16*index)] = [bits(((v*(index*2+3)+index*5)%11)-5) for v in range(count)]
            fields[hex(0xc430004+16*index)] = [bits(((v*(index*4+5)+index*3)%13)-6) for v in range(count)]
            fields[hex(0xc430008+16*index)] = {'values':[bits(.25),bits(2)],'stride':1<<index,'phase':index}
    paths = [base/f'{name}_watch.txt',base/f'{name}_owners.json',inputs/f'{name}_memory.json',inputs/f'{name}_registers.json',ROOT/f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths), 'refuse to overwrite original screening inputs'
    paths[0].write_text((base/f'{prior}_watch.txt').read_text())
    for path, value in zip(paths[1:4],(owners,memory,registers)):
        path.write_text(json.dumps(value,indent=2)+'\n')
    generate(paths[0],paths[4],0x8c0432e2,count,fpscr=0x40001,bounded_arguments=True,preserve_fields=True,register_overrides=registers,memory_overrides=memory)


if __name__=='__main__': prepare()
