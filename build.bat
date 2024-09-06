@echo off

:: creates bin and obj folders if they do not exist
if not exist bin mkdir bin
if not exist obj mkdir obj

:: compile the source files from src to object (obj) folder
gcc -Wall -std=c99 -I src -c src\lit.c -o obj\lit.o
gcc -Wall -std=c99 -I src -c src\file_handeling.c -o obj\file_handeling.o
gcc -Wall -std=c99 -I src -c src\commit.c -o obj\commit.o
gcc -Wall -std=c99 -I src -c src\main.c -o obj\main.o

:: linked the objects to create an executable file in the bin folder
gcc -o bin\lit.exe obj\main.o obj\lit.o obj\file_handeling.o obj\commit.o -mconsole

:: check if the executable was created in the bin folder
if exist bin\lit.exe (
    echo Build successful! lit.exe created in bin directory.

    echo.
    echo "            %@@@&                                            "
    echo "         @@@@ @*@@@@                                         "
    echo "       &@@@ @@@@@ @@@@      @@@@      @@@@ @@@@@@@@@@@        "
    echo "    &@@@ @@@@&.% @@& @@@&   @@@@      @@@@     @@@&           "
    echo "   @@@@  @@@  @ @@@@  @@@@  @@@@      @@@@    @@@@@           "
    echo "     @@@@ @@@@ @&@@@ @@@@    @@@@      @@@@    @@@@@           "
    echo "        @@ @%&@@ @ &@@@       @@@@@@@@@ @@@@    @@@@@           "
    echo "          @@@@,@@@@                                         "
    echo "             &@@                                            "
    echo.
    echo "Lit Build is Completed"
    echo "Lit it Now "
    echo.

    :: compiled the test file
    echo Running tests...
    gcc -Wall -std=c99 -I src -c test\test_lit.c -o obj\test_lit.o
    gcc -o bin\test_lit.exe obj\test_lit.o obj\lit.o obj\file_handeling.o obj\commit.o -mconsole
    bin\test_lit.exe

    :: clean up test executables
    del /Q obj\test_lit.o
    del /Q bin\test_lit.exe
) else (
    echo Build failed! Check for errors.
)

pause
