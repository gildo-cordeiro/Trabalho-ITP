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
	if (c == 'P'){

		Ponto p = definirPonto(lerArquivo().ponto[0].x, lerArquivo().ponto[0].y);
		
		PPM imagem = desenharPonto(lerArquivo(), p);
		gerarImagem(imagem);
		
	}else if (c == 'L'){

		Ponto p1, p2;

		p1 = definirPonto(lerArquivo().ponto[0].x, lerArquivo().ponto[0].y);
		p2 = definirPonto(lerArquivo().ponto[1].x, lerArquivo().ponto[1].y);

		PPM imagem = desenharLinha(p1, p2, lerArquivo());
		gerarImagem(imagem);

	}else if (c == 'T'){

		Ponto p1, p2, p3;	

		p1 = definirPonto(lerArquivo().ponto[0].x, lerArquivo().ponto[0].y);
		p2 = definirPonto(lerArquivo().ponto[1].x, lerArquivo().ponto[1].y);
		p3 = definirPonto(lerArquivo().ponto[2].x, lerArquivo().ponto[2].y);

		PPM imagem = desenharTriangulo(p1, p2, p3, lerArquivo());
		gerarImagem(imagem);

	}else if (c == 'Q'){

		Ponto p1, p2, p3, p4;	
		
		p1 = definirPonto(lerArquivo().ponto[0].x, lerArquivo().ponto[0].y);
		p2 = definirPonto(lerArquivo().ponto[1].x, lerArquivo().ponto[1].y);
		p3 = definirPonto(lerArquivo().ponto[2].x, lerArquivo().ponto[2].y);
		p4 = definirPonto(lerArquivo().ponto[3].x, lerArquivo().ponto[3].y);

		PPM imagem = desenharQuadrado(p1, p2, p3, p4, lerArquivo());
		gerarImagem(imagem);
	}
	return 0;
}