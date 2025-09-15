#include<iostream>
using namespace std;

inline max(int a,int b){
    return (a>b)?a:b; // inline if-else
}

int main(){
    int x,y;
    cin>>x>>y;

    int z=max(x,y); // function call

    int b,c;
    b=12;
    c=34;
    int d=max(b,c); // function call

}