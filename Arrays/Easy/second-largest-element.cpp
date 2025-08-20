/*
Second Largest Element

Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
Examples:
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned*/

//sheet solution-


class Solution {
   public:
    int secondLargestElement(vector<int>& nums) {
        int first = INT_MIN, sec = INT_MIN;
        for (int nums:nums){
              if (nums > first) {               
                sec = first;
                first = nums;
            } else if (nums < first && nums > sec) {
                sec = nums;
            }
        }    
        return (sec == INT_MIN) ? -1 : sec;
    }    
};

