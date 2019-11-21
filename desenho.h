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
/**
 * Funcao: DesenharPonto
 * Parametros: 
 *  - imagem: matriz que possue as propriedades que foram lidas no arquivo externo; 
 *  - p: objeto do tipo ponto com as coordenadas (x,y) que o ponto possuira na matriz;
 * Retorno: valor da nova matriz que possue um ponto desenhado
 * descrição: funçaõ para desenhar um ponto e retorna um objeto do tiṕo imagem
 * 
 * */
PPM desenharPonto(PPM imagem, Ponto p){
    for (int i = 0; i < imagem.altura; i++){
        for (int j = 0; j < imagem.largura; j++){
            if ((p.x == i && p.y == j) && (p.x < imagem.altura && p.y < imagem.largura)){
                imagem.mat[i][j] = corPixel(255,255,255);
            }else{
                imagem.mat[i][j] = corPixel(imagem.pixel.red,imagem.pixel.green, imagem.pixel.blue);
            }           
        }        
    } 
    return imagem;
}
/**
 * Função: desenharLinha
 * Parametros: 
 *  - ponto1: recebe o primeiro com suas coordenadas x e y;
 *  - ponto2: recebe o segundo ponto com suas coordenadas x e y;
 *  - imagem: matriz que possue as propriedades que foram lidas no arquivo externo;
 * */
PPM desenharLinha(Ponto ponto1, Ponto ponto2, PPM imagem){
    /**
     * Recebendo 2 pontos para saber o tamanho da linha
     * Recebendo a imagem lida do arquivo txt externo e preenchendo sua  matriz com a linha
     * */
    
    int dx = ponto2.x - ponto1.x;
    int dy = ponto2.y - ponto1.y;
    int modulo = 0;  

    //printf("%d",dy);
    if(dx < 0){// caso ponto final < ponto inicial
        desenharLinha(ponto2, ponto1, imagem);
        return imagem;
    }
    //inclinição da reta de acordo com o eixo y
    if(dy < 0)
        modulo = -1;
    else
        modulo = 1;

    //variaveis auxiliares
    int d;

    //objeto pixel do tipo ponto e instanciando como ponto inicial
    Ponto pixel = ponto1;
    //printf("%d",imagem.pixel.blue);
    if(dx >= modulo*dy){
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

PPM desenharTriangulo(Ponto p1, Ponto p2, Ponto p3, PPM imagem){
    PPM image1, image2, image3;
    image1 = desenharLinha(p1, p2, imagem);
    image2 = desenharLinha(p2, p3, image1);
    image3 = desenharLinha(p3, p1, image2);
    return image3;
}

PPM desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4, PPM imagem){
    PPM image1, image2, image3, image4;
    
    image1 = desenharLinha(p1, p2, imagem);
    image2 = desenharLinha(p2, p3, image1);
    image3 = desenharLinha(p3, p4, image2);
    image4 = desenharLinha(p1, p4, image3);
    return image4;
}

void preencherForma(Pixel p, PPM imagem){
    printf("%d",getCor(p).red);
    
    //return imagem;
}

