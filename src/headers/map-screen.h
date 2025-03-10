#ifndef MAP_SCREEN_H
#define MAP_SCREEN_H

void setupMap();
void destroyMap();
bool drawMap();

struct MapProtagonista {
  int x;
  float y;
  int stage;
  ALLEGRO_BITMAP *image;
};

extern struct MapProtagonista *MAPA_PROTAGONISTA;

void setupMapProtagonista();
void destroyMapProtagonista();
void drawMapProtagonista();
void protagonistaMapMovement();

#endif
