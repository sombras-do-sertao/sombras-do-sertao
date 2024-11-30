#ifndef _SAVE_STATE_
#define _SAVE_STATE_

struct saveFile {
  char *name;
  char *alias; 
  char *stage;
  char *seconds;
  char *honor;
  ALLEGRO_FONT *font;
  ALLEGRO_COLOR font_color;
  ALLEGRO_BITMAP *image;
  ALLEGRO_FONT *smallerFont;
};

#define SAVEFILES_COUNT 4
extern struct saveFile FILES[SAVEFILES_COUNT];

void loadSaves();

void saveHandler();

#endif