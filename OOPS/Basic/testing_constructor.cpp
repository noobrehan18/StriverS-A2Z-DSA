#include <iostream>
using namespace std;

#include  "Constructor.cpp"

int main() {
    student s1;

    s1.display();

    student s2; // another object
    student* s3 = new student; // dynamic object creation
    s3->display(); // access member function using pointer

    cout<<"parametrized constructor called ****"<< endl;
    
    student s4(25); // parameterized constructor called
    s4.display();

    student* s5 = new student(30); // dynamic object creation with parameterized constructor
    s5->display();

    student s6(22, 101); // parameterized constructor with two parameters



}