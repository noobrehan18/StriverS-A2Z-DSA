bool dfs(int node, int parent, int vis[], vector<int> adj[])
{
    vis[node] = 1;
    for (auto adjN : adj[node])
    {
        if (!vis[adjN])
        {
            if (dfs(adjN, node, vis, adj))
                return true;
        }
        else if (adjN != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, vis, adj))
                return true;
        }
    }
    return false;
}