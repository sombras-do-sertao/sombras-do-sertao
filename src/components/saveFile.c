#include "../headers/components.h"
#include "../headers/helper.h"
#include <allegro5/allegro_primitives.h>

bool drawSaveFile(struct saveFile *saveFile, struct AllegroGame *game) {
  int text_width = al_get_text_width(saveFile->font, saveFile->name);
  int text_height = al_get_font_line_height(saveFile->font);

  int nameX = saveFile->x + saveFile->width/2;
  int nameY = saveFile->y + saveFile->height/2;

  al_load_bitmap("assets/images/background/save.jpg");
  al_draw_text(saveFile->font, saveFile->font_color, nameX, nameY, ALLEGRO_ALIGN_CENTER, saveFile->name);
}