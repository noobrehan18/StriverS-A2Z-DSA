/*there are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.*/

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