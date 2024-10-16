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
      
      switch (mapProtagonista->stage)
      {
      case 1:
        
        break;
      
      default:
        break;
      }

      break;
    case ALLEGRO_KEY_RIGHT:
    case ALLEGRO_KEY_D:
      
      mapProtagonista->stage++;
      
      switch (mapProtagonista->stage)
      {
      case 1:
        for(int i = 0; i < 297-147; i++) {
          mapProtagonista->x++;
        }

        for(int i = 0; i < (495-327)/3; i++) {
          mapProtagonista->x ++;
          mapProtagonista->y += 3;
        }
        break;
      case 2:
        for (int i = 0; i < (694-495)/3; i++) {
          mapProtagonista->x ++;
          mapProtagonista->y += 3;
        }

        
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