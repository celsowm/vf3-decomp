"""Preserve strip proof dependencies before subsequent build/ledger changes."""
import hashlib
import json
from pathlib import Path
import subprocess

ROOT = Path(__file__).resolve().parents[2]
CACHE = Path('C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence')


def digest(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    out = CACHE/'strip_parent_accepted_historical_v1'
    out.mkdir(exist_ok=False)
    qualified = CACHE/'strip_parent_qualified_development_freeze_v1.json'
    acceptance = ROOT/'tools/oracle/strip_parent_qualification_v1.json'
    sources = CACHE/'strip_parent_integrated_dev_v1_complete_sources/manifest.json'
    references = {}
    for proof in (qualified, acceptance):
        references[str(proof)] = dict(path=str(proof), sha256=digest(proof))
        for row in json.loads(proof.read_text())['references']:
            key = row['path']
            assert key not in references or references[key]['sha256'] == row['sha256']
            references[key] = row
    archived = []
    for row in references.values():
        path = Path(row['path'])
        try:
            relative = path.relative_to(ROOT)
        except ValueError:
            relative = None
        if relative and relative.parts[0] in ('tools', 'docs', 'build', 'src'):
            destination = out/relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            data = path.read_bytes()
            if hashlib.sha256(data).hexdigest() != row['sha256']:
                assert relative.as_posix() == 'tools/golden_bindings.json'
                data = subprocess.check_output(['git', 'show', 'a2db606:'+relative.as_posix()], cwd=ROOT)
                if hashlib.sha256(data).hexdigest() != row['sha256']:
                    data = data.replace(b'\n', b'\r\n')
            assert hashlib.sha256(data).hexdigest() == row['sha256'], str(path)
            destination.write_bytes(data)
            archived.append(dict(path=str(destination), sha256=row['sha256'], original_path=str(path)))
        else:
            assert digest(path) == row['sha256'], str(path)
            archived.append(dict(row))
    closure = json.loads(sources.read_text())
    assert len(closure['files']) == 400
    for row in closure['files']:
        assert digest(sources.parent/row['path']) == row['sha256']
    manifest = dict(historical_only=True, coverage_credit=False,
        qualified_development_sha256=digest(qualified), acceptance_sha256=digest(acceptance),
        compiled_source_archive=dict(path=str(sources), sha256=digest(sources)),
        references=archived)
    destination = ROOT/'tools/oracle/strip_parent_historical_archive_v1.json'
    assert not destination.exists()
    destination.write_text(json.dumps(manifest, indent=2)+'\n')
    print(f'Historical strip evidence PASS: {len(archived)} pinned references; 400 compiled inputs')


if __name__ == '__main__':
    main()
