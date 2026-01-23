/*Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). */


class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1);
        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;

            int mn = min({last[0], last[1], last[2]});
            if(mn != -1) {
                cnt += mn + 1;
            }
        }

        return cnt;
    }
};
