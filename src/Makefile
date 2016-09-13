all: libroman

libroman: roman.o
	ar cru libroman.a roman.o
	ranlib libroman.a

roman.o: roman.c roman.h
	gcc -O0 -Wall -ggdb -std=c99 -c roman.c


.PHONY: clean
clean:
	-rm *.o *.a

