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
 * */
void desenharLinha(Ponto ponto1, Ponto ponto2){

    /**
     * Recebendo 2 pontos para saber o tamanho da linha
     * Recebendo a imagem lida do arquivo txt externo e preenchendo sua  matriz com a linha
     * */    
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
    //printf("%d",dy);
    /*if(dx < 0){// caso ponto final < ponto inicial
        desenharLinha(ponto2, ponto1);
        return ;
    }*/
    
    //variaveis auxiliares
    d = 2 * dy - dx;
    x = ponto1.x;
    y = ponto1.y;


    //objeto pixel do tipo ponto e instanciando como ponto inicial
    //Ponto pixel = ponto1;
    //printf("%d",imagem.pixel.blue);
    //printf("%d",imagem.mat[0][0].red);
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
    /*
    if(dx >= dy){
        printf("Aqui");
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
    imagem.mat[pixel.x][pixel.y] = corPixel(255,255,255);*/
}

void desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4){
    desenharLinha(p1, p2);
    desenharLinha(p2, p3);
    desenharLinha(p3, p4);
    desenharLinha(p1, p4);
    
}

void preencherForma(Ponto p, Pixel newColor){    
    if((p.x > imagem.altura || p.x < 0) && (p.y > imagem.largura || p.y < 0)){
        return ;
    }
    if (Equals(imagem.mat[p.x+1][p.y], corPixel(100,170,200)) == 1){
        while (Equals(imagem.mat[p.x][p.y], corPixel(255,255,255)) == 0){
            imagem.mat[p.x][p.y] = newColor;
        }        
    }
    

}

