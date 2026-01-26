/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.*/
class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1){
            return 0;
        }

        sort(intervals.begin(),intervals.end(), comp);
        int cnt=1;
        int lastEndTime=intervals[0][1];

        for(int i=0;i<n;i++){
            if(intervals[i][0]>=lastEndTime){
                cnt++;
                lastEndTime=intervals[i][1];
            }
            
        }
        return n-cnt;
    }
};