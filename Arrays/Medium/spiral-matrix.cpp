#include<bits/stdc++.h>

using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &MATRIX) {


  int n = MATRIX.size();
  int m = MATRIX[0].size();
  int left = 0, right = m - 1;
  int top = 0, bottom = n - 1;
  vector<int> ans;

  while (top <= bottom && left <= right) {
    // right
    for (int i = left; i <= right; i++) {
      ans.push_back(MATRIX[top][i]);
    }
    top++;

    // bottom
    for (int i = top; i <= bottom; i++) {
      ans.push_back(MATRIX[i][right]);
    }
    // left
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        ans.push_back(MATRIX[bottom][i]);
      }
      bottom--;
    }

    // top
    if(left<=right){
      for (int i = bottom; i >= top; i--) {
        ans.push_back(MATRIX[i][left]);
      }
      left++;
    }
  }
  return ans;
}

int main(){
    return 0;
}

// sheet qs
/*Print the matrix in spiral manner


0

100
Medium

Given an M * N matrix, print the elements in a clockwise spiral manner.

Return an array with the elements in the order of their appearance when printed in a spiral manner.
Examples:
Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
Explanation:
The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5
Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]
Output: [1, 2, 3, 4, 8, 7, 6, 5]
Explanation:
The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5*/

//sol->>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& MATRIX) {
        int n = MATRIX.size();
        int m = MATRIX[0].size();
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        vector<int> ans;
        while (top <= bottom && left <= right) {
            //  top row 
            for (int i = left; i <= right; i++) {
                ans.push_back(MATRIX[top][i]);
            }
            top++;
            // right col
            for (int i = top; i <= bottom; i++) {
                ans.push_back(MATRIX[i][right]);
            }
            right--;
            if (top <= bottom) {
                // bottom row 
                for (int i = right; i >= left; i--) {
                    ans.push_back(MATRIX[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                // left col
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(MATRIX[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
