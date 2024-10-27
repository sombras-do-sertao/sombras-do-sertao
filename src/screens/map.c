#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_map;
struct MapProtagonista *mapProtagonista;

void setupMap() {
  bg_map = al_load_bitmap("assets/images/background/bg_map.jpg");
}

void setupMapProtagonista () {
  mapProtagonista = (struct MapProtagonista *) malloc(sizeof(struct MapProtagonista));

  mapProtagonista->x = 147;
  mapProtagonista->y = 327;
  mapProtagonista->stage = 0;
  mapProtagonista->image = al_load_bitmap("assets/images/characters/map_protagonista.png");
}

void destroyMap() {
  al_destroy_bitmap(bg_map);
}

void destroyMapProtagonista() {
  al_destroy_bitmap(mapProtagonista->image);
}

void passFrame() {
  al_rest(0.001);
  al_draw_bitmap(bg_map, 0, 0, 0);
  drawMapProtagonista(mapProtagonista);
  al_flip_display();
}

void protagonistaMovement(int finalX, int finalY) {
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
    if (finalX > mapProtagonista->x && finalY < mapProtagonista->y) { // Função linear decrescente com deslocamento positivo 
      for (int i = 0; i < y/m; i++) {
        mapProtagonista->x++;
        mapProtagonista->y -= m*-1;
        passFrame(mapProtagonista);
      }  
    } 
    else if (finalX < mapProtagonista->x && finalY > mapProtagonista->y) { // Função linear decrescente com deslocamento negativo 
      for (int i = 0; i > y/m; i--) {
        mapProtagonista->x--;
        mapProtagonista->y += m*-1;
        passFrame(mapProtagonista);
      }
    }
  }
}

void protagonistaMapMovement() {
  int keycode = GAME_INFO->event.keyboard.keycode;

  switch (keycode) {
  case ALLEGRO_KEY_LEFT:
  case ALLEGRO_KEY_A:
    
    if (mapProtagonista->stage == 0) return;

    mapProtagonista->stage--;

    switch (mapProtagonista->stage) {
    case 0:
      protagonistaMovement(297, 327);
      protagonistaMovement(147, 327);
      break;
    case 1:
      protagonistaMovement(419, 694);
      protagonistaMovement(353, 495);
      break;
    case 2:
      protagonistaMovement(676, 694);
      protagonistaMovement(550, 694);
      break;
    case 3:
      protagonistaMovement(861, 269);
      protagonistaMovement(771, 475);
      break; 
    case 4:
      protagonistaMovement(1074, 269);
      protagonistaMovement(962, 269);    
      break;
    case 5:
      protagonistaMovement(1096, 505);
      break;
    case 6:
      protagonistaMovement(1555, 476);
      protagonistaMovement(1504, 505);
      protagonistaMovement(1329, 505);
      break;
    case 7:
      protagonistaMovement(1589, 392);
      protagonistaMovement(1571, 436);
      break;
    default:
      break;
    }
    break;
  case ALLEGRO_KEY_RIGHT:
  case ALLEGRO_KEY_D:

    if (mapProtagonista->stage == 8) return;

    mapProtagonista->stage++;
 
    switch (mapProtagonista->stage) {
    case 1:
      protagonistaMovement(297, 327);
      protagonistaMovement(353, 495);
      break;
    case 2:
      protagonistaMovement(419, 694);
      protagonistaMovement(550, 694);
      break;
    case 3:
      protagonistaMovement(676, 694);
      protagonistaMovement(771, 475);
      break;
    case 4:
      protagonistaMovement(861, 269);
      protagonistaMovement(962, 269);
      break;
    case 5:
      protagonistaMovement(1074, 269);
      protagonistaMovement(1096, 505);
      break;
    case 6:
      protagonistaMovement(1329, 505);
      break;
    case 7:
      protagonistaMovement(1504, 505);
      protagonistaMovement(1555, 476);
      protagonistaMovement(1571, 436);
      break;
    case 8:
      protagonistaMovement(1589, 392);
      protagonistaMovement(1589, 169);
      break;
    default:
      break;
    } 
    break;
  case ALLEGRO_KEY_ENTER:
    switch (mapProtagonista->stage) {
    case 0:
      setupProtagonista();
      setupEnemies(); 
      GAME_INFO->state = STAGE_1;
      break;
    case 2:
      setupProtagonista();
      setupEnemies(); 
      GAME_INFO->state = STAGE_2;
      break;
    case 4:
      setupProtagonista();
      setupEnemies(); 
      GAME_INFO->state = STAGE_3;
      break;
    case 6:
      setupProtagonista();
      setupEnemies(); 
      GAME_INFO->state = STAGE_4;
      break;
    case 8:     
      setupProtagonista();
      setupEnemies(); 
      GAME_INFO->state = STAGE_5;
      break;
    default:
      break;  
    }
    break;
  default:
    break;
  }
}

void drawMapProtagonista () {
  al_draw_bitmap(mapProtagonista->image, mapProtagonista->x, mapProtagonista->y, 0);
}

bool drawMap() {
  al_draw_bitmap(bg_map, 0, 0, 0);
  drawMapProtagonista();
  protagonistaMapMovement();

  return true;
}