#include <iostream>
using namespace std;

#include  "Initialisation_List.cpp"

int main() {
    student s1(101); // we have to pass value of rollNumber while creating object of student class
    s1.age = 24; 
   // s1.rollNumber = 101; // we can't do this because rollNumber is constant

}

