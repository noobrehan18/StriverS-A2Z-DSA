#include<iostream>
using namespace std;

int main(){

    char str[]="abcde";
    char* pstr="abcde";

    
    int b[]={1,2,3};
    char c[]='abc';

    cout<< b <<endl; // prints address of first element of array b
    cout<< c <<endl; 

    char* d=&c[0];
    cout<< d <<endl;

    char c1='a';
    char* pc=&c1;
    cout<<c1 <<endl; // prints value of c1
    cout<< pc <<endl; // prints address of c1







}