all: main

main: imagem.o pixel.o ponto.o desenho.o main.c
	gcc main.c -o main imagem.o pixel.o ponto.o desenho.o
	
imagem.o: imagem.c
	gcc -c imagem.c
	
pixel.o: pixel.c
	gcc -c pixel.c

ponto.o: ponto.c
	gcc -c ponto.c

desenho.o: desenho.c
	gcc -c desenho.c

clean:
	rm -f *.o