/*Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1 */

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        int n=text.size();
        for (int i = 0; i < n; i++) {
            freq[text[i] - 'a']++;
        }
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};