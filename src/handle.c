#include "headers/handle.h"
#include "headers/screens.h"
#include "headers/helper.h"

bool handleScrens () {
  bool redraw = true;

  if (GAME_INFO->event.type == ALLEGRO_EVENT_TIMER)
    redraw = true;
  else if(GAME_INFO->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    return false;

  if(GAME_INFO->event.type == ALLEGRO_EVENT_KEY_DOWN) {
    if(GAME_INFO->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      if (GAME_INFO->state >= STAGE_1 && GAME_INFO->state <= STAGE_5) {
        GAME_INFO->state = MAP;
      } else {
        GAME_INFO->state = MENU;
      }
    }
  }

  if(redraw && al_is_event_queue_empty(GAME_INFO->queue)) {
    al_clear_to_color(AL_COLOR_BLACK);

    switch (GAME_INFO->state) {
      case MENU:
        if (!drawHome()) return false;
        break;
      case CONFIG:
        if (!drawConfig()) GAME_INFO->state = MENU;
        break;
      case GAME:
        if (!drawGame()) GAME_INFO->state = MENU;
        break;
      case MAP:
        if(!drawMap()) GAME_INFO->state = MENU;
        break;
      case STAGE_1:
        if(!drawStage_1()) GAME_INFO->state = MAP;
        break;
      case STAGE_2:
        if(!drawStage_2()) GAME_INFO->state = MAP;
        break;
      case STAGE_3:
        if(!drawStage_3()) GAME_INFO->state = MAP;
        break;
      case STAGE_4:
        if(!drawStage_4()) GAME_INFO->state = MAP;
        break;
      case STAGE_5:
        if(!drawStage_5()) GAME_INFO->state = MAP;
        break;
      default:
        break;
    }

    al_flip_display();
  }

  return true;
}