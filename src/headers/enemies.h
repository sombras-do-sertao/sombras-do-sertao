#ifndef __ENEMIES_STATE__
#define __ENEMIES_STATE__

#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "helper.h"

struct Enemy {
  int x;
  int y;
  int width;
  int height;
  int speed;
  int direction;
  bool active;
  ALLEGRO_BITMAP *image;
};

struct BulletEnemy {
  int x;
  int y;
  int width;
  int height;
  int speed;
  bool active;
  ALLEGRO_BITMAP *image;
};

#define BULLETS_ENEMIES_COUNT 100
#define ENEMIES_COUNT 10

extern struct Enemy enemies[ENEMIES_COUNT];
extern struct BulletEnemy bullets_enemies[BULLETS_ENEMIES_COUNT];

void setupEnemies();

void setupBulletEnemies();

void drawEnemies();

void drawBulletEnemies();

void moveEnemies();

void handlerEnemies();

void destroyEnemies();

#endif