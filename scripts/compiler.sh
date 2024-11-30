#!/bin/bash
clear

# Diretórios
SRC_DIR="src"
BIN_DIR="bin"

# Arquivos fonte
SRCS="$SRC_DIR/*.c"

# Nome do executável
TARGET="$BIN_DIR/SombrasDoSertao"

# Flags do compilador
CFLAGS=$(pkg-config --cflags allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5 allegro_dialog-5)
LDFLAGS=$(pkg-config --libs allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5 allegro_dialog-5)

# Compilar os arquivos fonte
gcc $SRCS -o $TARGET $CFLAGS $LDFLAGS

# Verificar se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
  echo "Compilation succeeded!"
else
  echo "Compilation failed!"
  exit 1
fi

# Verificar se a flag --run foi passada
if [ "$1" == "--run" ]; then
  ./$TARGET
else
  echo "Use the --run flag to execute the program."
fi