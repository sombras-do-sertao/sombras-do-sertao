#include "headers/protagonista.h"
#include "headers/helper.h"
#include "headers/handle.h"
#include "headers/enemies.h"
#include "headers/colision.h"
#include "headers/sound.h"
#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

struct BulletProtagonista bullets_protagonista[BULLETS_PROTAGONISTA_COUNT];
struct Protagonista *protagonista;

int frameX = 0;
int frameY = 0;
void setupProtagonista() {
  protagonista = malloc(sizeof(struct Protagonista));

  protagonista->x = 20;
  protagonista->y = HEIGHT_SCREEN / 2;
  protagonista->width = 296;
  protagonista->height = 342;
  protagonista->speed = 20;
  protagonista->direction = 1;
  protagonista->health = 3;
  protagonista->score = 0;
  protagonista->stageX = 20;
  protagonista->estagioAtual = 0;
  protagonista->last_shoot = 0;
  protagonista->last_stab = 0;
  protagonista->bullets = 4;
  protagonista->image = al_load_bitmap("assets/images/characters/sprites/protagonista_andando.png");
  protagonista->image_stab = al_load_bitmap("assets/images/characters/sprites/protagonista_facada.png");
  protagonista->image_bullet = al_load_bitmap("assets/images/addons/ammo.png");
  protagonista->image_health = al_load_bitmap("assets/images/addons/heart.png");
  protagonista->is_stab = false;
}

void drawProtagonista() {
  if (protagonista->is_stab) {
    return;
  }

  if(frameX > 3) {
    frameX = 0;
  } 
  if(frameX < 0) {
    frameX = 3;
  }
  al_draw_bitmap_region(protagonista->image, frameX * protagonista->width, frameY * protagonista->height, protagonista->width, protagonista->height, protagonista->x, protagonista->y, 0);
}
void moveProtagonista() {
  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_UP) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_W)) {
    if (protagonista->y + protagonista->height - 50 <= HEIGHT_SCREEN - protagonista->height) {
      return;
    }

    protagonista->y -= protagonista->speed;
  }
  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_DOWN) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_S)) {
    if (protagonista->y + protagonista->height >= HEIGHT_SCREEN) {
      return;
    }
    protagonista->y += protagonista->speed;
  }
  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_LEFT) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_A)) {
    if (protagonista->x <= 0) {
      return;
    }

    protagonista->direction = -1;
    protagonista->x -= protagonista->speed;
    protagonista->stageX -= protagonista->speed;
    frameY = 1;
    frameX--;
  }
  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_RIGHT) || al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_D)) {
    if (protagonista->x + protagonista->width >= WIDTH_SCREEN && getEnemiesActive() > 0) {
      return;
    }

    protagonista->direction = 1;
    protagonista->x += protagonista->speed;
    protagonista->stageX += protagonista->speed;
    frameY = 0;
    frameX++;
  }
}

void setupBulletsProtagonista() {
  for (int i = 0; i < BULLETS_PROTAGONISTA_COUNT; i++) {
    bullets_protagonista[i].x = 0;
    bullets_protagonista[i].y = 0;
    bullets_protagonista[i].width = 32;
    bullets_protagonista[i].height = 32;
    bullets_protagonista[i].speed = 50;
    bullets_protagonista[i].direction = 1;
    bullets_protagonista[i].active = false;
    bullets_protagonista[i].direction = 1;
  }
}

void shootProtagonista() {
  double current_time = al_get_time();

  if (al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_SPACE) && 
      current_time - protagonista->last_shoot >= SHOOT_DELAY && 
      protagonista->bullets > 0
    ) {
    for (int i = 0; i < BULLETS_PROTAGONISTA_COUNT; i++) {
      if (!bullets_protagonista[i].active) {
        if (protagonista->direction == 1) {
          bullets_protagonista[i].x = protagonista->x + protagonista->width;
        } else {
          bullets_protagonista[i].x = protagonista->x;
        }

        bullets_protagonista[i].active = true;
        bullets_protagonista[i].y = protagonista->y + protagonista->height / 2 - 80;
        bullets_protagonista[i].direction = protagonista->direction;
        bullets_protagonista[i].speed = 50 * protagonista->direction;
        bullets_protagonista[i].image = al_load_bitmap("assets/images/addons/municao_revolver.png");

        protagonista->last_shoot = current_time;
        protagonista->bullets--;

        playSound(SHOOT);
        break;
      }
    }
  }

  for (int i = 0; i < BULLETS_PROTAGONISTA_COUNT; i++) {
    if (!bullets_protagonista[i].active) continue;

    bool colision = false;

    bullets_protagonista[i].x += bullets_protagonista[i].speed;

    if (bullets_protagonista[i].direction == 1) {
      al_draw_bitmap_region(bullets_protagonista[i].image, 0, 0, 21, 10, bullets_protagonista[i].x, bullets_protagonista[i].y, 0); 
    } else {
      al_draw_bitmap_region(bullets_protagonista[i].image, 0, 10, 21, 10, bullets_protagonista[i].x, bullets_protagonista[i].y, 0);
    }

    if (bullets_protagonista[i].x > WIDTH_SCREEN || bullets_protagonista[i].x < 0) {
      colision = true;
    }

    for (int j = 0; j < ENEMIES_COUNT; j++) {
      if (!enemies[j].active) continue;

      if (colision_bullet_in_enemy(&bullets_protagonista[i], &enemies[j])) {
        colision = true;
        enemies[j].active = false;
        break;
      }
    }

    if (colision) {
      bullets_protagonista[i].active = false;
    }
  }
}

void stabProtagonista() {
  double current_time = al_get_time();

  if (!al_key_down(&GAME_INFO->key_state, ALLEGRO_KEY_F)) {
    return;
  } else if (current_time - protagonista->last_stab < 3) {
    return;
  }

  protagonista->last_stab = current_time;
  protagonista->is_stab = true;
  playSound(KNIFE_HIT);

  float delay_sprite = 0.05;
  int frameY = protagonista->direction == 1 ? 0 : protagonista->height;
  for (int i = 0; i < 4; i++) {
    handleScrens();
    al_draw_bitmap_region(protagonista->image_stab, i * protagonista->width, frameY, protagonista->width, protagonista->height, protagonista->x, protagonista->y, 0);

    al_flip_display();
    al_rest(delay_sprite);
  }
  for (int i = 3; i >= 0; i--) {
    handleScrens();
    al_draw_bitmap_region(protagonista->image_stab, i * protagonista->width, frameY, protagonista->width, protagonista->height, protagonista->x, protagonista->y, 0);

    al_flip_display();
    al_rest(delay_sprite);
  }

  for (int i = 0; i < ENEMIES_COUNT; i++) {
    if (!enemies[i].active) continue;

    if (colision_protagonista_in_enemy(protagonista, &enemies[i])) {
      enemies[i].active = false;
      protagonista->is_stab = false;
      return;
    }
  }

  protagonista->is_stab = false;
}

void drawBulletCount() {
  al_draw_bitmap(protagonista->image_bullet, 0, 10, 0);
  al_draw_textf(GAME_INFO->font_bullet, AL_COLOR_BLACK, 100, 25, ALLEGRO_ALIGN_LEFT, "%d", protagonista->bullets);
}

void drawHealth() {
  for (int i = 0; i < protagonista->health; i++) {
    al_draw_bitmap(protagonista->image_health, 0 + (i * 50), 100, 0);
  }
}

void handlerProtagonista() {
  drawHealth();
  drawBulletCount();
  drawProtagonista();
  moveProtagonista();
  shootProtagonista();
  stabProtagonista();
}