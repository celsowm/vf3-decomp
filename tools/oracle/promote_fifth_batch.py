#!/usr/bin/env python3
"""Promote only the fifth batch's complete, independently replayed C bodies."""
import csv
import hashlib
import io
import json
from pathlib import Path

from select_next import union

ROOT=Path(__file__).resolve().parents[2]
AN=ROOT/'extract/analysis'
DEV=[('fifth_dev_replay.json','fifth_primary_cases','src/fight/fifth_adapters.c'),
     ('fifth_leaf_dev_replay.json','fifth_leaf_dev_v6_cases','src/fight/fifth_leaf_adapters.c')]
HOLD=[('fifth_holdout_replay.json','fifth_holdout_cases',None),
      ('fifth_leaf_holdout_replay.json','fifth_leaf_holdout_v6_cases',None)]
FRESH=[('fifth_fresh_replay.json','fifth_fresh_cases',None),
       ('fifth_leaf_fresh_replay.json','fifth_leaf_fresh_v6_cases',None)]


def main():
    reports={name:json.loads((AN/name).read_text()) for name,_,*rest in DEV+HOLD+FRESH}
    campaigns={}
    for _,directory,*rest in DEV+HOLD+FRESH:
        if directory in campaigns: continue
        path=AN/directory
        campaign=json.loads((path/'capsule_manifest.json').read_text())
        batch=json.loads((path/'batch_manifest.json').read_text())
        assert all(run['returncode']==0 and run.get('frame_complete',True) for run in batch['runs'])
        sources={str(Path(run['capsule']).resolve()):(run['name'],run['state'],run['play']) for run in batch['runs']}
        campaigns[directory]=(campaign,batch,sources)
    baseline=json.loads((AN/'coverage.json').read_text())
    assert baseline['ported_unique_bytes']==89720 and baseline['bytes_total']==434656
    spans=list(map(tuple,baseline['ported_spans']))
    assert union(spans)==89720
    sizes={int(row['entry'],16):int(row['size']) for row in csv.DictReader((AN/'funcs_1ST_READ.unsc.bin.csv').open())}
    ranges={}
    for row in csv.DictReader((AN/'function_body_ranges.csv').open()):
        ranges.setdefault(int(row['entry'],16),[]).append((int(row['start'],16),int(row['end'],16)))
    ledger_path=ROOT/'docs/decomp_status.csv'
    original=ledger_path.read_text()
    old={int(row['entry'],16) for row in csv.DictReader(io.StringIO(original)) if row['status'].startswith('ported')}
    bindings_path=ROOT/'tools/golden_bindings.json'
    bindings=json.loads(bindings_path.read_text())
    selected={}; excluded={}; additions=[]

    def validation(entry,choices):
        for report_name,directory,group in choices:
            proof=reports[report_name].get(entry)
            if not proof or not proof['pass']: continue
            manifest,_,sources=campaigns[directory]
            records=manifest['entries'].get(entry,[])
            used={sources.get(str(Path(src['source']).resolve()),(None,))[0]
                  for record in records for src in record['sources']}
            if any((int(item['entry'],16)|0x80000000)==int(entry,16) for run in manifest['runs'] for item in run.get('incomplete',[])): continue
            if records and (group is None or used&group):
                return report_name,directory,sorted(used&group if group else used)
        return None

    for dev_report,directory,port in DEV:
        campaign,batch,sources=campaigns[directory]
        for entry,dev_proof in reports[dev_report].items():
            if not dev_proof['pass']:
                excluded[entry]='Development replay failure'; continue
            records=campaign['entries'].get(entry,[])
            scenarios={(sources[str(Path(src['source']).resolve())][1],sources[str(Path(src['source']).resolve())][2])
                       for record in records for src in record['sources']}
            if len(records)<64 or len(scenarios)<2:
                excluded[entry]='Fewer than 64 distinct cases or two scenarios'; continue
            if any((int(item['entry'],16)|0x80000000)==int(entry,16)
                   for run in campaign['runs'] for item in run.get('incomplete',[])):
                excluded[entry]='Unfinished development invocation'; continue
            # A failure in any untouched campaign disqualifies the entry, even
            # if a different scenario happens to pass.
            if any(entry in reports[name] and not reports[name][entry]['pass']
                   for name,_,_ in HOLD+FRESH):
                excluded[entry]='Held-out or fresh replay failure'; continue
            held=validation(entry,HOLD); fresh=validation(entry,FRESH)
            if not held or not fresh:
                excluded[entry]='Missing independent held-out or fresh invocation'; continue
            e=int(entry,16)
            if e not in sizes or e not in ranges:
                excluded[entry]='Not a frozen baseline body'; continue
            path=ROOT/dev_proof['cases']
            assert path.is_file()
            archive=hashlib.sha256()
            artifacts=sorted(q for q in path.parent.glob(path.stem+'*') if q.is_file())
            for item in artifacts:
                with item.open('rb') as f: digest=hashlib.file_digest(f,'sha256').hexdigest()
                archive.update((item.relative_to(ROOT).as_posix()+'\\0'+digest+'\\n').encode())
            key='fifth:'+entry
            bindings[key]={
                'test':'build/vf3matrixfamily.exe '+entry,
                'golden':path.relative_to(ROOT).as_posix(),
                'strict':True,
                'source':'Complete invocation registers/banked/XF/FPUL/GBR/return-PC/touched-RAM/device-access tape; >=64 distinct cases across >=2 scenarios',
                'port':port,
            }
            proof_names={dev_report,held[0],fresh[0]}
            # Keep every other passing validation proof that actually observed
            # this entry, making the promoted boundary as broad as possible.
            proof_names.update(name for name,_,_ in HOLD+FRESH if entry in reports[name])
            new=e not in old
            selected[entry]={
                'new_credit':new,'size':sizes[e] if new else 0,'binding':key,
                'proofs':{name:reports[name][entry] for name in sorted(proof_names)},
                'scenario_count':len(scenarios),
                'validation_groups':{'heldout':{'report':held[0],'directory':held[1],'runs':held[2]},
                                     'fresh':{'report':fresh[0],'directory':fresh[1],'runs':fresh[2]}},
                'artifacts':{'count':len(artifacts),'sha256':archive.hexdigest()},
            }
            if new:
                line=io.StringIO()
                csv.writer(line,lineterminator='\n').writerow([
                    entry,'ported-invocation',port,sizes[e],
                    'shared C algorithms and static callers; complete invocation and device-tape replay',
                    dev_proof['stdout']+'; held-out and fresh replay; strict registers/banked/XF/FPUL/GBR/return-PC/RAM/device access; see docs/re/fifth_coverage_batch.md'])
                additions.append((entry,line.getvalue().rstrip('\n')))
    gain=union(spans+[span for entry,row in selected.items() if row['new_credit'] for span in ranges[int(entry,16)]])-union(spans)
    print(f'Fifth batch: {len(selected)} bindings, {sum(row["new_credit"] for row in selected.values())} new bodies, +{gain} unique C bytes')
    assert gain>0, 'No strictly verified new body; refusing ledger changes'
    manifest={
        'baseline_unique_bytes':89720,'baseline_spans':baseline['ported_spans'],
        'frozen_body_bytes':434656,'minimum_gain':1,'target_gain':20000,'target_met':gain>=20000,
        'measured_gain':gain,'minimum_cases':64,'minimum_scenarios':2,
        'entries':selected,'excluded':excluded,
        'reports':sorted(reports),'capture_runs':len({str(Path(run['capsule']).resolve()) for _,batch,_ in campaigns.values() for run in batch['runs']}),
        'device_tape_format':'VF3CAP6',
    }
    lines=original.splitlines()
    for entry,line in additions:
        prefix=entry+','
        matches=[i for i,row in enumerate(lines) if row.lower().startswith(prefix)]
        if matches:
            assert len(matches)==1
            lines[matches[0]]=line
        else: lines.append(line)
    ledger_path.write_text('\n'.join(lines)+'\n')
    bindings_path.write_text(json.dumps(bindings,indent=1)+'\n')
    (ROOT/'tools/oracle/fifth_batch.json').write_text(json.dumps(manifest,indent=1)+'\n')


if __name__=='__main__': main()
