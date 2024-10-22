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

extern ALLEGRO_BITMAP *bg_map;
void setupMap();
void destroyMap();
bool drawMap(struct AllegroGame *game, GameState *gameState);

extern struct MapProtagonista mapProtagonista;
struct MapProtagonista {
  int x;
  float y;
  int stage;
  ALLEGRO_BITMAP *image;
};
void setupMapProtagonista(struct MapProtagonista *mapProtagonista);
void destroyMapProtagonista(struct MapProtagonista *mapProtagonista);
void drawMapProtagonista(struct MapProtagonista *mapProtagonista);
void protagonistaMapMovement(struct AllegroGame *game, GameState *gameState, struct MapProtagonista *mapProtagonista);

extern ALLEGRO_BITMAP *bg_stage_1;
void setupStage_1();
void destroyStage_1();
bool drawStage_1(struct AllegroGame *game, GameState *gameState);

extern ALLEGRO_BITMAP *bg_stage_2;
void setupStage_2();
void destroyStage_2();
bool drawStage_2(struct AllegroGame *game, GameState *gameState);

extern ALLEGRO_BITMAP *bg_stage_3;
void setupStage_3();
void destroyStage_3();
bool drawStage_3(struct AllegroGame *game, GameState *gameState);

extern ALLEGRO_BITMAP *bg_stage_4;
void setupStage_4();
void destroyStage_4();
bool drawStage_4(struct AllegroGame *game, GameState *gameState);

extern ALLEGRO_BITMAP *bg_stage_5;
void setupStage_5();
void destroyStage_5();
bool drawStage_5(struct AllegroGame *game, GameState *gameState);

#endif