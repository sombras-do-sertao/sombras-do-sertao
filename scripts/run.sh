#!/bin/bash
clear

# Diretórios
SRC_DIR="src"
BIN_DIR="bin"

# Arquivos fonte
SRCS="$SRC_DIR/main.c \
$SRC_DIR/helper.c \
$SRC_DIR/screens.c \
$SRC_DIR/handle.c \
$SRC_DIR/sound.c \
$SRC_DIR/components.c \
$SRC_DIR/protagonista.c"

# Nome do executável
TARGET="$BIN_DIR/out"

# Flags do compilador
CFLAGS=$(pkg-config --cflags allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)
LDFLAGS=$(pkg-config --libs allegro-5 allegro_font-5 allegro_image-5 allegro_primitives-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)

# Criar diretório bin se não existir
if [ ! -d "$BIN_DIR" ]; then
  mkdir -p "$BIN_DIR"
fi

# Compilar os arquivos fonte
gcc $SRCS -o $TARGET $CFLAGS $LDFLAGS

# Verificar se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
  echo "Compilation succeeded!"
  # Executar o programa
  ./$TARGET
else
  echo "Compilation failed!"
  exit 1
fi