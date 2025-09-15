#include<iostream>
using namespace std;

int main(){
    //int const * p; // pointer to constant int
    int i=20;
    int j=21;

    int const * p=&i; // valid

    p=&j; // valid

    int * const p2=&i; // constant pointer to int

    (*p2)++; // valid
    // p2=&j; // error: assignment of read-only variable 'p2'
    int const * const p3=&i; // constant pointer to constant int
    
    p3=&j; // error: assignment of read-only variable 'p3'
   
    (*p3)++; // error: increment of read-only location '* p3'   

}