#include<iostream>
using namespace std;

int b;

void f(){
    cout<<b<<endl;
    b++;
    g();
    

}
void g(){

}
int main(){
    b=10;
    f();
    f();

    cout<<b<<endl;

}
