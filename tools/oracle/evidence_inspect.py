"""Inspect regression logs, original captures and replay failures without crediting C."""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT/'tools'))
from body_cover import body_spans
from capsules import records
from regression_status import summarize


def digest(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def load(path):
    return json.loads(Path(path).read_text(encoding='utf-8-sig'))


def address(value):
    return int(value, 0)|0x80000000


def fingerprints(sample):
    reads = b''.join(struct.pack('<4I', *event) for event in sample['device'] if not event[3])
    inputs = sample['before']+b''.join(struct.pack('<I', base)+before for base,before,after in sample['pages'])+reads
    outputs = sample['after']+struct.pack('<I', sample['exitpc'])+b''.join(after for base,before,after in sample['pages'])
    outputs += b''.join(struct.pack('<4I', *event) for event in sample['device'])
    return hashlib.sha256(inputs).hexdigest(), hashlib.sha256(outputs).hexdigest()


def status(logs, bindings, suite='portcheck'):
    expected = load(bindings)
    result = []
    for path in logs:
        row = summarize(Path(path).read_text(encoding='utf-8-sig', errors='replace'), expected, suite)
        row['log'] = str(path)
        row['log_state'] = ('COMPLETE_PASS' if row['passed'] else 'COMPLETE_FAIL') if row['complete'] else 'INCOMPLETE'
        result.append(row)
    return dict(diagnostic_only=True, process_liveness_checked=False, logs=result)


def capture(batches, owners, image=None):
    spans = body_spans() if owners else {}
    scenarios = {}
    runs = []
    signatures = defaultdict(dict)
    nondeterministic = set()
    image_data = Path(image).read_bytes() if image else None
    if image:
        from callable_geometry import original_pools
    for batch_path in batches:
        batch = load(batch_path)
        for run in batch['runs']:
            raw = Path(run['capsule'])
            summary_path = Path(str(raw)+'.summary.json')
            summary = load(summary_path)
            state = Path(run['state'])
            state = state if state.is_absolute() else ROOT/state
            state_hash = digest(state)
            scenario = scenarios.setdefault(state_hash, defaultdict(lambda: dict(pcs=set(),inputs=set(),valid=0,devices=0,flags=Counter())))
            count = 0
            for sample in records(raw):
                count += 1
                entry = hex(sample['entry']|0x80000000)
                if owners and entry not in owners:
                    continue
                row = scenario[entry]
                if sample['flags']:
                    row['flags'][sample['flags']] += 1
                    continue
                row['valid'] += 1
                row['devices'] += bool(sample['device'])
                row['pcs'].update(pc|0x80000000 for pc,op in sample['ops'])
                key, signature = fingerprints(sample)
                row['inputs'].add(key)
                if key in signatures[entry] and signatures[entry][key] != signature:
                    nondeterministic.add(entry)
                signatures[entry][key] = signature
                if image_data is not None:
                    original_pools(sample, image_data, sample['ops'])
                    for pc,op in sample['ops']:
                        offset = (pc&0x1fffffff)-0xc010000
                        if not 0 <= offset <= len(image_data)-2 or struct.unpack_from('<H', image_data, offset)[0] != op:
                            raise ValueError(f'Nonoriginal opcode at {pc:#x} in {raw}')
            accounting = count == summary['completed'] == summary['started'] and not summary['incomplete'] and not summary['unaccounted']
            runs.append(dict(batch=str(batch_path),name=run['name'],state_sha256=state_hash,
                records=count,started=summary['started'],completed=summary['completed'],
                incomplete=summary['incomplete'],unaccounted=summary['unaccounted'],complete_accounting=accounting,
                frame_complete=run.get('frame_complete',False),ran_frames=run.get('ran_frames'),returncode=run['returncode']))
    output = []
    for state_hash, entries in scenarios.items():
        rows = {}
        for entry,row in entries.items():
            owner = owners.get(entry) if owners else None
            required = {pc for a,z in spans[int(owner,16)] for pc in range(a,z,2)} if owner else set()
            missing = sorted(required-row['pcs'])
            rows[entry] = dict(owner=owner,valid_records=row['valid'],distinct_inputs=len(row['inputs']),
                device_records=row['devices'],excluded_flags=dict(row['flags']),
                body_bytes=len(required)*2,covered_body_bytes=len(required&row['pcs'])*2,
                missing_body_bytes=len(missing)*2,missing_pcs=[hex(pc) for pc in missing])
        output.append(dict(state_sha256=state_hash,entries=rows))
    return dict(diagnostic_only=True,coverage_credit=False,original_image_checked=image is not None,
        runs=runs,scenarios=output,nondeterministic_entries=sorted(nondeterministic))


def case_bytes(blob, windows, address, size):
    physical = address & 0x1fffffff
    file_offset = 0
    for base, length in windows:
        if base <= physical and size <= base + length - physical:
            start = file_offset + physical - base
            return blob[start:start + size]
        file_offset += length
    return None


def replay_case(directory, entry, number, window=None, preview=16,
                addresses=(), byte_count=4):
    if number < 1 or preview < 1:
        raise ValueError('case number and preview length must be positive')
    if not 1 <= byte_count <= 16:
        raise ValueError('RAM read width must be between 1 and 16 bytes')
    directory = Path(directory)
    stem = f'f_{entry:08x}'
    lines = (directory/(stem+'.cases')).read_text().splitlines()
    if number > len(lines):
        raise ValueError('case number exceeds corpus size')
    fields = lines[number-1].split()
    count = int(fields[75])
    windows = [(int(fields[76+2*n],16),int(fields[77+2*n],16)) for n in range(count)]
    after_index = 76+2*count
    after_count = int(fields[after_index+1])
    after_windows = [(int(fields[after_index+2+2*n],16),int(fields[after_index+3+2*n],16)) for n in range(after_count)]
    if windows != after_windows:
        raise ValueError('input/output window maps differ')
    before = (directory/fields[74]).read_bytes()
    after = (directory/fields[after_index]).read_bytes()
    if len(before) != len(after) or len(before) != sum(size for base,size in windows):
        raise ValueError('RAM files do not match window lengths')
    if window is not None and not 0 <= window < count:
        raise ValueError('window index exceeds window map')
    offset = 0
    rows = []
    for index,(base,size) in enumerate(windows):
        if window is None or index == window:
            rows.append(dict(index=index,base=hex(base),size=size,
                before=before[offset:offset+min(size,preview)].hex(),after=after[offset:offset+min(size,preview)].hex()))
        offset += size
    manifest_path = directory/'capsule_manifest.json'
    metadata = None
    if manifest_path.is_file():
        manifest = load(manifest_path)
        metadata = manifest.get('entries', {}).get(hex(entry), [])
        metadata = metadata[number-1] if number <= len(metadata) else None
    registers = {f'r{index}': f'0x{int(fields[index], 16):08x}'
                 for index in range(16)}
    ram_reads = []
    for address in addresses:
        old = case_bytes(before, windows, address, byte_count)
        new = case_bytes(after, windows, address, byte_count)
        ram_reads.append(dict(address=hex(address),size=byte_count,
            before=None if old is None else old.hex(),
            after=None if new is None else new.hex()))
    return dict(diagnostic_only=True,case=number,entry=hex(entry),sp=fields[15],r4=fields[4],
                registers=registers,
                sources=metadata.get('sources') if metadata else None,
                windows=rows,ram_reads=ram_reads)


def profile_case_memory(directory, entry, register, offsets, byte_count=4,
                        limit=8, widths=None, joint=False):
    widths = widths or {}
    if (not 0 <= register < 16 or not offsets or not 1 <= byte_count <= 4 or
            limit < 0 or any(offset not in offsets or not 1 <= width <= 4
                             for offset, width in widths.items())):
        raise ValueError('profile requires a GPR, offsets, byte widths 1..4, and nonnegative limit')
    directory = Path(directory)
    stem = f'f_{entry:08x}'
    lines = (directory/(stem+'.cases')).read_text().splitlines()
    profiles = {offset: {} for offset in offsets}
    examples = {offset: [] for offset in offsets}
    missing = {offset: 0 for offset in offsets}
    joint_profiles = {}
    joint_missing = 0
    for case_number, line in enumerate(lines, 1):
        fields = line.split()
        if len(fields) < 78:
            raise ValueError(f'case {case_number} is truncated')
        registers = [int(value, 16) for value in fields[:37]]
        base = registers[register]
        count = int(fields[75])
        windows = [(int(fields[76+2*n],16), int(fields[77+2*n],16))
                   for n in range(count)]
        blob = (directory/fields[74]).read_bytes()
        case_values = {}
        for offset in offsets:
            address = (base + offset) & 0xffffffff
            width = widths.get(offset, byte_count)
            raw = case_bytes(blob, windows, address, width)
            if raw is None:
                missing[offset] += 1
                continue
            value = int.from_bytes(raw, 'little')
            case_values[offset] = value
            profiles[offset][value] = profiles[offset].get(value, 0) + 1
            if len(examples[offset]) < limit:
                examples[offset].append(dict(case=case_number,base=hex(base),
                    address=hex(address),value=hex(value)))
        if joint:
            if len(case_values) != len(offsets):
                joint_missing += 1
            else:
                key = tuple(case_values[offset] for offset in offsets)
                joint_profiles[key] = joint_profiles.get(key, 0) + 1
    result = {}
    for offset in offsets:
        result[hex(offset)] = dict(captured=sum(profiles[offset].values()),
            uncaptured=missing[offset],
            values=[dict(value=hex(value),count=count)
                    for value,count in sorted(profiles[offset].items(),
                                              key=lambda item:(-item[1],item[0]))],
            examples=examples[offset])
    report = dict(diagnostic_only=True,entry=hex(entry),cases=len(lines),
        base_register=f'r{register}',byte_count=byte_count,
        byte_widths={hex(offset): widths.get(offset, byte_count) for offset in offsets},
        offsets=result)
    if joint:
        report['joint'] = dict(
            fields=[hex(offset) for offset in offsets],
            captured=sum(joint_profiles.values()),
            uncaptured=joint_missing,
            values=[dict(values={hex(offset): hex(value)
                                 for offset, value in zip(offsets, key)},
                         count=count)
                    for key, count in sorted(joint_profiles.items(),
                                             key=lambda item:(-item[1],item[0]))])
    return report


def offset_width(value):
    try:
        offset_text, width_text = value.split(':', 1)
        return int(offset_text, 0), int(width_text, 0)
    except ValueError as exc:
        raise argparse.ArgumentTypeError('expected OFFSET:WIDTH, for example 0x61:1') from exc


def gpr_index(value):
    value = value.lower()
    if not value.startswith('r') or not value[1:].isdigit():
        raise argparse.ArgumentTypeError('expected a GPR name r0..r15')
    index = int(value[1:])
    if not 0 <= index < 16:
        raise argparse.ArgumentTypeError('GPR index must be in 0..15')
    return index


def sample_info(capsule, invocation, pcs=(), tail=10):
    sample = next((r for r in records(capsule) if r['id']==invocation),None)
    if sample is None:
        raise ValueError('invocation ID is not in this capsule')
    key, signature = fingerprints(sample)
    selected = {pc&0x1fffffff for pc in pcs}
    hits = [dict(index=n,pc=hex(pc),opcode=f'{op:04x}') for n,(pc,op) in enumerate(sample['ops'])
            if (pc&0x1fffffff) in selected]
    stores = [dict(index=n,pc=hex(pc),opcode=f'{op:04x}') for n,(pc,op) in enumerate(sample['ops'])
              if op>>12==15 and op&15 in (7,10,11)]
    return dict(diagnostic_only=True,invocation=sample['id'],entry=hex(sample['entry']),exit=hex(sample['exitpc']),
        flags=sample['flags'],nstate=sample['nstate'],pages=len(sample['pages']),instructions=len(sample['ops']),
        device_events=len(sample['device']),input_sha256=key,output_sha256=signature,pc_hits=hits,
        float_store_instruction_count=len(stores),last_float_stores=stores[-20:],
        tail=[dict(pc=hex(pc),opcode=f'{op:04x}') for pc,op in sample['ops'][-tail:]])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out',type=Path,help='optional new JSON report; existing files are preserved')
    sub = parser.add_subparsers(dest='command',required=True)
    progress = sub.add_parser('status',help='inspect log completion; this does not establish process liveness')
    progress.add_argument('logs',nargs='+',type=Path)
    progress.add_argument('--bindings',type=Path,default=ROOT/'tools/golden_bindings.json')
    progress.add_argument('--suite',choices=('portcheck','verify_all'),default='portcheck')
    corpus = sub.add_parser('capture',help='summarize complete raw captures by original state and entry')
    corpus.add_argument('--batch',action='append',type=Path,required=True)
    corpus.add_argument('--owners',type=Path)
    corpus.add_argument('--image',type=Path,help='also verify executed original instructions and literal pools')
    case = sub.add_parser('case',help='locate a one-based replay failure and its original invocation')
    case.add_argument('directory',type=Path)
    case.add_argument('--entry',type=address,required=True)
    case.add_argument('--case',type=int,required=True)
    case.add_argument('--window',type=int,help='zero-based RAM window from native failure output')
    case.add_argument('--preview',type=int,default=16)
    case.add_argument('--address',type=address,action='append',default=[],
                      help='read a captured RAM address; may be repeated (mirrors accepted)')
    case.add_argument('--bytes',type=int,default=4,help='bytes to read at each --address (1..16)')
    profile = sub.add_parser('profile',help='summarize RAM values at GPR-relative offsets across a corpus')
    profile.add_argument('directory',type=Path)
    profile.add_argument('--entry',type=address,required=True)
    profile.add_argument('--register',type=gpr_index,required=True,help='base GPR, such as r5')
    profile.add_argument('--offset',type=lambda s:int(s,0),action='append',required=True,
                         help='register-relative RAM offset; may be repeated')
    profile.add_argument('--bytes',type=int,default=2,help='little-endian width (1..4)')
    profile.add_argument('--width',type=offset_width,action='append',default=[],
                         help='override one field width as OFFSET:BYTES; may be repeated')
    profile.add_argument('--joint',action='store_true',
                         help='also report per-case combinations across all requested offsets')
    profile.add_argument('--limit',type=int,default=8,help='examples to show per offset')
    raw = sub.add_parser('sample',help='inspect an original invocation ID and selected instruction PCs')
    raw.add_argument('capsule',type=Path)
    raw.add_argument('--id',type=int,required=True)
    raw.add_argument('--pc',type=address,action='append',default=[])
    args = parser.parse_args()
    if args.out and args.out.exists():
        parser.error('refusing to overwrite an evidence report')
    if args.command=='status':result=status(args.logs,args.bindings,args.suite)
    elif args.command=='capture':result=capture(args.batch,load(args.owners) if args.owners else {},args.image)
    elif args.command=='case':result=replay_case(args.directory,args.entry,args.case,args.window,
        args.preview,args.address,args.bytes)
    elif args.command=='profile':result=profile_case_memory(args.directory,args.entry,
        args.register,args.offset,args.bytes,args.limit,dict(args.width),args.joint)
    else:result=sample_info(args.capsule,args.id,args.pc)
    text=json.dumps(result,indent=2)+'\n'
    if args.out:
        args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(text)
    print(text,end='')


if __name__=='__main__':main()
