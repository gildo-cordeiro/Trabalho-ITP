#include "ponto.h"

Ponto definirPonto(int x, int y){
    Ponto p;
    p.x = x;
    p.y = y;
    return p;
}

int valorX (Ponto p) {
	return p.x;
}

int valorY (Ponto p) {
	return p.y;
}
Pixel getCor(Pixel p){
    return corPixel(p.red,p.green, p.blue);
}