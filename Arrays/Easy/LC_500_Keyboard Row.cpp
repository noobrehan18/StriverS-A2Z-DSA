/*Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

 

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]

Output: ["Alaska","Dad"]

*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3 = {'z','x','c','v','b','n','m'};
        vector<string> result;
        for (string word : words) {
            string lower = "";            
            for (char ch : word) {
                lower += tolower(ch);
            }
            unordered_set<char>* targetRow;            
            if (row1.count(lower[0])) {
                targetRow = &row1;
            } 
            else if (row2.count(lower[0])) {
                targetRow = &row2;
            } 
            else {
                targetRow = &row3;
            }
            bool valid = true;            
            for (char ch : lower) {
                if (!targetRow->count(ch)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result.push_back(word);
            }
        }
        return result;
    }
};