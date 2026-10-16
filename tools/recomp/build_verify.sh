#!/usr/bin/env bash
# One-shot incremental build into build2 + full verify of a port.
# usage: tools/recomp/build_verify.sh 0x8c09363a
# Rebuilds only changed sources (no touch), kills stale exes first, builds the three targets in one make call.
export PATH="/c/msys64/ucrt64/bin:/c/msys64/usr/bin:$PATH"
cd "$(dirname "$0")/../.."
taskkill //F //IM vf3tickmix.exe >/dev/null 2>&1
taskkill //F //IM vf3.exe >/dev/null 2>&1
[ -f build2/Makefile ] || cmake -S . -B build2 -G "MinGW Makefiles" >/dev/null
# re-run cmake only when the source list changed (add_readable_port edits CMakeLists.txt)
[ CMakeLists.txt -nt build2/Makefile ] && cmake -S . -B build2 -G "MinGW Makefiles" >/dev/null
mingw32-make -C build2 -j8 vf3core vf3tickmix vf3 2>&1 | grep -E "error|denied|undefined"
tools/recomp/verify_port.sh "$1" 2>&1 | tail -25
echo ALLDONE
