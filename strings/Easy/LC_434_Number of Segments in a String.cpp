/*Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

 

Example 1:

Input: s = "Hello, my name is John"
Output: 5 */
class Solution {
public:
    int countSegments(string s) {
        int seg=0;
        int x=s.size();
        for(int i=0;i<x;i++){
            if(s[i]!= ' ' && (i==0 || s[i-1]== ' ')){
                seg++;
            }
        }
        return seg;
        
    }
};