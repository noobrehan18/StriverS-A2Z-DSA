/*Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.*/

//SOLTION->

// brute force approach
 // t.c-->> 0(n^2) and 
 // s.c-O(1) 
 
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=s.length();
        for(int cnt=1;cnt<=m;cnt++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s==goal){
                return true;
            }
        }
        return false;       
    }
};