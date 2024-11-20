#include "headers/colision.h"
#include "headers/protagonista.h"
#include "headers/itens.h"
#include "headers/helper.h"

bool colision_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
  bool is_same_x = x1 < x2 + w2 && x1 + w1 > x2;

  bool is_same_y = y1 < y2 + h2 && y1 + h1 > y2;

  return is_same_x && is_same_y;
}

bool colision_bullet_in_enemy(struct BulletProtagonista *bullet, struct Enemy *enemy) {
  return colision_rect(bullet->x, bullet->y, bullet->width, bullet->height, enemy->x, enemy->y, enemy->width, enemy->height);
}

bool colision_bullet_in_protagonista(struct BulletEnemy *bullet, struct Protagonista *protagonista) {
  return colision_rect(bullet->x, bullet->y, bullet->width, bullet->height, protagonista->x, protagonista->y, protagonista->width, protagonista->height);
}

bool colision_ammoBox_in_protagonista(struct AmmoBox *ammo_box, struct Protagonista *protagonista) {  
  return colision_rect(ammo_box->x, ammo_box->y, ammo_box->width, ammo_box->height, protagonista->x, protagonista->y, protagonista->width / 2, protagonista->height);
}

bool colision_healthBox_in_protagonista(struct HealthBox *health_box, struct Protagonista *protagonista) {
  return colision_rect(health_box->x, health_box->y, health_box->width, health_box->height, protagonista->x, protagonista->y, protagonista->width / 2, protagonista->height);
}

bool colision_protagonista_in_enemy(struct Protagonista *protagonista, struct Enemy *enemy) {
  return colision_rect(protagonista->x, protagonista->y, protagonista->width, protagonista->height, enemy->x, enemy->y, enemy->width, enemy->height);
}