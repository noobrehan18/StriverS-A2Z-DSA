/*You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

 

Example 1:


Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m;
        int minCol = n;
        for (int i = 0; i < ops.size(); i++) {
            minRow = min(minRow, ops[i][0]);
            minCol = min(minCol, ops[i][1]);
        }
        return minRow * minCol;
    }
};