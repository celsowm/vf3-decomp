"""Prepare original scene-57 windows through the replay transition helpers."""
import argparse
import json
from pathlib import Path
from tenpp_probe_plan import override_sequence, override_value

ROOT = Path(__file__).resolve().parents[2]


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, default=ROOT / 'tools/oracle/replay_transition_original_dispatch_v1.json')
    parser.add_argument('--force-pair-reset', action='store_true', help='clear the original optional-reset input byte in each typed variant')
    args = parser.parse_args()
    source = ROOT / 'tools/oracle/percentage_inputs/coverage_65_replay_transition_helpers_dev_v2_memory.json'
    memory = json.loads(source.read_text())['0x8c099540']
    output = args.out
    assert not output.exists(), 'refuse to replace caller inputs'
    cases = []
    for n, variant in enumerate((0, 32, 64, 96)):
        fields = {address: override_value(override_sequence(values, address), variant)
                  for address, values in memory.items()}
        # The original input predicate enters its transition when the clock
        # expires. Preserve actor descriptors and let all callbacks execute.
        fields['0xc29bccc'] = 0
        fields['0xc29b870'] = 0
        if args.force_pair_reset:
            fields['0xc29be84'] &= ~0x0000ff00
        fields['0xc29b86c'] = (fields.get('0xc29b86c', 0) & ~0x00ff0000) | (57 << 16)
        registers = dict(fpscr=0x40001, r15=0xc690100)
        registers.update({f'r{r}': 0xc4b1000 + 0x100*n + 0x10*r for r in range(8, 15)})
        cases.append(dict(name=f'replay_scene57_{variant}', entry='0x0c0968d0',
            registers=registers, memory=fields, budget=100000,
            expected_exit='0x0c0432e4', transfer='0x0c0996c0', explicit_return_only=True))
    output.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', fixture_scope='Original immutable scene-57 dispatcher and input predicate, expired clock, paired actor reset and replay transition; no instruction or callback replacement.',
        cases=cases), indent=2) + '\n')
    print('Four replay caller inputs prepared; original capture and validation still required')


if __name__ == '__main__':
    main()
