#ifndef PONTO_H
#define PONTO_H

#include "pixel.h"

typedef struct ponto{
	int x, y;
	Pixel RGB;
}Ponto;

int valorX (Ponto p);

int valorY (Ponto p);

Ponto definirPonto(int x, int y);

Pixel getCor(Pixel p);

int Equals(Pixel px, Pixel px2);

#endif