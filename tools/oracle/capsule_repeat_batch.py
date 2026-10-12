"""Create exact-input rollback probes for phase-sensitive original diagnostics."""
import argparse
import json
from pathlib import Path
from capsule_repeat_recipe import prepare
from capsules import records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('capsule', type=Path)
    parser.add_argument('--id', type=int, required=True)
    parser.add_argument('--transfer', type=lambda value: int(value, 0), required=True)
    parser.add_argument('--prefix', type=Path, required=True)
    args = parser.parse_args()
    paths = [Path(str(args.prefix)+suffix) for suffix in ('.json', '.watch', '.patch')]
    assert not any(path.exists() for path in paths), 'refuse to replace exact-input probes'
    recipe = prepare(args.capsule, args.id, paths[0], args.transfer)
    case = recipe['cases'][0]
    trigger, entry = int(recipe['trigger'], 0), int(case['entry'], 0)
    original = next(sample for sample in records(args.capsule) if sample['id'] == args.id)
    actual_pc = original['ops'][0][0]
    paths[1].write_text(f'pc {entry:08x}\n')
    lines = [f'entry 0x{trigger:08x} 0x{entry:08x}', f'target 0x{trigger:08x} 0x{actual_pc:08x}']
    lines += [f'reg 0x{trigger:08x} {register} 0x{value:08x}' for register, value in case['registers'].items()]
    lines += [f'ram 0x{trigger:08x} 0x{int(address,0):08x} 0x{value:08x}' for address, value in case['memory'].items()]
    paths[2].write_text('\n'.join(lines)+'\n')
    print('Exact-input original probes prepared; all 63 words and input pages must still be compared')


if __name__ == '__main__':
    main()
