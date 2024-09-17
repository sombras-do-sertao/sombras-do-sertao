#ifndef __HERO_STATE__
#define __HERO_STATE__

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

struct Protagonista {
  int x;
  int y;
  int width;
  int height;
  int speed;
  int direction;
  int lives;
  int score;
  ALLEGRO_BITMAP *image;
};

extern struct Protagonista protagonista;

void setupProtagonista(struct Protagonista *protagonista);

void drawProtagonista(struct Protagonista *protagonista);

#endif