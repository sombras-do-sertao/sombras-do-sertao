#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "helper.h"

void setupButtonsHome(struct AllegroGame *game);
bool drawHome(struct AllegroGame *game, GameState *gameState);

bool drawConfig(struct AllegroGame *game);
void setupButtonsConfig(struct AllegroGame *game);

bool drawGame(struct AllegroGame *game);

#endif