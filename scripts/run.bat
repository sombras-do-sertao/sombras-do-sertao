@echo off
setlocal

cls

set PATH=C:\MinGW\bin;%PATH%
set PATH=C:\allegro\bin;%PATH%

:: Caso esteja no diretorio script volta 1 diretório
if (%cd:~-7%) == (scripts) (
  cd ..
)

set SRC_DIR=src
set BIN_DIR=bin

:: Arquivos fonte
set SRCS=%SRC_DIR%\main.c ^
%SRC_DIR%\helper.c ^
%SRC_DIR%\screens.c ^
%SRC_DIR%\handle.c ^
%SRC_DIR%\sound.c ^
%SRC_DIR%\components.c ^
%SRC_DIR%\protagonista.c

:: Nome do executável
set TARGET=%BIN_DIR%\game.exe

:: Flags do compilador
set CFLAGS=-I"C:\allegro\include"
set LDFLAGS=-L"C:\allegro\lib" -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

if not exist %BIN_DIR% mkdir %BIN_DIR%

:: Compilar os arquivos fonte
gcc %SRCS% -o %TARGET% %CFLAGS% %LDFLAGS%

if %errorlevel% neq 0 (
  echo Compilation failed!
  pause
  exit /b
)

:: Executar o programa
%TARGET%

endlocal