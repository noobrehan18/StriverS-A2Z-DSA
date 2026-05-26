/*You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

Return the number of special letters in word.

 

Example 1:

Input: word = "aaAbcBC"

Output: 3
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower, upper;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(tolower(ch));
        }
        int count = 0;
        unordered_set<char>::iterator it;
        for (it = lower.begin(); it != lower.end(); it++) {
            if (upper.count(*it))
                count++;
        }
        return count;
    }
};