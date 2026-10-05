"""Summarize a running or completed portcheck/verify_all log without polling."""
import argparse
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[2]


def summarize(log, expected, suite='portcheck'):
    # Parallel replay progress precedes a second, formatted final summary.
    # Count only the progress rows, deduplicating repeated reports of a binding.
    rows = {}
    for name, status in re.findall(r'^binding (.+): (\S+)\s*$', log, re.M):
        rows[name] = status
    if 'golden-bound ports:\n' in log:
        final = log.rsplit('golden-bound ports:\n', 1)[1]
        for name, status in re.findall(
                r'^  (\S+)\s+(PASS|FAIL|MISSING-TEST|MISSING-GOLDEN)\b', final, re.M):
            rows[name] = status
    endings = re.findall(r'^(portcheck|verify_all): (PASS|FAIL)\s*$', log, re.M)
    terminal = dict(endings)
    failures = sorted(name for name, status in rows.items() if status != 'PASS')
    errors = bool(re.search(r'^Traceback|^FAILED \(|^\S+Error:', log, re.M))
    complete = suite in terminal
    passed = complete and not errors and not failures and all(
        value == 'PASS' for value in terminal.values())
    if len(rows) != len(expected) or any(name not in expected for name in rows):
        passed = False
    return dict(expected_bindings=len(expected), reported_bindings=len(rows),
                failures=failures, errors=errors, complete=complete, passed=passed,
                terminal=terminal, last_lines=log.splitlines()[-3:])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('log', type=Path)
    parser.add_argument('--bindings', type=Path, default=ROOT / 'tools/golden_bindings.json')
    parser.add_argument('--out', type=Path)
    parser.add_argument('--suite', choices=('portcheck', 'verify_all'), default='portcheck',
                        help='terminal marker to await; use verify_all for the full repository gate')
    args = parser.parse_args()
    data = summarize(args.log.read_text(encoding='utf-8-sig', errors='replace'),
                     json.loads(args.bindings.read_text()), args.suite)
    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(data, indent=1) + '\n')
    state = ('PASS' if data['passed'] else 'FAIL') if data['complete'] else 'RUNNING'
    print(f"{data['reported_bindings']}/{data['expected_bindings']} bindings; "
          f"{len(data['failures'])} replay failures; {state}")
    for line in data['last_lines']:
        print(line)
    return int(bool(data['failures'] or data['errors'] or
                    (data['complete'] and not data['passed'])))


if __name__ == '__main__':
    raise SystemExit(main())
