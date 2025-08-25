#include<bits/stdc++.h>

using namespace std;

int longestConsequtiveSeq(int arr[], int n){
    if(n==0) return 0;
    int longest =1;
    unordered_set<int>st;

    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1)==st.end()){
            int cnt = 1;
            int x= it;
            while (st.find(x+1)!=st.end())
            {
                x+=1;
                cnt+=1;
            }
            longest = max(longest, cnt);
            
        }
    }
    return longest;

}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<longestConsequtiveSeq(arr,n);
    return 0;
}

//                      sheet    QS----->
/*Longest Consecutive Sequence in an Array

Given an array nums of n integers.

Return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.
Examples:
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation:
The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation:
The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. */


//SOLTION->
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last_smallest=INT_MIN;
        int cnt=0;
        int longest=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1==last_smallest){
                cnt+=1;
                last_smallest=nums[i];
            }
            else if(nums[i]!=last_smallest){
                cnt=1;
                last_smallest=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;

    }
};