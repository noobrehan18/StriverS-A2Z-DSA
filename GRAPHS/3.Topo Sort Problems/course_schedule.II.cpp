class Solution {
public:
    vector<int>toposort(unordered_map<int,vector<int>>adj,int n,vector<int>&indeg){
        queue<int>q;
        vector<int>res;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                res.push_back(i);
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    res.push_back(v);
                    cnt++;
                    q.push(v);
                }
            }
        }
        if(cnt==n)
            return res;
        
        return{};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(numCourses,0);
        for(auto &vec :prerequisites){
            int n=vec[0];
            int m=vec[1];
            adj[m].push_back(n);
            indeg[n]++;
        }
        return toposort(adj,numCourses,indeg);
    }
};