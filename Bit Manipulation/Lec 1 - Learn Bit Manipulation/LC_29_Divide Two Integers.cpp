/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend== divisor) return true;
    bool sign=true;
    if(dividend>=0 && divisor<0) sign=false;
    if(dividend<=0 && divisor>0) sign=false;
    long long n = abs((long long)dividend);
    long long d = abs((long long)divisor);
   // divisor=abs(divisor);
    long q=0;
    while(n>=d){
        int cnt=0;
        while(n>=(d<<(cnt+1))){
            cnt ++;
        }
        q+=1<<cnt;
        n-=(d << cnt);
    }
    if (q == (1 << 31) && sign) {
        return INT_MAX;
    }
    if (q == (1 << 31) && !sign) {
        return INT_MIN;
    }
    return sign ? q : -q;

    }
};