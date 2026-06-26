/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:

Input: s = "bcabc"
Output: "abc" */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);
        int n=s.size();
        for (int i = 0;i<n;i++) {
            freq[s[i] - 'a']++;
        }
        string st = "";
        for (int i = 0;i<n;i++) {
            char c = s[i];
            freq[c - 'a']--;
            if (vis[c - 'a'])
                continue;
            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(c);
            vis[c - 'a'] = true;
        }
        return st;
    }
};