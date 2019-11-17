#include <stdio.h>
#include <stdlib.h>
#include "desenho.h"

int main(int argc, char const *argv[]){
    char lixo, c = 'A';
	printf("\nDigite o que deseja fazer: \n");
	printf("P - inserir ponto\n");
	printf("L - Inserir linhal\n");
	printf("T - Inserir Triangulo\n");
	printf("Q - Inserir Quadrado\n");
	printf("S - sair do programa\n");
	scanf("%c", &c);
	if (c == 'P') {
		int x, y;
		printf("Digite o ponto na forma x y: \n");
		scanf("%d %d", &x, &y);

		Ponto p = definirPonto(x, y);
		
		PPM imagem = desenharPonto(lerArquivo(), p);
		gerarImagem(imagem);
		
	}else if (c == 'L') {
		Ponto p1, p2;	
		int x1,x2,y1,y2;

		printf("Informe a linha na forma X1, Y1, X2 e Y2:\n");
		scanf("%d %d %d %d",&x1,&y1, &x2, &y2);

		p1 = definirPonto(x1, y1);
		p2 = definirPonto(x2, y2);

		PPM imagem = desenharLinha(p1, p2, lerArquivo());
		gerarImagem(imagem);
	}else if (c == 'T') {
		Ponto p1, p2, p3;	
		int x1, x2, x3, y1, y2, y3;

		printf("Informe a linha na forma X1, Y1, X2 e Y2:\n");
		scanf("%d %d %d %d %d %d",&x1,&y1,&x3, &x2, &y2, &y3);

		p1 = definirPonto(x1, y1);
		p2 = definirPonto(x2, y2);
		p3 = definirPonto(x3, y3);

		PPM imagem = desenharTriangulo(p1, p2, p3, lerArquivo());
		gerarImagem(imagem);

		//essa merda desse quadrado não sai
	}else if (c == 'Q') {
		Ponto p1, p2, p3, p4;	
		int x1, x2, x3, x4, y1, y2, y3, y4;

		printf("Informe a linha na forma X1, Y1, X2, Y2, X3, Y3, X4 e Y4:\n");
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

		p1 = definirPonto(x1, y1);
		p2 = definirPonto(x2, y2);
		p3 = definirPonto(x3, y3);
		p4 = definirPonto(x4, y4);

		PPM imagem = desenharQuadrado(p1, p2, p3, p4, lerArquivo());
		gerarImagem(imagem);
	}
	return 0;
}