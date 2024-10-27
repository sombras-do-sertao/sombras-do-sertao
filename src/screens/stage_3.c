#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_3;

void setupStage_3 () {
  bg_stage_3 = al_load_bitmap("assets/images/background/bg_stage_3.jpg");
}

void destroyStage_3 () {
  al_destroy_bitmap(bg_stage_3);
}

bool drawStage_3 () {
  al_draw_bitmap_region(bg_stage_3, changeScreen(4) * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();

  return true;
}