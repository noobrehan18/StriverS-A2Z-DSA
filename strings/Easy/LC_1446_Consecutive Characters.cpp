/*The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.*/

//SOLTION->>
class Solution {
public:
    int maxPower(string s) {
        int ans=1;
        int x=1;
        int n=s.length();
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                x++;
            }
            else{
                ans=max(ans,x);
                x=1;
            }
        }
        ans=max(ans,x);
        return ans;       
    }
};