#include <stdio.h>
#include <stdlib.h>
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

int Equals (Pixel px, Pixel px2) {
    if ((px.red == px2.red) && (px.green == px2.green) && (px.blue == px2.blue)) {
        return 1;
    }else{
        return 0;
    }
}