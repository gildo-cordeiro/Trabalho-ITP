#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"

typedef struct imagem{
	int largura;
	int altura;
	pixel pixel;
	pixel **mat;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

#endif
