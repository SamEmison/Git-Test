# Makefile for Vector Assignment
# Modified from last assignment

CC = g++
TARGET = test
CFLAGS = -c -Wall -Wextra -g

#Object Files
OBJS = main.o Vector.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp Vector.h
	$(CC) $(CFLAGS) main.cpp -o main.o

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) Vector.cpp -o Vector.o

clean:
	rm -f *.o *~ $(TARGET)
