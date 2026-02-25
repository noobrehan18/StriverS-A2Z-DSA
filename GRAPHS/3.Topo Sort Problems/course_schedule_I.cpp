class Solution {
public:
    bool iscycledfs(int src ,vector<bool>&vis,vector<bool>&recpath,vector<vector<int>>&prerequisites){
        vis[src]=true;
        recpath[src]=true;
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            if(u == src){
                if(!vis[v]){
                    if(iscycledfs(v,vis,recpath,prerequisites)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recpath(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycledfs(i,vis,recpath,prerequisites)){
                    return false;
                }
            }
        }
        return true;  
    }
};