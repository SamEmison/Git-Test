/**
0;10;1c * @file main.cpp
 * @author Sam Emison
 * @date 2024-09-12
 * @brief Demonstrates the circle class
 * 
 * Program that demonstrates the circle class
 */

#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
  Circle myCircle;

  cout << "Reading circle values: " << endl;
  myCircle.read();

  cout << "Printing circle values: " << endl;
  myCircle.print();

  cout << "Moving the circle to (5,10)..." << endl;
  myCircle.move(5,10);
  myCircle.print();

  cout << "Resizing the circle to a radius of 6..." << endl;
  myCircle.resize(6);
  myCircle.print();
  
  return 0;
}
