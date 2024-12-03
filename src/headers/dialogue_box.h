#ifndef _DIALOGUE_STATE_
#define _DIALOGUE_STATE_

extern ALLEGRO_BITMAP *dialogue_box;
void setupDialogueBox();
void drawDialogueBox();
void dialogueBoxText(int stage);
void destroyDialogueBox();

#endif