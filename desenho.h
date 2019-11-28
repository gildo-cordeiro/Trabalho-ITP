#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "pixel.h"
#include "ponto.h"
#include <math.h>

int sign(int x);

PPM *desenharLinha(Ponto ponto1, Ponto ponto2,PPM *imagem, Pixel Color);

PPM *desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4, PPM *imagem, Pixel Color);

void preencherForma(int x, int y,Pixel oldColor, Pixel newColor, PPM *imagem);

void CirclePoints(Ponto p, Pixel color, PPM imagem);

void desenharCirculo(Ponto p, int raio, PPM imagem);

PPM *desenharBezier(Ponto A, Ponto B, Ponto C, Ponto D, PPM *imagem);

Ponto drawPoint(Ponto A, Ponto B, Ponto C, Ponto D, double t);
