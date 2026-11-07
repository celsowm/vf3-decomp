#!/usr/bin/env python3
"""Inspect candidate ADPCM spans in a DTPK VO_* package.

The current hypothesis is a leading array of 16-byte records. Each record
carries a byte length and a package-relative end offset in the low 24 bits of
its second word. This diagnostic validates candidate spans and reports unknown
descriptor words without claiming that every span is an independently playable
sample or assigning the fields an in-game meaning.

Examples:
  python tools/dtpk_samples.py extract/gamedata/VO_AKI.BIN
  python tools/dtpk_samples.py extract/gamedata/VO_JAC.BIN --json
  python tools/dtpk_samples.py extract/gamedata/VO_AKI.BIN --sample 0 --sample 1 \
      --wav-dir extract/analysis/vo_aki_samples
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import struct
import sys

import adpcm_decode

DTPK_HEADER_SIZE = 0x60
SECTION_COUNT = 16
SAMPLE_DESCRIPTOR = struct.Struct("<4I")
SAMPLE_ADDRESS_MASK = 0x00FFFFFF


def parse_sections(data: bytes) -> list[tuple[int, int, int]]:
    if len(data) < DTPK_HEADER_SIZE or data[:4] != b"DTPK":
        raise ValueError("not a complete DTPK package")
    declared_size = struct.unpack_from("<I", data, 8)[0]
    if declared_size != len(data):
        raise ValueError(f"DTPK size field is {declared_size}, file has {len(data)} bytes")
    offsets = [struct.unpack_from("<I", data, 0x20 + 4 * index)[0]
               for index in range(SECTION_COUNT)]
    present = [(index, offset) for index, offset in enumerate(offsets) if offset]
    if not present or present[0][1] != DTPK_HEADER_SIZE:
        raise ValueError("section directory has no initial 0x60 section")
    if any(offset >= len(data) for _index, offset in present):
        raise ValueError("section offset lies outside the package")
    if any(right[1] <= left[1] for left, right in zip(present, present[1:])):
        raise ValueError("nonzero section offsets are not strictly increasing")
    return [(index, offset,
             present[pos + 1][1] if pos + 1 < len(present) else len(data))
            for pos, (index, offset) in enumerate(present)]


def inspect_samples(data: bytes, requested_section: int | None = None) -> dict:
    sections = parse_sections(data)
    if requested_section is None:
        section_index, section_start, section_end = sections[-1]
    else:
        matches = [row for row in sections if row[0] == requested_section]
        if not matches:
            raise ValueError(f"section {requested_section} is absent")
        section_index, section_start, section_end = matches[0]
    if section_end - section_start < SAMPLE_DESCRIPTOR.size:
        raise ValueError("selected section is too short for a sample descriptor")

    first_length, first_address, _meta0, _meta1 = SAMPLE_DESCRIPTOR.unpack_from(
        data, section_start
    )
    first_end = first_address & SAMPLE_ADDRESS_MASK
    first_start = first_end - first_length
    descriptor_span = first_start - section_start
    if descriptor_span <= 0:
        raise ValueError("first sample starts before the candidate descriptor table")
    sample_count = descriptor_span // SAMPLE_DESCRIPTOR.size
    descriptor_bytes = sample_count * SAMPLE_DESCRIPTOR.size
    prefix_padding = descriptor_span - descriptor_bytes
    if sample_count == 0:
        raise ValueError("first sample boundary does not imply a descriptor table")
    if sample_count > (section_end - section_start) // SAMPLE_DESCRIPTOR.size:
        raise ValueError("inferred descriptor table exceeds the selected section")

    samples = []
    previous_end = first_start
    for sample_index in range(sample_count):
        record_offset = section_start + sample_index * SAMPLE_DESCRIPTOR.size
        length, address_word, meta0, meta1 = SAMPLE_DESCRIPTOR.unpack_from(data, record_offset)
        end = address_word & SAMPLE_ADDRESS_MASK
        start = end - length
        expected_start = first_start if sample_index == 0 else previous_end
        if length == 0 or start != expected_start:
            raise ValueError(
                f"sample {sample_index} has noncontiguous bounds: "
                f"start 0x{start:x}, expected 0x{expected_start:x}"
            )
        if end > section_end:
            raise ValueError(f"sample {sample_index} ends outside section {section_index}")
        samples.append({
            "index": sample_index,
            "record_offset": record_offset,
            "start": start,
            "end": end,
            "length": length,
            "address_word": f"0x{address_word:08x}",
            "metadata_words": [f"0x{meta0:08x}", f"0x{meta1:08x}"],
        })
        previous_end = end

    return {
        "diagnostic_only": True,
        "package_size": len(data),
        "section_index": section_index,
        "section_start": section_start,
        "section_end": section_end,
        "descriptor_size": SAMPLE_DESCRIPTOR.size,
        "descriptor_table_start": section_start,
        "descriptor_table_end": section_start + descriptor_bytes,
        "sample_data_start": first_start,
        "prefix_padding_bytes": prefix_padding,
        "sample_data_end": previous_end,
        "trailing_section_bytes": section_end - previous_end,
        "samples": samples,
        "notes": [
            "These are candidate spans, not a proven sample-to-game-event map.",
            "The low 24 bits of descriptor word 1 are treated as package-file end offsets.",
            "The two trailing descriptor words are preserved as raw values; their fields are unknown.",
            "Sample bytes are decoded as AICA ADPCM at the requested nominal rate.",
        ],
    }


def write_wavs(data: bytes, report: dict, indices: set[int], out_dir: Path,
               sample_rate: int) -> list[dict[str, object]]:
    chosen = [sample for sample in report["samples"]
              if not indices or int(sample["index"]) in indices]
    paths = [out_dir / f"sample_{int(sample['index']):03d}.wav" for sample in chosen]
    existing = [path for path in paths if path.exists()]
    if existing:
        raise FileExistsError("refusing to replace WAV output: " +
                              ", ".join(str(path) for path in existing))
    out_dir.mkdir(parents=True, exist_ok=True)
    written = []
    for sample, path in zip(chosen, paths):
        index = int(sample["index"])
        encoded = data[int(sample["start"]):int(sample["end"])]
        samples = adpcm_decode.decode(encoded)
        adpcm_decode.to_wav(str(path), samples, sample_rate)
        written.append({
            "index": index,
            "path": str(path),
            "encoded_bytes": len(encoded),
            "decoded_samples": len(samples),
            "duration_seconds": round(len(samples) / sample_rate, 4),
            "stats": adpcm_decode.stats(samples),
        })
    return written


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("file", type=Path, help="extracted DTPK audio package")
    parser.add_argument("--section", type=int,
                        help="audio section index (default: final nonempty section)")
    parser.add_argument("--sample", type=int, action="append",
                        help="decode only this zero-based sample; repeatable")
    parser.add_argument("--wav-dir", type=Path,
                        help="write selected samples as mono PCM16 WAV files")
    parser.add_argument("--rate", type=int, default=22050,
                        help="nominal WAV sample rate (default: 22050 Hz)")
    parser.add_argument("--json", action="store_true", help="emit JSON report")
    args = parser.parse_args(argv)
    if args.section is not None and args.section < 0:
        parser.error("--section must be nonnegative")
    if args.sample and any(index < 0 for index in args.sample):
        parser.error("sample indices must be nonnegative")
    if args.rate <= 0:
        parser.error("--rate must be positive")
    if args.sample and not args.wav_dir:
        parser.error("--sample requires --wav-dir")
    if not args.file.stem.upper().startswith("VO_"):
        parser.error("this candidate layout is currently limited to VO_* packages")

    try:
        data = args.file.read_bytes()
        report = inspect_samples(data, args.section)
        selected = set(args.sample or [])
        if selected:
            known = {int(sample["index"]) for sample in report["samples"]}
            missing = sorted(selected - known)
            if missing:
                raise ValueError("unknown sample index/indices: " +
                                 ", ".join(str(index) for index in missing))
        if args.wav_dir:
            report["decoded_wavs"] = write_wavs(data, report, selected,
                                                args.wav_dir, args.rate)
    except (OSError, ValueError, struct.error) as exc:
        print(f"dtpk_samples: {exc}", file=sys.stderr)
        return 1

    if args.json:
        print(json.dumps(report, indent=2) + "\n", end="")
        return 0
    print(f"{args.file.name}: section {report['section_index']} "
          f"0x{report['section_start']:x}..0x{report['section_end']:x}; "
          f"{len(report['samples'])} samples; "
          f"data 0x{report['sample_data_start']:x}..0x{report['sample_data_end']:x}; "
          f"trailing={report['trailing_section_bytes']} B")
    for sample in report["samples"]:
        print(f"  sample {sample['index']:3d}: file+0x{sample['start']:x}.."
              f"0x{sample['end']:x} bytes={sample['length']} "
              f"address={sample['address_word']} "
              f"metadata={','.join(sample['metadata_words'])}")
    for wav in report.get("decoded_wavs", []):
        print(f"  wrote {wav['path']}: {wav['decoded_samples']} samples, "
              f"{wav['duration_seconds']:.3f}s, stats={wav['stats']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
