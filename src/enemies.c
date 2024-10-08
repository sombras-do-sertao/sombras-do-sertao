#include "headers/enemies.h"

struct Enemy enemies[ENEMIES_COUNT];
struct BulletEnemy bullets_enemies[BULLETS_ENEMIES_COUNT];

// TODO:
// Para conseguir fazer é nescessario terminar a parte de renderização por partes do jogo
// - Implement setupEnemies
// - Implement handlerEnemies

void setupEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    enemies[i].x = rand() % 800;
    enemies[i].y = rand() % 600;
    enemies[i].width = 32;
    enemies[i].height = 32;
    enemies[i].speed = 1;
    enemies[i].direction = rand() % 4;
    enemies[i].active = false;
    enemies[i].image = al_load_bitmap("assets/images/characters/soldado.png");
  }
}

void setupBulletEnemies() {
  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    bullets_enemies[i].x = 0;
    bullets_enemies[i].y = 0;
    bullets_enemies[i].width = 32;
    bullets_enemies[i].height = 32;
    bullets_enemies[i].speed = 1;
    bullets_enemies[i].active = false;
    bullets_enemies[i].image = al_load_bitmap("assets/images/addons/municao_inimigo.png");
  }
}

void drawEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    if (enemies[i].active) {
      al_draw_bitmap(enemies[i].image, enemies[i].x, enemies[i].y, 0);
    }
  }
}

void drawBulletEnemies() {
  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    if (bullets_enemies[i].active) {
      al_draw_bitmap(bullets_enemies[i].image, bullets_enemies[i].x, bullets_enemies[i].y, 0);
    }
  }
}

void moveEnemies() {}

void handlerEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    if (enemies[i].active) {
      if (enemies[i].x < 0 || enemies[i].x > 800 || enemies[i].y < 0 || enemies[i].y > 600) {
        enemies[i].active = false;
      }
    }
  }
}

void destroyEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    al_destroy_bitmap(enemies[i].image);
  }

  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    al_destroy_bitmap(bullets_enemies[i].image);
  }
}