#include <iostream>
using namespace std;

#include  "student.cpp"

int main() {
    char name = 'Abcd';
    student s1(24, name);
    s1.display();

    name = 'e';
    student s2(25, name);
    s2.display();

}