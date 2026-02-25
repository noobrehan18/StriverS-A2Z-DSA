class Solution{
public:
    void dfs(int node, int vis[],stack<int>&st,vector<int>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);

    }
    vector<int> topoSort(int V, vector<int> adj[]){
        vis[V]={0};
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj[]);
            }
        }
        vector<int>sol;
        while(!st.empty()){
            sol.push_back(st.top());
            st.pop;
        }
        return sol;
        
    }
};