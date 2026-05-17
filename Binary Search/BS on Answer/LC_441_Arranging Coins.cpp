/*You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.


Input: n = 5
Output: 2*/

class Solution {
public:
    int arrangeCoins(int n) {
        long long low=1;
        long long high=n;
        long long sol=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long  coinsNeed=mid*(mid+1)/2;
            if(coinsNeed<=n){
                sol=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return sol;
    }
};