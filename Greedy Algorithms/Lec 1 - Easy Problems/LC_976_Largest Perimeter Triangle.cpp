/*Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 

Example 1:

Input: nums = [2,1,2]
Output: 5
Explanation: You can form a triangle with three side lengths: 1, 2, and 2.
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            if(nums[i-1]+nums[i-2]>nums[i]){
                return(nums[i]+nums[i-1]+nums[i-2]);
            }
        }
        return 0;
    }
};