#include<iostream>
using namespace std;

/* int sum(int b[],int size){
    cout<< sizeof(b)<< endl;
    return 0;
}
*/
int sum(int*b,int size){
    int ns=0;
    for(int i=0;i<size;i++){
        ns+=b[i];
    }
    return ns;

}

int main(){
    int b[10]; 
    cout<<sizeof(b)<<endl;
    cout<< sum(b+3,7)<<endl;


}
