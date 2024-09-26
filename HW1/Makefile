#/**
#* @file Makefile
#* @author Sam Emison
#* @date 2024-09-26
#* @brief Makfile for Vector Assignment
#* 
#* Cleans everything up and creates an executable
#*/
# Modified from last assignment

CC = g++ # The compiler
TARGET = test # Makes "test" the executable
CFLAGS = -c -Wall -Wextra -g # Compile with all errors and warnings

#Object Files
OBJS = main.o Vector.o

all: $(TARGET)


# Links object files to create an executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#Compiles main.o from source
main.o: main.cpp Vector.h
	$(CC) $(CFLAGS) main.cpp -o main.o

#Compiles Vector.o from source
Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) Vector.cpp -o Vector.o

clean: #Cleans everything up
	rm -f *.o *~ $(TARGET)
