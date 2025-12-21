int setKthBit(int n, int k) {
       
    return (n | (1<<k));
 }
/*Check if the i-th bit is Set or Not
Subscribe to TUF+
Hints
Company
Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.
Example 1
Input: n = 5, i = 0
Output: true
Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set (1).
*/



class Solution {
public:
    bool checkIthBit(int n, int i) {
        if((n &(1<<i))!=0){
            return true;
        }
        else{
            return false;
        }

        
    }
};