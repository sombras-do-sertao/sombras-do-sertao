#include "headers/map_protagonista.h"
#include "headers/helper.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
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

void moveMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game) {
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
          for (int i = 0; i < 1329-1104; i++) {
            mapProtagonista->x++;
          }
          break;
        default:
          break;
      };

      break;
    case ALLEGRO_KEY_ENTER:

      switch (mapProtagonista->stage) {
        case 0:
          
          break;
        case 1:

          break;
        default:
          break;
      }
    

      break;
    default:
      break;
  };
}

void handlerMapProtagonista(struct MapProtagonista *mapProtagonista, struct AllegroGame *game) {
  drawMapProtagonista(mapProtagonista);
  moveMapProtagonista(mapProtagonista, game);
}