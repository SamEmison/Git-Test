/**
 * @file main.cpp
 * @author Sam Emison
 * @date 2024-09-25
 * @Main
 * 
 * Prints and Reads a file
 */


#include <iostream>
#include <fstream>
#include "Vector.h" //Includes the Vector class

using namespace std;

//PopulateVector function was recycled from HW0.5 Problem 1+5
//Modified from static array to work with this assignment
/**
 * Populates the vector after reading the file. Sets it up for the rest of the functions
 *
 * @param Vector& vec 
 * @pre 
 * @return void 
 * @post 
 * 
 */
void populateVector(Vector& vec) {
  ifstream in;
  in.open("Numbers.txt"); //Opens the file

  if (!in.is_open()) {
    cout << "Unable to open file." << endl;
    return;
  }

  int temp; //Temp variable to hold the values in the file

  //Priming read
  cout << "Opening file..." << endl;
  if (!(in >> temp)) {
    cout << "Error reading the file." << endl;
    in.close(); //Close file
    return;
  }

  cout << endl;

  //First Initial Value
  vec.push_back(temp);

  while(in >> temp) {
    vec.push_back(temp); //Uses the pushback function to add elements dynamically
  }

  if (in.eof()) {
    cout << endl;
    cout << "Data was loaded successfully." << endl;
  }
  else if (in.fail()) {
    cout << "Error reading file V2." << endl; //V2 is for me if it fails I can catch where it fails exactly
  }

  
  in.close(); //Closes the file
}

int main() {
  Vector vec;
  Vector copyVec;
  Vector assignedVec;

  //Populates the vector from the file
  cout << "Populating vector from Numbers.txt file..." << endl;
  populateVector(vec);
  cout << "Finished populating vector." << endl;
  
  cout << endl;
  
  cout << "Vector size after file population: " << vec.size() << endl;
  cout << endl; 

  //Test 2
  //Test size() and print first 30 elements
  cout << "The first 30 elements: "; 
  for (int i = 0; i < 30 && i < vec.size(); i++) { //Loop to print the first 30 numbers in the vector
    cout << vec[i] << " ";
  }
  cout << endl; //New line
  cout << endl;

  //Test 3
  //Copy constructor
  cout << "Testing the copy constructor..." << endl;
  cout << "Copying vec into copyVec..." << endl;
  copyVec = vec; //Copy constructor
  cout << endl;

  //Test 4
  //Modifying elements with bracket operator[]
  cout << "Modifying the first 2 elements..." << endl;
  vec[0] = 1234; //Modifies first element
  vec[1] = 4321; //Modifies second element
  cout << "The first 2 modified elements: " << vec[0] << " " << vec[1] << endl;
  cout << endl;

  //Copy Constructer Cont.
  cout << "Size of copyVec: " << copyVec.size() << endl;
  cout << "The first element of copyVec: " << copyVec[0] << endl;
  cout << "The first element of vec: " << vec[0] << endl;
  cout << endl;
  
  //Test 5
  //Assingnment Operator
  cout << "Testing assignment operator..." << endl;
  assignedVec = vec; //Use Assignment operator
  cout << "Size of assignedVec: " << assignedVec.size() << endl;

  return 0;
}
