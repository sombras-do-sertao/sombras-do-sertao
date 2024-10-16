#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include "../headers/map_protagonista.h"
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

  handlerMapProtagonista(&mapProtagonista, game);
  
  return true;
}
  