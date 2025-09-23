#include <iostream>
using namespace std;

#include  "Constructor.cpp"

int main() {
    student s1(18, 100);
    cout << "s1: " ;
    s1.display();

    student s2 = s1; // copy constructor called
    cout << "s2: " ;
    s2.display();

    studdent* s3 = new student(s1); // copy constructor called for dynamic object
    cout << "s3: " ;
    s3->display();

    student s4(*s3); // copy constructor called

    student *s5 = new student(*s3); // copy constructor called for dynamic object

    student* s6 = new student(s1); // copy constructor called for dynamic object 
}