/*you are given an integer n.
The score of n is defined as the sum of d * freq(d) over all distinct digits d, where freq(d) denotes the number of times the digit d appears in n.
Return an integer denoting the score of n.
Example 1:
Input: n = 122
Output: 5*/

class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = {0};
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        int score = 0;
        for (int d = 0; d <= 9; d++) {
            score += d * freq[d];
        }
        return score;
    }
};