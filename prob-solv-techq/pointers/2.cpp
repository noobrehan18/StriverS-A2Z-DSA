#include<iostream>
using namespace std;

int main(){
    int i=10;
    int*p=&i;
    cout<< sizeof(p) <<endl; // size of pointer variable

    i++;
    cout<< i <<endl; 
    cout<< *p <<endl; 

    int a=i;
    a++;
    cout<< a <<endl;
    cout<< *p <<endl;

    










}