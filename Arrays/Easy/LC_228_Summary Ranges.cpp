/*You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"] */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>sol;
        int n=nums.size();
        for(int i=0;i<n;){
            int st=nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1){
                i++;
            }
            int end=nums[i];
            if(st==end){
                sol.push_back(to_string(st));
            }
            else{
                sol.push_back(to_string(st)+ "->" + to_string(end));
            }
            i++;
        }
        return sol;
    }
};