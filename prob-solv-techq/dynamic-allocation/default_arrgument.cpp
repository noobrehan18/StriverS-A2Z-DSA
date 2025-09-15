#include<iostream>
using namespace std;

int sum(int b[], int size,int si){
    int ns=0;
    for(int i=si;i<size;i++){
        ns+=b[i];
    }
}


int sum2(intb,int c,int d=0,int e=0){
    return b+c+d+e;
}

int main(){
    int b[20];
    //i/p code for b;;;

    cout<< sum(b,20)<<endl;



}