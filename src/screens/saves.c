#include "../headers/screens.h"
#include "../headers/components.h"
#include "../headers/helper.h"
#include <stdio.h>

struct saveFile FILES[SAVEFILES_COUNT];

ALLEGRO_FONT *fontSettings;
ALLEGRO_BITMAP *fileBackground
setupSaves(){
  fontSettings = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  fileBackground = al_load_bitmap("assets/images/background/save.jpg");
  int width = 404;
  int height = 72;

  struct saveFile save1 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 - 72,
    width,
    height,
    "Pedro",
    "Save 01", 
    fontSettings,
    AL_COLOR_WHITE,
    fileBackground,
  }; save1 = FILES[0];

  struct saveFile save2 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 72,
    width,
    height,
    "Lucas",
    "Save 02", 
    fontSettings,
    AL_COLOR_WHITE,
    fileBackground,
  }; save2 = FILES[1];

  struct saveFile save3 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 216,
    width,
    height,
    "Eduardo",
    "Save 03", 
    fontSettings,
    AL_COLOR_WHITE,
    fileBackground,
  }; save3 = FILES[2];

}

 /*int x;
  int y;
  int width;
  int height; 
  char *name;
  char *alias; 
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_BITMAP *image;*/