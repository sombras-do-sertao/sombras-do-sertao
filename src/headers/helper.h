#ifndef __HELPER_STATE__
#define __HELPER_STATE__

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#define WIDTH_SCREEN 1920
#define HEIGHT_SCREEN 1080

#define FONT_PATH "assets/fonts/Roboto-Regular.ttf"
#define FONT_SIZE 18
#define FONT_SIZE_SMALL 14
#define FONT_SIZE_BIG 24

#define AL_COLOR_BLACK al_map_rgb(0, 0, 0)
#define AL_COLOR_WHITE al_map_rgb(255, 255, 255)
#define AL_COLOR_BLUE al_map_rgb(0, 0, 128)
#define AL_COLOR_LIGHT_BLUE al_map_rgb(0, 0, 255)
#define AL_COLOR_YELLOW al_map_rgb(255, 255, 0)
#define AL_COLOR_RED al_map_rgb(128, 0, 0)
#define AL_COLOR_BROWN al_map_rgb(204, 136, 0)
#define AL_COLOR_LIGHT_BROWN al_map_rgb(255, 204, 0)
#define AL_COLOR_DARK_BROWN al_map_rgb(102, 51, 0)

struct AllegroGame {
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_EVENT event;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_FONT *font;
  ALLEGRO_FONT *font_small;
  ALLEGRO_FONT *font_big;
  ALLEGRO_MOUSE_STATE *mouse_state;
  bool is_mouse_pressed;
  bool was_mouse_pressed;
  bool is_sound;
};

enum MENU_OPTIONS { START_GAME, SETTINGS, EXIT, NUM_OPTIONS };

typedef enum {
  MENU = 0,
  GAME = 1,
  CONFIG = 2
} GameState;

bool isMouseOverText(ALLEGRO_MOUSE_STATE *mouse_state, int text_x, int text_y, const char *text, ALLEGRO_FONT *font);

bool isMouseOverBox(ALLEGRO_MOUSE_STATE *mouse_state, int box_x, int box_y, int box_width, int box_height);

void checkMouseClick(struct AllegroGame *game, bool *last_mouse_pressed, bool *last_was_mouse_pressed);

#endif