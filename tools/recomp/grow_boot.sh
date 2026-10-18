#!/bin/sh
# Grow the generated adapters along the boot path until the native loader run stops failing on an unowned address.
#   tools/recomp/grow_boot.sh [max_rounds] [state]
# Each round: run vf3boot past the loader wait (--continue), read the address the run failed at, add it to
# tools/watch/boot_seeds.txt, rebuild the static PC dump from the seeds (tools/static_pcs.py), regenerate
# src/fight/tickgap_adapters.c (tools/recomp/regen_tickgap.sh) and rebuild. Stops when the run ends without a failure
# or the same address fails twice (a different kind of gap: look at it by hand).
set -e
export PATH="/c/msys64/ucrt64/bin:$PATH:/c/msys64/usr/bin"
ROUNDS=${1:-10}
ST=${2:-21}
A=extract/analysis
SEEDS=tools/watch/boot_seeds.txt
touch $SEEDS
i=0
while [ $i -lt $ROUNDS ]; do
    i=$((i + 1))
    out=$(./build/vf3boot.exe $A/golden_bootV_vf3_$ST.bin $A/golden_bootI_vf3_30.bin $A/golden_bootS_vf3_30.bin \
        --loop-entry 0x8c035cba --loop-stop 0x0c035530 --irqa 0x8c063d1e --irqb 0x8c062e94 --cycle-frames 300 \
        --first-polls 531 --gd-phase 565440 --full-loop 1 --continue 4000 --aica-word 88:001e0000 --vblank-cap 120 --gdi rom/vf3.gdi \
        --gd-state $A/gdstate_s${ST}_0c0432de.txt 2>&1 | grep -E "hop|after the wait" | tail -2)
    echo "round $i: $out" | tail -3
    bad=$(echo "$out" | grep -o "failed [0-9a-f]*" | tail -1 | cut -d' ' -f2)
    first=$(echo "$out" | grep -o "first [0-9a-f]*" | tail -1 | cut -d' ' -f2)
    pc=""
    [ -n "$bad" ] && [ "$bad" != "00000000" ] && pc=$bad
    [ -z "$pc" ] && [ -n "$first" ] && [ "$first" != "00000000" ] && pc=$first
    if [ -z "$pc" ]; then echo "no failing address: done"; break; fi
    if grep -qi "^0x$pc" $SEEDS; then echo "0x$pc already seeded: stop"; break; fi
    echo "0x$pc" >> $SEEDS
    if [ "$(python tools/static_pcs.py --is-entry 0x$pc)" = 1 ]; then echo "0x$pc" >> tools/watch/boot_entries.txt; fi
    python tools/recomp/gen_call_targets.py --edges $A/p4 --extra tools/watch/boot_entries.txt > /dev/null 2>&1
    python tools/static_pcs.py --seed-file $SEEDS --edges $A/p4 --out $A/tick_static_boot_pcs.txt
    sh tools/recomp/regen_tickgap.sh $A/tick_s*_pcs.txt $A/tick_static_boot_pcs.txt > /dev/null
    cmake --build build 2>&1 | grep -E "error" || true
done
