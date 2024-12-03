#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_tutorial;

void setupTutorial () {
  bg_tutorial = al_load_bitmap("assets/images/background/bg_tutorial.png");
}

void destroyTutorial () {
  al_destroy_bitmap(bg_tutorial);
}

bool drawTutorial () {
  al_draw_bitmap(bg_tutorial, 0, 0, 0);

  return true;
}