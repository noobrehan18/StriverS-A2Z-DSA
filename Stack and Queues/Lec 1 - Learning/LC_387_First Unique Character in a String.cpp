/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"

Output: 0 */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        int n=s.size();
        for (int i = 0; i <n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};