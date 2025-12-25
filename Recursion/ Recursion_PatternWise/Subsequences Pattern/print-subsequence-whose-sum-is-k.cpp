/*Check if there exists a subsequence with sum K
Subscribe to TUF+
Hints
Company
Given an array nums and an integer k. R﻿eturn true if there exist subsequences such that the sum of all elements in subsequences is equal to k else false.
Example 1
Input : nums = [1, 2, 3, 4, 5] , k = 8
Output : Yes
Explanation : The subsequences like [1, 2, 5] , [1, 3, 4] , [3, 5] sum up to 8.*/

// sheet solve solution--

class Solution{
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return helper(0,0,nums,k);
         
    }
    private:
        bool helper(int ind,int sum,vector<int>& nums, int k)
        if(ind==nums.size()){
            return sum==k;
        }
        // pick
        if(helper(ind+1,sum+nums[ind],nums,k)){
            return true;
        }
        //not pick 
        if(helper(ind+1,,nums,k)){
            return true;
        
        return false;
    }
};



//////////////
#include <bits/stdc++.h>

using namespace std;

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        // condition statisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind + 1, ds, s, sum, arr, n);

    s -= arr[ind];
    ds.pop_back();

    // not pick
    printS(ind + 1, ds, s, sum, arr, n);
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);

    return 0;
}