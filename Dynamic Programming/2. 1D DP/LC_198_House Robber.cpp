/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4 */

//using memoization approach      //tc:O(n) sc:O(n)+O(n)
class Solution {
public:
    int fun(int i,vector<int>&nums,vector<int>&dp){
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=nums[i]+fun(i-2,nums,dp);
        int notpick=0+fun(i-1,nums,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fun(n-1,nums,dp);
        
    }
};

//using tabulation approach      //tc:O(n) sc:O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i-2>=0){
                take+=dp[i-2];
            }
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
        
    }
};

//using space optimization approach      //tc:O(n) sc:O(1)
int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();

    int prev = nums[0];
    int prev2 = 0;


    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i>0){
            take+=prev2;
        }  
        int nottake = prev;

        int curi = max(take, nottake);

        prev2 = prev;
        prev = curi;
    }

    return prev;  
}