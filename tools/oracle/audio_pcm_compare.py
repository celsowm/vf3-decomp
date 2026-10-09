"""Compare guest audio, then export a matched pair with the existing exporter."""
import argparse
import json
from pathlib import Path
from audio_determinism import compare,sha
from audio_pcm import export


def render(original,replacement,out):
    comparison=compare(original,replacement)
    if not comparison['equal']:raise ValueError('original/replacement audio differs')
    out.mkdir(parents=True,exist_ok=False)
    result=dict(passed=True,coverage_credit=False,manual_listening_completed=False,
                standalone_audio=False,dependency='research emulator ARM/DSP',
                comparison=comparison,
                original=export(original,out/'original.wav'),
                replacement=export(replacement,out/'replacement.wav'),
                exporter=dict(path=str(Path(__file__).with_name('audio_pcm.py')),
                              sha256=sha(Path(__file__).with_name('audio_pcm.py'))),
                wrapper=dict(path=str(Path(__file__)),sha256=sha(__file__)))
    assert result['original']['raw_right_left_sha256']==result['replacement']['raw_right_left_sha256']
    (out/'manifest.json').write_text(json.dumps(result,indent=2)+'\n')
    print(f"{result['original']['frames']} exact stereo frames exported")


if __name__=='__main__':
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('original',type=Path);ap.add_argument('replacement',type=Path)
    ap.add_argument('--out',type=Path,required=True)
    a=ap.parse_args();render(a.original,a.replacement,a.out)
