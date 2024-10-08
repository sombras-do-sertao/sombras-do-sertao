@echo off
setlocal

:: Diretórios
set SRC_DIR=src
set BIN_DIR=bin

:: Arquivos fonte
set SRCS=%SRC_DIR%\*.c

:: Nome e diretorio do executável
set TARGET=%BIN_DIR%\SombrasDoSertao.exe

:: Configurações do Allegro
set PROJECT_ROOT=%~dp0..\
set CFLAGS=-I"%PROJECT_ROOT%bin\allegro\include"
set LDFLAGS=-L"%PROJECT_ROOT%bin\allegro\lib" -lallegro -lallegro_font -lallegro_ttf -lallegro_image -lallegro_primitives -lallegro_audio -lallegro_acodec

:: Compilar os arquivos fonte
gcc %SRCS% -o %TARGET% %CFLAGS% %LDFLAGS%

:: Verificar se a compilação foi bem sucedida
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
