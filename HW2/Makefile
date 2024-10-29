#/**
#* @file Makefile
#* @author Sam Emison
#* @date 2024-10-29
#* @brief Makfile for Linked List Assignment
#* 
#* Cleans everything up and creates an executable
#*/
# Modified from last assignment

CC = g++ # The compiler
TARGET = test # Makes "test" the executable
CFLAGS = -c -Wall -Wextra -g # Compile with all errors and warnings

#Object Files
OBJS = main.o phonebook.o

all: $(TARGET)


# Links object files to create an executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

#Compiles main.o from source
main.o: main.cpp phonebook.h
	$(CC) $(CFLAGS) main.cpp -o main.o

#Compiles phonebook.o from source
phonebook.o: phonebook.cpp phonebook.h
	$(CC) $(CFLAGS) phonebook.cpp -o phonebook.o

clean: #Cleans everything up
	rm -f *.o *~ $(TARGET)
