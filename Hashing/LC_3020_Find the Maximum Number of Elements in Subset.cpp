/*You are given an array of positive integers nums.

You need to select a subset of nums which satisfies the following condition:
You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
Return the maximum number of elements in a subset that satisfies these conditions.

Example 1:
Input: nums = [5,4,1,2,2]
Output: 3 */

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int ans = 1;
        if (freq.find(1) != freq.end()) {
            int cnt = freq[1];
            ans = max(ans, (cnt % 2 == 0) ? cnt - 1 : cnt);
        }
        const long long LIMIT = 3037000499LL;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            long long cur = it->first;
            if (cur == 1)
                continue;
            int len = 0;
            while (true) {
                auto p = freq.find(cur);
                if (p == freq.end() || p->second < 2)
                    break;
                len += 2;
                if (cur > LIMIT) {
                    cur = -1;
                    break;
                }
                cur = cur * cur;
            }
            if (cur != -1) {
                auto p = freq.find(cur);
                if (p != freq.end() && p->second >= 1)
                    ans = max(ans, len + 1);
                else
                    ans = max(ans, max(1, len - 1));
            } else {
                ans = max(ans, max(1, len - 1));
            }
        }
        return ans;
    }
};