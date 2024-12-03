#include <allegro5/allegro_primitives.h>
#include "../headers/screens.h"
#include "../headers/sound.h"
#include "../headers/components.h"
#include "../headers/save.h"
#include <allegro5/allegro_image.h>
#include <stdio.h>

struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];
ALLEGRO_BITMAP *bg_home;
ALLEGRO_FONT *fontHome;
ALLEGRO_FONT *fontButton;

void setupHome() {
  bg_home = al_load_bitmap("assets/images/background/bg_home.jpg");
  fontButton = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 32, 0);
  fontHome = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 64, 0);

  int width = 335;
  int height = 65;

  int y = HEIGHT_SCREEN / 2;
  int spaceY = 100;

  int x = WIDTH_SCREEN / 2 - width / 2;

  struct Button saves = {
    x,
    y - spaceY,
    width,
    height,
    "Continuar",
    "saves",
    fontButton,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[SAVE_OPTIONS] = saves;

   struct Button start_game = {
    x,
    y,
    width,
    height,
    "Novo Jogo",
    "start_game",
    fontButton, 
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[START_GAME] = start_game;

  struct Button settings = {
    x,
    y + spaceY,
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

  struct Button tutorial = {
    x,
    y + spaceY * 2,
    width,
    height,
    "Tutorial",
    "tutorial",
    fontButton,
    AL_COLOR_WHITE,
    AL_COLOR_BROWN,
    FILLED,
  };
  BUTTONS_HOME[TUTORIALS] = tutorial;

  struct Button exit = {
    x,
    y + spaceY * 3,
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

bool drawHome () {
  al_draw_bitmap(bg_home, 0, 0, 0);

  const char *title = "Sombras do Sertão";
  int title_x = WIDTH_SCREEN / 2;
  int title_y = HEIGHT_SCREEN / 6;

  al_draw_text(fontHome, AL_COLOR_WHITE, title_x, title_y, ALLEGRO_ALIGN_CENTER, title);

  for (int i = 0; i < BUTTONS_HOME_COUNT; i++) {
    if (drawButton(&BUTTONS_HOME[i])) {
      BUTTONS_HOME[i].background_color = AL_COLOR_LIGHT_BROWN;

      if (GAME_INFO->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        printf("%s clicked\n", BUTTONS_HOME[i].text);
        playSound(MENU_CLICK);

        switch (i) {
          case SAVE_OPTIONS:
            GAME_INFO->state = SAVES;
            break;
          case START_GAME: {
            saveHandler();
            MAPA_PROTAGONISTA->stage = 0;
            GAME_INFO->state = MAP;
            break;
          }
          case SETTINGS:
            GAME_INFO->state = CONFIG;
            break;
          case TUTORIALS:
            GAME_INFO->state = TUTORIAL;
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