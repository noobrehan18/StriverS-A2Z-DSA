/*Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
 */

 class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=i+k && j<n;j++){
                if(nums[i]==nums[j]){
                    return true ;
                }
            }
        }
        return false;
        
    }
};