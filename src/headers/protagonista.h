#ifndef __HERO_STATE__
#define __HERO_STATE__

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "helper.h"

struct BulletProtagonista {
  int x;
  int y;
  int width;
  int height;
  int speed;
  int direction;
  bool active;
  ALLEGRO_BITMAP *image;
};

struct Protagonista {
  int x;
  int y;
  int width;
  int height;
  int speed;
  int direction;
  int lives;
  int score;
  int stageX;
  int estagioAtual;
  double last_shoot;
  int bullets;
  ALLEGRO_BITMAP *image;
  ALLEGRO_BITMAP *image_bullet;
};

extern struct Protagonista *protagonista;

#define BULLETS_PROTAGONISTA_COUNT 3
#define SHOOT_DELAY 0.9
extern struct BulletProtagonista bullets_protagonista[BULLETS_PROTAGONISTA_COUNT];

void setupProtagonista();
void drawProtagonista();
void moveProtagonista();

void drawBulletCount(int bullets);
void setupBulletsProtagonista();
void shootProtagonista();

void handlerProtagonista();

#endif