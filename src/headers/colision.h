#ifndef _COLISION_STATE_
#define _COLISION_STATE_

#include "protagonista.h"
#include "helper.h"
#include "enemies.h"
#include <stdbool.h>

bool colision_rect(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

bool colision_bullet_in_enemy(struct BulletProtagonista *bullet, struct Enemy *enemy);

bool colision_bullet_in_protagonista(struct BulletEnemy *bullet, struct Protagonista *protagonista);

bool colision_bullet_in_protagonista(struct BulletEnemy *bullet, struct Protagonista *protagonista);

#endif