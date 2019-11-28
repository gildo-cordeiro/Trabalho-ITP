#include "desenho.h"
#include <math.h>

void setPixel(Ponto p, PPM *mat) {
/* Function to plot a point
  cuidado: matriz é [linha][coluna] ponto (x,y) é coluna,linha */
  mat->mat[p.y][p.x] = 255;
}

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
 * Função: circlePoints;
 * Parametros:
 *  - p: ponto inicial por onde iniciará o desenho do circulo;
 *  - color: cor da linha do circulo;
 * Retorno: void
 * Descrição: Função recursiva para incrementar as coordenadas x e y nas direções sul, norte, leste e oeste
 **/
// void CirclePoints(Ponto p, Pixel color, PPM imagem)
// {
//     imagem.mat[p.x][p.y] =  color;
//     imagem.mat[p.x][-p.y] = color;
//     imagem.mat[-p.x][p.y] = color;
//     imagem.mat[-p.x][-p.y] = color;
//     imagem.mat[p.y][p.x] = color;
//     imagem.mat[p.y][-p.x] = color;
//     imagem.mat[-p.y][p.x] = color;
//     imagem.mat[-p.y][-p.x] = color;
// }
// /*
//  * Função: desenharCirculo;
//  * Parametros:
//  *  - radius: tamanho do raio do circulo;
//  *  - value: cor da linha do circulo;
//  * Retorno: void
//  * Descrição: Função para desenhar um circulo a partir do valor do raio especificado
//  *
//  */

// void desenharCirculo(Ponto p, int raio, PPM imagem)
// {

//     int x = 0;
//     int y = imagem.raio;

//     float d = (5.0/4.0) - imagem.raio;
//     CirclePoints(definirPonto(p.x, p.y), corPixel(255,255,255), imagem);

//     while(x < y)
//     {
//         x = x + 1;
//         if(d < 0)
//         {
//             d = d + 2*x+1;
//         }
//         else
//         {
//             y = y - 1;
//             d = d + 2*(x - y) + 1;
//         }
//         CirclePoints(definirPonto(p.x, p.y), corPixel(255,255,255), imagem);
//     }
// }

// *
//  * Função: preencherForma;
//  * Parametros:
//  *  - y: posição y do ponto por onde iniciará o preenchimento de cor;
//  *  - x: posição x do ponto por onde iniciará o preenchimento de cor;
//  *  - newColor: nova cor que irá substituir a antiga cor;
//  * Retorno: void
//  * Descrição: Função para para preecher todo o espaço da imagem onde o ponto foi especificado. A função não deverá
//  *  pintar dentro da figura caso o ponto especificado seja fora da mesma.
//  * 
// void preencherForma(int x, int y,Pixel oldColor, Pixel newColor, PPM *imagem){
//     if(y > imagem->largura - 1 || y < 0 || x > imagem->altura - 1 || x < 0){
//         return;
//     }

//     //printf("x %d alt %d, y %d lar %d\n",x,imagem->altura, y, imagem->largura);

//     if (imagem->mat[y][x].red == oldColor.red && imagem->mat[y][x].green == oldColor.green && imagem->mat[y][x].blue == oldColor.blue){
//     //if(1){
//         imagem->mat[y][x] = newColor;
//         preencherForma(y,x+1,oldColor,newColor,imagem);
//         preencherForma(y-1, x,oldColor,newColor,imagem);
//         preencherForma(y+1, x,oldColor,newColor,imagem);
//         preencherForma(y,x-1,oldColor,newColor,imagem);
//     }
// }

// void plot_point(int xc, int yc, int x, int y, Rgb cor, Rgb **mat){
// //Essa função será utilizada para desenho do círculo
//     setPixel(xc+x, yc+y, cor, mat);
//     setPixel(xc+x, yc-y, cor, mat);
//     setPixel(xc+y, yc+x, cor, mat);
//     setPixel(xc+y, yc-x, cor, mat);
//     setPixel(xc-x, yc-y, cor, mat);
//     setPixel(xc-y, yc-x, cor, mat);
//     setPixel(xc-x, yc+y, cor, mat);
//     setPixel(xc-y, yc+x, cor, mat);
// }

// void desenhaCirculo(int cxc, int cyc, int rc, Rgb cor, Rgb **mat){
//     int x = 0;
//     int y = rc;

//     float pk = (5.0/4.0) - rc;
//     plot_point(cxc, cyc, x, y, cor, mat);

//     while(x < y)  {
//         x = x + 1;
//     if(pk < 0){
//         pk = pk + 2*x+1;
//     } else {
//         y = y - 1;
//         pk = pk + 2*(x - y) + 1;
//     }
//         plot_point(cxc, cyc, x, y, cor, mat);
//   }
// }


