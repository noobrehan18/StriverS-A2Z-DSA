#include<iostream>
using namespace std;

void increment(int &n){ // reference variable
    n++;
}
// bad practice
// returning reference of local variable
int& f(int n){
    int a=n;
    return a;
}

int main(){
    int i=10;
    //int j=i;

    int &k=f(i);

    int &j=i; // j is reference to i
    increment(i);
    cout<<i<<endl;

    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;

    int k=100;
    j=k;
    cout<<i<<endl; 



}