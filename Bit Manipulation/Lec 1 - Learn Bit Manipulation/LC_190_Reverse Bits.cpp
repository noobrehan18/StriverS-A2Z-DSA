/*Reverse bits of a given 32 bits signed integer.
Example 1:
Input: n = 43261596

Output: 964176192*/

class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }
        return ans;
    }
};