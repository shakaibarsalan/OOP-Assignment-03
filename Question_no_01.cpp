#include <iostream>
using namespace std;

// Base class Person
class person
{
protected:
    string name;
    int age;

public:
    // Constructor with default values for name and age
    person(string name = "", int age = 0)
    {
        this->name = name;
        this->age = age;
    }

    // Virtual function to display details
    virtual void displayDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
    }
};

// Derived class Student
class student : public person
{
private:
    int studentID;

public:
    // Constructor with default values for name, age, and studentID
    student(string name = "", int age = 0, int studentID = 0) : person(name, age)
    {
        this->studentID = studentID;
    }

    // Override displayDetails() function to display additional studentID
    void displayDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Student ID: " << studentID << "\n";
    }
};

// Derived class Teacher
class teacher : public person
{
private:
    int teacherID;

public:
    // Constructor with default values for name, age, and teacherID
    teacher(string name = "", int age = 0, int teacherID = 0) : person(name, age)
    {
        this->teacherID = teacherID;
    }

    // Override displayDetails() function to display additional teacherID
    void displayDetails()
    {
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Teacher ID: " << teacherID << "\n";
    }
};

int main()
{
    // Creating objects using base class pointers
    person *per01 = new student("Eman Murtaza", 20, 12345);
    person *per02 = new teacher("Arman Bin Tahir", 25, 678901);

    // Calling displayDetails() function for each object
    per01->displayDetails();
    cout << endl;
    per02->displayDetails();

    // Deleting dynamically allocated objects to free memory
    delete per01;
    delete per02;

    return 0;
}
