#include "sfml.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>

using namespace std;

int random( int, int); //FUNÇAO RANDOMICA

bool colisao( float, float, float, float, float, float, float, float, float, float, float, float); //FUNÇÃO DETECTA COLISÃO

int main() {


    //VARIAVEIS ---------------------------------------------------------------
        //TELA
    int xtela = 480, ytela = 500;
        //TEMPO
    float tt = 0;
    int tempo = 0;
    clock_t timer;
        //JOGADOR
            //posição
    float xj = 220, yj = 50, lj = 25, hj = 25, esx = 25, esy = 25;
                //(voar)
    bool asas = false;
    float click = 0, g = 500, a = 0, vjo = 0, yjo = 0;
        //INIMIGO
    int qt = 5, u = 0;
    float xi[qt], yi1[qt], yi2[qt], lxi[qt], lyi1[qt], lyi2[qt];
    float vi = 1, distmax = 300;
            //criando as primeiras coordenadas dos inimigos
    for ( int i = 0; i < qt; i++) {
        xi[i] = xtela + (i*200);
        lyi1[i] = random(50,ytela-50);
        lyi2[i] = ytela;
        lxi[i] = 30;
        yi1[i] = 0;
        yi2[i] = yi1[i] + lyi1[i] + random(50,100);
    }
        //COLISAO
    int c = 0;

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
            sfml.fill(19, 32, 30);
            xi[i] = xi[i] - vi;

            sfml.rect(xi[i],yi1[i],lxi[i],lyi1[i]);
            sfml.rect(xi[i],yi2[i],lxi[i],lyi2[i]);
        }

        //CONSTROI OS PROXIMOS INIMIGOS(c/ caracteristicas diferentes/QND ELES ATRAVESSAM O LIMITE ESQUERDO DO CANVAS)
        if(xi[u]<0-lxi[u]){
            //selecionando qual inimigo atravessou o limite do canvas
            if(u == 0){
                xi[u] = random(lxi[u]+lj+esx,distmax) + xi[4];
                lyi1[u] = random(50,ytela-50);
                yi2[u] = yi1[u] + lyi1[u] + random(lj+esy,100);
            }
            if(u == 1){
                xi[u] = random(lxi[u]+lj+esx,distmax) + xi[0];
                lyi1[u] = random(50,ytela-50);
                yi2[u] = yi1[u] + lyi1[u] + random(lj+esy,100);
            }
            if(u == 2){
                xi[u] = random(lxi[u]+lj+esx,distmax) + xi[1];
                lyi1[u] = random(50,ytela-50);
                yi2[u] = yi1[u] + lyi1[u] + random(lj+esy,100);
            }
            if(u == 3){
                xi[u] = random(lxi[u]+lj+esx,distmax) + xi[2];
                lyi1[u] = random(50,ytela-50);
                yi2[u] = yi1[u] + lyi1[u] + random(lj+esy,100);
            }
            if(u == 4){
                xi[u] = random(lxi[u]+lj+esx,distmax) + xi[3];
                lyi1[u] = random(50,ytela-50);
                yi2[u] = yi1[u] + lyi1[u] + random(lj+esy,100);
            }

            u++;
            if(u==qt){
                u = 0;
            }
        }

        //MOVIMENTO -----------------------------------------------------------
            //JOGADOR
        a = g;
        if(yj < ytela - hj){
            yj = yjo + (vjo*tt) + (a*pow(tt,2));
        }
                //voar
       if(sfml.keyIsDown(SFML::Key::Up) && asas == false) {
            asas = true;
            tt = 0;
            yjo = yj;
            vjo = -400;
            if(yj > ytela - hj){
            yj -= 5;
            }

        }
        if(sfml.keyIsDown(SFML::Key::Up) == false && asas == true){
            asas = false;
        }

        //COLISÃO--------------------------------------------------------------
        if(colisao(xj, yj, lj, hj, xi[c], yi2[c], lxi[c], lyi2[c], xi[c], yi1[c], lxi[c], lyi1[c]) == true){
            cout << "bateu" << " " << c << endl;
            sfml.background(76,0,0);
        }else{
            sfml.background(0,0,0);
        }

        if(xi-lxi<xj){
            c++;
            if(c==qt){
                c = 0;
            }
        }


        //DESENHA -------------------------------------------------------------
            //JOGADOR
        sfml.fill(155, 0, 0);
        sfml.rect(xj, yj, lj, hj);


        sfml.display(); //MOSTRA O CONTEUDO NA JANELA


        timer = clock() - timer;  //FIM DO CONTADOR DE TEMPO
        tt+=((float)timer)/CLOCKS_PER_SEC;
    }


    return 0;
}


int random(int menor, int maior) {
       return rand()%(maior-menor+1) + menor;
}

bool colisao(float xj,float yj,float lj,float hj, float xi1, float yi1, float li1, float hi1, float xi2, float yi2, float li2, float hi2){
    if(yj+hj>yi1 && yj<yi1+hi1 && xj+lj>xi1 && xj<xi1+li1 || yj+hj>yi2 && yj<yi2+hi2 && xj+lj>xi2 && xj<xi2+li2){return true;}
    else{return false;}
}
