"""Check the 040fa4 allocation contract against original calls (advisory only).

This decodes captured original inputs and checks published descriptors and bus
writes. It does not execute C, replay devices or assign frozen-body credit.
"""
import argparse
import json
import struct
from pathlib import Path
from audio_determinism import sha
from capsules import records


def signed16(n):
    n &= 65535
    return n - 65536 if n & 32768 else n


def ram(c, address, size, after=False):
    for base, before, final in c['pages']:
        if base <= address and address+size <= base+len(before):
            return int.from_bytes((final if after else before)[address-base:address-base+size], 'little')
    raise ValueError(f'uncaptured RAM {address:#x}')


def check(c):
    if c['entry'] != 0x8c040fa4 or c['flags']:
        raise ValueError('requires a completed original channel configuration')
    regs = struct.unpack('<63I', c['before'])
    mono, dual, mode = map(signed16, regs[4:7])
    total = signed16(mono+2*dual)
    error = -2 if mode else -1 if total > 8 else 0
    if not error:
        active = any(ram(c, 0x0c19e250+24*i, 1) == 1 for i in range(8))
        error = -3 if active else 0
    result = struct.unpack_from('<I', c['after'])[0]
    if result != error & 0xffffffff:
        raise ValueError('argument/error contract differs')
    writes = [(addr, size, value) for addr, size, value, write in c['device'] if write]
    if error:
        if writes:
            raise ValueError('rejected configuration wrote the device')
        return dict(passed=True, result=error, mono=mono, dual=dual, mode=mode, writes=0)
    if mono < 0 or dual < 0:
        raise ValueError('negative-count allocation needs a separate bounded investigation')
    # The original helper's two input reads supply the observed protocol inputs.
    # These are for offline interpretation, never responses fed to a C backend.
    def device_read(address):
        values = [v for a, n, v, w in c['device'] if a == (address&0x1fffffff) and n == 4 and not w]
        if len(values) != 1:
            raise ValueError(f'expected one original input read at {address:#x}')
        return values[0]
    expected = [(0x008000a0, 4, mono), (0x008000a4, 4, dual)]
    boundary = device_read(0xa080008c)
    length, stride, position = 0, 0, None
    if total:
        length = min((((boundary-total*64)&0xffffffff)//total)&0x7fffffe0, 0x4000)
        stride = length+64
        alignment_input = device_read(ram(c, 0x0c19e220, 4))
        aligned = (alignment_input+31)&0xffffffe0
        position = (ram(c, 0x0c19e224, 4)-stride-aligned)&0xffffffff
    expected.append((0x008000a8, 4, stride))
    if ram(c, 0x0c19e22c, 4, True) != length:
        raise ValueError('published channel length differs')
    slots = []
    for i in range(mono+dual):
        host, descriptor = 0x0c19e250+i*24, 0x00800100+i*96
        if i < mono:
            a, b = position, 0
            expected.extend([(descriptor+12, 4, a), (descriptor+16, 4, b)])
            position = (position-stride)&0xffffffff
        else:
            b = position
            position = (position-stride)&0xffffffff
            a = position
            position = (position-stride)&0xffffffff
            expected.extend([(descriptor+16, 4, b), (descriptor+12, 4, a)])
        values = {0: (1, 0), 1: (1, 0), 4: (4, (0xa0800000+a)&0xffffffff),
                  8: (4, (0xa0800000+b)&0xffffffff if b else 0),
                  16: (4, descriptor+20+0xa0000000), 20: (4, descriptor+4+0xa0000000)}
        for offset, (size, value) in values.items():
            if ram(c, host+offset, size, True) != value:
                raise ValueError(f'channel {i} field +{offset} differs')
        slots.append(dict(slot=i, buffer_a=a, buffer_b=b))
    for i in range(mono+dual, 8):
        host = 0x0c19e250+i*24
        for offset, size, value in [(0,1,255), (1,1,0), (4,4,0xffffffff), (8,4,0xffffffff)]:
            if ram(c, host+offset, size, True) != value:
                raise ValueError('unused channel sentinel differs')
    queue = ram(c, 0x0c19e218, 4)
    if device_read(queue) == 0:
        expected.append((queue&0x1fffffff, 4, 0xa1))
        next_slot = 0xa0800400 if queue+4 == 0xa0800500 else queue+4
    else:
        next_slot = queue
    if ram(c, 0x0c19e218, 4, True) != next_slot:
        raise ValueError('nested queue publication differs')
    if writes != expected:
        raise ValueError(f'ordered device writes differ: actual={writes}, expected={expected}')
    return dict(passed=True, result=0, mono=mono, dual=dual, mode=mode,
                boundary=boundary, length=length, stride=stride, slots=slots,
                writes=len(writes), command=0xa1)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('manifest', type=Path)
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    data = json.loads(a.manifest.read_text())
    if not data['passed'] or data['execution'] != 'original_sh4':
        raise ValueError('incomplete original capture')
    rows = []
    for row in data['runs']:
        if sha(row['capsule']) != row['capsule_sha256']:
            raise ValueError('capsule hash changed')
        samples = list(records(row['capsule']))
        if len(samples) != 1:
            raise ValueError('expected one call')
        rows.append(dict(state=row['state'], case=row['case'], **check(samples[0])))
    report = dict(advisory=True, coverage_credit=False, passed=True,
        scope='original-call allocation interpretation; not independent C/device replay',
        original_manifest=dict(path=str(a.manifest), sha256=sha(a.manifest), manifest=data),
        checks=rows)
    a.out.write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    print(f'{len(rows)} original allocation contracts match')


if __name__ == '__main__':
    main()
