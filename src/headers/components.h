#ifndef _COMPONENTS_STATE_
#define _COMPONENTS_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "helper.h"

enum ButtonType {
  FILLED,
  OUTLINED
};

struct Button {
  int x;
  int y;
  int width;
  int height;
  char *text;
  char *alias;
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_COLOR background_color;
  enum ButtonType type;
};

struct saveFile {
  char *name;
  char *alias; 
  char *faseAtual;
  char *minutos;
  char *honra;
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_BITMAP *image;
  ALLEGRO_FONT *smallerFont;
};

#define BUTTONS_CONFIG_COUNT 2
extern struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

#define BUTTONS_HOME_COUNT 4
extern struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];

bool drawButton(struct Button *button);

#define SAVEFILES_COUNT 4
extern struct saveFile FILES[SAVEFILES_COUNT];

bool drawSaveFile(struct saveFile *saveFile, int index);
#endif