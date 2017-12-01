CC = clang

all:
	$(CC) src/*.c -Iinclude -pthread -o bin/run
debug:
	$(CC) src/*.c -Iinclude - pthread -g -o bin/run
