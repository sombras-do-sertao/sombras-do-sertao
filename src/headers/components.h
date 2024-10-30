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
  int x;
  int y;
  int width;
  int height; 
  char *name;
  char *alias; 
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_BITMAP *image;
};

#define BUTTONS_CONFIG_COUNT 2
extern struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

#define BUTTONS_HOME_COUNT 4
extern struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];

#define SAVEFILES_COUNT 3
extern struct saveFile FILES[SAVEFILES_COUNT];


bool drawButton(struct Button *button);

#endif