/*An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234] */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for (int len = lowLen; len <= highLen; len++) {
            for (int i = 0; i + len <= 9; i++) {
                int num = stoi(s.substr(i, len));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        return ans;
    }
};