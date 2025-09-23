#include <iostream>
using namespace std;

#include  "student.cpp"

int main() {

    // creting objects statically
    student s1;
    student s2;
    student s3,s4,s5;

    s1.id = 101; // accessing data members using object
    s1.age = 21;


    //creting objects dynamically
    student *s6 = new student;

    (*s6).id = 106; // accessing data members using object pointer
    (*s6).age = 26;

    s6->id = 107; // accessing data members using object pointer
    s6->age = 27;


}