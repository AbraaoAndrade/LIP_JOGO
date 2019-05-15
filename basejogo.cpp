#include "sfml.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;

int random( int, int); //FUNÇAO RANDOMICA

int main() {


    //VARIAVEIS ---------------------------------------------------------------
        //TELA
    int xtela = 680, ytela = 480;
        //TEMPO
    float tt = 0;
    int tempo = 0;
    clock_t timer;
        //JOGADOR
            //posição
    float xj = 220, yj = 50;
                //(voar)
    bool asas = false;
    float click = 0, g = 500, a = 0, vjo = 0, yjo = 0;
        //INIMIGO
    int qt = 5, u = 0;
    float xi[qt], yi1[qt], yi2[qt], lxi[qt], lyi1[qt], lyi2[qt];
    float vi = 2;
            //criando as primeiras coordenadas dos inimigos
    for ( int i = 0; i < qt; i++) {
        xi[i] = xtela + (i*200);
        lyi1[i] = random(50,ytela-50);
        lyi2[i] = ytela;
        lxi[i] = 30;
        yi1[i] = 0;
        yi2[i] = yi1[i] + lyi1[i] + random(50,100);
    }

    //CRIA A JANELA------------------------------------------------------------
    SFML sfml(xtela,ytela,"Meu jogo!");
    sfml.background(0,0,0);

    //LAÇO PRINCIPAL===========================================================
    while (sfml.windowIsOpen()) {
        timer = clock(); //INICIO DO CONTADOR DE TEMPO

        sfml.clear(); //APAGA O CONTEUDO DA JANELA

    //INIMIGOS VETORES --------------------------------------------------------
        //CONSTROI OS PRIMEIROS INIMIGOS
    for ( int i = 0; i < qt; i++) {
        sfml.fill(155, 0, 30);
        xi[i] = xi[i] - vi;

        sfml.rect(xi[i],yi1[i],lxi[i],lyi1[i]);
        sfml.rect(xi[i],yi2[i],lxi[i],lyi2[i]);
    }

    //CONSTROI OS PROXIMOS INIMIGOS(c/ caracteristicas diferentes/QND ELES ATRAVESSAM O LIMITE ESQUERDO DO CANVAS)
    if(xi[u]<-30){
        //selecionando qual inimigo atravessou o limite do canvas
        if(u == 0){
            xi[u] = random(lxi[u],xtela) + xi[4];
            lyi1[u] = random(50,ytela-50);
            yi2[u] = yi1[u] + lyi1[u] + random(50,100);
        }
        if(u == 1){
            xi[u] = random(lxi[u],xtela) + xi[0];
            lyi1[u] = random(50,ytela-50);
            yi2[u] = yi1[u] + lyi1[u] + random(50,100);
        }
        if(u == 2){
            xi[u] = random(lxi[u],xtela) + xi[1];
            lyi1[u] = random(50,ytela-50);
            yi2[u] = yi1[u] + lyi1[u] + random(50,100);
        }
        if(u == 3){
            xi[u] = random(lxi[u],xtela) + xi[2];
            lyi1[u] = random(50,ytela-50);
            yi2[u] = yi1[u] + lyi1[u] + random(50,100);
        }
        if(u == 4){
            xi[u] = random(lxi[u],xtela) + xi[3];
            lyi1[u] = random(50,ytela-50);
            yi2[u] = yi1[u] + lyi1[u] + random(50,100);
        }

        u++;
        if(u==qt){
            u = 0;
        }
    }

        //MOVIMENTO -----------------------------------------------------------
            //JOGADOR
        a = g;
        if(yj < ytela - 50){
            yj = yjo + (vjo*tt) + (a*pow(tt,2));
        }
                //voar
       if(sfml.keyIsDown(SFML::Key::Up) && asas == false) {
            asas = true;
            tt = 0;
            yjo = yj;
            vjo = -400;
            if(yj > ytela - 50){
            yj -= 5;
            }

        }
        if(sfml.keyIsDown(SFML::Key::Up) == false && asas == true){
            asas = false;
        }


        //DESENHA -------------------------------------------------------------
            //JOGADOR
        sfml.fill(155, 0, 0);
        sfml.ellipse(xj, yj, 50, 50);


        sfml.display(); //MOSTRA O CONTEUDO NA JANELA


        timer = clock() - timer;  //FIM DO CONTADOR DE TEMPO
        tt+=((float)timer)/CLOCKS_PER_SEC;
    }


    return 0;
}


int random(int menor, int maior) {
       return rand()%(maior-menor+1) + menor;
}
