#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    int x, y;       
    float radius;

public:
    
    void move(int newX, int newY); // Moves the circle to a new position
    void resize(float newRadius); // Resizes the circle with a new radius
    void read(); // Reads data from input
    void print(); // Prints circle details
};

#endif // CIRCLE_H
