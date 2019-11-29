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

void desenharCirculo(int cxc, int cyc, int rc, Pixel cor, PPM *mat);

void desenharBezier(int x1, int x2, int x3, int y1, int y2, int y3, Pixel cor, PPM *desenho);

Ponto drawPoint(Ponto A, Ponto B, Ponto C, Ponto D, double t);

void circlePoints(int xc, int yc, int x, int y, Pixel cor, PPM *imagem);

void setPixel(int x, int y, Pixel cor, PPM *desenho);

int getPt(int n1, int n2, float perc);
