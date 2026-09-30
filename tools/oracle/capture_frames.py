"""Check that a headless run reached its requested frame or scripted exit."""
import re
from pathlib import Path

def expected_frames(requested, play):
    limit=requested
    if not play: return limit
    text=Path(play).read_text(encoding='utf-8')
    for line in text.splitlines():
        fields=line.split()
        if len(fields)>=2 and fields[1]=='EXITF':
            limit=min(limit,int(fields[0],0))
        elif len(fields)>=2 and fields[1]=='EXIT':
            # Millisecond timelines have no frame-exact exit target.
            return 1
    return limit

def observed_frames(log):
    matches=re.findall(r'\[vf3\] ran (\d+) frames',Path(log).read_text(encoding='utf-8',errors='replace'))
    return int(matches[-1]) if matches else -1
