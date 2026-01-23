/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.*/


//Brute force:
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;

        for(int i=0;i<n;i++){
            int zeroes=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeroes++;
                }
                if(zeroes<=k){
                    int len=j-i+1;
                    maxlen=max(maxlen,len);
                }
                else{
                    break;
                }
                
            }
        }
        return maxlen;
    }
};

// optimal:
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int maxLen = 0;
            int l = 0;
            int zeros = 0;
    
            for (int r = 0; r < n; ++r) {
                if (nums[r] == 0)
                    zeros++;
    
                while (zeros > k) {
                    if (nums[l] == 0)
                        zeros--;
                    l++;
                }
    
                maxLen = max(maxLen, r - l + 1);
            }
    
            return maxLen;
        }
    };