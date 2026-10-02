@echo off

doskey make=nob.exe $*
doskey neovide="C:\Program Files\neovim-qt 0.2.19\bin\nvim-qt.exe" -platform windows:darkmode=1 $*
cmd /k
