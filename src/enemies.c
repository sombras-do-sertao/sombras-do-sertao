#include "headers/enemies.h"

struct Enemy enemies[ENEMIES_COUNT];
struct BulletEnemy bullets_enemies[BULLETS_ENEMIES_COUNT];

// TODO:
// Para conseguir fazer é nescessario terminar a parte de renderização por partes do jogo
// - Implement setupEnemies
// - Implement handlerEnemies

void setupEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    enemies[i].x = rand() % (WIDTH_SCREEN - 100);
    enemies[i].y = HEIGHT_SCREEN / 2 - 100;
    enemies[i].width = 500;
    enemies[i].height = 500;
    enemies[i].speed = 1;
    enemies[i].direction = rand() % 4;
    enemies[i].active = true;
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

void drawEnemie(struct Enemy *enemie) {
  al_draw_bitmap(enemie->image, enemie->x, enemie->y, 0);
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
    if (!enemies[i].active) continue;

    drawEnemie(&enemies[i]);  
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