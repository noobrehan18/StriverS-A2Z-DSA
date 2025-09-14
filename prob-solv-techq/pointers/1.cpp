#include<iostream>
using namespace std;

int main(){
   /* int i;
    cout<< &i <<endl; // prints address of i

    int *p = &i; // pointer p stores address of i
    cout<< p <<endl; 

    float f = 10.5;
    float *pf = &f; // pointer pf stores address of f

    double d = 20.5;
    double *pd = &d; // pointer pd stores address of d
    */

    int i=10;
    cout<< &i <<endl; 
    int *p = &i;
    cout<< p <<endl;

    cout<< *p <<endl; // dereferencing pointer p to get value at address stored in p

    float f = 10.5;
    float *pf = &f;
    
    double d = 20.5;
    double *pd = &d;

}