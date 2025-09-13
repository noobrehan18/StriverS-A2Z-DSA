/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true

 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.*/

//SOLTION->

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128]={0};
        char map_t[128]={0};
        int l=s.size();

        for(int i=0;i<l;i++){
            if(map_s[s[i]]!=map_t[t[i]]) return false;
            map_s[s[i]]=i+1;
            map_t[t[i]]=i+1;
        }
        return true;      
    }
};