"""Summarize capture progress, replay reports, and series audits without polling processes."""
import argparse
import json
from pathlib import Path
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('reports', nargs='+', type=Path, help='progress/replay/audit JSON, or isolated capture directory')
    args = parser.parse_args()
    failed = False
    for item in args.reports:
        path = item / 'progress.json' if item.is_dir() else item
        try:
            report = json.loads(path.read_text())
            if isinstance(report, list):
                errors = sum(r['returncode'] != 0 for r in report)
                cases = sum(r.get('complete_cases', 0) for r in report)
                last = report[-1].get('entry', '-') if report else '-'
                print(f'{path}: {len(report)} attempted roots; {errors} failed; {cases} cases; last={last}')
            elif 'audits' in report and 'milestones' in report:
                errors = sum(r['returncode'] != 0 for r in report['audits'])
                print(f"{path}: {len(report['audits'])}/{len(report['milestones'])} audits; "
                      f"{errors} failed; complete={report['complete']}; target_met={report['target_met']}")
            elif isinstance(report, dict) and all(isinstance(r, dict) and 'pass' in r for r in report.values()):
                errors = sum(not r['pass'] for r in report.values())
                print(f'{path}: {len(report) - errors}/{len(report)} replay entries passed; {errors} failed')
            else:
                raise ValueError('unrecognized report schema')
            failed |= bool(errors)
        except (OSError, ValueError, KeyError, TypeError) as error:
            print(f'{path}: {error}', file=sys.stderr)
            failed = True
    return int(failed)


if __name__ == '__main__':
    sys.exit(main())
