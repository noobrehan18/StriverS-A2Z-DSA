/*ou are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.

 

Example 1:

Input: nums = [2, 1, 3]
Output: false*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.back();
        int m=nums.size();

        if(m!=n+1)return false;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=i+1)return false;;
        }
        return nums[n-1]==n &&nums[n]==n;
        
    }
};