#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/itens.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_2;
int last_frameStage2 = -1;

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
  int frame = changeScreen(4);

  if (frame != last_frameStage2) {
    last_frameStage2 = frame;

    switch (frame) {
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
  
  al_draw_bitmap_region(bg_stage_2, frame * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();
  handlerItens();

  return true;
}