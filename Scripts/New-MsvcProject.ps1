param(
    [Parameter(Mandatory=$true)]
    [string] $Name
)

[System.IO.DirectoryInfo] $solutionDir = Split-Path -Path $PSScriptRoot

Copy-Item -Recurse "$solutionDir\Template" -Destination "$solutionDir\$Name" -Exclude *.user

Get-ChildItem $solutionDir\$Name\Template.* | ForEach-Object {
    Move-Item $_ ("$_" -replace 'Template', $Name)
}

[xml] $xml = Get-Content $solutionDir\$Name\$Name.vcxproj
($xml.Project.PropertyGroup | Where-Object 'Label' -eq 'Globals').ProjectGuid = '{' + [guid]::NewGuid().ToString().ToUpper() + '}'
$xml.Save((Get-ChildItem $solutionDir\$Name\$Name.vcxproj))

Write-Host "Created $Name\$Name.vcxproj"