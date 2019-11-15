#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"

PPM lerArquivo(){  
    FILE *arquivo = fopen("arquivo.txt","r");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    PPM imagem;

    fscanf(arquivo, "image %d %d\n", &imagem.altura, &imagem.largura);

    for (int i = 0; i < imagem.altura; i++){
        for (int j = 0; j < imagem.largura; j++){
            fscanf(arquivo,"color %d %d %d\n",&imagem.pixel.red, &imagem.pixel.green, &imagem.pixel.blue);
        }        
    }
     
    imagem.mat = (Pixel**)malloc(imagem.altura * sizeof(Pixel*));    
    for (int i = 0; i < imagem.altura; i++){
        imagem.mat[i] = (Pixel*)malloc(imagem.largura * sizeof(Pixel));
    }
    fclose(arquivo);  

    return imagem;
}

void gerarImagem(PPM imagem){
    FILE *arquivo = fopen("arquivo.ppm","w");
    if (arquivo == NULL){
        printf("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(arquivo,"P3\n%d %d\n255\n", imagem.altura, imagem.largura);
    for (int i = 0; i < imagem.altura; i++){
        for (int j = 0; j < imagem.largura; j++){
            if(imagem.mat[i][j].red == 0){
                fprintf(arquivo,"%d %d %d\n", imagem.pixel.red, imagem.pixel.green, imagem.pixel.blue);
            }else{
                fprintf(arquivo,"%d %d %d\n", imagem.mat[i][j].red, imagem.mat[i][j].green, imagem.mat[i][j].blue);
            }
        }        
    }
    fclose(arquivo);

    for (int i = 0; i < imagem.altura; i++){
        free(imagem.mat[i]);
    }   
    free(imagem.mat);
}
