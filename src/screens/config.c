#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "../headers/screens.h"
#include "../headers/components.h"

struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

ALLEGRO_FONT *fontSettings;

void setupButtonsConfig() {
  fontSettings = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  int width = 335;
  int height = 65;
  
  struct Button sound = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 - 50,
    width,
    height,
    "Som: Ligado",
    "sound",
    fontSettings,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_CONFIG[0] = sound;

  struct Button back = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 + 50,
    width,
    height,
    "Voltar",
    "back",
    fontSettings,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_CONFIG[1] = back;
}

bool drawConfig () {
  al_draw_bitmap(bg_home, 0, 0, 0);

  for (int i = 0; i < BUTTONS_CONFIG_COUNT; i++) {
    if (drawButton(&BUTTONS_CONFIG[i])) {
      BUTTONS_CONFIG[i].background_color = AL_COLOR_LIGHT_BROWN;

      if (GAME_INFO->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        printf("%s clicked\n", BUTTONS_CONFIG[i].text);
        playSound(0);

        switch (i) {
          case 0:
            if (GAME_INFO->is_sound) {
              BUTTONS_CONFIG[i].text = "Som: Desligado";
              GAME_INFO->is_sound = false;
            } else {
              BUTTONS_CONFIG[i].text = "Som: Ligado";
              GAME_INFO->is_sound = true;
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

void destroyConfig(void) {
  al_destroy_font(fontSettings);
}