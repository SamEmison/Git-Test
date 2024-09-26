/**
 * @file Vector.cpp
 * @author Sam Emison
 * @date 2024-09-25
 * @brief Functionality for Vector Class
 * 
 * Adds the Functionalities needed for the custom Vector class that has been made
 */
#include "Vector.h"
#include <iostream>


//Constructor
/**
 * Initializes an Empty Vector
 *
 * @param const Vector& other
 * @pre
 * @post Sets vec_ptr to nullptr, and vec_size=0 and vec_capacity to 1
 *
 */
Vector::Vector() : vec_ptr(nullptr), vec_size(0), vec_capacity(1) {
}


//Copy Constructor
/**
 * Creates a New Vector That is a Copy of other
 *
 * @param const Vector& other 
 * @pre 
 * @post Allocates new memory for vec_ptr, then copies the size and capacity, and copies each element from the other vector
 * 
 */
Vector::Vector(const Vector& other) {
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity]; //Allocate New Memory
  for (int i = 0; i < vec_size; i++) {
    vec_ptr[i] = other.vec_ptr[i]; //Copy Elements
  }
}


//Destructor
/**
 * Cleans up When a Vector Object is Destroyed
 *
 * @pre 
 * @post Deallocates Memory Pointed to by vec_ptr
 * 
 */
Vector::~Vector() {
  delete[] vec_ptr; //Deallocates Memory
}


//Assignment Operator
/**
 * Assings One Vector to Another
 *
 * @param const Vector& other 
 * @pre 
 * @return Vector& 
 * @post Self Assingment check, deallocates existing memory, allocates new memory and copies from the other vector, and returns a reference to the current object 
 * 
 */
Vector& Vector::operator=(const Vector& other) {
  if(this != &other) { //Self Assignment Check
    delete[] vec_ptr; //Deallocates Current Memory

    vec_size = other.vec_size;
    vec_capacity = other.vec_capacity;
    vec_ptr = new int[vec_capacity]; //Allocates New Memory
    for (int i = 0; i < vec_size; i++) {
      vec_ptr[i] = other.vec_ptr[i]; //Copy Elements
    }
  }
  return *this;
}


/**
 * Returns the number of elements currently in the vector
 *
 * @pre 
 * @return int 
 * @post Returns vec_size
 * 
 */
int Vector::size() const{
  return vec_size; //Returns Size
}


/**
 * Returns the current capacity of the Vector
 *
 * @pre 
 * @return int 
 * @post Returns vec_capacity
 * 
 */
int Vector::capacity() const {
  return vec_capacity; //Returns Capacity
}


/**
 * Adds an integer to the end of the vector
 *
 * @param int element 
 * @pre 
 * @return void 
 * @post Checks if vector needs more capacity, if yes it calls reserve to double the capacity. Also adds the new element to the array and increments vec_size
 * 
 */
void Vector::push_back(int element) {
  if (vec_size >= vec_capacity) {
    reserve(vec_capacity * 2); //Doubles Capacity
  }
  vec_ptr[vec_size++] = element; //Adds the New Element
}


/**
 * Allocates memory for at least n elements
 *
 * @param int n 
 * @pre 
 * @return void 
 * @post Checks if n execeeds current capacity. Allocates new memory and copies the existing elements. Also deallocates the old memory and updates vec_ptr and vec_capacity
 * 
 */
void Vector::reserve(int n) {
  if (n > vec_capacity) {
    int* new_ptr = new int[n]; //Allocates New Memory
    for (int i = 0; i < vec_size; i++) {
      new_ptr[i] = vec_ptr[i]; //Copy Existing Elements
    }
    delete[] vec_ptr; //Frees Old Memory
    vec_ptr = new_ptr; //Updates the Pointer to the New Memory
    vec_capacity = n; //Updates the Capacity
  }
}

//Indexing Operator to Access Elements
/**
 * Provides acces to elements using the [] operator
 *
 * @param unsigned int index 
 * @pre 
 * @return int& 
 * @post Returns a reference to the element at positoon index.
 * 
 */
int& Vector::operator[](unsigned int index) {
  return vec_ptr[index]; //Returns Reference to the Element
}

