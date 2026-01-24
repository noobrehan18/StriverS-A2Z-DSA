class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxinx=0;
        for(int i=0;i<n;i++){
            if(i>maxinx){
                return false;
            
            }
            maxinx=max(maxinx,i+nums[i]);
        }
        return true;
    }
};