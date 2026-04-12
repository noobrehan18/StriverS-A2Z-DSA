/*Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.

All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.

For example:
(i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)*/

#include <bits/stdc++.h> 
long long maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    long long prev = nums[0];
    long long prev2 = 0;
    for (int i = 1; i < n; i++) {
        long long  take = nums[i];
        if (i > 0) {
            take += prev2;
        }
        long long nottake = prev;

        long long curi = max(take, nottake);

        prev2 = prev;
        prev = curi;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse){
    vector<int>temp1,temp2;
    int n=valueInHouse.size();
    if (n==1)return valueInHouse[0];
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);
        if(i!=n-1)temp2.push_back(valueInHouse[i]);

    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
   
}