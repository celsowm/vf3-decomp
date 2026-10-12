"""Extract fixed ABI addresses for the named triangle clipping C model.

This emits metadata, not translated instructions or expected outputs. The C
model implements the topology and stack semantics independently. Original
opcode assertions keep the metadata limited to this verified kernel family.
"""
import hashlib
import json
import struct
from pathlib import Path
from coverage_65_batch_clip_inputs import OWNERS

ROOT = Path(__file__).resolve().parents[2]


def main():
    image_path = ROOT / 'extract/gamedata/1ST_READ.BIN'
    image = image_path.read_bytes()

    def instruction(pc):
        return struct.unpack_from('<H', image, pc - 0x0c010000)[0]

    def literal(pc):
        op = instruction(pc)
        assert op >> 12 == 13
        address = ((pc+4) & ~3) + (op & 255)*4
        value = struct.unpack_from('<I', image, address - 0x0c010000)[0]
        return address, value

    profiles = []
    for cached_entry, owner in OWNERS.items():
        entry = cached_entry & 0x1fffffff
        assert instruction(entry) == 0x2fa6 and instruction(entry+2) == 0x2f96
        assert instruction(entry+0x3e) == 0xff0b
        stride = instruction(entry+0x4e)
        assert stride in (0x7802, 0x7806, 0x780a)
        colored = instruction(entry+0x78) != 0xe001
        topology = entry + (0x92 if colored else 0x78)
        assert [instruction(topology+i*2) for i in range(3)] == [0xe001, 0x2049, 0x4015]
        cleanup = next(pc for pc in range(topology, topology+0x200, 2)
                       if instruction(pc) == 0xe101 and instruction(pc+2) == 0x4118
                       and instruction(pc+4) == 0x3f1c)
        calls = []
        masks = []
        for pc in range(topology, cleanup, 2):
            op = instruction(pc)
            if op >> 12 == 11:
                displacement = op & 4095
                if displacement & 2048:
                    displacement -= 4096
                assert instruction(pc+2) == 9
                calls.append((pc+4, pc+4+displacement*2))
            elif op >> 8 == 0xd0:
                address, value = literal(pc)
                assert value in (2, 4)
                masks.append(address)
        assert len(calls) == 21 and len(masks) == 4
        copy_target, edge_target = calls[0][1], calls[2][1]
        assert {target for _, target in calls} == {copy_target, edge_target}
        selector, simple_shader, color_shader = 0, 0, 0
        if colored:
            selector, value = literal(entry+0x78)
            assert value == 0x0c055b8c
            color_shader, _ = literal(entry+0x80)
            simple_shader, _ = literal(topology-2)
        profiles.append({'entry': entry, 'owner': owner, 'stride': stride & 255,
                         'selector_pool': selector, 'simple_shader_pool': simple_shader,
                         'color_shader_pool': color_shader, 'copy_target': copy_target,
                         'edge_target': edge_target, 'mask_pools': masks,
                         'returns': [returned for returned, _ in calls]})
    target = ROOT / 'extract/analysis/coverage_65_clip_profiles_v1.json'
    assert not target.exists(), 'refuse to replace retained ABI metadata'
    target.write_text(json.dumps({'coverage_credit': False, 'profiles': profiles,
                      'image': str(image_path), 'image_sha256': hashlib.sha256(image).hexdigest()}, indent=2)+'\n')
    lines = ['/* Fixed original callback/pool/return addresses; no opcodes or output values. */']
    for row in profiles:
        values = [row[key] for key in ('entry', 'stride', 'selector_pool', 'simple_shader_pool',
                                      'color_shader_pool', 'copy_target', 'edge_target')]
        lines.append('    {' + ','.join(f'0x{x:08x}u' for x in values) + ',')
        lines.append('     {' + ','.join(f'0x{x:08x}u' for x in row['mask_pools']) + '},')
        lines.append('     {' + ','.join(f'0x{x:08x}u' for x in row['returns']) + '}},')
    (ROOT / 'src/fight/clip_profiles.inc').write_text('\n'.join(lines)+'\n')
    print(f'{len(profiles)} fixed clipping ABI profiles; zero coverage credit')


if __name__ == '__main__':
    main()
