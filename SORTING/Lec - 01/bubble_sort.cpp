#include <bits/stdc++.h>
#include<iostream>
using namespace std;
// BUbble sort

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int did_Swap = 0;
        for(int j = 0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                    did_Swap = 1;
            }
        }
        if(did_Swap==0) break;
        cout<<"runs\n";
    }
}
