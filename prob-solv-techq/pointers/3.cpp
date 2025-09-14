#include<iostream>
using namespace std;

int main(){
    int i;
    cout<<i <<endl; // garbage value

    i++;
    cout<< i <<endl;

    int *p=0; // null pointer
    cout<< p <<endl; 

    cout<< *p <<endl; 

    (*p)++;
    cout<< *p <<endl;






}