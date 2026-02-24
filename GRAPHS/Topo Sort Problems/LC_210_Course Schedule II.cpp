/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].*/

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