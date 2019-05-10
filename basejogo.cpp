#include "sfml.h"
#include<iostream>


using namespace std;

int main() {


    //variaveis
        //tamanho da tela
    int xtela = 640, ytela = 480;
        //movimento
            //jogador
    float xj = 220, yj = 50;
                //(voar)
    bool asas = false;
    float contFrames = 0, g = 4, f = 0, a = 0;

    //cria a janela com tamanho 640x480 pixels
    SFML sfml(xtela,ytela,"Meu jogo!");

    //define a cor de fundo como preto
    sfml.background(0,0,0);

    //início do laço principal do jogo
    while (sfml.windowIsOpen()) {

        //apaga o conteúdo da janela
        sfml.clear();

        //MOVIMENTO -----------------------------------------------------
            //JOGADOR
        if(yj<430-70){
            a = g + f;
        }else{
            a = 0;
        }
        yj+=a;
                //voar
       if(sfml.keyIsDown(SFML::Key::Up) && asas == false) {
            asas = true;
            contFrames = 0;
        }
        if(asas = true) {
            contFrames++;
            f = -10;
            if(contFrames > 50) {
                asas = false;
                f = 0;
            }
        }

        //DESENHA ----------------------------------------------
            //CHAO
        sfml.fill(155, 200, 0);
        sfml.rect(0, 430, 640, 100);
            //JOGADOR
        sfml.fill(155, 0, 0);
        sfml.ellipse(xj, yj, 100, 100);


        //mostra o conteúdo na janela
        sfml.display();

    }

    return 0;
}
