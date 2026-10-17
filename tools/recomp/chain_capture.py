#!/usr/bin/env python3
"""chain_capture.py - build the next tick's capture from the oracle's exit RAM of the previous one.

  python tools/recomp/chain_capture.py <golden.bin> <oracle_dump.bin> <out.bin>

<golden.bin>  a tools/tick_capture.py recording (marker records 0xFA30 entry regs, 0xFA50 entry windows,
              0xFA32 exit regs, 0xFA60 exit windows); the first pair is used.
<oracle_dump> the reference oracle's tick dump (54 register words, then the 16 MiB RAM).
<out.bin>     the same recording with the entry RAM replaced by the oracle's exit RAM. The entry registers
              are kept, the exit side is left as it was (it is only used to diff against an emulator).

The oracle can then record the tick that follows, with no interrupts or main-loop code in between (see
docs/re/plan_native_slice.md, multi-tick probe)."""
import struct
import sys

RAM_BASE, RAM_LEN, HEADER = 0x0C000000, 0x01000000, 54 * 4


def main(golden, dump, out):
    ram = open(dump, 'rb').read()
    if len(ram) != HEADER + RAM_LEN:
        raise SystemExit(f'{dump}: not an oracle dump ({len(ram)} bytes)')
    ram = ram[HEADER:]
    src = open(golden, 'rb').read()
    words = len(src) // 8
    rec = struct.unpack(f'<{words}Q', src[:words * 8])
    res = []
    i, stage = 0, 0            # 0 wait entry regs, 1 wait entry windows, 2 done (copy the rest)
    while i < words:
        v = rec[i]
        marker = v & 0xFFFF
        if stage == 0 and (v >> 16) != 0 and marker == 0xFA30:
            res.extend(rec[i:i + 38]); i += 38; stage = 1; continue
        if stage == 1 and (v >> 16) != 0 and marker == 0xFA50:
            nwin = rec[i + 1]
            res.extend(rec[i:i + 2]); i += 2
            for _ in range(nwin):
                base, length = rec[i], rec[i + 1]
                res.extend(rec[i:i + 2]); i += 2
                if base == RAM_BASE and length == RAM_LEN:
                    res.extend(struct.unpack(f'<{length // 4}I', ram)); i += length // 4
                else:
                    res.extend(rec[i:i + length // 4]); i += length // 4
            stage = 2
            continue
        res.append(v); i += 1
    if stage != 2:
        raise SystemExit(f'{golden}: no entry pair found')
    open(out, 'wb').write(struct.pack(f'<{len(res)}Q', *res))


if __name__ == '__main__':
    if len(sys.argv) != 4:
        raise SystemExit(__doc__)
    main(*sys.argv[1:])
