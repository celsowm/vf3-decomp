#!/usr/bin/env python3
"""Audit complete original-image hit-only screens for 65% coverage candidates."""
import argparse
import csv
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / "extract/gamedata/1ST_READ.BIN"


def sha256(path):
    digest = hashlib.sha256()
    with Path(path).open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def reference(path):
    path = Path(path).resolve()
    try:
        return path.relative_to(ROOT).as_posix()
    except ValueError:
        return str(path)


def load_watch(path):
    entries = []
    for line_number, raw in enumerate(Path(path).read_text(encoding="utf-8-sig").splitlines(), 1):
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        parts = line.split()
        if len(parts) == 1:
            value = parts[0]
        elif len(parts) == 2 and parts[0].lower() == "pc":
            value = parts[1]
        else:
            raise ValueError(f"{path}:{line_number}: expected an address or 'pc ADDRESS'")
        address = int(value, 0) & 0xFFFFFFFF
        if address in entries:
            raise ValueError(f"{path}:{line_number}: duplicate watch address {address:#x}")
        entries.append(address)
    if not entries:
        raise ValueError(f"empty watch list: {path}")
    return entries


def load_hits(path):
    with Path(path).open(newline="", encoding="utf-8-sig") as stream:
        rows = list(csv.DictReader(stream))
    if not rows or set(rows[0]) != {"entry", "hits"}:
        raise ValueError(f"{path}: expected entry,hits CSV")
    hits = {}
    for row in rows:
        address = int(row["entry"], 0) & 0xFFFFFFFF
        if address in hits:
            raise ValueError(f"{path}: duplicate entry {address:#x}")
        count = int(row["hits"], 10)
        if count < 0:
            raise ValueError(f"{path}: negative hit count for {address:#x}")
        hits[address] = count
    return hits


def audit(manifests, watch, observer, image=IMAGE):
    watch = Path(watch).resolve()
    observer = Path(observer).resolve()
    image = Path(image).resolve()
    expected = load_watch(watch)
    observer_hash = sha256(observer)
    image_hash = sha256(image)
    runs = []
    seen_states = set()
    for manifest_path in manifests:
        manifest_path = Path(manifest_path).resolve()
        manifest = json.loads(manifest_path.read_text(encoding="utf-8-sig"))
        if Path(manifest["watch"]).resolve() != watch:
            raise ValueError(f"{manifest_path}: manifest uses a different watch list")
        for run in manifest.get("runs", []):
            if run.get("returncode") != 0 or run.get("emulator_returncode") != 0:
                raise ValueError(f"{manifest_path}: nonzero return code in {run.get('name')}")
            if not run.get("frame_complete") or run.get("ran_frames") != run.get("expected_frames"):
                raise ValueError(f"{manifest_path}: incomplete frame run {run.get('name')}")
            state = Path(run["state"]).resolve()
            if state in seen_states:
                raise ValueError(f"duplicate state in hit screen: {state}")
            seen_states.add(state)
            hits_path = Path(run["hits"]).resolve()
            hits = load_hits(hits_path)
            if list(hits) != expected:
                if set(hits) != set(expected):
                    raise ValueError(f"{hits_path}: hit addresses differ from watch list")
                raise ValueError(f"{hits_path}: hit rows do not preserve watch-list order")
            runs.append({
                "name": run["name"],
                "state": reference(state),
                "state_sha256": sha256(state),
                "frames_expected": run["expected_frames"],
                "frames_run": run["ran_frames"],
                "returncode": run["returncode"],
                "frame_complete": True,
                "hits_csv": reference(hits_path),
                "hits_csv_sha256": sha256(hits_path),
                "natural_hits": {f"0x{address:08x}": hits[address] for address in expected},
                "batch_manifest": reference(manifest_path),
                "batch_manifest_sha256": sha256(manifest_path),
            })
    if not runs:
        raise ValueError("no complete hit-screen runs found")
    return {
        "schema": "coverage-65-natural-hit-screen-v1",
        "diagnostic_only": True,
        "coverage_credit": False,
        "observer": reference(observer),
        "observer_sha256": observer_hash,
        "image": reference(image),
        "image_sha256": image_hash,
        "watch": reference(watch),
        "watch_sha256": sha256(watch),
        "watched_entries": [f"0x{address:08x}" for address in expected],
        "runs": runs,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--manifest", action="append", required=True,
                        help="golden_batch.py batch_manifest.json (repeatable)")
    parser.add_argument("--watch", required=True)
    parser.add_argument("--observer", required=True)
    parser.add_argument("--image", default=str(IMAGE))
    parser.add_argument("--out", required=True)
    args = parser.parse_args()
    report = audit(args.manifest, args.watch, args.observer, args.image)
    output = Path(args.out)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    totals = {entry: sum(run["natural_hits"][entry] for run in report["runs"])
              for entry in report["watched_entries"]}
    active = {entry: count for entry, count in totals.items() if count}
    print(f"audited {len(report['runs'])} complete runs; natural hits: {active}")
    print(f"diagnostic only; wrote {output}")


if __name__ == "__main__":
    main()
