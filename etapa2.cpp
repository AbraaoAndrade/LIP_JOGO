#include "sfml.h"

int main() {
    //variaveis
        //tamanho da tela
    int xtela = 640, ytela = 480;
        //movimento
    float xj = 220, yj = 190, xi = 370, yi =  190,v = 2;
            //pulo
    float puloy = 0, contframes = 0;
    bool pulo = false;




    //cria a janela com tamanho 640x480 pixels
    SFML sfml(xtela,ytela,"Meu jogo!");

    //define a cor de fundo como preto
    sfml.background(0,0,0);

    //início do laço principal do jogo
    while (sfml.windowIsOpen()) {

        //apaga o conteúdo da janela
        sfml.clear();

        //movimento
            //movimento inimigo
        xi+=v;
            //movimento por teclado jogador
        if (sfml.keyIsDown(SFML::Key::Left)) {  //seta esquerda
            xj-=v;
        }
        if (sfml.keyIsDown(SFML::Key::Right)) {   //seta direita
            xj+=v;
        }
                //pulo
        if(sfml.keyIsDown(SFML::Key::Up) && pulo == false){
            pulo = true;
            contframes = 0;
        }
        if(pulo == true){
            contframes++;
            puloy = 10*(contframes)*(contframes - 10.7308673997732);
            if(puloy>0){
                puloy = 0;
                pulo = false;
            }
        }

        //limites das extremidades
            //jogador
        if(xj>xtela){
            xj = -100;
        }
        if(xj<-100){
            xj = xtela;
        }
            //inimigo
        if(xi>xtela){
            xi = -100;
        }
        if(xi<-100){
            xi = xtela;
        }

        //desenha formas geometricas
            //quadrado
        sfml.fill(255, 0, 0);
        sfml.rect(xi, yi, 100, 100);
            //elipse
        sfml.fill(155, 0, 0);
        sfml.ellipse(xj, yj+puloy, 100, 100);

        //mostra o conteúdo na janela
        sfml.display();



    }

    return 0;
}
