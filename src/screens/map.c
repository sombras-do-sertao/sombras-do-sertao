#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/helper.h"
#include "../headers/protagonista.h"
#include "../headers/enemies.h"
#include "../headers/dialogue_box.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

ALLEGRO_BITMAP *bg_map;
struct MapProtagonista *MAPA_PROTAGONISTA;

void setupMap() {
  bg_map = al_load_bitmap("assets/images/background/bg_map.jpg");
}

void setupMapProtagonista () {
  MAPA_PROTAGONISTA = (struct MapProtagonista *) malloc(sizeof(struct MapProtagonista));

  MAPA_PROTAGONISTA->x = 147;
  MAPA_PROTAGONISTA->y = 327;
  MAPA_PROTAGONISTA->stage = 0;
  MAPA_PROTAGONISTA->image = al_load_bitmap("assets/images/characters/map_protagonista.png");
}

void destroyMap() {
  al_destroy_bitmap(bg_map);
}

void destroyMapProtagonista() {
  al_destroy_bitmap(MAPA_PROTAGONISTA->image);
}

void passFrame() {
  al_rest(0.001);
  al_draw_bitmap(bg_map, 0, 0, 0);
  drawMapProtagonista();
  al_flip_display();
}

void protagonistaMovement(int finalX, int finalY) {
  int x = finalX - MAPA_PROTAGONISTA->x;
  float y = finalY - MAPA_PROTAGONISTA->y; 

  float m = y/x; // Coeficiente angular
  
  if (m == 0 || x == 0) { // Quando o m ou y(quando y é zero o m também é) for zero, a função é na verdade uma constante paralela ao eixo x. Quando x for zero é uma constante paralela ao eixo y
    if (finalX > MAPA_PROTAGONISTA->x) { // Caso de deslocamento positivo no eixo x
      for (int i = 0; i < x; i++) {
        MAPA_PROTAGONISTA->x++;
        passFrame();
      } 
    } 
    else if (finalX < MAPA_PROTAGONISTA->x) { // Caso de deslocamento negativo no eixo x
      for (int i = 0; i > x; i--) {
        MAPA_PROTAGONISTA->x--;
        passFrame();
      }
    }
    else if (finalY > MAPA_PROTAGONISTA->y) { // Caso de deslocamento positivo no eixo y
      for (int i = 0; i < y; i++) {
        MAPA_PROTAGONISTA->y++;
        passFrame();
      }
    }
    else if (finalY < MAPA_PROTAGONISTA->y) { // Caso de deslocamento negativo no eixo y
      for (int i = 0; i > y; i--) {
        MAPA_PROTAGONISTA->y--;
        passFrame();
      }
    }
  }
  else if (m > 0) { // É uma função linear crescente ( f(x) = x )
    if (finalX > MAPA_PROTAGONISTA->x && finalY > MAPA_PROTAGONISTA->y) { // Função linear crescente com deslocamento positivo 
      for (int i = 0; i < y/m; i++) {
        MAPA_PROTAGONISTA->x++;
        MAPA_PROTAGONISTA->y += m;
        passFrame();
      }
    } 
    else if (finalX < MAPA_PROTAGONISTA->x && finalY < MAPA_PROTAGONISTA->y) { // Função linear crescente com deslocamento negativo 
      for (int i = 0; i > y/m; i--) {
        MAPA_PROTAGONISTA->x--;
        MAPA_PROTAGONISTA->y -= m;
        passFrame();
      }
    }
  } 
  else if (m < 0) { // É uma função linear decrescente( f(x) = -x )
    if (finalX > MAPA_PROTAGONISTA->x && finalY < MAPA_PROTAGONISTA->y) { // Função linear decrescente com deslocamento positivo 
      for (int i = 0; i < y/m; i++) {
        MAPA_PROTAGONISTA->x++;
        MAPA_PROTAGONISTA->y -= m*-1;
        passFrame();
      }  
    } 
    else if (finalX < MAPA_PROTAGONISTA->x && finalY > MAPA_PROTAGONISTA->y) { // Função linear decrescente com deslocamento negativo 
      for (int i = 0; i > y/m; i--) {
        MAPA_PROTAGONISTA->x--;
        MAPA_PROTAGONISTA->y += m*-1;
        passFrame();
      }
    }
  }
}

void protagonistaMapMovement() {
  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_LEFT) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_A)) {
    if (MAPA_PROTAGONISTA->stage == 0) return;

    MAPA_PROTAGONISTA->stage--;

    switch (MAPA_PROTAGONISTA->stage) {
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
    case 8:
      protagonistaMovement(1589, 928);
      protagonistaMovement(1589, 169);
      break;
    default:
      break;
    }
  } else if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_RIGHT) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_D)) {
    if (MAPA_PROTAGONISTA->stage == 9) return;

    MAPA_PROTAGONISTA->stage++;

    switch (MAPA_PROTAGONISTA->stage) {
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
      case 9:
        protagonistaMovement(1589, 928);
        protagonistaMovement(1619, 928);
        break;
      default:
        break;
    }
  } else if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_ENTER)) {
    switch (MAPA_PROTAGONISTA->stage) {
    case 0:
      setupProtagonista();
      GAME_INFO->state = STAGE_1;
      break;
    case 2:
      setupProtagonista();
      GAME_INFO->state = STAGE_2;
      break;
    case 4:
      setupProtagonista();
      GAME_INFO->state = STAGE_3;
      break;
    case 5: // Caixa de dialogo extra do stage 5
      drawDialogueBox(10);
      break;
    case 6:
      setupProtagonista();
      GAME_INFO->state = STAGE_4;
      break;
    case 8:     
      setupProtagonista();
      GAME_INFO->state = STAGE_5;
      break;
    case 9: // Caixa de dialogo extra do stage 9
      drawDialogueBox(18);
      break;
    default:
      break;  
    }
  } else if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_SPACE) && MAPA_PROTAGONISTA->stage == 0) { // Caixa de dialogo extra do stage 0
    drawDialogueBox(14);
  }
}

void positionProtagonistaMap() {
  switch (MAPA_PROTAGONISTA->stage) {
  case 0:
    MAPA_PROTAGONISTA->x = 147;
    MAPA_PROTAGONISTA->y = 327;
    break;
  case 1:
    MAPA_PROTAGONISTA->x = 353;
    MAPA_PROTAGONISTA->y = 495;
    break;
  case 2:
    MAPA_PROTAGONISTA->x = 550;
    MAPA_PROTAGONISTA->y = 694;
    break;
  case 3:
    MAPA_PROTAGONISTA->x = 771;
    MAPA_PROTAGONISTA->y = 475;
    break;
  case 4:
    MAPA_PROTAGONISTA->x = 962;
    MAPA_PROTAGONISTA->y = 269;
    break;
  case 5:
    MAPA_PROTAGONISTA->x = 1096;
    MAPA_PROTAGONISTA->y = 505;
    break;
  case 6:
    MAPA_PROTAGONISTA->x = 1329;
    MAPA_PROTAGONISTA->y = 505;
    break;
  case 7:
    MAPA_PROTAGONISTA->x = 1571;
    MAPA_PROTAGONISTA->y = 436;
    break;
  case 8:
    MAPA_PROTAGONISTA->x = 1589;
    MAPA_PROTAGONISTA->y = 169;
    break;
  case 9:
    MAPA_PROTAGONISTA->x = 1619;
    MAPA_PROTAGONISTA->y = 928; 
    break;
  default:
    break;
  }
}

void drawMapProtagonista () {
  al_draw_bitmap(MAPA_PROTAGONISTA->image, MAPA_PROTAGONISTA->x, MAPA_PROTAGONISTA->y, 0);
}

bool drawMap() {
  al_draw_bitmap(bg_map, 0, 0, 0);
  drawMapProtagonista();
  drawDialogueBox(MAPA_PROTAGONISTA->stage);
  protagonistaMapMovement();
  positionProtagonistaMap();
  return true;
}