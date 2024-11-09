#include "../headers/screens.h"
#include "../headers/components.h"
#include "../headers/helper.h"
#include <stdio.h>
#include <string.h>

struct saveFile FILES[SAVEFILES_COUNT];

ALLEGRO_FONT *fontSaves;
ALLEGRO_FONT *fontSaveTitle;
ALLEGRO_BITMAP *fileBackground;
ALLEGRO_FONT *smaller_font;

void setupSaves(){
  fontSaves = al_load_font("assets/fonts/LilitaOne-Regular.ttf",32,0);
  fontSaveTitle = al_load_font("assets/fonts/LilitaOne-Regular.ttf", 64, 0);
  fileBackground = al_load_bitmap("assets/images/background/save.jpg");
  smaller_font = al_load_font("assets/fonts/LilitaOne-Regular.ttf",18,0);

  FILE *file = fopen("data/save.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo de saves\n");
    return;
  }

  for (int i = 0; i < SAVEFILES_COUNT; i++) {
    char buffer[255];
    struct saveFile save;

    save.name = malloc(255 * sizeof(char));
    save.alias = malloc(255 * sizeof(char));
    save.faseAtual = malloc(255 * sizeof(char));
    save.minutos = malloc(255 * sizeof(char));
    save.honra = malloc(255 * sizeof(char));

    if (fgets(buffer, sizeof(buffer), file) == NULL) {
      printf("Erro ao ler linha de cabeçalho do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "name: %[^\n]\n", save.name) != 1) {
      printf("Erro ao ler nome do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "alias: %[^\n]\n", save.alias) != 1) {
      printf("Erro ao ler alias do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "faseAtual: %[^\n]\n", save.faseAtual) != 1) {
      printf("Erro ao ler faseAtual do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "minutos: %[^\n]\n", save.minutos) != 1) {
      printf("Erro ao ler minutos do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "honra: %[^\n]\n", save.honra) != 1) {
      printf("Erro ao ler honra do save %d\n", i + 1);
      break;
    }

    save.font = fontSaves;
    save.font_color = AL_COLOR_WHITE;
    save.image = fileBackground;
    save.smallerFont = smaller_font;

    FILES[i] = save;
  }

  fclose(file);
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

        printf("Stage: %d\n", atoi(FILES[i].faseAtual));
        
        MAPA_PROTAGONISTA->stage = atoi(FILES[i].faseAtual);
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
