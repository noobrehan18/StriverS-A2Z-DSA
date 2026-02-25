void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans)
{
    vis[node] = 1;       // Mark the current node as visited
    ans.push_back(node); // Add the node to the result
    for (auto it : adj[node])
    { // Traverse all neighbors
        if (!vis[it])
        {                           // If neighbor is not visited
            dfs(it, adj, vis, ans); // Recursive call to DFS
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> &adj)
{
    int n = adj.size();        // Number of nodes in the graph
    vector<int> vis(n, 0);     // Visited array initialized to 0
    int start = 0;             // Start DFS from node 0
    vector<int> ans;           // Vector to store DFS traversal
    dfs(start, adj, vis, ans); // Call DFS function
    return ans;                // Return the DFS order
}