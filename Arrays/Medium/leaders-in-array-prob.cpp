#include<bits/stdc++.h>

using namespace std;

vector<int> leaders(vector<int>&arr, int n){
        vector<int> ans;
        int maxi = INT_MIN;

        for(int i=n-1; i>=0; i--){
            if(arr[i]>maxi){
                ans.push_back(arr[i]);
            }
            maxi = max(maxi,arr[i]);
        }

        sort(ans.begin(), ans.end());
        return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    vector<int> result = leaders(arr,n);

     for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
}



//sheet qs->
/*/Leaders in an Array

Given an integer array nums, return a list of all the leaders in the array.

A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.
Examples:
Input: nums = [1, 2, 5, 3, 1, 2]
Output: [5, 3, 2]
Explanation: 2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]
Input: nums = [-3, 4, 5, 1, -4, -5]
Output: [5, 1, -4, -5]
Explanation: -5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]*/

// soltion->

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans; 

        for (int i = 0; i < n; i++) {
            bool leader = true; 

            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    leader = false;
                    break;
                }
            }

            if (leader) ans.push_back(nums[i]); 
        }

        return ans;
    }
};