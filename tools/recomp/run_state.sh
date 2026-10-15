#!/bin/bash
# run_state.sh <state...> - oracle record + native whole-tick verification for savestates
# whose golden capture (tools/tick_capture.py ... --name tickx) already exists.
#   tools/recomp/run_state.sh 4 5 9 11
# Prints one summary line per state. Needs refs/dream-recomp/build-vf3 and build/vf3tickmix.exe.
# TICK_GBR defaults to the fight tasks' context (0x0c16b880).
cd "$(dirname "$0")/../.." || exit 2
A=extract/analysis
ORACLE=refs/dream-recomp/build-vf3/games/vf3tb/vf3tb_tick.exe
for n in "$@"; do
  g=$A/golden_tickx_vf3_$n.bin
  [ -s "$g" ] || { echo "state $n: no capture"; continue; }
  TICK_GBR=${TICK_GBR:-0x0c16b880} TICK_INTERP=1 TICK_REC=$A/fxr_tick_s$n.bin \
    TICK_STATS=$A/fxr_tick_s${n}_stats.csv TICK_DUMP=$A/oracle_tick_s$n.bin \
    TICK_DEVLOG=$A/devlog_tick_s$n.bin TICK_EXITDUMP=$A/flycast_exit_s$n.bin \
    TICK_PCS=$A/tick_s${n}_pcs.txt $ORACLE 0x8c09616a "$g" 0 > /dev/null 2>&1
  if [ ! -s "$A/fxr_tick_s$n.bin" ]; then echo "state $n: no complete entry/exit pair"; continue; fi
  for mode in oracle poison; do
    out=$(TICK_SCRATCH=$mode TICK_DEVLOG=$A/devlog_tick_s$n.bin TICK_HW_RAM=$A/flycast_exit_s$n.bin \
      ./build/vf3tickmix.exe 0x8c09616a "$g" $A/fxr_tick_s$n.bin $A/oracle_tick_s$n.bin 0 2>&1)
    steps=$(echo "$out" | sed -n 's/^oracle steps under top-level calls: \([0-9]*\),.*native: \(.*\)$/\1 steps, native \2/p')
    stubs=$(echo "$out" | sed -n 's/^stub calls \([0-9]*\) .*readable calls \([0-9]*\)$/\1 stubs, \2 readable calls/p')
    mism=$(echo "$out" | sed -n 's/^arg mismatches \([0-9]*\)  readable output mismatches \([0-9]*\).*/\1 arg \2 out mismatches/p')
    ram=$(echo "$out" | sed -n 's/^ram diff bytes: \([0-9]*\) in.*/\1/p')
    echo "state $n [$mode]: $steps; $stubs; $mism; RAM diff vs oracle $ram bytes"
  done
done
