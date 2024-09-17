#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "helper.h"

extern ALLEGRO_BITMAP *bg_home;
void setupHome(struct AllegroGame *game);
bool drawHome(struct AllegroGame *game, GameState *gameState);

bool drawConfig(struct AllegroGame *game);
void setupButtonsConfig(struct AllegroGame *game);

extern ALLEGRO_BITMAP *bg_game;
void setupGame();
bool drawGame(struct AllegroGame *game);

#endif