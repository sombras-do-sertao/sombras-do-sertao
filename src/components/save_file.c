#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>


bool drawSaveFile(struct saveFile *saveFile) {
  //Declaração das variáveis

  int name_x = saveFile->x - 10;
  int name_y = saveFile->y + 10;

  int currentStage_x = name_x;
  int currentStage_y = name_y + 70;


  int honor_x = currentStage_x + 310;
  int honor_y = currentStage_y + 10;

  int hours_x = honor_x + 180;
  int hours_y = honor_y;
  
  int imageX = WIDTH_SCREEN/2 - 379; //metade da largura da imagem
  int imageY = saveFile->y;
  
  printf("\n draw save file executada\n");

  //desenha a img
  al_draw_bitmap(saveFile->image, imageX, imageY, 0);

  //Escrita dos textos
  al_draw_text(saveFile->font, saveFile->font_color, name_x, name_y, 0, saveFile->name); //nome do save
  al_draw_text(saveFile->smallerFont, saveFile->font_color, currentStage_x, currentStage_y, 0, saveFile->faseAtual); //fase atual
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  honor_x, honor_y, 0, saveFile->honra);//honra
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  hours_x, hours_y, 0, saveFile->horas);//horas

}
