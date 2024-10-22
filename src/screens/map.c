#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

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
  al_rest(0.001);
  drawMapProtagonista(mapProtagonista);
  al_flip_display();
}

void protagonistaMovement(int finalX, int finalY, struct MapProtagonista *mapProtagonista) {
  int x = finalX - mapProtagonista->x;
  float y = finalY - mapProtagonista->y; 

  float m = y/x; // Coeficiente angular
  
  if (m == 0 || x == 0) { // Quando o m ou y(quando y é zero o m também é) for zero, a função é na verdade uma constante paralela ao eixo x. Quando x for zero é uma constante paralela ao eixo y
    if (finalX > mapProtagonista->x) { // Caso de deslocamento positivo no eixo x
      for (int i = 0; i < x; i++) {
        mapProtagonista->x++;
        passFrame(mapProtagonista);
      } 
    } 
    else if (finalX < mapProtagonista->x) { // Caso de deslocamento negativo no eixo x
      for (int i = 0; i > x; i--) {
        mapProtagonista->x--;
        passFrame(mapProtagonista);
      }
    }
    else if (finalY > mapProtagonista->y) { // Caso de deslocamento positivo no eixo y
      for (int i = 0; i < y; i++) {
        mapProtagonista->y++;
        passFrame(mapProtagonista);
      }
    }
    else if (finalY < mapProtagonista->y) { // Caso de deslocamento negativo no eixo y
      for (int i = 0; i > y; i--) {
        mapProtagonista->y--;
        passFrame(mapProtagonista);
      }
    }
  }
  else if (m > 0) { // É uma função linear crescente ( f(x) = x )
    if (finalX > mapProtagonista->x && finalY > mapProtagonista->y) { // Função linear crescente com deslocamento positivo 
      for (int i = 0; i < y/m; i++) {
        mapProtagonista->x++;
        mapProtagonista->y += m;
        passFrame(mapProtagonista);
      }  
    } 
    else if (finalX < mapProtagonista->x && finalY < mapProtagonista->y) { // Função linear crescente com deslocamento negativo 
      for (int i = 0; i > y/m; i--) {
        mapProtagonista->x--;
        mapProtagonista->y -= m;
        passFrame(mapProtagonista);
      }
    }
  } 
  else if (m < 0) { // É uma função linear decrescente( f(x) = -x )
    if (finalX > mapProtagonista->x && finalY > mapProtagonista->y) { // Função linear decrescente com deslocamento positivo 
      for (int i = 0; i < y/m; i++) {
        mapProtagonista->x++;
        mapProtagonista->y -= m;
        passFrame(mapProtagonista);
      }  
    } 
    else if (finalX < mapProtagonista->x && finalY < mapProtagonista->y) { // Função linear decrescente com deslocamento negativo 
      for (int i = 0; i > y/m; i--) {
        mapProtagonista->x--;
        mapProtagonista->y += m;
        passFrame(mapProtagonista);
      }
    }
  }
}

void protagonistaMapMovement(struct AllegroGame *game, GameState *gameState, struct MapProtagonista *mapProtagonista) {
  int keycode = game->event.keyboard.keycode;
  
  
}

void drawMapProtagonista (struct MapProtagonista *mapProtagonista) {
  al_draw_bitmap(mapProtagonista->image, mapProtagonista->x, mapProtagonista->y, 0);
}

bool drawMap(struct AllegroGame *game, GameState *gameState) {
  al_draw_bitmap(bg_map, 0, 0, 0);

  return true;
}