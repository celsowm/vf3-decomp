"""Select original prologue leads absent from retained isolated probe history."""
import argparse
import json
from pathlib import Path
from campaign_io import attempted_entries, read_watch, write_watch

ROOT = Path(__file__).resolve().parents[2]


def select(parents, history, excluded=()):
    tried = attempted_entries(progress_files=history) | set(excluded)
    return {int(parent, 0): [int(child, 0) for child in children]
            for parent, children in parents.items() if int(parent, 0) not in tried}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--parents', type=Path, required=True)
    parser.add_argument('--history', default='extract/analysis/*/progress.json')
    parser.add_argument('--exclude-watch', type=Path, action='append', default=[],
                        help='reserve parents already scheduled by another capture shard')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--children-out', type=Path, required=True)
    parser.add_argument('--report', type=Path, required=True)
    args = parser.parse_args()
    history = sorted(ROOT.glob(args.history))
    parents = json.loads(args.parents.read_text())['parents']
    excluded = {entry for watch in args.exclude_watch for entry in read_watch(watch)}
    selected = select(parents, history, excluded)
    write_watch(args.out, selected, 'Previously unattempted prologue leads; verify original contract.')
    write_watch(args.children_out, {child for parent, children in selected.items()
                for child in [parent] + children}, 'Unattempted parents and frozen children; no credit.')
    args.report.write_text(json.dumps(dict(advisory=True, history=[str(p) for p in history],
        reserved=[hex(entry) for entry in sorted(excluded)],
        parents={hex(parent): [hex(child) for child in children]
                 for parent, children in selected.items()}), indent=1) + '\n')
    print(f'{len(history)} histories; {len(selected)}/{len(parents)} unattempted parents')


if __name__ == '__main__':
    main()
