"""Retain identical audio evidence at every path using verified local hard links."""
import argparse
import json
import os
from pathlib import Path
from audio_determinism import ROOT, sha


def retain_hard_link(path, canonical, digest):
    allowed = (ROOT/'extract/analysis').resolve()
    for p in (path,canonical):
        if p.is_symlink() or not p.resolve().is_relative_to(allowed):
            raise ValueError('audio evidence path must be local and regular')
    if canonical.stat().st_ino == path.stat().st_ino:
        return False
    if sha(canonical) != digest or sha(path) != digest:
        raise ValueError('evidence changed during deduplication')
    temporary = path.with_name(path.name+'.hardlink-tmp')
    os.link(canonical, temporary)
    os.replace(temporary, path)
    if sha(path) != digest:
        raise ValueError('hard-link reconstruction differs')
    return True


def deduplicate(directories):
    allowed = (ROOT/'extract/analysis').resolve()
    groups, linked, saved = {}, [], 0
    for directory in directories:
        directory = directory.resolve()
        if not directory.is_relative_to(allowed):
            raise ValueError('audio evidence directory outside extract/analysis')
        for path in sorted(directory.iterdir()):
            if not (path.name.endswith('.audio') or path.name.endswith('.audio.gz')):
                continue
            if path.is_symlink() or not path.resolve().is_relative_to(allowed):
                raise ValueError('audio evidence path must be local and regular')
            digest = sha(path)
            key = (path.stat().st_size, digest)
            canonical = groups.setdefault(key, path)
            # Both complete byte streams remain available at their original paths.
            if not retain_hard_link(path,canonical,digest): continue
            saved += key[0]
            linked.append(dict(path=str(path), canonical=str(canonical), sha256=digest))
    return dict(coverage_credit=False, retained_all_paths=True,
                estimated_bytes_saved=saved, hard_links=linked)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--dir', type=Path, action='append', required=True)
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    result = deduplicate(a.dir)
    a.out.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(f"Retained {len(result['hard_links'])} duplicate paths; {result['estimated_bytes_saved']/1024**3:.2f} GiB saved")


if __name__ == '__main__':
    main()
