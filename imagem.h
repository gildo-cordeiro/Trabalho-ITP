#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"
#include "ponto.h"

typedef struct imagem{
	int largura, altura;
	char *save;	
	Pixel pixel;
	Pixel **mat;
	Ponto *ponto;
}PPM;

void lerArquivo();

void gerarImagem();

#endif
