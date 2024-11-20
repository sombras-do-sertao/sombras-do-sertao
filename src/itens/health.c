#include "../headers/itens.h"
#include "../headers/helper.h"
#include "../headers/protagonista.h"
#include "../headers/colision.h"
#include "../headers/sound.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

struct HealthBox health_boxes[HEALTH_BOXES_COUNT];

void setupHealthBoxes(int quantity) {
  for (int i = 0; i < HEALTH_BOXES_COUNT; i++) {
    if (i >= quantity) {
      health_boxes[i].active = false;
      continue;
    }

    health_boxes[i].width = 192;
    health_boxes[i].height = 114;
    health_boxes[i].x = rand() % (WIDTH_SCREEN - health_boxes[i].width / 2) + health_boxes[i].width / 2;
    health_boxes[i].y = rand() % (HEIGHT_SCREEN - 756) + 756 - health_boxes[i].height / 2;
    health_boxes[i].active = true;
    health_boxes[i].quantity = 3;
    health_boxes[i].image = al_load_bitmap("assets/images/itens/kit-medico.png");
  }
}

void drawHealthBoxes() {
  for (int i = 0; i < HEALTH_BOXES_COUNT; i++) {
    if (health_boxes[i].active) {
      al_draw_bitmap(health_boxes[i].image, health_boxes[i].x, health_boxes[i].y, 0);
    }
  }
}

void resetHealthBoxes() {
  for (int i = 0; i < HEALTH_BOXES_COUNT; i++) {
    health_boxes[i].active = false;
    al_destroy_bitmap(health_boxes[i].image);
  }
}

void collectHealthBox() {
  for (int i = 0; i < HEALTH_BOXES_COUNT; i++) {
    if (!health_boxes[i].active) continue;

    if (colision_healthBox_in_protagonista(&health_boxes[i], protagonista)) {
      health_boxes[i].active = false;
      protagonista->health += health_boxes[i].quantity;
      
      if (protagonista->health > 5) protagonista->health = 5;
      
      playSound(PICK_ITEM);
    }
  }
}