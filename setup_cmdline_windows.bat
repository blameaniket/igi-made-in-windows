@echo off

doskey make=.\build_windows.bat $*
doskey neovide="C:\Program Files\neovim-qt 0.2.19\bin\nvim-qt.exe" -platform windows:darkmode=1 $*
cmd /k
