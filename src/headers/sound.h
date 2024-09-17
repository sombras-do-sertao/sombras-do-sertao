#ifndef __SOUND_STATE__
#define __SOUND_STATE__

#include <allegro5/allegro_audio.h>
#include "helper.h"

typedef struct {
  char path[256];
  char name[256];
  int id;
} Sample;

#define MAX_SAMPLES 1
extern Sample samples[MAX_SAMPLES];

void playSound(struct AllegroGame *game, int sample_index);

void setupSamples(void);

#endif