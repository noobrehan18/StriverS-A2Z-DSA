#include<iostream>
using namespace std;

int main()
{   //creating a 2D array of 
    int arr[3][4];

    // for i/p  // row wise i/p
    /*for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }*/

   // col-wise inp

    for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>arr[i][j];
            }
        }
        
        //print
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}