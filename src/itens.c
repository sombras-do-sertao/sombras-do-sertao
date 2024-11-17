#include "itens/ammo.c"
#include "itens/health.c"

void handlerItens() {
  drawAmmoBoxes();
  collectAmmoBox();

  drawHealthBoxes();
  collectHealthBox();
}