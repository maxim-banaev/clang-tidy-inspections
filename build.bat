REM @echo off

set PATH=C:\cygwin64-3.0.1\bin;%PATH%

cd C:\Users\maxim.banaev\CLionProjects\clang-tidy-inspections\build

cmake.exe ..
cmake.exe --build . --target all
