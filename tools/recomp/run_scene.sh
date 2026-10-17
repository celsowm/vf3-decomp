#!/bin/bash
# run_scene.sh <entry> <capture.bin> <label> - oracle record + tickmix verification for a non-fight scene entry.
#   python tools/tick_capture.py 0x8c09144e --state tools/emu/flycast-build/data/vf3_2.state --frames 300 \
#          --pairs 1 --name p4scene --exitpc 0x8c0917e6
#   tools/recomp/run_scene.sh 0x8c09144e extract/analysis/golden_p4scene_vf3_2.bin p4_s2
# Same flow as run_state.sh (fxr record -> tickmix in oracle and poison scratch modes), parameterised by entry.
cd "$(dirname "$0")/../.." || exit 2
A=extract/analysis
ORACLE=refs/dream-recomp/build-vf3/games/vf3tb/vf3tb_tick.exe
entry=$1; g=$2; n=$3
TICK_GBR=${TICK_GBR:-0x0c16b880} TICK_INTERP=1 TICK_REC=$A/fxr_$n.bin TICK_STATS=$A/fxr_${n}_stats.csv \
  TICK_DUMP=$A/oracle_$n.bin TICK_DEVLOG=$A/devlog_$n.bin TICK_EXITDUMP=$A/flycast_exit_$n.bin \
  TICK_PCS=$A/${n}_pcs.txt $ORACLE "$entry" "$g" 0 > /dev/null 2>&1
[ -s "$A/fxr_$n.bin" ] || { echo "$n: no complete entry/exit pair"; exit 1; }
for mode in oracle poison; do
  TICK_SCRATCH=$mode TICK_DEVLOG=$A/devlog_$n.bin TICK_HW_RAM=$A/flycast_exit_$n.bin \
    ${BUILD_DIR:-./build2}/vf3tickmix.exe "$entry" "$g" $A/fxr_$n.bin $A/oracle_$n.bin 0 2>&1 | \
    grep -E "^oracle steps|^stub calls|^arg mismatches|^ram diff bytes|MISMATCH" | head -${LINES_MAX:-12} | sed "s/^/[$mode] /"
done
