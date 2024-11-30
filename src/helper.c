#include "headers/helper.h"
#include "headers/protagonista.h"
#include "headers/screens.h"
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

float changeScreen(int totalStages) {
  int stage;
  int a = 0;

  int screen_thresholds[] = {WIDTH_SCREEN * 3, WIDTH_SCREEN * 2, WIDTH_SCREEN};
  stage = 0;

  for (int i = 0; i < 3; i++) {
    if (protagonista->stageX > screen_thresholds[i] - (protagonista->width / 3)) {
      stage = i + 1;
      if (!(protagonista->stageX > (screen_thresholds[i] - (protagonista->width / 3)) + protagonista->speed)) {
        protagonista->x = 0;
      }

      if(protagonista->stageX < (screen_thresholds[i] - (protagonista->width / 3)) ) {
        protagonista->stageX += protagonista->speed;
      }

      break;
    }
  }

  if (protagonista->stageX >= 7680) {
    GAME_INFO->state = MAP;
    GAME_INFO->save->stage += 1;

    protagonista->stageX = 0;
    protagonista->x = 0;

    float timer_interval = al_get_timer_speed(GAME_INFO->timer);
    float elapsed_seconds = al_get_timer_count(GAME_INFO->timer) * timer_interval;
    GAME_INFO->save->seconds += elapsed_seconds;
  }

  return stage;
}