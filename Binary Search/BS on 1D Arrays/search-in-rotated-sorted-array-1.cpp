#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;

            // Check for left half sorted array
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Check for right half sorted array
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }


// sheet qs sol->

class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0, high=n-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==k) return mid;
        
        // left sorted 
            if(nums[low]<=nums[mid]){
                if(nums[low]<=k && k<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            
            }
            // for right sorted
            else{
                if(nums[mid]<=k && k<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        
        }  
        return -1; 
    }
};
