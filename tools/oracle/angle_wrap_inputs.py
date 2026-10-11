"""Finite angle triples spanning every original wrapping threshold."""
import json
import struct
from pathlib import Path
from tenpp_probe_plan import generate
ROOT=Path(__file__).resolve().parents[2]
ENTRY='0x8c09f6fc'
def bits(value):
    return struct.unpack('<I',struct.pack('<f',value))[0]
def prepare():
    for holdout,label in [(False,'dev'),(True,'accept')]:
        target=0x0c510000 if holdout else 0x0c410000
        current=target+0x1000
        palette=[0,100,32768,32770,-32768,-32770,65530,-65530,65536,-65536,131080,-131080,655360,-655360,700000,-700000]
        if holdout:palette=[1,-101,32767,32769,-32767,-32769,65531,-65531,65537,-65537,196620,-196620,655361,-655361,800000,-800000]
        memory={ENTRY:{}}
        for axis in range(3):
            memory[ENTRY][hex(target+axis*4)]=[bits((i//16)*3.25+axis) for i in range(64)]
            memory[ENTRY][hex(current+axis*4)]=[bits((i//16)*3.25+axis-palette[(i+axis*5)%16]) for i in range(64)]
        registers={ENTRY:{'r4':target,'r5':current}}
        name=f'coverage_65_angle_wrap_{label}_v1'
        for kind,data in [('memory',memory),('registers',registers)]:
            (ROOT/f'tools/oracle/percentage_inputs/{name}_{kind}.json').write_text(json.dumps(data,indent=2)+'\n')
        generate(ROOT/'tools/oracle/coverage_65_angle_wrap_watch_v1.txt',ROOT/f'extract/analysis/{name}.patch',0x8c0432e2,64,
                 relocation=0x100000 if holdout else 0,fpscr=0x240001 if holdout else 0x40001,
                 bounded_arguments=True,preserve_fields=True,holdout_inputs=holdout,
                 memory_overrides=memory,register_overrides=registers)
if __name__=='__main__':prepare()
