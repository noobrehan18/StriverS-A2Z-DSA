class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>sol;
        sort(intervals.begin(),intervals.end());

        for(int i=0; i<n;i++){
            if(sol.empty() || intervals[i][0]> sol.back()[1]){
                sol.push_back(intervals[i]);
            }
            else{
                sol.back()[1]=max(sol.back()[1],intervals[i][1]);
            }
        }
        return sol;
    }
};