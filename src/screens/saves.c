#include "../headers/screens.h"
#include "../headers/components.h"
#include "../headers/helper.h"
#include <stdio.h>

struct saveFile FILES[SAVEFILES_COUNT];

ALLEGRO_FONT *fontSaves;
ALLEGRO_FONT *fontSaveTitle; //vai ficar no topo da tela
ALLEGRO_BITMAP *fileBackground;

void setupSaves(){
  
  ALLEGRO_FONT *smaller_font;

  fontSaves = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  fontSaveTitle = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 64, 0);
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
  }; FILES[0] = save1;

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
  }; FILES[1] = save2;

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
  }; FILES[2] = save3;

   struct saveFile save4 = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 288,
    width,
    height,
    "Vazio",
    "Save 04", 
    0, //fase
    0, //horas
    0, //honra  
    fontSaves,
    AL_COLOR_WHITE,
    fileBackground,
  }; FILES[3] = save4;

  printf("\nsetup saves executada \n");

}

bool drawSaves() {
  printf("\n draw saves executada \n");
  al_draw_bitmap(bg_home, 0, 0, 0);

  //Titulo da tela
  const char *title_text = "Jogos salvos";
  int text_width = al_get_text_width(fontSaveTitle, title_text);
  int title_x = WIDTH_SCREEN / 2 - text_width / 2;
  int title_y = 60;
  al_draw_text(fontSaveTitle, AL_COLOR_WHITE, title_x, title_y, 0, title_text);

  drawSaveFile(&FILES[0]);
  /*for(int i = 0; i < SAVEFILES_COUNT; i++) {
  


  }*/

 return true;
}

void destroySaves() {
  al_destroy_font(fontSaves);
  al_destroy_font(fontSaveTitle);
  al_destroy_bitmap(fileBackground);
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
