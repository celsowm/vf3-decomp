"""Export captured guest PCM to WAV, preserving samples and verifying reconstruction.

The research recorder stores right/left signed 16-bit pairs before host output.
Flycast's guest sample boundary is 44,100 Hz; WAV uses left/right pairs.
This renders existing research output, not a portable implementation of AICA.
"""
import argparse
import hashlib
import json
import struct
import wave
from pathlib import Path
from audio_determinism import checkpoints, sha


def swap_channels(data):
    if len(data) % 4:
        raise ValueError('incomplete stereo frame')
    out = bytearray(len(data))
    for i in range(0, len(data), 4):
        out[i:i+2], out[i+2:i+4] = data[i+2:i+4], data[i:i+2]
    return bytes(out)


def interval(first, last):
    if last[:len(first)] != first:
        raise ValueError('PCM checkpoints are not a cumulative stream')
    return last[len(first):]


def export(source, target):
    first = last = None
    for row in checkpoints(source):
        if first is None:
            first = row
        last = row
    if first is None or first is last:
        raise ValueError('need at least two PCM checkpoints')
    raw = interval(first['blocks'][6], last['blocks'][6])
    converted = swap_channels(raw)
    with wave.open(str(target), 'wb') as f:
        f.setnchannels(2)
        f.setsampwidth(2)
        f.setframerate(44100)
        f.writeframes(converted)
    with wave.open(str(target), 'rb') as f:
        if (f.getnchannels(), f.getsampwidth(), f.getframerate()) != (2, 2, 44100):
            raise ValueError('WAV format changed')
        if swap_channels(f.readframes(f.getnframes())) != raw:
            raise ValueError('WAV sample reconstruction mismatch')
    return dict(advisory=True, coverage_credit=False,
        scope='research-emulator PCM rendering; no command/transition attribution',
        source=dict(path=str(source), sha256=sha(source)),
        wav=dict(path=str(target), sha256=sha(target)),
        start_identity=first['identity'], end_identity=last['identity'],
        frames=len(raw)//4, sample_rate=44100, seconds=len(raw)/(4*44100),
        raw_right_left_sha256=hashlib.sha256(raw).hexdigest(),
        wav_left_right_sha256=hashlib.sha256(converted).hexdigest(),
        peak=max((abs(x[0]) for x in struct.iter_unpack('<h', raw)), default=0),
        sample_reconstruction_verified=True)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('source', type=Path)
    ap.add_argument('--wav', type=Path, required=True)
    ap.add_argument('--out', type=Path, required=True)
    a = ap.parse_args()
    report = export(a.source, a.wav)
    a.out.write_text(json.dumps(report, indent=2)+'\n', encoding='utf-8')
    print(f"{report['frames']} stereo frames; sample reconstruction verified")


if __name__ == '__main__':
    main()
