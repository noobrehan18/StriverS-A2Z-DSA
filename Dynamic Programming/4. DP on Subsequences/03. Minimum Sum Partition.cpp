// 1d dp solution tc: O(n*sum) sc: O(n*sum)
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
    for(int i = 0; i < n; i++)
        totalSum += arr[i];

    int k = totalSum / 2;

    vector<bool> dp(k + 1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++)
    {
        for(int target = k; target >= arr[i]; target--)
        {
            dp[target] = dp[target] || dp[target - arr[i]];
        }
    }

    for(int s1 = k; s1 >= 0; s1--)
    {
        if(dp[s1])
            return totalSum - 2 * s1;
    }

    return 0;
}

// 2d dp solution tc: O(n*totalSum) sc: O(n*totalSum)
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int totalSum = 0;
    for(int i = 0; i < n; i++)
        totalSum += arr[i];

    int k = totalSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    if(arr[0] <= k)
        dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int target = 1; target <= k; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;

            if(arr[i] <= target)
                take = dp[i - 1][target - arr[i]];

            dp[i][target] = take || notTake;
        }
    }

    int mini = INT_MAX;

    for(int s1 = 0; s1 <= k; s1++)
    {
        if(dp[n - 1][s1])
        {
            mini = min(mini, totalSum - 2 * s1);
        }
    }

    return mini;
}