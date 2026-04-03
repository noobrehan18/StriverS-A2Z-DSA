/*ou are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2*/

class Solution {
public:
    typedef pair<int,pair<int,int>>tri;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<tri, vector<tri>, greater<tri>> pq;
        dis[0][0]=0;
        pq.push({0,{0,0}});
        vector<int>dr={0,0,1,-1};
        vector<int>dc={1,-1,0,0};
        int sol=INT_MIN;
        while(!pq.empty()){
            tri t=pq.top();
            pq.pop();
            int x=t.second.first;
            int y=t.second.second;
            sol=max(sol,t.first);
            if(x==n-1 && y==m-1)return sol;
            for(int i=0;i<4;i++){
                int nx=x+dr[i];
                int ny=y+dc[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && (dis[nx][ny]>
                    abs(heights[x][y]-heights[nx][ny]))){
                        dis[nx][ny]=abs(heights[x][y]-heights[nx][ny]);
                        pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return -1;
    }
};