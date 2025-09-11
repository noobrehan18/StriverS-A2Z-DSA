#include<iostream>
using namespace std;


int main(){
    int arr[3][4];
    //row-wise input
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    //largest row sum
    int largest = INT_MIN;
    int rowIndex = -1;
    for(int i=0;i<3;i++){
        int sum = 0;
        for(int j=0;j<4;j++){
            sum += arr[i][j];
        }
        if(sum > largest){
            largest = sum;
            rowIndex = i;
        }
    }
    cout<<"Largest row sum is "<<largest<<" at row index "<<rowIndex<<endl;
    return 0;

}