/*Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]*/

class Solution {
public:
    void quicksort(vector<int>& nums,int low,int high){
        if(low>=high)return;
        int ranidx = low + rand() % (high - low + 1);
        swap(nums[ranidx], nums[high]);
        int pivot=nums[high];
        int i=low-1;

        for(int j=low;j<high;j++){
            if(nums[j]<pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        int pi=i+1;
        quicksort(nums,low,pi-1);
        quicksort(nums,pi+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        quicksort(nums,0,n-1);
        return nums;
        
    }
};