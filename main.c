#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"
#include "ponto.h"

int main(int argc, char const *argv[]){
	
    //gerarImagem(lerArquivo());

    int x, y;	

    printf("Informe o ponto na forma X e Y:\n");
    scanf("%d %d",&x, &y);

    ponto p = definirPonto(x,y);

    desenharPonto(lerArquivo(), p);

	return 0;
}