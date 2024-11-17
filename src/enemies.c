#include "headers/enemies.h"
#include "allegro5/allegro_primitives.h"
#include "headers/sound.h"
#include <stdio.h>

struct Enemy enemies[ENEMIES_COUNT];
struct BulletEnemy bullets_enemies[BULLETS_ENEMIES_COUNT];

int last_shoot = 0;
int delay_shoot = 1;

int frameX_Enemy = 0;
int frameY_Enemy = 1;

void setupEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    enemies[i].x = rand() % (WIDTH_SCREEN - 100);
    enemies[i].y = HEIGHT_SCREEN / 2 - 100;
    enemies[i].width = 295;
    enemies[i].height = 341;
    enemies[i].speed = 10;
    enemies[i].direction = rand() % 4;
    enemies[i].active = true;
    enemies[i].image = al_load_bitmap("assets/images/characters/sprites/soldado.png");
    enemies[i].last_shoot = 0;
    enemies[i].time_to_shoot = rand() % 5 + 1;
  }

  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    bullets_enemies[i].x = 0;
    bullets_enemies[i].y = 0;
    bullets_enemies[i].width = 32;
    bullets_enemies[i].height = 32;
    bullets_enemies[i].speed = 50;
    bullets_enemies[i].active = false;
    bullets_enemies[i].image = al_load_bitmap("assets/images/addons/municao_inimigo.png");
  }
}

void drawEnemie(struct Enemy *enemie) {
 if(frameX_Enemy > 3) {
    frameX_Enemy = 0;
  } 
  if(frameX_Enemy < 0) {
    frameX_Enemy = 3;
  }

  al_draw_bitmap_region(enemie->image, frameX_Enemy * 296, frameY_Enemy * 342, enemie->width, enemie->height, enemie->x, enemie->y, 0);
}

void drawBulletEnemies() {

  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    if (bullets_enemies[i].active) {
      al_draw_bitmap(bullets_enemies[i].image, bullets_enemies[i].x, bullets_enemies[i].y, 0);
    }
  }
}

void moveEnemie(struct Enemy *enemie) {
  if (rand() % 100 < 5) {
    enemie->direction = rand() % 4; // Ajustado para 4 direções
  }
  // 0 - left
  // 1 - right
  // 2 - up
  // 3 - down

  if (enemie->x < 0) {
    enemie->direction = 1;
  } else if (enemie->x > WIDTH_SCREEN - enemie->width) {
    enemie->direction = 0;
  } else if (enemie->y < 0) {
    enemie->direction = 3;
  } else if (enemie->y > HEIGHT_SCREEN - enemie->height) {
    enemie->direction = 2;
  }

  if (enemie->direction == 0) { // left
    if (enemie->x - enemie->width >= 0) {
      enemie->x -= enemie->speed;
      frameX_Enemy--;
    }
  } else if (enemie->direction == 1) { // right
    if (enemie->x + enemie->width + enemie->speed <= WIDTH_SCREEN) {
      enemie->x += enemie->speed;
      frameX_Enemy++;
    }
  } else if (enemie->direction == 2) { // up
    if (enemie->y + enemie->height >= HEIGHT_SCREEN - enemie->height + 200) {
      enemie->y -= enemie->speed;
      frameX_Enemy++;
    }
  } else if (enemie->direction == 3) { // down
    if (enemie->y + enemie->height + enemie->speed <= HEIGHT_SCREEN) {
      enemie->y += enemie->speed;
      frameX_Enemy--;
    }
  }
}

void shootBulletEnemy(struct Enemy *enemie) {
  double current_time = al_get_time();
  
  if (current_time - enemie->last_shoot < enemie->time_to_shoot || current_time - last_shoot < delay_shoot) {
    return;
  }

  enemie->last_shoot = current_time;
  last_shoot = current_time;
  enemie->time_to_shoot = rand() % 5 + 1;

  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    if (!bullets_enemies[i].active) {
      playSound(SHOOT_ENEMY);

      bullets_enemies[i].active = true;
      bullets_enemies[i].x = enemie->x + enemie->width / 2;
      bullets_enemies[i].y = enemie->y + enemie->height / 2 - 100;
      break;
    }
  }
}

void handlerEnemies() {
  for (int i = 0; i < ENEMIES_COUNT; i++) {
    if (!enemies[i].active) continue;

    drawEnemie(&enemies[i]);
    moveEnemie(&enemies[i]);
    shootBulletEnemy(&enemies[i]);
  }

  for (int i = 0; i < BULLETS_ENEMIES_COUNT; i++) {
    if (!bullets_enemies[i].active) continue;

    drawBulletEnemies();
    bullets_enemies[i].x += bullets_enemies[i].speed * -1;

    if (bullets_enemies[i].x > WIDTH_SCREEN || bullets_enemies[i].x < 0) {
      bullets_enemies[i].active = false;
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