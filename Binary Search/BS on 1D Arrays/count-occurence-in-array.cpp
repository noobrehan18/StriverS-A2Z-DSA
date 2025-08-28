#include <bits/stdc++.h>
using namespace std;
// first occurance

int firstOccurance(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      first = mid;
      high = mid - 1;
    } else if(arr[mid]<x){
        low = mid + 1;
    }else{
        high = mid - 1;
    }
  }
  return first;
}

// last occurance

int lastOccurance(vector<int> &arr, int n, int x) {
  int low = 0, high = n - 1;
  int last = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      last = mid;
      low = mid + 1;
    } else if(arr[mid]<x){
      low = mid + 1;
    }else{
        high = mid - 1;
    }
  }
  return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k) {
  int first = firstOccurance(arr, n, k);
  if(first==-1) return {-1,-1};
  int last = lastOccurance(arr,n,k);
  return {first, last};
}


int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans = firstAndLastPosition(arr, n, x);
	if(ans.first==-1) return 0;
	return ans.second - ans.first+1;
}
// sheet qs sol->> uisng C++ stl

/*                  Count Occurrences in a Sorted Array

You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.

Return the count of occurrences of target in the array.
Examples:
Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
Output: 3
Explanation: The number 1 appears 3 times in the array.
Input: arr = [5, 5, 5, 5, 5, 5], target = 5
Output: 6
Explanation: All elements in the array are 5, so the target appears 6 times.*/
// same as find first and last position some treeks in this count find 

//soltion->

class Solution {
public:
    vector<int> search_stl(const vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int rb = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};
        return {lb, rb - 1};
    }

    int countOccurrences(const vector<int>& arr, int target) {
        vector<int> count = search_stl(arr, target);
        if (count[0] == -1) return 0;
        return (count[1] - count[0] + 1);
    }
};

