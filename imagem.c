#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"

PPM imagem;
void lerArquivo(){  
    FILE *arquivo = fopen("arquivo.txt","r");
    if (arquivo == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char comando[10];

    while (fscanf(arquivo, "%s", comando) != EOF){
        if(strcmp(comando,"image") == 0){
            fscanf(arquivo, "%d %d", &imagem.largura, &imagem.altura); 

            imagem.ponto = (Ponto*)malloc(6 * sizeof(Ponto));
            
            imagem.mat = (Pixel**)malloc(imagem.largura * sizeof(Pixel*));    
            for (int i = 0; i < imagem.largura; i++){
                imagem.mat[i] = (Pixel*)malloc(imagem.altura * sizeof(Pixel));
            }

        }else if(strcmp(comando,"color") == 0){
            fscanf(arquivo,"%d %d %d",&imagem.pixel.red, &imagem.pixel.green, &imagem.pixel.blue);   

        }else if(strcmp(comando,"clean") == 0){
            //implementar
        }else if(strcmp(comando,"line") == 0){
            fscanf(arquivo, "%d %d %d %d", &imagem.ponto[0].x, &imagem.ponto[0].y, &imagem.ponto[1].x, &imagem.ponto[1].y);
        
        }else if(strcmp(comando,"polygon") == 0){
            fscanf(arquivo, "%d %d %d %d %d %d %d %d",&imagem.ponto[2].x, &imagem.ponto[2].y,&imagem.ponto[3].x, &imagem.ponto[3].y, 
                &imagem.ponto[4].x, &imagem.ponto[4].y,
                &imagem.ponto[5].x, &imagem.ponto[5].y);

        }else if(strcmp(comando,"fill") == 0){
            //implementar        
        }else if(strcmp(comando,"save") == 0){
            imagem.save = (char*)malloc(11 * sizeof(char));
            fscanf(arquivo, "%s", imagem.save);
        }
    }       
    for (int i = 0; i < imagem.largura; i++){
        for (int j = 0; j < imagem.altura; j++){
            imagem.mat[i][j].red = imagem.pixel.red;
            imagem.mat[i][j].green = imagem.pixel.green;
            imagem.mat[i][j].blue = imagem.pixel.blue;
        }        
    }    
    fclose(arquivo);
}

void gerarImagem(){
    FILE *arquivo = fopen(imagem.save,"w");
    if (arquivo == NULL){
        printf("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(arquivo,"P3\n%d %d\n255\n", imagem.altura, imagem.largura);
    for (int i = 0; i < imagem.largura; i++){
        for (int j = 0; j < imagem.altura; j++){
            fprintf(arquivo,"%d %d %d\n", imagem.mat[i][j].red, imagem.mat[i][j].green, imagem.mat[i][j].blue);
        }        
    }
    
    fclose(arquivo);
    for (int i = 0; i < imagem.largura; i++){
        free(imagem.mat[i]);
    }   
    free(imagem.mat);
    free(imagem.ponto);
    free(imagem.save);
}
