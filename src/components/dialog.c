#include "../../data/dialog.h"
#include "../headers/components.h"
#include <string.h>

ALLEGRO_BITMAP *dialog_background;
char **dialog_texts[DIALOG_COUNT];
int current_text_id = 0;
int last_dialog_id = -1;

void setupDialog() {
  dialog_background = al_load_bitmap("assets/images/dialog_case/dialog.png");

  dialog_texts[DIALOG_1] = text1;
  dialog_texts[DIALOG_2] = text2;
  dialog_texts[DIALOG_3] = text3;
  dialog_texts[DIALOG_4] = text4;
  dialog_texts[DIALOG_5] = text5;
}

void drawTextWithLineBreaks(float x, float y, const char *text) {
  char buffer[1024];
  strncpy(buffer, text, sizeof(buffer));
  buffer[sizeof(buffer) - 1] = '\0';

  char *line = strtok(buffer, "\n");
  float line_height = al_get_font_line_height(GAME_INFO->font_dialog);

  while (line) {
    al_draw_text(GAME_INFO->font_dialog, AL_COLOR_WHITE, x, y, 0, line);
    y += line_height;
    line = strtok(NULL, "\n");
  }
}

void drawDialogText(int dialog_id, int text_id, float x_text, float y_text) {
  const char *text = dialog_texts[dialog_id][text_id];
  
  drawTextWithLineBreaks(x_text, y_text, text);
}

void drawDialog(int dialog_id) {
  if (dialog_id != last_dialog_id) {
    current_text_id = 0;
    last_dialog_id = dialog_id;
  }

  int x_image = 0;
  int y_image = HEIGHT_SCREEN - al_get_bitmap_height(dialog_background);

  int x_text = x_image + 420;
  int y_text = y_image + 80;

  al_draw_bitmap(dialog_background, x_image, y_image, 0);

  drawDialogText(dialog_id, current_text_id, x_text, y_text);

  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_ENTER)) {
    updateDialogText(dialog_id, &current_text_id);
  }
}

void updateDialogText(int dialog_id, int *text_id) {
  char **texts = dialog_texts[dialog_id];
  int text_count = 0;

  while (texts[text_count] != NULL) {
    text_count++;
  }

  if (*text_id < text_count - 1) {
    (*text_id)++;
  } else {
    *text_id = 0;
  }
}