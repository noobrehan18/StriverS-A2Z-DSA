/*You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        for(int j1 = 0; j1 < m; j1++){
            for(int j2 = 0; j2 < m; j2++){
                if(j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
            for(int i = n-2; i >= 0; i--){
                for(int j1 = 0; j1 < m; j1++){
                    for(int j2 = 0; j2 < m; j2++){
                        int maxi = -1e8;
                        for(int dj1 = -1; dj1 <= 1; dj1++){
                            for(int dj2 = -1; dj2 <= 1; dj2++){
                                int val = 0;
                                if(j1 == j2) val = grid[i][j1];
                                else val = grid[i][j1] + grid[i][j2];

                                if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m){
                                    val += dp[i+1][j1 + dj1][j2 + dj2];
                                }
                                else{
                                    val += -1e8;
                                }
                                maxi = max(maxi, val);
                            }
                        }
                        dp[i][j1][j2] = maxi;
                    }
                }
            }
            return dp[0][0][m-1];            
    }
};
