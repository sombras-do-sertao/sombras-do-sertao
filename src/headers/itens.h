#ifndef _ITENS_STATE_
#define _ITENS_STATE_

#include <stdbool.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>

struct AmmoBox{
  int x;
  int y;
  int width;
  int height;
  bool active;
  int quantity;
  ALLEGRO_BITMAP *image;
};

struct HealthBox {
  int x;
  int y;
  int width;
  int height;
  bool active;
  int quantity;
  ALLEGRO_BITMAP *image;
};

#define AMMO_BOXES_COUNT 3
extern struct AmmoBox ammo_boxes[AMMO_BOXES_COUNT];

void setupAmmoBoxes(int quantity);
void drawAmmoBoxes();
void resetAmmoBoxes();
void collectAmmoBox();

#define HEALTH_BOXES_COUNT 3
extern struct HealthBox health_boxes[HEALTH_BOXES_COUNT];

void setupHealthBoxes(int quantity);
void drawHealthBoxes();
void collectHealthBox();
void resetHealthBoxes();

void handlerItens();

#endif