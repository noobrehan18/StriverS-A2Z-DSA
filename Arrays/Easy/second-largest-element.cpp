/*
Second Largest Element

Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
Examples:
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7
Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned*/

//sheet solution-
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
   public:
    int secondLargestElement(vector<int>& nums) {
        int first = INT_MIN, sec = INT_MIN;
        for (int nums:nums){
              if (nums > first) {               
                sec = first;
                first = nums;
            } else if (nums < first && nums > sec) {
                sec = nums;
            }
        }    
        return (sec == INT_MIN) ? -1 : sec;
    }    
};


//optimal approach->

int secondLarge(int arr[], int n)
{
    int largest = arr[0];
    int sLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            sLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sLargest)
        {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int secondSmall(int arr[], int n)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < secondSmallest)
        {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

void find_secondLargest(int arr[], int n)
{
    int secondLargest = secondLarge(arr, n);
    int secondSmallest = secondSmall(arr, n);
    cout << "Second Largest: " << secondLargest << endl;
    cout << "Second Smallest: " << secondSmallest << endl;
}

int main()
{
    int n;
    cin >> n;

    if (n < 2) 
    {
        cout << "Array must have at least 2 elements!" << endl;
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    find_secondLargest(arr, n);

    return 0;
}