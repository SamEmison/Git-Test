/**
 * @file main.cpp
 * @author Sam Emison
 * @date 2024-09-12
 * @brief Asks user for input for array and Reads file
 * 
 * Reads based on user input
 */


#include <iostream>
#include <fstream>

using namespace std;


/**
 * Populates the array based on the size the user gives
 *
 * @param int arr[] 
 * @param int maxSize 
 * @param int& size 
 * @pre 
 * @return void Numbers in the array
 * @post Returns the numbers in the array, ready to be printed
 * 
 */
void populateArray(int arr[], int maxSize, int& size) {
  ifstream in("integers.txt"); //Opens file

  if (!in.is_open()) {
    cout << "Unable to open file." << endl;
    size = 0; //No data = 0 size
    return;
  }

  int temp; //Temp to hold the values of the ints
  int index = 0; //Index for array

  cout << "Opening file..." << endl;
  
  //Priming Read
  if (!(in >> temp)) {
    cout << "Error reading the file." << endl;
    size = 0;
    return;
  }

  arr[index++] = temp;

  while (in >> temp && index < maxSize) {
    arr[index++] = temp;
  }
  if (in.fail()) {
    cout << "Error reading file or too many values based on user response." << endl;
  }
  else cout << "Data loaded succesfully..." << endl;
  
  size = index; //Size of integers read
  in.close(); //Closes file
}

int main() {
  int size;
  int maxSize;

  //User input of Array size (Relates to Problem 2 on the quiz; Prompt user and read size)
  cout << "Please specify the size of the array: ";
  cin >> maxSize;

  // Allocates Dynamic Array (Relates to Problem 2 on the quiz; Declares a dynamic array)
  int* intArr = new int[maxSize];

  //Calls function to populate the array
  populateArray(intArr, maxSize, size);

  cout << "Here are the numbers in the array: ";
  
  for (int i = 0; i < size; ++i) {
    cout << intArr[i] << " ";
  }
  cout << endl;

  //Deallocate the Dynamic Array (Relates to Problem 3 on the quiz; Deallocates the memory for intArr)
  delete[] intArr;
  
  return 0;
}
