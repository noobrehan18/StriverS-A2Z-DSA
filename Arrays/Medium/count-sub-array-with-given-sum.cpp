#include<bits/stdc++.h>

using namespace std;


// better 
int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
  int cnt = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                cnt++;
            }
        }
    }
    return cnt;
}
// TC - 0(N^2)


// optimal
 int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        mpp[0]=1;
        int preSum=0, cnt=0;

        for(int i=0; i<n; i++){
            preSum+=nums[i];
            int remove = preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }

int main(){
    return 0;
}

/*          sheet qs->>
Count subarrays with given sum

Hints
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
Examples:
Input: nums = [1, 1, 1], k = 2
Output: 2
Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.
Input: nums = [1, 2, 3], k = 3
Output: 2
Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
*/


//sol->

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int >mpp;
        mpp[0]=1;
        int preSum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            int remove=preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]+=1;
        }
        return cnt;
    }
};