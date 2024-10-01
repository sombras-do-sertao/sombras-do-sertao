#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_1;

void setupStage_1 () {
  bg_stage_1 = al_load_bitmap("assets/images/background/bg_stage_1.jpg");
}

void destroyStage_1 () {
  al_destroy_bitmap(bg_stage_1);
}

bool drawStage_1 (struct AllegroGame *game) {
  al_draw_bitmap(bg_stage_1, 0, 0, 0);
  
  handlerProtagonista(&protagonista, game);

  return true;
}