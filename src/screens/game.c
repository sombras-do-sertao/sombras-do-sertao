#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_game;

void setupGame () {
  bg_game = al_load_bitmap("assets/images/background/bg_temp.jpg");
}

bool drawGame (struct AllegroGame *game) {
  al_draw_bitmap(bg_game, 0, 0, 0);
  
  handlerProtagonista(&protagonista, game);

  return true;
}