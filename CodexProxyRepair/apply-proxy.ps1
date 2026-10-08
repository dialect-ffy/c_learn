$ErrorActionPreference = 'Stop'
$proxyAddress = 'http://127.0.0.1:7897'
$backupPath = Join-Path $PSScriptRoot 'proxy-env-before.json'
$names = @('HTTP_PROXY','HTTPS_PROXY','ALL_PROXY','NO_PROXY')
if (-not (Test-Path -LiteralPath $backupPath)) {
    $before = [ordered]@{}
    foreach ($name in $names) { $before[$name] = [Environment]::GetEnvironmentVariable($name, 'User') }
    $before | ConvertTo-Json | Set-Content -LiteralPath $backupPath -Encoding utf8
}
$userEnv = [Microsoft.Win32.Registry]::CurrentUser.CreateSubKey('Environment')
foreach ($name in @('HTTP_PROXY','HTTPS_PROXY','ALL_PROXY')) {
    $userEnv.SetValue($name, $proxyAddress, [Microsoft.Win32.RegistryValueKind]::String)
}
$existingBypass = [Environment]::GetEnvironmentVariable('NO_PROXY', 'User')
$bypass = @($existingBypass -split ',' | Where-Object { $_.Trim() }) + @('localhost','127.0.0.1','::1')
$userEnv.SetValue('NO_PROXY', (($bypass | Select-Object -Unique) -join ','), [Microsoft.Win32.RegistryValueKind]::String)
$userEnv.Close()
Add-Type @'
using System;
using System.Runtime.InteropServices;
public static class ProxyEnvironmentUpdate {
    [DllImport("user32.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    public static extern bool SendNotifyMessage(IntPtr hWnd, uint msg, UIntPtr wParam, string lParam);
}
'@
[void][ProxyEnvironmentUpdate]::SendNotifyMessage([IntPtr]0xffff, 0x1a, [UIntPtr]::Zero, 'Environment')
foreach ($name in $names) {
    $value = [Environment]::GetEnvironmentVariable($name, 'User')
    if ($name -ne 'NO_PROXY' -and $value -ne $proxyAddress) { throw "Verification failed for $name" }
    Write-Output "$name=$value"
}
Write-Output "Backup saved to $backupPath"
