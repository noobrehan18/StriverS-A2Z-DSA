#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxi = 0; 
    int cnt = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            cnt++; 
            maxi = (maxi > cnt) ? maxi : cnt; 
        } else {
            cnt = 0; 
        }
    }
    return maxi; 
}

int main(){

    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"number of consecutive ones: "<<findMaxConsecutiveOnes(arr,n);


    return 0;
}

/*. //sheet qs-???
Maximum Consecutive Ones


Given a binary array nums, return the maximum number of consecutive 1s in the array.

A binary array is an array that contains only 0s and 1s.
Examples:
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]
Output: 3
Explanation: The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s
Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]
Output: 0
Explanation: No 1s are present in nums, thus we return 0*/

//solution ----???

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxii=0;
        int cnt=0;
        for (int i=0; i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                maxii=max(maxii,cnt);
            }   
            else{
                cnt=0;
            }
        } 
        return maxii;  
    }
};