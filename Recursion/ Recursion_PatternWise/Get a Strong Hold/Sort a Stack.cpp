/*You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty).
Example 1
Input: stack = [4, 1, 3, 2]
Output: [4, 3, 2, 1]
Explanation:
After sorting, the largest element (4) is at the top, and the smallest (1) is at the bottom.
*/

class Solution {
public:
    void sortStack(stack<int> &st) {
        if (st.size() <= 1)
            return;

        int temp = st.top();
        st.pop();

        sortStack(st);
        insertSorted(st, temp);
    }

    void insertSorted(stack<int> &st, int val) {
        if (st.empty() || st.top() <= val) {
            st.push(val);
            return;
        }

        int temp = st.top();
        st.pop();

        insertSorted(st, val);
        st.push(temp);
    }
};