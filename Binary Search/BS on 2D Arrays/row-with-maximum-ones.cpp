#include<bits/stdc++.h>

using namespace std;

// lower bound code 
int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      high = mid - 1; 
    }
    else {
      low = mid + 1;
    }
  }
  return ans;
}


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int max_ele = 0;
    int index = -1;

    for(int i=0; i<n; i++){
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if(cnt_ones>max_ele){
            max_ele = cnt_ones;
            index = i;
        }
    }
    return index;
}


// sheet qs->
/*
            Find row with maximum 1's


Given a non-empty grid mat consisting of only 0s and 1s, where all the rows are sorted in ascending order, find the index of the row with the maximum number of ones.
If two rows have the same number of ones, consider the one with a smaller index. If no 1 exists in the matrix, return -1.
Examples:
Input : mat = [ [1, 1, 1], [0, 0, 1], [0, 0, 0] ]
Output: 0
Explanation: The row with the maximum number of ones is 0 (0 - indexed).
Input: mat = [ [0, 0], [0, 0] ]
Output: -1
Explanation: The matrix does not contain any 1. So, -1 is the answer.*/

// soltion->
class Solution {
  public:   
    int rowWithMax1s(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxCount = 0;
        int rowIndex = -1;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            
            if (count > maxCount) {
                maxCount = count;
                rowIndex = i;
            }
        }
        
        if (maxCount == 0) return -1;  // no 1’s found
        return rowIndex;
    }
};
