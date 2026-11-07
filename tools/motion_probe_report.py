#!/usr/bin/env python3
"""Summarize register samples from retained Flycast PC-watch or capsule data.

At the motion-update PC 0x8C0AD1B8, r4 is the actor pointer and r5 is the
candidate motion ID. The default 0x1FFF mask is a display aid, not an action
label. Sample order is retained, but the captures have no frame timestamps.
An optional play script is printed as a separate schedule and is not aligned
with the samples.

Example:
  python tools/motion_probe_report.py \
      extract/analysis/goldens_actions2/f_0c0ad1b8.json \
      --play-script extract/analysis/vf3_play_actions2.txt
  python tools/motion_probe_report.py \
      extract/analysis/native_motion_action_probe_s29_v4/f_8c0ad1b8.cases \
      --show-pr
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path


def register_index(text: str) -> int:
    value = text.lower()
    if not value.startswith('r') or not value[1:].isdigit():
        raise argparse.ArgumentTypeError('expected a GPR such as r4')
    index = int(value[1:])
    if not 0 <= index < 16:
        raise argparse.ArgumentTypeError('GPR index must be in 0..15')
    return index


def number(text: str) -> int:
    try:
        value = int(text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(f'invalid integer: {text}') from exc
    if value < 0 or value > 0xFFFFFFFF:
        raise argparse.ArgumentTypeError('mask must fit in 32 bits')
    return value


def load_capture(path: Path) -> dict:
    if path.suffix.lower() == '.cases':
        try:
            lines = path.read_text(encoding='ascii').splitlines()
        except OSError as exc:
            raise ValueError(f'cannot read capsule cases {path}: {exc}') from exc
        register_names = ([f'r{i}' for i in range(16)] +
                          ['pr', 'sr', 'fpscr', 'macl', 'mach'] +
                          [f'fr{i}' for i in range(16)])
        samples = []
        for line_number, line in enumerate(lines, 1):
            fields = line.split()
            if not fields:
                continue
            if len(fields) < 74:
                raise ValueError(f'{path}:{line_number}: expected 74 register words')
            try:
                words = [int(value, 16) for value in fields[:74]]
            except ValueError as exc:
                raise ValueError(f'{path}:{line_number}: invalid register word') from exc
            samples.append({
                'in': dict(zip(register_names, words[:37])),
                'out': dict(zip(register_names, words[37:])),
            })
        if not samples:
            raise ValueError(f'capsule cases file has no samples: {path}')
        name = path.stem
        pc = name[2:] if name.startswith('f_') else '(unknown PC)'
        return {'name': name, 'pc': f'0x{pc}' if pc != '(unknown PC)' else pc,
                'samples': samples}

    try:
        capture = json.loads(path.read_text(encoding='utf-8'))
    except (OSError, json.JSONDecodeError) as exc:
        raise ValueError(f'cannot read capture JSON {path}: {exc}') from exc
    if not isinstance(capture, dict) or not isinstance(capture.get('samples'), list):
        raise ValueError('capture must be a PC-watch JSON object with a samples array')
    return capture


def print_samples(capture: dict, actor_register: int, value_register: int,
                  value_mask: int, aux_register: int | None,
                  show_output: bool, show_pr: bool) -> None:
    print(f"capture {capture.get('name', '(unnamed)')} at {capture.get('pc', '(unknown PC)')}")
    print(f"{len(capture['samples'])} samples; input order only, no frame timestamps")
    columns = ['#', f'r{actor_register} actor',
               f'r{value_register} raw', f'r{value_register}&mask motion']
    if aux_register is not None:
        columns.append(f'r{aux_register} raw')
    if show_pr:
        columns.append('PR')
    if show_output:
        columns.append(f'out r{value_register}')
    print('  '.join(columns))

    for index, sample in enumerate(capture['samples']):
        if not isinstance(sample, dict) or not isinstance(sample.get('in'), dict):
            raise ValueError(f'sample {index} has no input register map')
        inputs = sample['in']
        required = [f'r{actor_register}', f'r{value_register}']
        if aux_register is not None:
            required.append(f'r{aux_register}')
        missing = [name for name in required if name not in inputs]
        if missing:
            raise ValueError(f'sample {index} is missing {", ".join(missing)}')
        actor = int(inputs[f'r{actor_register}'])
        raw = int(inputs[f'r{value_register}'])
        row = [str(index), f'0x{actor:08x}', f'0x{raw:08x}',
               f'0x{raw & value_mask:04x}']
        if aux_register is not None:
            row.append(f'0x{int(inputs[f"r{aux_register}"]):08x}')
        if show_pr:
            pr = inputs.get('pr')
            row.append('(missing)' if pr is None else f'0x{int(pr):08x}')
        if show_output:
            output = sample.get('out', {})
            value = output.get(f'r{value_register}') if isinstance(output, dict) else None
            row.append('(missing)' if value is None else f'0x{int(value):08x}')
        print('  '.join(row))


def print_play_schedule(path: Path) -> None:
    try:
        lines = path.read_text(encoding='utf-8').splitlines()
    except OSError as exc:
        raise ValueError(f'cannot read play script {path}: {exc}') from exc
    event = re.compile(r'^\s*(\d+)\s+(KEYF|EXITF)\b(?:\s+(\S+))?', re.IGNORECASE)
    events = []
    for line in lines:
        match = event.match(line)
        if match:
            frame, command, value = match.groups()
            events.append((int(frame), command.upper(), value or ''))
    print(f'\nControl schedule from {path} (not aligned to sample indices):')
    if not events:
        print('  (no KEYF or EXITF events found)')
        return
    for frame, command, value in events:
        print(f'  frame {frame:>5}: {command}' + (f' {value}' if value else ''))


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('capture', type=Path, help='retained golden PC-watch JSON')
    parser.add_argument('--actor-register', type=register_index, default=4,
                        help='register containing the actor pointer (default: r4)')
    parser.add_argument('--value-register', type=register_index, default=5,
                        help='register containing the candidate motion value (default: r5)')
    parser.add_argument('--value-mask', type=number, default=0x1FFF,
                        help='mask applied to the candidate value (default: 0x1fff)')
    parser.add_argument('--aux-register', type=register_index, default=7,
                        help='raw context register to include (default: r7)')
    parser.add_argument('--no-aux-register', action='store_const',
                        const=None, dest='aux_register',
                        help='omit the auxiliary register column')
    parser.add_argument('--play-script', type=Path,
                        help='print KEYF/EXITF events separately from the samples')
    parser.add_argument('--show-output', action='store_true',
                        help='also show the value of the selected register on return')
    parser.add_argument('--show-pr', action='store_true',
                        help='show the saved PR (return PC) at each captured sample')
    args = parser.parse_args(argv)
    try:
        capture = load_capture(args.capture)
        print_samples(capture, args.actor_register, args.value_register,
                      args.value_mask, args.aux_register, args.show_output,
                      args.show_pr)
        if args.play_script:
            print_play_schedule(args.play_script)
    except (OSError, ValueError, TypeError) as exc:
        print(f'motion_probe_report: {exc}', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
