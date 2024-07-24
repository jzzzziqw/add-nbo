all: add_nbo

add-nbo: add_nbo.o
	gcc -Wall -o add_nbo add-nbo.o

add-nbo.o: add_nbo.c
	gcc -Wall -c add_nbo.c

clean:
	rm -f add_nbo *.o

