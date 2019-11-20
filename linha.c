#include "linha.h"
#include "ponto.h"


Linha definirLinha(Ponto p1, Ponto p2){
	linha lin;
	lin.p1.x = p1.x;
	lin.p1.y = p1.y;

	lin.p2.x = p2.x;
	lin.p2.y = p2.y;

	return lin;
}