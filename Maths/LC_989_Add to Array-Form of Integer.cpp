/*The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

 

Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4] */

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size() - 1;
        while (i >= 0 || k > 0) {
            if (i >= 0) k += num[i--];
            ans.push_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};