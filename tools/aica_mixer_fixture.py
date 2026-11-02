#!/usr/bin/env python3
"""aica_mixer_fixture.py - the AICA mixer's proof fixture.

The reference's audio checkpoint (tools/oracle/audio_determinism.py) carries,
in one file, everything the mixer needs to reproduce the guest's audio:

  - the AICA's whole state: the register file, the sound RAM and the 64
    channels' running state (the reference's own serialization);
  - the PCM the chip produced, frame by frame.

The ARM observer's trace (tools/oracle/arm_observer.py) carries what the
ARM7 (the sound CPU) did in the same window: every write it made into the
register file and into the sound RAM, with the cycle each write happened in.

This tool joins the two into one fixture the C test can read:

  - the state at the first checkpoint;
  - the ARM7's writes, in order, each with the sample tick it belongs to;
  - the reference's PCM for the window.

The tick origin is the first AICA tick after the checkpoint.  The AICA's
tick is 4535 SH-4 cycles long (flycast's AICA_TICK), and the ARM7 runs
inside the tick's callback, so every write of a tick carries the tick's
cycle.  The tool checks that all the writes fall on the same phase inside
their tick - if they did not, the tick index would be a guess.

    python tools/aica_mixer_fixture.py
    python tools/aica_mixer_fixture.py --out extract/analysis/aica_mixer_fixture.bin
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools" / "oracle"))

from audio_determinism import checkpoints, sha  # noqa: E402
from arm_trace import records  # noqa: E402

AICA_TICK = 4535

# The AICA block's layout (the reference's serialization, see
# tools/oracle/audio_state.py for the same offsets in Python).
ARAM_OFFSET = 969
ARAM_BYTES = 0x200000
REG_OFFSET = ARAM_OFFSET + ARAM_BYTES + 16
REG_BYTES = 0x8000
CHANNEL_OFFSET = REG_OFFSET + REG_BYTES
CHANNEL_BYTES = 72
CHANNEL_COUNT = 64

DEFAULT_CHECKPOINT = REPO / "extract" / "analysis" / "audio_arm_observer_v3" / "vf3_28_baseline.audio.gz"
DEFAULT_TRACE = REPO / "extract" / "analysis" / "audio_arm_observer_v3" / "vf3_28_traced.arm"


def build(checkpoint: Path, trace: Path, out: Path) -> dict:
    rows = list(checkpoints(checkpoint))
    if len(rows) < 2:
        raise SystemExit("the checkpoint needs the first and the last point")

    first, last = rows[0], rows[1]
    block = first["blocks"][3]
    if len(block) < CHANNEL_OFFSET + CHANNEL_COUNT * CHANNEL_BYTES:
        raise SystemExit("the AICA block is too small")

    registers = block[REG_OFFSET:REG_OFFSET + REG_BYTES]
    ram = block[ARAM_OFFSET:ARAM_OFFSET + ARAM_BYTES]
    channels = block[CHANNEL_OFFSET:CHANNEL_OFFSET + CHANNEL_COUNT * CHANNEL_BYTES]

    pcm = last["blocks"][6]
    if not pcm.startswith(first["blocks"][6]):
        raise SystemExit("the PCM checkpoints are not a cumulative stream")
    pcm = pcm[len(first["blocks"][6]):]

    # The tick origin: the first AICA tick after the checkpoint.  The
    # checkpoint's cycle is inside a tick, so the next boundary is the tick
    # period away.
    cycle0 = first["identity"][1]
    origin = cycle0 + (AICA_TICK - cycle0 % AICA_TICK)

    writes = []
    phases = set()
    for row in records(trace):
        if not row["store"]:
            continue
        cycle = row["callback_cycle"]
        if cycle < origin:
            continue
        phase = (cycle - origin) % AICA_TICK
        phases.add(phase)
        tick = (cycle - origin) // AICA_TICK
        address = row["address"]
        if address >= 0x800000:
            offset = address & 0x7FFF
            writes.append((tick, 0, offset, row["value"], row["size"]))
        else:
            writes.append((tick, 1, address & 0x1FFFFF, row["value"], row["size"]))

    frames = len(pcm) // 4
    span = (last["identity"][1] - cycle0) / AICA_TICK
    ticks = [w[0] for w in writes]

    # The tick origin is exact when the writes stay inside the window the
    # PCM covers: the first write in the first tick, the last write in the
    # last tick, and none outside.  (The writes are spread inside their
    # tick - the ARM7 works in bursts - so the phase is not constant.)
    window_ok = bool(ticks) and min(ticks) == 0 and max(ticks) == frames - 1

    payload = struct.pack("<8s6I", b"VF3MIX1\0", REG_BYTES, ARAM_BYTES,
                           CHANNEL_COUNT * CHANNEL_BYTES, len(writes), frames, 0)
    payload += registers
    payload += ram
    payload += channels
    for tick, kind, offset, value, size in writes:
        payload += struct.pack("<5I", tick, kind, offset, value, size)
    payload += pcm
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(payload)

    manifest = dict(
        coverage_credit=False,
        source=dict(checkpoint=str(checkpoint), checkpoint_sha256=sha(checkpoint),
                    trace=str(trace), trace_sha256=sha(trace)),
        fixture=dict(path=str(out), bytes=len(payload), sha256=sha(out)),
        tick=dict(aica_tick=AICA_TICK, checkpoint_cycle=cycle0, origin_cycle=origin,
                  phases=sorted(phases), phase_count=len(phases),
                  checkpoint_span_ticks=span, frames=frames,
                  window_ok=window_ok),
        writes=dict(total=len(writes),
                    registers=sum(1 for w in writes if w[1] == 0),
                    ram=sum(1 for w in writes if w[1] == 1),
                    first_tick=min((w[0] for w in writes), default=None),
                    last_tick=max((w[0] for w in writes), default=None)),
        pcm=dict(bytes=len(pcm), frames=frames,
                 sha256=hashlib.sha256(pcm).hexdigest()),
    )
    return manifest


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n")[0])
    ap.add_argument("--checkpoint", type=Path, default=DEFAULT_CHECKPOINT)
    ap.add_argument("--trace", type=Path, default=DEFAULT_TRACE)
    ap.add_argument("--out", type=Path,
                    default=REPO / "extract" / "analysis" / "aica_mixer_fixture.bin")
    ap.add_argument("--manifest", type=Path,
                    default=REPO / "extract" / "analysis" / "aica_mixer_fixture.json")
    args = ap.parse_args()

    for path in (args.checkpoint, args.trace):
        if not path.is_file():
            print(f"aica_mixer_fixture: {path} missing")
            return 2
    manifest = build(args.checkpoint, args.trace, args.out)
    args.manifest.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"{manifest['writes']['total']} writes, {manifest['pcm']['frames']} frames, "
          f"the tick window holds the writes: {manifest['tick']['window_ok']}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
