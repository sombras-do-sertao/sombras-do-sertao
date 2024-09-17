#include "headers/protagonista.h"
#include "headers/helper.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

struct Protagonista protagonista;

void setupProtagonista(struct Protagonista *protagonista) {
  protagonista->x = 20;
  protagonista->y = HEIGHT_SCREEN / 2;
  protagonista->width = 32;
  protagonista->height = 32;
  protagonista->speed = 4;
  protagonista->direction = 0;
  protagonista->lives = 3;
  protagonista->score = 0;
  protagonista->image = al_load_bitmap("assets/images/characters/protagonista.png");
}

void drawProtagonista(struct Protagonista *protagonista) {
  al_draw_bitmap(protagonista->image, protagonista->x, protagonista->y, 0);
}