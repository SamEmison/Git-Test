/**
 * @file Vector.h
 * @author Sam Emison
 * @date 2024-09-25
 * @brief Sets up structure
 * 
 * Sets up structure for the vector class by defining its members and operations
 */
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
 private:
  int* vec_ptr; //Points to the vector's dynamic array
  int vec_size, vec_capacity; //Same as size and capacity for std::Vector

 public:

/**
 * Default constructor. Initializes an empty vector
 *
 * @pre 
 * @post vec_ptr is NULL, vec_size=0, and vec_capacity=0
 * 
 */
  Vector();


/**
 * Copy constructor. Initializes a dynamic array of the appropriate size/capacity and copies data from other's array to the new array.
 *
 * @param const Vector& other 
 * @pre 
 * @post vec_ptr is initialized, and its array contains other.vec_ptr's data, vec_size=other.vec_size, and vec_capacity=other.vec_capacity.
 * 
 */
  Vector(const Vector& other);


/**
 * Destructor. Deallocates vec_ptr
 *
 * @pre 
 * @post vec_ptr has been deallocated, current_size=0, and capacity=0
 * 
 */
  ~Vector();


/**
 * Assignment operator. Initializes a dynamic array of the appropriate size/capacity and copies data from other's array to the new array.
 *
 * @param const Vector& other 
 * @pre 
 * @return Vector& 
 * @post vec_ptr is initialized, and its array contains other.vec_ptr's data, vec_size=other.vec__size, and vec_capacity=other.vec_capacity
 * 
 */
  Vector& operator=(const Vector& other);


/**
 * Returns the current number of elements in the vector
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int size() const;


/**
 * Returns the currently allocated storage capacity of the vector
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int capacity() const;


/**
 * Similar to std::vector.push_back(int element), stores element at the end of the vector.
 *
 * @param int element 
 * @pre 
 * @return void 
 * @post Item element has is stored at the end of the vector.
 * Notes:
 *   If necessary, calls reserve() before adding element to the end of the vector.
 *   This reserve doubles the current capacity of the vector.
 */
  void push_back(int element);


/**
 * Requests that the vector capacity be resized at least enough to contain n elements.
 * 
 * If n is greater than the current capacity, the function causes the container to reallocate
 * its storage increasing its capacity to n (or greater).
 *
 * If n is less than or equal to the current capacity, the call does nothing (no reallocation
 * or change in vector capacity).
 *
 * This function has no effect on vector size and cannot alter its elements.
 *
 * @param int n 
 * @pre 
 * @return void 
 * @post Vector capacity is now n.  Vector size (and contents) remains the same.
 * 
 */
  void reserve(int n);


/**
 * Returns a reference to the element at position index.
 *
 * @param unsigned int index 
 * @pre 
 * @return int& 
 * @post 
 * 
 */
  int& operator[](unsigned int index);
};

#endif // VECTOR_H
