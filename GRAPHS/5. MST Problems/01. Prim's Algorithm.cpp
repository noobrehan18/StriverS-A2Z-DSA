/* QUESTION:

Given a weighted, undirected and connected graph of V vertices and E edges, the task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Example:

Input: 
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.

APPROACH:
- We will use Prim's algorithm to find the Minimum Spanning Tree (MST) of the graph.
- The idea is to start from any vertex (let's say vertex 0) and add it to the MST.
- Then, we will add the edges connected to vertex 0 to a priority queue (min-heap), where the edges are sorted based on their weights in ascending order.
- We will keep adding the edges with the minimum weight to the MST and add their connected vertices to the priority queue if they are not already in the MST.
- We will repeat this process until all vertices are added to the MST.

COMPLEXITY ANALYSIS:
- The time complexity of Prim's algorithm is O(V^2) using an adjacency matrix representation, where V is the number of vertices.
- If an adjacency list representation is used, the time complexity reduces to O(E + V log V), where E is the number of edges and log V is the time complexity of priority queue operations.
- The space complexity is O(V) for the priority queue and other data structures.

CODE:
*/
//sheet qs solution-->>
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edw=it[1];
                if(!vis[adjNode]){
                    pq.push({edw,adjNode});
                }
            }
        }
        return sum;
        

    }
};

// gfg qs solution-->>
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0, 0});
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                
                if(!vis[adjNode]){
                    pq.push({edw, adjNode});
                }
            }
        }
        
        return sum;
    }
}