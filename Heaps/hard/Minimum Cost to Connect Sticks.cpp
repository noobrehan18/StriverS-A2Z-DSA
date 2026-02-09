class Solution {
  public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> mh(sticks.begin(),sticks.end());
        int cost=0;
        while(mh.size()>=2){
            int first=mh.top();
            mh.pop();
            int second=mh.top();
            mh.pop();
            cost=cost+first+second;
            mh.push(first+second);
        }
        return cost;
    }
};