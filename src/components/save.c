#include "../headers/components.h"
#include "../headers/helper.h"
#include "../headers/save.h"
#include <allegro5/allegro_font.h>
#include <stdio.h>

bool drawSaveFile(struct saveFile *saveFile, int index) {
  int width = 404;
  int height = 135;

  int x = WIDTH_SCREEN / 2 - width / 2;
  int y = 250 + (index * 180);

  int name_x = x - 10;
  int name_y = y + 10;

  int currentStage_x = name_x;
  int currentStage_y = name_y + 70;

  int honor_x = currentStage_x + 310;
  int honor_y = currentStage_y + 10;

  int minutes_x = honor_x + 180;
  int minutes_y = honor_y;
  
  int imageX = WIDTH_SCREEN /2 - 379;
  int imageY = y;
  
  al_draw_bitmap(saveFile->image, imageX, imageY, 0);

  al_draw_text(saveFile->font, saveFile->font_color, name_x, name_y, 0, saveFile->name);
  al_draw_text(saveFile->smallerFont, saveFile->font_color, currentStage_x, currentStage_y, 0, "Fase:");
  al_draw_text(saveFile->smallerFont, saveFile->font_color, currentStage_x + 50, currentStage_y, 0, saveFile->stage);
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  honor_x, honor_y, 0, saveFile->honor);
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  minutes_x, minutes_y, 0, saveFile->minutes);
    
  if (atoi(saveFile->minutes) > 1) {
    int text_width = al_get_text_width(saveFile->smallerFont, saveFile->minutes);
    minutes_x += text_width;
    al_draw_text(saveFile->smallerFont, saveFile->font_color, minutes_x + 5, minutes_y, 0, "S");
  }

  return isMouseOverBox(GAME_INFO->mouse_state, x - 180, y, width + 360, height);
}
