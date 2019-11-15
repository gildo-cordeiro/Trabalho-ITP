#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"
#include "linha.h"

int sign(int x){
    if (x > 0){
        return 1;
    } else if (x < 0){
        return -1;
    }
    return 0; 
}

PPM desenharPonto(PPM imagem, Ponto p){
    for (int i = 0; i < imagem.altura; i++){
        for (int j = 0; j < imagem.largura; j++){
            if (p.x == i && p.y == j){
                imagem.mat[i][j] = corPixel(255,255,255);
            }else{
                imagem.mat[i][j] = corPixel(imagem.pixel.red,imagem.pixel.green, imagem.pixel.blue);
            }           
        }        
    }    
    return imagem;
}
PPM desenharLinha(Linha linha, PPM imagem){
    int dx, dy, x, y, d, s1, s2, swap = 0, temp;
    dx = abs(linha.x2 - linha.x1);
    dy = abs(linha.y2 - linha.y1);
    s1 = sign(linha.x2 - linha.x1);
    s2 = sign(linha.y2 - linha.y1);

    /* Check if dx or dy has a greater range */
    /* if dy has a greater range than dx swap dx and dy */
    if(dy > dx){
        temp = dx; 
        dx = dy; 
        dy = temp; 
        swap = 1;
    }
    /* Set the initial decision parameter and the initial point */
    d = 2 * dy - dx;
    x = linha.x1;
    y = linha.y1;
    for(int i = 1; i <= dx; i++) {
        
        imagem.mat[x][y] = corPixel(255,255,255);
        // setPixel(x,y,'*');
        
        while(d >= 0) {
            if(swap){
                x = x + s1;
            } else {
                y = y + s2;
                d = d - 2* dx;
            }
        }
        if(swap) {
            y = y + s2;
        }else{
            x = x + s1;
            d = d + 2 * dy;
        }
    }
    imagem.mat[x][y] = corPixel(255,255,255);
    return imagem;
    //setPixel(x,y,'*');
}
