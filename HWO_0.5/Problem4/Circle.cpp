#include "Circle.h"
#include <iostream>
using namespace std;

// Method implementations
void Circle::move(int newX, int newY) {
    x = newX;
    y = newY;
}

void Circle::resize(float newRadius) {
    radius = newRadius;
}

void Circle::read() {
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << "Enter radius: ";
    cin >> radius;
}

void Circle::print() {
    cout << "Circle position: (" << x << ", " << y << ")" << endl;
    cout << "Radius: " << radius << endl;
}
