#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "../headers/screens.h"
#include "../headers/components.h"

struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

void setupSaves(){
  fontSettings = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  saveBackground = al_load_bitmap("assets/images/background/save.jpg", 0,0)

}

bool drawSaves(struct AllegroGame *game, GameState *gameState) {

}

void destroySaves(void) {

}

ALLEGRO_FONT *fontSettings;
