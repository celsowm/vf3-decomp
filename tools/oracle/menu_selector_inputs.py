"""Exercise every selector/character branch in the long original menu owner."""
import argparse
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--complete-profile', action='store_true', help='place all character boundaries and class-six branches within the first 128 probes')
    args = parser.parse_args()
    name = 'coverage_65_menu_selector_dev_v4' if args.complete_profile else 'coverage_65_menu_selector_dev_v3'
    count = 128 if args.complete_profile else 256
    base = ROOT / 'tools/oracle'
    entry = '0x8c07cf3e'
    prior = base / 'percentage_inputs/coverage_65_menu_reserve_dev_v2_memory.json'
    fields = copy.deepcopy(json.loads(prior.read_text())[entry])
    modes = [1 + (n//32)%3 for n in range(count)]
    characters = (0, 7, 8, 9, 10, 13, 20, 6)
    fields.update({
        '0xc640000': [2 if mode in (1, 3) else 0 for mode in modes],
        '0xc641000': [2 if mode in (2, 3) else 0 for mode in modes],
        '0xc29b8e0': [(n//8)%4 << 8 for n in range(count)],
        '0xc640030': [characters[(n//2 if args.complete_profile else n)%8] << 16 for n in range(count)],
        '0xc641030': [characters[(n//2 if args.complete_profile else n)%8] << 16 for n in range(count)],
        '0xc64006c': [6 if (n%32 >= 24 if args.complete_profile else n//64 == 3) else 0 for n in range(count)],
        '0xc64106c': [6 if (n%32 >= 24 if args.complete_profile else n//64 == 3) else 0 for n in range(count)],
    })
    paths = [base / f'{name}_watch.txt', base / f'{name}_owners.json',
             base / f'percentage_inputs/{name}_memory.json', ROOT / f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths), 'refuse to replace selector inputs'
    paths[0].write_text('pc '+entry+'\n')
    paths[1].write_text(json.dumps({entry:'0x8c07cf50'}, indent=2)+'\n')
    paths[2].write_text(json.dumps({entry:fields}, indent=2)+'\n')
    generate(paths[0], paths[3], 0x8c0432e2, count, fpscr=0x40001,
             bounded_arguments=True, preserve_fields=True, memory_overrides={entry:fields})
    print('Long selector branch inputs prepared; original complete-body audit remains required')


if __name__ == '__main__':
    main()
