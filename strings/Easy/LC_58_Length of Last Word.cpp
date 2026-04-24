/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        return length;
    }
};