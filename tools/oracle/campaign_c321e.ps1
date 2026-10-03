$ErrorActionPreference = 'Continue'
# 0x8C0C321E seed sweep. The oracle fires ~3 probes per run and rotates seed
# variants round-robin, so walking all 227 variants needs ceil(227/3) runs,
# stepping --probe-offset by 3 each time.
$total = 227
$step  = 3
$runs  = [math]::Ceiling($total / $step)
Write-Output "planning $runs runs x $step probes (offset 0..$total)"

for ($i = 0; $i -lt $runs; $i++) {
    $off = $i * $step
    $name = "c321e_{0:d3}" -f $i
    $out  = "extract/analysis/c321e_runs/$name"
    Write-Output "=== run $i offset $off -> $name ==="
    python tools/golden_batch.py --name $name --watch tools/watch/vf3_c321e.txt `
        --out $out --entry-patch tools/oracle/phase3_c321e.patch `
        --max-samples 200 --capsule --probe-debug --probe-offset $off `
        --run dev:extract/analysis/vf3_fight_keep.state:extract/analysis/vf3_play_actions.txt:600 `
        2>&1 | Select-String -Pattern 'distinct complete cases|Rejected|rc=|failed|WARNING' | ForEach-Object { $_.Line }
    if ($LASTEXITCODE -ne 0) { Write-Output "  run $i FAILED rc=$LASTEXITCODE" }
}
Write-Output "campaign done: $runs runs"
