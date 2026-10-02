@echo off

rg --files | fzf > "%TEMP%\catfile_selection.txt"

set /p "file=" < "%TEMP%\catfile_selection.txt"

if not defined file exit /b

echo.
echo Selected: %file%
echo ----------------------------------------
type "%file%"

del "%TEMP%\catfile_selection.txt" >nul 2>&1
