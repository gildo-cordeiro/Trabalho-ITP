#ifndef LINHA_H
#define LINHA_H

#include "ponto.h"

typedef struct linha{
	Ponto p1, p2;
}Linha;

Linha definirLinha(Ponto p1, Ponto p2);

#endif