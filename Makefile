CC = clang

all:
	$(CC) src/*.c -Iinclude -pthread -g -o bin/run
