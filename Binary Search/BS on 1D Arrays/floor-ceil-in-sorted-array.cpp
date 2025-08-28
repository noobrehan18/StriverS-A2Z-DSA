#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    int floor = -1, ceil = -1;

    // floor
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x)
        {
            floor = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    //  ceil
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x)
        {
            ceil = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return {floor, ceil};
}

// using c++ stl

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    auto ceil_it = lower_bound(a.begin(), a.end(), x);

    auto floor_it = upper_bound(a.begin(), a.end(), x);

    int floor = (floor_it != a.begin()) ? *(--floor_it)
                                        : -1;
    int ceil =
        (ceil_it != a.end()) ? *ceil_it : -1;

    return {floor, ceil};
}

// sheet QS->

/*                  Floor and Ceil in Sorted Array

Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.
Examples:
Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
Input : nums =[3, 4, 4, 7, 8, 10], x= 8
Output: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

//sol->>

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor=-1, ceil=-1;
        for(int i=0,i<nums.size(),i++){
            int num=nums[i];
            if(num<=x){
                floor=num;
            }
            if(num>x && ceil==-1){
                ceil=num;
            }
        }
        return {floor,ceil};
   
    }
};
