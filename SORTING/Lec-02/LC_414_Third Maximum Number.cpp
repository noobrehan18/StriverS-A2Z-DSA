/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());

        int n = v.size();
        if (n < 3) {
            return v[n - 1];
        }
        return v[n - 3];
    }
};