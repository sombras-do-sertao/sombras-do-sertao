#include <allegro5/allegro_primitives.h>
#include "headers/game-screen.h"
#include "headers/protagonista.h"
#include "headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_game;

void setupGame () {
  bg_game = al_load_bitmap("assets/images/background/bg_temp.jpg");
}

void destroyGame () {
  al_destroy_bitmap(bg_game);
}

bool drawGame () {
  al_draw_bitmap(bg_game, 0, 0, 0);
  
  handlerProtagonista();
  handlerEnemies();

  return true;
}