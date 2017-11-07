CC = clang

all:
	$(CC) src/*.c -Iinclude -pthread -o bin/run
