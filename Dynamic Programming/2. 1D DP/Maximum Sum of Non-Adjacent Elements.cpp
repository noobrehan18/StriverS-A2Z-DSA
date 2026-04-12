//recursive approach      //tc:O(2^n) sc:O(n)
int f(int i, vector<int> &nums){
    if(i==0)return nums[i];
    if(i<0)return 0;

    int pick=nums[i]+f(i-2,nums);
    int notpick=0+f(i-1,nums);
    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return f(n-1,nums);

  
}
//memoization approach      //tc:O(n) sc:O(n)+O(n)
int f(int i, vector<int> &nums, vector<int> &dp) {
    if (i == 0) return nums[i];
    if (i < 0) return 0;

    if (dp[i] != -1) return dp[i];

    int pick = nums[i] + f(i - 2, nums, dp);
    int notpick = f(i - 1, nums, dp);

    return dp[i] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, -1);  
    return f(n - 1, nums, dp);
}
//tabulation approach      //tc:O(n) sc:O(n)

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();             
    vector<int> dp(n);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int take = nums[i];

        if (i - 2 >= 0)             
            take += dp[i - 2];      

        int nottake = dp[i - 1];

        dp[i] = max(take, nottake);
    }

    return dp[n - 1];
}