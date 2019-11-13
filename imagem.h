#ifndef IMAGEM_H
#define IMAGEM_H

#include "pixel.h"

typedef struct imagem{
	int largura;
	int altura;
	pixel **pixel;
}PPM;

void lerArquivo(void);

void gerarImagem(PPM imagem, pixel pixel);

#endif
