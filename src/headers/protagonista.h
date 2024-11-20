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
  int health;
  int score;
  int stageX;
  int estagioAtual;
  double last_shoot;
  double last_stab;
  int bullets;
  bool is_stab;
  ALLEGRO_BITMAP *image;
  ALLEGRO_BITMAP *image_bullet;
  ALLEGRO_BITMAP *image_health;
  ALLEGRO_BITMAP *image_stab;
};

extern struct Protagonista *protagonista;

#define BULLETS_PROTAGONISTA_COUNT 3
#define SHOOT_DELAY 0.9
#define STAB_DELAY 2
extern struct BulletProtagonista bullets_protagonista[BULLETS_PROTAGONISTA_COUNT];

void setupProtagonista();
void drawProtagonista();
void moveProtagonista();

void drawBulletCount();
void setupBulletsProtagonista();
void shootProtagonista();

void stabProtagonista();

void drawHealth();

void handlerProtagonista();

#endif