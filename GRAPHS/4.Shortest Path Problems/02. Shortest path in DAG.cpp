/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array (or vector) edges[][] of length M, where there is a directed edge from edges[i][0] to edges[i][1] with a distance of edges[i][2] for all i.

Find the shortest path from the source (vertex 0) to all other vertices, and if it is impossible to reach any vertex, then return -1 for that vertex.

APPROACH:
- To find the shortest path from the source vertex to all other vertices in a Directed Acyclic Graph (DAG), we can use a topological sorting based approach along with dynamic programming (DP).
- First, we perform a topological sorting of the DAG. This will give us a linear order in which the vertices should be visited such that there are no backward edges.
- After obtaining the topological order, we initialize the distance array with a large value (infinity) for all vertices, except the source vertex whose distance is set to 0.
- We then iterate through the vertices in the topological order and update the distance for each vertex by considering all outgoing edges from that vertex and the distances of its neighboring vertices.
- Since the graph is a DAG, we are guaranteed that we visit all the parent nodes of a vertex before visiting the vertex itself. Hence, we can safely update the distance of each vertex in a topological order.
- After updating the distance array, if any vertex remains at the initial large value (infinity), it means that it is not reachable from the source vertex, and we set its distance to -1.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N + M), where N is the number of vertices and M is the number of edges in the graph. The time complexity is dominated by the topological sorting and DP updates.
- Space Complexity: O(N + M), where N is the number of vertices and M is the number of edges in the graph. We use additional space for the adjacency list, visited array, topological order, and the distance array.
*/

class Solution {
public:

    void dfs(int node, vector<pair<int,int>> adj[], vector<bool> &vis, vector<int> &topo) {
        vis[node] = true;
        for (auto &it : adj[node]) {
            if (!vis[it.first]) {
                dfs(it.first, adj, vis, topo);
            }
        }
        topo.push_back(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        
        // Step 1: Create adjacency list
        vector<pair<int,int>> adj[N];
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        // Step 2: Topological sort (DFS)
        vector<bool> vis(N, false);
        vector<int> topo;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, topo);
            }
        }

        reverse(topo.begin(), topo.end());

        // Step 3: Initialize distances
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Step 4: Relax edges
        for (auto &u : topo) {
            if (dist[u] != 1e9) {  // important check
                for (auto &it : adj[u]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 5: Replace unreachable nodes with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};