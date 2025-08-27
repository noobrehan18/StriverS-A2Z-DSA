/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109*/

//SOLTION->
            // USING c++ stl 
            // we can do with raw binary search also
class Solution {
public:
    vector<int>search_stl(vector<int>& nums,int target){
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int rb=upper_bound(nums.begin(),nums.end(),target)-nums.begin();

        if(lb==nums.size() || nums[lb]!=target)
            return {-1,-1};
        return {lb,rb-1};
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return search_stl(nums,target);
    }
};
