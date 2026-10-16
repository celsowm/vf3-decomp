#!/bin/bash
# run_native.sh <state...> - run the standalone native tick (build/vf3) on captured fight states
# and check the RAM against the reference oracle and the hardware image.
#   tools/recomp/run_native.sh 4 5 7 9 10 11 12 13 14 15 16 37 41
# Needs build/vf3(.exe) and, per state, the files tools/recomp/run_state.sh produces.
# Exit status is the number of states that did not complete or did not match.
cd "$(dirname "$0")/../.." || exit 2
A=extract/analysis
EXE=${BUILD_DIR:-./build}/vf3
[ -x "$EXE" ] || EXE=$EXE.exe
bad=0
for n in "$@"; do
  out=$($EXE "$A/golden_tickx_vf3_$n.bin" --expect "$A/oracle_tick_s$n.bin" --hw "$A/flycast_exit_s$n.bin" \
        --ta-out "$A/ta_s$n.bin" 2>&1)
  status=$?
  line=$(echo "$out" | sed -n 's/^tick \(.*\)$/\1/p')
  ram=$(echo "$out" | sed -n 's/^ram vs [^:]*: \(.*\)$/\1/p')
  ta=$(echo "$out" | sed -n 's/^hardware: .*, \([0-9]*\) TA words$/\1 TA words/p')
  echo "state $n: $line; $ta; ram $ram"
  [ $status -eq 0 ] || bad=$((bad + 1))
done
exit $bad
