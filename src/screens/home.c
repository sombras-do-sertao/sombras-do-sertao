#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/sound.h"
#include "../headers/components.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];
ALLEGRO_BITMAP *bg_home;
ALLEGRO_FONT *fontHome;
ALLEGRO_FONT *fontButton;

void setupHome(struct AllegroGame *game) {
  bg_home = al_load_bitmap("assets/images/background/bg_home.jpg");
  fontButton = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 32, 0);
  fontHome = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 64, 0);

  int width = 335;
  int height = 65;

  struct Button start_game = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 - 50,
    width,
    height,
    "Iniciar Jogo",
    "start_game",
    fontButton, 
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[START_GAME] = start_game;

  struct Button settings = {
    WIDTH_SCREEN /2 - width/2,
    HEIGHT_SCREEN / 2 + 50,
    width,
    height,
    "Configurações",
    "settings",
    fontButton,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[SETTINGS] = settings;

  struct Button exit = {
    WIDTH_SCREEN / 2 - width/2,
    HEIGHT_SCREEN / 2 + 150,
    width,
    height,
    "Sair",
    "exit",
    fontButton,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[EXIT] = exit;
}

void destroyHome(void) {
  al_destroy_bitmap(bg_home);
  al_destroy_font(fontButton);
  al_destroy_font(fontHome);
}

bool drawHome (struct AllegroGame *game, GameState *gameState) {
  al_draw_bitmap(bg_home, 0, 0, 0);

  const char *title = "Sombras do Sertão";
  int title_x = WIDTH_SCREEN / 2;
  int title_y = HEIGHT_SCREEN / 6;

  al_draw_text(fontHome, AL_COLOR_WHITE, title_x, title_y, ALLEGRO_ALIGN_CENTER, title);

  for (int i = 0; i < BUTTONS_HOME_COUNT; i++) {
    if (drawButton(&BUTTONS_HOME[i], game)) {
      BUTTONS_HOME[i].background_color = AL_COLOR_LIGHT_BROWN;

      if (game->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        printf("%s clicked\n", BUTTONS_HOME[i].text);
        playSound(game, 0);

        switch (i) {
          case START_GAME:
            printf("Iniciar Jogo\n");
            *gameState = MAP;
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
      BUTTONS_HOME[i].background_color = AL_COLOR_BROWN;
    }
  }

  return true;
}