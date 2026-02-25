vector<int>bfs(V,vector<int>adj[]){
    int vis[V]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
        return ans;
    }
}

// other way
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto i : adj[node]) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }

    return ans;
}