/*Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.

Find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.
Example 1
Input: n = 9, m = 10, edges = [[0,1],[0,3],[3,4],[4,5],[5, 6],[1,2],[2,6],[6,7],[7,8],[6,8]]

Output: 0 1 2 1 2 3 3 4 4 */

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M) {
        
        vector<vector<int>> adj(N);
        
        // Build graph
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(N, false);
        vector<int> dist(N, -1);
        
        queue<int> q;
        
        q.push(0);
        vis[0] = true;
        
        int lvl = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                int node = q.front();
                q.pop();
                
                dist[node] = lvl;
                
                for (auto v : adj[node]) {
                    if (!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            lvl++;
        }
        
        return dist;
    }
};