param([int]$VkCode, [double]$HoldMs = 90)
# Send a single keystroke to the focused Flycast window.
$AddType = @'
using System;
using System.Runtime.InteropServices;
public class KB {
    [DllImport("user32.dll")] public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, UIntPtr dwExtraInfo);
    [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr hWnd);
    public const uint KEYUP = 0x2;
    public static void Tap(byte vk, int holdMs) {
        keybd_event(vk, 0, 0, UIntPtr.Zero);
        System.Threading.Thread.Sleep(holdMs);
        keybd_event(vk, 0, KEYUP, UIntPtr.Zero);
    }
}
'@
if (-not ([System.Management.Automation.PSTypeName]'KB').Type) { Add-Type -TypeDefinition $AddType }
$proc = Get-Process flycast -ErrorAction Stop | Where-Object { $_.MainWindowHandle -ne 0 }
if (-not $proc) { Write-Host 'no flycast window'; exit 1 }
[KB]::SetForegroundWindow($proc.MainWindowHandle) | Out-Null
Start-Sleep -Milliseconds 150
[KB]::Tap([byte]$VkCode, [int]$HoldMs)
Write-Host ("sent VK 0x{0:X2}" -f $VkCode)
