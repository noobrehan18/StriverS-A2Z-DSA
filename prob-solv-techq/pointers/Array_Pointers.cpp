#include<iostream>
using namespace std;

int main(){
    int b[10]; // array of 10 integers
    cout<< b <<endl; // prints address of first element of array b
    cout<< &b[0] <<endl; // prints address of first element of array b

    b[0]=5;
    b[1]=10;

    cout<< *b <<endl;
      // dereferencing pointer to get value at first element of array b
    cout<< *(b+1) <<endl;

    int* p = *b[0]; 
    
    cout<< b <<endl;
    cout<< p <<endl;
    
    // II> ADDRESS OF POINTER AND ARRAY 
    cout<< &p <<endl;
    cout<< &b <<endl;

    // I> SIZE OF POINTER AND ARRAY
    cout<< sizeof(p) <<endl;
    cout<< sizeof(b) <<endl;

// III> DIFFERENCE BETWEEN POINTER AND ARRAY
    p=p+1;
    b=b+1; // not allowed

    b++; // not allowed
}