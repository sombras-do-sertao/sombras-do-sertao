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
  protagonista->speed = 20;
  protagonista->direction = 1;
  protagonista->lives = 3;
  protagonista->score = 0;
  protagonista->image = al_load_bitmap("assets/images/characters/protagonista.png");
}

void drawProtagonista(struct Protagonista *protagonista) {
  al_draw_bitmap(protagonista->image, protagonista->x, protagonista->y, 0);
}

void moveProtagonista(struct Protagonista *protagonista, struct AllegroGame *game) {
  int keycode = game->event.keyboard.keycode;

  switch (keycode) {
    case ALLEGRO_KEY_UP:
      protagonista->y -= protagonista->speed;
      break;
    case ALLEGRO_KEY_DOWN:
      protagonista->y += protagonista->speed;
      break;
    case ALLEGRO_KEY_LEFT:
      protagonista->x -= protagonista->speed;
      break;
    case ALLEGRO_KEY_RIGHT:
      protagonista->x += protagonista->speed;
      break;
    default:
      break;
  }
}