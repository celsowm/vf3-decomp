$ErrorActionPreference = 'Continue'
# Focused campaign: the 44 switch variants (index 227..270) that gate everything
# past 0x8c0c329C in 0x8C0C321E. 3 probes per run, so 16 runs covers them.
$offsets = 225,228,231,234,237,240,243,246,249,252,255,258,261,264,267,270
$i = 0
foreach ($off in $offsets) {
    $name = "c321e_sw{0:d3}" -f $i
    Write-Output "=== run $i offset $off -> $name ==="
    python tools/golden_batch.py --name $name --watch tools/watch/vf3_c321e.txt `
        --out "extract/analysis/c321e_sw/$name" `
        --entry-patch tools/oracle/phase3_c321e.patch `
        --max-samples 200 --capsule --probe-debug --probe-offset $off `
        --run dev:extract/analysis/vf3_fight_keep.state:extract/analysis/vf3_play_actions.txt:600 `
        2>&1 | Select-String -Pattern 'complete cases|Rejected|rc=|failed' | ForEach-Object { $_.Line }
    $i++
}
Write-Output "switch campaign done: $i runs"
