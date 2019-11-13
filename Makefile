all: main

main: imagem.o pixel.o main.c
	gcc main.c -o main imagem.o pixel.o
	
imagem.o: imagem.c
	gcc -c imagem.c
	
pixel.o: pixel.c
	gcc -c pixel.c

clean:
	rm -f *.o