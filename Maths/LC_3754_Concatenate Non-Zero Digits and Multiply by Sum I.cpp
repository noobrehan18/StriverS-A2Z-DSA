/*You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

 

Example 1:

Input: n = 10203004

Output: 12340 */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        int plce=1;
        int sum_digit=0;
        while(n>0){
            int d=n%10;
            n/=10;
            if(d==0)continue;
            x=d*plce+x;
            sum_digit+=d;
            plce*=10;
        }
        return x*sum_digit;
    }
};