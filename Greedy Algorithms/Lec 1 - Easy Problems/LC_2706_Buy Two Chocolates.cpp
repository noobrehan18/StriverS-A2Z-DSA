/*You are given an integer array prices representing the prices of various chocolates in a store. You are also given a single integer money, which represents your initial amount of money.

You must buy exactly two chocolates in such a way that you still have some non-negative leftover money. You would like to minimize the sum of the prices of the two chocolates you buy.

Return the amount of money you will have leftover after buying the two chocolates. If there is no way for you to buy two chocolates without ending up in debt, return money. Note that the leftover must be non-negative.

 

Example 1:

Input: prices = [1,2,2], money = 3
Output: 0*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        int mincost= INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=prices[i]+prices[j];
                if(cost<=money){
                    mincost=min(mincost,cost);
                }
            }
        }
        if(mincost==INT_MAX){
            return money;
        }
        else{
            return money-mincost;
        }
    }
};