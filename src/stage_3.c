#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "headers/stage_3-screen.h"
#include "headers/protagonista.h"
#include "headers/enemies.h"
#include "headers/components.h"
#include "headers/itens.h"
#include "headers/helper.h"
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_3;

void setupStage_3 () {
  bg_stage_3 = al_load_bitmap("assets/images/background/bg_stage_3.jpg");
}

void setupFrame1Stage3() {
  setupEnemies(3);
}

void setupFrame2Stage3() {
  resetEnemies();
  setupEnemies(3);
  setupHealthBoxes(1);
  setupAmmoBoxes(1);
}

void setupFrame3Stage3() {
  resetEnemies();
  resetHealthBoxes();
  resetAmmoBoxes();
  setupEnemies(3);
  setupAmmoBoxes(1);
}

void setupFrame4Stage3() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(3);
  setupHealthBoxes(1);
}

void destroyStage_3 () {
  al_destroy_bitmap(bg_stage_3);
}

bool drawStage_3 () {
  if (protagonista->health <= 0) {
    drawDied();
    return true;
  }

  FRAME = changeScreen(4);

  if (FRAME != LAST_FRAME) {
    LAST_FRAME = FRAME;

    switch (FRAME) {
      case 0:
        setupFrame1Stage3();
        break;
      case 3:
        setupFrame2Stage3();
        break;
      case 2:
        setupFrame3Stage3();
        break;
      case 1:
        setupFrame4Stage3();
        break;
    }
  }

  al_draw_bitmap_region(bg_stage_3, FRAME * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}