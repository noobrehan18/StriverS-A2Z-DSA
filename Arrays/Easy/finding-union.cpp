//code->
#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int unionArray(int arr1[], int arr2[], int n1, int n2, int uni[]){
    set<int>st;
    for(int i=0; i<n1; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(arr2[i]);
    }
    int i = 0;
    for (auto it : st) {
        uni[i++] = it; 
    }
    return i;
    
}
int main()
{
     int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    
    int uni[n1+n2];
    int uniSize = unionArray(arr1, arr2, n1, n2, uni);
    for(int i=0; i<uniSize; i++){
        cout<<uni[i]<<" ";
    }
    return 0;

}

//sheet     Qs->
/*Union of two sorted arrays

Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.
Examples:
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
Output: [1, 2, 3, 4, 5, 7]
Explanation: The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2
Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
Input: nums1 = [3, 4, 4, 4], nums2 = [6, 7, 7]*/

//solution ->
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        set<int>st;
        for(int i=0;i<n1;i++){
            st.insert(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            st.insert(nums2[i]);
        }
        vector<int>temp;
        for(auto it:st){
            temp.push_back(it);
        }
        return temp;
    }
};
