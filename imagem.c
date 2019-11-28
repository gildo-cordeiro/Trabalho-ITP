#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"

PPM *lerArquivo(PPM *imagem)
{
    FILE *arquivo = fopen("arquivo.txt","r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char comando[10];
    int cont = 0;

    while (fscanf(arquivo, "%s", comando) != EOF)
    {
        if(strcmp(comando,"image") == 0)
        {
            fscanf(arquivo, "%d %d", &imagem->largura, &imagem->altura);

            //talvez usar o realloc
            imagem->ponto = (Ponto*)malloc(8 * sizeof(Ponto));
            imagem->pixel = (Pixel*)malloc(3 * sizeof(Pixel));

            imagem->mat = (Pixel**)malloc(imagem->altura * sizeof(Pixel*));
            for (int i = 0; i < imagem->altura; i++)
            {
                imagem->mat[i] = (Pixel*)malloc(imagem->largura * sizeof(Pixel));
            }

        }
        else if(strcmp(comando,"color") == 0)
        {
            fscanf(arquivo,"%d %d %d",&imagem->pixel[cont].red, &imagem->pixel[cont].green, &imagem->pixel[cont].blue);
            printf("contador  %d, red %d",cont,imagem->pixel[cont].red);
            cont++;
        }
        else if(strcmp(comando,"clean") == 0)
        {
            fscanf(arquivo, "%d %d %d", &imagem->clean.red, &imagem->clean.green, &imagem->clean.blue);
        }
        else if(strcmp(comando,"line") == 0)
        {
            fscanf(arquivo, "%d %d %d %d", &imagem->ponto[0].x, &imagem->ponto[0].y, &imagem->ponto[1].x, &imagem->ponto[1].y);

        }
        else if(strcmp(comando,"polygon") == 0)
        {
            fscanf(arquivo, "%d %d %d %d %d %d %d %d",&imagem->ponto[2].x, &imagem->ponto[2].y,&imagem->ponto[3].x, &imagem->ponto[3].y,
                   &imagem->ponto[4].x, &imagem->ponto[4].y,
                   &imagem->ponto[5].x, &imagem->ponto[5].y);

        }
        else if(strcmp(comando,"fill") == 0)
        {
            fscanf(arquivo, "%d %d", &imagem->ponto[6].x, &imagem->ponto[6].y);
        }
        else if(strcmp(comando,"circle") == 0)
        {
            fscanf(arquivo, "%d %d %d", &imagem->ponto[7].x, &imagem->ponto[7].y, &imagem->raio);

        }
        else if(strcmp(comando,"save") == 0)
        {
            imagem->save = (char*)malloc(11 * sizeof(char));
            fscanf(arquivo, "%s", imagem->save);
        }
    }

    fclose(arquivo);
    for (int i = 0; i < imagem->altura; i++)
    {
        for (int j = 0; j < imagem->largura; j++)
        {
            imagem->mat[i][j].red = imagem->pixel[0].red;
            imagem->mat[i][j].green = imagem->pixel[0].green;
            imagem->mat[i][j].blue = imagem->pixel[0].blue;
        }
    }
    return imagem;
}

void gerarImagem(PPM *imagem)
{
    FILE *arquivo = fopen(imagem->save,"w");
    if (arquivo == NULL)
    {
        printf("Erro ao criar arquivo");
        exit(1);
    }

    fprintf(arquivo,"P3\n%d %d\n255\n", imagem->largura, imagem->altura);
    for (int i = 0; i < imagem->altura; i++)
    {
        for (int j = 0; j < imagem->largura; j++)
        {
            fprintf(arquivo,"%d %d %d\n", imagem->mat[i][j].red, imagem->mat[i][j].green, imagem->mat[i][j].blue);
        }
    }

    fclose(arquivo);
}
