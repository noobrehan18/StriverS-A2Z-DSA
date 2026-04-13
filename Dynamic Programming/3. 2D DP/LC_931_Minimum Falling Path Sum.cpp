/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++)dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u=matrix[i][j]+dp[i-1][j];
                int ld=matrix[i][j];
                if(j-1>=0)ld+=dp[i-1][j-1];
                else ld+=1e8;
                int rd=matrix[i][j];
                if(j+1<m)rd+=dp[i-1][j+1];
                else rd+=1e8;
                dp[i][j]=min(u,min(ld,rd));
            }
        }
        int mini=1e8;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
        
    }
};