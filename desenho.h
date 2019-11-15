#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"

int sign(int x){
    if (x > 0){
        return 1;
    } else if (x < 0){
        return -1;
    }
    return 0; 
}

PPM desenharPonto(PPM imagem, Ponto p){
    for (int i = 0; i < imagem.largura; i++){
        for (int j = 0; j < imagem.altura; j++){
            if ((p.x == i && p.y == j) && (p.x < imagem.altura && p.y < imagem.largura)){
                imagem.mat[i][j] = corPixel(255,255,255);
            }else{
                imagem.mat[i][j] = corPixel(imagem.pixel.red,imagem.pixel.green, imagem.pixel.blue);
            }           
        }        
    }    
    return imagem;
}
PPM desenharLinha(Ponto ponto1, Ponto ponto2, PPM imagem){
    /**
     * Recebendo 2 pontos para saber o tamanho da linha
     * Recebendo a imagem lida do arquivo txt externo e preenchendo sua  matriz com a linha
     * */
    int dx = ponto2.x - ponto1.x;
    int dy = ponto2.y - ponto1.y;
    int inclinacao=0;  

    if(dx < 0){// caso ponto final < ponto inicial
        //recursão
        desenharLinha(ponto2, ponto1, imagem);
        imagem.mat[ponto1.x][ponto1.y] = corPixel(255,255,255);
        return imagem;
    }
    //inclinição da reta de acordo com o eixo y
    if(dy < 0)
        inclinacao = -1;
    else
        inclinacao = 1;

    //variaveis auxiliares
    int incE, incNE, d;

    //objeto pixel do tipo ponto e instanciando como ponto inicial
    Ponto pixel = ponto1;
    imagem.mat[ponto1.x][ponto1.y] = corPixel(255,255,255);
    
    if(dx >= inclinacao*dy){
        if(dy < 0){// caso y2 < y1
            d = 2 * dy + dx;
            while(pixel.x < ponto2.x){
                if(d < 0){
                    d += 2*(dy+dx);
                    pixel.x++;
                    pixel.y--;
                }else{
                    d += 2 * dy;
                    pixel.x++; // varia apenas no eixo x
                }
                imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);
            }
        }else{ // caso y1 < y2
            d = 2 * dy - dx;
            while(pixel.x < ponto2.x){
                if(d < 0){ // escolhido é o I
                    d += 2 * dy;
                    pixel.x++; // varia apenas no eixo x
                }else{ // escolhido é o S
                    d += 2 * (dy - dx);
                    pixel.x++;
                    pixel.y++;
                }
                imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);
            }
        }
    }else{
        if(dy < 0){ // caso y2 < y1
            d = dy + 2*dx;
            while(pixel.y > ponto2.y){
                if(d < 0){
                    d += 2 * dx;
                    pixel.y--; // varia apenas no eixo y
                }
                else{
                    d += 2 * (dy + dx);
                    pixel.x++;
                    pixel.y--;
                }
            imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);
            }
        }else{ // caso y1 < y2
            d = dy - 2 * dx;
            while(pixel.y < ponto2.y){
                if(d < 0){
                    d += 2 * (dy - dx);
                    pixel.x++;
                    pixel.y++;
                }else{
                    d += -2 * dx;
                    pixel.y++; // varia apenas no eixo y
                }
                imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);
            }
        }
    }
    imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);
    return imagem;
}

