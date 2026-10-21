#!/usr/bin/env python3
"""Capture roots independently so one probe cannot starve later targets.

Every original interpreter run starts from a fresh state. Failed runs and
invalid specimens remain excluded. Generated fixtures live under analysis.
"""
import argparse
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--watch', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--start', type=int, default=0)
    ap.add_argument('--limit', type=int, default=30)
    ap.add_argument('--frames', type=int, default=120)
    ap.add_argument('--max-samples', type=int, default=8)
    ap.add_argument('--probe-ops', type=int, default=100000,
                    help='synthetic-call instruction budget per probe')
    ap.add_argument('--states', default='20,21')
    ap.add_argument('--trigger', type=lambda s: int(s, 16), default=0x8c063d36)
    ap.add_argument('--target-form', choices=('ram', 'rom'), default='ram',
                    help='address form the synthetic probe jumps to.  The RAM alias '
                         '(0x0c) is where the game runs the image from, but the RAM '
                         'copy only covers the part of the image the loader has '
                         'already placed; the low image region is still zero there '
                         'and the probe would execute zeros until it hits the '
                         'erased 0xffff padding.  The ROM form (0x8c) always holds '
                         'the image.')
    ap.add_argument('--pointer-fixtures', action='store_true')
    ap.add_argument('--arena-seeds', action='store_true',
                    help='seed every register the fixture did not infer with a '
                         'RAM arena pointer, so a bogus live pointer cannot '
                         'reach a device address')
    ap.add_argument('--emulator', type=Path,
                    help='explicit immutable oracle executable; default is the '
                         'local build.  The extended observer '
                         '(tools/oracle/extended_observer_controls_v1.json) '
                         'records up to 500,000 instructions per probe, which '
                         'is what a target whose loop count comes from the '
                         'arena spread needs.')
    ap.add_argument('--observer-controls', type=Path,
                    default=ROOT / 'tools/oracle/extended_observer_controls_v1.json',
                    help='proof that pins the recorder used with --emulator; it '
                         'authorises the recorded instruction bound the sweep may '
                         'ask for')
    ap.add_argument('--counter-variants', type=int, default=4,
                    help='extra seed variants that give the registers the static '
                         'inference did not classify small values instead of arena '
                         'pointers, so a target whose unclassified register is a '
                         'counter terminates instead of looping forever')
    ap.add_argument('--ram-patch', type=Path,
                    help='global RAM fixture applied at start-up (the oracle\'s '
                         'VF3_RAM_PATCH two-field form).  tools/oracle/ram_image_seed.py '
                         'writes one that fills the low RAM region with the image, '
                         'so a probe that targets an entry there runs the real code '
                         'instead of zeros.')
    ap.add_argument('--arena-base', type=lambda s: int(s, 16), default=0x0c420000)
    ap.add_argument('--arena-stride', type=lambda s: int(s, 16), default=0x1000,
                    help='distance between the arena pages the seeded registers '
                         'point at.  The default spreads them over 16 pages; a '
                         'target that derives a loop count from the distance '
                         'between two of them then runs 16k iterations and the '
                         'probe hits its instruction budget instead of '
                         'returning, so a tighter spread makes those targets '
                         'come back.')
    ap.add_argument('--arena-variants', type=int, default=8,
                    help='number of seed variants; each one points the arena '
                         'registers at a different page')
    ap.add_argument('--seed-mode', choices=('zero', 'open', 'one'), default='zero')
    ap.add_argument('--timeout', type=int, default=90,
                    help='seconds allowed per target, including both state runs')
    a = ap.parse_args()
    roots = [int(line.split()[1], 16) for line in a.watch.read_text().splitlines()
             if line.startswith('pc ')][a.start:a.start + a.limit]
    a.out.mkdir(parents=True, exist_ok=True)
    rows = []
    for index, entry in enumerate(roots, a.start):
        name = f'{a.out.name}_{entry:08x}'
        directory = a.out / name
        directory.mkdir(parents=True, exist_ok=True)
        if (directory / 'capsule_manifest.json').exists():
            print(f'{index}: {entry:08x} already captured', flush=True)
            continue
        watch = directory / 'watch.txt'
        patch = directory / 'entry.patch'
        watch.write_text(f'pc 0x{entry:08x}\n')
        registers, words = ({}, {})
        if a.pointer_fixtures:
            from pointer_seeds import fixture
            registers, words = fixture(entry, a.seed_mode)
        if a.arena_seeds:
            # The probe runs with the game's live registers unless the patch
            # overrides them.  A live register that holds a bogus pointer
            # (a null-ish 0x11, say) makes the target dereference a device
            # address, and the oracle rejects the specimen (flags 2|4).
            # Point every register the static inference could not classify at
            # a page of the RAM arena instead: the probe then stays inside
            # the main RAM the oracle already snapshots and restores.
            lines = ['entry 0x%08x 0x%08x' % (a.trigger, entry)]
            probe_target = (entry & 0x1fffffff) if a.target_form == 'ram' else (entry | 0x80000000)
            for variant in range(a.arena_variants + a.counter_variants):
                if variant:
                    lines.append('seed 0x%08x' % a.trigger)
                lines += ['target 0x%08x 0x%08x' % (a.trigger, probe_target),
                          'reg 0x%08x pr 0x%08x' % (a.trigger, (a.trigger + 2) & 0x1fffffff)]
                for reg in range(15):
                    if reg in registers:
                        value = registers[reg]
                    elif variant >= a.arena_variants:
                        # The static inference only classifies the registers the
                        # target dereferences.  A register it never dereferences
                        # is usually a counter, and a counter seeded with an
                        # arena pointer never terminates: `dt r5` on a pointer
                        # counts down from 0x0c4xxxxx and the probe spends its
                        # whole budget inside the loop.  The extra variants seed
                        # those registers with small values instead, so a target
                        # that counts comes back; the pointer-style variants
                        # still cover the registers only a callee dereferences.
                        value = (reg % 8) + 1
                    else:
                        value = a.arena_base + (reg + variant * 16) * a.arena_stride
                    lines.append('reg 0x%08x r%d 0x%08x' % (a.trigger, reg, value & 0xffffffff))
                # r15 is the stack pointer: give it its own page so a frame
                # push lands in the arena instead of under the null pointer.
                lines.append('reg 0x%08x r15 0x%08x' %
                             (a.trigger, a.arena_base + (15 + variant * 16) * a.arena_stride))
                for addr, value in sorted(words.items()):
                    lines.append('ram 0x%08x 0x%08x 0x%08x' % (a.trigger, addr, value & 0xffffffff))
            patch.write_text('\n'.join(lines) + '\n')
        else:
            patch.write_text(f'entry 0x{a.trigger:08x} 0x{entry:08x}\n'
                             f'target 0x{a.trigger:08x} 0x{entry & 0x1fffffff:08x}\n'
                             f'reg 0x{a.trigger:08x} pr 0x{(a.trigger + 2) & 0x1fffffff:08x}\n')
            with patch.open('a') as output:
                for register, value in sorted(registers.items()):
                    output.write(f'reg 0x{a.trigger:08x} r{register} 0x{value:08x}\n')
                for addr, value in sorted(words.items()):
                    output.write(f'ram 0x{a.trigger:08x} 0x{addr:08x} 0x{value:08x}\n')
        cmd = [sys.executable, '-u', 'tools/golden_batch.py', '--name', name,
               '--watch', str(watch), '--out', str(directory), '--entry-patch',
               str(patch), '--capsule', '--probe-debug', '--probe-only',
               '--max-samples', str(a.max_samples),
               '--probe-ops', str(a.probe_ops)]
        if a.emulator:
            cmd += ['--emulator', str(a.emulator)]
            cmd += ['--observer-controls', str(a.observer_controls)]
        for state in a.states.split(','):
            run = f's{state}:tools/emu/flycast-build/data/vf3_{state}.state::{a.frames}'
            if a.ram_patch:
                run += f':{a.ram_patch}'
            cmd += ['--run', run]
        with (directory / 'capture.log').open('w') as log:
            process = subprocess.Popen(cmd, cwd=ROOT, stdout=log, stderr=log)
            try:
                returncode = process.wait(timeout=a.timeout)
            except subprocess.TimeoutExpired:
                # The emulator is a descendant of this capture process. Stop
                # that owned tree so a stalled guest cannot block the sweep.
                subprocess.run(['taskkill', '/PID', str(process.pid), '/T', '/F'],
                               stdout=log, stderr=log)
                process.wait()
                returncode = 124
        count = 0
        if (directory / 'capsule_manifest.json').is_file():
            count = len(json.loads((directory / 'capsule_manifest.json').read_text())['entries'].get(hex(entry), []))
        rows.append(dict(index=index, entry=hex(entry), returncode=returncode,
                         complete_cases=count, directory=str(directory)))
        (a.out / 'progress.json').write_text(json.dumps(rows, indent=1) + '\n')
        print(f'{index}: {entry:08x} rc={returncode} complete={count}', flush=True)


if __name__ == '__main__':
    main()
