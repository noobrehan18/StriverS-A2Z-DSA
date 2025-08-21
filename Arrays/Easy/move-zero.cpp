#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void moveZero(int arr[], int n) {
    int nonZeroIndex = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            if (i != nonZeroIndex) {
                arr[i] = 0;  
            }
            nonZeroIndex++;
        }
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
moveZero(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/* ///////// SHEET QS->

Move Zeros to End

Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same. This must be done in place, without making a copy of the array.
Examples:
Input: nums = [0, 1, 4, 0, 5, 2]
Output: [1, 4, 5, 2, 0, 0]
Explanation: Both the zeroes are moved to the end and the order of the other elements stay the same
Input: nums = [0, 0, 0, 1, 3, -2]
Output: [1, 3, -2, 0, 0, 0]
Explanation: All 3 zeroes are moved to the end and the order of the other elements stay the same*/

//SOLUTION------>>>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
        while (pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
};