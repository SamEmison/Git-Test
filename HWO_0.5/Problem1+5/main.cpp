/**
 * @file main.cpp
 * @author Sam Emison
 * @date 2024-09-12
 * @brief Sentinal Loop with Averaging Capabilities
 * 
 * Sentinal loop takes in array and Averages the numbers and prints them out
 */


#include <iostream>
#include <fstream>
#include <iomanip> //For set precision

using namespace std;

//Constant Variable MAX_ARRAY
const int MAX_ARRAY=1000;


/**
 * Prints the array of numbers
 *
 * @param const int arr[] 
 * @param int size 
 * @pre 
 * @return void The numbers in the array
 * @post When called it prints the number in the array
 * 
 */
void printArray(const int arr[], int size) {
  cout << "Here are the numbers in the file: " << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " "; //Prints each with a space
  }
  cout << endl;
}


/**
 * Does the math averaging all the numbers in the array
 *
 * @param const int arr[] 
 * @param int size 
 * @pre 
 * @return float average
 * @post Returns the average
 * 
 */
//This relates to the first problem on the quiz (Average and Return as Floating Point)
float average(const int arr[], int size) {
  if (size == 0) return 0.0; //Dividing by zero causes time out error

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  
  return (1.0*(sum) / size); //Actual math of the average
  //Multiplied by 1.0 to produce decimal points 
}


/**
 * Reads the file and populates the array
 *
 * @param int arr[] 
 * @param int& size 
 * @pre 
 * @return void 
 * @post Populates the array
 * 
 */
void populateArray(int arr[], int& size) {
  ifstream in; //File stream
  in.open("integers.txt"); //Opens file

  if (!in.is_open()) {
    cout << "Unable to open file." << endl;
    size = 0; //Nothing read = Size 0
    return;
  }

  int temp; //Temporary variable to hold int values
  int index = 0; //Index for array

  //Priming read (This relates to the 5th problem on the quiz (Reading with Sentinal logic and Priming Read)
  cout << "Opening file" << endl;
  if (!(in >> temp)) {
    cout << "Error reading the file." << endl;
    in.close();
    size = 0;
    return;
  }

  //First initial value
  arr[index++] = temp;

  while(in >> temp && index < MAX_ARRAY) {
    arr[index++] = temp; //Store value and increment
  }

  if (in.eof()) {
    cout << "Data loaded successfully." << endl;
  }
  else if (in.fail()) {
      cout << "Error reading file. V2" << endl;
    }
  size = index; //Set size of integers read
  in.close(); //Closes file
}

int main() {
  int integers[MAX_ARRAY]; //Array of integers with a parameter of MAX_ARRAY
  int size; //Number of integers read

  populateArray(integers,size); //Populates the array with numbers

  printArray(integers,size); //Prints the numbers
  
  float avg = average(integers, size); //Calls average function and stores value

  cout << "Average: " << avg << endl;
  
  return 0;
}
