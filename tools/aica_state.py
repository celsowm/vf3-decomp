#!/usr/bin/env python3
"""Read the AICA (sound) RAM out of a Flycast savestate.

The AICA RAM is not part of the SH-4's RAM dump, but Flycast serializes it
into the savestate, so the state file is the only place where the sound
driver's own view of the sound RAM can be read back.

Format (flycast/core/nullDC.cpp and flycast/core/archive/rzip.cpp):

    SavestateHeader  "FLYSAVE1"[8], u64 creationDate, u32 version, u32 pngSize
    optional PNG     pngSize bytes
    RZIP stream      "#RZIPv\\x01#"[8], u32 maxChunkSize, u64 size,
                     then (u32 zippedSize, zlib data) chunks

The serialized blob (flycast/core/serialize.cpp, dc_serialize) starts with the
version and the RAM size and continues with aica::serialize, whose first big
block is the AICA RAM itself.

Usage:
    python tools/aica_state.py <savestate>              # header dump
    python tools/aica_state.py <savestate> --dump out.bin  # the whole 2 MiB
    python tools/aica_state.py <savestate> --range 0x40:0x90
"""
from __future__ import annotations

import struct
import sys
import zlib

RZIP_MAGIC = b"#RZIPv\x01#"

# offset of the AICA RAM inside the deserialized blob (dc_serialize order):
#   u32 version, u32 ram_size
#   bool aica_interr, u32 aica_reg_L, bool e68k_out, u32 e68k_reg_L, u32 e68k_reg_M
#   reg_pair arm_Reg[RN_ARM_REG_COUNT - 1]        (reg_pair is 4 bytes)
#   bool armIrqEnable, bool armFiqEnable, int armMode, bool Arm7Enabled,
#   int arm7ClockTicks
#   dsp::state: s32 TEMP[128], MEMS[32], MIXS[16], u32 RBP, RBL, MDEC_CT
#   timers[3]: s32 c_step, u32 m_step
AICA_RAM_OFF = (4 + 4 + (1 + 4 + 1 + 4 + 4) + 49 * 4 + (1 + 1 + 4 + 1 + 4)
                + (128 * 4 + 32 * 4 + 16 * 4 + 12) + 3 * 8)
ARAM_SIZE = 2 * 1024 * 1024          # Dreamcast


def load_state(path: str) -> bytes:
    """Return the deserialized savestate blob."""
    data = open(path, "rb").read()
    off = 0
    if data[:8] == b"FLYSAVE1":
        png_size = struct.unpack_from("<I", data, 20)[0]
        off = 24 + png_size
    if data[off:off + 8] != RZIP_MAGIC:
        raise SystemExit("no RZIP stream at %d: %r" % (off, data[off:off + 8]))
    off += 8
    max_chunk = struct.unpack_from("<I", data, off)[0]
    off += 4
    size = struct.unpack_from("<Q", data, off)[0]
    off += 8
    out = bytearray()
    while len(out) < size:
        zipped_size = struct.unpack_from("<I", data, off)[0]
        off += 4
        if zipped_size == 0:
            continue
        out += zlib.decompress(data[off:off + zipped_size])
        off += zipped_size
    if len(out) != size:
        raise SystemExit("state size mismatch: %d != %d" % (len(out), size))
    return bytes(out)


def aica_ram(blob: bytes) -> bytes:
    return blob[AICA_RAM_OFF:AICA_RAM_OFF + ARAM_SIZE]


def main() -> int:
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    path = sys.argv[1]
    blob = load_state(path)
    version, ram_size = struct.unpack_from("<II", blob, 0)
    ram = aica_ram(blob)
    print("state %s: version %d, RAM size 0x%08x, blob %d bytes"
          % (path, version, ram_size, len(blob)))
    print("AICA RAM at %d, last byte 0x%02x" % (AICA_RAM_OFF, ram[-1]))

    if "--dump" in sys.argv:
        out = sys.argv[sys.argv.index("--dump") + 1]
        open(out, "wb").write(ram)
        print("wrote %s (%d bytes)" % (out, len(ram)))
        return 0

    lo, hi = 0x00, 0x100
    if "--range" in sys.argv:
        spec = sys.argv[sys.argv.index("--range") + 1]
        lo, hi = (int(x, 0) for x in spec.split(":"))
    for base in range(lo, hi, 16):
        row = ram[base:base + 16]
        print("%04X  %s  |%s|" % (base, " ".join("%02x" % b for b in row),
                                  "".join(chr(b) if 32 <= b < 127 else "." for b in row)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
