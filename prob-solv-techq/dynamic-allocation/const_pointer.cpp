#include<iostream>
using namespace std;

void g(int const &b){
    b++; // error: increment of read-only reference 'b'
}
void f(const int *p){

}
int main(){
    int const i=10;

    //int* p=&i; // error: invalid conversion from 'const int*' to 'int*'
    
    const int* p=&i; // valid

   //  (*p)++; // error: increment of read-only location '* p'
   /* int j=12;
    int const * p2=&j; // valid
    cout<<*p2<<endl;*/

    int j=12;
    int *p3=&j; // valid
    f(p3);
    g(j);

    int const *p2=&j; // valid
    cout<<*p2<<endl;
    j++;
    cout<<*p2<<endl; 

}