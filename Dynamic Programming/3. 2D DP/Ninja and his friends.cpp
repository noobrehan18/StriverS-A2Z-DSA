/*We are given an ‘N*M’ matrix. Every cell of the matrix has some chocolates on it, mat[i][j] gives us the number of chocolates. 
We have two friends ‘Alice’ and ‘Bob’. initially, Alice is standing on the cell(0,0) and Bob is standing on the cell(0, M-1). 
Both of them can move only to the cells below them in these three directions: to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
 When Alica and Bob visit a cell, they take all the chocolates from that cell with them. It can happen that they visit the same cell, in that case, the chocolates need to be considered only once. 
 They cannot go out of the boundary of the given matrix, we need to return the maximum number of chocolates that Bob and Alice can together collect.

Examples
Example 1:
Input: ‘R’ = 3, ‘C’ = 4
‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21. */

//recursive 
int f(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid){
    if(j1<0 || j2>=c || j2>c)return -1e8;
    if(i==r-1){
        if(j1==j2)return grid[i][j2];
        else return grid[i][j1]+grid[i][j2];
    }
    //explore all path alice & bob together....
    int maxi=0;
    for(int dj1=-1;dj1<=+1;dj1++){
        for(int dj2=-1;dj2<=+1;dj2++){
            int val=0;
            if(j1==j2)val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f(i+1,j1+dj1,j2+dj2,r,c,grid);
            maxi=max(maxi,val);
        }
    }
    return maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0,0,c-1,r,c,grid);
   
}
//memoization
int f(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
   
    if(j1<0 || j2>=c || j2>c)return -1e8;
    if(i==r-1){
        if(j1==j2)return grid[i][j2];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    //explore all path alice & bob together....
    int maxi=0;
    for(int dj1=-1;dj1<=+1;dj1++){
        for(int dj2=-1;dj2<=+1;dj2++){
            int val=0;
            if(j1==j2)val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            val+=f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            maxi=max(maxi,val);
        }
    }
    return dp[i][j1][j2]= maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return f(0,0,c-1,r,c,grid,dp);
   
}

//tabulation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
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
