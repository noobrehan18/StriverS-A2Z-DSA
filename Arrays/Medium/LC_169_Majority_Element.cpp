/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

// BRUTE FORCE APPROACH->
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if (nums[j]==nums[i])                   // it is too slow for large input sizes
                    cnt++;                              // 52/53 test cases passed so i will not consider this 
            }                                               // proceed to better approach-> below 
                if(cnt>n/2) return nums[i];
        }
        return -1;
    }
};

// BETTER APPROACH->

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>nums.size()/2){
                return it.first;
            }
        }
        return -1;
    }
};