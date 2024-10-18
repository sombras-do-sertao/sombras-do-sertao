#include "headers/map_protagonista.h"
#include "headers/helper.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <unistd.h>

struct MapProtagonista mapProtagonista;

void setupMapProtagonista (struct MapProtagonista *mapProtagonista) {
  mapProtagonista->x = 147;
  mapProtagonista->y = 327;
  mapProtagonista->stage = 0;
  mapProtagonista->image = al_load_bitmap("assets/images/characters/map_protagonista.png");
}

void drawMapProtagonista(struct MapProtagonista *mapProtagonista) {
  al_draw_bitmap(mapProtagonista->image, mapProtagonista->x, mapProtagonista->y, 0);
}

void moveMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game, GameState *gameState) {
  int keycode = game->event.keyboard.keycode;

  switch (keycode) {
    case ALLEGRO_KEY_LEFT:
    case ALLEGRO_KEY_A:
      
      mapProtagonista->stage--;

      switch (mapProtagonista->stage) {
        case 0:
          for(int i = 0; i < 297-147; i++) {
            mapProtagonista->x--;
          }
          for(int i = 0; i < (495-327)/3; i++) {
            mapProtagonista->x--;
            mapProtagonista->y -= 3;
          }
          break;
        case 1:
          for (int i = 0; i < (694-495)/3; i++) {
            mapProtagonista->x--;
            mapProtagonista->y -= 3;
          }
          for(int i = 0; i < 550-419; i++) {
            mapProtagonista->x--;
          }
          break;
        case 2:
          for(int i = 0; i < 676-550; i++) {
            mapProtagonista->x--;
          }
          for(int i = 0; i < (694-475)/2.3; i++) {
            mapProtagonista->x--;
            mapProtagonista->y += 2.3;
          }
          break;
        case 3:
          for(int i = 0; i < (475-269)/2.3; i++) {
            mapProtagonista->x--;
            mapProtagonista->y += 2.3;
          }
          for(int i = 0; i < 962-861; i++) {
            mapProtagonista->x--;
          }
          break;
        case 4:
          for (int i = 0; i < 1074-962; i++) {
            mapProtagonista->x--;
          }
          for(int i = 0; i < (505-269)/7.86; i++) {
            mapProtagonista->x--;
            mapProtagonista->y -= 7.86;
          }
          break;
        case 5:
          for (int i = 0; i < 1329-1104; i++) {
            mapProtagonista->x--;
          }
          break;
        case 6:
          for(int i = 0; i < 1504-1329; i++) {
            mapProtagonista->x--;
          }
          for (int i = 0; i < (505-476)*0.56 ; i++) {
            mapProtagonista->x--;
            mapProtagonista->y += 0.56;
          }
          for (int i = 0; i < (476-436)/2; i++) {
            mapProtagonista->x--;
            mapProtagonista->y += 2.5;
          }
          break;
        case 7:
          for (int i = 0; i < (436-392)/2; i++) {
            mapProtagonista->x--;
            mapProtagonista->y += 2.5;
          }
          for (int i = 0; i < (392-169); i++) {
            mapProtagonista->y++;
          }
          break;
        case 8:

          break;
        default:
          break;
      };

      break;
    case ALLEGRO_KEY_RIGHT:
    case ALLEGRO_KEY_D:

       mapProtagonista->stage++;

      switch (mapProtagonista->stage) {
        case 1:
          for(int i = 0; i < 297-147; i++) {
            mapProtagonista->x++;
          }
          for(int i = 0; i < (495-327)/3; i++) {
            mapProtagonista->x++;
            mapProtagonista->y += 3;
          }
          break;
        case 2:
          for (int i = 0; i < (694-495)/3; i++) {
            mapProtagonista->x++;
            mapProtagonista->y += 3;
          }
          for(int i = 0; i < 550-419; i++) {
            mapProtagonista->x++;
          }
          break;
        case 3:
          for(int i = 0; i < 676-550; i++) {
            mapProtagonista->x++;
          }
          for(int i = 0; i < (694-475)/2.3; i++) {
            mapProtagonista->x++;
            mapProtagonista->y -= 2.3;
          }
          break;
        case 4:
          for(int i = 0; i < (475-269)/2.3; i++) {
            mapProtagonista->x++;
            mapProtagonista->y -= 2.3;
          }
          for(int i = 0; i < 962-861; i++) {
            mapProtagonista->x++;
          }
          break;
        case 5:
          for (int i = 0; i < 1074-962; i++) {
            mapProtagonista->x++;
          }
          for(int i = 0; i < (505-269)/7.86; i++) {
            mapProtagonista->x++;
            mapProtagonista->y += 7.86;
          }
          break;
        case 6:
          for(int i = 0; i < 1329-1096; i++) {
            mapProtagonista->x++;
          }
          break;
        case 7:
          for(int i = 0; i < 1504-1329; i++) {
            mapProtagonista->x++;
          }
          for (int i = 0; i < (505-476)*0.56 ; i++) {
            mapProtagonista->x++;
            mapProtagonista->y -= 0.56;
          }
          for (int i = 0; i < (476-436)/2; i++) {
            mapProtagonista->x++;
            mapProtagonista->y -= 2.5;
          }
          break;
        case 8:
          for (int i = 0; i < (436-392)/2; i++) {
            mapProtagonista->x++;
            mapProtagonista->y -= 2.5;
          }
          for (int i = 0; i < (392-169); i++) {
            mapProtagonista->y--;
          }          
          break;
        case 9:

          break; 
        default:
          break;
      };

      break;
    case ALLEGRO_KEY_ENTER:

      switch (mapProtagonista->stage) {
        case 0:
          *gameState = STAGE_1;
          break;
        case 1:

          break;
        case 2:
          *gameState = STAGE_2;
          break;
        case 3:

          break;
        case 4:
          *gameState = STAGE_3;
          break;
        case 5:

          break;
        case 6:
          *gameState = STAGE_4;
          break;
        case 7:

          break;
        case 8:
          *gameState = STAGE_5;
          break;
        case 9:
          
          break;
        default:
          break;
      }

      break;
    default:
      break;
  };
}

void handlerMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game, GameState *gameState) {
  drawMapProtagonista(mapProtagonista);
  moveMapProtagonista(mapProtagonista, game, gameState);
}