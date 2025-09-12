/*Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/

// SOL-->>
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
