#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_map;
void setupMap() {
  bg_map = al_load_bitmap("assets/images/background/bg_map.jpg");
}

void destroyMap() {
  al_destroy_bitmap(bg_map);
}

bool drawMap(struct AllegroGame *game, GameState *gameState) {
  al_draw_bitmap(bg_map, 0, 0, 0);

  switch(game->event.keyboard.keycode) {
    case ALLEGRO_KEY_1:
      *gameState = STAGE_1;
      break;
    case ALLEGRO_KEY_2:
      *gameState = STAGE_2;
      break;
    case ALLEGRO_KEY_3:
      *gameState = STAGE_3;
      break;
    case ALLEGRO_KEY_4:
      *gameState = STAGE_4;
      break;
    case ALLEGRO_KEY_5:
      *gameState = STAGE_5;
      break;
    case EXIT:
      return false;
      break;
  }
  return true;
}