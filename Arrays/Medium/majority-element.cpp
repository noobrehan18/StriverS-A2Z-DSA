#include <bits/stdc++.h>

using namespace std;

// brute force

int majorityElement(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                cnt++;
            }
            if (cnt > n / 2)
                return arr[i];
        }
    }
    return -1;
}

// better

int majorityElementBetter(vector<int> arr)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (arr.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// optimal

int majorityElementOptimal(vector<int>arr){
    int cnt =0;
    int el;

    for(int i=0; i<arr.size(); i++){
        if(cnt==0){
            cnt=1;
            el=arr[i];
        }else if(arr[i]==el){
            cnt++;
        }else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==el) cnt1++;
    }
        if(cnt1>(arr.size()/2)){
            return el;
        }
        return -1;
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    // cout<<majorityElement(arr,n);

    // cout << majorityElementBetter(arr);

    // optimal output

    cout<<majorityElementOptimal(arr);

    return 0;
}

//sheet qs->


/*Majority Element-I

Given an integer array nums of size n, return the majority element of the array.

The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.
Examples:
Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]
Output: 7
Explanation: The number 7 appears 5 times in the 9 sized array
Input: nums = [1, 1, 1, 2, 1, 2]
Output: 1
Explanation: The number 1 appears 4 times in the 6 sized array
*/

//sol->>>>>

class Solution {
public:
    int majorityElement(vector<int>& nums) {      
        int n=nums.size();
        for(int i=0;i<n;i++){                           // brute force approach
            int cnt=0;
            for(int j=0;j<n;j++){
                if (nums[j]==nums[i])
                    cnt++;
            }
                if(cnt>n/2) return nums[i];
        }
        return -1;
    }
};

