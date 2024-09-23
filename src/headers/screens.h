#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "helper.h"

extern ALLEGRO_BITMAP *bg_home;
void setupHome(struct AllegroGame *game);
void destroyHome(void);
bool drawHome(struct AllegroGame *game, GameState *gameState);

bool drawConfig(struct AllegroGame *game);
void destroyConfig(void);
void setupButtonsConfig(struct AllegroGame *game);

extern ALLEGRO_BITMAP *bg_game;
void setupGame();
void destroyGame();
bool drawGame(struct AllegroGame *game);

#endif