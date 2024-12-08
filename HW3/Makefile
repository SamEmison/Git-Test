CC = g++ # The compiler
TARGET = driver # The executable name
CFLAGS = -c -Wall -Wextra -g # Compile with all errors and warnings

# Object Files
OBJS = driver.o Node.o BinarySearchTree.o

all: $(TARGET)

# Links object files to create an executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compiles driver.o from source
driver.o: driver.cpp BinarySearchTree.h Node.h
	$(CC) $(CFLAGS) driver.cpp -o driver.o

# Compiles Node.o from source
Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) Node.cpp -o Node.o

# Compiles BinarySearchTree.o from source
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Node.h
	$(CC) $(CFLAGS) BinarySearchTree.cpp -o BinarySearchTree.o

clean: # Cleans everything up
	rm -f *.o *~ $(TARGET)
