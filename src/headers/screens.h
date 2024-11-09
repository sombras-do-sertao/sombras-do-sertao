#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include "helper.h"

extern ALLEGRO_BITMAP *bg_home;
void setupHome();
void destroyHome(void);
bool drawHome();

bool drawConfig();
void destroyConfig(void);
void setupButtonsConfig();

extern ALLEGRO_BITMAP *bg_game;
void setupGame();
void destroyGame();
bool drawGame();

extern ALLEGRO_BITMAP *bg_map;
void setupMap();
void destroyMap();
bool drawMap();

extern struct MapProtagonista *MAPA_PROTAGONISTA;

struct MapProtagonista {
  int x;
  float y;
  int stage;
  ALLEGRO_BITMAP *image;
};

void setupMapProtagonista();
void destroyMapProtagonista();
void drawMapProtagonista();
void protagonistaMapMovement();

extern ALLEGRO_BITMAP *bg_stage_1;
void setupStage_1();
void destroyStage_1();
bool drawStage_1();

extern ALLEGRO_BITMAP *bg_stage_2;
void setupStage_2();
void destroyStage_2();
bool drawStage_2();

extern ALLEGRO_BITMAP *bg_stage_3;
void setupStage_3();
void destroyStage_3();
bool drawStage_3();

extern ALLEGRO_BITMAP *bg_stage_4;
void setupStage_4();
void destroyStage_4();
bool drawStage_4();

extern ALLEGRO_BITMAP *bg_stage_5;
void setupStage_5();
void destroyStage_5();
bool drawStage_5();

extern ALLEGRO_BITMAP *fileBackground;
void setupSaves();
void destroySaves();
bool drawSaves();

#endif