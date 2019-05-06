#include "sfml.h"

int main() {

    //cria a janela com tamanho 640x480 pixels
    SFML sfml(640,480,"Meu jogo!");

    //define a cor de fundo como preto
    sfml.background(0,0,0);

    //variaveis
        //movimento por teclado
    float x = 220, y = 190, v = 5;

    //início do laço principal do jogo
    while (sfml.windowIsOpen()) {

        //apaga o conteúdo da janela
        sfml.clear();

        //movimento por teclado
        if (sfml.keyIsDown(SFML::Key::Left)) {  //seta esquerda
            x-=v;
        } else if (sfml.keyIsDown(SFML::Key::Right)) {   //seta direita
            x+=v;
        } else if (sfml.keyIsDown(SFML::Key::Up)) {   //seta cima
            y-=v;
        } else if (sfml.keyIsDown(SFML::Key::Down)) {   //seta baixo
            y+=v;
        }

        //desenha formas geometricas
            //quadrado
        sfml.fill(255, 0, 0);
        sfml.rect(320+50, 240-50, 100, 100);
            //elipse
        sfml.fill(155, 0, 0);
        sfml.ellipse(x, y, 100, 100);

        //mostra o conteúdo na janela
        sfml.display();



    }

    return 0;
}
