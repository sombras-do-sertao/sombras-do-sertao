#include "headers/helper.h"
#include "headers/save.h"
#include "headers/components.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
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

  int seconds_x = honor_x + 180;
  int seconds_y = honor_y;
  
  int imageX = WIDTH_SCREEN /2 - 379;
  int imageY = y;
  
  al_draw_bitmap(saveFile->image, imageX, imageY, 0);

  al_draw_text(saveFile->font, saveFile->font_color, name_x, name_y, 0, saveFile->name);
  al_draw_text(saveFile->smallerFont, saveFile->font_color, currentStage_x, currentStage_y, 0, "Fase:");
  al_draw_text(saveFile->smallerFont, saveFile->font_color, currentStage_x + 50, currentStage_y, 0, saveFile->stage);
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  honor_x, honor_y, 0, saveFile->honor);
  al_draw_text(saveFile->smallerFont, saveFile->font_color,  seconds_x, seconds_y, 0, saveFile->seconds);
    
  if (atoi(saveFile->seconds) > 1) {
    int text_width = al_get_text_width(saveFile->smallerFont, saveFile->seconds);
    seconds_x += text_width;
    al_draw_text(saveFile->smallerFont, saveFile->font_color, seconds_x + 5, seconds_y, 0, "S");
  }

  return isMouseOverBox(GAME_INFO->mouse_state, x - 180, y, width + 360, height);
}

ALLEGRO_BITMAP *skull;

void setupDied() {
  skull = al_load_bitmap("assets/images/addons/caveira.png");
}

void drawDied() {
  al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, AL_COLOR_BLACK);

  al_draw_bitmap(skull, WIDTH_SCREEN / 2 - 220, HEIGHT_SCREEN / 2 - 50, 0);
  al_draw_bitmap(skull, WIDTH_SCREEN / 2 + 120, HEIGHT_SCREEN / 2 - 50, 0);
  al_draw_text(GAME_INFO->font_big, AL_COLOR_WHITE, WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2, ALLEGRO_ALIGN_CENTER, "Você morreu, Cangaceiro!");
  al_draw_text(GAME_INFO->font_small, AL_COLOR_WHITE, WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2 + 50, ALLEGRO_ALIGN_CENTER, "Pressione ESC tecla para voltar...");
}

bool drawButton(struct Button *button) {
  int text_width = al_get_text_width(button->font, button->text);
  int text_height = al_get_font_line_height(button->font);

  int text_x = button->x + button->width / 2;
  int text_y = button->y + button->height / 2 - text_height / 2;

  if (button->type == FILLED) {
    al_draw_filled_rectangle(button->x, button->y, button->x + button->width, button->y + button->height, button->background_color);
    al_draw_text(button->font, button->font_color, text_x, text_y, ALLEGRO_ALIGN_CENTRE, button->text);
  } else {
    al_draw_rectangle(button->x, button->y, button->x + button->width, button->y + button->height, button->background_color, 2);
    al_draw_text(button->font, button->font_color, text_x, text_y, ALLEGRO_ALIGN_CENTRE, button->text);
  }

  return isMouseOverBox(GAME_INFO->mouse_state, button->x, button->y, button->width, button->height);
}