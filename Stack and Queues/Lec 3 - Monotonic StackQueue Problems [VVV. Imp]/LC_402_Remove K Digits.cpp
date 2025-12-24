/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.*/
class Solution {
    public:
        string removeKdigits(string num, int k) {
            stack<char> st;
            
            for (int i = 0; i < num.size(); i++) {
                while (!st.empty() && k > 0 && st.top() > num[i]) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
            
            while (k > 0 && !st.empty()) { 
                st.pop();
                k--;
            }
    
            if (st.empty()) return "0";
    
            string res = "";
            while (!st.empty()) {
                res += st.top();
                st.pop();
            }
    
            reverse(res.begin(), res.end());
    
            while (!res.empty() && res.front() == '0') {
                res.erase(res.begin());
            }
    
            return res.empty() ? "0" : res;
        }
    };