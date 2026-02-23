class Solution {
public:
    bool dfs(int node, int col, vector<int> &colour, vector<vector<int>> &graph){
        colour[node] = col;

        for(auto it : graph[node]){
            if(colour[it] == -1){
                if(!dfs(it, 1-col, colour, graph)){
                    return false;
                }
            }
            else if(colour[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);

        for(int i = 0; i < n; i++){
            if(colour[i] == -1){
                if(!dfs(i, 0, colour, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};