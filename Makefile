
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

reverse-linked-list: reverse-linked-list.o
	$(CC) $(CFLAGS) -o reverse-linked-list reverse-linked-list.o

reverse-linked-list.o: reverse-linked-list.cpp
	$(CC) $(CFLAGS) -c reverse-linked-list.cpp

clean:
	rm -rf reverse-linked-list reverse-linked-list.o
