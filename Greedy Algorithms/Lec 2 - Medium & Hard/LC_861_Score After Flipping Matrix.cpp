/*You are given an m x n binary matrix grid.

A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score after making any number of moves (including zero moves).

 

Example 1:


Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        res+=m*(1<<(n-1));
        for(int j=1;j<n;j++){
            int ones=0;
            for(int i=0;i<m;i++){
                if(grid[i][0]==1){
                    ones+=grid[i][j];
                }
                else{
                    ones+=(1-grid[i][j]);
                }
            }
            int maxOnes=max(ones,m-ones);
            res+=maxOnes*(1<<(n-j-1));
        }
        return res;
        
    }
};