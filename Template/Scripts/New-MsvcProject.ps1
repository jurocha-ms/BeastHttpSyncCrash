param(
    [Parameter(Mandatory=$true)]
    [string] $Name
)

[System.IO.Directory] $solutionDir = Split-Path -Path $PSScriptRoot

Copy-Item -Recurse "$solutionDir\Template" -Destination "$solutionDir\$Name"

Get-ChildItem