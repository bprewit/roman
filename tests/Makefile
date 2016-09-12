
all:
	gcc -O0 -Wall -ggdb -std=c99 -o check_roman check_roman.c -lm -lrt -lcheck ../src/libroman.a -lm -lrt -lcheck -pthread

check: all
	./check_roman
