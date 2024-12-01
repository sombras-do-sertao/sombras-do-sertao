#ifndef _COMPONENTS_STATE_
#define _COMPONENTS_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "helper.h"
#include "save.h"

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

enum {
  DIALOG_1 = 0,
  DIALOG_2 = 1,
  DIALOG_3 = 2,
  DIALOG_4 = 3,
  DIALOG_5 = 4,
} DialogStage;
#define DIALOG_COUNT 5

#define BUTTONS_CONFIG_COUNT 2
extern struct Button BUTTONS_CONFIG[BUTTONS_CONFIG_COUNT];

#define BUTTONS_HOME_COUNT 5
extern struct Button BUTTONS_HOME[BUTTONS_HOME_COUNT];

bool drawButton(struct Button *button);

bool drawSaveFile(struct saveFile *saveFile, int index);

void setupDied();
void drawDied();

void setupDialog();
void drawDialog(int dialog_id);
void drawDialogText(int dialog_id, int text_id, float x_text, float y_text);
void drawTextWithLineBreaks(float x, float y, const char *text);
void updateDialogText(int stage, int *text_id);

#endif