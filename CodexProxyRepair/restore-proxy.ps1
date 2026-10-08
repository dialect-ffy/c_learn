$ErrorActionPreference = 'Stop'
$backupPath = Join-Path $PSScriptRoot 'proxy-env-before.json'
$before = Get-Content -LiteralPath $backupPath -Raw | ConvertFrom-Json
$userEnv = [Microsoft.Win32.Registry]::CurrentUser.CreateSubKey('Environment')
foreach ($property in $before.PSObject.Properties) {
    if ([string]::IsNullOrEmpty($property.Value)) { $userEnv.DeleteValue($property.Name, $false) }
    else { $userEnv.SetValue($property.Name, $property.Value, [Microsoft.Win32.RegistryValueKind]::String) }
}
$userEnv.Close()
Write-Output 'Original user proxy environment restored. Restart the affected apps to apply.'
