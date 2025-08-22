#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// better
int missingNum(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// optimal

int missNum(int arr[], int n)
{
    int sum = n * (n + 1) / 2;
    int s2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        s2 += arr[i];
    }
    return (sum - s2);
}

//  better optimal

int missingNumber(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i <= n; i++)
    {
        xor1 = xor1 ^ i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
    }
    return (xor1 ^ xor2);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // int missingNumber = missingNum(arr,n);
    // cout<<missingNumber;

    // cout<<missNum(arr,n);

    cout << missingNumber(arr, n);

    return 0;
}

/*
//                      sheet qs
Find missing number


Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.
Examples:
Input: nums = [0, 2, 3, 1, 4]
Output: 5
Explanation: nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]
Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]*/

// sol->

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),orgsum=0;
        for(auto el:nums) orgsum+=el;
        return (n*(n+1))/2 - orgsum;
    }
};
