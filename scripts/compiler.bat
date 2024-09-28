@echo off
setlocal

:: Diretórios
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
set TARGET=%BIN_DIR%\SombrasDoSertao.exe

:: Flags do compilador
set PROJECT_ROOT=%~dp0..\

:: Verificar se os diretórios de inclusão e biblioteca existem
if not exist "%PROJECT_ROOT%bin\allegro\include" (
  echo Error: Directory %PROJECT_ROOT%allegro\include does not exist.
  pause
  exit /b 1
)

if not exist "%PROJECT_ROOT%bin\allegro\lib" (
  echo Error: Directory %PROJECT_ROOT%allegro\lib does not exist.
  pause
  exit /b 1
)

set CFLAGS=-I"%PROJECT_ROOT%bin\allegro\include"
set LDFLAGS=-L"%PROJECT_ROOT%bin\allegro\lib" -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

if not exist %BIN_DIR% mkdir %BIN_DIR%

:: Compilar os arquivos fonte
gcc %SRCS% -o %TARGET% %CFLAGS% %LDFLAGS%

if %errorlevel% neq 0 (
  echo Compilation failed!
  pause
  exit /b
)

:: Verificar se a flag --run foi passada
for %%i in (%*) do (
  if "%%i"=="--run" (
    %TARGET%
  )
)

endlocal
