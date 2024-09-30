#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_5;

void setupStage_5 () {
  bg_stage_5 = al_load_bitmap("assets/images/background/bg_stage_5.jpg");
}

void destroyStage_5 () {
  al_destroy_bitmap(bg_stage_5);
}

bool drawStage_5 (struct AllegroGame *game) {
  al_draw_bitmap(bg_stage_5, 0, 0, 0);
  
  handlerProtagonista(&protagonista, game);

  return true;
}