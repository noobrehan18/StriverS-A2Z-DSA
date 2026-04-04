/*You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

 

Example 1:

Input: s = "010"
Output: "001"*/

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }
        int zeroes=s.size()-ones;
        return string(ones-1,'1')+string(zeroes,'0')+'1';

        
    }
};