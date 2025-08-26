#include <bits/stdc++.h>

using namespace std;

// iterative

int search(vector<int> &nums, int target)
{
    int left = 0, high = nums.size() - 1;

    while (left <= high)
    {
        int mid = left + (high - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// recursive

int bs(vector<int>&nums, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;

    if(nums[mid]==target) return mid;
    else if(target>nums[mid]) return bs(nums, mid+1,high, target);
    return bs(nums, low, high-1, target);
}

int search(vector<int> &nums, int target)
{
    return bs(nums, 0, nums.size()-1, target);
}


// sheet    QS
/*

Given a sorted array of integers nums with 0-based indexing, find the index of a specified target integer. If the target is found in the array, return its index. If the target is not found, return -1.
Examples:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: The target integer 9 exists in nums and its index is 4
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: The target integer 2 does not exist in nums so return -1
*/

// sol->


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};