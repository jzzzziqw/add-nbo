all: add-nbo

add-nbo: add-nbo.o
	gcc -Wall -o add-nbo add-nbo.o

add-nbo.o: add-nbo.c
	gcc -Wall -c add-nbo.c

clean:
	rm -f add-nbo *.o

