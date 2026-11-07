#!/usr/bin/env python3
"""Pack the extracted VF3 data files for the source-level native port.

This is an offline step.  It reads the already extracted ISO directory and
writes a standalone archive of game assets; it does not keep the disc image,
either SH-4 executable, or the sound firmware in the runtime bundle.

    python tools/pack_assets.py --source extract/gamedata --output build/vf3_assets.vfa
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import tempfile
from dataclasses import dataclass
from pathlib import Path

MAGIC = b"VF3AST\0\0"
VERSION = 1
HEADER = struct.Struct("<8sIIQQ")
ENTRY = struct.Struct("<64sQQ32s")
ALIGNMENT = 16
ASSET_EXTENSIONS = {".BIN", ".POL", ".TEX", ".CLI", ".ASC", ".SFD", ".BMS"}
NON_ASSET_FILES = {
    "1ST_READ.BIN", "VF3TBE3.BIN", "SNDDRV.BIN", "RELOAD.BIN",
}
HASH_CHUNK = 1024 * 1024


@dataclass(frozen=True)
class Asset:
    path: Path
    name: str
    size: int
    sha256: bytes


def align(value: int, boundary: int = ALIGNMENT) -> int:
    return (value + boundary - 1) & ~(boundary - 1)


def hash_file(path: Path) -> bytes:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        while chunk := stream.read(HASH_CHUNK):
            h.update(chunk)
    return h.digest()


def collect_assets(source: Path) -> tuple[list[Asset], list[str]]:
    if not source.is_dir():
        raise ValueError(f"asset source directory does not exist: {source}")

    assets: list[Asset] = []
    excluded: list[str] = []
    names: set[str] = set()
    for path in sorted(source.iterdir(), key=lambda p: p.name.upper()):
        if not path.is_file():
            continue
        name = path.name.upper()
        if name in NON_ASSET_FILES:
            excluded.append(name)
            continue
        if path.suffix.upper() not in ASSET_EXTENSIONS:
            continue
        try:
            encoded = name.encode("ascii")
        except UnicodeEncodeError as exc:
            raise ValueError(f"asset name is not ASCII: {path.name}") from exc
        if len(encoded) >= 64 or b"/" in encoded or b"\\" in encoded:
            raise ValueError(f"asset name cannot be represented safely: {path.name}")
        if name in names:
            raise ValueError(f"duplicate asset name after case folding: {name}")
        names.add(name)
        size = path.stat().st_size
        assets.append(Asset(path, name, size, hash_file(path)))

    if not assets:
        raise ValueError(f"no supported asset files found in {source}")
    if len(assets) > 0xFFFFFFFF:
        raise ValueError("too many files for asset archive format")
    return assets, excluded


def pack_assets(source: Path, output: Path, manifest: Path | None = None) -> dict:
    source = source.resolve()
    output = output.resolve()
    if output == source or source in output.parents:
        raise ValueError("output must be outside the extracted source directory")
    manifest_path = manifest.resolve() if manifest else Path(str(output) + ".json")
    if manifest_path == output:
        raise ValueError("manifest and archive must use different paths")
    if manifest_path == source or source in manifest_path.parents:
        raise ValueError("manifest must be outside the extracted source directory")
    assets, excluded = collect_assets(source)
    output.parent.mkdir(parents=True, exist_ok=True)

    index_offset = HEADER.size
    data_offset = align(index_offset + len(assets) * ENTRY.size)
    cursor = data_offset
    entries: list[tuple[Asset, int]] = []
    for asset in assets:
        cursor = align(cursor)
        entries.append((asset, cursor))
        cursor += asset.size

    temp_name: str | None = None
    try:
        with tempfile.NamedTemporaryFile("w+b", delete=False,
                                         dir=output.parent,
                                         prefix=output.name + ".tmp-") as out:
            temp_name = out.name
            out.write(HEADER.pack(MAGIC, VERSION, len(assets), index_offset, data_offset))
            for asset, offset in entries:
                name = asset.name.encode("ascii")
                out.write(ENTRY.pack(name + b"\0" * (64 - len(name)),
                                     offset, asset.size, asset.sha256))
            out.write(b"\0" * (data_offset - out.tell()))

            for asset, offset in entries:
                out.write(b"\0" * (offset - out.tell()))
                digest = hashlib.sha256()
                written = 0
                with asset.path.open("rb") as src:
                    while chunk := src.read(HASH_CHUNK):
                        out.write(chunk)
                        digest.update(chunk)
                        written += len(chunk)
                if written != asset.size or digest.digest() != asset.sha256:
                    raise ValueError(f"asset changed while being packed: {asset.name}")

            out.flush()
            os.fsync(out.fileno())
        os.replace(temp_name, output)
        temp_name = None
    finally:
        if temp_name:
            try:
                os.unlink(temp_name)
            except FileNotFoundError:
                pass

    manifest_data = {
        "format": "VF3AST",
        "version": VERSION,
        "source": "extracted game data files",
        "runtime_disc_required": False,
        "runtime_executable_included": False,
        "asset_count": len(assets),
        "asset_bytes": sum(a.size for a in assets),
        "excluded_program_files": excluded,
        "archive": output.name,
        "assets": [
            {"name": a.name, "size": a.size, "sha256": a.sha256.hex()}
            for a in assets
        ],
    }
    manifest_path.parent.mkdir(parents=True, exist_ok=True)
    manifest_tmp: str | None = None
    try:
        with tempfile.NamedTemporaryFile("w", encoding="utf-8", newline="\n",
                                         delete=False, dir=manifest_path.parent,
                                         prefix=manifest_path.name + ".tmp-") as stream:
            manifest_tmp = stream.name
            json.dump(manifest_data, stream, indent=2, sort_keys=True)
            stream.write("\n")
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(manifest_tmp, manifest_path)
        manifest_tmp = None
    finally:
        if manifest_tmp:
            try:
                os.unlink(manifest_tmp)
            except FileNotFoundError:
                pass
    return manifest_data


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--source", type=Path, default=Path("extract/gamedata"),
                        help="directory produced by the one-time ISO extraction")
    parser.add_argument("--output", type=Path, default=Path("build/vf3_assets.vfa"),
                        help="standalone asset archive (outside --source)")
    parser.add_argument("--manifest", type=Path,
                        help="manifest path (default: <output>.json)")
    args = parser.parse_args()
    try:
        manifest = pack_assets(args.source, args.output, args.manifest)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))
    print(f"packed {manifest['asset_count']} assets ({manifest['asset_bytes']:,} bytes) -> {args.output}")
    print(f"excluded program files: {', '.join(manifest['excluded_program_files']) or '(none found)'}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
