#include "desenho.h"

int sign(int x){
    if (x > 0){
        return 1;
    } else if (x < 0){
        return -1;
    }
    return 0; 
}

/**
 * Função: desenharLinha
 * Parametros: 
 *  - ponto1: recebe o primeiro com suas coordenadas x e y;
 *  - ponto2: recebe o segundo ponto com suas coordenadas x e y;
 *  - imagem: matriz que possue as propriedades que foram lidas no arquivo externo;
 * Retorno: void
 * Descrição: Função para desenhar uma linha com ponto inicial e final especificados na iamgem (matriz)
 * */
PPM desenharLinha(Ponto ponto1, Ponto ponto2, PPM imagem){
    int dx, dy, x, y, d, s1, s2, swap=0, temp;

    dx = abs(ponto2.x - ponto1.x);
    dy = abs(ponto2.y - ponto1.y);  
    s1 = sign(ponto2.x - ponto1.x);
    s2 = sign(ponto2.y - ponto1.y);

    if(dy > dx){
        temp = dx; 
        dx = dy; 
        dy = temp; 
        swap = 1;
    }
    
    //variaveis auxiliares
    d = 2 * dy - dx;
    x = ponto1.x;
    y = ponto1.y;

    for(int i = 1; i <= dx; i++) {
        imagem.mat[y][x] = corPixel(255,255,255);
        //printf("x %d\n", x);
        //printf("y %d\n", y);
        
        while(d >= 0) {
        if(swap){
            x = x + s1;
        } else {
            y = y + s2;
            d = d - 2* dx;
        }
        }
        if(swap) y = y + s2;
        else x = x + s1;
        d = d + 2 * dy;
    }
    imagem.mat[y][x] = corPixel(255,255,255);
    
    return imagem;
}
/**
 * Função: desenharPloigono;
 * Parametros: 
 *  - p1: primeiro ponto do poligono;
 *  - p2: segundo ponto do poligono;
 *  - p3: terceiro ponto do poligono;
 *  - p4: quarto ponto do poligono;
 * Retorno: void
 * Descrição: Função para desenhar um poligono com posições especificas na iamgem (matriz)
 * */
PPM desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4, PPM imagem){
    PPM imagem1, imagem2, imagem3, imagem4;
    imagem1 = desenharLinha(p1, p2, imagem);
    imagem2 = desenharLinha(p2, p3, imagem1);
    imagem3 = desenharLinha(p3, p4, imagem2);
    imagem4 = desenharLinha(p1, p4, imagem3);
    
    return imagem4;
}

/**
 * Função: preencherForma;
 * Parametros: 
 *  - y: posição y do ponto por onde iniciará o preenchimento de cor;
 *  - x: posição x do ponto por onde iniciará o preenchimento de cor;
 *  - newColor: nova cor que irá substituir a antiga cor;
 * Retorno: void
 * Descrição: Função para para preecher todo o espaço da imagem onde o ponto foi especificado. A função não deverá 
 *  pintar dentro da figura caso o ponto especificado seja fora da mesma.
 * */
void preencherForma(Ponto p, Pixel newColor, PPM imagem){
    if(p.y > imagem.largura || p.y < 0 || p.x > imagem.altura-1 || p.x < 0){ 
        return;        
    }
    printf("x %d alt %d, y %d lar %d\n",p.x,imagem.altura, p.y, imagem.largura);
    if (Equals(imagem.mat[p.y][p.x], corPixel(100,170,200))) {
        imagem.mat[p.y][p.x] = corPixel(255,0,0);

        preencherForma(definirPonto(p.y+1, p.x), corPixel(255,0,0), imagem);
        preencherForma(definirPonto(p.y-1, p.x), corPixel(255,0,0), imagem);
        preencherForma(definirPonto(p.y, p.x+1), corPixel(255,0,0), imagem);
        preencherForma(definirPonto(p.y, p.x-1), corPixel(255,0,0), imagem);
    }
}
/**
 * Função: circlePoints;
 * Parametros: 
 *  - p: ponto inicial por onde iniciará o desenho do circulo;
 *  - color: cor da linha do circulo;
 * Retorno: void
 * Descrição: Função recursiva para incrementar as coordenadas x e y nas direções sul, norte, leste e oeste
 **/
void CirclePoints(Ponto p, Pixel color, PPM imagem){
    imagem.mat[p.x][p.y] =  color;
    imagem.mat[p.x][-p.y] = color;
    imagem.mat[-p.x][p.y] = color;
    imagem.mat[-p.x][-p.y] = color;
    imagem.mat[p.y][p.x] = color;
    imagem.mat[p.y][-p.x] = color;
    imagem.mat[-p.y][p.x] = color;
    imagem.mat[-p.y][-p.x] = color;
}
/**
 * Função: desenharCirculo;
 * Parametros: 
 *  - radius: tamanho do raio do circulo;
 *  - value: cor da linha do circulo;
 * Retorno: void
 * Descrição: Função para desenhar um circulo a partir do valor do raio especificado
 * */
void desenharCirculo(Ponto p, int raio, PPM imagem){
    int x = 0;
    int y = raio;
    int d = 1 - raio;
    CirclePoints(definirPonto(x, y), corPixel(255,255,255), imagem);
    while(y > x) {
        if (d < 0){
            d += 2 * x + 3;
        }else {
            d += 2 * (x - y) + 5;
            y--;
        }
    }
    x++;
    CirclePoints(definirPonto(x, y), corPixel(255,255,255), imagem);
}

