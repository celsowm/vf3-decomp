"""Prepare original resource-table JSR windows with immutable callback slots."""
import argparse
import json
from pathlib import Path
from actor_table_layout import layout
from actor_table_inputs import OWNERS, EXTRA_OWNERS
from tenpp_probe_plan import override_sequence, override_value


def prepare(inputs, output, extra=False):
    data = json.loads(inputs.read_text())
    cases = []
    for entry in (EXTRA_OWNERS if extra else OWNERS):
        record, = layout(entry)['original_resource_records']
        descriptor = int(record['words'][6], 16)
        for variant in (0, 5):
            fields = {address: override_value(override_sequence(value, address), variant)
                      for address, value in data['memory'][hex(entry)].items()}
            fields.pop('0xc400010')
            fields[hex(descriptor+16)] = 0xc420000
            fields['0xc690100'] = int(record['address'], 16) & 0x1fffffff
            cases.append(dict(name=f'actor_table_{entry:08x}_{variant}',
                entry='0x0c0a2f3c', registers=dict(r13=descriptor, r14=0xc4b1000,
                    r15=0xc690100, fpscr=0x40001), memory=fields, budget=100000,
                # A configured transfer captures the two real continuation
                # instructions before the observer closes the invocation.
                transfer='0x0c0a2f44', expected_exit='0x0c0a2f48', explicit_return_only=True))
    if output.exists():
        raise FileExistsError(output)
    output.write_text(json.dumps(dict(advisory=True, coverage_credit=False,
        trigger='0x8c0432e2', fixture_scope='Original stack-resident resource record, '
        'immutable table callback at +28 and resource descriptor at +24, original '
        'JSR/delay slot and explicit callee return. Table words and code stay original.',
        cases=cases), indent=2)+'\n')
    print(f'{len(cases)} immutable resource-table caller windows prepared')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inputs', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--extra', action='store_true')
    args = parser.parse_args()
    prepare(args.inputs, args.out, args.extra)
