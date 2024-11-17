#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP *skull;

void setupDied() {
  skull = al_load_bitmap("assets/images/addons/caveira.png");
}

void drawDied() {
  al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, AL_COLOR_BLACK);

  al_draw_bitmap(skull, WIDTH_SCREEN / 2 - 220, HEIGHT_SCREEN / 2 - 50, 0);
  al_draw_bitmap(skull, WIDTH_SCREEN / 2 + 120, HEIGHT_SCREEN / 2 - 50, 0);
  al_draw_text(GAME_INFO->font_big, AL_COLOR_WHITE, WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2, ALLEGRO_ALIGN_CENTER, "Você morreu, Cangaceiro!");
  al_draw_text(GAME_INFO->font_small, AL_COLOR_WHITE, WIDTH_SCREEN / 2, HEIGHT_SCREEN / 2 + 50, ALLEGRO_ALIGN_CENTER, "Pressione ESC tecla para voltar...");
}