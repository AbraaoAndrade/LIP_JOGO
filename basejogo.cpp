#include "sfml.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;

int main() {


    //VARIAVEIS ---------------------------------------------------------------
        //TAMANHO DA TELA
    int xtela = 680, ytela = 680;
        //CONTADOR DE TEMPO
    float tt = 0;
    int tempo = 0;
    clock_t timer;
        //MOVIMENTO
            //jogador
    float xj = 220, yj = 50;
                //(voar)
    bool asas = false;
    float click = 0, g = 500, a = 0, vo = 0, yjo = 0;




    //CRIA A JANELA------------------------------------------------------------
    SFML sfml(xtela,ytela,"Meu jogo!");
    sfml.background(0,0,0);

    //LAÇO PRINCIPAL===========================================================
    while (sfml.windowIsOpen()) {
        //inicio do contador de tempo
        timer = clock();

        //apaga o conteúdo da janela
        sfml.clear();

        //MOVIMENTO -----------------------------------------------------------
            //JOGADOR
        a = g;
        if(yj < ytela - 50){
            yj = yjo + (vo*tt) + (a*pow(tt,2));
        }
                //voar
       if(sfml.keyIsDown(SFML::Key::Up) && asas == false) {
            asas = true;
            tt = 0;
            yjo = yj;
            vo = -400;
            if(yj > ytela - 50){
            yj -= 5;
            }

        }
        if(sfml.keyIsDown(SFML::Key::Up) == false && asas == true){
            asas = false;
        }
        
            //OBSTACULOS
        

        //DESENHA -------------------------------------------------------------
            //JOGADOR
        sfml.fill(155, 0, 0);
        sfml.ellipse(xj, yj, 50, 50);
            //OBSTACULOS
        


        //mostra o conteúdo na janela
        sfml.display();

        //fim do contador de tempo
        timer = clock() - timer;
        tt+=((float)timer)/CLOCKS_PER_SEC;
    }

    return 0;
}
