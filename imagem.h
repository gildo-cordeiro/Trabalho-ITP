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
	Pixel clean;
	int raio;
}PPM;

PPM lerArquivo();

void gerarImagem(PPM imagem);

void verificarVertcesQuadrado(Ponto p1, Ponto p2, Ponto p3,  Pixel newColor);

#endif
