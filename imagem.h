#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"
#include "ponto.h"

typedef struct imagem{
	int largura, altura;	
	Pixel pixel;
	Pixel **mat;
	Ponto *ponto;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

#endif
