#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/sound.h"
#include "../headers/components.h"
#include <stdio.h>

struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];

void setupButtonsHome(struct AllegroGame *game) {
  struct Button start_game = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 - 50,
    200,
    50,
    "Iniciar Jogo",
    "start_game",
    game->font_big,
    AL_COLOR_WHITE,
    AL_COLOR_BLUE,
    FILLED,
  };
  BUTTONS_HOME[START_GAME] = start_game;

  struct Button settings = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 + 50,
    200,
    50,
    "Configurações",
    "settings",
    game->font_big,
    AL_COLOR_WHITE,
    AL_COLOR_BLUE,
    FILLED,
  };
  BUTTONS_HOME[SETTINGS] = settings;

  struct Button exit = {
    WIDTH_SCREEN / 2 - 100,
    HEIGHT_SCREEN / 2 + 150,
    200,
    50,
    "Sair",
    "exit",
    game->font_big,
    AL_COLOR_WHITE,
    AL_COLOR_BLUE,
    FILLED,
  };
  BUTTONS_HOME[EXIT] = exit;
}

bool drawHome (struct AllegroGame *game, GameState *gameState) {
  al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, AL_COLOR_BLACK);

  const char *title = "Game-Machine";
  int title_x = WIDTH_SCREEN / 2;
  int title_y = HEIGHT_SCREEN / 6;

  al_draw_text(game->font_big, AL_COLOR_YELLOW, title_x, title_y, ALLEGRO_ALIGN_CENTER, title);

  for (int i = 0; i < BUTTONS_HOME_COUNT; i++) {
    if (drawButton(&BUTTONS_HOME[i], game)) {
      BUTTONS_HOME[i].background_color = AL_COLOR_LIGHT_BLUE;

      if (game->is_mouse_pressed && !game->was_mouse_pressed) {
        printf("%s clicked\n", BUTTONS_HOME[i].text);
        playSound(game, 0);

        switch (i) {
          case START_GAME:
            printf("Iniciar Jogo\n");
            *gameState = GAME;
            break;
          case SETTINGS:
            printf("Configurações\n");
            *gameState = CONFIG;
            break;
          case EXIT:
            return false;
            break;
        }
      }
    } else {
      BUTTONS_HOME[i].background_color = AL_COLOR_BLUE;
    }
  }

  return true;
}