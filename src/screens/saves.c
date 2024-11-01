#include "../headers/screens.h"
#include "../headers/components.h"
#include "../headers/helper.h"
#include <stdio.h>

struct saveFile FILES[SAVEFILES_COUNT];

ALLEGRO_FONT *fontSaves;
ALLEGRO_BITMAP *fileBackground;
void setupSaves(){
  fontSaves = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  fileBackground = al_load_bitmap("assets/images/background/save.jpg");
  int width = 404;
  int height = 72;

  struct saveFile save1 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 - 72,
    width,
    height,
    "Vazio",
    "Save 01",
    0, //fase
    0, //horas
    0, //honra  
    fontSaves,
    AL_COLOR_WHITE,
    fileBackground,
  }; save1 = FILES[0];

  struct saveFile save2 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 72,
    width,
    height,
    "Vazio",
    "Save 02",
    0, //fase
    0, //horas
    0, //honra   
    fontSaves,
    AL_COLOR_WHITE,
    fileBackground,
  }; save2 = FILES[1];

  struct saveFile save3 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 216,
    width,
    height,
    "Vazio",
    "Save 03", 
    0, //fase
    0, //horas
    0, //honra  
    fontSaves,
    AL_COLOR_WHITE,
    fileBackground,
  }; save3 = FILES[2];
  printf("\nsetup saves executada \n");

}

bool drawSaves() {
  printf("\n draw saves executada \n");
  al_draw_bitmap(bg_home, 0, 0, 0);
  drawSaveFile(&FILES[0]);
}

void destroySaves() {
  al_destroy_font(fontSaves);
}

/* int x;
  int y;
  int width;
  int height; 
  char *name;
  char *alias; 
  int fase;
  int horas;
  int honra;
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_BITMAP *image;*/
