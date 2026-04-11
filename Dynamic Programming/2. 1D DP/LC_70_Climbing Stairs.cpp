/*ou are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2 */

//memoization way
class Solution {
public:
    int fun(int n,vector<int>&dp){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};