#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include "../headers/itens.h"
#include <allegro5/allegro_image.h>
#include "../headers/components.h"
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_4;
int last_frameStage4 = -1;

void setupStage_4 () {
  bg_stage_4 = al_load_bitmap("assets/images/background/bg_stage_4.jpg");
}

void destroyStage_4 () {
  al_destroy_bitmap(bg_stage_4);
}

void setupFrame1Stage4() {
  setupEnemies(2);
}

void setupFrame2Stage4() {
  resetEnemies();
  setupEnemies(3);
  setupAmmoBoxes(1);
}

void setupFrame3Stage4() {
  resetEnemies();
  resetAmmoBoxes();
  setupEnemies(3);
  setupAmmoBoxes(1);
  setupHealthBoxes(1);
}

void setupFrame4Stage4() {
  resetEnemies();
  resetAmmoBoxes();
  resetHealthBoxes();
  setupEnemies(3);
}

bool drawStage_4 () {
  if (protagonista->health <= 0) {
    drawDied();
    return true;
  }

  int frame = changeScreen(4);

  if (frame != last_frameStage4) {
    last_frameStage4 = frame;

    switch (frame) {
      case 0:
        setupFrame1Stage4();
        break;
      case 3:
        setupFrame2Stage4();
        break;
      case 2:
        setupFrame3Stage4();
        break;
      case 1:
        setupFrame4Stage4();
        break;
    }
  }

  al_draw_bitmap_region(bg_stage_4, changeScreen(4) * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}