/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
*/

class Solution {
public:
    int ans(vector<int>&nums,int goal){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        int n=nums.size();
        if(goal<0){
            return 0;
        }
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            cnt=cnt+(r-l+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums,goal)-ans(nums,goal-1);
    }
};