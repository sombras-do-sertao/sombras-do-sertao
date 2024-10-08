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

/*
frames_tela [tela1, tela2...]

frame a renderizar = null

if (jogador metade corpo dele > tela1 * 1920) {
 frame a renderizar = tela2
}*/

bool drawStage_1 (struct AllegroGame *game) {
   //função de desenhar o estágio do mapa pela posição do personagem
  float window_frame[4] = {0, 1, 2, 3};
  float window_size = 1920;
  int frame = 0;

  if(protagonista.x > window_size - (protagonista.width/3)) {
    frame = 1;
  } 
  al_draw_bitmap_region(bg_stage_1, window_frame[frame] * window_size , 0, window_size, 1080, 0, 0, 0);
  

  handlerProtagonista(&protagonista, game);

  return true;
}