#include <stdio.h>
#include <stdlib.h>
#include "desenho.h"

int main(int argc, char const *argv[]){
    char lixo, c = 'A';
	printf("\nDigite o que deseja fazer: \n");
	printf("P - inserir ponto\n");
	printf("L - Inserir linhal\n");
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
	}
	return 0;
}