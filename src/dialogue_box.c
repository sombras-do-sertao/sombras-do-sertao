#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "headers/dialogue_box.h"
#include "headers/helper.h"
#include "headers/save.h"

ALLEGRO_BITMAP *dialogue_box;

void setupDialogueBox() {
  dialogue_box = al_load_bitmap("assets/images/addons/dialogue_box.png");
}

void dialogueBoxText(int text_num) {

  al_draw_text(GAME_INFO->font_big, AL_COLOR_WHITE, 660, 955, 0, "Narrador");

  switch (text_num) {
  case 0:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "A história de %s começa nas terras áridas e implacáveis do sertão nordestino, onde o sol queimava o solo e o vento sussurrava promessas de esperanças perdidas. Era o começo do século XX, e ele nasceu em meio à pobreza que dominava a vida de sua família. Seu lar, simples e humilde, mal oferecia o suficiente para sustentar os sonhos de uma infância que parecia condenada à dureza da terra seca. Cresceu ao lado do pai, em jornadas incansáveis de trabalho duro, buscando a subsistência nos bicos que surgiam esporadicamente, mas que, por mais que se esforçassem, raramente davam à família o que precisavam para viver com dignidade. A fome era constante e a miséria, uma sombra que jamais os deixava. Porém, o destino de %s",  GAME_INFO->save->name, GAME_INFO->save->name);
    
    al_draw_text(GAME_INFO->font, AL_COLOR_WHITE, 1000, 1019, 0, "PRESSIONE ESPAÇO");
    break;
  case 14: // Dialogo extra do stage 0
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "estava prestes a se modificar para sempre, e a mudança viria de uma forma que ele jamais poderia imaginar. Mundico, um amigo de infância, que até então compartilhava da mesma realidade dura e sem esperança, tomou um rumo inesperado e se uniu a um bando de bandidos, vivendo a adrenalina dos assaltos e a promessa de uma vida fora das limitações do sertão. Enquanto %s observava, uma chama de inquietação se acendeu dentro de seu peito. A vida que ele conhecia, a vida de luta constante e de escassez, parecia tão distante da liberdade selvagem que Mundico agora experimentava. Movido por um impulso que ele próprio não compreendia, %s fugiu de casa, decidido a seguir os passos de Mundico.", GAME_INFO->save->name, GAME_INFO->save->name);
    break;
  case 1:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "Após decidir seguir os passos de Mundico e provar seu valor, %s se junta ao bando para roubar uma das fazendas mais ricas da região. A fazenda é bem guardada, com cercas altas, cães de guarda e capangas armados. O plano é ousado, mas %s sabe que essa é sua chance de ganhar o respeito do grupo. Ele tem a missão de invadir o curral, liberar o gado e criar caos para distrair os seguranças. No entanto, ele logo percebe que, para realmente conquistar seu lugar no bando, precisa fazer algo mais audacioso e tomar a liderança da operação. Ele se arrisca ao confrontar o fazendeiro e mostrar sua coragem, desafiando o poder da fazenda e garantindo seu espaço entre os criminosos.", GAME_INFO->save->name, GAME_INFO->save->name);         
    break;
  case 3:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "Com o respeito conquistado após o roubo da fazenda, %s agora é visto de forma diferente pelos membros do bando. Ele já provou sua coragem, mas agora o próximo passo é mais arriscado: o assalto a um banco na cidade. O plano é grande e exige precisão, mais planejamento e maior habilidade. Mundico e os outros membros do bando começam a confiar mais em %s, que, com seu novo status, assume um papel mais ativo na elaboração da estratégia. O roubo ao banco será a verdadeira prova de seu valor, e todos sabem que, se falharem, as consequências serão graves.", GAME_INFO->save->name, GAME_INFO->save->name);
    break;
  case 5:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "Após o assalto bem-sucedido ao banco, %s e o bando de Mundico ganham notoriedade. Agora, com uma fama crescente e a polícia à caça deles, o grupo se torna mais audacioso, sabendo que precisam agir rapidamente antes que sejam capturados. O próximo passo é ainda mais ousado: roubar uma cidade inteira. A cidade, próspera e cheia de comerciantes ricos, se torna o alvo perfeito. O plano é grande e envolve mais gente, mais logística e mais riscos. %s, agora um membro fundamental do bando, cresce em seu papel, assumindo uma liderança mais ativa. Sua astúcia e coragem começam a brilhar, e ele não hesita em tomar decisões importantes. À medida que o bando se prepara para o assalto, %s sente que está não só", GAME_INFO->save->name, GAME_INFO->save->name, GAME_INFO->save->name);

    al_draw_text(GAME_INFO->font, AL_COLOR_WHITE, 1000, 1019, 0, "PRESSIONE ENTER");
    break;
  case 10: // Dialogo extra do stage 5
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "conquistando seu lugar no mundo dos criminosos, mas também se tornando um homem mais forte, mais imponente. O roubo à cidade será o teste definitivo. Agora, mais do que nunca, %s está em uma jornada de ascensão ao poder, e a sombra da perseguição policial só aumenta sua determinação.", GAME_INFO->save->name);
    break; 
  case 7:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "O bando de Mundico, agora com uma fama temida por todos, se vê cercado pela polícia em uma emboscada. Após a última ação ousada, a perseguição finalmente os alcançou. Em um local isolado, com a vegetação seca do sertão cobrindo os arredores, as opções de fuga são mínimas, e o destino do grupo está prestes a ser decidido. Com o som distante das sirenes e o cerco se fechando, o clima de tensão aumenta. Cada membro do bando sente o peso da última escolha. As balas começam a voar, e %s, agora no centro da ação, tem que agir rápido. O pânico poderia tomar conta, mas ele mantém a calma, já sabendo que cada movimento que fizer pode significar a diferença entre a vida e a morte.", GAME_INFO->save->name);
    break;
  case 9:
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "Após uma vida de escolhas erradas e uma jornada marcada pela violência e pela ganância, %s finalmente conseguiu escapar do destino fatal que parecia iminente. Fugindo das forças que o cercavam, você se perdeu pelo mundo, longe daquelas antigas paisagens do sertão que um dia chamaram sua casa. Foi uma fuga difícil, mas, ao olhar para trás, sentiu a certeza de que o preço que pagaria por suas ações não deveria ser pago com sua vida. Os anos passaram, e a estrada de redenção foi longa. O peso dos pecados, as memórias de cada erro, cada traição, o assalto e a violência, tudo isso ainda o acompanhava. Agora, depois de muitos anos, você não é mais aquele homem perdido no crime, mas um pastor que busca redenção. Suas palavras, embora", GAME_INFO->save->name);

    al_draw_text(GAME_INFO->font, AL_COLOR_WHITE, 1000, 1019, 0, "PRESSIONE ENTER");
    break;
  case 18: // Dialogo extra stage 9
    al_draw_multiline_textf(GAME_INFO->font, AL_COLOR_WHITE, 852, 713, 462, 20, 0, "marcadas pela experiência de uma vida dura, são agora um reflexo de um homem que, com coragem, escolheu mudar, buscar a paz e, através da fé, tentar corrigir os erros do passado.");
    break;
  default:
    break;
  }
}

void drawDialogueBox(int stage_text) {
  if(stage_text == 2 || stage_text == 4 || stage_text == 6 || stage_text == 8) return;
  al_draw_bitmap(dialogue_box, 511, 631, 0);
  dialogueBoxText(stage_text);
}

void destroyDialogueBox() {
  al_destroy_bitmap(dialogue_box);
}