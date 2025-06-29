#include <iostream>
using namespace std;

class shape
{
public:
    virtual double calculateArea() = 0;                                              // Pure virtual function for calculating the area of a shape
    virtual void resize(double width = 0, double height = 0, double radius = 0) = 0; // Pure virtual function for resizing a shape
};

class rectangle : public shape
{
    double width;  // Private member variable to store the width of the rectangle
    double height; // Private member variable to store the height of the rectangle

public:
    rectangle(double width = 0, double height = 0)
    {
        this->width = width;   // Assign the provided width to the member variable
        this->height = height; // Assign the provided height to the member variable
    }

    double calculateArea() // Calculate the area of the rectangle
    {
        return width * height;
    }

    void resize(double width = 0, double height = 0, double radius = 0) // Resize the rectangle by updating its dimensions
    {
        this->width = width;   // Assign the provided width to the member variable
        this->height = height; // Assign the provided height to the member variable
    }
};

class circle : public shape
{
    double radius; // Private member variable to store the radius of the circle

public:
    circle(double radius = 0)
    {
        this->radius = radius; // Assign the provided radius to the member variable
    }

    double calculateArea() // Calculate the area of the circle
    {
        return 3.14 * radius * radius;
    }

    void resize(double radius = 0, double width = 0, double height = 0) // Resize the circle by updating its radius
    {
        this->radius = radius; // Assign the provided radius to the member variable
    }
};

int main()
{
    double length = 0, width = 0, radius = 0;
    cout << "For Rectangle\n";
    cout << "  Enter Length: ";
    cin >> length;
    cout << "  Enter Width: ";
    cin >> width;

    cout << "\nFor Circle\n";
    cout << "  Enter Radius: ";
    cin >> radius;

    shape *ptr01 = new rectangle(length, width); // Create a pointer to the base class shape and instantiate it with a rectangle object
    shape *ptr02 = new circle(radius);              // Create a pointer to the base class shape and instantiate it with a circle object

    cout << "\nArea of Rectangle is " << ptr01->calculateArea() << endl; // Call the calculateArea() function on ptr01, which is a rectangle object
    cout << "Area of Circle is " << ptr02->calculateArea() << endl;    // Call the calculateArea() function on ptr02, which is a circle object

    cout << "\n ==== Resizing ====\n";
    cout << "For Rectangle\n";
    cout << "  Enter New Length: ";
    cin >> length;
    cout << "  Enter New Width: ";
    cin >> width;

    cout << "\nFor Circle\n";
    cout << "  Enter New Radius: ";
    cin >> radius;
    cout << "\nAfter Resizing.\n";
    ptr01->resize(length,width); // Call the resize() function on ptr01, which is a rectangle object, to resize its dimensions
    ptr02->resize(radius);      // Call the resize() function on ptr02, which is a circle object, to resize its radius

    cout << "\nArea of Rectangle is " << ptr01->calculateArea() << endl; // Call the calculateArea() function on ptr01 again after resizing
    cout << "Area of Circle is " << ptr02->calculateArea() << endl;    // Call the calculateArea() function on ptr02 again after resizing

    return 0;
}
