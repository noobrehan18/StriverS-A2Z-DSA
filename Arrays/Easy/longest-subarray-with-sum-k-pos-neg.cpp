//                      CODE->

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int longSubArrWithSumK(int arr[], int n, long long k) {
   map<long long, int> prefixSumMap; 
    long long sum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == k) {
            maxLength = i + 1;
        }

        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[sum - k]);
        }

        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }

    return maxLength;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longSubArrWithSumK(arr, n, k) << endl;
    return 0;
}

/*
            Longest subarray with sum K

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Examples:
Input: nums = [10, 5, 2, 7, 1, 9],  k=15
Output: 4
Explanation:
The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
Input: nums = [-3, 2, 1], k=6
Output: 0
Explanation:
There is no sub-array in the array that sums to 6. Therefore, the output is 0.*/

