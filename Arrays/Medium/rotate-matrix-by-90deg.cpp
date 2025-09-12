#include <bits/stdc++.h>

using namespace std;


// brute force

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();

    vector<vector<int>> ans(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = ans[i][j];
        }
    }
}


// better

#include<bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat) {
  int n = mat.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    reverse(mat[i].begin(), mat[i].end());
  }
}

// sheet qs
/*          Rotate matrix by 90 degrees


Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.
Examples:
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]

Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]

Input: matrix = [[1, 1, 2], [5, 3, 1], [5, 3, 5]]
[[2, 1, 5], [1, 3, 3], [1, 5, 5]]
[[5, 3, 5], [1, 3, 5], [2, 1, 1]]
[[5, 5, 1], [3, 3, 1], [5, 1, 2]]
[[5, 3, 5], [1, 3, 5], [1, 1, 2]]

Submit
Unlock Gamification Challenge

Access comprehensive solutions, in-depth editorials, and additional learning resources.

Upgrade to Plus
Constraints:
n == matrix.length.
n == matrix[i].length.
1 <= n <= 100.
-104 <= matrix[i][j] <= 104

Hint 1


*/

// soltion->
// brute force approach
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-1-i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ans[i][j];
            }
        }
        
    }
};