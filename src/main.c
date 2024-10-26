#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>

#include "headers/helper.h"
#include "headers/handle.h"
#include "headers/sound.h"
#include "headers/components.h"
#include "headers/screens.h"
#include "headers/protagonista.h"
#include "headers/enemies.h"

struct AllegroGame *GAME_INFO;

void initializeAllegro() {
  ALLEGRO_MONITOR_INFO monitor_info;

  al_get_monitor_info(0, &monitor_info);

  WIDTH_SCREEN = monitor_info.x2 - monitor_info.x1;
  HEIGHT_SCREEN = monitor_info.y2 - monitor_info.y1;

  int window_x = monitor_info.x1;
  int window_y = monitor_info.y1;

  GAME_INFO = (struct AllegroGame *) malloc(sizeof(struct AllegroGame));
  GAME_INFO->state = MENU;

  if (!GAME_INFO) {
    fprintf(stderr, "Fail to allocate memory.\n");
    exit(1);
  }

  GAME_INFO->font = al_load_font(FONT_PATH, FONT_SIZE, 0);
  GAME_INFO->font_small = al_load_font(FONT_PATH, FONT_SIZE_SMALL, 0);
  GAME_INFO->font_big = al_load_font(FONT_PATH, FONT_SIZE_BIG, 0);
  GAME_INFO->font_bullet = al_load_font(FONT_PATH, 50, 0);

  GAME_INFO->timer = al_create_timer(1.0 / 30.0);
  GAME_INFO->queue = al_create_event_queue();
  GAME_INFO->display = al_create_display(WIDTH_SCREEN, HEIGHT_SCREEN);

  al_set_window_position(GAME_INFO->display, window_x, window_y);

  GAME_INFO->mouse_state = (ALLEGRO_MOUSE_STATE *) malloc(sizeof(ALLEGRO_MOUSE_STATE));

  GAME_INFO->is_sound = true;

  if (!GAME_INFO->timer || !GAME_INFO->queue || !GAME_INFO->display) {
    fprintf(stderr, "Fail to load Allegro.\n");
    exit(1);
  }
}

void setupAllegro() {
  al_init();
  al_install_keyboard();
  al_init_image_addon();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_mouse();
  al_install_audio();
  al_init_acodec_addon();

  initializeAllegro();

  if (!GAME_INFO->timer || !GAME_INFO->queue || !GAME_INFO->display) {
    fprintf(stderr, "Fail to load Allegro.\n");
    exit(1);
  }

  al_register_event_source(GAME_INFO->queue, al_get_keyboard_event_source());
  al_register_event_source(GAME_INFO->queue, al_get_display_event_source(GAME_INFO->display));
  al_register_event_source(GAME_INFO->queue, al_get_timer_event_source(GAME_INFO->timer));
  al_register_event_source(GAME_INFO->queue, al_get_mouse_event_source());

  al_set_window_title(GAME_INFO->display, "Sombras do Sertão");
  al_set_display_icon(GAME_INFO->display, al_load_bitmap("assets/images/icon/icon.jpeg"));

  setupSamples();

  setupProtagonista();
  setupBulletsProtagonista();
  setupMapProtagonista();
  setupEnemies();
  setupBulletEnemies();
  setupButtonsConfig();
  setupHome();
  setupGame();
  setupMap();
  setupStage_1();
  setupStage_2();
  setupStage_3();
  setupStage_4();
  setupStage_5();
}

void destroyAllegro() {
  al_destroy_font(GAME_INFO->font);
  al_destroy_font(GAME_INFO->font_small);
  al_destroy_font(GAME_INFO->font_big);
  al_destroy_font(GAME_INFO->font_bullet);
  
  al_destroy_display(GAME_INFO->display);
  al_destroy_timer(GAME_INFO->timer);
  al_destroy_event_queue(GAME_INFO->queue);

  al_uninstall_audio();
  al_uninstall_keyboard();
  al_uninstall_mouse();
  al_shutdown_ttf_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
  al_shutdown_image_addon();

  destroyEnemies();

  destroyHome();
  destroyConfig();
  destroyGame();
  destroyMap();
  destroyMapProtagonista();
  destroyStage_1();
  destroyStage_2();
  destroyStage_3();
  destroyStage_4();
  destroyStage_5();
  free(GAME_INFO->mouse_state);
  free(GAME_INFO);
}

int main() {
  setupAllegro();

  bool redraw = true;

  al_start_timer(GAME_INFO->timer);
  bool done = false;

  while(!done) {
    al_wait_for_event(GAME_INFO->queue, &GAME_INFO->event);
    al_get_mouse_state(GAME_INFO->mouse_state);

    if (!handleScrens()) {
      done = true;
    }

    if (GAME_INFO->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
      done = true;
    }
  }

  destroyAllegro(GAME_INFO);

  return 0;
}