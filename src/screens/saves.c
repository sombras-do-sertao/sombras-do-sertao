#include "../headers/screens.h"
#include "../headers/components.h"
#include "../headers/helper.h"
#include <stdio.h>
#include <string.h>

ALLEGRO_FONT *fontSaves;
ALLEGRO_FONT *fontSaveTitle;
ALLEGRO_BITMAP *fileBackground;
ALLEGRO_FONT *smaller_font;

void setupSaves(){
  fontSaves = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  fontSaveTitle = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 64, 0);
  fileBackground = al_load_bitmap("assets/images/background/save.jpg");
  smaller_font = al_load_font("assets/fonts/LilitaOne-Regular.ttf",18,0);

  for (int i = 0; i < SAVEFILES_COUNT; i++) {
    FILES[i].font = fontSaves;
    FILES[i].font_color = AL_COLOR_WHITE;
    FILES[i].image = fileBackground;
    FILES[i].smallerFont = smaller_font;
  }
}

bool drawSaves() {
  al_draw_bitmap(bg_home, 0, 0, 0);

  const char *title_text = "Jogos salvos";
  int text_width = al_get_text_width(fontSaveTitle, title_text);
  int title_x = WIDTH_SCREEN / 2 - text_width / 2;
  int title_y = 80;
  al_draw_text(fontSaveTitle, AL_COLOR_WHITE, title_x, title_y, 0, title_text);

  for(int i = 0; i < SAVEFILES_COUNT; i++) {
    if (drawSaveFile(&FILES[i], i)) {
      FILES[i].font_color = AL_COLOR_YELLOW;

      if (GAME_INFO->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        printf("%s clicked\n", FILES[i].name);
        playSound(MENU_CLICK);

        printf("Stage: %d\n", atoi(FILES[i].stage));
        
        MAPA_PROTAGONISTA->stage = atoi(FILES[i].stage);
        GAME_INFO->state = MAP;

        printf("Stage: %d\n", MAPA_PROTAGONISTA->stage);
      }
    } else {
      FILES[i].font_color = AL_COLOR_WHITE;
    }
  }

 return true;
}

void destroySaves() {
  al_destroy_font(fontSaves);
  al_destroy_font(fontSaveTitle);
  al_destroy_bitmap(fileBackground);
  al_destroy_font(smaller_font);
}
