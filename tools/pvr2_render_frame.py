#!/usr/bin/env python3
"""pvr2_render_frame.py - render one captured frame with vf3pvr and diff it.

Splits the frame out of a reference TA capture (tools/ta_split.py), runs
build/vf3pvr against a PVR2 state dump, writes <out>.ppm (and a .png when
Pillow is installed) and, with --ref, reports the pixel diff
(tools/pvr2_frame_diff.py).  --ref may be a PPM, a raw RGB dump or a PNG.

  python tools/pvr2_render_frame.py ref_ta.bin 300 ref_pvr.bin.300 --out o300 --ref ref_fb300.png
"""
from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import ta_split  # noqa: E402


def to_png(ppm: Path) -> Path | None:
    try:
        from PIL import Image
    except ImportError:
        return None
    png = ppm.with_suffix('.png')
    Image.open(ppm).save(png)
    return png


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or '').split('\n')[0])
    ap.add_argument('capture', type=Path, help='reference TA capture with frame markers')
    ap.add_argument('frame', type=int)
    ap.add_argument('state', type=Path, help='PVR2 state dump (registers + VRAM)')
    ap.add_argument('--out', type=Path, required=True, help='output stem (no extension)')
    ap.add_argument('--ref', type=Path, help='reference image to diff against')
    ap.add_argument('--tolerance', type=int, default=8)
    ap.add_argument('--exe', type=Path, default=ROOT / 'build' / 'vf3pvr.exe')
    a = ap.parse_args()

    with tempfile.TemporaryDirectory() as td:
        ta = ta_split.split(a.capture, [a.frame], Path(td))[0]
        ppm = a.out.with_suffix('.ppm')
        r = subprocess.run([str(a.exe), str(ta), str(a.state), str(ppm)],
                           capture_output=True, text=True)
    sys.stdout.write(r.stdout)
    if r.returncode:
        sys.stderr.write(r.stderr)
        return r.returncode
    png = to_png(ppm)
    if png:
        print(f'wrote {png}')
    if a.ref:
        ref = a.ref
        if ref.suffix.lower() == '.png':
            from PIL import Image
            ref = a.out.with_name(a.out.name + '_ref.ppm')
            Image.open(a.ref).convert('RGB').save(ref)
        r = subprocess.run([sys.executable, str(ROOT / 'tools' / 'pvr2_frame_diff.py'),
                            str(ppm), str(ref), '--tolerance', str(a.tolerance),
                            '--out', str(a.out) + '_diff.ppm'])
        return r.returncode
    return 0


if __name__ == '__main__':
    sys.exit(main())
