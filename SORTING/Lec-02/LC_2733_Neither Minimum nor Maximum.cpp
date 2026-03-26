/*iven an integer array nums containing distinct positive integers, find and return any number from the array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.

Return the selected integer.

 

Example 1:

Input: nums = [3,2,1,4]
Output: 2*/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return -1;
        }
        sort(nums.begin(),nums.end());
        return nums[1];
        
    }
};