#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_primitives.h>

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