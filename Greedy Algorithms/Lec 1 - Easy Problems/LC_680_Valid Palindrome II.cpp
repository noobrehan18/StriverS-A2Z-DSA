/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
*/

class Solution {
public:
    bool chk(string &s,int l,int r){
        while(l<r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return chk(s,l+1,r) || chk(s,l,r-1);
            }
        }
        return true;
        
    }
};