#include "desenho.h"
#include <math.h>

int sign(int x)
{
    if (x > 0)
    {
        return 1;
    }
    else if (x < 0)
    {
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
PPM *desenharLinha(Ponto ponto1, Ponto ponto2, PPM *imagem, Pixel Color)
{
    int dx, dy, x, y, d, s1, s2, swap=0, temp;
    printf("%d",Color.red);

    dx = abs(ponto2.x - ponto1.x);
    dy = abs(ponto2.y - ponto1.y);
    s1 = sign(ponto2.x - ponto1.x);
    s2 = sign(ponto2.y - ponto1.y);

    if(dy > dx)
    {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }

    //variaveis auxiliares
    d = 2 * dy - dx;
    x = ponto1.x;
    y = ponto1.y;

    for(int i = 1; i <= dx; i++)
    {
        imagem->mat[y][x] = Color;
        //printf("x %d\n", x);
        //printf("y %d\n", y);

        while(d >= 0)
        {
            if(swap)
            {
                x = x + s1;
            }
            else
            {
                y = y + s2;
                d = d - 2* dx;
            }
        }
        if(swap) y = y + s2;
        else x = x + s1;
        d = d + 2 * dy;
    }
    imagem->mat[y][x] = Color;

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
PPM *desenharPoligono(Ponto p1, Ponto p2, Ponto p3, Ponto p4, PPM *imagem, Pixel Color)
{
    imagem = desenharLinha(p1, p2, imagem, Color);
    imagem = desenharLinha(p2, p3, imagem, Color);
    imagem = desenharLinha(p3, p4, imagem, Color);
    imagem = desenharLinha(p1, p4, imagem, Color);

    return imagem;
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
 **/ 
void preencherForma(int y, int x,Pixel oldColor, Pixel newColor, PPM *imagem){
    if(y > imagem->largura - 1 || y < 0 || x > imagem->altura - 1 || x < 0){
        return;
    }

    //printf("x %d alt %d, y %d lar %d\n",x,imagem->altura, y, imagem->largura);

    if (imagem->mat[y][x].red == oldColor.red && imagem->mat[y][x].green == oldColor.green && imagem->mat[y][x].blue == oldColor.blue){
    //if(1){
        imagem->mat[y][x] = newColor;
        preencherForma(y,x+1,oldColor,newColor,imagem);
        preencherForma(y-1, x,oldColor,newColor,imagem);
        preencherForma(y+1, x,oldColor,newColor,imagem);
        preencherForma(y,x-1,oldColor,newColor,imagem);
    }
}

/**
 * Função: setPixel;
 * Parametros:
 *  - x:;
 *  - y: ;
 *  - cor: ;
 *  - desenho: ;
 * Retorno: void
 * Descrição: Função auxiliar para setar o pixel na matriz.
 **/
void setPixel(int y, int x, Pixel cor, PPM *desenho){
    desenho->mat[y][x] = cor;
}

/**
 * Função: circlePoints;
 * Parametros:
 *  - xc: ;
 *  - yc: ;
 *  - x: ;
 *  - y: ;
 *  - cor: ;
 *  - imagem: ;
 * Retorno: void
 * Descrição: Função recursiva para incrementar as coordenadas x e y nas direções sul, norte, leste e oeste
 **/
void circlePoints(int xc, int yc, int x, int y, Pixel cor, PPM *imagem){
//Essa função será utilizada para desenho do círculo

    setPixel(xc+x, yc+y, cor, imagem);
    setPixel(xc+x, yc-y, cor, imagem);
    setPixel(xc+y, yc+x, cor, imagem);
    setPixel(xc+y, yc-x, cor, imagem);
    setPixel(xc-x, yc-y, cor, imagem);
    setPixel(xc-y, yc-x, cor, imagem);
    setPixel(xc-x, yc+y, cor, imagem);
    setPixel(xc-y, yc+x, cor, imagem);
}

/**
 * Função: desenharCirculo;
 * Parametros:
 *  - px: ;
 *  - py: ;
 *  - raio: tamanho do raio do circulo;
 *  - cor: ;
 *  - imagem: ;
 * Retorno: void
 * Descrição: Função para desenhar um circulo a partir do valor do raio especificado
 *
 **/
void desenharCirculo(int px, int py, int raio, Pixel cor, PPM *imagem){
    int x = 0;
    int y = raio;

    float pk = (15.0/14.0) - raio;
    circlePoints(py,px, y, x, cor, imagem);

    while(x < y)  {
        x = x + 1;
        if(pk < 0){
            pk = pk + 2*x+1;
        } else {
            y = y - 1;
            pk = pk + 2*(x - y) + 1;
        }
        circlePoints(py,px, y, x, cor, imagem);
    }
}

/**
 * Função: desenharBezier;
 * Parametros:
 *  - y: posição y do ponto por onde iniciará o preenchimento de cor;
 *  - x: posição x do ponto por onde iniciará o preenchimento de cor;
 *  - newColor: nova cor que irá substituir a antiga cor;
 * Retorno: void
 * Descrição: Função para para preecher todo o espaço da imagem onde o ponto foi especificado. A função não deverá
 *  pintar dentro da figura caso o ponto especificado seja fora da mesma.
 * */
PPM *desenharBezier(Ponto A, Ponto B, Ponto C, Ponto D, PPM *imagem){ 
    for (double t = 0.0; t < 1.0; t += 0.1){        
        Ponto p = drawPoint(A, B, C, D, t);
        imagem->mat[p.y][p.x] = corPixel(255,255,255);        
    }   
    return imagem; 
}

Ponto drawPoint(Ponto A, Ponto B, Ponto C, Ponto D, double t){
    Ponto p;
    p.x = ((1 - t)*(1 - t)*(1 - t)) * A.x + 3 * t * ((1 -t)*(1 -t)) * B.x + 3 * (1-t) * (t*t)* C.x + (t*t*t)* D.x;
    p.y = ((1 - t)*(1 - t)*(1 - t)) * A.y + 3 * t * ((1 -t)*(1 -t)) * B.y + 3 * (1-t) * (t*t)* C.y + (t*t*t)* D.x;

    return p;
}

