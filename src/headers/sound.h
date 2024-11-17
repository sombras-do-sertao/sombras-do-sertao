#ifndef __SOUND_STATE__
#define __SOUND_STATE__

#include <allegro5/allegro_audio.h>
#include "helper.h"

typedef struct {
  char path[256];
  char name[256];
  int id;
} Sample;

typedef enum {
  MENU_CLICK = 0,
  SHOOT = 1,
  SHOOT_ENEMY = 2,
  PICK_ITEM = 3,
} SampleIndex;

#define MAX_SAMPLES 4
extern Sample samples[MAX_SAMPLES];

void playSound(int sample_index);

void setupSamples(void);

#endif