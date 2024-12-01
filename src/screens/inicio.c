#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "../../data/dialog.h"

bool drawInicio () {
  al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, al_map_rgb(0, 0, 0));

  int y_offset = 100;
  for (int i = 0; TEXT_INICIO[i] != NULL; i++) {
    const char *line_start = TEXT_INICIO[i];
    const char *line_end = strchr(line_start, '\n');
    while (line_end != NULL) {
      char line[256];
      strncpy(line, line_start, line_end - line_start);
      line[line_end - line_start] = '\0';
      al_draw_text(GAME_INFO->font_big, AL_COLOR_WHITE, WIDTH_SCREEN / 2, y_offset, ALLEGRO_ALIGN_CENTER, line);
      y_offset += 30;
      line_start = line_end + 1;
      line_end = strchr(line_start, '\n');
    }
    if (*line_start != '\0') {
      al_draw_text(GAME_INFO->font_big, AL_COLOR_WHITE, WIDTH_SCREEN / 2, y_offset, ALLEGRO_ALIGN_CENTER, line_start);
      y_offset += 30;
    }
    y_offset += 50;
  }

  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_ENTER)) {
    GAME_INFO->state = MAP;
  }

  return true;
}