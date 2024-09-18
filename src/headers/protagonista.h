#ifndef __HERO_STATE__
#define __HERO_STATE__

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "helper.h"
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

struct BulletProtagonista {
  int x;
  int y;
  int width;
  int height;
  int speed;
  bool active;
  ALLEGRO_BITMAP *image;
};

extern struct Protagonista protagonista;

#define BULLETS_PROTAGONISTA_COUNT 100
extern struct BulletProtagonista bullets_protagonista[BULLETS_PROTAGONISTA_COUNT];

void setupProtagonista(struct Protagonista *protagonista);
void drawProtagonista(struct Protagonista *protagonista);
void moveProtagonista(struct Protagonista *protagonista, struct AllegroGame *game);

void setupBulletsProtagonista();
void shootProtagonista(struct Protagonista *protagonista, struct AllegroGame *game);

void handlerProtagonista(struct Protagonista *protagonista, struct AllegroGame *game);

#endif