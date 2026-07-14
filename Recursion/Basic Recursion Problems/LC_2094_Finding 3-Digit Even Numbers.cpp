/*You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

 

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320] */

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0)
                continue; 
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;
                    if (digits[k] % 2 != 0)
                        continue; 
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    st.insert(num);
                }
            }
        }
        return vector<int>(st.begin(), st.end());
    }
};