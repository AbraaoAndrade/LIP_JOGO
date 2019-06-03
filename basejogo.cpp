#include "sfml.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include <cstring>

using namespace std;

int random( int, int); //FUNÇAO RANDOMICA

bool colisao( float, float, float, float, float, float, float, float, float, float, float, float); //FUNÇÃO DETECTA COLISÃO

int main() {


    //VARIAVEIS ---------------------------------------------------------------
        //TELA
    int xtela = 480, ytela = 640;
        //TEMPO
    float tt = 0;
    int tempo = 0;
    clock_t timer;
        //JOGADOR
            //posição
    float xj = 190, yj = 50, lj = 40, hj = 40;
                //(voar)
    bool asas = false;
    float click = 0, g = 800, a = 0, vjo = 0, yjo = 0;
        //INIMIGO
    int qt = 5, u = 0;
    float xi[qt], yi1[qt], yi2[qt], lxi[qt], lyi1[qt], lyi2[qt];
    float vi = 0.8, distmax = 250 + 90, distminx = 240 + 90, distminy = 130;
            //criando as primeiras coordenadas dos inimigos
    for ( int i = 0; i < qt; i++) {
        xi[i] = xtela + (i*290);
        lyi1[i] = random(50,ytela-140-60);
        lyi2[i] = ytela;
        lxi[i] = 90;
        yi1[i] = 0;
        yi2[i] = yi1[i] + lyi1[i] + 140;
    }
        //COLISAO
    int c = 0;
        //TELA
    int tela = 1;
    bool telinha = false;
        //TEXTO
    int n = 0, b = 0;
    char pontuacao[] = "PONTOS", nivel[] = "NIVEL : 1", gameover[] = "GAME OVER";
    char numero[200], pontos[200], nively[200];
    char nomejogo[] = "PIQUE PARDAL", start[] = "START";
        //NIVEL
    int nivelx = 1, sobe = 0;
        //BONUS
    bool bonus = false;
    int xb = xtela + 10, yb = 50, lb = 30, hb = 15, vb = 0;

    //CRIA A JANELA------------------------------------------------------------
    SFML sfml(xtela,ytela,"Meu jogo!");
    sfml.background(0,0,0);

    //LAÇO PRINCIPAL===========================================================
    while (sfml.windowIsOpen()) {
        sfml.clear(); //APAGA O CONTEUDO DA JANELA
        //MUDA TELAS
        if(tela == 5){
            tela = 1;
        }
        if(sfml.keyIsDown(SFML::Key::Enter) && telinha == false && tela!=2){
            tela++;
            telinha = true;
        }
        if(sfml.keyIsDown(SFML::Key::Enter) == false && telinha == true){
            telinha = false;
        }
    //TELA DE INICIO+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if(tela == 1){
            sfml.text(nomejogo, (xtela/2)-30, 300);
            sfml.text(start, (xtela/2)-15, 380);

        }
    //TELA DE CARREGAMENTO+++++++++++++++++++++++++++++++++++++++++++++++++++++
        if(tela == 2){
                cout << "oii " << endl;
                    //VARIAVEIS ---------------------------------------------------------------
                //TEMPO
            tt = 0;
            tempo = 0;
                //JOGADOR
                    //posição
            xj = 190, yj = 50, lj = 40, hj = 40;
                        //(voar)
            asas = false;
            click = 0, g = 800, a = 0, vjo = 0, yjo = 0;
                //INIMIGO
            qt = 5, u = 0;
            xi[qt], yi1[qt], yi2[qt], lxi[qt], lyi1[qt], lyi2[qt];
            vi = 0.8, distmax = 250 + 90, distminx = 240 + 90, distminy = 130;
                    //criando as primeiras coordenadas dos inimigos
            for ( int i = 0; i < qt; i++) {
                xi[i] = xtela + (i*290);
                lyi1[i] = random(50,ytela-140-60);
                lyi2[i] = ytela;
                lxi[i] = 90;
                yi1[i] = 0;
                yi2[i] = yi1[i] + lyi1[i] + 140;
            }
                //COLISAO
            c = 0;
                //NIVEL
            nivelx = 1;
            sobe = 0;
            bonus = false;
            xb = xtela + 10, yb = 50, lb = 30, hb = 15, vb = 0;

            tela++;

        }
    //TELA DE JOGO+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if(tela == 3){
            timer = clock(); //INICIO DO CONTADOR DE TEMPO



        //INIMIGOS VETORES --------------------------------------------------------
            //CONSTROI OS PRIMEIROS INIMIGOS
            for ( int i = 0; i < qt; i++) {
                sfml.fill(0, 90, 0);
                xi[i] = xi[i] - vi;

                sfml.rect(xi[i],yi1[i],lxi[i],lyi1[i]);
                sfml.rect(xi[i],yi2[i],lxi[i],lyi2[i]);
            }

            //CONSTROI OS PROXIMOS INIMIGOS(c/ caracteristicas diferentes/QND ELES ATRAVESSAM O LIMITE ESQUERDO DO CANVAS)
            if(xi[u]<0-lxi[u]){
                //selecionando qual inimigo atravessou o limite do canvas
                if(u == 0){
                    xi[u] = random(distminx,distmax) + xi[4];
                    lyi1[u] = random(50,ytela-140-80);
                    yi2[u] = yi1[u] + lyi1[u] + 140;
                }
                if(u == 1){
                    xi[u] = random(distminx,distmax) + xi[0];
                    lyi1[u] = random(50,ytela-140-80);
                    yi2[u] = yi1[u] + lyi1[u] + 140;
                }
                if(u == 2){
                    xi[u] = random(distminx,distmax) + xi[1];
                    lyi1[u] = random(50,ytela-140-80);
                    yi2[u] = yi1[u] + lyi1[u] + 140;
                }
                if(u == 3){
                    xi[u] = random(distminx,distmax) + xi[2];
                    lyi1[u] = random(50,ytela-140-80);
                    yi2[u] = yi1[u] + lyi1[u] + 140;
                }
                if(u == 4){
                    xi[u] = random(distminx,distmax) + xi[3];
                    lyi1[u] = random(50,ytela-140-80);
                    yi2[u] = yi1[u] + lyi1[u] + 140;
                }

                u++;
                if(u==qt){
                    u = 0;
                }
            }

            //MOVIMENTO -----------------------------------------------------------
                //JOGADOR
            a = g;
            if(yj < ytela - hj - 80){
                yj = yjo + (vjo*tt) + (a*pow(tt,2));
            }
                    //voar
           if(sfml.keyIsDown(SFML::Key::Up) && asas == false) {
                asas = true;
                tt = 0;
                yjo = yj;
                vjo = -480;
                if(yj > ytela - hj - 80){
                yj -= 5;
                }

            }
            if(sfml.keyIsDown(SFML::Key::Up) == false && asas == true){
                asas = false;
            }

            //COLISÃO--------------------------------------------------------------
            if(colisao(xj, yj, lj, hj, xi[c], yi2[c], lxi[c], lyi2[c], xi[c], yi1[c], lxi[c], lyi1[c]) == true){
                cout << "bateu" << " " << c << endl;
                tela = 1;
            }

            if(xi-lxi<xj){
                c++;
                if(c==qt){
                    c = 0;
                }
            }

            //TEXTO----------------------------------------------------------------
            if(xi[b]+lxi[b]<xj ){
                n++;
                b++;
                sobe++;
                if(b == qt){
                    b = 0;
                }
            }
            sprintf(numero,"%d",n);
            sprintf(nively,"%d",nivelx);
            sfml.fill(255,255,255);
            sfml.text(pontuacao, (xtela/2)-10, 100);
            sfml.text(nivel, xtela-90,15);
            sfml.text(numero, xtela/2,115);

            //NIVEL ---------------------------------------------------------------
            if(sobe>=2){
                sobe = 0;
                nivelx++;
                cout << nivelx << endl;
            }
            if(nivelx == 1){
                vi = 0.8, distmax = 250 + 90, distminx = 240 + 90, distminy = 130, g = 800;

            }
            if(nivelx == 2){
                vi = 1.5, distmax = 200 + 90, distminx = 190 + 90, distminy = 80, g = 850;

            }

            //POWERUP--------------------------------------------------------------
            xb-=vb;
            if(random(1,10) >= 1 && bonus == false){
                bonus = true;
            }
            if(bonus == true && vb==0){
                yb = random(0,ytela-hb-80);
                vb = vi + 3;
            }
            if(xb+lb < 0){
                xb = xtela + 10, yb = 50, lb = 30, hb = 15, vb = 0;
                bonus = false;
            }


            //DESENHA -------------------------------------------------------------
                //JOGADOR
            sfml.fill(155, 0, 0);
            sfml.rect(xj, yj, lj, hj);
                //CHAO
            sfml.fill(50, 0, 0);
            sfml.rect(0, 560, xtela, 80);
                //BONUS
            sfml.fill(155, 0, 0);
            sfml.rect(xb, yb, lb, hb);



            sfml.display(); //MOSTRA O CONTEUDO NA JANELA


            timer = clock() - timer;  //FIM DO CONTADOR DE TEMPO
            tt+=((float)timer)/CLOCKS_PER_SEC;
        }
    //GAMEOVER++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if(tela == 4){
            sfml.text(gameover, (xtela/2)-30, 300);
        }
        if(tela != 3){
            sfml.display(); //MOSTRA O CONTEUDO NA JANELA
        }

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
