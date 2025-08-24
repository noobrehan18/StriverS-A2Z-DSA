/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

// BETTER APPROACH

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();                          // t.c->O(2n)
        int cnt_0=0,cnt_1=0,cnt_2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) cnt_0++;
            else if(nums[i]==1) cnt_1++;
            else cnt_2++;
            
        }
        for(int i=0;i<cnt_0;i++) nums[i]=0;
        for(int i=cnt_0;i<cnt_0 + cnt_1;i++) nums[i]=1;
        for(int i=cnt_0 + cnt_1;i<n;i++) nums[i]=2;
    }
};
