#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "../headers/helper.h"
#include "../headers/itens.h"
#include "../headers/components.h"

ALLEGRO_BITMAP *bg_stage_1;

int last_frameStage1 = -1;

void setupStage_1 () {
  bg_stage_1 = al_load_bitmap("assets/images/background/bg_stage_1.jpg");
}

void setupFrame1Stage1() {
  setupEnemies(1);
  setupAmmoBoxes(1);
}

void setupFrame2Stage1() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(2);
  setupHealthBoxes(1);
}

void setupFrame3Stage1() {
  resetEnemies();
  resetHealthBoxes();
  setupEnemies(1);
  setupAmmoBoxes(1);
}

void setupFrame4Stage1() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(2);
}

void destroyStage_1 () {
  al_destroy_bitmap(bg_stage_1);
}

bool drawStage_1 () {
  if (protagonista->health <= 0) {
    drawDied();
    return true;
  }

  int frame = changeScreen(4);

  if (frame != last_frameStage1) {
    last_frameStage1 = frame;

    switch (frame) {
      case 0:
        setupFrame1Stage1();
        break;
      case 3:
        setupFrame2Stage1();
        break;
      case 2:
        setupFrame3Stage1();
        break;
      case 1:
        setupFrame4Stage1();
        break;
    }
  }

  al_draw_bitmap_region(bg_stage_1, frame * WIDTH_SCREEN, 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}