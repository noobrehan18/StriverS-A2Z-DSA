/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true */ 
//recursive solution.  tc- 0(N*TaRGET) 
                        //SC---> 0(N*TaRGET)+O(N)
class Solution {
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target)
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for(int i = 0; i < n; i++){
            totsum += nums[i];
        }
        if(totsum % 2) return false;
        int target = totsum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); 
        return f(n - 1, target, nums, dp);  
    }
};