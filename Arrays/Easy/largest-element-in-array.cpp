/*Largest Element

0

100
Easy

Given an array of integers nums, return the value of the largest element in the array
Examples:
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6
Input: nums = [3, 3, 0, 99, -40]
Output: 99
Explanation: The largest element in array is 99
Input: nums = [-4, -3, 0, 1, -8]*/

// sheet qs-sol


class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size();
        int largest = nums[0]; 
        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }
        return largest;
    }
};



/*#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void find_largest(int arr[], int n){
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<largest<<endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    find_largest(arr, n); 
    return 0;
}
    */