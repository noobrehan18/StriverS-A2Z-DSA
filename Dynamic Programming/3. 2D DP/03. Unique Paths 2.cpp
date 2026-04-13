/*given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
For Example :
Consider the maze below :
0 0 0 
0 -1 0 
0 0 0

There are two ways to reach the bottom left corner - 

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.*/

// method 1 : memoization

int f(int i, int j, vector< vector< int> > &mat,vector< vector< int> > &dp){
    if(i>=0 && j>=0 && mat[i][j]==-1 )return 0;
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=f(i-1,j,mat,dp);
    int left=f(i,j-1,mat,dp);

}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,mat,dp);
    
}
// method 2 : tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1)dp[i][j]=0;
            else if(i==0 && j==0)dp[i][j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
   
    
}
// method 3 : space optimization
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curi(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1)curi[j]=0;
            else if(i==0 && j==0)curi[j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0)up=prev[j];
                if(j>0)left=curi[j-1];
                curi[j]=up+left;
            }
        }
        prev=curi;
    }
    return prev[m-1];
}