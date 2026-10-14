#!/usr/bin/env python3
import json, csv

j = json.load(open('extract/analysis/coverage.json'))
print('=== FINAL STATUS ===')
print(f'Pure C union: {j["ported_unique_bytes"]} bytes ({100*j["ported_unique_bytes"]/j["bytes_total"]:.4f}%)')
target = int(j["bytes_total"] * 0.7)
print(f'Target 70%: {target} bytes')
gap = target - j["ported_unique_bytes"]
print(f'Gap: {gap} bytes ({100*gap/j["bytes_total"]:.4f} pp)')

rows = list(csv.DictReader(open('docs/decomp_status.csv')))
ported = [r for r in rows if r['status'].startswith('ported')]
print(f'Total ported entries: {len(ported)}')
replay = [r for r in ported if 'replay_scan' in r['oracle']]
print(f'Replay_scan promotions: {len(replay)}')
print(f'Replay_scan bytes: {sum(int(r["size"]) for r in replay)}')

rows2 = list(csv.DictReader(open('extract/analysis/port_plan_70.csv')))
ported_set = set(r['entry'].lower() for r in csv.DictReader(open('docs/decomp_status.csv')) if r['status'].startswith('ported'))
unported = [r for r in rows2 if r['entry'].lower() not in ported_set and r['campaign'] in ('A','B','C')]
print(f'Total unported A/B/C: {len(unported)} bytes: {sum(int(r["size"]) for r in unported)}')
print('Top 10:')
for r in sorted(unported, key=lambda x: -int(x['size']))[:10]:
    print(f'  {r["entry"]} {r["size"]} {r["campaign"]} {r["closure_ok"]}')