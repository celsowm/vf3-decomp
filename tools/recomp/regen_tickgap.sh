#!/bin/sh
# Regenerate src/fight/tickgap_adapters.c: adapters for every guest PC that an oracle tick executed
# but no other generated adapter owns. Inputs are TICK_PCS dumps of tick_oracle (see
# docs/re/oracle_recomp.md); pass them as arguments, e.g.
#   tools/recomp/regen_tickgap.sh extract/analysis/tick_s7_pcs.txt extract/analysis/tick_s12_pcs.txt
set -e
A=extract/analysis
rm -rf $A/tickgap
python tools/recomp/unowned_pcs.py "$@" --skip tickgap_adapters.c --ops-dir $A/tickgap --root 0x8c06f3ba --name tickgap
python tools/oracle/translate_adapters.py $A/tickgap --watch tools/watch/vf3_tickgap.txt \
    --function vf3_tickgap_adapter --reuse-matrix --reuse-adapter "src/fight/*.c" \
    --indirect-targets $A/tickgap/tickgap.indirect.json --out src/fight/tickgap_adapters.c
