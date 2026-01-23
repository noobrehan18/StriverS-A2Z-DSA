class Solution {
public:
    int ans(vector<int>&nums,int k){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        int n=nums.size();
        if(k<0){
            return 0;
        }
        for(int r=0;r<n;r++){
            if(nums[r]%2==1){
                k--;
            }
            while(k<0){
                if(nums[l]%2==1){
                    k++;
                }
                l++;
            }
            cnt=cnt+(r-l+1);
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return ans(nums,k)-ans(nums,k-1);
    }
};