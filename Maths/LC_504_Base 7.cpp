/*Given an integer num, return a string of its base 7 representation.

 

Example 1:

Input: num = 100
Output: "202" */

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool neg = num < 0;
        int n = abs(num);
        string ans;
        while (n > 0) {
            ans.push_back((n % 7) + '0');
            n /= 7;
        }
        if (neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};