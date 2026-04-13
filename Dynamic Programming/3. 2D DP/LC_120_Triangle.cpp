/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
	    for(int j=0;j<n;j++){
		    dp[n-1][j]=triangle[n-1][j];
	    }
	    for(int i=n-2;i>=0;i--){
		    for(int j=i;j>=0;j--){
			    int d=triangle[i][j]+dp[i+1][j];
			    int dg=triangle[i][j]+dp[i+1][j+1];
			    dp[i][j]=min(dg,d);
		    }
	    }
        return dp[0][0];
    }
};
