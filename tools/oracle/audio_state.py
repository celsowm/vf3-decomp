"""Inspect the pinned Windows/x64 VF3 audio checkpoint layout.

Register key bits describe requested state, not whether a hardware voice is
currently audible. This reader earns no coverage or driver-protocol credit.
"""
import argparse
import hashlib
import json
import struct
import zlib
from pathlib import Path
from audio_determinism import checkpoints, sha

ARAM_OFFSET = 969
ARAM_BYTES = 0x200000
REG_OFFSET = ARAM_OFFSET + ARAM_BYTES + 16
CHANNEL_STATE_OFFSET = REG_OFFSET + 0x8000
CHANNEL_STATE_BYTES = 72
BLOCK_BYTES = (2137886, 2137930)
FORMAT = ('pcm16','pcm8','adpcm','adpcm_stream')


def digest(data):
    return dict(bytes=len(data), crc32=f'{zlib.crc32(data):08x}',
                sha256=hashlib.sha256(data).hexdigest())


def inspect(data):
    if len(data) not in BLOCK_BYTES or struct.unpack_from('<2I',data) != (854,0x1000000):
        raise ValueError('unsupported pinned AICA serializer layout')
    wave = data[ARAM_OFFSET:ARAM_OFFSET+ARAM_BYTES]
    regs = data[REG_OFFSET:REG_OFFSET+0x8000]
    channels = []
    for slot in range(64):
        offset = slot*128
        words = struct.unpack_from('<10I',regs,offset)
        control = words[0]
        fmt = (control>>7)&3
        address = (((control&127)<<16)|(words[1]&65535))&0x1fffff
        if fmt==0: address &= ~1
        runtime=CHANNEL_STATE_OFFSET+slot*CHANNEL_STATE_BYTES
        sample_base, sample_position, step=struct.unpack_from('<3I',data,runtime)
        if data[runtime+71] not in (0,1):
            raise ValueError('invalid pinned channel enabled byte')
        channels.append(dict(slot=slot, sample_address=f'0x{address:06x}',
            format=FORMAT[fmt], loop=bool(control&0x200),
            enabled=bool(data[runtime+71]), runtime_sample_address=f'0x{sample_base:06x}',
            sample_position=sample_position, step_fixed_22_10=step,
            key_on_request=bool(control&0x4000), key_execute=bool(control&0x8000),
            loop_start=words[2]&65535, loop_end=words[3]&65535,
            pitch_fraction=words[6]&1023, pitch_octave_bits=(words[6]>>11)&15,
            pan_bits=words[9]&31, direct_level=(words[9]>>8)&15,
            bank_region='baseline' if address<0x086e54 else 'song_kit',
            registers=regs[offset:offset+128].hex()))
    return dict(layout='windows-x64-v59', dsp_extra= len(data)==BLOCK_BYTES[1],
        arm_registers=[f'0x{x:08x}' for x in struct.unpack_from('<49I',data,22)],
        aram=digest(wave), protocol=wave[0x40:0x600].hex(),
        baseline=digest(wave[:0x086e54]), song_kit=digest(wave[0x086e54:]),
        streaming_window=digest(wave[0x00a0b4:0x00cf5e]), channels=channels)


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('checkpoint',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    args=ap.parse_args()
    rows=[dict(identity=row['identity'], **inspect(row['blocks'][3]))
          for row in checkpoints(args.checkpoint)]
    args.out.write_text(json.dumps(dict(coverage_credit=False,
        source=dict(path=str(args.checkpoint),sha256=sha(args.checkpoint)),
        checkpoints=rows),indent=2)+'\n')
    print(f'{len(rows)} checkpoints; {len(rows)*64} channel register records')


if __name__=='__main__': main()
