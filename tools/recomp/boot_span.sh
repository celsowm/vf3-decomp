#!/bin/bash
# boot_span.sh <entry> <state...> - capture one function of a boot savestate and replay it natively against the recorded exit.
#   tools/recomp/boot_span.sh 0x8c0434c8 21 23 24
# GD seed: extract/analysis/gdstate_s<N>_0c0432de.txt when present (needed for spans that reach the GET_CMD_STAT wrapper).
# Prints one line per state; "4 bytes differ" is the saved-return slot (native sentinel 0xDEAD0000), i.e. a match.
cd "$(dirname "$0")/../.." || exit 2
entry=$1; shift
for n in "$@"; do
  python=tools/.venv/Scripts/python
  $python tools/tick_capture.py "$entry" --state tools/emu/flycast-build/data/vf3_$n.state --frames 120 --pairs 1 --name bootS > /dev/null 2>&1
  seed=extract/analysis/gdstate_s${n}_0c0432de.txt
  [ -f "$seed" ] && seedarg="--gd-state $seed" || seedarg=""
  echo "state $n: $(./build/vf3.exe extract/analysis/golden_bootS_vf3_$n.bin --entry "$entry" --gdi rom/vf3.gdi $seedarg --gd-polls-per-step 179 --vs-exit 2>&1 | grep -E 'tick |ram vs|no ' | tr '\n' ' ')"
done
