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

    int x;
    cin>>x;

    //linear search
    bool found = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==x){
                cout<<"Found at "<<i<<","<<j<<endl;
                found = true;
            }
        }
    }
    if(!found){
        cout<<"Not Found"<<endl;
    }
    return 0;
    

}