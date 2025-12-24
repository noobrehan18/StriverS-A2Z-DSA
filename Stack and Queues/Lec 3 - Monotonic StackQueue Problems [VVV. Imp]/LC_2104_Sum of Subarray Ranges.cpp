/*You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.*/

class Solution {
public:
    // MINIMUM 
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    // Previous Smaller Element (PSE)
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }
    // MAXIMUM
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }
    //  (PGE)
    vector<int> findPGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n, -1);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGE(arr);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += (long long)arr[i] * left * right;
        }
        return total;
    }


    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};