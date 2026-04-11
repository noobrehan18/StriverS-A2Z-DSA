/*A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.

Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.
Example 1
Input: heights = [10, 5, 20, 0, 15], k = 2
Output: 15*/



class Solution {
public:
    int f(int i, vector<int>& h, int k, vector<int>& dp) {
        if (i == 0) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                ans = min(ans, f(i - j, h, k, dp) + abs(h[i] - h[i - j]));
            }
        }

        return dp[i] = ans;
    }

    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return f(n - 1, heights, k, dp);
    }
};
// Tabulation
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n=heights.size();
        vector<int>dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int minsteps=INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
                    minsteps=min(minsteps,jump);
                }
            }
            dp[i]=minsteps;
        }
        return dp[n-1];

    }
};