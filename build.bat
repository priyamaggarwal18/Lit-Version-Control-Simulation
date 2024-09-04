:: echo off disables to display all the command in this bat file except the echo commands
@echo off

:: creates a bin and obj file if not exist
if not exist bin mkdir bin
if not exist obj mkdir obj

:: compile the source files from src to object (obj) folder
gcc -Wall -std=c99 -c src\lit.c -o obj\lit.o
gcc -Wall -std=c99 -c src\file_handeling.c -o obj\file_handeling.o
gcc -Wall -std=c99 -c src\commit.c -o obj\commit.o
gcc -Wall -std=c99 -c src\main.c -o obj\main.o

:: Link the objects to create a executable files in binary(bin) folder
gcc -o bin\lit.exe obj\main.o obj\lit.o obj\file_handeling.o obj\commit.o -mconsole

:: check if the executable was created in binary folder
if exist bin\lit.exe (
    echo Build successful! lit.exe created in bin directory.
    
) else (
    echo Build failed! Check for errors.
)

pause
