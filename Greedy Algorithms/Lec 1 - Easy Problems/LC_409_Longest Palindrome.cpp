/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7*/

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};
        for (char c : s) freq[c]++;
        int ans = 0;
        bool odd = false;
        for (int i = 0; i < 128; i++) {
            ans += (freq[i] / 2) * 2; 
            if (freq[i] % 2 == 1) {
                odd = true;
            }
        }
        if (odd) ans++; 
        return ans;
    }
};