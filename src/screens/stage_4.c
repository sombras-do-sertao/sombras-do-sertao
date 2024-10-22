#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_stage_4;

void setupStage_4 () {
  bg_stage_4 = al_load_bitmap("assets/images/background/bg_stage_4.jpg");
}

void destroyStage_4 () {
  al_destroy_bitmap(bg_stage_4);
}

bool drawStage_4 (struct AllegroGame *game, GameState *gameState) {
  al_draw_bitmap_region(bg_stage_4, changeScreen(&protagonista, 4, gameState) * WIDTH_SCREEN , 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista(&protagonista, game);
  handlerEnemies();

  return true;
}