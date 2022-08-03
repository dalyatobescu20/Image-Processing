build: utils.c main.c
	gcc main.c utils.c -Wall -o bmp -lm
run: bmp
	./bmp
clean:
	rm -f bmp
export:
	zip tema3.zip utils.c bmp_header.h main.c Makefile README.txt
	mv tema3.zip ~/Desktop/SharedFolder/tema3.zip