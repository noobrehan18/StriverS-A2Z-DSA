// Memoization

class Solution {
  public:
    int fun(int ind, vector<int>& height, vector<int>& dp) {
        if (ind == 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int left = fun(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

        int right = INT_MAX;
        if (ind > 1) {
            right = fun(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }

        return dp[ind] = min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return fun(n - 1, height, dp);
    }
};

// Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
       vector<int>dp(n,0);
       dp[0]=0;
       for(int i=1;i<n;i++){
           int fs=dp[i-1]+abs(height[i]-height[i-1]);
           int ss=INT_MAX;
           if(i>1){
               ss=dp[i-2]+abs(height[i]-height[i-2]);
           }
           dp[i]=min(fs,ss);
       }
       return dp[n-1];
        
    }
};

// Space Optimized
class Solution {
  public:
    int minCost(vector<int>& height) {
        int n=height.size();
        int prev=0;
        int prev2=0;
       for(int i=1;i<n;i++){
           int fs=prev+abs(height[i]-height[i-1]);
           int ss=INT_MAX;
           if(i>1){
               ss=prev2+abs(height[i]-height[i-2]);
           }
           int curi=min(fs,ss);
           prev2=prev;
           prev=curi;
       }
       return prev;
        
    }
};
