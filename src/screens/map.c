#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <math.h>

ALLEGRO_BITMAP *bg_map;

void setupMap() {
  bg_map = al_load_bitmap("assets/images/background/bg_map.jpg");
}

struct MapProtagonista mapProtagonista;

void setupMapProtagonista (struct MapProtagonista *mapProtagonista) {
  mapProtagonista->x = 147;
  mapProtagonista->y = 327;
  mapProtagonista->stage = 0;
  mapProtagonista->image = al_load_bitmap("assets/images/characters/map_protagonista.png");
}

void destroyMap() {
  al_destroy_bitmap(bg_map);
}

void passFrame(struct MapProtagonista *mapProtagonista) {
  al_rest(0.0001);
  al_draw_bitmap(bg_map, 0, 0, 0);
  drawMapProtagonista(mapProtagonista);
  al_flip_display();
}

void protagonistaMovement(int finalX, int finalY, struct MapProtagonista *mapProtagonista) {
  int x = finalX - mapProtagonista->x;
  float y = finalY - mapProtagonista->y; 

  if (x == 0 && y == 0) return; // No movement needed

  float m = (x != 0) ? y / x : 0; // Coeficiente angular

  if (fabs(m) < 1e-6 || x == 0) { // Comparação aproximada para zero
    if (finalX > mapProtagonista->x) { // Deslocamento positivo no eixo x
      for (int i = 0; i < x; i++) {
        mapProtagonista->x++;
        passFrame(mapProtagonista);
      } 
  } else if (finalX < mapProtagonista->x) { // Deslocamento negativo no eixo x
      for (int i = 0; i > x; i--) {
        mapProtagonista->x--;
        passFrame(mapProtagonista);
      }
  } else if (finalY > mapProtagonista->y) { // Deslocamento positivo no eixo y
      for (int i = 0; i < y; i++) {
        mapProtagonista->y++;
        passFrame(mapProtagonista);
      }
  } else if (finalY < mapProtagonista->y) { // Deslocamento negativo no eixo y
      for (int i = 0; i > y; i--) {
        mapProtagonista->y--;
        passFrame(mapProtagonista);
      }
  }
} else if (m > 0) { // Função linear crescente
  if (finalX > mapProtagonista->x && finalY > mapProtagonista->y) { // Deslocamento positivo
      for (int i = 0; i < x; i++) {
        mapProtagonista->x++;
        mapProtagonista->y += m;
        passFrame(mapProtagonista);
      }  
  } else if (finalX < mapProtagonista->x && finalY < mapProtagonista->y) { // Deslocamento negativo
      for (int i = 0; i > x; i--) {
        mapProtagonista->x--;
        mapProtagonista->y -= m;
        passFrame(mapProtagonista);
      }
  }
} else if (m < 0) { // Função linear decrescente
  if (finalX > mapProtagonista->x && finalY < mapProtagonista->y) { // Deslocamento positivo
      for (int i = 0; i < x; i++) {
        mapProtagonista->x++;
        mapProtagonista->y += m;
        passFrame(mapProtagonista);
      }  
  } else if (finalX < mapProtagonista->x && finalY > mapProtagonista->y) { // Deslocamento negativo
      for (int i = 0; i > x; i--) {
        mapProtagonista->x--;
        mapProtagonista->y -= m;
        passFrame(mapProtagonista);
      }
    }
  }
}

void protagonistaMapMovement(struct AllegroGame *game, GameState *gameState, struct MapProtagonista *mapProtagonista) {
  int keycode = game->event.keyboard.keycode;

  if (keycode == ALLEGRO_KEY_ENTER) {
    switch (mapProtagonista->stage) {
      case 0:
        *gameState = STAGE_1;
        break;
      case 2:
        *gameState = STAGE_2;
        break;
      case 4:
        *gameState = STAGE_3;
        break;
      case 6:
        *gameState = STAGE_4;
        break;
      case 8:
        *gameState = STAGE_5;
        break;
    }
  }

  if (keycode == ALLEGRO_KEY_RIGHT || keycode == ALLEGRO_KEY_D) {
    printf("right: %d stage\n", mapProtagonista->stage);
    switch (mapProtagonista->stage) {
      case 0:
        protagonistaMovement(297, 327, mapProtagonista);
        protagonistaMovement(355, 500, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 1:
        protagonistaMovement(410, 690, mapProtagonista);
        protagonistaMovement(545, 690, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 2:
        protagonistaMovement(680, 690, mapProtagonista);
        protagonistaMovement(765, 475, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 3:
        protagonistaMovement(850, 260, mapProtagonista);
        protagonistaMovement(960, 260, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 4:
        protagonistaMovement(1075, 260, mapProtagonista);
        protagonistaMovement(1100, 500, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 5:
        protagonistaMovement(1330, 500, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 6:
        protagonistaMovement(1500, 500, mapProtagonista);
        protagonistaMovement(1575, 430, mapProtagonista);
        mapProtagonista->stage++;
        break;
      case 7:
        protagonistaMovement(1585, 170, mapProtagonista);
        mapProtagonista->stage++;
        break;
    }
  }

  if (keycode == ALLEGRO_KEY_LEFT || keycode == ALLEGRO_KEY_A) {
    printf("left: %d stage\n", mapProtagonista->stage);
    switch (mapProtagonista->stage) {
      case 1:
        protagonistaMovement(297, 327, mapProtagonista);
        protagonistaMovement(147, 327, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 2:
        protagonistaMovement(410, 690, mapProtagonista);
        protagonistaMovement(355, 500, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 3:
        protagonistaMovement(680, 690, mapProtagonista);
        protagonistaMovement(545, 690, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 4:
        protagonistaMovement(850, 260, mapProtagonista);
        protagonistaMovement(765, 475, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 5:
        protagonistaMovement(1075, 260, mapProtagonista);
        protagonistaMovement(960, 260, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 6:
        protagonistaMovement(1330, 500, mapProtagonista);
        protagonistaMovement(1100, 500, mapProtagonista);
        mapProtagonista->stage--;
        break;
      case 7:
        protagonistaMovement(1500, 500, mapProtagonista);
        protagonistaMovement(1330, 500, mapProtagonista);
        mapProtagonista->stage--;
        break;
    }
  }
}

void drawMapProtagonista (struct MapProtagonista *mapProtagonista) {
  al_draw_bitmap(mapProtagonista->image, mapProtagonista->x, mapProtagonista->y, 0);
}

bool drawMap(struct AllegroGame *game, GameState *gameState) {
  al_draw_bitmap(bg_map, 0, 0, 0);
  
  drawMapProtagonista(&mapProtagonista);
  protagonistaMapMovement(game, gameState, &mapProtagonista);

  return true;
}