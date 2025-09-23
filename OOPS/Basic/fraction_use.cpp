#include <iostream>
using namespace std;

#include  "fraction-class.cpp"

int main() {
    Fraction f1(10, 2); // parameterized constructor will be called
    Fraction f2(15, 4);
    
    f1.add(f2); // f1 = f1 + f2
    // f1.add(f2) -> this will add f2 to f1 and store
    f1.print();
    f1.print();

    f1.multiply(f2); // f1 = f1 * f2
    f1.print();
    f2.print();

}