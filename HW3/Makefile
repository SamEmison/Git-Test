#/**
# * @file Makefile
# * @author Sam Emison
# * @date 2024-12-08
# * @brief Makefile
# * 
#* 
# */

CC = g++ # The compiler
TARGET = test # The executable name
CFLAGS = -c -Wall -Wextra -g # Compile with all errors and warnings

# Object Files
OBJS = Driver.o Node.o BST.o

all: $(TARGET)

# Links object files to create an executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compiles driver.o from source
Driver.o: Driver.cpp BST.h Node.h
	$(CC) $(CFLAGS) Driver.cpp -o Driver.o

# Compiles Node.o from source
Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp -o Node.o

# Compiles BST.o from source
BST.o: BST.cpp BST.h Node.h
	$(CC) $(CFLAGS) BST.cpp -o BST.o

clean: # Cleans everything up
	rm -f *.o *~ $(TARGET)
