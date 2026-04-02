class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]==1) return -1;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            if(r==m-1 && c==n-1) return dis;

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=r+i;
                    int ncol=c+j;
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                        grid[nrow][ncol]==0 && dis+1< dist[nrow][ncol]){
                            dist[nrow][ncol]=dis+1;
                            q.push({dis +1 ,{nrow,ncol}});
                        } 
                }
            }
        }
        return -1;
        
    }
};