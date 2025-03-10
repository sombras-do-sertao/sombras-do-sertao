#include <allegro5/allegro_primitives.h>
#include "headers/stage_2-screen.h"
#include "headers/protagonista.h"
#include "headers/itens.h"
#include "headers/enemies.h"
#include <allegro5/allegro_image.h>
#include "headers/components.h"
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_2;

void setupStage_2 () {
  bg_stage_2 = al_load_bitmap("assets/images/background/bg_stage_2.jpg");
}

void setupFrame1Stage2() {
  setupEnemies(2);
  setupAmmoBoxes(1);
}

void setupFrame2Stage2() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(3);
  setupHealthBoxes(1);
}

void setupFrame3Stage2() {
  resetEnemies();
  resetHealthBoxes();
  setupEnemies(2);
  setupAmmoBoxes(1);
}

void setupFrame4Stage2() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(2);
}

void destroyStage_2 () {
  al_destroy_bitmap(bg_stage_2);
}

bool drawStage_2 () {
  if (protagonista->health <= 0) {
    drawDied();
    return true;
  }

  FRAME = changeScreen(4);

  if (FRAME != LAST_FRAME) {
    LAST_FRAME = FRAME;

    switch (FRAME) {
      case 0:
        setupFrame1Stage2();
        break;
      case 3:
        setupFrame2Stage2();
        break;
      case 2:
        setupFrame3Stage2();
        break;
      case 1:
        setupFrame4Stage2();
        break;
    }
  }
  
  al_draw_bitmap_region(bg_stage_2, FRAME * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}