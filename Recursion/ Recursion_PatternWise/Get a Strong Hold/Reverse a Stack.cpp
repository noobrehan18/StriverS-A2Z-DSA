/*Hints
Company
You are given a stack of integers. Your task is to reverse the stack using recursion. You may only use standard stack operations (push, pop, top/peek, isEmpty). You are not allowed to use any loop constructs or additional data structures like arrays or queues.

Your solution must modify the input stack in-place to reverse the order of its elements.
Example 1
Input: stack = [4, 1, 3, 2]

class Solution {
public:
    void reverseStack(stack<int> &st) {
        if (st.size() <= 1)
            return;

        int temp = st.top();
        st.pop();

        reverseStack(st);
        insertAtBottom(st, temp);
    }

    void insertAtBottom(stack<int> &st, int ele) {
        if (st.empty()) {
            st.push(ele);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, ele);
        st.push(temp);
    }
};
