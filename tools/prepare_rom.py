#!/usr/bin/env python3
"""Verify and prepare the supported, user-supplied VF3tb USA disc ZIP offline.

No download, descrambling, or tracked-file changes. The archive must contain
the four exact files identified in README.md (the original .cue is optional).
Existing differing local files are never overwritten. All extraction is staged
and checked before installation; game data stays under rom/ and extract/.
"""
from __future__ import annotations

import argparse
from contextlib import redirect_stdout
from dataclasses import dataclass
import hashlib
import importlib.util
import io
import json
from pathlib import Path, PurePosixPath
import shutil
import stat
import sys
import tempfile
from typing import BinaryIO
import zipfile

REPO = Path(__file__).resolve().parents[1]
CHUNK = 1024 * 1024
RETAIL_SHA256 = "37f38dd9a47b785f526157c4a1674ca75322f0de1342f64bbf33c88d128e4b32"


@dataclass(frozen=True)
class Identity:
    size: int
    sha1: str


EXPECTED = {
    "vf3.gdi": Identity(171, "cfc65b63e7878fe4fda033c88246f7eb1b8e5c2d"),
    "Virtua Fighter 3tb (USA) (Track 1).bin": Identity(
        705600, "bb30bc9d46c58c14475895ccc9bdba3cc7184f36"),
    "Virtua Fighter 3tb (USA) (Track 2).bin": Identity(
        1589952, "a3705cb0ce53c7adf906c5af76887406984de6a9"),
    "Virtua Fighter 3tb (USA) (Track 3).bin": Identity(
        1185760800, "831b616be8eb2ed2f98bbeea271a4e8a9e3c152a"),
}
OPTIONAL_CUE = "Virtua Fighter 3tb (USA).cue"


class PreparationError(ValueError):
    """Unsupported input or conflicting local data; no replacement is allowed."""


def digest_stream(stream: BinaryIO) -> dict[str, str | int]:
    h1, h256, size = hashlib.sha1(), hashlib.sha256(), 0
    while chunk := stream.read(CHUNK):
        h1.update(chunk)
        h256.update(chunk)
        size += len(chunk)
    return {"size": size, "sha1": h1.hexdigest(), "sha256": h256.hexdigest()}


def digest_file(path: Path) -> dict[str, str | int]:
    with path.open("rb") as stream:
        return digest_stream(stream)


def check_member(info: zipfile.ZipInfo) -> None:
    """Only plain, root-level files are valid for this specific disc bundle."""
    name = info.filename
    path = PurePosixPath(name)
    if (not name or "\\" in name or ":" in name or "\x00" in name
            or path.is_absolute() or len(path.parts) != 1
            or name in (".", "..") or info.is_dir()):
        raise PreparationError(f"unsafe or nested ZIP member: {name!r}")
    mode = info.external_attr >> 16
    kind = stat.S_IFMT(mode)
    if kind not in (0, stat.S_IFREG):
        raise PreparationError(f"ZIP member is not a regular file: {name!r}")
    if info.flag_bits & 1:
        raise PreparationError(f"encrypted ZIP member is unsupported: {name!r}")


def inspect_archive(archive: Path, expected: dict[str, Identity] | None = None
                    ) -> dict[str, dict[str, str | int]]:
    """Read and hash every allowed member without writing any files."""
    expected = EXPECTED if expected is None else expected
    result = {}
    with zipfile.ZipFile(archive) as zf:
        infos = zf.infolist()
        # Reject extra/missing/duplicate/oversized entries before decompression.
        for info in infos:
            check_member(info)
            name = info.filename
            if name in result:
                raise PreparationError(f"duplicate ZIP member: {name}")
            if name not in expected and name != OPTIONAL_CUE:
                raise PreparationError(f"unexpected ZIP member: {name}")
            if name in expected and info.file_size != expected[name].size:
                raise PreparationError(
                    f"wrong size for {name}: {info.file_size}; expected {expected[name].size}")
            if name == OPTIONAL_CUE and info.file_size > 65536:
                raise PreparationError("optional CUE exceeds 64 KiB")
            result[name] = {}
        missing = sorted(set(expected) - set(result))
        if missing:
            raise PreparationError("missing required ZIP members: " + ", ".join(missing))
        for info in infos:
            with zf.open(info) as stream:
                identity = digest_stream(stream)
            if identity["size"] != info.file_size:
                raise PreparationError(f"short ZIP member: {info.filename}")
            wanted = expected.get(info.filename)
            if wanted and identity["sha1"] != wanted.sha1:
                raise PreparationError(
                    f"wrong SHA-1 for {info.filename}: {identity['sha1']}; expected {wanted.sha1}")
            result[info.filename] = identity
    return result


def check_destination(path: Path, identity: dict[str, str | int]) -> bool:
    """Return True for an identical existing file, rejecting symlinks/conflicts."""
    for part in (path, *path.parents):
        if part.is_symlink():
            raise PreparationError(f"refusing symlink destination: {part}")
    if not path.exists():
        return False
    if (not path.is_file() or path.stat().st_size != identity["size"]
            or digest_file(path)["sha256"] != identity["sha256"]):
        raise PreparationError(f"existing file differs; preserved unchanged: {path}")
    return True


def publish(source: Path, target: Path, identity: dict[str, str | int]) -> None:
    if check_destination(target, identity):
        return
    target.parent.mkdir(parents=True, exist_ok=True)
    # Exclusive creation prevents replacing a file created after the preflight.
    with source.open("rb") as incoming:
        try:
            outgoing = target.open("xb")
        except FileExistsError as exc:
            raise PreparationError(f"destination appeared during import: {target}") from exc
        try:
            with outgoing:
                shutil.copyfileobj(incoming, outgoing, CHUNK)
        except BaseException:
            target.unlink()
            raise


def extract_staged(stage: Path) -> list[dict[str, str | int]]:
    spec = importlib.util.spec_from_file_location("vf3_extract_iso", REPO / "tools/extract_iso.py")
    assert spec and spec.loader
    extractor = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(extractor)
    extractor.REPO = str(stage)
    extractor.ROM_DIR = str(stage / "rom")
    extractor.OUT_GAME = str(stage / "extract/gamedata")
    extractor.OUT_IP = str(stage / "extract/ip")
    extractor.DOCS = str(stage / "extract/analysis/rom-import")
    # Its legacy progress text hardcodes docs/files.md, even when redirected.
    # Keep this CLI's output accurate and machine-readable.
    with redirect_stdout(io.StringIO()):
        extractor.main()
    game = stage / "extract/gamedata"
    retail = digest_file(game / "1ST_READ.BIN")
    if retail["sha256"] != RETAIL_SHA256:
        raise PreparationError(f"extracted 1ST_READ.BIN SHA-256 mismatch: {retail['sha256']}")
    if sum(path.is_file() for path in game.rglob("*")) != 412:
        raise PreparationError("expected 412 extracted game files for this disc")
    executables = []
    for name in ("1ST_READ", "VF3TBE3", "RELOAD"):
        source = game / f"{name}.BIN"
        target = stage / f"extract/exe/{name}.unsc.bin"
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)  # Retail files are already unscrambled.
        executables.append({"source": f"extract/gamedata/{name}.BIN",
                            "path": f"extract/exe/{name}.unsc.bin",
                            "transform": "identity", **digest_file(target)})
    return executables


def prepare(archive: Path, repo: Path = REPO, verify_only: bool = False) -> dict:
    archive = archive.resolve(strict=True)
    files = inspect_archive(archive)
    report = {"schema_version": 1, "disc": "VF3tb USA MK-51001 V1.002",
              "archive": {"path": str(archive), **digest_file(archive)},
              "tracks": files, "verified_only": verify_only}
    if verify_only:
        return report
    repo = repo.resolve(strict=True)
    # Fail on conflicting tracks before creating a staging directory.
    for name, identity in files.items():
        check_destination(repo / "rom" / name, identity)
    staging_parent = repo / "extract"
    for part in (staging_parent, *staging_parent.parents):
        if part.is_symlink():
            raise PreparationError(f"refusing symlink destination: {part}")
    staging_parent.mkdir(exist_ok=True)
    with tempfile.TemporaryDirectory(prefix=".rom-import-", dir=staging_parent) as temp:
        stage = Path(temp)
        (stage / "rom").mkdir()
        with zipfile.ZipFile(archive) as zf:
            for name, identity in files.items():
                target = stage / "rom" / name
                with zf.open(name) as incoming, target.open("xb") as outgoing:
                    shutil.copyfileobj(incoming, outgoing, CHUNK)
                if digest_file(target) != identity:
                    raise PreparationError(f"ZIP changed during import: {name}")
        report["executables"] = extract_staged(stage)
        report["game_file_count"] = 412
        manifest = stage / "extract/rom_manifest.json"
        manifest.write_text(json.dumps(report, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        staged = [(path, repo / path.relative_to(stage), digest_file(path))
                  for path in sorted(stage.rglob("*")) if path.is_file()]
        # No tracked docs are touched; reject any differing local output before
        # publishing the first file. A disk failure can leave identical partial
        # output, and a repeat invocation safely resumes those files.
        for _, target, identity in staged:
            check_destination(target, identity)
        for source, target, identity in staged:
            publish(source, target, identity)
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--zip", required=True, type=Path, dest="archive")
    parser.add_argument("--verify-only", action="store_true",
                        help="hash and validate the archive; do not write anything")
    args = parser.parse_args()
    try:
        report = prepare(args.archive, verify_only=args.verify_only)
    except (PreparationError, OSError, zipfile.BadZipFile, RuntimeError) as exc:
        print(f"prepare_rom: {exc}", file=sys.stderr)
        return 1
    print(json.dumps(report, indent=2, sort_keys=True))
    if not args.verify_only:
        print("Prepared local game data; manifest: extract/rom_manifest.json")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
