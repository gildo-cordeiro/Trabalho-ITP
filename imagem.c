#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"

PPM lerArquivo(){  

    FILE *arquivo = fopen("arquivo.txt","r");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    PPM imagem;

    fscanf(arquivo, "image %d %d\ncolor %d %d %d\n", &imagem.altura, &imagem.largura, &imagem.pixel.red, &imagem.pixel.green, &imagem.pixel.blue);
    
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
            fprintf(arquivo,"%d %d %d\n", imagem.pixel.red, imagem.pixel.green, imagem.pixel.blue);
        }        
    }
    fclose(arquivo);   
}
