/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100] */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> sol(n);  
        int left = 0;
        int right = n - 1;
        int ind = n - 1;
        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            
            if (leftSq > rightSq) {
                sol[ind] = leftSq;
                left++;
            } else {
                sol[ind] = rightSq;
                right--;
            }
            ind--;
        }
        return sol;
    }
};