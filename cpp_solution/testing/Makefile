CC = clang++
CFLAGS = -std=c++17 -Wall

all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o main -lm

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f main main.o

