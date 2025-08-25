#include<bits/stdc++.h>

using namespace std;


int buyAndSell(int prices[], int n){
    int mini = prices[0], profit=0;
    for(int i=1; i<n; i++){
        int cost = prices[i]-mini;
        profit = max(profit,cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}

int main(){
    int n;
    cin>>n;
    int prices[n];

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    cout<<buyAndSell(prices,n);


    return 0;
}

/* sheet qs->
Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. Determine the maximum profit achievable by buying and selling the stock at most once. 

The stock should be purchased before selling it, and both actions cannot occur on the same day.
Examples:
Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.
Input: arr = [5, 4, 3, 2, 1]
Output: 0
Explanation: In this case, no transactions are made. Therefore, the maximum profit remains 0.
*/

// soltion 
class Solution {
public:
    int stockBuySell(vector<int> arr, int n) {
        int mini = arr[0], profit = 0;
        for (int i = 1; i < n; i++) {
            int cost = arr[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, arr[i]);
        }
        return profit;
    }
};
