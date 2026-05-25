/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321 */

class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int n=INT_MIN;
        int m=INT_MAX;
        while(x!=0){
            int digit=x%10;
            if(rev>m/10 || rev<n/10){
                return 0;
            }
            rev=rev*10+digit;
            x/=10;
        }
        return rev;
    }
};