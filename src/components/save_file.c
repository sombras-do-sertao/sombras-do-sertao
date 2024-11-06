#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>


bool drawSaveFile(struct saveFile *saveFile) {
  //Declaração das variáveis

  smaller_font = al_load_font("assets/fonts/LilitaOne-Regular.ttf",18,0);
  

  int name_x = saveFile->x - 10;
  int name_y = saveFile->y + 10;

  int currentStage_x = name_x;
  int currentStage_y = name_y + 70;


  int honor_x = currentStage_x + 100;
  int honor_y = currentStage_y;

  int hours_x;
  int hours_y;

  
  int imageX = WIDTH_SCREEN/2 - 379; //metade da largura da imagem
  int imageY = saveFile->y;
  
  printf("\n draw save file executada\n");

  //desenha a img
  al_draw_bitmap(saveFile->image, imageX, imageY, 0);

  //Escrita dos textos
  al_draw_text(saveFile->font, saveFile->font_color, name_x, name_y, 0, saveFile->name); //nome do save
  al_draw_text(smaller_font, saveFile->font_color, currentStage_x, currentStage_y, 0, "Fase atual: 0"); //fase atual
  al_draw_text(smaller_font, saveFile->font_color,  honor_x, honor_y, 0, "Honra: 20");//Honra
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
