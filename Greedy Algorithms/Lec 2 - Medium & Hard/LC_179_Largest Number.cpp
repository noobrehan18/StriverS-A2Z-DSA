/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210" */

class Solution {
public:
    static bool cmp(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), cmp);
        if (arr[0] == "0") return "0";

        string result;
        for (string &s : arr) {
            result += s;
        }
        return result;
    }
};