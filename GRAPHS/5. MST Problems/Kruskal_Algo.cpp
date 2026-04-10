class DisjointSet {
    vector<int> rank,parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node])return node;

        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u == ulp_v){return;}
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &adjLs) {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(auto it:adjLs){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            edges.push_back({wt,{u,v}});
        } 
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mst=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                mst+=wt;
                ds.unionByRank(u,v);
            }
        }
        return mst;
    }
};