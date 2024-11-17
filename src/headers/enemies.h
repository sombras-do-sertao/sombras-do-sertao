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
  int last_shoot;
  int time_to_shoot;
  ALLEGRO_BITMAP *image;
};

struct BulletEnemy {
  int x;
  int y;
  int width;
  int height;
  int speed;
  bool active;
  int direction;
  ALLEGRO_BITMAP *image;
};

#define BULLETS_ENEMIES_COUNT 10
#define ENEMIES_COUNT 5

extern struct Enemy enemies[ENEMIES_COUNT];
extern struct BulletEnemy bullets_enemies[BULLETS_ENEMIES_COUNT];

void setupEnemies(int quantity);

void drawEnemie(struct Enemy *enemie);

void drawBulletEnemies();

void moveEnemie(struct Enemy *enemie);

void shootBulletEnemy(struct Enemy *enemie);

void handlerEnemies();

void resetEnemies();

void destroyEnemies();

#endif