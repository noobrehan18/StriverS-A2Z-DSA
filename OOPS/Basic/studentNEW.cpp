#include <iostream>
using namespace std;

#include  "student.cpp"

int main() {
    student s1;

    student *s2 = new student;

    s1.setId(101);
    s2->setId(102);

    s1.display();
    s2->display();


}
