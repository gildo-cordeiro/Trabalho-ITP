#include <stdio.h>
#include <stdlib.h>
#include "desenho.h"
#include "string.h"

int main(int argc, char const *argv[])
{
    Ponto p1, p2, p3, p4, p5, p6, p7, p8;

    PPM *desenho = (PPM*)malloc(sizeof(PPM));

    desenho = lerArquivo(desenho);


    //Linha
    p1 = definirPonto(desenho->ponto[0].x,desenho->ponto[0].y);
    p2 = definirPonto(desenho->ponto[1].x,desenho->ponto[1].y);

    //Poligono
    p3 = definirPonto(desenho->ponto[2].x,desenho->ponto[2].y);
    p4 = definirPonto(desenho->ponto[3].x,desenho->ponto[3].y);
    p5 = definirPonto(desenho->ponto[4].x,desenho->ponto[4].y);
    p6 = definirPonto(desenho->ponto[5].x,desenho->ponto[5].y);

    //fill
    p7 = definirPonto(desenho->ponto[6].x,desenho->ponto[6].y);

    //circle
	//printf("%d", desenho->pixel[1].red);
    desenho = desenharLinha(p1, p2, desenho, desenho->pixel[1]);

    desenho = desenharPoligono(p3, p4, p5, p6, desenho, desenho->pixel[1]);

	desenharBezier(50,50,100,100,130,130,corPixel(255,255,255), desenho);

    desenharCirculo(desenho->ponto[7].x,desenho->ponto[7].y, desenho->raio,desenho->pixel[1], desenho);

    preencherForma(p7.x,p7.y, desenho->pixel[0], desenho->pixel[2], desenho);
	
    gerarImagem(desenho);

	for (int i = 0; i < desenho->altura; i++)
    {
        free(desenho->mat[i]);
    }
    free(desenho->mat);
    free(desenho->ponto);
    free(desenho->save);
    free(desenho->pixel);
    free(desenho);
    /*
    while (i != 1){
    	printf("Informe o comando\n");
    	scanf("%s",comando);
    	printf("\n");

    	if (strcmp(comando,"image")==0){
    		printf("imagem gerada com sucesso\n");
    		i = 1;
    	}else if(strcmp(comando,"color")==0){
    		//implementar
    	}else if(strcmp(comando,"clear")==0){
    		//implementar
    	}else if(strcmp(comando,"line")==0){

    		i = 1;

    	}else if(strcmp(comando,"rect")==0){
    		//reutilizar a função do poligono (adaptada)
    	}else if(strcmp(comando,"circle")==0){
    		//implementar
    	}else if(strcmp(comando,"polygon")==0){
    		Ponto p1, p2, p3, p4;
    		PPM image;

    		p1 = definirPonto(image.ponto[2].x, image.ponto[2].y);
    		p2 = definirPonto(image.ponto[3].x, image.ponto[3].y);
    		p3 = definirPonto(image.ponto[4].x, image.ponto[4].y);
    		p4 = definirPonto(image.ponto[5].x, image.ponto[5].y);

    		desenharPoligono(p1, p2, p3, p4);

    	}else if(strcmp(comando,"fill") == 0){
    		Ponto p1;
    		preencherForma(definirPonto(150,150), corPixel(255,0,0), imagem);
    		printf("t\n");
    		i = 1;
    	}else if(strcmp(comando,"save") == 0){
    		gerarImagem(imagem);
    		i = 1;
    	}else if(strcmp(comando,"open") == 0){
    		if(imagem.save != NULL){
    			printf("Arquivo carregado\n");
    		}else{
    			printf("Erro ao carregar arquivo\n");
    		}
    		i = 1;
    	}else{
    		printf("comando invalido\n");
    	}
    }*/



    /*
    if (c == 'P') {
    	int x, y;
    	printf("Digite o ponto na forma x y: \n");
    	scanf("%d %d", &x, &y);

    	Ponto p = definirPonto(x, y);

    	PPM imagem = desenharPonto(lerArquivo(), p);
    	gerarImagem(imagem);

    }else if (c == 'L') {

    }else if (c == 'T') {
    	Ponto p1, p2, p3;
    	int x1, x2, x3, y1, y2, y3;

    	printf("Informe o triangulo na forma X1, Y1, X2, Y2, X3 e Y3:\n");
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

    	printf("Informe a quadrado na forma X1, Y1, X2, Y2, X3, Y3, X4 e Y4:\n");
    	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    	p1 = definirPonto(x1, y1);
    	p2 = definirPonto(x2, y2);
    	p3 = definirPonto(x3, y3);
    	p4 = definirPonto(x4, y4);

    	PPM imagem = desenharQuadrado(p1, p2, p3, p4, lerArquivo());
    	gerarImagem(imagem);
    }*/
    return 0;
}
