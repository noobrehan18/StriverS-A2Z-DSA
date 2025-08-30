#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[low] <= arr[mid]) {
      if (arr[low] < ans) {
        ans = arr[low];
        index = low;
      }
      low = mid + 1;
    } else {
      if (arr[mid] < ans) {
        ans = arr[mid];
        index = mid;
      }
      high = mid - 1;
    }
  }
  return index;
}

// sheet qs

/*Find out how many times the array is rotated


0

100
Easy

Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.
Examples:
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 4
Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.
Input: nums = [3, 4, 5, 1, 2]
Output: 3
Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.*/

// soltiion->

class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int low=0, high=nums.size()-1;
        int rot=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[low]<=nums[high]){
                if(nums[low]<rot){
                    index=low;
                    rot=nums[low];
                }
                break;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=nums[mid]){
                     index=low;
                     rot=nums[low];
                }
                low=mid+1;
            }
            else {
                high=mid-1;
                if(nums[mid-1]<rot){
                    index=mid;
                    rot=nums[mid];

                }
            }
        }
        return index;

        
    }
};