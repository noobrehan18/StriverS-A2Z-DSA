#include<bits/stdc++.h>

using namespace std;

//  better approach
int maxSubarray(int arr[], int n){
    int maxi = INT64_MIN;
    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            maxi = max(sum, maxi);
        }
    }

}

// optimal

int maxSubArray(int arr[], int n){
    int sum=0, maxi=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxi = max(sum, maxi);
        if(sum<0){
            sum=0;
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

    // cout<<maxSubarray(arr,n);
    
    // better soln 
    cout<<maxSubArray(arr,n);

    return 0;
}

/*
Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.
Examples:
Input: nums = [2, 3, 5, -2, 7, -4]
Output: 15
Explanation: The subarray from index 0 to index 4 has the largest sum = 15
Input: nums = [-2, -3, -7, -2, -10, -4]
Output: -2
Explanation: The element on index 0 or index 3 make up the largest sum when taken as a subarray

*/

//better approach ->
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                maxi=max(sum,maxi);
            }
        }
        return maxi;
    }
};