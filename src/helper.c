#include "headers/helper.h"
#include <stdio.h>
#include <allegro5/allegro5.h>

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
