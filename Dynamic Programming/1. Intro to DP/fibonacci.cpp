/*
QUESTION:-
Find the nth fibonacci number.

Approach:
1. We can use dynamic programming to calculate the nth Fibonacci number.
2. We define a helper function fibo(n, dp) that calculates the nth Fibonacci number using memoization.
3. The function checks if the nth Fibonacci number is already calculated and stored in the dp array. If yes, it returns the value from dp.
4. Otherwise, it calculates the nth Fibonacci number by recursively calling fibo(n-1, dp) and fibo(n-2, dp) and stores the result in dp.
5. The base cases are when n is 0 or 1, in which case the function returns n.
6. In the main function, we take the input for n and create a dp array of size n+1 initialized with -1.
7. We then call the fibo function passing n and the dp array as arguments.
8. Finally, we print the value of dp[n], which represents the nth Fibonacci number.

Complexity Analysis:
- The time complexity of the fibo function is O(n) because we are calculating and storing the Fibonacci numbers from 0 to n.
- The space complexity is also O(n) to store the dp array.
*/


// recursion
int func(int n)
{
    if (n <= 1)
        return n;

    return func(n - 1) + func(n - 2);
}

// memoization
int func(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = func(n - 1, dp) + func(n - 2, dp);
}
// tabulation
int func(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
// further space optimization
int func(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int prev1 = 1;
    int prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}