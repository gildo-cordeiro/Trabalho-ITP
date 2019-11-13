#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"
#include "ponto.h"

typedef struct imagem{
	int largura;
	int altura;
	pixel pixel;
	pixel **mat;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

void desenharPonto(PPM imagem, ponto p);

#endif
