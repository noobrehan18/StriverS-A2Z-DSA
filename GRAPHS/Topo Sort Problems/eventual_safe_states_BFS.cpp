class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revadj(n);
        vector<int>outdeg(n);
        for(int i=0;i<n;i++){
            outdeg[i]+=graph[i].size();
            for(auto j:graph[i]){
               revadj[j].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if (outdeg[i]==0){
                q.push(i);
            }
        }
        vector<int>sol;
        while(!q.empty()){
            int w=q.size();
            while(w--){
                int node=q.front();
                q.pop();
                sol.push_back(node);

                for(auto v:revadj[node]){
                    outdeg[v]--;
                    if (outdeg[v]==0){
                        q.push(v);
                    }
                }
            }
        }
        sort(sol.begin(),sol.end());
        return sol;
    }
};