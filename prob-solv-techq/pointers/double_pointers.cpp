#include<iostream>
using namespace std;

void increment1(int **p){
    p=p+1;
}

void increment2(int **p){
    *p=*p+1;
}

void increment3(int **p){
    **p=**p+1;
}


int main(){
    int i=10;
    int *p=&i; // pointer p stores address of i

    int **p2=&p; // double pointer q stores address of p
    cout<< p2 <<endl; 
    cout<< &p2 <<endl;

    cout<< p <<endl;
    cout<< *p2 <<endl; // value at address stored in p2 is address of i

    cout<< i <<endl;
    cout<< *p <<endl; // value at address stored in p is 10
    cout<< **p2 <<endl; // value at address stored in p2 is address







    



}