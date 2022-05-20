@echo Compile programm...
@echo off
g++ -g .\bin_tree.cpp -o .\bin_tree.exe
if %errorlevel% == 0 (@echo Run application... && @echo off && .\bin_tree.exe)