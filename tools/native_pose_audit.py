#!/usr/bin/env python3
"""Build a repeatable multi-state native fighter-pose evidence bundle.

For each retained savestate and actor this runs the pose exporter, records the
actor/motion fields and basis quality, and retains matrix and joint bytes. For
each ``--model ACTOR[:KIND]=POL`` mapping it exports slot/matrix AABB
candidates only for poses whose actor kind matches and whose 23 matrix rows
all have usable basis vectors. The report is
diagnostic: it does not infer fighter names, channel meanings, or rig mappings.

Example:
  python tools/native_pose_audit.py \
      --image extract/exe/1ST_READ.unsc.bin \
      --state-dir tools/emu/flycast-build/data --pattern 'vf3_2[6-9].state' \
      --actor 0x0c1fefe4 --actor 0x0c20138c \
      --model 0x0c20138c:7=extract/gamedata/MKAO_JAC.POL \
      --out extract/analysis/native_pose_audit_s26_s29_v4
"""

from __future__ import annotations

import argparse
import csv
import hashlib
import json
import math
from pathlib import Path

from pose_slot_matrix_report import MATRIX_COUNT, report as matrix_report
from pose_state_inventory import DEFAULT_IMAGE_ADDRESS, number
from pose_state_inventory import inspect_one as inspect_pose

ROOT = Path(__file__).resolve().parents[1]


def model_mapping(text: str) -> tuple[int, int | None, Path]:
    actor_text, separator, path_text = text.partition("=")
    if not separator or not path_text:
        raise argparse.ArgumentTypeError("expected ACTOR[:KIND]=POL_PATH")
    actor_text, kind_separator, kind_text = actor_text.partition(":")
    try:
        actor = number(actor_text)
    except argparse.ArgumentTypeError as exc:
        raise argparse.ArgumentTypeError(str(exc)) from exc
    kind = None
    if kind_separator:
        try:
            kind = number(kind_text)
        except argparse.ArgumentTypeError as exc:
            raise argparse.ArgumentTypeError(f"invalid actor kind: {exc}") from exc
        if kind > 0xFF:
            raise argparse.ArgumentTypeError("actor kind must fit in one byte")
    return actor, kind, Path(path_text)


def relative(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return str(path.resolve())


def csv_value(value: object) -> object:
    if isinstance(value, (list, dict)):
        return json.dumps(value, separators=(",", ":"), allow_nan=False)
    return value


def write_candidates(path: Path, rows: list[dict[str, object]]) -> None:
    fields = list(rows[0]) if rows else ["slot"]
    with path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields)
        writer.writeheader()
        writer.writerows({key: csv_value(value) for key, value in row.items()}
                         for row in rows)


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("states", nargs="*", type=Path,
                        help="savestates to inspect")
    parser.add_argument("--state-dir", type=Path,
                        help="include matching savestates from this directory")
    parser.add_argument("--pattern", default="vf3_*.state",
                        help="state filename glob for --state-dir")
    parser.add_argument("--image", type=Path, required=True,
                        help="exact 1ST_READ image used by the pose exporter")
    parser.add_argument("--image-address", type=number,
                        default=DEFAULT_IMAGE_ADDRESS,
                        help=f"image load address (default {DEFAULT_IMAGE_ADDRESS:#x})")
    parser.add_argument("--actor", type=number, action="append", required=True,
                        help="actor record address; repeat for multiple actors")
    parser.add_argument("--model", type=model_mapping, action="append", default=[],
                        metavar="ACTOR[:KIND]=POL",
                        help="tagged POL model; optional +0x61 actor-kind filter")
    parser.add_argument("--out", type=Path, required=True,
                        help="new output directory; existing paths are refused")
    parser.add_argument("--basis-epsilon", type=float, default=1e-6,
                        help="minimum matrix basis length (default 1e-6)")
    args = parser.parse_args(argv)

    if not args.states and not args.state_dir:
        parser.error("provide savestate paths or --state-dir")
    if len(set(args.actor)) != len(args.actor):
        parser.error("--actor values must be unique")
    if len({actor for actor, _kind, _path in args.model}) != len(args.model):
        parser.error("each actor may have at most one --model mapping")
    if any(actor not in args.actor for actor, _kind, _path in args.model):
        parser.error("every --model actor must also appear in --actor")
    if not math.isfinite(args.basis_epsilon) or args.basis_epsilon < 0:
        parser.error("--basis-epsilon must be finite and nonnegative")

    states = [path.resolve() for path in args.states]
    if args.state_dir:
        state_dir = args.state_dir.resolve()
        if not state_dir.is_dir():
            parser.error(f"state directory does not exist: {state_dir}")
        states.extend(path.resolve() for path in state_dir.glob(args.pattern)
                      if path.is_file())
    states = sorted(set(states), key=lambda path: str(path).casefold())
    if not states or any(not state.is_file() for state in states):
        parser.error("one or more savestate paths do not exist or matched no files")
    image = args.image.resolve()
    if not image.is_file():
        parser.error(f"game image does not exist: {image}")
    models: dict[int, tuple[int | None, Path, bytes]] = {}
    for actor, kind, path in args.model:
        resolved = path.resolve()
        if not resolved.is_file():
            parser.error(f"POL model does not exist: {resolved}")
        try:
            models[actor] = (kind, resolved, resolved.read_bytes())
        except OSError as exc:
            parser.error(f"cannot read POL model {resolved}: {exc}")

    out = args.out.resolve()
    try:
        out.relative_to(ROOT)
    except ValueError:
        parser.error("--out must be inside the repository")
    if out.exists():
        parser.error(f"refusing to replace existing output directory: {out}")

    matrix_dir = out / "matrices"
    joint_dir = out / "joints"
    matrix_dir.mkdir(parents=True)
    joint_dir.mkdir(parents=True)

    inventory: list[dict[str, object]] = []
    candidates: list[dict[str, object]] = []
    failures = 0
    for state in states:
        for actor in args.actor:
            matrix_path = matrix_dir / f"{state.stem}_actor_{actor:08x}.bin"
            joint_path = joint_dir / f"{state.stem}_actor_{actor:08x}.bin"
            row = inspect_pose(state, image, args.image_address, actor,
                               matrix_path, joint_path, args.basis_epsilon)
            row["state"] = relative(state)
            row["matrix_bin"] = relative(matrix_path)
            row["joint_bin"] = relative(joint_path)
            inventory.append(row)
            if "error" in row:
                failures += 1
                continue

            model = models.get(actor)
            if model is None:
                continue
            expected_kind, model_path, model_data = model
            actual_kind = int(str(row.get("actor_byte_0x61", "0")), 0)
            if expected_kind is not None and actual_kind != expected_kind:
                candidates.append({
                    "state": relative(state),
                    "actor": f"0x{actor:08x}",
                    "actor_kind": actual_kind,
                    "expected_kind": expected_kind,
                    "pol": relative(model_path),
                    "status": "skipped_kind_mismatch",
                })
                continue
            if row.get("basis_usable_rows") != MATRIX_COUNT:
                candidates.append({
                    "state": relative(state),
                    "actor": f"0x{actor:08x}",
                    "actor_kind": actual_kind,
                    "pol": relative(model_path),
                    "status": "skipped_degenerate_pose",
                    "usable_rows": row.get("basis_usable_rows"),
                    "matrix_rows": row.get("matrix_count"),
                })
                continue
            try:
                result = matrix_report(model_data, matrix_path.read_bytes())
                candidate_rows = result["candidates"]
                csv_path = out / f"{state.stem}_actor_{actor:08x}_slot_matrix.csv"
                write_candidates(csv_path, candidate_rows)
            except (OSError, ValueError, OverflowError) as exc:
                failures += 1
                candidates.append({
                    "state": relative(state),
                    "actor": f"0x{actor:08x}",
                    "actor_kind": actual_kind,
                    "pol": relative(model_path),
                    "status": "error",
                    "error": str(exc),
                })
                continue
            candidates.append({
                "state": relative(state),
                "actor": f"0x{actor:08x}",
                "actor_kind": actual_kind,
                "pol": relative(model_path),
                "status": "diagnostic_candidates",
                "slot_count": result["slot_count"],
                "candidate_count": result["candidate_count"],
                "csv": relative(csv_path),
            })

    report = {
        "diagnostic_only": True,
        "image": relative(image),
        "image_sha256": hashlib.sha256(image.read_bytes()).hexdigest(),
        "actors": [f"0x{actor:08x}" for actor in args.actor],
        "states": [relative(state) for state in states],
        "inventory": inventory,
        "slot_matrix_reports": candidates,
        "limitations": [
            "Actor bytes are reported without assigning fighter names.",
            "Usable matrix bases do not establish a POL-slot or MT-channel mapping.",
            "Transformed AABBs are review candidates, not an inferred rig.",
        ],
    }
    manifest = out / "pose_audit.json"
    manifest.write_text(json.dumps(report, indent=2, allow_nan=False) + "\n",
                         encoding="utf-8")

    usable = sum(row.get("basis_usable_rows") == MATRIX_COUNT
                 for row in inventory if "error" not in row)
    mapped = sum(row.get("status") == "diagnostic_candidates"
                 for row in candidates)
    skipped = sum(row.get("status") == "skipped_degenerate_pose"
                  for row in candidates)
    kind_mismatch = sum(row.get("status") == "skipped_kind_mismatch"
                        for row in candidates)
    print("state              actor      kind60 kind61 motion cycle matrices")
    for row in inventory:
        if "error" in row:
            print(f"{Path(str(row['state'])).name:18} {row['actor']} ERROR: {row['error']}")
            continue
        print(f"{Path(str(row['state'])).name:18} {row['actor']} "
              f"{str(row['actor_byte_0x60']):>6} "
              f"{str(row['actor_byte_0x61']):>6} "
              f"{str(row['motion_id']):>6} "
              f"{str(row['cycle']):>5} "
              f"{row['basis_usable_rows']:>2}/{row['matrix_count']}")
    print(f"native_pose_audit: {len(inventory)} actor/state records; "
          f"{usable} with {MATRIX_COUNT}/{MATRIX_COUNT} usable matrices; "
          f"{mapped} candidate reports written; {skipped} degenerate pose(s) and "
          f"{kind_mismatch} kind mismatch(es) skipped")
    print(f"manifest: {relative(manifest)}")
    return 1 if failures else 0


if __name__ == "__main__":
    raise SystemExit(main())
