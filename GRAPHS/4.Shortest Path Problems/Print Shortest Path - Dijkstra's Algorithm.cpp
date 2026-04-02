vector<int> printShortestPath(int n, vector<vector<int>> adj[], int s, int dest) {
    vector<int> dis(n, 1e9), parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto p : adj[u]){
            int v = p[0], wt = p[1]; 
            if(dis[u] + wt < dis[v]){
                dis[v] = dis[u] + wt;
                parent[v] = u; // store the parent of vertex v
                pq.push({dis[v], v});
            }
        }
    }

    // reconstruct the shortest path from source to destination
    vector<int> path;
    if(dis[dest] == 1e9) return {-1}; // if destination is unreachable

    for(int v = dest; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // reverse the path to get the correct order

    return path;
}