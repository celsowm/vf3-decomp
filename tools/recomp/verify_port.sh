#!/usr/bin/env bash
# Full per-port verification: state replay, native tick, oracle+poison tickmix, scratch deps, ledger.
# usage: tools/recomp/verify_port.sh 0x8c073aac   (run after serial build into build2)
export PATH="$PATH:/c/msys64/ucrt64/bin:/c/msys64/usr/bin"
S="4 5 7 9 10 11 12 13 14 15 16 37 41"
echo "run_state (want 26): $(BUILD_DIR=./build2 bash tools/recomp/run_state.sh $S 2>&1 | grep -c '; 0 arg 0 out mismatches')"
echo "run_native (want 13): $(BUILD_DIR=./build2 bash tools/recomp/run_native.sh $S 2>&1 | grep -c 'ram 0 bytes differ')"
for n in $S; do ( for m in oracle poison; do TICK_SCRATCH=$m TICK_DEVLOG=extract/analysis/devlog_tick_s$n.bin TICK_HW_RAM=extract/analysis/flycast_exit_s$n.bin ./build2/vf3tickmix.exe 0x8c09616a extract/analysis/golden_tickx_vf3_$n.bin extract/analysis/fxr_tick_s$n.bin extract/analysis/oracle_tick_s$n.bin 0 2>&1 | grep -i "STORE MISMATCH\|OUT MISMATCH\|PRESERVE" | head -2 | sed "s/^/s$n $m: /"; done ) & done; wait
echo "(no lines above = tickmix clean)"
[ -n "$1" ] && python tools/recomp/scratch_deps.py 0x0c$(printf %s "${1#0x8c}") --jobs 4 2>&1 | tail -1
python tools/recomp/readable_ledger.py | tail -1
