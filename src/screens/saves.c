#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "../headers/screens.h"
#include "../headers/components.h"


struct saveFile SAVE_ITEM[SAVE_FILES_COUNT];

ALLEGRO_BITMAP *saveBackground;
ALLEGRO_FONT *fontSaves;

void setupSaves(){
  fontSaves = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  saveBackground = al_load_bitmap("assets/images/background/save.jpg");

  int width = 300; 
  int height = 250;

  struct saveFile save1 = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 - 50,
    width,
    height,
    "Pedro",
    "Save 1",
    fontSaves,
    AL_COLOR_WHITE,
    saveBackground,
  };

  struct saveFile save2 = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 + 50,
    width,
    height,
    "João",
    "Save 2",
    fontSaves,
    AL_COLOR_WHITE,
    saveBackground,
  };

  struct saveFile save3 = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 + 150,
    width,
    height,
    "Jonas",
    "Save 3",
    fontSaves,
    AL_COLOR_WHITE,
    saveBackground,
  };

  SAVE_ITEM[0] = save1;
  SAVE_ITEM[1] = save2;
  SAVE_ITEM[2] = save3;
}

bool drawSaves(struct AllegroGame *game, GameState *gameState) {
  for(int i = 0; i < SAVE_FILES_COUNT; i++) {
    drawSaveFile(&SAVE_ITEM[i], game);  
  }
}

void destroySaves(void) {
  al_destroy_font(fontSaves);
  al_destroy_bitmap(saveBackground);
}

ALLEGRO_FONT *fontSettings;
