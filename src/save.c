#include <stdio.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "headers/helper.h"
#include "headers/save.h"
#include "headers/home-screen.h"

struct saveFile FILES[SAVEFILES_COUNT];

void saveHandler() {
  int result = al_show_native_message_box(GAME_INFO->display, "Novo Jogo", "Salvar Jogo", "Deseja salvar o jogo?", NULL, ALLEGRO_MESSAGEBOX_YES_NO);

  if (result == 1) {
    int width_dialog = 400;
    int height_dialog = 200;
    int window_x = (WIDTH_SCREEN - width_dialog) / 2;
    int window_y = (HEIGHT_SCREEN - height_dialog) / 2;

    bool selecting_save_slot = true;
    int selected_slot = -1;

    while (selecting_save_slot) {
      al_wait_for_event(GAME_INFO->queue, &GAME_INFO->event);
      al_get_mouse_state(GAME_INFO->mouse_state);

      al_draw_bitmap(bg_home, 0, 0, 0);

      al_draw_filled_rounded_rectangle(window_x, window_y, window_x + width_dialog, window_y + height_dialog, 10, 10, al_map_rgb(50, 50, 50));
      al_draw_rectangle(window_x, window_y, window_x + width_dialog, window_y + height_dialog, AL_COLOR_WHITE, 2);

      ALLEGRO_COLOR color_slot1 = AL_COLOR_WHITE;
      ALLEGRO_COLOR color_slot2 = AL_COLOR_WHITE;
      ALLEGRO_COLOR color_slot3 = AL_COLOR_WHITE;
      ALLEGRO_COLOR color_slot4 = AL_COLOR_WHITE;

      if (GAME_INFO->mouse_state->x > window_x + 20 && GAME_INFO->mouse_state->x < window_x + width_dialog - 20) {
        if (GAME_INFO->mouse_state->y > window_y + 60 && GAME_INFO->mouse_state->y < window_y + 80) {
          color_slot1 = AL_COLOR_YELLOW;
        } else if (GAME_INFO->mouse_state->y > window_y + 90 && GAME_INFO->mouse_state->y < window_y + 110) {
          color_slot2 = AL_COLOR_YELLOW;
        } else if (GAME_INFO->mouse_state->y > window_y + 120 && GAME_INFO->mouse_state->y < window_y + 140) {
          color_slot3 = AL_COLOR_YELLOW;
        } else if (GAME_INFO->mouse_state->y > window_y + 150 && GAME_INFO->mouse_state->y < window_y + 170) {
          color_slot4 = AL_COLOR_YELLOW;
        }
      }

      al_draw_text(GAME_INFO->font, AL_COLOR_WHITE, window_x + 20, window_y + 20, 0, "Selecione o slot para salvar:");
      al_draw_text(GAME_INFO->font, color_slot1, window_x + 20, window_y + 60, 0, FILES[0].name);
      al_draw_text(GAME_INFO->font, color_slot2, window_x + 20, window_y + 90, 0, FILES[1].name);
      al_draw_text(GAME_INFO->font, color_slot3, window_x + 20, window_y + 120, 0, FILES[2].name);
      al_draw_text(GAME_INFO->font, color_slot4, window_x + 20, window_y + 150, 0, FILES[3].name);
      al_flip_display();

      if (GAME_INFO->event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if (GAME_INFO->mouse_state->x > window_x + 20 && GAME_INFO->mouse_state->x < window_x + width_dialog - 20) {
          if (GAME_INFO->mouse_state->y > window_y + 60 && GAME_INFO->mouse_state->y < window_y + 80) {
            selected_slot = 1;
          } else if (GAME_INFO->mouse_state->y > window_y + 90 && GAME_INFO->mouse_state->y < window_y + 110) {
            selected_slot = 2;
          } else if (GAME_INFO->mouse_state->y > window_y + 120 && GAME_INFO->mouse_state->y < window_y + 140) {
            selected_slot = 3;
          } else if (GAME_INFO->mouse_state->y > window_y + 150 && GAME_INFO->mouse_state->y < window_y + 170) {
            selected_slot = 4;
          }
          if (selected_slot != -1) {
            selecting_save_slot = false;
          }
        }
      }
      if (GAME_INFO->event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (GAME_INFO->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
          break;
        }
      }
    }

    if (selected_slot != -1) {
      GAME_INFO->save->alias = FILES[selected_slot - 1].alias;
      GAME_INFO->save->stage = 0;
      GAME_INFO->save->honor = 0;
      GAME_INFO->save->seconds = 0;
      GAME_INFO->save->name = FILES[selected_slot - 1].name;

      saveGame();
    }
  }
}

void loadSaves() {
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
    save.stage = malloc(255 * sizeof(char));
    save.seconds = malloc(255 * sizeof(char));
    save.honor = malloc(255 * sizeof(char));

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

    if (fscanf(file, "stage: %[^\n]\n", save.stage) != 1) {
      printf("Erro ao ler stage do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "seconds: %[^\n]\n", save.seconds) != 1) {
      printf("Erro ao ler seconds do save %d\n", i + 1);
      break;
    }

    if (fscanf(file, "honor: %[^\n]\n", save.honor) != 1) {
      printf("Erro ao ler honor do save %d\n", i + 1);
      break;
    }

    FILES[i] = save;
  }

  fclose(file);
}

void saveGame() {
  FILE *file = fopen("data/save.txt", "w");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo de saves\n");
    return;
  }

  for (int i = 0; i < SAVEFILES_COUNT; i++) {
    if (FILES[i].alias == GAME_INFO->save->alias) {
      fprintf(file, "Save %d: \n", i + 1);
      fprintf(file, "name: %s\n", FILES[i].name);
      fprintf(file, "alias: %s\n", FILES[i].alias);
      fprintf(file, "stage: %d\n", GAME_INFO->save->stage);
      fprintf(file, "seconds: %.2f\n", GAME_INFO->save->seconds);
      fprintf(file, "honor: %d\n", GAME_INFO->save->honor);
      fprintf(file, "\n");

      continue;
    }
    
    fprintf(file, "Save %d: \n", i + 1);
    fprintf(file, "name: %s\n", FILES[i].name);
    fprintf(file, "alias: %s\n", FILES[i].alias);
    fprintf(file, "stage: %s\n", FILES[i].stage);
    fprintf(file, "seconds: %s\n", FILES[i].seconds);
    fprintf(file, "honor: %s\n", FILES[i].honor);
    fprintf(file, "\n");
  }

  fclose(file);
}