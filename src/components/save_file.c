#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>


bool drawSaveFile(struct saveFile *saveFile) {
  //Declaração das variáveis
  int name_x = saveFile->x + 200;
  int name_y = saveFile->y + 50;

  /*int honor_x;
  int honor_y;

  int hours_x;
  int hours_y;

  int currentStage_x;
  int currentStage_y;*/
  printf("\n draw save file executada\n");
  //Escrita dos textos
  al_draw_text(saveFile->font, saveFile->font_color, name_x, name_y, 0, saveFile->name);
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
