param(
    [Parameter(Mandatory=$true)][string]$Plan,
    [string]$Out = 'extract/analysis/capture_cleanup_applied.json',
    [switch]$Apply
)
$ErrorActionPreference = 'Stop'
$taskRepo = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot '../..')).Path
$taskAnalysis = (Resolve-Path -LiteralPath (Join-Path $taskRepo 'extract/analysis')).Path
$taskPlan = Get-Content -LiteralPath $Plan -Raw | ConvertFrom-Json -AsHashtable
if (-not $taskPlan.dry_run -or $taskPlan.analysis -ne $taskAnalysis) {
    throw 'Expected a capture_storage plan for this workspace analysis directory'
}
# Validate every absolute file before deleting any. No recursive operations.
foreach ($candidate in $taskPlan.candidates) {
    $file = Get-Item -LiteralPath $candidate.path
    if ($file.Directory.FullName -ne $taskAnalysis -or $file.Extension -ne '.bin' -or
        $file.Name -notlike 'capsule_*' -or $file.Name -like '*target*' -or
        $file.Length -ne $candidate.bytes -or
        ($file.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Unsafe or changed cleanup candidate: $($candidate.path)"
    }
    $manifest = Get-Content -LiteralPath $candidate.manifest -Raw | ConvertFrom-Json -AsHashtable
    if (-not $manifest.ContainsKey('entries')) { throw 'Missing specimen index' }
    foreach ($records in $manifest.entries.Values) {
        if ($records.Count -gt 0) { throw 'Candidate corpus has valid specimens' }
    }
}
if (-not $Apply) {
    Write-Output "$($taskPlan.candidates.Count) cleanup candidates validated; no deletion"
    return
}
$taskRemoved = [System.Collections.Generic.List[object]]::new()
try {
    foreach ($candidate in $taskPlan.candidates) {
        Remove-Item -LiteralPath $candidate.path
        $taskRemoved.Add($candidate)
    }
} finally {
    @{removed=@($taskRemoved.ToArray()); plan=$Plan;
      free_bytes=([IO.DriveInfo]::new([IO.Path]::GetPathRoot($taskAnalysis))).AvailableFreeSpace
    } | ConvertTo-Json -Depth 7 | Set-Content -Encoding utf8 -LiteralPath $Out
}
Write-Output "$($taskRemoved.Count) old invalid capsules removed; journal: $Out"
