#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_2;

void setupStage_2 () {
  bg_stage_2 = al_load_bitmap("assets/images/background/bg_stage_2.jpg");
}

void destroyStage_2 () {
  al_destroy_bitmap(bg_stage_2);
}

bool drawStage_2 (struct AllegroGame *game) {
  al_draw_bitmap(bg_stage_2, 0, 0, 0);
  
  handlerProtagonista(&protagonista, game);

  return true;
}