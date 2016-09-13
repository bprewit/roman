all: ../src/libroman.a
	gcc -O0 -Wall -ggdb -std=c99 -pthread -o check_roman check_roman.c -pthread -lm -lrt -lcheck ../src/libroman.a -lrt -lm -lcheck

check: all
	./check_roman
