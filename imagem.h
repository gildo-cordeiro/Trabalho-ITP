#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"

typedef struct imagem{
	int largura;
	int altura;
	Pixel pixel;
	Pixel **mat;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

#endif
