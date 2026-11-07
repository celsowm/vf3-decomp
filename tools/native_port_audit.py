#!/usr/bin/env python3
"""Audit the standalone native port's executable and VFA runtime boundary.

The port release should need only vf3port.exe, vf3_assets.vfa, and libraries
that ship with Windows. This audit checks the PE import table for third-party
DLLs and validates that the VFA archive contains the native runtime assets but
not the guest executable or firmware.

Example:
  python tools/native_port_audit.py --exe build/vf3port.exe \
      --assets build/vf3_assets.vfa
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
import sys

VFA_MAGIC = b"VF3AST\0\0"
VFA_HEADER_SIZE = 32
VFA_ENTRY_SIZE = 112
REQUIRED_ASSETS = {
    "MKAO_AKI.POL", "MKAO_AKI.TEX", "MKAO_WO2.POL", "MKAO_WO2.TEX",
    "ST01.POL", "ST01.TEX", "ST01_E.POL", "ST01_E.TEX",
}
FORBIDDEN_ASSETS = {
    "1ST_READ.BIN", "SNDDRV.BIN", "RELOAD.BIN", "VF3TBE3.BIN",
}
WINDOWS_DLLS = {
    "advapi32.dll", "bcrypt.dll", "cfgmgr32.dll", "comdlg32.dll",
    "dinput8.dll", "dwmapi.dll", "gdi32.dll", "hid.dll", "imm32.dll",
    "kernel32.dll", "msvcrt.dll", "ntdll.dll", "ole32.dll",
    "oleaut32.dll", "setupapi.dll", "shell32.dll", "user32.dll",
    "version.dll", "winmm.dll", "winspool.drv", "ws2_32.dll",
    "ucrtbase.dll", "uuid.dll",
}


class AuditError(ValueError):
    pass


def u16(data: bytes, offset: int) -> int:
    if offset < 0 or offset + 2 > len(data):
        raise AuditError("truncated executable while reading a 16-bit field")
    return struct.unpack_from("<H", data, offset)[0]


def u32(data: bytes, offset: int) -> int:
    if offset < 0 or offset + 4 > len(data):
        raise AuditError("truncated executable while reading a 32-bit field")
    return struct.unpack_from("<I", data, offset)[0]


def cstring(data: bytes, offset: int) -> str:
    if offset < 0 or offset >= len(data):
        raise AuditError("string offset lies outside the executable")
    end = data.find(b"\0", offset)
    if end < 0:
        raise AuditError("unterminated string in executable import table")
    try:
        return data[offset:end].decode("ascii")
    except UnicodeDecodeError as exc:
        raise AuditError("non-ASCII DLL name in executable import table") from exc


def pe_imports(data: bytes) -> list[str]:
    if len(data) < 0x40 or data[:2] != b"MZ":
        raise AuditError("executable is not a Windows PE file")
    pe = u32(data, 0x3C)
    if data[pe:pe + 4] != b"PE\0\0":
        raise AuditError("invalid PE signature")
    section_count = u16(data, pe + 6)
    optional_size = u16(data, pe + 20)
    optional = pe + 24
    magic = u16(data, optional)
    if magic == 0x20B:  # PE32+
        directory = optional + 112
    elif magic == 0x10B:  # PE32
        directory = optional + 96
    else:
        raise AuditError(f"unsupported PE optional-header magic 0x{magic:04x}")
    import_rva = u32(data, directory + 8)
    import_size = u32(data, directory + 12)
    if not import_rva or not import_size:
        return []

    section_table = optional + optional_size
    sections = []
    for index in range(section_count):
        row = section_table + index * 40
        virtual_size = u32(data, row + 8)
        virtual_address = u32(data, row + 12)
        raw_size = u32(data, row + 16)
        raw_offset = u32(data, row + 20)
        sections.append((virtual_address, max(virtual_size, raw_size), raw_size,
                         raw_offset))

    def map_rva(rva: int) -> int:
        for va, span, raw_size, raw_offset in sections:
            if va <= rva < va + span:
                delta = rva - va
                if delta >= raw_size:
                    break
                return raw_offset + delta
        raise AuditError(f"import-table RVA 0x{rva:x} is not file-backed")

    imports = []
    descriptor = map_rva(import_rva)
    limit = min(len(data), descriptor + import_size)
    while descriptor + 20 <= limit:
        name_rva = u32(data, descriptor + 12)
        if name_rva == 0:
            return sorted(set(imports), key=str.casefold)
        imports.append(cstring(data, map_rva(name_rva)).casefold())
        descriptor += 20
    raise AuditError("unterminated PE import descriptor table")


def vfa_entries(path: Path) -> list[str]:
    file_size = path.stat().st_size
    with path.open("rb") as archive:
        header = archive.read(VFA_HEADER_SIZE)
        if len(header) != VFA_HEADER_SIZE or header[:8] != VFA_MAGIC:
            raise AuditError(f"{path} is not a VF3 asset archive")
        version, count = struct.unpack_from("<II", header, 8)
        index_offset, data_offset = struct.unpack_from("<QQ", header, 16)
        table_end = index_offset + count * VFA_ENTRY_SIZE
        if version != 1 or count == 0 or index_offset != VFA_HEADER_SIZE:
            raise AuditError("unsupported or malformed VFA header")
        if table_end > file_size or data_offset < table_end or data_offset > file_size:
            raise AuditError("VFA index/data offsets exceed the archive")

        archive.seek(index_offset)
        entries = []
        previous_name = ""
        previous_end = data_offset
        for row_index in range(count):
            row = archive.read(VFA_ENTRY_SIZE)
            if len(row) != VFA_ENTRY_SIZE:
                raise AuditError("truncated VFA index")
            name_raw = row[:64].split(b"\0", 1)[0]
            try:
                name = name_raw.decode("ascii")
            except UnicodeDecodeError as exc:
                raise AuditError("non-ASCII asset name in VFA") from exc
            offset, size = struct.unpack_from("<QQ", row, 64)
            end = offset + size
            if not name:
                raise AuditError(f"VFA entry {row_index} has an empty name")
            if name.upper() <= previous_name.upper():
                raise AuditError(
                    f"VFA names are duplicated or unsorted at entry {row_index}: "
                    f"{previous_name!r}, {name!r}"
                )
            if offset < previous_end or end > file_size:
                raise AuditError(f"VFA bounds are invalid for {name}")
            entries.append(name.upper())
            previous_name = name
            previous_end = end
        return entries


def audit(exe_path: Path, asset_path: Path) -> dict[str, object]:
    for path, kind in ((exe_path, "executable"), (asset_path, "asset archive")):
        if not path.is_file():
            raise AuditError(f"{kind} does not exist: {path}")

    imports = pe_imports(exe_path.read_bytes())
    external = [name for name in imports
                if name not in WINDOWS_DLLS
                and not name.startswith("api-ms-win-")
                and not name.startswith("ext-ms-win-")]
    entries = vfa_entries(asset_path)
    names = set(entries)
    missing = sorted(REQUIRED_ASSETS - names)
    forbidden = sorted(FORBIDDEN_ASSETS & names)
    return {
        "executable": str(exe_path.resolve()),
        "asset_archive": str(asset_path.resolve()),
        "asset_count": len(entries),
        "external_dlls": external,
        "missing_runtime_assets": missing,
        "forbidden_guest_assets": forbidden,
        "pass": not external and not missing and not forbidden,
    }


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--exe", type=Path, required=True,
                        help="standalone vf3port PE executable")
    parser.add_argument("--assets", type=Path, required=True,
                        help="runtime VFA asset archive")
    parser.add_argument("--json", action="store_true",
                        help="print the complete audit report as JSON")
    args = parser.parse_args(argv)
    try:
        report = audit(args.exe, args.assets)
    except (OSError, AuditError, struct.error) as exc:
        print(f"native_port_audit: {exc}", file=sys.stderr)
        return 1

    if args.json:
        print(json.dumps(report, indent=2))
    else:
        print(f"Executable: {report['executable']}")
        print(f"VFA archive: {report['asset_archive']} ({report['asset_count']} assets)")
        print(f"Third-party DLL imports: {report['external_dlls'] or 'none'}")
        print(f"Missing runtime assets: {report['missing_runtime_assets'] or 'none'}")
        print(f"Guest/firmware assets in VFA: {report['forbidden_guest_assets'] or 'none'}")
        print(f"Standalone boundary: {'PASS' if report['pass'] else 'FAIL'}")
    return 0 if report["pass"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
