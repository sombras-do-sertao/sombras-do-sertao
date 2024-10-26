#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "../headers/helper.h"

ALLEGRO_BITMAP *bg_stage_1;

void setupStage_1 () {
  bg_stage_1 = al_load_bitmap("assets/images/background/bg_stage_1.jpg");
}

void destroyStage_1 () {
  al_destroy_bitmap(bg_stage_1);
}
/*duplica um x, um xDoFrame. Dentro de cada fase ele vai andar com o X e o xDoFrame, quando ele passar da metade da tela o XDoFrame é zerado
e o personagem é desenhado no xDoFrame*/


bool drawStage_1 () {
  al_draw_bitmap_region(bg_stage_1, changeScreen(&protagonista, 4) * WIDTH_SCREEN, 0, WIDTH_SCREEN, 1080, 0, 0, 0);
  
  handlerProtagonista(&protagonista);
  handlerEnemies();

  return true;
}