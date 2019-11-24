#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"
#include <math.h>

int sign(int x){
    if (x > 0){
        return 1;
    } else if (x < 0){
        return -1;
    }
    return 0; 
}
PPM imagem;

/**
 * Função: desenharLinha
 * Parametros: 
 *  - ponto1: recebe o primeiro com suas coordenadas x e y;
 *  - ponto2: recebe o segundo ponto com suas coordenadas x e y;
 *  - imagem: matriz que possue as propriedades que foram lidas no arquivo externo;
 * Retorno: void
 * Descrição: Função para desenhar uma linha com ponto inicial e final especificados na iamgem (matriz)
 * */
void desenharLinha(Ponto ponto1, Ponto ponto2){    
    int dx, dy, x, y, d, s1, s2, swap=0, temp;

    dx = abs(ponto2.x - ponto1.x);
    dy = abs(ponto2.y - ponto1.y);  
    s1 = sign(ponto2.x - ponto1.x);
    s2 = sign(ponto2.y - ponto1.y);

    if(dy > dx){
        temp = dx; 
        dx = dy; 
        dy = temp; 
        swap = 1;
    }
    
    //variaveis auxiliares
    d = 2 * dy - dx;
    x = ponto1.x;
    y = ponto1.y;

    for(int i = 1; i <= dx; i++) {
        imagem.mat[y][x] = corPixel(255,255,255);
        //printf("x %d\n", x);
        //printf("y %d\n", y);
        
        while(d >= 0) {
        if(swap){
            x = x + s1;
        } else {
            y = y + s2;
            d = d - 2* dx;
        }
        }
        if(swap) y = y + s2;
        else x = x + s1;
        d = d + 2 * dy;
    }
    imagem.mat[y][x] = corPixel(255,255,255);
}
/**
 * Função: desenharPloigono;
 * Parametros: 
 *  - p1: primeiro ponto do poligono;
 *  - p2: segundo ponto do poligono;
 *  - p3: terceiro ponto do poligono;
 *  - p4: quarto ponto do poligono;
 * Retorno: void
 * Descrição: Função para desenhar um poligono com posições especificas na iamgem (matriz)
 * */
void desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4){
    desenharLinha(p1, p2);
    desenharLinha(p2, p3);
    desenharLinha(p3, p4);
    desenharLinha(p1, p4);
    
}

/**
 * Função: preencherForma;
 * Parametros: 
 *  - y: posição y do ponto por onde iniciará o preenchimento de cor;
 *  - x: posição x do ponto por onde iniciará o preenchimento de cor;
 *  - newColor: nova cor que irá substituir a antiga cor;
 * Retorno: void
 * Descrição: Função para para preecher todo o espaço da imagem onde o ponto foi especificado. A função não deverá 
 *  pintar dentro da figura caso o ponto especificado seja fora da mesma.
 * */
void preencherForma(int y, int x, Pixel newColor){  
    if((y < imagem.largura || y < imagem.altura) && (x < imagem.altura || x < imagem.largura)){    
        if (Equals(imagem.mat[y][x], corPixel(100,170,200)) == 1){

            imagem.mat[y][x] = newColor;

            preencherForma(y+1, x, corPixel(255,0,0));
            preencherForma(y-1, x, corPixel(255,0,0));
            preencherForma(y, x+1, corPixel(255,0,0));
            preencherForma(y, x-1, corPixel(255,0,0));

        }
    }
}

/**
 * Função: circlePoints;
 * Parametros: 
 *  - p: ponto inicial por onde iniciará o desenho do circulo;
 *  - color: cor da linha do circulo;
 * Retorno: void
 * Descrição: Função recursiva para incrementar as coordenadas x e y nas direções sul, norte, leste e oeste
 **/
void CirclePoints(Ponto p, Pixel color){
    imagem.mat[p.x][p.y] =  color;
    imagem.mat[p.x][-p.y] = color;
    imagem.mat[-p.x][p.y] = color;
    imagem.mat[-p.x][-p.y] = color;
    imagem.mat[p.y][p.x] = color;
    imagem.mat[p.y][-p.x] = color;
    imagem.mat[-p.y][p.x] = color;
    imagem.mat[-p.y][-p.x] = color;
}
/**
 * Função: desenharCirculo;
 * Parametros: 
 *  - radius: tamanho do raio do circulo;
 *  - value: cor da linha do circulo;
 * Retorno: void
 * Descrição: Função para desenhar um circulo a partir do valor do raio especificado
 * */
void desenharCirculo(int radius, Pixel value){
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    CirclePoints(definirPonto(x, y), value);
    while(y > x) {
        if (d < 0){
            d += 2 * x + 3;
        }else {
            d += 2 * (x - y) + 5;
            y--;
        }
    }
    x++;
    CirclePoints(definirPonto(x, y), value);
}

