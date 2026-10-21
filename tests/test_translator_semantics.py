"""Compile emitted SH-4 instructions and compare their C effects with arithmetic.

These are synthetic semantic regressions, not game replay or coverage credit.
MAC read ordering/S=0 behavior follows Flycast's sh4_opcodes.cpp:1366-1404 at
34ad8c8262c82db237a8b9cee0d8046d9cdd6f78.
"""
from __future__ import annotations

import importlib.util
import os
from pathlib import Path
import random
import re
import shlex
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location('translate_adapters', ROOT / 'tools/oracle/translate_adapters.py')
TRANSLATOR = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(TRANSLATOR)
MASK32 = (1 << 32) - 1
MASK64 = (1 << 64) - 1
OPCODES = (0x412F, 0x411F, 0x012F, 0x011F, 0x0C0F, 0x00CF)


def signed(value, bits):
    value &= (1 << bits) - 1
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


class TranslatorSemantics(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.temp = tempfile.TemporaryDirectory(prefix='vf3-translator-')
        cls.addClassCleanup(cls.temp.cleanup)
        directory = Path(cls.temp.name)
        source = directory / 'mac.c'
        cls.executable = directory / ('mac.exe' if os.name == 'nt' else 'mac')
        cases = []
        for opcode in OPCODES:
            body = '\n'.join(TRANSLATOR.emit(0x0c010000, opcode))
            cases.append(f'case 0x{opcode:04x}:\n{body}\nreturn 1;')
        source.write_text(r'''
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
struct memory { uint32_t address[2], value[2]; };
static uint32_t read_addresses[2], read_sizes[2], reads;
static uint32_t read(const struct memory *ram,uint32_t addr,unsigned size) {
    unsigned i;
    if(reads<2) { read_addresses[reads]=addr; read_sizes[reads]=size; }
    ++reads;
    for(i=0;i<2;++i) if(ram->address[i]==addr) return ram->value[i];
    return 0xf00dfaceu;
}
static int run(unsigned opcode,uint32_t *r,const struct memory *ram) {
    uint64_t wide;
    switch(opcode) {
''' + '\n'.join(cases) + r'''
    default: return -1;
    }
unsupported: return 0;
}
int main(int argc,char **argv) {
    uint32_t r[54];
    struct memory ram;
    uint64_t accumulator;
    unsigned opcode,n,m,i;
    int ok;
    if(argc!=10) return 2;
    opcode=(unsigned)strtoul(argv[1],NULL,0); n=(opcode>>8)&15; m=(opcode>>4)&15;
    for(i=0;i<54;++i) r[i]=0xabc00000u+i;
    r[n]=(uint32_t)strtoull(argv[2],NULL,0); r[m]=(uint32_t)strtoull(argv[3],NULL,0);
    accumulator=(uint64_t)strtoull(argv[4],NULL,0);
    r[19]=(uint32_t)accumulator; r[20]=(uint32_t)(accumulator>>32);
    r[17]=(uint32_t)strtoull(argv[5],NULL,0);
    ram.address[0]=(uint32_t)strtoull(argv[6],NULL,0); ram.value[0]=(uint32_t)strtoull(argv[7],NULL,0);
    ram.address[1]=(uint32_t)strtoull(argv[8],NULL,0); ram.value[1]=(uint32_t)strtoull(argv[9],NULL,0);
    ok=run(opcode,r,&ram);
    printf("%d %u %u %u %u %u",ok,reads,read_addresses[0],read_sizes[0],read_addresses[1],read_sizes[1]);
    for(i=0;i<54;++i) printf(" %u",r[i]);
    putchar('\n');
    return 0;
}
''', encoding='ascii')
        chosen = os.environ.get('VF3_TEST_CC') or os.environ.get('CC')
        if chosen:
            compiler = [chosen] if Path(chosen).is_file() else shlex.split(chosen)
        else:
            path = next((shutil.which(name) for name in ('cc', 'clang', 'gcc', 'cl') if shutil.which(name)), None)
            if not path:
                raise RuntimeError('a C compiler is required; set CC or VF3_TEST_CC')
            compiler = [path]
        if Path(compiler[0]).name.lower() in ('cl', 'cl.exe'):
            command = compiler + ['/nologo', '/TC', '/O2', str(source), '/Fe:' + str(cls.executable)]
        else:
            command = compiler + ['-std=c99', '-O2', '-Wall', '-Wextra', '-Werror', str(source), '-o', str(cls.executable)]
        built = subprocess.run(command, capture_output=True, text=True, cwd=directory)
        if built.returncode:
            raise RuntimeError(f'C semantic harness failed to compile:\n{built.stdout}\n{built.stderr}')

    def check_mac(self, opcode, value0, value1, accumulator=0, nbase=0x100, mbase=0x200, sr=0):
        n, m = (opcode >> 8) & 15, (opcode >> 4) & 15
        size = 2 if opcode >> 12 == 4 else 4
        if n == m:
            mbase = nbase
        if size == 2:
            addresses = [nbase, (mbase + (size if n == m else 0)) & MASK32]
        else:
            addresses = [mbase, (nbase + (size if n == m else 0)) & MASK32]
        arguments = [opcode, nbase, mbase, accumulator, sr, addresses[0], value0 & MASK32, addresses[1], value1 & MASK32]
        completed = subprocess.run([str(self.executable), *(str(v) for v in arguments)], capture_output=True, text=True, check=True)
        actual = [int(v) for v in completed.stdout.split()]
        expected_regs = [0xabc00000 + i for i in range(54)]
        expected_regs[n], expected_regs[m] = nbase, mbase
        expected_regs[17] = sr
        expected_regs[19], expected_regs[20] = accumulator & MASK32, accumulator >> 32
        if sr & 2:
            self.assertEqual(actual, [0, 0, 0, 0, 0, 0] + expected_regs)
            return
        # Memory aliasing: equal addresses return the same first mapped value.
        second = value0 if addresses[0] == addresses[1] else value1
        product = signed(value0, size * 8) * signed(second, size * 8)
        expected_acc = (accumulator + product) & MASK64
        expected_regs[19], expected_regs[20] = expected_acc & MASK32, expected_acc >> 32
        expected_regs[n] = (expected_regs[n] + size) & MASK32
        expected_regs[m] = (expected_regs[m] + size) & MASK32
        self.assertEqual(actual, [1, 2, addresses[0], size, addresses[1], size] + expected_regs)

    def test_signed_products_and_accumulator_wrap(self):
        for opcode in OPCODES:
            bits = 16 if opcode >> 12 == 4 else 32
            minimum, maximum = -(1 << (bits - 1)), (1 << (bits - 1)) - 1
            for values in ((-1, 1, 0), (-3, 7, 0), (minimum, minimum, 0),
                           (minimum, maximum, 0), (minimum, -1, MASK64),
                           (maximum, maximum, (1 << 63) - 1), (1, 1, MASK64),
                           (-1, 1, 0), (0, minimum, 0x0123456789abcdef)):
                with self.subTest(opcode=hex(opcode), values=values):
                    self.check_mac(opcode, *values)

    def test_same_address_is_not_same_register(self):
        for opcode in OPCODES:
            with self.subTest(opcode=hex(opcode)):
                self.check_mac(opcode, -7, 19, 123, nbase=0x100, mbase=0x100)

    def test_pointer_wrap_and_encoded_same_register(self):
        for opcode in OPCODES:
            size = 2 if opcode >> 12 == 4 else 4
            with self.subTest(opcode=hex(opcode)):
                self.check_mac(opcode, -5, -11, 23, nbase=(1 << 32) - size, mbase=(1 << 32) - size)

    def test_saturation_is_rejected_before_reads_or_state_changes(self):
        for opcode in OPCODES:
            with self.subTest(opcode=hex(opcode)):
                self.check_mac(opcode, -7, 19, MASK64, sr=3)

    def test_random_full_width_operands(self):
        rng = random.Random(0x534834)
        for opcode in OPCODES:
            for _ in range(16):
                self.check_mac(opcode, rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(64))

    def test_unmodelled_ldc_long_stays_unsupported(self):
        for n in range(16):
            # SR, VBR, SSR, SPC plus reserved encodings formerly caught by F00F.
            for low in (0x07, 0x27, 0x37, 0x47, 0x57, 0x67, 0x77):
                with self.subTest(n=n, low=hex(low)):
                    with self.assertRaisesRegex(ValueError, 'unsupported'):
                        TRANSLATOR.emit(0x0c010000, 0x4000 | n << 8 | low)
            self.assertIn('s->gbr=', '\n'.join(TRANSLATOR.emit(0x0c010000, 0x4017 | n << 8)))
            self.assertIn('s->bank[', '\n'.join(TRANSLATOR.emit(0x0c010000, 0x4087 | n << 8)))

    def test_c95_mac_sites_match_current_generator(self):
        source = (ROOT / 'src/fight/vf3_c95_adapter.c').read_text()
        for pc in (0x0c07350a, 0x0c07350e, 0x0c073512):
            site = re.search(rf'P_{pc:08x}:.*?\nif\(!s->budget--\).*?\n(.*?)goto P_', source, re.S)
            self.assertIsNotNone(site)
            self.assertEqual(site.group(1), '\n'.join(TRANSLATOR.emit(pc, 0x0c0f)) + '\n')


if __name__ == '__main__':
    unittest.main()
