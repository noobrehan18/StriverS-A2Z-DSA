/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]*/

class MinStack {
private:
    std::stack<long long> st;
    long long mini;
public:
    MinStack() {    
    }
    
    void push(int val) {
        long long x = val;
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val>mini){
                st.push(val);
            }
            else{
                st.push(2LL * x - mini);
                mini=val;
            }
        }
        
    }
    long long x;
    
    void pop() {
        if(st.empty()){
            return;
        }
        x=st.top();
        st.pop();
        if(x<mini){
            mini=2LL * mini - x;
        }
        
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        x=st.top();
        if(mini<x){
            return x;
        }
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
        
    }
};