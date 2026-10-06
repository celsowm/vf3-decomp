param(
    [Parameter(Mandatory=$true)][string]$Plan,
    [string]$Out = 'extract/analysis/decoded_cleanup_applied.json',
    [switch]$Apply
)
$ErrorActionPreference = 'Stop'
$taskRepo = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot '../..')).Path
$taskAnalysis = (Resolve-Path -LiteralPath (Join-Path $taskRepo 'extract/analysis')).Path
$taskPlan = Get-Content -LiteralPath $Plan -Raw | ConvertFrom-Json -AsHashtable
if (-not $taskPlan.dry_run -or $taskPlan.mode -ne 'decoded_cache' -or
    $taskPlan.analysis -ne $taskAnalysis) { throw 'Expected a decoded_storage plan for this workspace' }
$taskProtected = [System.Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
foreach ($directory in $taskPlan.protected_directories) { [void]$taskProtected.Add($directory) }
foreach ($directory in $taskPlan.corpora.Keys) {
    $resolved = (Resolve-Path -LiteralPath $directory).Path
    if ($resolved -ne $directory -or -not $resolved.StartsWith($taskAnalysis+'\', [StringComparison]::OrdinalIgnoreCase) -or
        $resolved -like '*target*' -or $taskProtected.Contains($resolved)) {
        throw "Protected or unsafe corpus: $directory"
    }
    $batch = Get-Content -LiteralPath (Join-Path $directory 'batch_manifest.json') -Raw | ConvertFrom-Json -AsHashtable
    foreach ($run in $batch.runs) {
        if ($run.returncode -ne 0 -or -not $run.frame_complete) { throw 'Original capture was incomplete' }
    }
    foreach ($source in $taskPlan.corpora[$directory].sources) {
        $file = Get-Item -LiteralPath $source.path
        if ($file.Length -ne $source.bytes -or $file.Name -notlike 'capsule_*.bin') {
            throw "Original capsule missing or changed: $($source.path)"
        }
    }
}
# Validate all exact files before deleting any. Keep manifests and original capsules.
foreach ($candidate in $taskPlan.candidates) {
    $file = Get-Item -LiteralPath $candidate.path
    if ($file.Directory.FullName -ne $candidate.corpus -or
        -not $taskPlan.corpora.ContainsKey($candidate.corpus) -or
        $file.Name -notmatch '^f_[0-9a-f]{8}_[0-9]+\.(in|out)\.bin$' -or
        $file.Length -ne $candidate.bytes -or
        ($file.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Unsafe or changed shadow: $($candidate.path)"
    }
}
if (-not $Apply) {
    Write-Output "$($taskPlan.candidates.Count) old cache files validated; no deletion"
    return
}
$taskRemoved = [System.Collections.Generic.List[string]]::new()
try {
    foreach ($candidate in $taskPlan.candidates) {
        Remove-Item -LiteralPath $candidate.path
        $taskRemoved.Add($candidate.path)
        if ($taskRemoved.Count % 10000 -eq 0) { Write-Output "$($taskRemoved.Count) old cache files removed" }
    }
} finally {
    @{removed=@($taskRemoved.ToArray()); plan=$Plan;
      free_bytes=([IO.DriveInfo]::new([IO.Path]::GetPathRoot($taskAnalysis))).AvailableFreeSpace
    } | ConvertTo-Json -Depth 5 | Set-Content -Encoding utf8 -LiteralPath $Out
}
Write-Output "$($taskRemoved.Count) decoded shadows removed; original capsules retained; journal: $Out"
