#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"
#include "linha.h"

typedef struct imagem{
	int largura, altura;	
	Pixel pixel, clear;
	Linha linha;
	Pixel **mat;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

#endif
