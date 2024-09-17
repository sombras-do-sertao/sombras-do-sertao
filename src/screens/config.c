#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "../headers/screens.h"
#include "../headers/components.h"

struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

void setupButtonsConfig(struct AllegroGame *game) {
  struct Button sound = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 - 50,
    200,
    50,
    "Som: Ligado",
    "sound",
    game->font_big,
    AL_COLOR_WHITE,
    AL_COLOR_BLUE,
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
    game->font_big,
    AL_COLOR_WHITE,
    AL_COLOR_BLUE,
    FILLED,
  };
  BUTTONS_CONFIG[1] = back;
}

bool drawConfig (struct AllegroGame *game) {
  for (int i = 0; i < BUTTONS_CONFIG_COUNT; i++) {
    if (drawButton(&BUTTONS_CONFIG[i], game)) {
      BUTTONS_CONFIG[i].background_color = AL_COLOR_LIGHT_BLUE;

      if (game->is_mouse_pressed && !game->was_mouse_pressed) {
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
      BUTTONS_CONFIG[i].background_color = AL_COLOR_BLUE;
    }
  }

  return true;
}