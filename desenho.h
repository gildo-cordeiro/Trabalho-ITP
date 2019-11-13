#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"

void desenharPonto(PPM imagem, ponto p){
    for (int i = 0; i < imagem.altura; i++){
        for (int j = 0; j < imagem.largura; j++){
            if (p.x == i && p.y == j){
                imagem.mat[i][j] = corPixel(0,0,0);
            }else{
                imagem.mat[i][j] = corPixel(imagem.pixel.red,imagem.pixel.green, imagem.pixel.blue);
            }           
        }        
    }    
    gerarImagem(imagem);
}