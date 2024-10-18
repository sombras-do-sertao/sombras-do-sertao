#ifndef __HERO_MAP_MOVEMENT__
#define __HERO_MAP_MOVEMENT__

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "helper.h"

struct MapProtagonista {
  int x;
  float y;
  int stage;
  ALLEGRO_BITMAP *image;
};

extern struct MapProtagonista mapProtagonista;

void setupMapProtagonista(struct MapProtagonista *mapProtagonista);
void drawMapProtagonista(struct MapProtagonista *mapProtagonista);
void moveMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game, GameState *gameState);

void handlerMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game, GameState *gameState);

#endif