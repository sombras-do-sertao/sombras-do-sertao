#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "../headers/screens.h"
#include "../headers/components.h"

struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

void setupButtonsConfig(struct AllegroGame *game) {
  ALLEGRO_FONT *fontSettings = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  
  struct Button sound = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 - 50,
    200,
    50,
    "Som: Ligado",
    "sound",
    fontSettings,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_CONFIG[0] = sound;

  struct Button back = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 + 50,
    200,
    50,
    "Voltar",
    "back",
    fontSettings,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_CONFIG[1] = back;
}

bool drawConfig (struct AllegroGame *game) {
  al_draw_bitmap(bg_home, 0, 0, 0);

  for (int i = 0; i < BUTTONS_CONFIG_COUNT; i++) {
    if (drawButton(&BUTTONS_CONFIG[i], game)) {
      BUTTONS_CONFIG[i].background_color = AL_COLOR_LIGHT_BROWN;

      if (game->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        printf("%s clicked\n", BUTTONS_CONFIG[i].text);
        playSound(game, 0);

        switch (i) {
          case 0:
            if (game->is_sound) {
              BUTTONS_CONFIG[i].text = "Som: Desligado";
              game->is_sound = false;
            } else {
              BUTTONS_CONFIG[i].text = "Som: Ligado";
              game->is_sound = true;
            }
            break;
          case 1:
            return false;
        }
      }
    } else {
      BUTTONS_CONFIG[i].background_color = AL_COLOR_BROWN;
    }
  }

  return true;
}