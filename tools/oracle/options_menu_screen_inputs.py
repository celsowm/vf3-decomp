"""Exercise original options-menu wrap boundaries; screening grants no C credit."""
import copy
import json
from pathlib import Path
from tenpp_probe_plan import generate

ROOT = Path(__file__).resolve().parents[2]


def main():
    name = 'coverage_65_options_menu_dev_v1'
    entry = '0x8c09bc1c'
    base = ROOT / 'tools/oracle'
    old = base / 'percentage_inputs/coverage_65_batch_screen_dev_v2_memory.json'
    fields = copy.deepcopy(json.loads(old.read_text())[entry])
    # Selected index, original button bits, current value, config toggle.
    # These are pre-execution structure inputs, never expected output bytes.
    cases = [(0,64,2,0), (0,128,5,0), (1,64,0,0), (1,128,0,0),
             (2,64,0,0), (5,64,0,0), (6,64,0,0), (7,64,0,0),
             (3,128,400,0), (4,128,400,0), (10,4,0,1),
             (11,32,0,0), (0,16,0,0)]
    buttons = (0,16,32,64,128,4,2,8)
    for selector in range(12):
        for button in buttons:
            maximum = (5,3,3,400,400,1,2,1)[selector] if selector < 8 else 1
            value = maximum if button == 128 else 0
            cases.append((selector,button,value,(selector+button)&1))
    while len(cases) < 128:
        n = len(cases)
        cases.append((n%12,buttons[n%8],(0,1,2,3,5,160,400,401)[n%8],n&1))
    assert len(cases) == 128
    fields.update({
        '0xc29ba84': [row[0] for row in cases],  # owner +0x220
        '0xc2cf83c': [row[1] for row in cases],  # controller zero +8
        '0xc2cf850': [row[1] for row in cases],  # controller one +8
        '0xc29ba80': [row[2] for row in cases],  # owner +0x21c
        '0xc11e510': [row[3] << 16 for row in cases],  # config +14 byte
    })
    paths = [base/f'{name}_watch.txt', base/f'{name}_owners.json',
             base/f'percentage_inputs/{name}_memory.json',
             ROOT/f'extract/analysis/{name}.patch']
    assert not any(path.exists() for path in paths), 'refuse to replace screening inputs'
    paths[0].write_text('pc '+entry+'\n')
    paths[1].write_text(json.dumps({entry:'0x8c09bc2e'},indent=2)+'\n')
    paths[2].write_text(json.dumps({entry:fields},indent=2)+'\n')
    generate(paths[0],paths[3],0x8c0432e2,128,fpscr=0x40001,
             bounded_arguments=True,preserve_fields=True,memory_overrides={entry:fields})
    print('128 original options-menu boundary inputs prepared; no coverage credit')


if __name__ == '__main__':
    main()
