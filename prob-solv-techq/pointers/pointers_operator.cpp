#include<iostream>
using namespace std;

int main(){
    int i=10;
    int* p = &i;
    cout<< i <<endl; // prints value of i

    p=p+1; 
    cout<< p <<endl; 

    double d=20.5;
    double* dp=&d;
    cout<< dp <<endl;
    dp++;
    cout<< dp <<endl;

    
}