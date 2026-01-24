/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/

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