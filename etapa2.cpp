#include "sfml.h"

int main() {
    //variaveis
        //tamanho da tela
    int xtela = 640, ytela = 480;
        //movimento
            //jogador
    float xj = 220, yj = 190, vj = 5;
            //inimigo
    float xi =220, yi = 190, vi = 5;
        //pulo
    bool pulo = false;
    float yp = 0;
    int contFrames = 0;

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
        if (sfml.keyIsDown(SFML::Key::Left)) {  //seta esquerda
            xj-=vj;
        }
        if (sfml.keyIsDown(SFML::Key::Right)) {   //seta direita
            xj+=vj;
        }
                //pulo
        if(sfml.keyIsDown(SFML::Key::Up) && pulo == false) {
            pulo = true;
            contFrames = 0;
        }
        if(pulo = true) {
            contFrames++;
            yp = 0.5*(contFrames)*(contFrames - 30);
            if(yp > 0) {
                pulo = false;
                yp = 0;
            }
        }
                //limites das extremidades
        if(xj>xtela){
            xj = -100;
        }
        if(xj<-100){
            xj = xtela;
        }
            //INIMIGO
        xi+=vi;
                //limites das extremidades
        if(xi>xtela){
            xi = -100;
        }
        if(xi<-100){
            xj = xtela;
        }

        //DESENHA PERSONAGENS --------------------------------------------
            //JOGADOR
        sfml.fill(155, 0, 0);
        sfml.ellipse(xj, yj+yp, 100, 100);
            //INIMIGO
        sfml.fill(115, 0, 0);
        sfml.ellipse(xi, yi, 100, 100);

        //mostra o conteúdo na janela
        sfml.display();



    }

    return 0;
}

