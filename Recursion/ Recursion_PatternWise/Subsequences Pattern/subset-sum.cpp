/*Given an array nums of n integers. Return array of sum of all subsets of the array nums.

Output can be returned in any order.
Example 1
Input : nums = [2, 3]
Output : [0, 2, 3, 5]
Explanation :
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then sum = 2+3 = 5.*/
class Solution {
public:
    void func(int ind, int sum, vector<int>& arr, int N, vector<int>& sumSubset) {
        if (ind == N) {
            sumSubset.push_back(sum);
            return;
        }
        
        // Pick the element
        func(ind + 1, sum + arr[ind], arr, N, sumSubset);
        
        // Do not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }
    
    vector<int> subsetSums(vector<int>& nums) {
        int N = nums.size();
        vector<int> sumSubset;
        
        func(0, 0, nums, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        
        return sumSubset;
    }
};
///

void func(int ind, int sum, vector<int>&arr, int N, vector<int> &sumSubset){
        if(ind == N){
            sumSubset.push_back(sum);
            return ;
        }
        
        // pick the element
        func(ind+1, sum+arr[ind], arr, N, sumSubset);
        
        // do not pick the element 
        func(ind + 1, sum, arr, N, sumSubset);
    }
    vector<int> subsetSums(vector<int>& arr) {
        int N = arr.size();
        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }