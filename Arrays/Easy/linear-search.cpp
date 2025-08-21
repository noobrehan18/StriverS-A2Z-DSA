//code 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int num){
    for(int i=0; i<n; i++){
        if(arr[i]==num) return i;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   int num;
    cin >> num; 
    
    int result = linearSearch(arr, n, num); 
    
    cout << "at index:"<<result << endl;
    
    cout << endl;
}
/* //// sheet qs

Linear Search

Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1
Examples:
Input: nums = [2, 3, 4, 5, 3], target = 3
Output: 1
Explanation: The first occurence of 3 in nums is at index 1
Input: nums = [2, -4, 4, 0, 10], target = 6
Output: -1
Explanation: The value 6 does not occur in the array, hence output is -1
*/

// sol->

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;  
            }
        }
        return -1;  
    }
};