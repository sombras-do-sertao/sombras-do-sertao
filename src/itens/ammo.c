#include "../headers/itens.h"
#include "../headers/helper.h"
#include "../headers/protagonista.h"
#include "../headers/colision.h"
#include "../headers/sound.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct AmmoBox ammo_boxes[AMMO_BOXES_COUNT];

void setupAmmoBoxes(int quantity) {
  for (int i = 0; i < AMMO_BOXES_COUNT; i++) {
    if (i >= quantity) {
      ammo_boxes[i].active = false;
      continue;
    }

    ammo_boxes[i].width = 135;
    ammo_boxes[i].height = 113;
    ammo_boxes[i].x = rand() % (WIDTH_SCREEN - ammo_boxes[i].width);
    ammo_boxes[i].y = rand() % (HEIGHT_SCREEN - 756 - ammo_boxes[i].height) + 756;
    ammo_boxes[i].active = true;
    ammo_boxes[i].quantity = 3;
    ammo_boxes[i].image = al_load_bitmap("assets/images/itens/caixa-de-municao.png");
  }
}

void drawAmmoBoxes() {
  for (int i = 0; i < AMMO_BOXES_COUNT; i++) {
    if (ammo_boxes[i].active) {
      al_draw_bitmap(ammo_boxes[i].image, ammo_boxes[i].x, ammo_boxes[i].y, 0);
    }
  }
}

void resetAmmoBoxes() {
  for (int i = 0; i < AMMO_BOXES_COUNT; i++) {
    ammo_boxes[i].active = false;
  }
}

void collectAmmoBox() {
  for (int i = 0; i < AMMO_BOXES_COUNT; i++) {
    if (!ammo_boxes[i].active) continue;

    if (colision_ammoBox_in_protagonista(&ammo_boxes[i], protagonista)) {
      ammo_boxes[i].active = false;
      protagonista->bullets += ammo_boxes[i].quantity;
      playSound(PICK_ITEM);
    }
  }
}