#include <allegro5/allegro_primitives.h>
#include "headers/stage_5-screen.h"
#include "headers/protagonista.h"
#include "headers/enemies.h"
#include "headers/itens.h"
#include <allegro5/allegro_image.h>
#include "headers/components.h"
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_5;

void setupStage_5 () {
  bg_stage_5 = al_load_bitmap("assets/images/background/bg_stage_5.jpg");
}

void destroyStage_5 () {
  al_destroy_bitmap(bg_stage_5);
}

void setupFrame1Stage5() {
  setupEnemies(2);
  setupAmmoBoxes(1);
}

void setupFrame2Stage5() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(3);
  setupHealthBoxes(1);
}

void setupFrame3Stage5() {
  resetEnemies();
  resetHealthBoxes();
  setupEnemies(2);
  setupAmmoBoxes(1);
}

void setupFrame4Stage5() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(2);
}


bool drawStage_5 () {
  if (protagonista->health <= 0) {
    drawDied();
    return true;
  }

  FRAME = changeScreen(4);

  if (FRAME != LAST_FRAME) {
    LAST_FRAME = FRAME;

    switch (FRAME) {
      case 0:
        setupFrame1Stage5();
        break;
      case 3:
        setupFrame2Stage5();
        break;
      case 2:
        setupFrame3Stage5();
        break;
      case 1:
        setupFrame4Stage5();
        break;
    }
  }

  al_draw_bitmap_region(bg_stage_5, FRAME * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}