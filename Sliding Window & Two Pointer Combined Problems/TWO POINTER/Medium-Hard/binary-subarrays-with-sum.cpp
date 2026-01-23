class Solution {
public:
    int ans(vector<int>&nums,int goal){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        int n=nums.size();
        if(goal<0){
            return 0;
        }
        for(int r=0;r<n;r++){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            cnt=cnt+(r-l+1);
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return ans(nums,goal)-ans(nums,goal-1);
    }
};