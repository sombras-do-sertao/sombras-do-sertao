#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_5;

void setupStage_5 () {
  bg_stage_5 = al_load_bitmap("assets/images/background/bg_stage_5.jpg");
}

void destroyStage_5 () {
  al_destroy_bitmap(bg_stage_5);
}

bool drawStage_5 () {
  al_draw_bitmap_region(bg_stage_5, changeScreen(4) * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();

  return true;
}