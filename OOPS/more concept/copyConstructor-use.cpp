#include <iostream>
using namespace std;

#include  "student.cpp"

int main() {
    char name = 'Abcd';
    student s1(24, name);
    s1.display();

    student s2(s1); 
    s2.name[0]="x"; // deep copy
    s2.display(); 
    s1.display();

    

}