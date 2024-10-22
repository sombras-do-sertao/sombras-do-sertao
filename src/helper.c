#include "headers/helper.h"
#include <stdio.h>
#include <allegro5/allegro5.h>

int WIDTH_SCREEN = 1920;
int HEIGHT_SCREEN = 1080;

bool isMouseOverText(ALLEGRO_MOUSE_STATE *mouse_state, int text_x, int text_y, const char *text, ALLEGRO_FONT *font) {
  int text_width = al_get_text_width(font, text);
  int text_height = al_get_font_line_height(font);

  int text_left = text_x - text_width / 2;
  int text_right = text_x + text_width / 2;
  int text_top = text_y;
  int text_bottom = text_y + text_height;

  return (mouse_state->x >= text_left && mouse_state->x <= text_right && mouse_state->y >= text_top && mouse_state->y <= text_bottom);
}

bool isMouseOverBox(ALLEGRO_MOUSE_STATE *mouse_state, int box_x, int box_y, int box_width, int box_height) {
  int box_right = box_x + box_width;
  int box_bottom = box_y + box_height;

  return (mouse_state->x >= box_x && mouse_state->x <= box_right && mouse_state->y >= box_y && mouse_state->y <= box_bottom);
}

float changeScreen(struct Protagonista *protagonista, int totalStages, GameState *gamestate) {

  int stage;
  int a = 0;

  if(protagonista->stageX > WIDTH_SCREEN * 3 - (protagonista->width/3)) {
    
    stage = 3;
    if(!(protagonista->stageX > (WIDTH_SCREEN * 3 - (protagonista->width/3)) + protagonista->speed)) { // coloca o personagem na esquerda da tela antes do primeiro passo dado, se tirar o negado ele não vai andar pq vai retornar true sempre
      protagonista->x = 0;
    }
     if(protagonista->stageX >= 7680) {
        *gamestate = MAP;  // caso tenha acabado a fase, volta pro mapa
        protagonista->stageX = 0;
        protagonista->x = 0;
      } 

  } else if(protagonista->stageX > WIDTH_SCREEN * 2 - (protagonista->width/3)) {
    stage = 2;
     if(!(protagonista->stageX > (WIDTH_SCREEN * 2 - (protagonista->width/3)) + protagonista->speed)) { 
      protagonista->x = 0;
    }
  } else if(protagonista->stageX > WIDTH_SCREEN - (protagonista->width/3)) { //1837
    stage = 1;
    if(!(protagonista->stageX > (WIDTH_SCREEN - (protagonista->width/3)) + protagonista->speed)) { 
      protagonista->x = 0;
    }
  } else {
    stage = 0;
  }

  return stage;
}